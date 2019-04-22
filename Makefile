NAME := "entropy-camera"
VERSION := "0.0.1"

.PHONY: all
all: clean build

.PHONY: entropy-camera start
start: entropy-camera
entropy-camera: make
	@echo "\n--------"
	@dist/bin/entropy-camera

.PHONY: make
make: clean autoreconf
	@cd dist && ./configure
	@cd dist && make

.PHONY: clean
clean:
	@git clean -fXd

.PHONY: autoreconf
autoreconf: dist
dist:
	@rsync -rv --exclude=Makefile --exclude=.git --exclude=dist ./ dist
	@cd dist && autoreconf --install
	@rm -r dist/*.cache

.PHONY: build
build: $(NAME)_$(VERSION).tar.gz
$(NAME)_$(VERSION).tar.gz: dist
	@mv dist $(NAME)
	@tar -czvf $(NAME)_$(VERSION).tar.gz $(NAME)
	@mv $(NAME) dist

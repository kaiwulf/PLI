CABAL   ?= cabal
TARGET  ?= pl1c

.PHONY: all build test repl lint fmt clean

all: build

build:
	$(CABAL) build $(TARGET)

test:
	$(CABAL) test --test-show-details=direct

repl:
	$(CABAL) repl $(TARGET)

lint:
	hlint app test

fmt:
	fourmolu -i app test

clean:
	$(CABAL) clean

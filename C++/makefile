.PHONY: all build clean

all: build

build:
	mkdir -p build && cd build && cmake ../lang/virtual_inheritance && make

run:
	./build/timer

clean:
	rm -rf build
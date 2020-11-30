
BIN := run

all: run

build/Makefile: Makefile CMakeLists.txt
	mkdir -p build
	(cd build && cmake ..)

$(BIN): $(wildcard *.cpp) build/Makefile
	(cd build && make)
	cp build/$(BIN) .

clean:
	rm -rf build $(BIN)

BIN := brain

all: 
	(cd brain && make)
	(cd plugins && make)

build/Makefile: Makefile CMakeLists.txt
	mkdir -p build
	(cd build && cmake ..)


$(BIN): $(wildcard *.cc) build/Makefile
	(cd build && make)
	cp build/$(BIN) .

clean:
	rm -rf build $(BIN)

.PHONY: all clean

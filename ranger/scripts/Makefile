
BIN := brain

all: commands SerialController Subsystems run

build/Makefile: Makefile CMakeLists.txt
	mkdir -p build
	(cd build && cmake ..)

$(BIN): $(wildcard *.cc) build/Makefile
	(cd build && make)
	cp build/$(BIN) .

clean:
	rm -rf build $(BIN) commands SerialController Subsystems run

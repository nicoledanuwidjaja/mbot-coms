
all:
	rm -f *.so
	make libtank_control_plugin.so

libtank_control_plugin.so:
	(cd tank_control && make)
	cp tank_control/*.so .

libmicrophone_control_plugin.so:
	(cd microphone_control && make)
	cp microphone_control/*.so .

clean:
	rm -f *.so
	(cd microphone_control && make clean)
	(cd tank_control && make clean)

.PHONY: all clean

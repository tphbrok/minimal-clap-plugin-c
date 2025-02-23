build: src/plugin.c
	rm -rf build
	mkdir build
	gcc -Wall -shared -fPIC -o ./plugin.clap/Contents/MacOS/plugin src/plugin.c

build-clap-info:
	cd tools/clap-info && cmake -Bbuild && cmake --build build

run-clap-info: src/plugin.c
	make build-clap-info
	make build
	./tools/clap-info/build/clap-info --brief ./plugin.clap
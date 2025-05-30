tronWindows: src/main.c
	gcc src/*.c -g -o tronGame.exe -Wall -std=c99 -I include/ -L lib/ -lraylibdll -lopengl32 -lgdi32 -lwinmm

tronLinux: src/main.c
	gcc src/*.c -g -o tronGame -I include/ -L lib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
tronWasm:
	emcc src/*.c \
		-I include \
		lib/libraylib.web.a \
		-o build/raylib.js \
		-DPLATFORM_WEB \
		-s USE_GLFW=3 \
		-s ASYNCIFY \
		-s ALLOW_MEMORY_GROWTH=1 \
		-s TOTAL_MEMORY=67108864 \
		-s FORCE_FILESYSTEM=1 \
		-std=c99 \

clean:
	rm build/tronGame build/tronGame.exe build/index.html build/index.wasm build/index.js build/raylib.js

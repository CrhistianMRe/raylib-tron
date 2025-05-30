tronWindows: src/main.c
	gcc src/*.c -g -o tronGame.exe -Wall -std=c99 -I include/ -L lib/ -lraylibdll -lopengl32 -lgdi32 -lwinmm

tronLinux: src/main.c
	gcc src/*.c -g -o tronGame -I include/ -L lib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


clean:
	rm tronGame 

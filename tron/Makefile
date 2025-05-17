tronLinux: src/main.c
	gcc src/main.c -o tronGame -I include/ -L lib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

tronWindows: src/main.c
	gcc main.c -o tronGame -O1 -Wall -std=c99 -Wno-missing-braces -l include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

clean:
	rm tronGame 

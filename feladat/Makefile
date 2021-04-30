#all:
	#gcc -o beadando -Iinclude/ src/* -lSOIL -lGL -lGLU -lm -lglut -std=c99
	#gcc -obeadando.exe -Iinclude/ src/* -lSOIL -lopengl32 -lglu32 -lglut32 -std=c99

#linux:
	#gcc -o beadando -Iinclude/ src/* -lSOIL -lGL -lGLU -lglut -lm -std=c99

all:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/draw.c src/model.c -lSOIL -lopengl32 -lglu32 -lglut32 -lm -o Beadando.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/draw.c src/model.c -lSOIL -lGL -lGLU -lglut -lm -o Beadando.exe -Wall -Wextra -Wpedantic
	

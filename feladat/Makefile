all:
	gcc -Iinclude/ -Iutils/obj/include/ src/animal.c src/callbacks.c src/camera.c src/draw_scene.c src/init.c src/main.c src/load_scene.c src/texture.c utils/obj/src/draw.c utils/obj/src/info.c utils/obj/src/load.c utils/obj/src/model.c utils/obj/src/transform.c -lSOIL -lopengl32 -lglu32 -lglut32 -lm -o Beadando.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ -Iutils/obj/include/ src/animal.c src/callbacks.c src/camera.c src/draw_scene.c src/init.c src/main.c src/load_scene.c src/texture.c utils/obj/src/draw.c utils/obj/src/info.c utils/obj/src/load.c utils/obj/src/model.c utils/obj/src/transform.c  -lSOIL -lGL -lGLU -lglut -lm -o Beadando.exe -Wall -Wextra -Wpedantic
	

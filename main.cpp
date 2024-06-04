#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


const int WIDTH = 850;
const int HEIGHT = 450;

void UpdateDrawFrame();

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	BeginDrawing();
	
	ClearBackground(RAYWHITE);

	DrawText("Yay you setup a raylib web game!", 100, 100, 20, BLACK);

	EndDrawing();
}

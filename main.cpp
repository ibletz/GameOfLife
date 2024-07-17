// Conway's Game of life
// Using raylib
// 2027/07/16
// tutorial : youtube.com/watch?v=daFYGrXq0aw

#include "raylib.h"

int main()
{
	Color GREY{ 29, 29, 29, 255 };
	const int WINDOW_WIDTH{ 750 };
	const int WINDOW_HEIGHT{ 750 };
	int FPS{ 12 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	// simulation loop
	while (WindowShouldClose() == false)
	{
		// event handling

		// updating state

		// drawing
		BeginDrawing();
		ClearBackground(GREY);
		EndDrawing();
	}



	CloseWindow();
	return 0;
}
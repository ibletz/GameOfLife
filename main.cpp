// Conway's Game of life
// Using raylib
// 2027/07/16
// tutorial : youtube.com/watch?v=daFYGrXq0aw

#include <iostream>
#include "raylib.h"
#include "simulation.h"

int main()
{
	Color GREY{ 29, 29, 29, 255 };
	const int WINDOW_WIDTH{ 750 };
	const int WINDOW_HEIGHT{ 750 };
	const int CELL_SIZE{ 25 };
	int FPS{ 12 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	Simulation simulation{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };

	// simulation loop
	while (WindowShouldClose() == false)
	{
		// event handling

		// updating state
		simulation.update();

		// drawing
		BeginDrawing();
		ClearBackground(GREY);
		simulation.draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
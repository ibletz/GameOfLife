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

	// switch to start and stop the game
	bool go{ false };

	// simulation loop
	while (WindowShouldClose() == false)
	{
		// event handling
		// press the space bar to start and stop the simulation
		if (IsKeyDown(KEY_SPACE))
			go = !go;
		if (go)
		{
			simulation.start();
			SetWindowTitle("Game of Life is running ...");
		}
		else
		{
			simulation.stop();
			SetWindowTitle("Game of Life is paused");
		}

		// speed up and slow down the game with arrow keys
		if (IsKeyPressed(KEY_UP))
		{
			FPS += 2;
			SetTargetFPS(FPS);
		}
		if (IsKeyPressed(KEY_DOWN))
		{
			FPS -= 2;
			SetTargetFPS(FPS);
		}

		// clear the grid
		if (IsKeyPressed(KEY_C))
			simulation.clearGrid();
		// set a random state for the grid
		if (IsKeyPressed(KEY_R))
			simulation.createRandomState();

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
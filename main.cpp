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
	const int WINDOW_WIDTH{ 800 };
	const int WINDOW_HEIGHT{ 800 };
	const int CELL_SIZE{ 10 };
	int FPS{ 12 };

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);

	// simulation object running the game
	Simulation simulation{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };

	// switch to start and stop the game
	bool go{ false };
	// switch to display the title/instructions only once
	bool displayTitle{ true };

	// simulation loop
	while (WindowShouldClose() == false)
	{
		/*---------- EVENT HANDLING ----------*/
		
		// use the mouse to manually edit the grid
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y / CELL_SIZE;
			int column = mousePosition.x / CELL_SIZE;
			simulation.toggleCell(row, column);
		}

		// press the space bar to start and stop the simulation
		if (IsKeyDown(KEY_SPACE))
		{
			go = !go;
			displayTitle = false;
		}
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

		// speed up and slow down the game with keys
		if (IsKeyPressed(KEY_F))
		{
			FPS += 2;
			SetTargetFPS(FPS);
		}
		if (IsKeyPressed(KEY_S))
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

		/*---------- UPDATING ----------*/
		simulation.update();

		/*---------- DRAWING ----------*/
		BeginDrawing();
		ClearBackground(GREY);
		simulation.draw();
		// draw the instructions once when the game starts
		if (displayTitle)
		{
			DrawRectangle(10, 10, 355, 140, LIGHTGRAY);
			DrawText("Conway's Game of life",15,15,30, WHITE);
			DrawText("Spacebar - start/stop", 15, 55, 20, WHITE);
			DrawText("F/S keys - faster/slower", 15, 75, 20, WHITE);
			DrawText("C/R keys - clear/randomize grid", 15, 95, 20, WHITE);
			DrawText("Use LMB to toggle cells", 15, 115, 20, WHITE);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
#pragma once
#include "grid.h"

class Simulation
{
public:
	Simulation(int width, int height, int cellSize)
		: grid(width, height, cellSize)
		, tempGrid(width, height, cellSize)
	{
		// initalize the grid with random values
		grid.fillRandom();
	}
	void draw();
	void setCellValue(int row, int column, int value);
	int countLiveNeighbors(int row, int column);
	void update();

private:
	Grid grid;
	Grid tempGrid;
};

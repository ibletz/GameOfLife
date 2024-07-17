#pragma once
#include "grid.h"

class Simulation
{
public:
	Simulation(int width, int height, int cellSize)
		: grid(width, height, cellSize)
	{}
	void draw();
	void setCellValue(int row, int column, int value);
	int countLiveNeighbors(int row, int column);

private:
	Grid grid;
};

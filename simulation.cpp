#include <vector>
#include <utility>
#include "simulation.h"

void Simulation::draw()
{
	grid.draw();
}

void Simulation::setCellValue(int row, int column, int value)
{
	grid.setValue(row, column, value);
}

int Simulation::countLiveNeighbors(int row, int column)
{
	int liveNeighbors{ 0 };
	// a vector of pair types to hold the offsets for the 8 neighbor cells
	std::vector<std::pair<int, int>> neighborOffsets =
	{
		{-1, 0},	// directly above
		{1, 0},		// directly below
		{0, -1},	// to left
		{0, 1},		// to right
		{-1, -1},	// diagonal upper left
		{-1, 1},	// diagonal upper right
		{1, -1},	// diagonal lower left
		{1, 1}		// diagonal lower right
	};

	// check each neighbor cell to count how many are alive
	// grid wraps around so edge neighbors can be counted
	for (const auto& offset : neighborOffsets)
	{
		// using modulo to count wrapping neighbors of edge cells
		int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
		int neighborColumn = (column + offset.second + grid.getColumns()) % grid.getColumns();
		liveNeighbors += grid.getValue(neighborRow, neighborColumn);
	}
	return liveNeighbors;
}

void Simulation::update()
{
	// iterate over the cells and update them based on rules
	for (int row = 0; row < grid.getRows(); row++)
	{
		for (int column = 0; column < grid.getColumns(); column++)
		{
			int liveNeighbors = countLiveNeighbors(row, column);
			int cellValue = grid.getValue(row, column);

			if (cellValue == 1)
			{
				if (liveNeighbors > 3 || liveNeighbors < 2)
				{
					// set the cell as dead on the temp grid 
					tempGrid.setValue(row, column, 0);
				}
				else
				{
					// keep the cell alive on the temp grid
					tempGrid.setValue(row, column, 1);
				}
			}
			else
			{
				if (liveNeighbors == 3)
				{
					// set the cell alive on the temp grid
					tempGrid.setValue(row, column, 1);
				}
				else
				{
					// keep the cell dead
					tempGrid.setValue(row, column, 0);
				}
			}

		}
	}
	// copy the updated values to the original grid
	grid = tempGrid;
}

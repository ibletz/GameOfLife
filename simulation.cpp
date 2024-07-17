#include <vector>
#include <utility>
#include "simulation.h"

void Simulation::draw()
{
	grid.draw();
}

// set a specific cell's value
void Simulation::setCellValue(int row, int column, int value)
{
	grid.setValue(row, column, value);
}

// return a count of all live neighbors of the specific cell
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

// update the state of the cells
void Simulation::update()
{
	if (isRunning())
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
}

// reset the grid to all 0s
void Simulation::clearGrid()
{
	if (!isRunning())
		grid.clear();
}

// create a random starting state for the grid
void Simulation::createRandomState()
{
	if (!isRunning())
		grid.fillRandom();
}

// toggle the value of the cell
void Simulation::toggleCell(int row, int column)
{
	if (!isRunning())
		grid.toggleCell(row, column);
}

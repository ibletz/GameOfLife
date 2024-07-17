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
		int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
		int neighborColumn = (column + offset.second + grid.getColumns()) % grid.getColumns();
		liveNeighbors += grid.getValue(neighborRow, neighborColumn);
	}
	return liveNeighbors;
}

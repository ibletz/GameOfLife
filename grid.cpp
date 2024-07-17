#include "raylib.h"
#include "grid.h"

void Grid::draw()
{
	// draw the grid
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			// assign grey color to dead cells, green to live cells
			Color color = cells[row][column] ? Color{ 0, 255, 0, 255 } : Color{ 55, 55, 55, 255 };
			// draw all the cells in the grid
			DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
		}
	}
}

// check if a row/column represents a valid cell
bool Grid::inBounds(int row, int column)
{
	return (row >= 0 && row < rows && column >= 0 && column < columns);
}

// manually set the value of a single cell
void Grid::setValue(int row, int column, int value)
{
	if(inBounds(row, column))
		cells[row][column] = value;
}

// return alive value of cell
int Grid::getValue(int row, int column)
{
	if (inBounds(row, column))
		return cells[row][column];
	return 0;
}

// fill the grid with random values
void Grid::fillRandom()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			// adjust second GetRandomValue() argument to increase/decrease live starting cells
			int randomValue = GetRandomValue(0, 4);
			cells[row][column] = (randomValue == 4) ? 1 : 0;
		}
	}
}

// clear the grid of all live cells
void Grid::clear()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			cells[row][column] = 0;
		}
	}
}

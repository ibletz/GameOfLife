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

// manually set the value of a single cell
void Grid::setValue(int row, int column, int value)
{
	if(row >= 0 && row < rows && column >= 0 && column < columns )
		cells[row][column] = value;
}

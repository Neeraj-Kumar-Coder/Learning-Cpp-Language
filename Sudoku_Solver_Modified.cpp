#include <iostream>

using namespace std;

void printSudoku(int **sudokuGrid, int size)
{
    int smallBoxSize = 0;
    while (smallBoxSize * smallBoxSize < size)
    {
        smallBoxSize++;
    }

    for (int currentRow = 0; currentRow < size; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < size; currentColumn++)
        {
            cout << sudokuGrid[currentRow][currentColumn] << ' ';
            if ((currentColumn + 1) % smallBoxSize == 0)
            {
                cout << '\t';
            }
        }
        cout << '\n';
        if ((currentRow + 1) % smallBoxSize == 0)
        {
            cout << '\n';
        }
    }
    cout << '\n';
}

bool isVaildPosition(int **sudokuGrid, int row, int column, int size, int number)
{
    // Row Scanning
    for (int currentColumn = 0; currentColumn < size; currentColumn++)
    {
        if (sudokuGrid[row][currentColumn] == number)
        {
            return false;
        }
    }

    // Column Scanning
    for (int currentRow = 0; currentRow < size; currentRow++)
    {
        if (sudokuGrid[currentRow][column] == number)
        {
            return false;
        }
    }

    // Mini Box Scanning
    int miniBoxSize = 0;
    while (miniBoxSize * miniBoxSize < size)
    {
        miniBoxSize++;
    }
    while ((row % miniBoxSize) != 0 || (column % miniBoxSize) != 0)
    {
        row % miniBoxSize != 0 ? row-- : row;
        column % miniBoxSize != 0 ? column-- : column;
    }
    for (int currentRow = row; currentRow < row + miniBoxSize; currentRow++)
    {
        for (int currentColumn = column; currentColumn < column + miniBoxSize; currentColumn++)
        {
            if (sudokuGrid[currentRow][currentColumn] == number)
            {
                return false;
            }
        }
    }

    // If no clashing number is present
    return true;
}

bool sudokuSolver(int **sudokuGrid, int size)
{
    int row = -1, column = -1;
    for (int currentRow = 0; currentRow < size; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < size; currentColumn++)
        {
            if (sudokuGrid[currentRow][currentColumn] == 0)
            {
                row = currentRow;
                column = currentColumn;
                break;
            }
        }
        if (row != -1 && column != -1)
        {
            break;
        }
    }
    if (row == -1 && column == -1) // No empty cell found (means Sudoku is now solved)
    {
        printSudoku(sudokuGrid, size);
        return true;
    }

    for (int number = 1; number <= size; number++)
    {
        if (isVaildPosition(sudokuGrid, row, column, size, number))
        {
            sudokuGrid[row][column] = number;
            sudokuSolver(sudokuGrid, size);
            sudokuGrid[row][column] = 0; // Backtracking
        }
    }
    return false;
}

int main(void)
{
    int size;
    cout << "Enter the size of sudoku you want to solve: ";
    cin >> size;
    int **sudokuMaze = new int *[size];
    for (int i = 0; i < size; i++)
    {
        sudokuMaze[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the element at (" << i << ',' << ' ' << j << "): ";
            cin >> sudokuMaze[i][j];
        }
    }
    sudokuSolver(sudokuMaze, size);
    return 0;
}
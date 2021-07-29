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
        return true;
    }

    for (int number = 1; number <= size; number++)
    {
        if (isVaildPosition(sudokuGrid, row, column, size, number))
        {
            sudokuGrid[row][column] = number;
            if (sudokuSolver(sudokuGrid, size))
            {
                return true;
            }
            sudokuGrid[row][column] = 0; // Backtracking
        }
    }
    return false;
}

int main(void)
{
    freopen("SudokuInput.txt", "r", stdin);
    int **sudokuMaze = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        sudokuMaze[i] = new int[9];
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudokuMaze[i][j];
        }
    }
    if (sudokuSolver(sudokuMaze, 9))
    {
        cout << "SOLVED!\n";
        printSudoku(sudokuMaze, 9);
    }
    else
    {
        cout << "Can't solve!\n";
    }
    return 0;
}
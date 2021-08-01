#include <iostream>
#include <iomanip>
#define canGo(x) !x

using namespace std;

struct Maze
{
    int row, column;
    int **mazeArray;
};

bool pathFinder(Maze *maze, int curRow, int curCol, int desRow, int desCol)
{
    if (curRow == desRow && curCol == desCol)
    {
        return true; // Reached the destination
    }

    maze->mazeArray[curRow][curCol] = 1;
    if (curRow + 1 < maze->row && canGo(maze->mazeArray[curRow + 1][curCol]))
    {
        maze->mazeArray[curRow + 1][curCol] = 1;
        if (pathFinder(maze, curRow + 1, curCol, desRow, desCol))
            return true;
        maze->mazeArray[curRow + 1][curCol] = 0;
    }
    if (curCol + 1 < maze->column && canGo(maze->mazeArray[curRow][curCol + 1]))
    {
        maze->mazeArray[curRow][curCol + 1] = 1;
        if (pathFinder(maze, curRow, curCol + 1, desRow, desCol))
            return true;
        maze->mazeArray[curRow][curCol + 1] = 0;
    }
    if (curRow - 1 > -1 && canGo(maze->mazeArray[curRow - 1][curCol]))
    {
        maze->mazeArray[curRow - 1][curCol] = 1;
        if (pathFinder(maze, curRow - 1, curCol, desRow, desCol))
            return true;
        maze->mazeArray[curRow - 1][curCol] = 0;
    }
    if (curCol - 1 > -1 && canGo(maze->mazeArray[curRow][curCol - 1]))
    {
        maze->mazeArray[curRow][curCol - 1] = 1;
        if (pathFinder(maze, curRow, curCol - 1, desRow, desCol))
            return true;
        maze->mazeArray[curRow][curCol - 1] = 0;
    }
    return false;
}

void printMaze(Maze *maze)
{
    for (int i = 0; i < maze->row; i++)
    {
        for (int j = 0; j < maze->column; j++)
        {
            cout << setw(2) << maze->mazeArray[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void)
{
    Maze *maze = new Maze;
    cout << "Enter the Row and Column of the maze: ";
    cin >> maze->row >> maze->column;
    maze->mazeArray = new int *[maze->row];
    for (int i = 0; i < maze->row; i++)
        maze->mazeArray[i] = new int[maze->column];
    cout << "Enter the maze (0 -> Not blocked, -1 -> Blocked):\n";
    for (int i = 0; i < maze->row; i++)
        for (int j = 0; j < maze->column; j++)
            cin >> maze->mazeArray[i][j];
    cout << "The maze you entered is:\n";
    printMaze(maze);
    int startRow, startColumn, endRow, endColumn;
    cout << "Enter the start row, start column, end row and end column: ";
    cin >> startRow >> startColumn >> endRow >> endColumn;
    if (pathFinder(maze, startRow, startColumn, endRow, endColumn))
    {
        cout << "The solved maze is:\n";
        printMaze(maze);
    }
    else
    {
        cout << "The maze can't be solved!\n";
    }
    return 0;
}
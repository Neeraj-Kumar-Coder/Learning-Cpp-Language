#include <iostream>
#include <iomanip>
#include <limits>
#define canGo(x) !x

using namespace std;

struct Maze
{
    int row, column;
    int **mazeArray;
    int **shortestPathMaze;
    int shortestPathLength;
};

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

void printMazeShortest(Maze *maze)
{
    for (int i = 0; i < maze->row; i++)
    {
        for (int j = 0; j < maze->column; j++)
        {
            cout << setw(2) << maze->shortestPathMaze[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool pathFinder(Maze *maze, int curRow, int curCol, int desRow, int desCol)
{
    static int pathLength = 1;
    static int minimumPathLength = INT_MAX;
    if (curRow == desRow && curCol == desCol)
    {
        printMaze(maze);
        if (pathLength < minimumPathLength)
        {
            minimumPathLength = pathLength;
            for (int i = 0; i < maze->row; i++)
                for (int j = 0; j < maze->column; j++)
                    maze->shortestPathMaze[i][j] = maze->mazeArray[i][j];
            maze->shortestPathLength = minimumPathLength;
        }
        return true; // Reached the destination
    }

    maze->mazeArray[curRow][curCol] = pathLength;
    // Go down
    if (curRow + 1 < maze->row && canGo(maze->mazeArray[curRow + 1][curCol]))
    {
        pathLength++;
        maze->mazeArray[curRow + 1][curCol] = pathLength;
        pathFinder(maze, curRow + 1, curCol, desRow, desCol);
        pathLength--;
        maze->mazeArray[curRow + 1][curCol] = 0;
    }
    // Go right
    if (curCol + 1 < maze->column && canGo(maze->mazeArray[curRow][curCol + 1]))
    {
        pathLength++;
        maze->mazeArray[curRow][curCol + 1] = pathLength;
        pathFinder(maze, curRow, curCol + 1, desRow, desCol);
        pathLength--;
        maze->mazeArray[curRow][curCol + 1] = 0;
    }
    // Go up
    if (curRow - 1 > -1 && canGo(maze->mazeArray[curRow - 1][curCol]))
    {
        pathLength++;
        maze->mazeArray[curRow - 1][curCol] = pathLength;
        pathFinder(maze, curRow - 1, curCol, desRow, desCol);
        pathLength--;
        maze->mazeArray[curRow - 1][curCol] = 0;
    }
    // Go left
    if (curCol - 1 > -1 && canGo(maze->mazeArray[curRow][curCol - 1]))
    {
        pathLength++;
        maze->mazeArray[curRow][curCol - 1] = pathLength;
        pathFinder(maze, curRow, curCol - 1, desRow, desCol);
        pathLength--;
        maze->mazeArray[curRow][curCol - 1] = 0;
    }
    return false;
}

int main(void)
{
    Maze *maze = new Maze;
    cout << "Enter the Row and Column of the maze: ";
    cin >> maze->row >> maze->column;

    maze->mazeArray = new int *[maze->row];
    maze->shortestPathMaze = new int *[maze->row];
    for (int i = 0; i < maze->row; i++)
    {
        maze->mazeArray[i] = new int[maze->column];
        maze->shortestPathMaze[i] = new int[maze->column];
    }
    cout << "Enter the maze (0 -> Not blocked, -1 -> Blocked):\n";
    for (int i = 0; i < maze->row; i++)
        for (int j = 0; j < maze->column; j++)
            cin >> maze->mazeArray[i][j];
    cout << "The maze you entered is:\n";
    printMaze(maze);
    int startRow, startColumn, endRow, endColumn;
    cout << "Enter the start row, start column, end row and end column: ";
    cin >> startRow >> startColumn >> endRow >> endColumn;
    cout << "All possible paths are:\n\n";
    pathFinder(maze, startRow, startColumn, endRow, endColumn);
    cout << "\nThe shortest path is:\n";
    printMazeShortest(maze);
    cout << "Path Length: " << maze->shortestPathLength << '\n';
    return 0;
}
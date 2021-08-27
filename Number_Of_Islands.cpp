#include <iostream>

using namespace std;

void islandScanner(bool **, int, int, int, int);

int main(void)
{
    int row, column;
    cout << "Enter the rows and the columns: ";
    cin >> row >> column;

    bool **world = new bool *[row];
    for (int i = 0; i < row; i++)
    {
        world[i] = new bool[column];
    }

    // Getting the input of the world
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> world[i][j];
        }
    }

    int countOfIslands = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (!world[i][j])
            {
                islandScanner(world, row, column, i, j);
                countOfIslands++;
            }
        }
    }

    cout << "The total number of islands are: " << countOfIslands << '\n';
    return 0;
}

void islandScanner(bool **world, int row, int column, int curRow, int curColumn)
{
    // Guard Clause
    if (curRow < 0 || curColumn < 0 || curRow >= row || curColumn >= column || world[curRow][curColumn])
    {
        return;
    }

    world[curRow][curColumn] = true;
    islandScanner(world, row, column, curRow - 1, curColumn);
    islandScanner(world, row, column, curRow + 1, curColumn);
    islandScanner(world, row, column, curRow, curColumn - 1);
    islandScanner(world, row, column, curRow, curColumn + 1);
}
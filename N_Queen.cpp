#include <iostream>

using namespace std;

int **createBoard(int size)
{
    int **chessBoard = new int *[size];
    for (int column = 0; column < size; column++)
    {
        chessBoard[column] = new int[size];
    }
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            // Initially none of the position should have the queen
            chessBoard[row][column] = 0;
        }
    }
    return chessBoard;
}

void printBoard(int **board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            cout << board[row][column] << ' ';
        }
        cout << '\n';
    }
}

bool isSafePosition(int **board, int row, int column, int totalRow)
{
    // Column Scanning (because row scanning is redundant as there will be no queen for obvious reason)
    for (int currentColumn = 0; currentColumn < totalRow; currentColumn++)
    {
        if (board[currentColumn][column])
        {
            return false;
        }
    }

    // Diagonal 1 Scanning
    int tempRow = row;
    int tempColumn = column;
    while (tempRow > 0 && tempColumn > 0)
    {
        tempRow--, tempColumn--;
    }

    while (tempRow < totalRow && tempColumn < totalRow)
    {
        if (board[tempRow++][tempColumn++])
        {
            return false;
        }
    }

    // Diagonal 2 Scanning
    tempRow = row;
    tempColumn = column;
    while (tempRow > 0 && tempColumn < totalRow - 1)
    {
        tempRow--, tempColumn++;
    }
    while (tempRow < totalRow && tempColumn > -1)
    {
        if (board[tempRow++][tempColumn--])
        {
            return false;
        }
    }

    // When there is no Queen for danger
    return true;
}

bool N_Queen(int **board, const int totalRow, int currentRow = 0)
{
    if (currentRow == totalRow) // Successful in finding a solution
    {
        printBoard(board, totalRow);
        return true;
    }
    for (int currentColumn = 0; currentColumn < totalRow; currentColumn++)
    {
        if (isSafePosition(board, currentRow, currentColumn, totalRow))
        {
            board[currentRow][currentColumn] = 1; // Placed the Queen at the current position
            if (N_Queen(board, totalRow, currentRow + 1))
            {
                return true;
            }
            board[currentRow][currentColumn] = 0; // Backtracking (Removed the Queen as it didn't gave a solution)
        }
    }
    return false;
}

int main(void)
{
    int size;
    cout << "Enter the size of the chess board: ";
    cin >> size;
    int **chessBoard = createBoard(size);
    if (!N_Queen(chessBoard, size))
    {
        cout << "Solution do not exist!\n";
    }
    return 0;
}
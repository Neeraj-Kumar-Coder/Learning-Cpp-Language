#include <iostream>
#include <iomanip>

using namespace std;

int **createBoard(int);
void printBoard(int **, int);
void knightTour(int **, int, int, int, int = 1);

int main(void)
{
    int sizeOfChessBoard;
    cout << "Enter the size of the chess board: ";
    cin >> sizeOfChessBoard;

    int **board = createBoard(sizeOfChessBoard);
    int row, column;
    cout << "Enter the initial position of the knight: ";
    cin >> row >> column;
    knightTour(board, sizeOfChessBoard, row, column);
    return 0;
}

int **createBoard(int sizeOfChessBoard)
{
    int **board = new int *[sizeOfChessBoard];
    for (int i = 0; i < sizeOfChessBoard; i++)
    {
        board[i] = new int[sizeOfChessBoard];
        for (int j = 0; j < sizeOfChessBoard; j++)
        {
            board[i][j] = 0;
        }
    }
    return board;
}

void printBoard(int **board, int sizeOfChessBoard)
{
    for (int i = 0; i < sizeOfChessBoard; i++)
    {
        for (int j = 0; j < sizeOfChessBoard; j++)
        {
            cout << setw(2) << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void knightTour(int **board, int sizeOfChessBoard, int curRow, int curColumn, int move)
{
    if (curRow < 0 || curColumn < 0 || curRow >= sizeOfChessBoard || curColumn >= sizeOfChessBoard || board[curRow][curColumn])
    {
        return;
    }
    if (move == sizeOfChessBoard * sizeOfChessBoard)
    {
        board[curRow][curColumn] = move;
        printBoard(board, sizeOfChessBoard);
        cout << '\n';
        board[curRow][curColumn] = 0;
        return;
    }

    board[curRow][curColumn] = move;
    knightTour(board, sizeOfChessBoard, curRow - 2, curColumn + 1, move + 1);
    knightTour(board, sizeOfChessBoard, curRow - 1, curColumn + 2, move + 1);
    knightTour(board, sizeOfChessBoard, curRow + 1, curColumn + 2, move + 1);
    knightTour(board, sizeOfChessBoard, curRow + 2, curColumn + 1, move + 1);
    knightTour(board, sizeOfChessBoard, curRow + 2, curColumn - 1, move + 1);
    knightTour(board, sizeOfChessBoard, curRow + 1, curColumn - 2, move + 1);
    knightTour(board, sizeOfChessBoard, curRow - 1, curColumn - 2, move + 1);
    knightTour(board, sizeOfChessBoard, curRow - 2, curColumn - 1, move + 1);
    board[curRow][curColumn] = 0;
}
#include <iostream>
#include <vector>
#define N 8
using namespace std;
int board[N][N];

bool checkqueen(int board[N][N], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][column] == 1)
            return false;
    }
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = column; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
bool tryqueen(int board[N][N], int row)
{
    if (row == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int j = 0; j < N; j++)
    {
        if (checkqueen(board, row, j) == true)
        {
            board[row][j] = 1;
            tryqueen(board, row + 1);
            board[row][j] = 0;
        }
    }
    return true;
}
int main()
{
    freopen("queen.out", "w", stdout);
    //memset(board,0,sizeof(board));
    tryqueen(board, 0);
}
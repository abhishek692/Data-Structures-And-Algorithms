#include <bits/stdc++.h>
using namespace std;

bool Safe(int **board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col])
        {
            return false;
        }
    }
    int j = row - 1, k = col + 1;
    while (j >= 0 && k < n)
    {
        if (board[j--][k++])
        {
            return false;
        }
    }
    int l = row - 1, m = col - 1;
    while (l >= 0 && m >= 0)
    {
        if (board[l--][m--])
        {
            return false;
        }
    }
    return true;
}

void nQueens(int **board, int row, int n)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (Safe(board, row, col, n))
        {
            board[row][col] = 1;
            nQueens(board, row + 1, n);
            board[row][col] = 0;
        }
    }
    return;
}

int main()
{

    int n;
    cin >> n;

    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    nQueens(board, 0, n);
    return 0;
}
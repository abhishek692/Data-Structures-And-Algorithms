#include <bits/stdc++.h>
using namespace std;

bool canPlace(int **board, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    int rowF = row - row % 3;
    int colF = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + rowF][j + colF] == num)
            {
                return false;
                ;
            }
        }
    }
    return true;
}

bool sudokuSolver(int **board, int row, int col)
{
    if (row > 8)
    {
        return true;
    }
    if (col > 8)
    {
        return sudokuSolver(board, row + 1, 0);
    }
    if (board[row][col] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            bool correctNum = canPlace(board, row, col, i);
            if (correctNum)
            {
                board[row][col] = i;
                bool ans = sudokuSolver(board, row, col + 1);
                if (ans)
                {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
    else
    {
        return sudokuSolver(board, row, col + 1);
    }
}

int main()
{

    // write your code here
    int **board = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    bool ans = sudokuSolver(board, 0, 0);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false";
    }
}

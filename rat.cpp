
#include <bits/stdc++.h>
using namespace std;

void ratInMaze(int **maze, int **path, int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        path[row][col] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    if (row < 0 || row >= n || col < 0 || col >= n || path[row][col] == 1 || maze[row][col] == 0)
    {
        return;
    }
    path[row][col] = 1;
    ratInMaze(maze, path, row - 1, col, n);
    ratInMaze(maze, path, row + 1, col, n);
    ratInMaze(maze, path, row, col - 1, n);
    ratInMaze(maze, path, row, col + 1, n);
    path[row][col] = 0;
}
int main()
{

    // Write your code here
    int n;
    cin >> n;

    int **maze = new int *[n];

    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    int **path = new int *[n];

    for (int i = 0; i < n; i++)
    {
        path[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            path[i][j] = 0;
        }
    }

    ratInMaze(maze, path, 0, 0, n);

    return 0;
}

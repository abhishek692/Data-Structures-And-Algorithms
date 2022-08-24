#include <iostream>
using namespace std;
#include <climits>

int minVertex(bool *visited, int *distances, int v)
{
    int minV = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (minV == -1 || distances[minV] > distances[i]))
        {
            minV = i;
        }
    }
    return minV;
}

void dijkstra(int **input, int v, int e)
{
    bool *visited = new bool[v];
    int *distances = new int[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[0] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int minV = minVertex(visited, distances, v);
        visited[minV] = true;

        for (int j = 0; j < v; j++)
        {
            if (input[minV][j] != 0 && !visited[j])
            {

                int dist = distances[minV] + input[minV][j];
                if (dist < distances[j])
                {
                    distances[j] = dist;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << " " << distances[i] << endl;
    }

    delete[] visited;
    delete[] distances;
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;

    int **input = new int *[v];

    for (int i = 0; i < v; i++)
    {
        input[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            input[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int sv, ev, weight;
        cin >> sv >> ev >> weight;
        input[sv][ev] = weight;
        input[ev][sv] = weight;
    }

    dijkstra(input, v, e);

    for (int i = 0; i < v; i++)
    {
        delete[] input[i];
    }

    delete[] input;
}
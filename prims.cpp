#include <iostream>
using namespace std;
#include <climits>

int minVertex(int *weights, bool *visited, int v)
{
    int min = -1;
    weights[-1] = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && weights[i] < weights[min])
        {
            min = i;
        }
    }
    return min;
}

void prims(int **input, int v, int e)
{

    int *weights = new int(v);
    int *parents = new int(v);
    bool *visited = new bool(v);

    for (int i = 0; i < v; i++)
    {
        weights[i] = INT_MAX;
        visited[i] = false;
    }

    weights[0] = 0;
    parents[0] = -1;

    for (int i = 0; i < v; i++)
    {
        int minV = minVertex(weights, visited, v);
        visited[minV] = true;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && input[minV][j] != 0 && (input[minV][j] < weights[j]))
            {
                weights[j] = input[minV][j];
                parents[j] = minV;
            }
        }
    }

    for (int i = 0; i < (v - 1); i++)
    {
        cout << min(i, parents[i]) << " " << max(i, parents[i]) << " " << weights[i] << endl;
        i = parents[i];
    }
}

int main()
{
    // Write your code here
    int v, e;

    int **edges = new int *[v];

    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int startVertex, endVertex, weight;
        cin >> startVertex >> endVertex >> weight;
        edges[startVertex][endVertex] = weight;
        edges[endVertex][startVertex] = weight;
    }

    prims(edges, v, e);
}
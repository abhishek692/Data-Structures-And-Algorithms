#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class edge
{
public:
    int startVertex;
    int endVertex;
    int weight;
};

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int parent(int v, int *parents)
{
    if (parents[v] == v)
    {
        return v;
    }
    return parent(parents[v], parents);
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;

    edge *input = new edge[e];

    for (int i = 0; i < e; i++)
    {
        cin >> input[i].startVertex >> input[i].endVertex >> input[i].weight;
    }

    int *parents = new int[v];
    for (int i = 0; i < v; i++)
    {
        parents[i] = i;
    }

    int count = 0;

    edge *output = new edge[v - 1];

    sort(input, input + e, compare);

    for (int i = 0; i < e, count < (v - 1); i++)
    {
        int v1 = input[i].startVertex;
        int v2 = input[i].endVertex;
        int w = input[i].weight;

        int p1 = parent(v1, parents);
        int p2 = parent(v2, parents);

        if (p1 != p2)
        {
            output[count].startVertex = v1;
            output[count].endVertex = v2;
            output[count].weight = w;
            parents[p2] = p1;
            count++;
        }
    }

    for (int i = 0; i < (v - 1); i++)
    {

        cout << min(output[i].startVertex, output[i].endVertex) << " " << max(output[i].startVertex, output[i].endVertex) << " " << output[i].weight << endl;
    }
}
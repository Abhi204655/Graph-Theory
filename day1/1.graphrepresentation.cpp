#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main()
{
    OJ;

    int nodes, edges, startNode, endNode;

    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes + 1);

    for (int i = 0; i < edges; i++)
    {
        cin >> startNode >> endNode;
        adjList[startNode].push_back(endNode);
        adjList[endNode].push_back(startNode);
    }

    for (int i = 1; i <= nodes; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
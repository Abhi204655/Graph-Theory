#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int nodes, edges, startNode, endNode;
vector<vector<int>> adjList(2001);
vector<bool> vis(2001, false);

void dfs(int node)
{
    vis[node] = true;

    for (auto child : adjList[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    OJ;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        cin >> startNode >> endNode;
        adjList[startNode].push_back(endNode);
        adjList[endNode].push_back(startNode);
    }

    int countOfConnectedComponents = 0;
    for (int i = 1; i <= nodes; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            countOfConnectedComponents++;
        }
    }

    cout << "Count of connected components : " << countOfConnectedComponents << endl;

    return 0;
}
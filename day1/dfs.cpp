// Adjacency list representation....
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
    cout << node << " ";

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

    dfs(2);
    cout << endl;

    return 0;
}
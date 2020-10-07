// Single source shortest path in a tree.
#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int n, e, a, b;
vector<int> ar[2001];
vector<bool> vis(2001, false);
vector<int> dist(2001, 0);

void dfs(int node, int d)
{
    vis[node] = true;
    dist[node] = d;

    for (auto child : ar[node])
    {
        if (!vis[child])
        {
            dfs(child, d + 1);
        }
    }
}

int main()
{
    OJ;

    cin >> n >> e;
    while (e--)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    int src = 1;
    dfs(src, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}

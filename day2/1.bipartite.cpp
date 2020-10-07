#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int n, e, a, b;
vector<int> ar[2001];
vector<bool> vis(2001, false);

vector<int> colors(2001, -1);

bool dfs(int node, int c)
{
    vis[node] = true;
    colors[node] = c;

    for (auto child : ar[node])
    {
        if (!vis[child])
        {
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        else if (colors[node] == colors[child])
        {
            return false;
        }
    }
    return true;
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
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, 0) == false)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "Bipartite" << endl;
    else
        cout << "Not bipartite" << endl;

    return 0;
}
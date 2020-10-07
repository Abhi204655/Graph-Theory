#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int n, e, a, b;
vector<int> ar[2001];
vector<bool> vis(2001, false);
vector<int> parent(2001, -1);

bool dfs(int node, int p)
{
    vis[node] = true;
    parent[node] = p;

    for (auto child : ar[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node) == true)
                return true;
        }
        else if (child != p)
            return true;
    }
    return false;
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

    if (dfs(1, -1) == true)
    {
        cout << "Cycle hai" << endl;
    }
    else
    {
        cout << "Cycle nhi hai" << endl;
    }

    return 0;
}
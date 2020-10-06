#include <bits/stdc++.h>
using namespace std;

#define OJ                               \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main()
{
    OJ;

    vector<vector<int>> ar(5, vector<int>());

    ar[0].push_back(10);
    ar[0].push_back(20);
    ar[0].push_back(30);

    ar[3].push_back(10);
    ar[3].push_back(30);
    ar[3].push_back(20);

    for (int i = 0; i < 5; i++)
    {
        cout << i << " : ";
        // for (auto it = ar[i].begin(); it != ar[i].end(); it++)
        for (int j = 0; j < ar[i].size(); j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
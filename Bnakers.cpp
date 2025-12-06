#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, r;
    // cout << "Enter number of processes: ";
    cin >> n;
    // cout << "Enter number of resources: ";
    cin >> r;

    vector<vector<int>> alloc(n, vector<int>(r));
    vector<vector<int>> mx(n, vector<int>(r));
    vector<int> avail(r);

    // cout << "\nEnter Allocation Matrix (" << n << "x" << r << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // cout << "\nEnter Max Matrix (" << n << "x" << r << "):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> mx[i][j];
        }
    }

    // cout << "\nEnter Available Resources (" << r << " values): ";
    for (int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }

    vector<int> f(n, 0);
    vector<int> ans(n);
    int ind = 0;

    vector<vector<int>> need(n, vector<int>(r));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = mx[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout << "\nThe SAFE Sequence is:\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "P" << ans[i]+1 << " -> ";
    }
    cout << "P" << ans[n - 1]+1 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid, att, bt, ct, tat, wt, priority;
};

int main()
{
    int n;
    cin >> n;

    vector<process> p(n);

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cin >> p[i].att >> p[i].bt >> p[i].priority;
    }

    int completed = 0, time = 0;
    long long total_tat = 0, total_wt = 0;
    vector<bool> done(n, false);

    while (completed < n)
    {
        int idx = -1;
        int mn_priority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (p[i].att <= time && !done[i])
            {
                if (p[i].priority < mn_priority ||
                        (p[i].priority == mn_priority && p[i].att < p[idx].att))
                {
                    mn_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            time++;
            continue;
        }

        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].att;
        p[idx].wt = p[idx].tat - p[idx].bt;
        done[idx] = true;

        total_tat += p[idx].tat;
        total_wt += p[idx].wt;
        completed++;
    }

    cout << "\nPID\tAT\tBT\tP\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].att << "\t" << p[i].bt << "\t"
             << p[i].priority << "\t" << p[i].ct << "\t"
             << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average TAT = " << (double)total_tat / n << endl;
    cout << "Average WT = " << (double)total_wt / n << endl;
}

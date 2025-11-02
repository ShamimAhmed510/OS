#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, att, bt, rt, ct, tat, wt, priority;
};

int main()
{
    int n;
    cin >> n;

    vector<Process>p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].att >> p[i].bt >> p[i].priority;
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    double total_tat = 0, total_wt = 0;

    while (completed < n)
    {
        int idx = -1, mn_priority = INT_MAX;

        // find process with highest priority (lowest number)
        for (int i = 0; i < n; i++)
        {
            if (p[i].att <= time && p[i].rt > 0)
            {
                if (p[i].priority < mn_priority)
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

        // run process for 1 time unit only
        p[idx].rt--;
        time++;

        // if finished
        if (p[idx].rt == 0)
        {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].att;
            p[idx].wt = p[idx].tat - p[idx].bt;
            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
            completed++;
        }
    }

    cout << "\nPreemptive Priority Scheduling\n";
    cout << "PID\tAT\tBT\tP\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].att << "\t" << p[i].bt << "\t"
             << p[i].priority << "\t" << p[i].ct << "\t"
             << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average TAT = " << total_tat / n << endl;
    cout << "Average WT = " << total_wt / n << endl;
}

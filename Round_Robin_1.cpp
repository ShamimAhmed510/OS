
#include <bits/stdc++.h>
using namespace std;

struct pr
{
    int pid, at, bt, rt, ct, st, tat, wt;
};

int main()
{
    int n;
    cin >> n;

    vector<pr> p(n);

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
        p[i].st = -1;
    }

    int time_quantum;
    cin >> time_quantum;

    sort(p.begin(), p.end(), [](pr a, pr b)
    {
        return a.at < b.at;
    });

    int time = p[0].at, completed = 0;
    queue<int> q;
    int p_ind = 1;

    q.push(0);

    while (completed != n)
    {
        int ind = q.front();
        q.pop();

        if (p[ind].st == -1) p[ind].st = time;

        if (p[ind].rt > time_quantum)
        {
            time += time_quantum;
            p[ind].rt -= time_quantum;
        }
        else
        {
            time += p[ind].rt;
            p[ind].rt = 0;
            p[ind].ct = time;
            completed++;
        }

        for (int i = p_ind; i < n; i++)
        {
            if (p[i].at <= time)
            {
                q.push(i);
                p_ind++;
            }
            else break;
        }

        if (p[ind].rt > 0)
        {
            q.push(ind);
        }

        if (q.empty() && p_ind < n)
        {
            time = p[p_ind].at;
            q.push(p_ind);
            p_ind++;
        }
    }

    int total_tat = 0, total_wt = 0, total_rt = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        int response_time = p[i].st - p[i].at;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        total_rt += response_time;
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t"
             << p[i].bt << "\t" << p[i].ct << "\t"
             << p[i].tat << "\t" << p[i].wt << "\t"
             << response_time << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average TAT = " << (double)total_tat / n << endl;
    cout << "Average WT = " << (double)total_wt / n << endl;
    cout << "Average RT = " << (double)total_rt / n << endl;

    return 0;

}


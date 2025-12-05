#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int at;
    int bt;
    int st;
    int ct;
    int wt;
    int tat;
};

void generate_table(vector<Process>& v, int n)
{
    float total_wt = 0, total_tat = 0;

    sort(v.begin(),v.end(),[](Process a, Process b)
    {
        return a.pid < b.pid;
    });

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n";


    for (int i = 0; i < n; i++)
    {
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt  = v[i].tat - v[i].bt;
        total_tat += v[i].tat;
        total_wt  += v[i].wt;

        cout << v[i].pid << "\t"
             << v[i].at << "\t"
             << v[i].bt << "\t"
             << v[i].ct << "\t"
             << v[i].tat << "\t"
             << v[i].wt << "\t"
             << v[i].st - v[i].at << "\n";
    }

    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << total_tat/n;
    cout << "\nAverage Waiting Time   : " << fixed << setprecision(2) << total_wt/n << "\n";
}

void FCFS(vector<Process>& v, int n)
{
    int time = 0;

    sort(v.begin(), v.end(), [](Process a, Process b)
    {
        return a.at < b.at;
    });

    for (int i = 0; i < n; i++)
    {
        if (time < v[i].at)
            time = v[i].at;

        v[i].st = time;
        time += v[i].bt;
        v[i].ct = time;
    }

    generate_table(v, n);
}

int main()
{
    int n;
    cin >> n;

    vector<Process> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i].pid = i + 1;
        cin >> v[i].at;
        cin >> v[i].bt;
    }

    FCFS(v, n);

    return 0;
}

#include<bits/stdc++.h>
using namespace std ;

#define MAX 100


struct Process
{
    int pid, at,bt,ct,st,rt,wt,tat;
};



void maketable(vector<Process>&v, int n)
{
    float total_tat=0, total_wt=0;

    sort(v.begin(),v.end(),[](Process a, Process b)
    {
        return a.pid < b.pid;
    });


    cout << "PID\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;

    for(int i=0; i<n; i++)
    {
        v[i].tat = v[i].ct - v[i].at;
        v[i].wt = v[i].tat - v[i].bt;
        v[i].rt = v[i].st - v[i].at;

        total_tat +=v[i].tat;
        total_wt +=v[i].wt;

        cout << v[i].pid << "\t"
             << v[i].at << "\t"
             << v[i].bt << "\t"
             << v[i].ct << "\t"
             << v[i].tat << "\t"
             << v[i].wt << "\t"
             << v[i].rt << "\t"<< endl;

    }

    cout<<"avg wt "<< setprecision(2)<<(total_tat/n)<<"\n"<<"avg tat "<<setprecision(2)<<(total_wt/n)<<endl;

}

void sjf(vector<Process>&v, int n)
{

    sort(v.begin(),v.end(),[](Process a, Process b)
    {
        return a.at < b.at;
    });

    int completed = 0, time = 0;
    int done[MAX] = {0};

    while (completed < n)
    {
        int idx = -1, min_burst = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!done[i] && v[i].at <= time && v[i].bt < min_burst)
            {
                idx = i;
                min_burst = v[i].bt;
            }
        }
        if (idx == -1)
        {
            time++;
            continue;
        }

        v[idx].st = time;
        time += v[idx].bt;
        v[idx].ct = time;
        done[idx] = 1;
        completed++;
    }
    maketable(v, n);
}

int main()
{
    int n;
    cin>> n;

    vector<Process>v(n);

    for(int i=0; i<n; i++)
    {
        v[i].pid = i+1;
        cin>>v[i].at>>v[i].bt;
    }

    sjf(v,n);

    return 0;

}



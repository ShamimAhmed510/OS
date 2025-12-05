#include<bits/stdc++.h>
using namespace std ;

#define MAX 100


struct Process
{
    int pid, at,bt,ct,st,rt,wt,tat,rm;
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

void srtf(vector<Process>&v, int n)
{

    sort(v.begin(),v.end(),[](Process a, Process b)
    {
        return a.at < b.at;
    });

    int completed = 0, time = 0;

    for ( int i = 0; i < n; i++)
    {
        v[i].rm = v[i].bt;
        v[i].st = -1;
        v[i].ct = 0;
    }

    while (completed < n)
    {
        int idx = -1, min_rem = INT_MAX;

        for ( int i = 0; i < n; i++)
        {
            if (v[i].at <= time && v[i].rm > 0 && v[i].rm < min_rem)
            {
                min_rem = v[i].rm;
                idx = i;
            }
        }
        if (idx == -1)
        {
            time++;
            continue;
        }

        if (v[idx].st == -1) v[idx].st = time;
        v[idx].rm--;
        time++;

        if (v[idx].rm == 0)
        {
            v[idx].ct = time;
            completed++;
        }
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

    srtf(v,n);

    return 0;

}




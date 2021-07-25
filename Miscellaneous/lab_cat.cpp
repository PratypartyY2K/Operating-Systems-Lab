#include <iostream>
#include <algorithm>
#include <string.h>
#include <unistd.h>

using namespace std;

typedef struct proccess {
        int at,bt,pr,ct,ta,wt;
        string pro_id;

     /*
    artime = Arrival time,
    bt = Burst time,
    ct = Completion time,
    ta = Turn around time,
    wt = Waiting time
    */

    }process;

    bool compare(process a,process b)
    {
    return a.at < b.at;
    /* This schedule will always return TRUE
    if above condition comes*/

    }

    bool compare2(process a,process b)
    {
    return a.pr > b.pr;
    /* This schedule will always return TRUE
    if above condition comes*/

    }

void priority() {
    

    cout << "You've chosen non-preemptive Priority CPU - Scheduling Algorithm\n";
    process pro[10];
    int n, i, j;
    cout << "Enter the number of process:: ";
    cin >> n;
    cout << "Enter the process id arrival time burst time and priority ::: ";

    for ( i=0; i < n; i++)
    {
    cin >> pro[i].pro_id;
    cin >> pro[i].at;
    cin >> pro[i].bt;
    cin >> pro[i].pr;
    }

    sort(pro,pro+n,compare);

    /*sort is a predefined function  defined in algorithm.h header file,
    it will sort the schedules according to their arrival time*/

    pro[0].ct = pro[0].bt + pro[0].at;
    pro[0].ta = pro[0].ct - pro[0].at;
    pro[0].wt = pro[0].ta - pro[0].bt;
    i = 1;

    while(i < n-1)
    {

    for (j = i; j < n; j++)
    {
    if (pro[j].at > pro[i-1].ct)
    break;
    }
    sort (pro+i,pro+i+(j-i),compare2);
    pro[i].ct = pro[i-1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;
    i++;
    }
    pro[i].ct = pro[i-1].ct + pro[i].bt;
    pro[i].ta = pro[i].ct - pro[i].at;
    pro[i].wt = pro[i].ta - pro[i].bt;

    cout << "P	AT	BT	CT	TAT	WT	Priority\n";
    for (i = 0; i < n; i++)
    {
    //displaying all the values
    cout << pro[i].pro_id << "\t" << pro[i].at << "\t"<<pro[i].bt << "\t" << pro[i].ct << "\t" << pro[i].ta << "\t" << pro[i].wt << "\t" << pro[i].pr;
    cout << endl;
    }
        float avg_TAT = 0, avg_WT = 0;
        for (i = 0; i < n; i++)
        {
            avg_TAT += pro[i].ta;
            avg_WT += pro[i].wt;
        }
        avg_TAT = (float)avg_TAT/n;
        avg_WT = (float) avg_WT/n;
        cout << "\nAverage turn-around time: " << avg_TAT;
        cout << "\nAverage waiting time: " << avg_WT;
        cout << "\n";

}

void sjf() {
    
    cout << "You've chosen Shortest job First CPU - Scheduling Algorithm\n";
    int bt[20], at[10], n, i, j, temp, st[10], ft[10], wt[10], tat[10];
	//bt[]->burst time, at[]-> arrival time, st[]->start time, wt[]->waiting time, tat[]->turn around time
    int totwt = 0, tottat = 0;
    float awt, atat;
    char pn[10][10], t[10];//pn -> process number
    printf("Enter the number of process:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter process name, arrival time & burst time:");
        scanf("%s%d%d", pn[i], &at[i], &bt[i]);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (bt[i] < bt[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            st[i] = at[i];
        else
            st[i] = ft[i-1];
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
        tat[i] = ft[i] - at[i];
        totwt += wt[i];
        tottat += tat[i];
    }
    awt = (float)totwt/n;
    atat = (float)tottat/n;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for (i = 0; i < n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d", pn[i], at[i], bt[i], wt[i], tat[i]);
    printf("\nAverage waiting time is:%f", awt);
    printf("\nAverage turnaroundtime is:%f", atat);
}


int main() {
    int choice;
    cout << "1. Shortest Job First\n2. Priority non-preemptive\n";
    do {
        
        cout << "\nEnter choice";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sjf();
            break;
        
        case 2:
            priority();
            break;

        default:
            cout << "Invalid option\n";
            break;
        }
    } while (choice < 3);
    
    cout << "Name: Pratyush Kumar\n";
    cout << "Reg. No.: 19BCE0506\n";
    return 0;
}

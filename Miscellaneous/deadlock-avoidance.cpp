#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Process {
    string pid;
    int max_req;
    int current_alloc;
    int need;
};
Process process[10];

bool compare(Process a,Process b) {
    return a.need < b.need;
}

int main() {
    vector<string> safe_seq;
    int i, n, sum_current = 0, available;
    cout << "Enter the number of processes";
    cin >> n;
    cout << "Enter amount of available resources in OS";
    cin >> available;
    for (i = 0; i < n; i++) {
        cout << "Enter the process id, max_requirement and current allocation";
        cin >> process[i].pid >> process[i].max_req >> process[i].current_alloc;
    }

    for (i = 0; i < n; i++) {
        process[i].need = process[i].max_req - process[i].current_alloc;
    }
    
    sort(process,process+n,compare);

    for ( i = 0; i < n; i++) {
        sum_current += process[i].current_alloc;
    }

    available -= sum_current;
    
    for (i = 0; i < n; i++) {
        if (process[i].need > 0 && process[i].need <= available) {
            process[i].current_alloc = process[i].current_alloc - process[i].need;
            available -= process[i].need;
            process[i].need = -1;
            available += process[i].max_req;
            safe_seq.push_back(process[i].pid);
        }
    }
    
    if (safe_seq.size() != n) {
        cout << "Deadlock has occured\n";
        exit(0);
    }
    else {
        cout << "The safe sequence is: " << "\n";
        for (auto i = safe_seq.begin(); i != safe_seq.end(); i++) {
            cout << *i << " ";  
        }
        cout << "\n";
    }
    
    cout << "Resources available after whole algo is: " << available <<"\n";

    cout << "Enter the process number requesting";
    cin >> i;

    int request;

    cout << "Enter the amount of resouces requested";
    cin >> request;

    if (request <= process[i].need && request <= available) {
        cout << "Request granted";
        available -= request;
    } else {
        cout << "Request granted\n";
        exit(0);
    }

    return 0;
}

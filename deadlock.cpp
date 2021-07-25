#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdlib.h>

using namespace std;

int main() {
    int n, i; 

    cout << "Enter the number of processes: ";
    cin >> n;

    int max[n], alloc[n], avail, need[n], sum = 0;

    cout << "\n";

    cout << "Enter the number of resources available in the system";
    cin >> avail;

    for (i = 0; i < n; i++) {
        cout << "Enter the maximum requirement matrix for process P" << i;
        cin >> max[i];
    }

    cout << "\n\n";

    for (i = 0; i < n; i++) {
        cout << "Enter the current allocation matrix for process P" << i;
        cin >> alloc[i];
    }

    for (i = 0; i < n; i++) {
        need[i] = max[i] - alloc[i];
    }

    cout << "Need matrix is: ";
    for (i = 0; i < n; i++) {
        cout << need[i] << " ";
    }

    cout << "\n";

    for (i = 0; i < n; i++) {
        sum += alloc[i];
    }

    avail -= sum;

    cout << "At time T0 available is: " << avail << "\n";

    int count = 0, ans[n], ind = 0, f[n];
    
    for (i = 0; i < n; i++) {
        f[i] = 0;
    }

    do
    {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { 

				int flag = 0;  
				if (need[i] > avail){ 
					flag = 1; 
					break; 
				} 
			 
				if (flag == 0) { 
					ans[ind++] = i;
                    avail -= need[i];
					avail += max[i];
                    cout << "Process" << i << " completed\n"; 
					f[i] = 1;
                    count++; 
				} 
            }    	 
        } 
    } while(count != n);
    
    if (count != n) {
        cout << "DEADLOCK has occured";
        cout << "\n";
        exit(0);
    } else {
        cout << "System is in safe state\n";
        cout << "Safe sequence is:\n";
        for (i = 0; i < n; i++) {
            cout << ans[i] <<" ";
        }
        cout << "\n";
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{    
    int n, r, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\n");

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("\n"); 

    int max[n][r], alloc[n][r], avail[r], need[n][r], req[r];

    for (i = 0; i < n; i++) {
        printf("Enter the maximum requirement matrix for process P%d: ", i);
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0; i < n; i++) {
        printf("Enter the current allocation matrix for process P%d: ", i);
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\n\n");

    printf("Enter the initial available matrix");
    for (i = 0; i < r; i++)
    {
        scanf("%d", &avail[i]);
    }

    printf("\n\n");

    printf("Content of NEED matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\n");

	int f[n], ans[n], ind = 0; 
	for (i = 0; i < n; i++) { 
		f[i] = 0; 
	} 
	 
	int count = 0, y; 
	do
    {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1;
                    count++; 
				} 
			} 
        }    
    } while (count != n);

    if (count != n) {
        printf("DEADLOCK HAS OCCURRED!!");
        exit(0);
    } else {   
        printf("SAFE Sequence is: \n"); 
        for (i = 0; i < n; i++) 
            printf("P%d ", ans[i]); 
        printf("\n"); 
    }

    printf("\n");

    printf("Need matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("Availability matrix: \n");
    for (i = 0; i < r; i++) {
        printf("%d ", avail[i]);
    }

    printf("\n");

    printf("Enter the process number requesting");
    scanf("%d", &y);

    printf("Enter the instance of each resource type");
    for (i = 0; i < r; i++) {
        scanf("%d", &req[i]);
    }

    int flag = 0;
    for (i = 0; i < r; i++) {
        if (need[y][i] < req[i] && avail[i] < req[i]) {
            flag = 1;
            break;
        }

        if (flag == 0) {
            avail[i] = avail[i] - req[i];
            alloc[y][i] = alloc[y][i] + req[i];
            need[y][i] = need[y][i] - req[i];
        }
    }
    if (flag == 1) {
        printf("Request not granted\n");
    } else {
        printf("Request granted\n");
    }

	return 0;
} 

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int n;

#define THINKING 0
#define HUNGRY 1
#define EATING 2


int state[10];
int philosopher_num[10];

sem_t mutex;
sem_t sem_phil[10];

void * philosopher(void *);
void takechops(int);
void putchops(int);
void test(int);

int main() {
    int k, N;
    printf("Enter the number of philosophers");
    scanf("%d", &N);
    n = N;
    pthread_t tid[N];

    printf("Dining Phiosopher\n");
    
    for(k = 0; k < N; k++) {
        philosopher_num[k]=k;
    }
    
    sem_init(&mutex,0,1);

    for(k = 0; k < N; k++) 
        sem_init(&sem_phil[k],0,0);
    for(k = 0;k < N; k++) {
        pthread_create(&tid[k],NULL,philosopher,&philosopher_num[k]);
        printf("Philosopher #%d sits on the table.\n", k    +1);
    }
    for(k = 0; k < N; k++) 
        pthread_join(tid[k],NULL);

    return 0;
}

    #define LEFT i>0?(i-1)%n:n-1
    #define RIGHT (i+1)%n

void * philosopher(void *param) {
    int i = *((int *)param);
    int tt=1;
    int et=2;
    while(1) {
        sleep(tt);
        takechops(i);
        sleep(et);
        putchops(i);
    }
}

void takechops(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry\n",i);
    test(i);
    sem_post(&mutex);
    sem_wait(&sem_phil[i]);
}

void putchops(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d is thinking\n",i);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void test(int i) {
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT]!= EATING){
        state[i]=2;
        printf("Philosopher %d is eating\n",i);
        sem_post(&sem_phil[i]);
    }
}
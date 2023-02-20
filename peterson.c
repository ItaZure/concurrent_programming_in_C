#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>


bool flag[2] = {false, false};
int turn;

void my_thread_1(void){
    turn = 1;
    while(flag[1] == true && turn == 1); // busy wait
    printf("1");
    sleep(1); // sleep for 1 second
    flag[0] = false;
}

void my_thread_2(void){
    turn = 0;
    while(flag[0] == true && turn == 0); // busy wait
    printf("2");
    sleep(1);
    flag[1] = false;
}


int main(int argc, char const *argv[])
{
    pthread_t tid_1;
    pthread_t tid_2;

    pthread_create(&tid_1, NULL, (void*)&my_thread_1, NULL);
    pthread_create(&tid_2, NULL, (void*)&my_thread_2, NULL);

    pthread_exit(NULL);

    return 0;
}

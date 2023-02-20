#include <stdio.h>
#include <pthread.h>

void printint( int x ){
    while(1){
        printf("%d", x);
    }
}


int main(int argc, char const *argv[])
{
    pthread_t tid_1;
    pthread_t tid_2;

    pthread_create(&tid_1, NULL, (void*)&printint, 1);
    pthread_create(&tid_2, NULL, (void*)&printint, 2);

    pthread_exit(NULL);

    return 0;
}

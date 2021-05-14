#include <pthread.h>
#include <stdio.h> 
#include <unistd.h>

void *f1(void *arg)
{
    while(1){
    sleep(1);
    printf("f1 now\n");}
    return NULL;
}

void f2(void)
{
    while (1){
    sleep(1);
    printf("f2 later\n");}
}

int main(void)
{
    pthread_t new;

    pthread_create(&new,NULL,f1,NULL);
    f2();

}
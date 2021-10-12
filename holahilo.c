#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000
int saldo;
pthread_mutex_t saldoLock;

/*
void * printHola(void *arg)
{
    char *c = (char *)arg;
    printf("Hola desde un hilo %s \n", c);
    
    
    pthread_exit(NULL);
}
*/

void * suma100(void *arg)
{   
    int threadSaldo;
    pthread_mutex_lock(&saldoLock);
    threadSaldo = saldo;
    threadSaldo += 100;
    saldo = threadSaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    char *s = "¿Soy un argumento?";
    for (int i = 0; i < NUM_THREADS; i++)
    {
        //pthread_create(&threads[i], NULL, printHola, (void *) s);
        pthread_create(&threads[i], NULL, suma100, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Saldo final es: %d \n", saldo);

    pthread_exit(NULL);
}
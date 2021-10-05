#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handleSignal(int signal)
{
    printf("JAJAJA no me matas\n");
}

int main()
{
    signal(2, handleSignal);
    while (1)
    {
        printf("Trabajando \n");
        sleep(1);
    }

    return 0;
}
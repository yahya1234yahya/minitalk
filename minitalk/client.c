#include <stdio.h>
#include <signal.h>


void send_bits(int pid, char c)
{
    int i = 0;
    while(i < 8)
    {
        if((c & 128) == 128)
        {
            kill(pid , SIGUSR1);
            printf("1 is sent");
        }
        else
        {
            kill(pid , SIGUSR2);
            printf("0 is sent");
        }
        c <<=1;
        i++;
        usleep(1000);
    }
}

int main()
{
    
}
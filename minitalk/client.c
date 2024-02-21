#include <stdio.h>
#include <signal.h>


void send_bits(int pid, unsigned char c)
{
    int i = 0;
    while(i < 8)
    {
        if(c & 1)
        {
            kill(pid , SIGUSR1);
            printf("1 is sent");
        }
        else
        {
            kill(pid , SIGUSR2);
            printf("0 is sent");
        }
        c = c >> 1;
        i++;
        usleep(1000);
    }
}
void send_len(int pid, long c)
{
    int i = 0;
    while(i < 64)
    {
        if(c & 1)
        {
            kill(pid , SIGUSR1);
            printf("1 is sent");
        }
        else
        {
            kill(pid , SIGUSR2);
            printf("0 is sent");
        }
        c = c >> 1;
        i++;
        usleep(1000);
    }
}

int main(int argc ,char *argv[])
{
    long len;
    int pid;
    int i;

    pid = atoi(argv[1]);
    len = ft_strlen(argv[2]);
    send_len(pid, len);
    printf("lengh of the string is sent");
    while(i < len)
    {
        send_bits(pid, argv[2][i]);
        printf("Charactere '%c' is sent", argv[2][i]);
        i++;
    }
    printf("all sent");
}
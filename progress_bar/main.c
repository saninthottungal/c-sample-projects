#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int progress = 0;

    while (progress != 100)
    {
        printf("[");
        for (int i = 0; i < 10; i++)
        {
            if (i <= (progress) / 10)
            {
                printf("=");
            }
            else
            {
                printf(" ");
            }
        }

        progress = progress + 10;
        printf("]%d%%\n", progress);
        sleep(1);

        system("clear");
    }

    return 0;
}

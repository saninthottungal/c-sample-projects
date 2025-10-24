#include <stdio.h>

int main(int argc, char const *argv[])
{
    int progress = 0;

    printf("[");
    for (int i = 1; i <= 10; i++)
    {
        printf("=");
        progress = (i * 10);
    }

    printf("]%d%%\n", progress);

    return 0;
}

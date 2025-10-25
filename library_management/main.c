#include <stdio.h>
#include <string.h>

void showWelcomeMessage();

int main(int argc, char const *argv[])
{
    showWelcomeMessage();
    return 0;
}

void showWelcomeMessage()
{
    char *welcomeMessage = "Welcome to Udayam Vayanashaala";
    int length = strlen(welcomeMessage) + 6;

    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("/");
    }
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        if (i == 0 || i == length - 3)
        {
            printf("**");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n**");

    printf(" %s ", welcomeMessage);
    printf("**");
    printf("\n");

    for (int i = 0; i < length; i++)
    {
        if (i == 0 || i == length - 3)
        {
            printf("**");
        }
        else
        {
            printf(" ");
        }
    }

    printf("\n");

    for (int i = 0; i < length; i++)
    {
        printf("/");
    }

    printf("\n\n");
}

#include <stdio.h>
#include <string.h>

#include "library.h"

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

int showAvailableActions()
{
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Update Book\n");
    printf("5. Delete Book\n");
    printf("6. Issue/Return Book\n");
    printf("7. Exit\n");

    int option;
    printf("Please choose your option: ");
    scanf("%d", &option);

    return option;
}
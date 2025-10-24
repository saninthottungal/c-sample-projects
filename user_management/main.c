#include <stdio.h>

int main(int argc, char const *argv[])
{
    while (1)
    {
        int userSelection;
        printf("\n1. Register\n2. Login\n3. Exit\n");
        scanf(" %d", &userSelection);

        switch (userSelection)
        {
        case 1:
            printf("Registration initiated\n");
            return 0;

        case 2:
            printf("Login initiated\n");
            return 0;

        case 3:
            printf("Exited\n");
            return 0;
        }
    }
    return 0;
}

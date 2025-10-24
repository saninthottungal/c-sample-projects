#include <stdio.h>

#define MAX_USERS 50

typedef struct
{
    char username[20];
    char password[20];
} User;

void registerUser(User arr[], int index);

int main(int argc, char const *argv[])
{
    User users[MAX_USERS] = {0};
    int counter = 0;

    while (1)
    {
        int userSelection;
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Select an option: ");
        scanf(" %d", &userSelection);

        switch (userSelection)
        {
        case 1:
            printf("Register a new user\n");
            registerUser(users, counter);

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

void registerUser(User arr[], int index)
{
    User user;
    printf("\nEnter username(MAX 20 characters): ");
    scanf(" %s", user.username);
    printf("Enter password(MAX 20 characters): ");
    scanf(" %s", user.password);
}

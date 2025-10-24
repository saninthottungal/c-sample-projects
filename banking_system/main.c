#include <stdio.h>

typedef enum
{
    create,
    Deposit,
    withdraw,
    balance,
    exit,
    unknown,
} UserChoice;

UserChoice getUserChoice(UserChoice *choice);

int main(int argc, char const *argv[])
{
    UserChoice choice;
    getUserChoice(&choice);
    return 0;
}

UserChoice getUserChoice(UserChoice *choice)
{
    int numberChoice;
    printf("\n*** Bank Management System ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    scanf("%1d", &numberChoice);

    return unknown;
}

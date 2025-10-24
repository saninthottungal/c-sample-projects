#include <stdio.h>

typedef enum
{
    create,
    deposit,
    withdraw,
    balance,
    exit,
    unknown,
} UserChoice;

UserChoice getUserChoice();

int main()
{
    UserChoice choice = getUserChoice();

    return 0;
}

UserChoice getUserChoice()
{
    int numberChoice;
    printf("\n*** Bank Management System ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &numberChoice);

    switch (numberChoice)
    {
    case 1:
        return create;
        break;
    case 2:
        return deposit;
        break;
    case 3:
        return withdraw;
        break;
    case 4:
        return balance;
        break;
    case 5:
        return exit;
        break;
    default:
        return unknown;
    }
}

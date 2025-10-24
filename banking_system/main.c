#include <stdio.h>

typedef struct
{
    char name[20];
    int accountId;
    float balance;
} BankUser;

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
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void handleInvalidSelection();

int main()
{

    while (1)
    {

        UserChoice choice = getUserChoice();

        switch (choice)
        {
        case create:
            createAccount();
            break;
        case deposit:
            depositMoney();
            break;
        case withdraw:
            withdrawMoney();
            break;
        case balance:
            checkBalance();
            break;
        case unknown:
            handleInvalidSelection();
            break;
        case exit:

            return 0;
        }
    }

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

void createAccount() {}
void depositMoney() {}
void withdrawMoney() {}
void checkBalance() {}
void handleInvalidSelection()
{
    printf("\nInvalid choice. Please select a valid choice.\n");
}
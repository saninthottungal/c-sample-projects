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
void createAccount(BankUser *users, int *counter);
void depositMoney();
void withdrawMoney();
void checkBalance();
void handleInvalidSelection();
int doesAccountExists(BankUser *users, int accountId, int *counter);

int main()
{
    BankUser bankUsers[50] = {0};
    int counter = 0;

    while (1)
    {

        UserChoice choice = getUserChoice();

        switch (choice)
        {
        case create:
            createAccount(bankUsers, &counter);
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
    printf("\n\n*** Bank Management System ***\n");
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

void createAccount(BankUser *users, int *counter)
{
    BankUser user;
    printf("\nEnter your name: ");
    scanf(" %s", user.name);
    printf("Enter an account number: ");
    scanf(" %d", &user.accountId);

    if (doesAccountExists(users, user.accountId, counter))
    {
        printf("\n!!! User Already Exists !!!");
    }
    else
    {
        *(users + *counter) = user;
        (*counter)++;

        printf("\n!!! Account created Successfully !!!");
    }
}

void depositMoney() {}
void withdrawMoney() {}
void checkBalance() {}

int doesAccountExists(BankUser *users, int accountId, int *counter)
{
    for (int i = 0; i < *counter; i++)
    {
        if ((*(users + i)).accountId == accountId)
        {
            return 1;
        }
    }

    return 0;
}

void handleInvalidSelection()
{
    printf("\nInvalid choice. Please select a valid choice.\n");
}
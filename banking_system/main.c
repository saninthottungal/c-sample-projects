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
void depositMoney(BankUser *users, int *counter);
void withdrawMoney();
void checkBalance(BankUser *users, int *counter);
void handleInvalidSelection();
int doesAccountExists(BankUser *users, int accountId, int *counter, int *indexOf);

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
            depositMoney(bankUsers, &counter);
            break;
        case withdraw:
            withdrawMoney();
            break;
        case balance:
            checkBalance(bankUsers, &counter);
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

    int indexOfUser;
    if (doesAccountExists(users, user.accountId, counter, &indexOfUser))
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

void depositMoney(BankUser *users, int *counter)
{
    int accountId;
    printf("\n Enter your accountId: ");
    scanf(" %d", &accountId);
}
void withdrawMoney() {}
void checkBalance(BankUser *users, int *counter)
{
    int accountId;
    printf("\nPlease Enter your account number: ");
    scanf(" %d", &accountId);

    int indexOfUser;
    if (doesAccountExists(users, accountId, counter, &indexOfUser))
    {
        BankUser user = *(users + indexOfUser);
        printf("\n!!! Account balance for the account number %d is: %f !!!", user.accountId, user.balance);
    }
    else
    {
        printf("\n!!! Ooopsss.... Account not found !!!");
    }
}

int doesAccountExists(BankUser *users, int accountId, int *counter, int *indexOf)
{
    for (int i = 0; i < *counter; i++)
    {
        BankUser user = *(users + i);
        if (user.accountId == accountId)
        {
            *indexOf = i;
            return 1;
        }
    }

    *indexOf = -1;
    return 0;
}

void handleInvalidSelection()
{
    printf("\nInvalid choice. Please select a valid choice.\n");
}
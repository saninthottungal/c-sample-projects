#include <stdio.h>
#include "bank.h"

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
            withdrawMoney(bankUsers, &counter);
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
    int accountId, indexOf;
    printf("\nEnter your account number: ");
    scanf(" %d", &accountId);

    if (doesAccountExists(users, accountId, counter, &indexOf))
    {
        float amount;
        printf("Enter the amount to deposit: ");
        scanf(" %f", &amount);

        if (amount > 0)
        {
            BankUser user = *(users + indexOf);
            user.balance += amount;

            *(users + indexOf) = user;

            printf("\n!!! Amount of %.2f has been credited to your account !!!", amount);
            printf("\n!!! Your current balance is %.2f !!!", user.balance);
        }
        else
        {
            printf("\n!!! Please choose a valid Amount !!!");
        }
    }
    else
    {
        printf("\n!!! Ooopsss.... Account not found !!!");
    }
}
void withdrawMoney(BankUser *users, int *counter)
{
    int accountId, indexOf;
    printf("\nEnter your account number: ");
    scanf(" %d", &accountId);
    if (doesAccountExists(users, accountId, counter, &indexOf))
    {
        float amount;
        printf("Enter the amount to Withdraw: ");
        scanf(" %f", &amount);

        BankUser user = *(users + indexOf);

        if (amount <= user.balance)
        {
            user.balance -= amount;

            *(users + indexOf) = user;

            printf("\n!!! Amount of %.2f has been Debited From your account !!!", amount);
            printf("\n!!! Your current balance is %.2f !!!", user.balance);
        }
        else
        {
            printf("\n!!! Insufficient Balance !!!");
        }
    }
    else
    {
        printf("\n!!! Ooopsss.... Account not found !!!");
    }
}
void checkBalance(BankUser *users, int *counter)
{
    int accountId;
    printf("\nPlease Enter your account number: ");
    scanf(" %d", &accountId);

    int indexOfUser;
    if (doesAccountExists(users, accountId, counter, &indexOfUser))
    {
        BankUser user = *(users + indexOfUser);
        printf("\n!!! Account balance for the account number %d is: %.2f !!!", user.accountId, user.balance);
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
#ifndef BANK_H
#define BANK_H

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
void withdrawMoney(BankUser *users, int *counter);
void checkBalance(BankUser *users, int *counter);
void handleInvalidSelection();
int doesAccountExists(BankUser *users, int accountId, int *counter, int *indexOf);

#endif
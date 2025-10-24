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

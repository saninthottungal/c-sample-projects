#include <stdio.h>

int main(int argc, char const *argv[])
{
    int choice;
    float num1 = 0, num2 = 0;

    printf("\n-------------------------------\n");
    printf("Welcome to the Calculator\n");

    printf("\nChoose one of the following options: \n");
    printf(""
           "1. Add\n"
           "2. Substract\n"
           "3. Multiply\n"
           "4. Divide\n"
           "5. Modulus\n"
           "6. Power\n"
           "7. Exit\n"
           "");

    printf("Now, Enter your choice: ");
    scanf(" %d", &choice);

    if (choice != 1 &&
        choice != 2 &&
        choice != 3 &&
        choice != 4 &&
        choice != 5 &&
        choice != 6 &&
        choice != 7)
    {
        printf("\n\nInvalid Option Selected!!\n");
        return 0;
    }

    printf("\n\nPlease enter your first number: ");
    scanf(" %f", &num1);

    printf("Please enter your second number: ");
    scanf(" %f", &num2);

    return 0;
}

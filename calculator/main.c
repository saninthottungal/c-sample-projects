#include <stdio.h>
#include <math.h>

float sum(float num1, float num2);
float substraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
float modulus(float num1, float num2);
float power(float num1, float num2);

int main(int argc, char const *argv[])
{
    int choice;
    float num1 = 0, num2 = 0, result = 0;
    do
    {

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

        if (choice < 1 || choice > 7)
        {
            printf("\n\nInvalid Option Selected!!\n");
            return 0;
        }

        if (choice == 7)
        {
            return 0;
        }

        printf("\n\nPlease enter your first number: ");
        scanf(" %f", &num1);

        printf("Please enter your second number: ");
        scanf(" %f", &num2);

        switch (choice)
        {
        case 1:
            result = sum(num1, num2);
            break;
        case 2:
            result = substraction(num1, num2);
            break;
        case 3:
            result = multiplication(num1, num2);
            break;
        case 4:
            result = division(num1, num2);
            break;
        case 5:
            result = modulus(num1, num2);
            break;
        case 6:
            result = power(num1, num2);
            break;
        default:
            printf("\nInvalid option Selected\n");
            return 0;
        }

        printf("\n\nThe result of the operation is: %f\n", result);
    } while (choice != 7);

    return 0;
}

float sum(float num1, float num2) { return num1 + num2; }
float substraction(float num1, float num2) { return num1 - num2; }
float multiplication(float num1, float num2) { return num1 * num2; }
float division(float num1, float num2) { return num1 / num2; }
float modulus(float num1, float num2) { return fmod(num1, num2); }
float power(float num1, float num2) { return pow(num1, num2); }

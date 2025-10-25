#include <stdio.h>
#include <string.h>

void showWelcomeMessage();
int showAvailableActions();
void addBook();
void viewBooks();
void searchBooks();
void updateBook();
void deleteBook();
void issueOrReturnBook();
void showInvalidOptionSelected();

int main(int argc, char const *argv[])
{
    showWelcomeMessage();

    while (1)
    {
        int userChoice = showAvailableActions();
        switch (userChoice)
        {
        case 1:
            addBook();
            break;

        case 2:
            viewBooks();
            break;

        case 3:
            searchBooks();
            break;

        case 4:
            updateBook();
            break;

        case 5:
            deleteBook();
            break;

        case 6:
            issueOrReturnBook();
            break;

        case 7:
            return 0;

        default:
            showInvalidOptionSelected();
        }
    }

    return 0;
}

void showWelcomeMessage()
{
    printf("\n");
    printf("////////////////////////////////////\n");
    printf("//                                //\n");
    printf("// Welcome to Udayam Vayanashaala //\n");
    printf("//                                //\n");
    printf("////////////////////////////////////\n");
    printf("\n");
}

int showAvailableActions()
{
    printf("\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Update Book\n");
    printf("5. Delete Book\n");
    printf("6. Issue/Return Book\n");
    printf("7. Exit\n");

    int option;
    printf("Please choose your option: ");
    scanf("%d", &option);

    return option;
}

void showInvalidOptionSelected()
{
    printf("\n!!! Invalid option selected, please choose a valid option !!!\n");
}

//* Actions

void addBook() {}
void viewBooks() {}
void searchBooks() {}
void updateBook() {}
void deleteBook() {}
void issueOrReturnBook() {}

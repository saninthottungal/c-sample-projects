#include <stdio.h>
#include <string.h>

#define DB_PATH "library_db.csv"

typedef struct
{
    int id;
    char title[50];
    int year;

} Book;

void showWelcomeMessage();
int showAvailableActions();
void addBook();
void viewBooks();
void searchBooks();
void updateBook();
void deleteBook();
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
    printf("6. Exit\n");

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

void addBook()
{
    Book book;
    FILE *file = fopen(DB_PATH, "a+");

    if (file == NULL)
    {
        printf("\n!!! opening file failed !!!\n");
        return;
    }

    printf("\nEnter bookId: ");
    scanf("%d", &book.id);

    printf("Enter book name: ");
    getchar();
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0';
    printf("Enter the year: ");
    scanf("%d", &book.year);

    fprintf(file, "%d,%s,%d\n", book.id, book.title, book.year);
    fclose(file);

    printf("\n!!! Book added succesfully !!!\n");
}
void viewBooks()
{
    FILE *file = fopen(DB_PATH, "r");
    if (file == NULL)
    {
        printf("\n!!! opening file failed !!!\n");
        return;
    }

    printf("\n");
    char entry[1024];
    while (fgets(entry, sizeof(entry), file))
    {
        entry[strcspn(entry, "\n")] = '\0';

        char *token = strtok(entry, ",");
        while (token)
        {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }

        printf("\n");
    }
    fclose(file);
}
void searchBooks()
{
    FILE *file = fopen(DB_PATH, "r");
    if (file)
    {

        char line[1024];
        char bookId[20];
        int bookFound = 0;

        printf("\nEnter the bookId: ");
        scanf("%s", bookId);

        while (fgets(line, sizeof(line), file))
        {
            line[strcspn(line, "\n")] = '\0';

            char *token = strtok(line, ",");

            if (strcmp(bookId, token) == 0)
            {
                printf("\nBook Found\n");
                bookFound = 1;

                while (token)
                {
                    printf("%s ", token);
                    token = strtok(NULL, ",");
                }
                break;
            }
        }
        if (!bookFound)
        {
            printf("\n!!! Book not found !!!\n");
        }

        fclose(file);
        printf("\n");
    }
    else
    {
        printf("\n!!! opening file failed !!!\n");
    }
}
void updateBook() {}
void deleteBook() {}

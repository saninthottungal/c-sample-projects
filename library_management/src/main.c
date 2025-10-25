#include "library.h"

void showWelcomeMessage();
int showAvailableActions();

int main(int argc, char const *argv[])
{
    showWelcomeMessage();
    int userChoice = showAvailableActions();

    return 0;
}

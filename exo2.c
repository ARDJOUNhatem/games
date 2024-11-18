#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    int user_choice, computer_choice;
    
    srand(time(0)); // Initialize random number generator

    do {
        printf("Choose (0: Rock, 1: Paper, 2: Scissors): ");
        scanf("%d", &user_choice);
        computer_choice = rand() % 3;

        printf("Computer chose: %s\n", choices[computer_choice]);

        if (user_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((user_choice == 0 && computer_choice == 2) ||
                   (user_choice == 1 && computer_choice == 0) ||
                   (user_choice == 2 && computer_choice == 1)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }
    } while (user_choice >= 0 && user_choice < 3);

    return 0;
}
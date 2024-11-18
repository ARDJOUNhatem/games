#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    srand(time(0)); // Initialize random number generator
    number = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("Guess the number between 1 and 100:\n");

    do {
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Your guess is too high. Try again.\n");
        } else if (guess < number) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", number, attempts);
        }
    } while (guess != number);

    return 0;
}
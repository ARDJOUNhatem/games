#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *words[] = {"software", "algorithm", "development", "code", "application"};
const int num_words = sizeof(words) / sizeof(words[0]);

int main() {
    srand(time(0));
    const char *word = words[rand() % num_words];
    char guess[50];
    int attempts = 3;

    printf("Guess the word! You have %d attempts.\n", attempts);

    while (attempts > 0) {
        printf("Enter the word: ");
        scanf("%s", guess);

        if (strcmp(guess, word) == 0) {
            printf("Congratulations! You guessed the word: %s\n", word);
            return 0;
        } else {
            attempts--;
            printf("Wrong! You have %d attempts left.\n", attempts);
        }
    }
    printf("You lost! The word was: %s\n", word);
    return 0;
}
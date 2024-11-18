#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6

const char *words[] = {"software", "algorithm", "development", "code", "application"};
const int num_words = sizeof(words) / sizeof(words[0]);

void display_word(const char *word, int *guessed) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {
    srand(time(0));
    const char *word = words[rand() % num_words];
    int guessed[strlen(word)];
    memset(guessed, 0, sizeof(guessed));
    int tries = 0;
    char guess;

    while (tries < MAX_TRIES) {
        printf("Word: ");
        display_word(word, guessed);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        int found = 0;

        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Wrong! You have %d tries left.\n", MAX_TRIES - tries);
        }

        if (memchr(guessed, 0, sizeof(guessed)) == NULL) {
            printf("Congratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }
    printf("You lost! The word was: %s\n", word);
    return 0;
}
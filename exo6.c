#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[SIZE];
    int user_numbers[SIZE];
    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100; // Numbers between 0 and 99
    }

    printf("Random numbers: ");
    print_array(numbers, SIZE);

    // User sorts the numbers
    for (int i = 0; i < SIZE; i++) {
        printf("Enter number %d in ascending order: ", i + 1);
        scanf("%d", &user_numbers[i]);
    }

    // Compare the lists
    int correct = 0, incorrect = 0;
    for (int i = 0; i < SIZE; i++) {
        if (user_numbers[i] == numbers[i]) {
            correct++;
        } else {
            incorrect++;
        }
    }

    printf("Number of correct placements: %d\n", correct);
    printf("Number of incorrect placements: %d\n", incorrect);

    return 0;
}
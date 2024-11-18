#include <stdio.h>

char board[3][3]; // Game board

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

int check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Column win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonal win
    return 0; // No winner
}

int main() {
    initialize_board();
    int row, col, turn = 0;
    while (turn < 9) {
        print_board();
        printf("Player %d, enter row and column (0-2): ", turn % 2 + 1);
        scanf("%d %d", &row, &col);
        
        if (board[row][col] == ' ') {
            board[row][col] = (turn % 2 == 0) ? 'X' : 'O';
            if (check_winner()) {
                print_board();
                printf("Player %d wins!\n", turn % 2 + 1);
                return 0;
            }
            turn++;
        } else {
            printf("Spot is taken! Try again.\n");
        }
    }
    print_board();
    printf("It's a draw!\n");
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

const int BOARD_SIZE = 15;
const int NUM_PLAYERS = 4;
const int NUM_PAWNS = 4;

class LudoGame {
private:
    int board[BOARD_SIZE];
    int playerPositions[NUM_PLAYERS][NUM_PAWNS];
    int currentPlayer;
    bool gameOver;

public:
    LudoGame() {
        std::fill_n(board, BOARD_SIZE, -1);
        std::fill_n(&playerPositions[0][0], NUM_PLAYERS * NUM_PAWNS, -1);
        currentPlayer = 0;
        gameOver = false;
    }

    void displayBoard() const {
        system("clear");  // For Unix-based systems
        // system("cls");  // For Windows-based systems

        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i] == -1) {
                std::cout << " - ";
            } else {
                std::cout << " " << board[i] << " ";
            }

            if ((i + 1) % 5 == 0) {
                std::cout << std::endl;
            }
        }
    }

    void rollDice() {
        int diceRoll = rand() % 6 + 1;
        std::cout << "Player " << currentPlayer + 1 << " rolled a " << diceRoll << std::endl;

        movePawn(diceRoll);
    }

    void movePawn(int steps) {
        int& currentPosition = playerPositions[currentPlayer][0];

        if (currentPosition == -1) {
            if (steps == 6) {
                currentPosition = 0;
            }
        } else {
            currentPosition += steps;

            if (currentPosition >= BOARD_SIZE) {
                currentPosition = -1;
            }
        }

        displayBoard();
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
    }

    bool isGameOver() const {
        return gameOver;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    LudoGame game;

    while (!game.isGameOver()) {
        game.rollDice();
        game.switchPlayer();

        // Add conditions to check for a winning state or end the game
        // ...

        // For simplicity, the game loop here runs indefinitely; you may want to add conditions for game over.
    }

    return 0;
}

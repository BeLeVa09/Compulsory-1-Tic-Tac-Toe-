#include <iostream>
#include <string>
#include <vector>

//std::string row1{ "| A | B | C |\n" };      
//std::string row2{ "| D | E | F |\n" };      // The characters we wish to change here are index 2, 6 & 10
//std::string row3{ "| G | H | I |\n" };      // Old system
void menu();

std::vector <char> board{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
std::vector <char> takenSquares{ '0', '0', '0', '0', '0', '0', '0', '0', '0'};
int takenSquaresCounter{ 0 };
char input{};

int getInput() {

    std::cin >> input;

    for (int a{ 0 }; a < takenSquaresCounter; a++) {
        if (input == takenSquares[a]) {
            std::cout << "Square is already taken!\n";
            system("pause");
            return 0;
        }
    }
    takenSquares[takenSquaresCounter] = input;
    takenSquaresCounter++;

    switch (input) {        // Each letter on the grid is given a specific value so that the grid becomes a "magic square"
    case '1':               // A magic square is an X*X grid (in this case 3*3) where each "tile" is assigned a value so that each row, coloumn and diagonal will sum up to the same value
        return 2;           // This grid looks like this:
        break;              // A(2) B(7) C(6)
                            // D(9) E(5) F(1)
    case '2':               // G(4) H(3) I(8)
        return 7;           // When the grid is arranged in this way, any row, coloumn or diagonal added together sums up to 15
        break;              // This system makes it so you simply store the tiles assigned value in an array for the player and then add them together
                            // If the sum of 3 array values is 15 then that player has won
    case '3':
        return 6;
        break;

    case '4':
        return 9;
        break;

    case '5':
        return 5;
        break;

    case '6':
        return 1;
        break;

    case '7':
        return 4;
        break;

    case '8':
        return 3;
        break;

    case '9':
        return 8;
        break;

    default:
        return 0;
        break;
    }
}

void drawGrid() {
    std::string space{ "\t\t\t\t\t\t     " };

    std::cout << "\n\n" << space << "---------------\n";
    std::cout << space;
    for (int i{ 0 }; i < board.size(); i++) {
        if (i != 0 && i % 3 == 0) {
            std::cout << "\n" << space;
        }
        std::cout << "| " << board[i] << " |";
    }
    std::cout << '\n' << space << "---------------\n";

}

void swapGrid(int index, char playerID) {
    if (index > 47) {
        index -= 48;
    }
    board[(index - 1)] = playerID;
}

void win(int player) {
    std::cout << "Player " << player << " has won!\n";
    system("pause");
    menu();
}

void calculateWin(int inArray[5], int player) {          // Checking to see if a player has won by running calculations on the hidden values they have "taken" from the tiles
    for (int j{ 0 }; j < 3; j++) {
        for (int k{ 1 }; k < 4; k++) {
            for (int l{ 2 }; l < 5; l++) {
                if ((inArray[j] + inArray[k] + inArray[l]) == 15) {
                    win(player);
                }
            }
        }
    }
    return;
}

void game() {
    swapGrid(1, '1');
    swapGrid(2, '2');
    swapGrid(3, '3');
    swapGrid(4, '4');
    swapGrid(5, '5');
    swapGrid(6, '6');
    swapGrid(7, '7');
    swapGrid(8, '8');
    swapGrid(9, '9');

    takenSquaresCounter = 0;
    drawGrid();

    bool validInput = 1;
    int player1[5]{ 15, 15, 15, 15, 15 };
    int player2[5]{ 15, 15, 15, 15, 15 };
    int takenSquares[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int index1{ 0 };
    int index2{ 0 };
    int takenIndex{ 0 };

    for (int i{ 0 }; i < 9; i++) {
        validInput = 1;
        do {
            system("cls");
            drawGrid();

            if (i % 2 == 0) {
                std::cout << "Player 1's turn:\n";
            }
            else {
                std::cout << "Player 2's turn:\n";
            }

            int num{ getInput() };
            if (num == 0) {
                validInput = 0;
            }
            else {
                validInput = 1;

                if (i % 2 == 0) {
                    player1[index1] = num;
                    takenSquares[takenIndex] = num;

                    swapGrid(input, 'X');
                    drawGrid();
                    calculateWin(player1, 1);
                }
                else {
                    player2[index2] = num;
                    takenSquares[takenIndex] = num;

                    swapGrid(input, 'O');
                    drawGrid();
                    calculateWin(player2, 2);
                }
            }

            
        } while (validInput != 1);

        index1++;
        index2++;
        takenIndex++;

    }
    std::cout << "It's a draw!";
    system("pause");
    return;
}

void menu() {
    int answer{};

    do {
        system("cls");      // This mess of \t under here is just to make the menu look good
        // The seemingly excessive use of '\' in the text beneath is to actually have it display properly since '\' is used to declare that an important symbol is coming up
        // So I used two '\' in a row to make the first one declare the second, but since the second one doesn't have a function it gets printed instead
        // The '\' used in the top and bottom lines are completely decorative as the only purpose they serve is to line up the code here in the editor, you can go without them but it looks better this way
        std::cout << "\t  |  _______       _______          _______    \     _______          _______   _______   _______  |\n";
        std::cout << "\t  |     |      |   |                   |      /\\    |                   |      |     |   |        |\n";
        std::cout << "\t  |     |      |   |                   |     /  \\   |                   |      |     |   |___     |\n";
        std::cout << "\t  |     |      |   |                   |    /____\\  |                   |      |     |   |        |\n";
        std::cout << "\t  |     |      |   |______             |   /      \\ |______             |      |_____|   |______  |\n";
        std::cout << "\t  |_________________________________________________\______________________________________________|\n";
        std::cout << "\t\t\t\t\t     |                     |\n";
        std::cout << "\t\t\t\t\t     | 1. Player VS Player |\n";
        std::cout << "\t\t\t\t\t     |                     |\n";
        std::cout << "\t\t\t\t\t     | 2.    Exit Game     |\n";
        std::cout << "\t\t\t\t\t     |_____________________|\n\n\n";

        std::cin >> answer;

        switch (answer) {
        case 1:
            system("cls");
            game();
            break;

        case 2:
            break;

        default:
            std::cout << "Invalid input\n";

        }
    } while (answer != 2);
}

int main() {
    menu();
    return 0;
}

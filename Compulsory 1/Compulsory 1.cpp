#include <iostream>
#include <string>
#include <vector>

//std::string row1{ "| A | B | C |\n" };      
//std::string row2{ "| D | E | F |\n" };      // The characters we wish to change here are index 2, 6 & 10
//std::string row3{ "| G | H | I |\n" };

int getInput() {
    char input{};

    std::cin >> input;

    switch (input) {        // Each letter on the grid is given a specific value so that the grid becomes a "magic square"
    case 'A': case 'a':     // A magic square is an X*X grid (in this case 3*3) where each "tile" is assigned a value so that each row, coloumn and diagonal will sum up to the same value
        return 2;           // This grid looks like this:
        break;              // A(2) B(7) C(6)
                            // D(9) E(5) F(1)
    case 'B': case 'b':     // G(4) H(3) I(8)
        return 7;           // When the grid is arranged in this way, any row, coloumn or diagonal added together sums up to 15
        break;              // This system makes it so you simply store the tiles assigned value in an array for the player and then add them together
                            // If the sum of 3 array values is 15 then that player has won
    case 'C': case 'c':
        return 6;
        break;

    case 'D': case 'd':
        return 9;
        break;

    case 'E': case 'e':
        return 5;
        break;

    case 'F': case 'f':
        return 1;
        break;

    case 'G': case 'g':
        return 4;
        break;

    case 'H': case 'h':
        return 3;
        break;

    case 'I': case 'i':
        return 8;
        break;

    default:
        return 0;
        break;
    }
}

void drawGrid() {
    std::vector <char> board{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
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

//void swapGrid(int num, char playerID) {
//    switch (num) {
//    case 1:
//        row1[2] = playerID;
//        break;
//
//    case 7:
//        row1[6] = playerID;
//        break;
//
//    case 6:
//        row1[10] = playerID;
//        break;
//
//    case 9:
//        row2[2] = playerID;
//        break;
//
//    case 5:
//        row2[6] = playerID;
//        break;
//
//    case 1:
//        row2[10] = playerID;
//        break;
//
//    case 4:
//        row3[2] = playerID;
//        break;
//
//    case 3:
//        row3[6] = playerID;
//        break;
//
//    case 8:
//        row3[10] = playerID;
//        break;
//    }
//}

void swapGrid(int index, char playerID) {
    switch (index) {
        
    }
}

int calculateWin(int inArray[5]) {          // Checking to see if a player has won by running calculations on the hidden values they have "taken" from the tiles
    for (int j{ 0 }; j < 2; j++) {
        for (int k{ 1 }; k < 3; k++) {
            for (int l{ 2 }; l < 4; l++) {
                std::cout << inArray[j] + inArray[k] + inArray[l];
                system("pause");
                if ((inArray[j] + inArray[k] + inArray[l]) == 15) {
                    return 15;
                }
            }
        }
    }
    return -1;
}

void game() {
    /*swapGrid(2, 'A');
    swapGrid(7, 'B');
    swapGrid(6, 'C');
    swapGrid(9, 'D');
    swapGrid(5, 'E');
    swapGrid(1, 'F');
    swapGrid(4, 'G');
    swapGrid(3, 'H');
    swapGrid(8, 'I');*/

    drawGrid();

    bool validInput = 1;
    int player1[5]{ 10, 10, 10, 10, 10 };
    int player2[4]{ 10, 10, 10, 10 };
    int takenSquares[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int index1{ 0 };
    int index2{ 0 };
    int takenIndex{ 0 };
    bool winningPlayer{ 0 };

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
            }

            if (i % 2 == 0) {
                player1[index1] = num;
                takenSquares[takenIndex] = num;

                //swapGrid(num, 'X');
                drawGrid();

                int win1 = calculateWin(player1);
                if (win1 == 15) {
                    i = 9;
                    std::cout << "Player 1 has won!\n";
                    winningPlayer = 1;
                }
            }
            else {
                player2[index2] = num;
                takenSquares[takenIndex] = num;

                //swapGrid(num, 'O');
                drawGrid();

                int win2 = calculateWin(player2);
                if (win2 == 15) {
                    i = 9;
                    std::cout << "Player 2 has won!\n";
                    winningPlayer = 1;
                }
            }
        } while (validInput != 1);

        index1++;
        index2++;
        takenIndex++;

    }
    if (winningPlayer == 0) {
        std::cout << "It's a draw!\n";
    }
    system("pause");
}

void gameVsAi() {

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
        std::cout << "\t\t\t\t\t     | 2.   Player VS AI   |\n";
        std::cout << "\t\t\t\t\t     |                     |\n";
        std::cout << "\t\t\t\t\t     | 3.    Exit Game     |\n";
        std::cout << "\t\t\t\t\t     |_____________________|\n\n\n";

        std::cin >> answer;

        switch (answer) {
        case 1:
            system("cls");
            game();
            break;

        case 2:
            system("cls");
            //gameVsAi();
            break;

        case 3:
            break;

        default:
            std::cout << "Invalid input\n";

        }
    } while (answer != 3);
}

int main() {
    menu();
}

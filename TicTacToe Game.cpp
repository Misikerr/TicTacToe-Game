#include <iostream>
#include <cstdlib> // For system("clear") or system("cls")
#include <ctime>   // For random AI moves
#include <iomanip> 

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'X';
bool gameTie = false;
string name1, name2;
int width = 60;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void toeBox() { 
    int x = 39;
    cout << setw(width) <<" _______________________ \n";
    cout << setw(width) <<"|                       |\n";
    cout << setw(width) <<"|      TIC TAC TOE      |\n";
    cout << setw(width) <<"|_______________________|\n";
    cout << setw(width) <<"|***********************|\n";
    cout << setw(width) <<"|*|     |      |      |*|\n";
    cout << setw(x)     <<"|*|  " << space[0][0] << "  |  " << space[0][1] << "   |  " << space[0][2] << "   |*|\n";
    cout << setw(width) <<"|*|_____|______|______|*|\n";
    cout << setw(width) <<"|*|     |      |      |*|\n";
    cout <<setw(x)      <<"|*|  " << space[1][0] << "  |  " << space[1][1] << "   |  " << space[1][2] << "   |*|\n";
    cout << setw(width) <<"|*|_____|______|______|*|\n";
    cout << setw(width) <<"|*|     |      |      |*|\n";
    cout << setw(x)     <<"|*|  " << space[2][0] <<  "  |  " << space[2][1] << "   |  " << space[2][2] << "   |*|\n";
    cout << setw(width) <<"|*|     |      |      |*|\n";
    cout << setw(width) <<" *********************** \n";
}


bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    
    gameTie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                gameTie = false;
                return false;
            }
        }
    }
    return false;
}

void gameLogic() {
    int digit;
    bool validChoice = false;

    while (!validChoice) {
        clearConsole();
        toeBox();
        if (token == 'X') {
            cout << setw(35) << name1 << " Please Enter Choice (1-9): ";
        } else {
            cout << setw(35) << name2 << " Please Enter Choice (1-9): ";
        }
        cin >> digit;
        if (cin.fail()) {  // Invalid input check
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        if (digit < 1 || digit > 9) {
            cout << "Invalid choice. Please enter a number between 1 and 9.\n";
            continue;
        }

        int row = (digit - 1) / 3;
        int column = (digit - 1) % 3;

        if (space[row][column] != 'X' && space[row][column] != 'O') {
            space[row][column] = token;
            token = (token == 'X') ? 'O' : 'X';
            validChoice = true;
        } else {
            cout << "This space is already occupied. Try again.\n";
        }
    }
}

void resetGame() {
    char defaultSpace = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = defaultSpace++;
        }
    }
    token = 'X';
    gameTie = false;
}

void aiMove() {
    
    int row, column;
    do {
        int move = rand() % 9 + 1;
        row = (move - 1) / 3;
        column = (move - 1) % 3;
    } while (space[row][column] == 'X' || space[row][column] == 'O');

    space[row][column] = 'O';  // AI always plays 'O'
    cout << "AI played O at position " << (row * 3 + column + 1) << endl;
}

void singlePlayerGame() {
    resetGame();
    clearConsole();
    cout << setw(58) <<"Enter your name: ";
    getline(cin, name1);
    name2 = "AI";

    while (!checkWinner()) {
        clearConsole();
        toeBox();
        if (token == 'X') {
            gameLogic();
        } else {
            aiMove();
            token = 'X';
        }
    }

    clearConsole();
    toeBox();
    if (gameTie) {
        cout << setw(width) <<"It's a draw!\n";
    } else {
        cout << setw(70) <<"*************************************************\n";
        cout << setw(30) <<((token == 'X') ? name2 : name1) << " Wins!\n";
        cout << setw(70) <<"*************************************************\n";

        char a = 1;
        cout <<"please enter any key with out power button "<< a;
        string button;
        cin.ignore();
        getline(cin,button);
    }
}


void twoPlayerGame() {
    resetGame();
    clearConsole();
    cout << setw(58) << "Enter the name of the First player : ";
    getline(cin, name1);
    cout << setw(58) << "Enter the name of the Second player: ";
    getline(cin, name2);

    while (!checkWinner()) {
        clearConsole();
        toeBox();
        gameLogic();
    }

    clearConsole();
    toeBox();
    if (gameTie) {
        cout << setw(width) << "It's a draw!\n";
    } else {
        cout << setw(70) << "*************************************************\n";
        cout << setw(30) << ((token == 'X') ? name2 : name1) << " Wins!\n";
        cout << setw(70) << "*************************************************\n";
    }
    cout << "\nPress Enter to return to the menu...";
    cin.ignore();
}

void showMenu() {
    int choice;
    while (true) {
        clearConsole();
        cout << setw(width) << " _______________________\n";
        cout << setw(width) << "|                       |\n";
        cout << setw(width) << "|      TIC TAC TOE      |\n";
        cout << setw(width) << "|_______________________|\n";
        cout << setw(width) << "|1. Start New Game      |\n";
        cout << setw(width) << "|2. Single player       |\n";
        cout << setw(width) << "|3. View Game Rules     |\n";
        cout << setw(width) << "|4. Exit                |\n";
        cout << setw(width) << "*************************\n";
        cout << setw(40) << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                twoPlayerGame();
                break;
            case 2:
                singlePlayerGame();
                break;
            case 3:
                clearConsole();
                cout << setw(width) << " ____________________________________________________________________________________________\n";
                cout << setw(width) << "|                                                                                            |\n";
                cout << setw(width) << "|                                      TIC TAC TOE RULES:                                    |\n";
                cout << setw(width) << "|____________________________________________________________________________________________|\n";
                cout << setw(width) << "|********************************************************************************************|\n";
                cout << setw(width) << "|1. The game is played on a 3x3 grid.                                                        |\n";
                cout << setw(width) << "|2. Players take turns placing their marks (X or O) in an empty cell.                        |\n";
                cout << setw(width) << "|3. The first player to get 3 marks in a row (horizontally, vertically, or diagonally) wins. |\n";
                cout << setw(width) << "|4. If all 9 cells are filled and no one has won, the game is a tie.                         |\n";
                cout << setw(width) << "|                  Press Enter to return to the menu....                                     |\n";
                cout << setw(width) << "**********************************************************************************************\n";
                cin.get();
                break;
            case 4:
                cout << "Exiting the game. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
                cin.get();
                break;
        }
    }
}


int main() {
    srand(time(0));
    showMenu();
    while (!checkWinner()) {
        gameLogic();
    }
    clearConsole();
    toeBox();
    if (gameTie) {
        cout << "It's a draw!\n";
    } else {
        cout << setw(70) <<"*************************************************\n";
        cout <<  setw(30) <<"\t\t"<< ((token == 'X') ? name2 : name1) << " Wins!\n";
        cout << setw(70) <<"*************************************************\n";
    }
    return 0;
}

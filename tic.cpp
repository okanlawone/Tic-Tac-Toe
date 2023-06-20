#include<iostream>
using namespace std;

char board[3][3];
int player;

void initializeBoard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j];
            if(j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if(i < 2) {
            cout << "---------" << endl;
        }
    }
}

void markBoard(char mark, int position) {
    int row = (position-1) / 3;
    int col = (position-1) % 3;
    if(board[row][col] != ' '){
        cout << "Invalid move, try again." << endl;
    }else{
        board[row][col] = mark;
    }
}

bool checkWin(char mark) {
    for(int i=0; i<3; i++)
        if(board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return true;

    for(int i=0; i<3; i++)
        if(board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
            return true;

    if(board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return true;
    if(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return true;

    return false;
}

void playerMove() {
    int position;
    cout << "Enter a number (1-9):  ";
    cin >> position;
    markBoard('X', position);
}

void aiMove() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(checkWin('O')) {
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(checkWin('X')) {
                    board[i][j] = 'O';
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe! Choose an option:\n1. Play against AI\n2. Two-player game\n";
    cin >> player;

    if(player == 1) {
        initializeBoard();
        do {
            displayBoard();
            playerMove();
            if(checkWin('X')) {
                displayBoard();
                cout << "You win!";
                break;
            }
            aiMove();
            if(checkWin('O')) {
                displayBoard();
                cout << "AI wins!";
                break;
            }
        } while(true);
    } else {
        int currentPlayer = 0;
        char mark;
        int position;
        initializeBoard();
        do {
            displayBoard();
            mark = currentPlayer == 0 ? 'X' : 'O';
            cout << "Player " << currentPlayer + 1 << ", enter a number (1-9):  ";
            cin >> position;
            markBoard(mark, position);
            if(checkWin(mark)){
                displayBoard();
                cout << "Player " << currentPlayer + 1 << " wins!";
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2;
        } while(true);
    }
    return 0;
}

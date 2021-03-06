//
//  main.cpp
//  gotoEightQueens
//
//  Created by Jon Horn on 2/17/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

void print(int array[8][8]) {
//    for (int j = 0; j < 8; j++) {
//        for(int k = 0; k < 8; k++) {
//            cout << array[j][k] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
}

void findEightQueens(int startingRow, int startingColumn) {
    int board[8][8] = {0}, row, column, i;
    
    board[startingRow][startingColumn] = 1;
nc:
    column++;
    row = -1;
    if (column == 8)
        goto print;
nr:
    row++;
    if (row == 8)
        goto backtrack;
    for (i = 0; i < column; i++) { // row test
        if (board[row][i])
            goto nr;
    }
    for (i = 1; row - i >= 0 && column - i >= 0; i++) { // up diagonal
        if (board[row - i][column - i])
            goto nr;
    }
    for (i = 1; row + i <= 7 && column - i >= 0; i++) { // down diagonal
        if (board[row + i][column - i]) {
            goto nr;
        }
    }
    board[row][column] = 1;
    goto nc;
backtrack:
    column--;
    if (column == -1) {
        return;
    }
    row = 0;
    while (board[row][column] != 1) {
        row++;
    }
    board[row][column] = 0;
    goto nr;
print:
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            cout << board[j][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main() {
    findEightQueens(0, 0);
}

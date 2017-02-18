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
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            cout << array[j][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int board[8][8] = {0}, r, c = 0, i = 0;

    board[0][0] = 1;
//    print(board);
nc:
    c++;
    r = -1;
    if (c == 8) {
        goto print;
    }
nr:
    r++;
    if (r == 8)
        goto backtrack;
    for (i = 0; i < c; i++) { // row test
        if (board[r][i])
            goto nr;
    }
    for (i = 1; r - i >= 0 && c - i >= 0; i++) { // up diagonal
        if (board[r - i][c - i])
            goto nr;
    }
    for (i = 1; r + i <= 7 && c - i >= 0; i++) { // down diagonal
        if (board[r + i][c - i]) {
            goto nr;
        }
    }
    board[r][c] = 1;
    goto nc;
backtrack:
    c--;
    if (c == -1) {
        return 0;
    }
    r = 0;
    while (board[r][c] != 1) {
        r++;
    }
    board[r][c] = 0;
    goto nr;
print:
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            cout << board[j][k] << " ";
        }
        cout << endl;
    }
}

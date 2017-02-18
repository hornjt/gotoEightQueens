//
//  main.cpp
//  gotoEightQueens
//
//  Created by Jon Horn on 2/17/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int board[8][8] = {0}, r = -1, c = 0, i = 0;

    board[0][0] = 1;
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            cout << board[j][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
nc:
    c++;
    if (c == 8) {
        cout << "done";
        goto print;
    }
nr:
    r++;
    if (r == 8)
        goto backtrack;
    for (i = 0; i < c; i++) { // row test
        if (board[r][i] == 1)
            goto nr;
    }
    for (i = 0; i < r; i++) { // column test
        if (board[i][c] == 1)
            goto nc;
    }
    for (i = 1; r - i >= 0 && c - i >= 0; i++) { // up diagonal
        if (board[r - i][c - i] == 1)
            goto nr;
    }
    for (i = 1; i < 8; i++) { // down diagonal
        if (board[r + i][c - i] == 1)
            goto nr;
    }
    board[r][c] = 1;
    goto nc;
backtrack:
    c--;
    if (c == -1) {
        for (int j = 0; j < 8; j++) {
            for(int k = 0; k < 8; k++) {
                cout << board[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "hit c = -1" << endl;
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

//
//  main.cpp
//  gotoEightQueens
//
//  Created by Jon Horn on 2/17/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int board[8][8] = {0}, r = -1, c = 0, i = 0;
nc: c++;
//    if (c == 8)
//        goto print;
nr: r++;
    if (r == 8)
        goto backtrack;
    for (i = 0; i < c; i++) {   // row test
        if (board[r][i]) goto nr;
    }
    for (i = 0; i < r; i++) {
        if (board[i][c]) goto nr;   // column test
    }
    for (i = 1; r >= 0 && c >= 0; i++) {
        if (board[r - i][c - i]) goto nr;   // up diagonal
    }
    for (i = 0; r < 8 && c >= 0; i++) {
        if (board[r + i][r - i]) goto nr;   // down diagonal
    }
//backtrack: c--;
}

//
//  main.cpp
//  gotoEightQueens
//
//  Created by Jon Horn on 2/17/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>

//void print() {
//    for (int j = 0; j < 8; j++) {
//        for(int k = 0; k < 8; k++) {
//            std::cout << board[j][k] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}

int main() {
    int board[8][8] = {0}, r = -1, c = 0, i = 0;
    
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            std::cout << board[j][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
//    print();
    board[0][0] = 1;
nc:
    c++;
    if (c == 8) {
        std::cout << "done";
        goto print;
    }
nr:
    r++;
    if (r == 8)
        goto backtrack;
    for (i = 0; i < c; i++) { // row test
        if (board[r][i] == 0)
            goto nr;
    }
    for (i = 0; i < r; i++) { // column test
        if (board[i][c] == 0)
            goto nc;
    }
    for (i = 1; r >= 0 && c >= 0; i++) { // up diagonal
        if (board[r - i][c - i] == 0)
            goto nr;
    }
    for (i = 1; r < 8 && c >= 0; i++) { // down diagonal
        if (board[r + i][r - i] == 0)
            goto nr;
    }
    board[r][c] = 1;
    goto nc;
backtrack:
    c--;
    if (c == -1) return 0;
    r = 0;
    while (board[r][c] != 1) {
        board[r][c] = 0;
        goto nr;
    }
print:
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            std::cout << board[j][k] << " ";
        }
        std::cout << std::endl;
    }
}

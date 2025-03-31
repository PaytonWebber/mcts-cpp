#include <cassert>
#include <iostream>
#include <vector>
#include <array>
#include "tictactoe.hpp"

void testInitialState() {
    TicTacToeState state;
    for (int i = 0; i < 9; ++i) {
        assert(state.board[i] == EMPTY);
    }
    assert(state.current_player == X);
}

void testStep() {
    TicTacToeState state;
    TicTacToeState newState = state.step(0);
    assert(newState.board[0] == X);
    assert(newState.current_player == O);
}

void testWinDetectionRow() {
    std::array<int, 9> board = { X, X, X, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
    std::vector<int> legal_actions = { 3, 4, 5, 6, 7, 8 };
    TicTacToeState state(board, legal_actions, O);
    assert(state.is_winner(X) == true);
    assert(state.is_winner(O) == false);
}

void testWinDetectionCol() {
    std::array<int, 9> board = { EMPTY, EMPTY, O, EMPTY, EMPTY, O, EMPTY, EMPTY, O };
    std::vector<int> legal_actions = { 0, 1, 3, 4, 6, 7 };
    TicTacToeState state(board, legal_actions, X);
    assert(state.is_winner(O) == true);
    assert(state.is_winner(X) == false);
}
void testWinDetectionDiag() {
    std::array<int, 9> board = { X, EMPTY, EMPTY, EMPTY, X, EMPTY, EMPTY, EMPTY, X };
    std::vector<int> legal_actions = { 1, 2, 3, 5, 6, 7 };
    TicTacToeState state(board, legal_actions, O);
    assert(state.is_winner(X) == true);
    assert(state.is_winner(O) == false);
}

void testTerminal() {
    std::array<int, 9> board = { X, O, X, X, O, O, O, X, X };
    std::vector<int> legal_actions;  // Empty legal actions since the board is full.
    TicTacToeState state(board, legal_actions, X);
    assert(state.is_terminal() == true);
}

void testReward() {
    std::array<int, 9> boardWin = { X, X, X, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
    std::vector<int> legal_actionsWin = { 3, 4, 5, 6, 7, 8 };
    TicTacToeState winState(boardWin, legal_actionsWin, O);
    assert(winState.reward(X) == +1);
    assert(winState.reward(O) == -1);

    std::array<int, 9> boardDraw = { X, O, X, X, O, O, O, X, X };
    std::vector<int> legal_actionsDraw;  // No moves left.
    TicTacToeState drawState(boardDraw, legal_actionsDraw, X);
    assert(drawState.reward(X) == 0);
    assert(drawState.reward(O) == 0);
}

int main() {
    testInitialState();
    testStep();
    testWinDetectionRow();
    testWinDetectionCol();
    testWinDetectionDiag();
    testTerminal();
    testReward();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

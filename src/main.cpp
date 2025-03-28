#include "mcts.hpp"
#include "tictactoe.hpp"
#include <cstdlib>

int main() {
  TicTacToeState test_state = TicTacToeState();

  MCTS mcts = MCTS();
  while (!test_state.is_terminal()) {
    test_state.render();
    auto [best_move, probs] = mcts.search(test_state);
    test_state = test_state.step(best_move);
  }
  test_state.render();

}

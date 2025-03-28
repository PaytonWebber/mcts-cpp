#include "mcts.hpp"
#include "tictactoe.hpp"

int main() {
  TicTacToeState test_state = TicTacToeState();

  MCTS mcts = MCTS();
  std::vector<float> probs = mcts.search(test_state);
  for (auto i: probs) {
   std::cout << i << " ";
  }
  std::cout << std::endl;
}

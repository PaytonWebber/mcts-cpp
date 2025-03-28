#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

#include "mcts.hpp"
#include "tictactoe.hpp"

struct DummyState {
    std::vector<int> legal_actions;
    int current_player;
    
    DummyState() : legal_actions({0, 1, 2}), current_player(1) {}
    
    bool is_terminal() const { return false; }
    
    DummyState step(int /*action*/) const { return *this; }
    
    int reward(int /*to_play*/) const { return 0; }
};

void testNodeBasics() {
    DummyState ds;
    Node<DummyState> node(ds, 0, nullptr);
    
    assert(node.is_leaf());
    
    float ucb_val = node.ucb(1.414);
    assert(ucb_val == std::numeric_limits<float>::max());
    
    node.N = 10;
    node.W = 5;
    node.Q = node.W / node.N;
    
    DummyState parent_state;
    Node<DummyState> parent(parent_state, -1, nullptr);
    parent.N = 100;
    node.parent = &parent;
    
    ucb_val = node.ucb(1.414);
    assert(ucb_val > node.Q);
}

void testMCTSOnTicTacToe() {
    TicTacToeState state;
    
    MCTS mcts(1.414, 10);
    
    auto [move, action_probs] = mcts.search(state);

    assert((std::find(state.legal_actions.begin(), state.legal_actions.end(), move) != state.legal_actions.end()));
    
    assert(action_probs.size() == 9);
    
    float sum = 0.0f;
    for (float p : action_probs) {
        assert(p >= 0.0f);
        sum += p;
    }
    assert(sum > 0.0f);
    
    std::cout << "Action probabilities: ";
    for (float p : action_probs) {
        std::cout << p << " ";
    }
    std::cout << "\n";
}

int main() {
    testNodeBasics();
    testMCTSOnTicTacToe();
    std::cout << "All MCTS tests passed." << std::endl;
    return 0;
}

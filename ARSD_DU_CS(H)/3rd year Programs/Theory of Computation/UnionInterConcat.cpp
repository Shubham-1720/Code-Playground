#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;

// Finite Automaton class
class FiniteAutomaton {
public:
    set<string> states;                    // Set of states
    set<char> alphabet;                    // Set of input symbols (alphabet)
    string initial_state;                  // Initial state
    set<string> final_states;              // Set of final states
    map<pair<string, char>, string> transitions;  // Transition function

    FiniteAutomaton(set<string> states, set<char> alphabet, string initial_state,
                    set<string> final_states, map<pair<string, char>, string> transitions) {
        this->states = states;
        this->alphabet = alphabet;
        this->initial_state = initial_state;
        this->final_states = final_states;
        this->transitions = transitions;
    }

    // Function to simulate the automaton
    bool accepts(string input_string) {
        string current_state = initial_state;
        for (char symbol : input_string) {
            if (alphabet.find(symbol) == alphabet.end()) {
                return false;  // Symbol not in alphabet
            }
            pair<string, char> key = make_pair(current_state, symbol);
            if (transitions.find(key) != transitions.end()) {
                current_state = transitions[key];
            } else {
                return false;  // No valid transition
            }
        }
        return final_states.find(current_state) != final_states.end();
    }
};

// Function to create the union automaton
FiniteAutomaton unionAutomaton(FiniteAutomaton fa1, FiniteAutomaton fa2) {
    set<string> new_states;
    set<string> new_final_states;
    map<pair<string, char>, string> new_transitions;
    string new_initial_state = "U(" + fa1.initial_state + "," + fa2.initial_state + ")";

    // Cartesian product of states
    for (const string& s1 : fa1.states) {
        for (const string& s2 : fa2.states) {
            string new_state = "U(" + s1 + "," + s2 + ")";
            new_states.insert(new_state);
            // A state is final if it's final in either FA
            if (fa1.final_states.count(s1) || fa2.final_states.count(s2)) {
                new_final_states.insert(new_state);
            }
            // Build transitions
            for (char symbol : fa1.alphabet) {
                pair<string, char> key1 = make_pair(s1, symbol);
                pair<string, char> key2 = make_pair(s2, symbol);
                if (fa1.transitions.count(key1) && fa2.transitions.count(key2)) {
                    string next_state = "U(" + fa1.transitions[key1] + "," + fa2.transitions[key2] + ")";
                    new_transitions[make_pair(new_state, symbol)] = next_state;
                }
            }
        }
    }

    return FiniteAutomaton(new_states, fa1.alphabet, new_initial_state, new_final_states, new_transitions);
}

// Function to create the intersection automaton
FiniteAutomaton intersectionAutomaton(FiniteAutomaton fa1, FiniteAutomaton fa2) {
    set<string> new_states;
    set<string> new_final_states;
    map<pair<string, char>, string> new_transitions;
    string new_initial_state = "I(" + fa1.initial_state + "," + fa2.initial_state + ")";

    // Cartesian product of states
    for (const string& s1 : fa1.states) {
        for (const string& s2 : fa2.states) {
            string new_state = "I(" + s1 + "," + s2 + ")";
            new_states.insert(new_state);
            // A state is final only if it's final in both FA
            if (fa1.final_states.count(s1) && fa2.final_states.count(s2)) {
                new_final_states.insert(new_state);
            }
            // Build transitions
            for (char symbol : fa1.alphabet) {
                pair<string, char> key1 = make_pair(s1, symbol);
                pair<string, char> key2 = make_pair(s2, symbol);
                if (fa1.transitions.count(key1) && fa2.transitions.count(key2)) {
                    string next_state = "I(" + fa1.transitions[key1] + "," + fa2.transitions[key2] + ")";
                    new_transitions[make_pair(new_state, symbol)] = next_state;
                }
            }
        }
    }

    return FiniteAutomaton(new_states, fa1.alphabet, new_initial_state, new_final_states, new_transitions);
}

// Function to create the concatenation automaton
FiniteAutomaton concatenationAutomaton(FiniteAutomaton fa1, FiniteAutomaton fa2) {
    set<string> new_states = fa1.states;
    set<string> new_final_states;
    map<pair<string, char>, string> new_transitions = fa1.transitions;
    string new_initial_state = fa1.initial_state;

    // Add states and transitions for FA2, starting from FA1's final states
    for (const string& state : fa2.states) {
        new_states.insert(state);
    }
    for (const auto& [key, value] : fa2.transitions) {
        new_transitions[key] = value;
    }
    // Adjust final states
    for (const string& final_state : fa1.final_states) {
        for (const string& start_state : fa2.states) {
            pair<string, char> key = make_pair(final_state, *fa2.alphabet.begin());
            if (fa2.states.count(start_state)) {
                new_transitions[key] = start_state;
            }
        }
    }
    new_final_states = fa2.final_states;

    return FiniteAutomaton(new_states, fa1.alphabet, new_initial_state, new_final_states, new_transitions);
}

// Main function to test the FAs
int main() {
    // Define FA1
    set<string> states1 = {"A", "B", "C", "D"};
    set<char> alphabet1 = {'a', 'b'};
    string initial_state1 = "A";
    set<string> final_states1 = {"C"};
    map<pair<string, char>, string> transitions1 = {
        {{"A", 'a'}, "B"},
        {{"A", 'b'}, "D"},
        {{"B", 'a'}, "B"},
        {{"B", 'b'}, "C"},
        {{"C", 'a'}, "B"},
        {{"C", 'b'}, "C"},
        {{"D", 'a'}, "D"},
        {{"D", 'b'}, "D"}
    };
    FiniteAutomaton fa1(states1, alphabet1, initial_state1, final_states1, transitions1);

    // Define FA2
    set<string> states2 = {"A", "B", "C", "D"};
    set<char> alphabet2 = {'a', 'b'};
    string initial_state2 = "A";
    set<string> final_states2 = {"C"};
    map<pair<string, char>, string> transitions2 = {
        {{"A", 'a'}, "D"},
        {{"A", 'b'}, "B"},
        {{"B", 'a'}, "C"},
        {{"B", 'b'}, "B"},
        {{"C", 'a'}, "C"},
        {{"C", 'b'}, "B"},
        {{"D", 'a'}, "D"},
        {{"D", 'b'}, "D"}
    };
    FiniteAutomaton fa2(states2, alphabet2, initial_state2, final_states2, transitions2);

    // Create union, intersection, and concatenation automata
    FiniteAutomaton unionFA = unionAutomaton(fa1, fa2);
    FiniteAutomaton intersectionFA = intersectionAutomaton(fa1, fa2);
    FiniteAutomaton concatenationFA = concatenationAutomaton(fa1, fa2);

    // Test strings
    string test_string = "ab";
    cout << "Union FA accepts \"" << test_string << "\": " << unionFA.accepts(test_string) << endl;
    cout << "Intersection FA accepts \"" << test_string << "\": " << intersectionFA.accepts(test_string) << endl;
    cout << "Concatenation FA accepts \"" << test_string << "\": " << concatenationFA.accepts(test_string) << endl;

    return 0;
}
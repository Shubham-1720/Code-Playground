#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

class FiniteAutomaton {
public:
    set<string> states;            // Set of states
    set<char> alphabet;            // Set of input symbols (alphabet)
    string initial_state;          // Initial state
    set<string> final_states;      // Set of final states
    map<pair<string, char>, string> transitions;  // Transition function

    FiniteAutomaton(set<string> states, set<char> alphabet, string initial_state,
                    set<string> final_states, map<pair<string, char>, string> transitions) {
        this->states = states;
        this->alphabet = alphabet;
        this->initial_state = initial_state;
        this->final_states = final_states;
        this->transitions = transitions;
    }

    bool accepts(string input_string) {
        string current_state = initial_state;

        for (char symbol : input_string) {
            if (alphabet.find(symbol) == alphabet.end()) {
                return false;  // Reject if the symbol is not in the alphabet
            }

            pair<string, char> transition_key = make_pair(current_state, symbol);
            if (transitions.find(transition_key) != transitions.end()) {
                current_state = transitions[transition_key];
            } else {
                return false;  // Reject if no valid transition
            }
        }

        return final_states.find(current_state) != final_states.end();  // Accept if in a final state
    }
};

int main() {
    // Define states, alphabet, initial state, final states, and transitions
    // set<string> states = {"q0", "q1"};
    // set<char> alphabet = {'a', 'b'};
    // string initial_state = "q0";
    // set<string> final_states = {"q0"};

    // Define transitions as a map where the key is a pair of (state, input symbol)
    map<pair<string, char>, string> transitions;
    transitions[make_pair("q0", 'a')] = "q1";
    transitions[make_pair("q0", 'b')] = "q0";
    transitions[make_pair("q1", 'a')] = "q0";
    transitions[make_pair("q1", 'b')] = "q1";

    //Q1
    set<string> statesQ1 = {"q0", "q1", "q2", "q3"};
    set<char> alphabetQ1 = {'0', '1'};
    string initial_stateQ1 = "q0";
    set<string> final_statesQ1 = {"q3"};
    
    map<pair<string, char>, string> transitionsQ1;
    transitionsQ1[make_pair("q0", '0')] = "q0";
    transitionsQ1[make_pair("q0", '1')] = "q1";
    transitionsQ1[make_pair("q1", '0')] = "q0";
    transitionsQ1[make_pair("q1", '1')] = "q2";
    transitionsQ1[make_pair("q2", '0')] = "q0";
    transitionsQ1[make_pair("q2", '1')] = "q3";
    transitionsQ1[make_pair("q3", '0')] = "q3";
    transitionsQ1[make_pair("q3", '1')] = "q3";
    
    // Create a finite automaton
    FiniteAutomaton automatonQ1(statesQ1, alphabetQ1, initial_stateQ1, final_statesQ1, transitionsQ1);
    
    //q2
    set<string> statesQ2 = {"q0", "q1", "q2", "q3", "q4"};
    set<char> alphabetQ2 = {'0', '1'};
    string initial_stateQ2 = "q0";
    set<string> final_statesQ2 = {"q2", "q3"};
    
    map<pair<string, char>, string> transitionsQ2;
    transitionsQ2[make_pair("q0", '0')] = "q0";
    transitionsQ2[make_pair("q0", '1')] = "q1";
    transitionsQ2[make_pair("q1", '0')] = "q1";
    transitionsQ2[make_pair("q1", '1')] = "q2";
    transitionsQ2[make_pair("q2", '0')] = "q2";
    transitionsQ2[make_pair("q2", '1')] = "q3";
    transitionsQ2[make_pair("q3", '0')] = "q3";
    transitionsQ2[make_pair("q3", '1')] = "q4";
    transitionsQ2[make_pair("q4", '0')] = "q4";
    transitionsQ2[make_pair("q4", '1')] = "q4";
    
    
    // Create a finite automaton
    FiniteAutomaton automatonQ2(statesQ2, alphabetQ2, initial_stateQ2, final_statesQ2, transitionsQ2);


     //q3
    set<string> statesQ3 = {"q0", "q1", "q2", "q3", "q4","q5","q6","q7","q8","q9","q10","q11","q12","q13","q14"};
    set<char> alphabetQ3 = {'a', 'b'};
    string initial_stateQ3 = "q0";
    set<string> final_statesQ3 = {"q4", "q7","q11","q14"};
    
    map<pair<string, char>, string> transitionsQ3;
    transitionsQ3[make_pair("q0", 'a')] = "q1";
    transitionsQ3[make_pair("q0", 'b')] = "q8";
    transitionsQ3[make_pair("q1", 'a')] = "q2";
    transitionsQ3[make_pair("q1", 'b')] = "q5";
    transitionsQ3[make_pair("q2", 'a')] = "q3";
    transitionsQ3[make_pair("q2", 'b')] = "q2";
    transitionsQ3[make_pair("q3", 'a')] = "q4";
    transitionsQ3[make_pair("q3", 'b')] = "q2";
    transitionsQ3[make_pair("q4", 'a')] = "q4";
    transitionsQ3[make_pair("q4", 'b')] = "q2";
    transitionsQ3[make_pair("q5", 'a')] = "q6";
    transitionsQ3[make_pair("q5", 'b')] = "q5";
    transitionsQ3[make_pair("q6", 'a')] = "q6";
    transitionsQ3[make_pair("q6", 'b')] = "q7";
    transitionsQ3[make_pair("q7", 'a')] = "q6";
    transitionsQ3[make_pair("q7", 'b')] = "q5";
    transitionsQ3[make_pair("q8", 'a')] = "q12";
    transitionsQ3[make_pair("q8", 'b')] = "q9";
    transitionsQ3[make_pair("q9", 'a')] = "q9";
    transitionsQ3[make_pair("q9", 'b')] = "q10";
    transitionsQ3[make_pair("q10", 'a')] = "q9";
    transitionsQ3[make_pair("q10", 'b')] = "q11";
    transitionsQ3[make_pair("q11", 'a')] = "q9";
    transitionsQ3[make_pair("q11", 'b')] = "q11";
    transitionsQ3[make_pair("q12", 'a')] = "q12";
    transitionsQ3[make_pair("q12", 'b')] = "q13";
    transitionsQ3[make_pair("q13", 'a')] = "q14";
    transitionsQ3[make_pair("q13", 'b')] = "q13";
    transitionsQ3[make_pair("q14", 'a')] = "q12";
    transitionsQ3[make_pair("q14", 'b')] = "q13";
    
    // Create a finite automaton
    FiniteAutomaton automatonQ3(statesQ3, alphabetQ3, initial_stateQ3, final_statesQ3, transitionsQ3);
    
    
    //q4
    set<string> statesQ4 = {"q0", "q1", "q2", "q3"};
    set<char> alphabetQ4 = {'a', 'b'};
    string initial_stateQ4 = "q0";
    set<string> final_statesQ4 = {"q2"};
    
    map<pair<string, char>, string> transitionsQ4;
    transitionsQ4[make_pair("q0", 'a')] = "q1";
    transitionsQ4[make_pair("q0", 'b')] = "q3";
    transitionsQ4[make_pair("q1", 'a')] = "q1";
    transitionsQ4[make_pair("q1", 'b')] = "q2";
    transitionsQ4[make_pair("q2", 'a')] = "q1";
    transitionsQ4[make_pair("q2", 'b')] = "q2";
    transitionsQ4[make_pair("q3", 'a')] = "q3";
    transitionsQ4[make_pair("q3", 'b')] = "q3";
   
   
   // Create a finite automaton
    FiniteAutomaton automatonQ4(statesQ4, alphabetQ4, initial_stateQ4, final_statesQ4, transitionsQ4);
    
    
    //q5
    set<string> statesQ5 = {"q0", "q1", "q2", "q3"};
    set<char> alphabetQ5 = {'a', 'b'};
    string initial_stateQ5 = "q0";
    set<string> final_statesQ5 = {"q0"};
    
    map<pair<string, char>, string> transitionsQ5;
    transitionsQ5[make_pair("q0", 'a')] = "q3";
    transitionsQ5[make_pair("q0", 'b')] = "q1";
    transitionsQ5[make_pair("q1", 'a')] = "q2";
    transitionsQ5[make_pair("q1", 'b')] = "q0";
    transitionsQ5[make_pair("q2", 'a')] = "q1";
    transitionsQ5[make_pair("q2", 'b')] = "q3";
    transitionsQ5[make_pair("q3", 'a')] = "q0";
    transitionsQ5[make_pair("q3", 'b')] = "q2";
   
   
   // Create a finite automaton
    FiniteAutomaton automatonQ5(statesQ5, alphabetQ5, initial_stateQ5, final_statesQ5, transitionsQ5);
    
    //Choice menu
    cout<<"Enter the question number ";
    int quesno;
    cin>>quesno;
    if(quesno == 1){
        // Input string to test
        string input_string;
        cout << "Enter a string of 'a' and 'b' to check: ";
        cin >> input_string;
    
    
        // Check if the automaton accepts the input string
        if (automatonQ1.accepts(input_string)) {
            cout << "The input string '" << input_string << "' is accepted.\n";
        } else {
            cout << "The input string '" << input_string << "' is rejected.\n";
        }
    }
    
    else if(quesno == 2){
        // Input string to test
        string input_string;
        cout << "Enter a string of 'a' and 'b' to check: ";
        cin >> input_string;
    
    
        // Check if the automaton accepts the input string
        if (automatonQ2.accepts(input_string)) {
            cout << "The input string '" << input_string << "' is accepted.\n";
        } else {
            cout << "The input string '" << input_string << "' is rejected.\n";
        }
    }
    
    else if(quesno == 3){
        // Input string to test
        string input_string;
        cout << "Enter a string of 'a' and 'b' to check: ";
        cin >> input_string;
    
    
        // Check if the automaton accepts the input string
        if (automatonQ3.accepts(input_string)) {
            cout << "The input string '" << input_string << "' is accepted.\n";
        } else {
            cout << "The input string '" << input_string << "' is rejected.\n";
        }
    }
    
    else if(quesno == 4){
        // Input string to test
        string input_string;
        cout << "Enter a string of 'a' and 'b' to check: ";
        cin >> input_string;
    
    
        // Check if the automaton accepts the input string
        if (automatonQ4.accepts(input_string)) {
            cout << "The input string '" << input_string << "' is accepted.\n";
        } else {
            cout << "The input string '" << input_string << "' is rejected.\n";
        }
    }
    
    else if(quesno == 5){
        // Input string to test
        string input_string;
        cout << "Enter a string of 'a' and 'b' to check: ";
        cin >> input_string;
    
    
        // Check if the automaton accepts the input string
        if (automatonQ5.accepts(input_string)) {
            cout << "The input string '" << input_string << "' is accepted.\n";
        } else {
            cout << "The input string '" << input_string << "' is rejected.\n";
        }
    }
    
    else{
        cout<<"Out of bound"<<endl;
    }
    

    return 0;
}

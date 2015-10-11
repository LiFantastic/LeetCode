/*============================================================
Problem: Valid Number
==============================================================
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
============================================================*/
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
        	INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        int transitionTable[9][6] = {   // state -1 means not valid
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        
        int state = 0;
        int i=0, n=s.size();
        
        while (i<n) {
            InputType inputType = INVALID;
            char c = s[i];
            if (c == ' ')
                inputType = SPACE;
            else if (c == '+' || c == '-')
                inputType = SIGN;
            else if ('0' <= c && c <= '9')
                inputType = DIGIT;
            else if (c == '.')
                inputType = DOT;
            else if (c == 'e' || c == 'E')
                inputType = EXPONENT;
                
            state = transitionTable[state][inputType];
            
            if (state == -1)
                return false;
            else
                i++;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};
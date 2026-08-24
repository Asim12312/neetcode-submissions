//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    bool isValid(string s) {
        stack<char> paran;

        for (char c : s) {

            // Opening bracket
            if (c == '(' || c == '{' || c == '[') {
                paran.push(c);
            }

            // Closing bracket
            else {
                if (paran.empty()) {
                    return false;
                }

                if (c == ')' && paran.top() != '(') return false;
                if (c == '}' && paran.top() != '{') return false;
                if (c == ']' && paran.top() != '[') return false;

                paran.pop();
            }
        }

        return paran.empty();
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<int> sck;

        if (s.size() % 2 != 0) return false;

        for (char c : s) {
            if (c == '{' || c == '[' || c == '(')
                sck.push(c);
            else if ( c == ']' && !sck.empty() && sck.top() == '[')
                sck.pop();
            else if ( c == ')' && !sck.empty() && sck.top() == '(')
                sck.pop();
            else if ( c == '}' && !sck.empty() && sck.top() == '{')
                sck.pop();
            else return false;
        }

        return true;
    }
};

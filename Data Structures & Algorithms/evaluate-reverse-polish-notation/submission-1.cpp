class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sck;

        for (string x : tokens) {
            if (x[0] != '+' && x[0] != '*' && x[0] != '-' && x[0] != '/')
                sck.push(stoi(x));
            else if (x[0] == '+' && sck.size() >= 2) {
                int a = sck.top();
                sck.pop();
                int b = sck.top();
                sck.pop();

                sck.push(a + b);
            } else if (x[0] == '*' && sck.size() >= 2) {
                int a = sck.top();
                sck.pop();
                int b = sck.top();
                sck.pop();

                sck.push(a * b);
            } else if (x[0] == '/' && sck.size() >= 2) {
                int a = sck.top();
                sck.pop();
                int b = sck.top();
                sck.pop();

                sck.push(b / a);
            } else if (x[0] == '-' && sck.size() >= 2) {
                int a = sck.top();
                sck.pop();
                int b = sck.top();
                sck.pop();

                sck.push(b - a);
            }
        }

        return sck.top();
    }
};

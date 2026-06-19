class Solution {
public:

    string encode(vector<string>& strs) {
        string finalStr = "";

        for (string str : strs) {
            for (char ch : str) {
                int code = ch;
                finalStr += to_string(code) + ".";
            }
            finalStr += ";";
        }

        return finalStr;
    }

    vector<string> decode(string s) {
        vector<string> tokens;
        string token;
        stringstream ss(s);

        while (getline(ss, token, ';')) {
            tokens.push_back(token);
        }

        vector<string> words;

        for (string str : tokens) {
            vector<string> asciis;
            string asciiToken;
            stringstream ass(str);

            while(getline(ass, asciiToken, '.')) {
                asciis.push_back(asciiToken);
            }

            string word = "";
            for (string assToken : asciis) {
                word += stoi(assToken);
            }
            words.push_back(word);
        }

        return words;
    }
};

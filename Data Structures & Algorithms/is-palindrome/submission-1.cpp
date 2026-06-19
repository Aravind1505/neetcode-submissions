class Solution {
public:
    bool isPalindrome(string s) {

        string md = "";
        for (char c : s) {
            if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57)) md += c;
            else if (c >= 65 && c <= 90) md += (c - 'A' + 'a');
        }

        string rev = "";
        for (int i = md.size() - 1; i >= 0 ; i--)
            rev += md[i];

        if (rev == md) return true;
        return false;

    }
};

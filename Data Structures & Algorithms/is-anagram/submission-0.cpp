class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);

        for (char c : s) {
            chars[c - 97]++;
        }

        for (char c : t) {
            chars[c - 97]--;
        }

        for (int i = 0; i < chars.size(); i++) 
            if (chars[i] != 0)
                return false;

        return true;
    }
};

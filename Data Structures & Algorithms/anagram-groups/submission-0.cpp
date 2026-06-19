class Solution {

    string getSignature(string str) {
        string p = str;
        sort(p.begin(), p.end());
        return p;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> gA;
        vector<vector<string>> result;

        for (string str : strs) {
            string signature = getSignature(str);
            gA[signature].push_back(str);
        }

        for (const auto& [key, value] : gA) {
            result.push_back(value);
        }

        return result;

    }
};

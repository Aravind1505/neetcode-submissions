class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> chars;

        int l = 0, maxi = 0;
        for (int i = 0 ; i < s.size(); i++) {
            while (chars[s[i]] > 0){
                chars[s[l]]--;
                l++;
            }
            chars[s[i]]++;
            
            int temp = 0;
            for (auto const& [key, value] : chars)
                temp += value;
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};

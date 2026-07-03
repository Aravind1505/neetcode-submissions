class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1f(26, 0);
        vector<int> s2f(26, 0);

        for (int i = 0 ; i < s1.size(); i++) s1f[s1[i] - 'a']++;

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            s2f[s2[r] - 'a']++;
            if (r - l + 1 > s1.size()) {
                s2f[s2[l] - 'a']-- ;
                l++; 
            }

            int ctr = 0;
            for (int i = 0; i < 26; i++) {
                if (s1f[i] == s2f[i]) ctr++;
            }

            if (ctr == 26) return true;
        }

        return false;
    }
};

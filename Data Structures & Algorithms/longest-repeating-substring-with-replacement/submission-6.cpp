class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqMap(26, 0);
        int l = 0, maxi = 0, maxl = 0;

        for (int r = 0; r < s.size(); r++) {
            int rchind = s[r] - 'A';
            freqMap[rchind]++;

            maxi = max(maxi, freqMap[rchind]);

            while ((r - l + 1) - maxi > k) {
                int lchind = s[l] - 'A';
                freqMap[lchind]--;
                l++;
            }

            maxl = max(maxl, r - l + 1);
        }

        return maxl;
    }
};

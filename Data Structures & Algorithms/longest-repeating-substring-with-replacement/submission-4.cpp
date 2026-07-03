class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqMap(26, 0);
        int maxi = 0;
        char maxiC = 'A';

        for (int i = 0; i < s.size(); i++) {
            freqMap[s[i] - 'A']++;
            if (freqMap[s[i]-'A'] > maxi) {
                maxi = freqMap[s[i] - 'A'];
                maxiC = s[i];
            }
        }

        vector<pair<int, int>> existingSubstrs;
        int l = -1, r = -1;
        for (int i = 0; i < s.size(); i++) {
            if ( s[i]==maxiC && l == -1) {
                l = i;
                r = i;
            } else if (s[i] == maxiC && l != -1) {
                r = i;
            } else if (s[i] != maxiC && l != -1) {
                existingSubstrs.push_back({l,r});
                l = -1;
                r = -1;
            }
        }
        if (l != -1) existingSubstrs.push_back({l, r});

        int maxiL = -1, maxiR = -1; // Longest substring of most characters.
        for (int i = 0; i < existingSubstrs.size(); i++) {
            if (existingSubstrs[i].second - existingSubstrs[i].first >= maxiR - maxiL) {
                maxiR = existingSubstrs[i].second;
                maxiL = existingSubstrs[i].first;
            }
        }

        int farR = maxiR;
        for (int i = maxiR + 1; i < s.size(); i++) {
            if (k==0) break;
            if (s[i] != maxiC) {
                k--;
            }
            farR = i;
        }
        if (farR + 1 < s.size() && s[farR + 1] == maxiC) farR++;

        int farL = maxiL;
        for (int i = maxiL - 1; i >= 0; i--) {
            if (k == 0) break;
            if (s[i] != maxiC) k--;
            farL = i;
        }
        if (farL - 1 >= 0 && s[farL - 1] == maxiC) farL--;

        return farR - farL + 1;

    }
};

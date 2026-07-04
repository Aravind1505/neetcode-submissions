class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tf(26, 0);
        vector<int> sf(26, 0);

        for (int i = 0; i < t.size(); i++) tf[toupper(t[i]) - 'A']++;

        int l = 0, minl = -4 * s.size(), minr = 4 * s.size();
        string result = "";
        for (int r = 0; r < s.size(); r++) {
            int sind = toupper(s[r]) - 'A';
            sf[sind]++;

            for (int i = 0 ; i < 26; i++) {
                while(sf[i] > tf[i] && tf[i] != 0) {
                    sf[toupper(s[l]) - 'A']--;
                    l++;
                }
            }

            bool isValid = true;
            for (int i = 0; i < 26; i++) {
                if (tf[i] != 0 && sf[i] != tf[i]) isValid = false;
            }

            //Debugging
            cout << r << " " << l << " " << isValid << " "; 
            string temp = "";
            for (int i = l; i<= r; i++) temp += s[i];
            cout << temp << "\n";

            if (isValid) {
                for(int i = l; ;i++) {
                    if (tf[toupper(s[i]) - 'A'] != 0 && tf[toupper(s[i]) - 'A'] == sf[toupper(s[i]) - 'A']) {
                        l = i;
                        break;
                    }
                }
                
                if ((r - l + 1) < (minr - minl + 1)) {
                    minr = r;
                    minl = l;
                }
            }
        }

        if (minl == -4 * s.size()) return result;

        for (int i = minl; i <= minr; i++) result += s[i];

        return result;
    }
};

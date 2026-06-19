class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<int> s;
        
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);

        int maxi = 0, ctr = 0;

        vector<int> v;

        for (int num: s) {
            v.push_back(num);
        }

        for (int i = 0; i < v.size(); i++) {
            if (i == 0) ctr = 1;
            else if (v[i] - v[i-1] == 1) ctr++;
            else ctr = 1;

            if (ctr > maxi) maxi = ctr;
        }

        return maxi;
    }
};

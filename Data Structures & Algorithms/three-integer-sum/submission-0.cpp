class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        for (int i = 0; i < nums.size(); i++) {
            int j = i+1, k = nums.size()-1;
            while (j < nums.size() && j < k) {
                if (nums[i] * -1 == nums[j] + nums[k]) {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    results.push_back(res);
                    res.clear();
                    break;
                } else if (nums[i] * -1 < nums[j] + nums[k]) {
                    k--;
                } else if (nums[i] * -1 > nums[j] + nums[k]) {
                    j++;
                }
            }
        }        
        return results;
    }
};

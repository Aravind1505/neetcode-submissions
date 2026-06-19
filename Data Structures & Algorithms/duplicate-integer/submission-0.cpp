class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mhs;

        for (int i = 0; i < nums.size(); i++) {
            if (mhs.find(nums[i]) != mhs.end()) {
                return true;
            }
            mhs.insert(nums[i]);
        }

        return false;
    }
};
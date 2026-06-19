class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> mesh;

        for (int i = 0; i < nums.size(); i++) {
            if (mesh.find(target - nums[i]) != mesh.end()) {
                result.push_back(mesh[target - nums[i]]);
                result.push_back(i);
                return result;
            } else {
                mesh[nums[i]] = i;
            }
        }
    }
};

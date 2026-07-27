class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, res = nums[0], mid;
        while (l < r) {

            if (nums[l] < nums[r]) {
                res = min(nums[l], res);
                break;
            }

            mid = (r + l) / 2;
            res = min(nums[mid], res);

            if (nums[mid + 1] < nums[r]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }
        return res;
    }
};

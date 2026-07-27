class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;

        while (l <= r) {
            if (nums[l] < nums[r])
                break;

            m = (l + r) / 2;
            if (nums[m] > nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return 0;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r) {
            if (nums[l] < nums[r])
                break;

            mid = (l + r) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return 0;
    }
};

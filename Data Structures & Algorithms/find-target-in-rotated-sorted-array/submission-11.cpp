class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        mid = (l + r) / 2;

        while (l <= r) {
            if (nums[l] < nums[r])
                break;

            mid = (l + r) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (target >= nums[0] && target <= nums[mid]) {
            r = mid;
            l = 0;
        } else {
            l = mid + 1;
            r = nums.size() - 1;
        }

        mid = (l + r) / 2;

        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }

        if (nums[mid] == target) return mid;

        return -1;
    }
};

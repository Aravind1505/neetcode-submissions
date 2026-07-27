class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size(), res, mid;
        if (nums.back() < nums[0]) {
            while (l <= r) {
                mid = (r + l) / 2;
                res = min (nums[mid], res);

                if ((mid+1) < nums.size() && nums[mid] > nums[mid + 1]) {
                    l = mid;
                } else 
                    r = mid - 1;
            }

        } else {
            res = nums[0];
        } 
        return res;
    }
};

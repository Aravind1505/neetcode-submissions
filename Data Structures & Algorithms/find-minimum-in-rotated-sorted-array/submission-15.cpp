class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size(), res = nums[0], mid;
        if (nums.back() < nums[0]) {
            while (l < r) {
                mid = (r + l) / 2;
                res = min (nums[mid], res);

                if ((mid+1) < nums.size() && nums[mid] > nums[mid + 1]) {
                    l = mid + 1;
                } else 
                    r = mid;
            }

        } else {
            res = nums[0];
        } 
        return res;
    }
};

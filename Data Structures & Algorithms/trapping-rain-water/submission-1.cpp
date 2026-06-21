class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        vector<int> lmax(height.size());
        vector<int> rmax(height.size());

        lmax[0] = height[0];
        rmax[height.size() - 1] = height[height.size() - 1];

        for (int i = 1, j = height.size() - 2; i < height.size(); i++, j--) {
            lmax[i] = max(lmax[i-1], height[i]);
            rmax[j] = max(rmax[j+1], height[j]);
        }

        int res = 0;
        for (int i = 0 ; i < height.size() ; i++)
            res += min(lmax[i], rmax[i]) - height[i];

        return res;
    }
};

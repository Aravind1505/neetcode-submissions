class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        int maxArea = 0, area = 1, ctr = 0;
        for (int i = 0; i < n; i++) {
            ctr = i;
            while (ctr < n && ctr + 1 < n && heights[i] <= heights[ctr+1]) 
                ctr++;
            lmax[i] = ctr - i;
        }
        lmax[n-1] = 0;

        for (int i = n - 1; i>=0; i--) {
            ctr = i;
            while(ctr >= 0 && ctr - 1 >= 0 && heights[i] <= heights[ctr - 1])
                ctr--;
            rmax[i] = i - ctr;
        }
        rmax[0] = 0;

        for (int i = 0; i < n; i++) 
            area = max((lmax[i] + rmax[i] + 1) * heights[i], area);

        return area;
    }
};

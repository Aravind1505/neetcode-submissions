#include <algorithm> 

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        for (int i = 0, j = heights.size() - 1; i < j; ) {
            int mini = min(heights[i], heights[j]);
            int area = mini * (j - i);
            maxi = max(area, max);

            if (mini == heights[i]) i++;
            else j--;
        }
        return maxi;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> shorter;

        vector<int> lmax(n, -1);
        vector<int> rmax(n, n);

        int area = 0;
        
        for (int i = 0; i < n; i++) {
            while (!shorter.empty() && heights[shorter.top()] >= heights[i])
                shorter.pop(); 
            if (!shorter.empty())
                lmax[i] = shorter.top();
            shorter.push(i);
        }

        while(!shorter.empty()) shorter.pop();

        for (int i = n-1; i >= 0; i--) {
            while (!shorter.empty() && heights[shorter.top()] >= heights[i])
                shorter.pop(); 
            if (!shorter.empty())
                rmax[i] = shorter.top();
            shorter.push(i);
        }

        for (int i = 0; i < n; i++) {
            lmax[i]+=1;
            rmax[i]-=1;
            area = max((rmax[i] - lmax[i] + 1) * heights[i] , area);
        }
        
        return area;
    }
};

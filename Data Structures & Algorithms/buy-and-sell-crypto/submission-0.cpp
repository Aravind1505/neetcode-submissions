class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> lmin(prices.size());
        vector<int> rmax(prices.size());

        lmin[0] = prices[0];
        rmax[prices.size() - 1] = prices[prices.size() - 1];

        for (int i = 1, j = prices.size() - 2; i < prices.size(); i++, j--) {
            lmin[i] = min(lmin[i-1], prices[i]);
            rmax[j] = max(rmax[j + 1], prices[j]);
        }

        int maxi = 0;

        for (int i = 0; i < prices.size() ; i++)
            maxi = max(rmax[i] - lmin[i], maxi);

        return maxi;
    }
};

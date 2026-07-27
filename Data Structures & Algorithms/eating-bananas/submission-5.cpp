class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;

        for (int i = 0; i < piles.size(); i++)
            maxi = max(piles[i], maxi);

        if (h == piles.size()) return maxi;

        int cons, record = maxi, l = 1;
        while(l <= maxi) {
            int mid = (maxi + l) / 2;
            cons = 0;
            for (int i = 0; i < piles.size(); i++)
                cons += ceil((double)piles[i] / mid);

            if (cons <= h) {
                record = mid;
                maxi = record - 1;
            } else {
                l = mid + 1;
            }
        }

        return record;
    }
};

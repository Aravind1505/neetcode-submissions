class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1, mini = piles[0];

        for (int i = 0; i < piles.size(); i++) {
            maxi = max(piles[i], maxi);
            mini = min(piles[i], mini);
        }

        if (h == piles.size()) return maxi;

        int cons = 0, record = maxi, l = 1;
        while(l < maxi) {
            int mid = (maxi + l) / 2;
            cons = 0;
            for (int i = 0; i < piles.size(); i++) {
                cons += piles[i] / mid;
                if (piles[i] % mid != 0)
                    cons++;
            }

            if (cons <= h) {
                record = mid;
                maxi = record - 1;
            } else {
                l = cons + 1;
            }
        }

        return record;
    }
};

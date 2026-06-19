class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<pair<int,int>> pairs;
        vector<int> result;

        for (int num : nums) {
            if (m.find(num) != m.end())
                m[num]++;
            else 
                m[num] = 1;
        }

        for (const auto& [key, value] : m) {
            pairs.emplace_back(value, key);
        }

        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        for (int i = 0; i < k; i++) {
            result.push_back(pairs[i].second);
        }

        return result;
    }
};

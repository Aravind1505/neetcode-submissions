class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(), i++) {
            for (int j = i, j < temperatures.size(), j++) {
                if (temperatures[j] - temperatures[i] > 0) {
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }
};

/**
* 30,38,30,36,35,40,28
* 
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> sc;

        for (int i = 0; i < temperatures.size(); i++) {
            if (sc.empty() || temperatures[sc.top()] >= temperatures[i])
                sc.push(i);
            else if (temperatures[sc.top()] < temperatures[i]) {
                while (!sc.empty() && temperatures[sc.top()] < temperatures[i]) {
                    res[sc.top()] = i - sc.top();
                    sc.pop();
                }
                sc.push(i);
            }
        }

        return res;
    }
};

/**
* 30,38,30,36,35,40,28
* 
*/
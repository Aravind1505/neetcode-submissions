class Solution {

    int bSearch(vector<int>& numbers, int n, int sindex) {
        int l = 0, r = numbers.size() - 1, m;

        while (l <= r) {
            m = (l + r) / 2;
            if (numbers[m] == n) {
                if (m == sindex ) {
                    for (int i = m + 1; (i < numbers.size() && numbers[i] == numbers[sindex]); i++) {
                        return i;
                    }
                    for (int i = m - 1; (i >= 0 && numbers[i] == numbers[sindex]); i--) {
                        return i;
                    }
                } else if (m != sindex) return m;
            } else if (n < numbers[m]) {
                r = m - 1;
            } else if (n > numbers[m]) {
                l = m + 1;
            }
        }

        return -1;
    }

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int x = bSearch(numbers, target - numbers[i], i);
            if (x != -1) {
                result.push_back(i + 1);
                result.push_back(x + 1);
                return result;
            }
        }
    }
};

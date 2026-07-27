bool desPair(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first; // it sorts in descending order
    }

class Solution {

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<int> times;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end(), desPair);

        for (int i = 0; i < cars.size(); i++) {
            int time = (target - cars[i].first) / cars[i].second;

            if ((target - cars[i].first) % cars[i].second != 0) time++;

            if (times.empty()) times.push(time);
            else if (times.top() < time) times.push(time);
        }

        return times.size();
    }
};

//b = a + (n-1)diff
// 10 = 1 + (n-1) 3
// 3 = n - 1
// n = 4

// 10 = 4 + (n-1) 2
// 3 = n - 1
// n = 4
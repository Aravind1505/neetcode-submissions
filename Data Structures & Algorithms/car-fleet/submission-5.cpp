bool desPair(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first; // it sorts in descending order
    }

class Solution {

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        vector<double> times;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end(), desPair);

        for (int i = 0; i < cars.size(); i++) {
            times.push_back((double)(target - cars[i].first) / cars[i].second);
            if (times.size() >= 2 && times.back() <= times[times.size() - 2])
                times.pop_back();
        }

        return times.size();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, ctr = 0;
        priority_queue<int> maxHeap;
        map<int, int> freq;
        vector<int> results;
        for (int r = 0; r < nums.size(); r++) {
            maxHeap.push(nums[r]);
            freq[nums[r]]++;
            ctr++;
            
            if (ctr > k) {
                ctr--;
                freq[nums[l]]--;
                l++;
            }

            if (ctr == k) {
                while (freq[maxHeap.top()] == 0) {
                    maxHeap.pop();
                }
                results.push_back(maxHeap.top());
            }
        }
        return results;
    }
};

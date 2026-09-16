class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int left = 0;
        int right = n - 1;

        for(int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[left], 0});
            left++;
        }

        for(int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[right], 1});
            right--;
        }

        long long ans = 0;

        while(k--) {
            auto [cost, side] = pq.top();
            pq.pop();

            ans += cost;

            if(left <= right) {
                if(side == 0) {
                    pq.push({costs[left], 0});
                    left++;
                } else {
                    pq.push({costs[right], 1});
                    right--;
                }
            }
        }

        return ans;
    }
};
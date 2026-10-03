class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int,int>> pairs;

        for(int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0;
        long long ans = 0;

        for(auto &[num2, num1] : pairs) {

            minHeap.push(num1);
            sum += num1;

            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k) {
                ans = max(ans, sum * num2);
            }
        }

        return ans;
    }
};
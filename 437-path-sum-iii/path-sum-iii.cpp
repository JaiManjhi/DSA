class Solution {
public:
    unordered_map<long long,int> mp;
    int ans = 0;

    void dfs(TreeNode* root, long long currSum, int target) {
        if(root == nullptr)
            return;

        currSum += root->val;

        ans += mp[currSum - target];

        mp[currSum]++;

        dfs(root->left, currSum, target);
        dfs(root->right, currSum, target);

        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;

        dfs(root, 0, targetSum);

        return ans;
    }
};
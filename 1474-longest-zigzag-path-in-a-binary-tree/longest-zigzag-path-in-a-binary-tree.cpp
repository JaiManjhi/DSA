class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, int left, int right) {
        if (node == nullptr)
            return;

        ans = max(ans, max(left, right));

        // Move left -> next move must be right
        dfs(node->left, 0, left + 1);

        // Move right -> next move must be left
        dfs(node->right, right + 1, 0);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maximumPathSum(root, maxi);
        return maxi;
    }

    int maximumPathSum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int lhs = max(0,maximumPathSum(root->left, maxi));
        int rhs = max(0, maximumPathSum(root-> right, maxi));
        maxi = max(maxi,root->val+lhs+rhs);
        return max(lhs, rhs) + root->val;
    }
};
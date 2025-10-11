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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return{};
        }
        vector<int> product;
        postorder(root, product);
        return product;
    }
    void postorder(TreeNode* root, vector<int>& product){
        if(root == NULL){
            return;
        }
        postorder(root->left, product);
        postorder(root->right, product);
        product.push_back(root->val);
    }
};
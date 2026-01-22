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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh) return (1<<lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int findHeightLeft(TreeNode* node){
        int left =0;
        while(node){
            left++;
            node =node ->left;
        }
        return left;
    }
    int findHeightRight(TreeNode* node){
        int right =0;
        while(node){
            right++;
            node = node->right;
        }
        return right;
    }
};
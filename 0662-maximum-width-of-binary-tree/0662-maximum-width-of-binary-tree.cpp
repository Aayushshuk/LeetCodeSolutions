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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans =0;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first=0; 
            int last =0;
            for(int i=0; i<size; i++){
                long long curIndex = q.front().second - mmin;
                TreeNode* node= q.front().first;
                q.pop();
                if(i==0) 
                    first = curIndex;
                if(i==size-1) 
                    last = curIndex;
                if(node->left)
                    q.push({node->left, 2 * curIndex + 1});
                if(node->right)
                    q.push({node->right, 2 * curIndex + 2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
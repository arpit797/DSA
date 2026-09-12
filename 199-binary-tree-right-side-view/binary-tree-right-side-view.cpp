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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            TreeNode*curr=NULL;
            while(size--){
                curr=q.front();
                q.pop();
                if(curr->left !=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            result.push_back(curr->val);
        }
        return result;
    }
};
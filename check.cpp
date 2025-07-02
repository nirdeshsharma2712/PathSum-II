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
    void check(TreeNode*root , int targetSum , int &sum ,vector<vector<int>> &test,vector<int>&ans){
        if(root==NULL) return;
        sum+=root->val;
        ans.push_back(root->val);
        check(root->left , targetSum , sum , test ,ans);
        check(root->right , targetSum , sum , test , ans);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum) test.push_back(ans);
        }
        ans.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        vector<vector<int>> test;
        int sum = 0;
        check(root,targetSum , sum , test , ans);
        return test;
    }
};

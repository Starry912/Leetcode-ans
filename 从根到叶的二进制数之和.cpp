/*
1075.给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，
那么它表示二进制数 01101，也就是 13 。对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。以 10^9 + 7 为模，返回这些数字之和。
思路：DFS的同时进行计算
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const long long MOD=1e9+7;
class Solution {
public:
    long long ans;
    
    void dfs(TreeNode* rt, long long v){
        v=(v*2+rt->val)%MOD;
        if (rt->left==NULL && rt->right==NULL){
            ans=(ans+v)%MOD;
        }else{
            if (rt->left !=NULL) dfs(rt->left, v);
            if (rt->right !=NULL) dfs(rt->right, v);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        ans=0; dfs(root, 0);
        return ans;
    }
};

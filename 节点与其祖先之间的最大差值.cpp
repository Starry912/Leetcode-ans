/*
给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
思路：DFS
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
class Solution {
public:
    int ans=0;
    inline int Abs(int x){
        if (x<0) return -x;
        return x;
    }
    
    void dfs(TreeNode* rt, int mi, int mx){
        if (rt==NULL) return;
        ans=max(ans, Abs(mx-rt->val));
        ans=max(ans, Abs(mi-rt->val));
        mi=min(mi, rt->val);
        mx=max(mx, rt->val);
        dfs(rt->left, mi, mx);
        dfs(rt->right, mi, mx);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        dfs(root, root->val, root->val);
        return ans;
    }
};

/*
链表中的下一个更大节点
思路：单调栈
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    vector<int> nextLargerNodes(ListNode* head){
        vector<int> arr; arr.clear();
        while(head) arr.push_back(head->val),head=head->next;
        
        int n=arr.size();
        vector<int> ans; ans.clear();
        for (int i=0;i<n;i++) ans.push_back(0);
        
        int stk[n+5],top=0;
        for (int i=0;i<n;i++){
            while (top>0 && arr[stk[top]]<arr[i]){
                ans[stk[top]]=arr[i];
                --top;
            }
            stk[++top]=i;
        }
        return ans;
    }
};


/*
给定一个整数数组 A，返回 A 中最长等差子序列的长度。
回想一下，A 的子序列是列表 A[i_1], A[i_2], ..., A[i_k] 其中 0 <= i_1 < i_2 < ... < i_k <= A.length - 1。并且如果 B[i+1] - B[i]( 0 <= i < B.length - 1) 的值都相同，那么序列 B 是等差的。
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int mx=0,n=A.size();
        for (int i=0; i<n; i++) mx=max(mx,A[i]);
        
        map<int, int> last;
        int ans=0;
        for (int delta=-mx; delta<=mx; delta++){
            last.clear();
            for (int i=0; i<n; i++){
                int v=A[i];
                last[v]=max(last[v], last[v-delta]+1);
                ans=max(ans, last[v]);
            }
        }
    
        return ans;
    }
};

/*https://leetcode-cn.com/contest/weekly-contest-128/problems/numbers-with-repeated-digits/
1012:给定正整数 N，返回小于等于 N 且具有至少 1 位重复数字的正整数。（N会很大）
思路：数位DP 记忆化搜索
10000： 889x 899x 
DP[i][digit][succ]表示当前从高位往低位尝试，已经确定到了第i位，前面已经使用过的数字情况为digit（长度为10的01串，状态压缩），succ表示前面是否有数字已经重复
*/

int num[15],tot;
int dp[15][1500][5];

int dfs(int now, int state , int succ, bool lead, bool flag){
    if (now==0){
        return succ;
    }
    if (flag==false && lead==false && dp[now][state][succ]!=-1) return dp[now][state][succ];
    
    int lim=((flag==false)?9:num[now]);
    int ret=0;
    for (int i=(lead?1:0); i<=lim; i++){
        ret+=dfs(now-1,state|(1<<i),succ|((state>>i)&1),false,(flag && i==lim));
    }
    if(flag==false && lead==false) dp[now][state][succ]=ret;
    return ret;
}


class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        memset(dp, -1, sizeof(dp));
        tot=0;
        while(N) num[++tot]=N%10,N/=10;
        int ans=0;
        for (int i=tot; i>=1; i--){
            ans+=dfs(i,0,0,true,i==tot);
        }
        return ans;
    }
};

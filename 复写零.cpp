/*1089.给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
注意：请不要在超过该数组长度的位置写入元素。
要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

示例 1：
输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：
输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        
        int sum[n+5];
        for(int i=0;i<n;i++) sum[i]=0;
        
        if (arr[0]==0) ++sum[0];
        for (int i=1;i<n;i++) sum[i]=sum[i-1]+(arr[i]==0?1:0);
        
        for(int i=n-1;i>=0;i--){
            int pos=i+sum[i];
            if (arr[i]==0){
                if (pos-1<n) arr[pos-1]=0;
            }
            if (pos<n) arr[pos]=arr[i];
            
        }
    }
};

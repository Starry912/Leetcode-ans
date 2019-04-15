/*
给出数字 N，返回由若干 "0" 和 "1"组成的字符串，该字符串为 N 的负二进制（base -2）表示。
除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
输入：2
输出："110"
解释：(-2) ^ 2 + (-2) ^ 1 = 2

思路：
3%2==0 "1" 
(3-1)%4==0 "11"
(2+2)%8==0 "111"
4-4=0
*/
class Solution {
public:
    string baseNeg2(int N) {
        if (N==0) return "0";
        string ret="";
        bool flag=true;
        while (N){
            if (N&1){
                if (flag) N-=1;else N+=1;
                ret="1"+ret;
            }else ret="0"+ret;
            N/=2;
            flag=!flag;
        }
        return ret;
    }
};

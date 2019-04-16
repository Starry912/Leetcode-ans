/*
如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）
给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。
示例 1：
输入：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
输出：[true,false,true,true,false]
示例：
"FooBar" 可以这样生成："F" + "oo" + "B" + "ar"。
"FootBall" 可以这样生成："F" + "oot" + "B" + "all".
"FrameBuffer" 可以这样生成："F" + "rame" + "B" + "uffer".

思路：
1.Queries大写字母一定要匹配2.Queries小写字母不一定要匹配3.Pattern中所有字母都要匹配
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans; ans.clear();
        int n=pattern.length();
        for (auto& str:queries){
            int m=str.length(), j=0, i=0;
            bool flag=true;
            for (i=j=0; i<n && j<m;){
                while (j<m && str[j]!=pattern[i] && 'a'<=str[j] && str[j]<='z') ++j;
                if (j>m) break;
                if (str[j]!=pattern[i]) break;
                ++j; ++i;
            }
            flag=(i==n);
            for (;j<m && flag; ++j) flag=flag && ('a'<=str[j] && str[j]<='z');
            ans.push_back(flag);
        }
        return ans;
    }
};

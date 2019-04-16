/*
出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。
移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。
返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。

示例 1：
输入：[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
输出：3
解释： 有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。

思路：BFS
先计算边界上的格子，再统计边界上格子能到达的格子，再统计剩余的就是飞地
*/

bool vis[505][505];
queue<pair<int,int> > que;
const int dx[]={0,-1,0,1};
const int dy[]={1,0,-1,0};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        memset(vis,false,sizeof(vis));
        while(!que.empty()) que.pop();
        
        for (int i=0;i<n;i++){
            if (A[i][0]==1) que.push(make_pair(i,0)),vis[i][0]=true;
            if (A[i][m-1]==1) que.push(make_pair(i,m-1)),vis[i][m-1]=true;
        }
        for (int j=0;j<m;j++){
            if (A[0][j]==1) que.push(make_pair(0,j)),vis[0][j]=true;
            if (A[n-1][j]==1) que.push(make_pair(n-1,j)),vis[n-1][j]=true;
        }
        int ans=0;
        while (!que.empty()){
            int x=que.front().first, y=que.front().second; que.pop();
            for (int k=0;k<4;k++){
                int tx=x+dx[k], ty=y+dy[k];
                if (!(0<=tx && tx<n && 0<=ty && ty<m)) continue;
                if (A[tx][ty]==1 && !vis[tx][ty]){
                    vis[tx][ty]=true;
                    que.push(make_pair(tx,ty));
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (A[i][j]==1 && vis[i][j]==false) ++ans;
            }
        }
        return ans;
    }
};

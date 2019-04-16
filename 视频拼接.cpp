/*
你将会获得一系列视频片段，这些片段来自于一项持续时长为 T 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。
视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1] 结束。我们甚至可以对这些片段自由地再剪辑，例如片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。
我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, T]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。
思路：线段覆盖问题
已经覆盖[0，now]，找一个clip[k],满足clip[k][0]<=now,clips[k][1]尽可能大。
排序：左端点升序
*/

const int MAXN=100+50;
struct Segment{
    int l,r;
}seg[MAXN];
int n;
inline bool cmp(const Segment &a, const Segment &b){
    if (a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        n=clips.size();
        for (int i=0; i<n; i++){
            seg[i].l=clips[i][0];
            seg[i].r=clips[i][1];
        }
        sort(seg, seg+n, cmp);
        int now=0, ans=0, i=0;
        while (now<T && i<n){
            int mx=now;
            while(i<n && seg[i].l<=now){mx=max(mx,seg[i].r); ++i;}
            if (mx==now) break;
            now=mx;++ans;
        }
        if (now<T) return -1;
        return ans;
    }
};

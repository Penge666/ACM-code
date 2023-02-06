/*
这种方法十分巧妙——
首先，让我们转换一下思维，从数到图。先说说操作，对于任意一个0..k-1之间的整数x，将x看做一个点。由于从x出发可以引出两项基本操作：
(1)x*=10,此时x的各位数字和不发生改变，此操作可以转换成从x到x*10%k连一条有向边，权值0；
(2)x++,此时x的各位数字和也加一，此操作可以转换成从x到(x+1)%k连一条有向边，权值1。
这样图中有k个点（0..k-1），2*k条边。
然后， 关于合理性和含义，阐释如下。所有对k同余的数目可以看做图中的同一个点，当我们从点1出发，沿着构造好的有向图的边走到0点时，就相当于走到了一个k的正整数倍数的点值，不妨设其为ak。而这一路走来经过的所有边的权值之和，也就是逐步或加1或加0得到的总和，正是ak的各位数值总和减一。（这一路走来是经过了连接点与点的路径，而出发点是1不是0；出发点显然不能与终点相同，故不能是0；若出发点不是1而是1后面的点，难免会忽略了一些在那后面的点之前的可能的比较优的路径。因此应从1到0走一趟）。易知此有向图的最短路径长度减一就是答案。
(3)k<=1e5,点数k，边数2k，跑dijkstra即可。
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
struct str{
    int num;
    int sum;
};
map<int,int> vis;
deque<str> q;
signed main(){
    int k;
    cin>>k;
    q.push_back((str){1,1});
    while(!q.empty()){
        struct str t=q.front();
        q.pop_front();
        if(vis[t.num]) continue;
        vis[t.num]=1;
        if(t.num==0){
            cout<<t.sum;
            return 0;
        }
        q.push_front((str){(10*t.num)%k,t.sum});
        q.push_back((str){(t.num+1)%k,t.sum+1});
    }
    return 0;
}

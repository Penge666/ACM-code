/*题意
有n个机器人，然后打了m场比赛

m场比赛描述是:A打败了B

如果A打败B，B打败C，那么A就能打败C，具有传递性

现在问你，最少只需要前多少场比赛就能够知道顺序了。

或者说无论如何都不能知道，输出-1

 

题解：
二分，然后check的时候，我们检查他的拓扑序是否是一条直线就好了

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
struct str{
    int x,y;
}st[N];
int n,m;
vector<int> v[N];
int in[N];
int check(int num){
    queue<int> q;
    for(int i=1;i<=n;i++){
        v[i].clear();in[i]=0;
    }
    for(int i=1;i<=num;i++){
        in[st[i].y]++;
        v[st[i].x].push_back(st[i].y);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);
    }
    int sum=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(q.size()) return 0;
        sum++;
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!in[to]){
                q.push(to);
            }
        }
    }
    if(sum==n) return 1;
    else return 0;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>st[i].x>>st[i].y;
    int l=1;
    int r=m;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

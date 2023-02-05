/*由题可知，一个人能经别人知道自己的生日，则他必然在一个环中，所以显然题目是让我们求图中最小的环。结合本题的特性，每个人的出度都为111，那么每个人必定只在一个环中。如果有人的入度为000则说明他一定不在环中，我们可以用拓扑的思想把他及他所连的边删去，然后继续做拓扑排序删除入度为000的点即可。删完点之后剩下的就全是环了。这个时候我们对每个环做一次dfsdfsdfs即可。dfsdfsdfs的过程中将一个环内所有点标记(因为一个点只可能在一个环内，所以一个环内dfsdfsdfs任意一个点都是一样的)，标记过的点就不用再搜索了。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 999999999
#define N 666666
int arr[N];
int n;
vector<int> v[N];
int in[N];
queue<int> q;
map<int,int> vis;
int sum;
void topoSort(){
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!in[to]){
                q.push(to);
                vis[to]=1;
            }
        }
    }
}

int SUM;
void dfs(int root,int fa){
    sum++;
    for(int i=0;i<v[root].size();i++){
        if(v[root][i]==SUM){
            return ;
        }
        vis[v[root][i]]=1;
        dfs(v[root][i],root);
    }
}


signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        v[i].push_back(arr[i]);
        in[arr[i]]++;
    }
    topoSort();
    //cout<<"==";
    int ans=inf;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        sum=0;
        SUM=i;
        dfs(i,i);
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}


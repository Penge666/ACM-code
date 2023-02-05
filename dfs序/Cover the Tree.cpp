#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666

//******************************DFS序
int in[N],out[N],num[N];
int head[N];
int tot,cnt;
struct Edge{
    int to, nxt;
}edge[N];
void add(int a, int b)
{
    edge[cnt].to = b;
    edge[cnt].nxt = head[a];
    head[a] = cnt++;
}
void dfs(int x){
    in[x] = ++tot;//第一次遇到
    num[tot] = x;//num[tot]=x表示在新的序列中，tot这个点是原先的x这个点
    for(int i = head[x]; i != -1; i = edge[i].nxt)
        dfs(edge[i].to);
    out[x] = tot;//最后一次遇到
}

//**************************SLOVE
struct Node{
    int id,dfs_time;
};
int IN[N];
void init(){
    cnt=tot=0;
    memset(head,-1,sizeof(head));
}
vector<Node> v;
bool cmp(Node A,Node B){
    return A.dfs_time<B.dfs_time;
}
signed main(){
    init();
    int n;
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        add(a,b);
        IN[a]++,IN[b]++;
    }
    dfs(1);
    /*
    for(int i=1;i<=n;i++){
        cout<<num[i]<<" ";
    }
    */
    for(int i=1;i<=n;i++){
        if(IN[i]==1){
            v.push_back((Node){i,num[i]});
        }
    }
    sort(v.begin(),v.end(),cmp);
    int ans=v.size()/2;
    if(v.size()%2) ans++;
    printf("%lld\n",ans);
    int len=v.size();
    if(len%2==0){
        for(int i=0;i<v.size()/2;i++){
            cout<<v[i].id<<" "<<v[len/2+i].id<<'\n';
        }
    }else{
        for(int i=0;i<v.size()/2;i++){
            cout<<v[i].id<<" "<<v[len/2+i+1].id<<'\n';
        }
        cout<<v[len/2].id<<" "<<"1"<<'\n';
    }

    return 0;
}

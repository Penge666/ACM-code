#include<bits/stdc++.h>

using namespace std;
#define maxn 1000009
int now;
inline int read(){
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' & c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int match[maxn];
int vis[maxn];
struct Edge{
    int to;
    int next;
}e[3*maxn];
int cnt=1;
int head[maxn];
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int dfs(int u){
    int temp;
    for(int i=head[u];i;i=e[i].next){
        temp=e[i].to;
        if(vis[temp]!=now){
            vis[temp]=now;
        //    vis[temp]=1;
            if(match[temp]==0||dfs(match[temp])){
                match[temp]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int n;int x,y;
    //scanf("%d",&n);
    n=read();
    for(int i=1;i<=n;i++){
        x=read();
        y=read();
        add(x,i);
        add(y,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        now++;
        if(dfs(i))
            ans++;
        else{
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
//vector
#include<bits/stdc++.h>

using namespace std;
#define maxn 1000009
int match[maxn];
int vis[maxn];
int id;
vector<int> v[maxn];
int dfs(int u){
    for(int i=0;i<v[u].size();i++){
        int temp=v[u][i];
        if(vis[temp]!=id){
            vis[temp]=id;
            if(match[temp]==0||dfs(match[temp])){
                match[temp]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(i);
        v[y].push_back(i);
    }
    memset(match,0,sizeof(match));
    int ans=0;
    for(int i=1;i<=n;i++){
        id++;
        if(dfs(i))
            ans++;
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

*/

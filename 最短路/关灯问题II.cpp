#include<bits/stdc++.h>

using namespace std;
const int N =  6666 ;
int mp[N][N];
int n,m;
int vis[N];
struct str{
    int state;
    int num;
};
int SPFA(int s){
    queue<str> q;
    q.push((str){s,0});
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        struct str st=q.front();
        q.pop();
        int state=st.state,num=st.num;
        if(!state) return num;
        if(vis[state]) continue;
        vis[state]=1;
        for(int i=0;i<m;i++){
            int tmp=state;
            for(int j=0;j<n;j++){
                if(mp[i][j]==1&&(1<<j)&tmp){
                    tmp=tmp^(1<<j);
                }
                if(mp[i][j]==-1&&!((1<<j)&tmp)){
                    tmp=tmp|(1<<j);
                }
            }
            q.push((str){tmp,num+1});
        }
    }
    return -1;
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mp[i][j];
    cout<<SPFA((1<<n)-1);
    return 0;
}

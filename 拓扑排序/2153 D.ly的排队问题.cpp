//思路：优先队列维护拓扑排序
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
vector<int> v[66];
int in[66];//入度
map<int,int> vis;
priority_queue <int,vector<int>,greater<int> > q;
vector<int> ans;
signed main(){
    int sum=0;
    char s[6];
    while(cin>>s){
        if(!vis[s[0]-'A']) sum++;
        if(!vis[s[2]-'A']) sum++;
        vis[s[0]-'A']=1;
        vis[s[2]-'A']=1;
        if(s[1]=='>'){
            in[s[2]-'A']++;
            v[s[0]-'A'].push_back(s[2]-'A');
        }else{
            in[s[0]-'A']++;
            v[s[2]-'A'].push_back(s[0]-'A');
        }
    }
    for(int i=0;i<26;i++){
        if(!in[i]&&vis[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t=q.top();
        q.pop();
        ans.push_back(t);
        for(int i=0;i<v[t].size();i++){
            int to=v[t][i];
            in[to]--;
            if(!in[to]&&vis[to]) q.push(to);
        }
    }
    if(sum==ans.size()){
        for(int i=0;i<ans.size();i++)
            printf("%c",ans[i]+'A');
        printf("\n");
    }else{
        printf("No Answer!\n");
    }
    return 0;
}

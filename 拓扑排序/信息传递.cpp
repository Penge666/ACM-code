/*�����֪��һ�����ܾ�����֪���Լ������գ�������Ȼ��һ�����У�������Ȼ��Ŀ����������ͼ����С�Ļ�����ϱ�������ԣ�ÿ���˵ĳ��ȶ�Ϊ111����ôÿ���˱ض�ֻ��һ�����С�������˵����Ϊ000��˵����һ�����ڻ��У����ǿ��������˵�˼��������������ı�ɾȥ��Ȼ���������������ɾ�����Ϊ000�ĵ㼴�ɡ�ɾ���֮��ʣ�µľ�ȫ�ǻ��ˡ����ʱ�����Ƕ�ÿ������һ��dfsdfsdfs���ɡ�dfsdfsdfs�Ĺ����н�һ���������е���(��Ϊһ����ֻ������һ�����ڣ�����һ������dfsdfsdfs����һ���㶼��һ����)����ǹ��ĵ�Ͳ����������ˡ�
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


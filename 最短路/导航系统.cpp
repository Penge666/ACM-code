/*
I ����ϵͳ
��Ȼ���ݸ�����ԭͼ��һ������
���׷��֣�����������N(N-1)�����뿴��N(N-1)������ߵĻ�����ô������ݺϷ���ԭ������������ͼ����С��������
֤�������ڱ�Ȩ�ǷǸ��ģ����Կ���Kruskal�㷨�Ĺ��̣�ÿһ������ı߶��Ǿ����̵ܶģ�����һ�������еıߣ�ͨ���򵥵Ĺ��ɼ�֤��
���������С������֮���ٽ�����֤�ͺ��ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 999999999
#define N 6666
int f[N];
int mp[N][N],arr[N][N];
struct str{
    int u,v,w;
}st[N*N];
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
int merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        f[t1]=t2;
        return 1;
    }
    return 0;
}
bool cmp(str a,str b){
    return a.w<b.w;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                mp[i][j]=0;
            else
                mp[i][j]=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>arr[i][j];
    int f=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]!=arr[j][i]){
                f=0;
                break;
            }
        }
        if(!f) break;
    }
    if(!f){
        cout<<"No"<<'\n';
        return 0;
    }
    int cnt;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            st[cnt].u=i;
            st[cnt].v=j;
            st[cnt].w=arr[i][j];
            cnt++;
        }
    }
    sort(st,st+cnt,cmp);
    vector<int> ans;
    for(int i=0;i<cnt;i++){
        if(merge(st[i].u,st[i].v)){
            mp[st[i].u][st[i].v]=st[i].w;
            mp[st[i].v][st[i].u]=st[i].w;
            ans.push_back(st[i].w);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        //  cout<<mp[i][j]<<" ";
            if(mp[i][j]!=arr[i][j]){
                f=0;
                break;
            }
        }
    //  cout<<'\n';
        if(!f) break;
    }

    if(f){
        printf("Yes\n");
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<'\n';
    }else{
        cout<<"No"<<'\n';
    }

    return 0;
}

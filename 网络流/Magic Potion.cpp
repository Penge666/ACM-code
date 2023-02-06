/*
 ���⣺��n��Ӣ�ۣ�m�����ˣ�kƿҩ��������ÿ��Ӣ�ۿ�������ĵ��˵ı�š�ÿ��Ӣ��ֻ������һ�����ˣ���ÿ��Ӣ��ֻ������һ�����ˡ�������ҩ����Ӣ�ۺ���֮����Զ�����һ�����ˣ���ÿ��Ӣ��ֻ�ܺ�һƿ���������������ٸ����ˡ�

����ѧ��EK���������ס������������������忴���롣

��ʵҲ����������

*/
//EK�㷨��������
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            flag=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(flag)
        x=-x;
    return x;
}
#define inf 1<<30
int n,m,s,t,tot;
int found;
struct Node{
    int v;
    int val;
    int next;
}node[201010];
int top=1,head[101010];
inline void addedge(int u,int v,int val){
    node[++top].v=v;
    node[top].val=val;
    node[top].next=head[u];
    head[u]=top;
}
int inque[101010];// ���Ƿ��ʹ���
struct Pre{
    int v;// �õ��ǰһ���㣨����������
    int edge;// ��õ������ıߣ��������ģ�
}pre[101010];
int ansk[1050];//���Ϊi���⼮����Ա�ͱ��Ϊansk[i]-n��Ӣ������Ա��Ӧ
inline bool bfs(){
    queue<int> q;
    memset(inque,0,sizeof(inque));
    memset(pre,-1,sizeof(pre));
    inque[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next){
            int d=node[i].v;
            if(!inque[d]&&node[i].val){
                pre[d].v=u;
                pre[d].edge=i;
                if(d==t)
                    return 1;
                inque[d]=1;
                q.push(d);
            }
        }
    }
    return 0;
}

int EK(){
    int ans=0;
    while(bfs()){
        int mi = inf;
        for(int i=t;i!=s;i=pre[i].v){
            mi=min(mi,node[pre[i].edge].val);
        }
        for(int i=t;i!=s;i=pre[i].v){

            ansk[pre[i].v]=i;
            node[pre[i].edge].val-=mi;
            node[pre[i].edge^1].val+=mi;
        }
        ans+=mi;
    }
    return ans;
}

signed main(){
    found=509;
    s=2666,t=2677;
    n=read();m=read();tot=read();
    for(int i=1;i<=n;i++){
        int T;
        T=read();
        int num;
        while(T--){
            num=read();
            addedge(i,found+num,1);
            addedge(found+num,i,0);
        }
    }
    for(int i=1;i<=n;i++) addedge(i,s,0),addedge(s,i,1);
    for(int i=1;i<=m;i++) addedge(i+found,t,1),addedge(t,i+found,0);
    int ans1=EK();
    s=5555;
    for(int i=1;i<=n;i++) addedge(i,s,0),addedge(s,i,1);
    //for(int i=1;i<=m;i++) addedge(i+found,t,1),addedge(t,i+found,0);
    int ans2=EK();
    int ans=ans1+min(tot,ans2);
    printf("%lld",ans);
    return 0;
}

/*
���������ϣ�A��B������A��һЩԪ��a1,a2,a3������B��һЩԪ��b1,b2,b3����

����a1���b1��b4�������е�һ����ԣ�a2���b1��b250��b2500��������Щ����ûʲô�ر��壩��ԣ�Ϊ������������ж�������Գɹ���

��ô���أ�

��ʵ����ƥ���������ת��Ϊ���������⡣

�Ѽ���A������㣬����B�����յ㣬������һ��Ԫ��a���Զ�Ӧ���϶���Ԫ��b�����һ��aָ��b����Ϊһ�ı�

�����������㣬s��t��s��ָ���������ıߣ������յ���ָ��t�ıߣ�ֻ�����s��t�����������EK�㷨���ɡ�

����Ҫ���¼��Է�����ֻ����������·ʱ�Ӹ���Ǽ��ɡ�
*/
//EK�㷨��������
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
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
int n,m,s,t;
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
int main(){
    s=2019,t=2020;
    register int i;
    m=read();n=read();
    //Ӣ������Ա��n+i�ŵ��ʾ���⼮����Ա��i�ŵ��ʾ
    for(i=1;i<=n;i++)addedge(i+n,t,1),addedge(t,i+n,0);//ʹ����Ӣ���վ��ͻ������
    for(i=1;i<=m;i++)addedge(s,i,1),addedge(i,s,0);//ʹ�����⼮�վ���Դ������
    int u,v;
    while(1){
        u=read();v=read();
        if(u==-1&&v==-1) break;
        addedge(u,v+n,1);
        addedge(v+n,u,0);
    }
    printf("%d\n",EK());
    for(int i=1;i<=n;i++){
        if(ansk[i]){
            cout<<i<<" "<<ansk[i]-n<<'\n';
        }
    }
    return 0;
}

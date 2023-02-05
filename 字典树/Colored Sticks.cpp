/*
��Ŀ���⣺������������ɫ��ľ����ֻ����ͬ����ɫ�������������������������ľ������ܲ���ƴ��һ����ľ����

����˼·�������ֵ���ֻ�Ƿ����˲�ͬ��ɫ�ı�ţ���map<string,int>Ҳ�ǿ��Եģ����ǿ��Լ�¼ÿ����ɫ�Ķȣ�һ��ľ����������ɫ����������������������ò��鼯����ͬ����ɫ��������������������ɫ�����Ⱥ�������һ�����ǿ϶���������������֮�Ǿ�Ҫ�ж�ŷ��·�� �ˣ���������ȵĵ�Ϊ0����2�������ͼ�Ϳ���һ�����꣬���������ӳ�һ��ľ����


�����п���������������ʲô���붼û��ֱ�Ӿ�Crtl+Z��Ӧ�����Possible


*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<sstream>
#include<map>
using namespace std;
#define int long long
#define N 2666666
int tree[N][66];
int in[N];
int mp[N];
int cnt,tot;
//*****************************�ֵ���
int insert(char *s){
    int root=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!tree[root][id]) tree[root][id]=++tot;
        root=tree[root][id];
    }
    if(!mp[root]) mp[root]=++cnt;
    return mp[root];
}
//*****************************���鼯
int f[N];
int getf(int v){
    if(v==f[v]) return f[v];
    else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
void merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2) f[t1]=(t2);
}
//*****************************SLOVE
char s1[N],s2[N];
signed main(){
    cnt=0;tot=0;
    for(int i=0;i<N;i++) f[i]=i;
    while(scanf("%s%s",s1,s2)!=EOF){
        int t1=insert(s1);
        int t2=insert(s2);
        in[t1]++,in[t2]++;
        merge(t1,t2);
    }
    int sum=0;
    int F=1,temp=getf(1);
    for(int i=1;i<=cnt;i++)
        if(temp!=getf(i)) F=0;

    if(F!=1){
        printf("Impossible");//����ͨͼ
        return 0;
    }
    int add=0;
    for(int i=1;i<=cnt;i++){
        if(in[i]%2) add++;
    }
    if(add==0||add==2){
        printf("Possible");
    }else{
        printf("Impossible");

    }
    return 0;
}

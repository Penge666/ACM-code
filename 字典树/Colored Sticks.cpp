/*
题目大意：给你两段有颜色的木棒，只有相同的颜色才能连接起来，问你最后给你的木棒最后能不能拼成一根长木棒。

解题思路：这里字典树只是返回了不同颜色的编号，用map<string,int>也是可以的，我们可以记录每个颜色的度，一个木棒的两个颜色可以相连，所以这里可以用并查集将不同的颜色并起来，最后如果，有颜色的祖先和其他不一样，那肯定不能连起来，反之那就要判断欧拉路径 了，如果奇数度的点为0或者2，那这个图就可以一笔走完，即可以连接成一根木棒。


这题有空输入的情况，就是什么输入都没有直接就Crtl+Z，应该输出Possible


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
//*****************************字典树
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
//*****************************并查集
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
        printf("Impossible");//非连通图
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

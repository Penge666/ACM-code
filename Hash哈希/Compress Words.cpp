//题意：按顺序给你n个单词，对于两个单词重复的部分，一个单词的后缀和另一个单词前缀相等即可缩写。问最后的结果。
//
//题解：hash就完事了。每次新增一个单词时更新答案单词的长度以及hash值。
//
//Hash做法：【嫖的代码·】【感觉还是Hash好使】

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
ll p[3][N],h[3][N];
ll mod[3]={100000007,998244353,100000009},base[3]={73,87,61};
void init()
{
    p[0][0]=p[1][0]=p[2][0]=1;
    for(int i=0;i<3;++i)
        for(int j=1;j<N;++j)
            p[i][j] = (p[i][j-1]*base[i])%mod[i];
}
int getid(char c){
    if(c>='a'&&c<='z') return c-'a';
    if(c>='0'&&c<='9') return c-'0'+26;
    return c-'A'+36;
}
ll gkd(int l,int r,int i){
    ll tmp = (h[i][r]-h[i][l-1]*p[i][r-l+1]%mod[i]+mod[i])%mod[i];
    return tmp;
}
string s,t;
int main()
{
    init();
    int n,idx=1;
    scanf("%d",&n);
    cin>>s;
    for(int z=1;z<n;++z){
        string t;
        cin>>t;
        for(int i=idx;i<=s.length();++i){
            int id = getid(s[i-1]);
            h[0][i] = (h[0][i-1]*base[0]+id)%mod[0];
            h[1][i] = (h[1][i-1]*base[1]+id)%mod[1];
            h[2][i] = (h[2][i-1]*base[2]+id)%mod[2];
        }
        idx=s.length();
        ll H[3]={0};
        int cur=0;
        for(int i=1;i<=t.length();++i){
            int id = getid(t[i-1]);
            for(int j=0;j<3;j++) H[j]=(H[j]*base[j]+id)%mod[j];
            if(H[0]==gkd(idx-i+1,idx,0)&&H[1]==gkd(idx-i+1,idx,1)&&H[2]==gkd(idx-i+1,idx,2)){
                cur=i;
            }
            if(i==idx) break;
        }
        for(int i=cur;i<t.length();i++) s+=t[i];
    }
    cout<<s<<endl;
}

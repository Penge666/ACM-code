/*
题意：给定一个字符串，找出其中一个最长的子串，使得这个子串既是前缀又是后缀又在中间出现。
思路:i + z[i] == n i位开始能匹配到的 后缀 同时 ma >= n - i 之前 出现过不小它 的串
链接：https://codeforces.com/contest/126/problem/B
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxn=1000910;   //字符串长度最大值
int nt[maxn],ex[maxn]; //ex数组即为extend数组
///预处理计算next数组
void GETNEXT(char *str)
{
    int i=0,j,po,len=strlen(str);
    nt[0]=len;///用自己作为后缀与自己匹配
    while(str[i]==str[i+1]&&i+1<len) i++;///暴力求next[1]
    nt[1]=i;

    po=1;///从此点出发next数组延伸位置最远
    for(i=2;i<len;i++)
    {
        if(nt[i-po]< nt[po]+po-i )///第一种情况，可以直接得到next[i]的值
        nt[i]=nt[i-po];
        else///第二种情况，要继续匹配才能得到next[i]的值
        {
            j=nt[po]+po-i;
            if(j<0)j=0; ///小于0表示没有已知相同部分，重新开始匹配
            while(i+j<len&&str[j]==str[j+i])
            j++;
            nt[i]=j;
            po=i;///更新po的位置
        }
    }
}
///计算extend数组
//void EXKMP(char *s1,char *s2)
//{
//    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
//    GETNEXT(s2);
//    while(s1[i]==s2[i]&&i<l2&&i<len)
//    i++;
//    ex[0]=i;
//    po=0;
//    for(i=1;i<len;i++)
//    {
//        if(nt[i-po]<ex[po]+po-i)
//        ex[i]=nt[i-po];
//        else
//        {
//            j=ex[po]+po-i;
//            if(j<0)j=0;
//            while(i+j<len&&j<l2&&s1[j+i]==s2[j])
//            j++;
//            ex[i]=j;
//            po=i;
//        }
//    }
//}
char S[maxn],T[maxn];
map<int,int> mp;
signed main(){
    cin>>S;
    GETNEXT(S);
    int Slen=strlen(S);
//    for(int i=0;i<Slen;i++) cout<<nt[i]<<" ";cout<<endl;
    int ans=-1;
    int mx=0;
    for(int i=1;i<Slen;i++){
        if(i+nt[i]==Slen&&(mx>=(Slen-i))){
            ans=max(ans,(Slen-i));
        }
        mx=max(mx,nt[i]);
    }
    if(ans==-1){
        cout<<"Just a legend";
    }else{
        for(int i=0;i<ans;i++) cout<<S[i];
    }
//    for(int i=0;i<Slen;i++) cout<<nt[i]<<" ";cout<<endl;
//    EXKMP(S,T);
//    for(int i=0;i<Slen;i++) cout<<ex[i]<<" ";cout<<endl;
    return 0;
}
/*
qwertyqwertyqwerty

*/

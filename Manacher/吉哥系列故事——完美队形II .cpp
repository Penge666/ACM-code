/*
题意求的同样是回文，不过多了要求这个回文子串从中点向两边非严格递减，同样的预处理的时候需要用不会影响题目的数字（负数和0等等）来组成新的队列。
扩展回文子串时需要多一句 s[i-p[i]]<=s[i-p[i]+2] 来进行限制从中点向两边非严格递减，至于为什么+2？因为相邻的数是预处理时添加的负数或0，不会影响原串的回文判定。

*/
#include<bits/stdc++.h>

using namespace std;
const int N=100000+100;
int a[N],b[N];
int p[N];
int n;
int init(){
    b[0]=-1,b[1]=0;
    int j=2;
    for(int i=0;i<n;i++){
        b[j++]=a[i];
        b[j++]=0;
    }
    b[j++]=1;
    return j;
}
int manacher(){
    int len=init();
    int id=0,mx=0;
    int ans=0;
    for(int i=1;i<len;i++){
        if(i<mx){
            p[i]=min(p[2*id-i],mx-i);
        }else{
            p[i]=1;
        }
        while(b[i+p[i]]==b[i-p[i]]&&b[i+p[i]]<=b[i+p[i]-2]) ++p[i];
        if((i+p[i])>mx) mx=i+p[i],id=i;
        ans=max(ans,p[i]-1);
    }
    return ans;
}
signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=manacher();
        printf("%d\n",ans);
    }
    return 0;
}

/*
题意:
给出字符串S, 输出S所有前缀的出现次数之和

题解:
仔细回忆一下KMP中next数组的含义, 0 - i 中的最大前缀后缀匹配, 所有非零的情况都说明某前缀成功匹配了一次.
这样遍历一遍遇见非零项就加一的话, 就是所有前缀的出现次数和了.
记得加上M, 即有M个前缀至少都出现一次

*/
#include <cstdio>
#include <cstring>

using namespace std;
#define int long long
const int MAX_N=1010000;
char str[MAX_N],pattern[MAX_N];
int Next[MAX_N];
void getFail(char *p,int plen){
    int i;
    Next[0]=0;Next[1]=0;
    for(i=1;i<plen;i++){
        int j=Next[i];
        while(j&&p[i]!=p[j])
            j=Next[j];
        Next[i+1]=(p[i]==p[j])?j+1:0;
    }
}

signed main(){
    int T,n;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        scanf("%s",pattern);
        for(int i=0;i<=n;i++) Next[i]=0;
        getFail(pattern,n);
        int ans=n;
        for(int i=n;i>0;i--){
            int k=Next[i];
            while(k>0){
                ans=(ans+1)%10007;
                k=Next[k];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

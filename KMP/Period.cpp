/*
kmp的话重点考察对next数组的理解，next[i]是指回滚到上一次匹配的位置，可以发现每次回滚的长度都是 j-next[j] 。所以当有循环节
（n%(n?next[n])==0 && next[n] != 0）的时候，n-next[n]便是最小的循环节长度，循环次数便是 n / ( n - next[n] ) 
 Period POJ - 1961 【KMP的Next数组求一个字符串的最小循环节】
 */

/*
 今天的第一道KMP的题。嘿嘿嘿

KMP的Next数组可以求一个字符串的最小循环节，如果它有的话。
循环节长度 x=len-Next[len]。
比如ababab，x为2
abbcabbcabbc，x为3
但是如果是abba的话x为3，如果想要求这个字符串的最小循环节长度再加一个判断条件即可，
即如果len%x!=0的话x=len。
像abba,x应该为len，即为4.
像abbabba，x应该为7，abbabbab,x为8，abbabbabb，x为3，因为它可以整除了。

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
    int T=1,n;
    while(~scanf("%lld",&n)&&n){

        scanf("%s",pattern);
        for(int i=0;i<=n;i++) Next[i]=0;
        getFail(pattern,n);
        printf("Test case #%lld\n",T++);
        for(int i=0;i<n;i++){
            int len=i+1;
            if(len%(len-Next[i+1])==0&&(len-Next[i+1])!=len){
                printf("%lld %lld\n",len,len/(len-Next[i+1]));
            }
        }
         puts("");
    }
    return 0;
}

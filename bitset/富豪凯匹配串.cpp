/*
题解：
设三个二进制串a,tag,q。若询问的第i位为’_’,则q[i]=0,tag[i]=0。若第i位为0,则q[i]=1,tag[i]=0。若第i位为1，则q[i]=1,tag[i]=1。对于一个确定的文本串，若第i位为0,a[i]=0,否则a[i]=1。对于每一位，若a[i]&q[i]==tag[i]，则询问的串和这个文本串匹配。然后bitset优化一下，或按位压缩成long long。


*/
#include<bits/stdc++.h>
using namespace std;

#define N 1005

bitset<N> s,t,res[N];
char str[N],ss[N];
signed main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++){
            res[i][j]=str[j]-'0';
        }
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",ss);
        for(int i=0;i<m;i++){
            if(ss[i]=='_'){
                s[i]=0;
                t[i]=0;
            }else{

                if(ss[i]=='1'){
                    s[i]=1;
                    t[i]=1;
                }else{
                    s[i]=1;
                    t[i]=0;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if((res[i]&s)==t) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

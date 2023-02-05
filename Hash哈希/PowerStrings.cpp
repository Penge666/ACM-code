// 给出一个不超过1e6的字符串，求这个字符串最多有多少个周期
//
//Hash+暴力求解
//
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define int unsigned long long
#define seed 233
#define mod 10009
#define N 1666666
char str[N];
int hash[N];
int f[N];
int len;
int check(int num){
    for(int i=num*2;i<=len;i+=num){
        if((hash[i]-(hash[i-num]*f[num])%mod+mod)%mod!=hash[num]%mod)
            return 0;
    }
    return 1;
}
signed main(){
    while(1){
        scanf("%s",str+1);
        len=strlen(str+1);
        if(len==1&&str[1]=='.')
            break;
        f[0]=1;
        for(int i=1;i<=len;i++){
            hash[i]=(hash[i-1]*seed+(str[i]-'a'+1))%mod;
            f[i]=(f[i-1]*seed)%mod;
        }
        for(int i=1;i<=len;i++){
            if(len%i==0&&check(i)){
                cout<<len/i<<'\n';
                break;
            }
        }
    }
    return 0;
}

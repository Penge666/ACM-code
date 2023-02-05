// ����һ���ַ��������ַ����д��ڶ����Ӵ���ʹ����Щ�Ӵ������ַ�����ǰ׺�������ַ����ĺ�׺��Ҫ���С�������������Щ�Ӵ��ĳ��ȡ�

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
#define seed 23
#define mod 1000000007
#define N 1666666
char str[N];
int hash[N];
int f[N];
int len;
int check(int num){
    if(hash[num]==(hash[len]-(hash[len-num]*f[num])%mod+mod)%mod)
        return 1;
    else
        return 0;
}
signed main(){
    while(~scanf("%s",str+1)){
        vector<int> ans;
        len=strlen(str+1);
        f[0]=1;
        for(int i=1;i<=len;i++){
            hash[i]=(hash[i-1]*seed+(str[i]-'a'+1))%mod;
            f[i]=(f[i-1]*seed)%mod;
        }
        for(int i=1;i<=len;i++){
            if(check(i)){
                cout<<i<<" ";
            }
        }
        printf("\n");
    }
    return 0;
}

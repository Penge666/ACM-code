#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1000000;
const int seed = 13331;
char s1[maxn];// 子串
char s2[maxn];// 主串
ull _base[maxn],_hash[maxn];
void init(){  // 初始化
    _base[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        _base[i] = _base[i - 1] * seed;
    }
}
ull str_hash(int l,int r){  // 求【L，R】区间的哈希值
    return _hash[r] - _hash[l - 1] * _base[r - l + 1];
}
int main(){
    init();
    int _;cin>>_;
    while(_--){
        scanf("%s%s",s1+1,s2+1);
        int len1=strlen(s1+1);
        int len2=strlen(s2+1);
        _hash[0] = 0;
        for(int i = 1; i <= len2; i++) {   //求字符串的哈希值，类似于求前缀的方法.
            _hash[i] = _hash[i - 1] * seed + (ull)(s2[i] - 'A'+1);// 求主串的哈希
        }
        ull str=0;
        for(int i=1;i<=len1;i++){
            str = str*seed + (ull)(s1[i]-'A'+1);
        }
        long long int ans=0;
        //printf("%llu\n",str);
        for(int i=1;i<=len2-len1+1;i++){
        //printf("%lld\n",str_hash(i,i+len1-1));
            if(str==str_hash(i,i+len1-1))
                ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

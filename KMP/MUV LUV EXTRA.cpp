#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define inf 999999999999999
#define N 16666666
int a,b,m;
char str[N];
char S[N];
int Next[N];
void getNext(){
  int j,k;
  j=0,k=-1;
  Next[0]=-1;
  while(j<m){
    if(k==-1||str[j]==str[k]){
      Next[++j]=++k;
    }else{
      k=Next[k];
    }
  }
  return ;
}
signed main(){

  while(~scanf("%lld%lld",&a,&b)){
      getchar();
      scanf("%s",S);
       int slen=strlen(S);
    int F=0,cnt=0;
    for(int i=0;i<slen;i++){
      if(F){
          str[cnt++]=S[i];
      }
      if(S[i]=='.'){
        F=1;
      }
    }
    m=cnt;
    for(int i=0;i<m/2;i++){
        swap(str[i],str[m-1-i]);
    }
    for(int i=0;i<=m+1;i++) Next[i]=0;
    getNext();
    int ans=a-b;
    for(int i=0;i<m;i++){
      int len=i+1;
      ans=max(ans,a*len-b*(len-Next[len]));

    }

    printf("%lld\n",ans);
  }
  return 0;
}
/*
1 1
1.12312312
*/

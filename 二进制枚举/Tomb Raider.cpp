/*
这道题其实和当时的思路是差不多的，就是去枚举每个字符串的子序列，但是不用去跑lcs，只需要把这些所有没出现过的子序列都存起来，如果某个子序列出现的个数是等于n的话就是这n个字符串的公共子序列了，然后再对这些存起来的子序列进行一个排序就好了。方法可以用dfs去暴力，这里我用的是二进制枚举，需要注意的是在二进制枚举完子序列后的那个if，是为了防止同一个字符串中出现多个相同的子序列的一个判重的操作，其他的不太难理解，主要是二进制枚举的操作。


*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;
map<string,int> ma,vis;
vector<string> v;
int n,m;
bool flag;
string s,str,ch;

bool cmp(string a,string b){
  if(a.length() == b.length())return a < b;
  return a.length() > b.length();
}

void init(){
  ma.clear();
  v.clear();
  flag = false;
  m = n;
}

void Fun(int x){
  string index = ch.substr(x);
  index += ch.substr(0,x);
  str = index;
}

int main()
{
  while(~scanf("%d",&n)){
    init();
    while(m--){
      cin>>ch;
      vis.clear();
      int len = ch.length();
      for(int k=0;k<len;k++){
        Fun(k);
        for(int i=1;i<(1<<len);i++){      // 二进制枚举
          for(int j=0;j<len;j++){
            if(i & (1 << j)){
              s += str[j];
            }
          }
          if(vis[s] == 0){  // 判重
            ma[s] ++;
            vis[s] = 1;
          }
          s.clear();
        }
      }
    }
    for(auto i : ma){       // 遍历求公共子序列
      if(i.second == n){
        v.push_back(i.first);
        flag = true;
      }
    }
    sort(v.begin(),v.end(),cmp);
    if(flag == false){
      puts("0");
    }
    else{
      cout<<v[0]<<endl;
    }
  }
  return 0;
}

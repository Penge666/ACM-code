/*
�������ʵ�͵�ʱ��˼·�ǲ��ģ�����ȥö��ÿ���ַ����������У����ǲ���ȥ��lcs��ֻ��Ҫ����Щ����û���ֹ��������ж������������ĳ�������г��ֵĸ����ǵ���n�Ļ�������n���ַ����Ĺ����������ˣ�Ȼ���ٶ���Щ�������������н���һ������ͺ��ˡ�����������dfsȥ�������������õ��Ƕ�����ö�٣���Ҫע������ڶ�����ö���������к���Ǹ�if����Ϊ�˷�ֹͬһ���ַ����г��ֶ����ͬ�������е�һ�����صĲ����������Ĳ�̫����⣬��Ҫ�Ƕ�����ö�ٵĲ�����


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
        for(int i=1;i<(1<<len);i++){      // ������ö��
          for(int j=0;j<len;j++){
            if(i & (1 << j)){
              s += str[j];
            }
          }
          if(vis[s] == 0){  // ����
            ma[s] ++;
            vis[s] = 1;
          }
          s.clear();
        }
      }
    }
    for(auto i : ma){       // �����󹫹�������
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

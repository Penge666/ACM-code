/*
题目意思：

有n个集合（n<=1000),每个集合有m个数ai（m<=10000,1=<ai<=10000),同一个集合中可能有相同的数.有q个查询（q<=200000),对于每个查询a,b，问是否存在一个集合同时包含a和b.


*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1

#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

bitset<1100>myb[11000],temp;

int main()
{
   int n;

   while(~scanf("%d",&n))
   {
       for(int i=1;i<=10000;i++)
            myb[i].reset(); //清0
       for(int i=0;i<n;i++)
       {
           int num;
           scanf("%d",&num);
           for(int j=1;j<=num;j++)
           {
               int a;
               scanf("%d",&a);
               myb[a].set(i); //置1
           }
       }
       int q;
       scanf("%d",&q);
       for(int i=1;i<=q;i++)
       {
           int a,b;
           scanf("%d%d",&a,&b);
           temp=myb[a]&myb[b];
           if(temp.count()) //是否存在1
                printf("Yes\n");
           else
                printf("No\n");
       }
   }
   return 0;
}

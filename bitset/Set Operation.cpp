/*
��Ŀ��˼��

��n�����ϣ�n<=1000),ÿ��������m����ai��m<=10000,1=<ai<=10000),ͬһ�������п�������ͬ����.��q����ѯ��q<=200000),����ÿ����ѯa,b�����Ƿ����һ������ͬʱ����a��b.


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
            myb[i].reset(); //��0
       for(int i=0;i<n;i++)
       {
           int num;
           scanf("%d",&num);
           for(int j=1;j<=num;j++)
           {
               int a;
               scanf("%d",&a);
               myb[a].set(i); //��1
           }
       }
       int q;
       scanf("%d",&q);
       for(int i=1;i<=q;i++)
       {
           int a,b;
           scanf("%d%d",&a,&b);
           temp=myb[a]&myb[b];
           if(temp.count()) //�Ƿ����1
                printf("Yes\n");
           else
                printf("No\n");
       }
   }
   return 0;
}

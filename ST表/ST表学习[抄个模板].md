https://www.luogu.org/problemnew/show/P3865

https://www.luogu.org/problemnew/show/P1816

https://www.luogu.org/problemnew/show/P2880

 

https://www.luogu.com.cn/problem/P2216//有点难

三道板子题

```c
 1 #include<bits/stdc++.h>
 2 using namespace std;
 3 #define int long long
 4 #define maxn 666666
 5 int a[maxn];
 6 int stmin[maxn][20];
 7 int stmax[maxn][20];
 8 int n,m;
 9 //st[i][j]表示[i,i+2^j-1]的最值 
10 void Init(){
11     int i,j;
12     for(i=1;i<=n;i++)
13         stmin[i][0]=stmax[i][0]=a[i];
14     for(i=1;(1<<i)<=n;i++){   //按区间长度递增顺序递推 
15         for(j=1;j+(1<<i)-1<=n;j++){   //区间起点 
16             stmin[j][i]=min(stmin[j][i-1],stmin[j+(1<<(i-1))][i-1]);
17             stmax[j][i]=max(stmax[j][i-1],stmax[j+(1<<(i-1))][i-1]);
18         }
19     }
20 }
21 int Query_MAX(int l,int r){//得到[l,r]的最值 
22     int k=(int)(log(r-l+1)/log(2));//log也是需要时间的，有些题目会T，预处理向下取整更好 
23     return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
24 //    return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
25 }
26 int Query_MIN(int l,int r){//得到[l,r]的最值 
27     int k=(int)(log(r-l+1)/log(2));//log也是需要时间的，有些题目会T，预处理向下取整更好 
28 //    return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
29     return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
30 }
31 signed  main(){
32     int i,l,r;
33     scanf("%lld%lld",&n,&m);
34     for(i=1;i<=n;i++)
35         scanf("%lld",&a[i]);
36     Init();
37     for(i=1;i<=m;i++){
38         scanf("%lld %lld",&l,&r);
39         printf("%lld\n",Query_MAX(l,r)-Query_MIN(l,r));
40     }
41     return 0;
42 }
```

 
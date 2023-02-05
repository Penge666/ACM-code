1 ¡¡ 2  3
  4 
  5 // #include <bits/stdc++.h>
  6 #include <iostream>
  7 #include <cstdio>
  8 #include <cstring>
  9 using namespace std ;
 10 typedef unsigned long long ull ;
 11 typedef long long ll ;
 12 typedef pair < ll, ll > P ;
 13 const int Maxn = 100010 << 2 ;
 14 const int Mod = 1e9 + 7  ;
 15 const int INF = 0x3f3f3f3f ;
 16  
 17 #define lson ri << 1, l, Mid
 18 #define rson ri << 1 | 1, Mid + 1, r
 19  
 20 int head[Maxn], to[Maxn], Next[Maxn], cnt ;
 21 int d[Maxn], size[Maxn], dis ;
 22 int c[Maxn], n, m ;
 23  
 24 void init (){
 25     cnt = 0 ;
 26     dis = 0 ;
 27     memset(head, 0, sizeof(head)) ;
 28 }
 29  
 30 void add (int u, int v){
 31     to[++cnt] = v ;
 32     Next[cnt] = head[u] ;
 33     head[u] = cnt ;
 34 }
 35  
 36 void Dfs (int x, int pre){
 37     size[x] = 1 ;
 38     d[x] = ++dis ;
 39     for (int i = head[x]; i > 0; i = Next[i]){
 40         if (to[i] != pre) {
 41             Dfs(to[i], x) ;
 42             size[x] += size[to[i]] ;
 43         }
 44     }
 45 }
 46  
 47 void pushUp (int ri){
 48     c[ri] = c[ri << 1] + c[ri << 1 | 1] ;
 49 }
 50  
 51 void Build (int ri, int l, int r){
 52     if (l == r) {
 53         c[ri] =  1;
 54         return ;
 55     }
 56     int Mid = (l + r) >> 1 ;
 57     Build (lson) ;
 58     Build (rson) ;
 59     pushUp(ri) ;
 60 }
 61  
 62 int query (int L, int R, int ri, int l, int r){
 63     if (l >= L && r <= R) return c[ri]  ;
 64     int Mid = (l + r) >> 1 ;
 65     int ans = 0 ;
 66     if (L <= Mid) ans += query(L, R, lson) ;
 67     if (R > Mid) ans += query(L, R, rson) ;
 68     return ans ;
 69 }
 70  
 71 void Updata (int ri, int l, int r, int x){
 72     if (l == r) {
 73         c[ri] ^= 1 ;
 74         return ;
 75     }
 76     int Mid = (l + r) >> 1 ;
 77     if (x <= Mid) Updata (lson, x) ;
 78     else  Updata(rson, x) ;
 79     pushUp(ri) ;
 80 }
 81  
 82 int main (){
 83     // ios_base::sync_with_stdio(false) ;
 84     // cin.tie(0) ;
 85     // cout.tie(0) ;
 86     while (~scanf("%d", &n)){
 87         init() ;
 88         for (int i = 1; i < n; i++){
 89             int x, y ;
 90             // cin >> x >> y ;
 91             scanf("%d%d", &x, &y );
 92             add(x, y) ;
 93             add(y, x) ;
 94         }
 95         Dfs (1, 0) ;
 96         Build (1, 1, n) ;
 97         // cin >> m ;
 98         scanf("%d", &m);
 99         getchar() ;
100         for (int i = 1; i <= m; i++){
101             char ch = getchar() ;
102             int x ;
103             // cin >> x ;
104             scanf("%d", &x);
105             if (ch == 'Q') printf("%d\n", query (d[x], d[x] + size[x] - 1, 1, 1, n)) ;
106             else Updata (1, 1, n, d[x]) ;
107             getchar() ;
108         }
109     }
110     return 0 ;
111 }

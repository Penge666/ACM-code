```C
 1 对于一个字符串S，和一个下标i(i>1)
 2 令Next[i]表示S和S[i...|S|]的最长公共前缀。
 3 例如：S=aabcaabxaaz
 4 Next[5]=3(因为下标[1-3] 和从5开始的下标[5-8]) 注意下标0还是1 
 5 
 6 给定2个字符串S和T(长度分别为n和m)
 7 定义extend[i]为S[i...n]与T的最长公共前缀的长度
 8 求出extend数组
 9      S:a b a b a c a
10       T:a b a a c
11 extend:3 0 4 0 1 0 1
12 
13 ababaca 
14 abac
```

完整模板（理解数组nt[ ],extend[ ]数组的含义）

```c
 1 #include<bits/stdc++.h>
 2 
 3 using namespace std;
 4 
 5 #define int long long
 6 
 7 const int maxn=100010;   //字符串长度最大值
 8 int nt[maxn],ex[maxn]; //ex数组即为extend数组
 9 ///预处理计算next数组
10 void GETNEXT(char *str)
11 {
12     int i=0,j,po,len=strlen(str);
13     nt[0]=len;///用自己作为后缀与自己匹配
14     while(str[i]==str[i+1]&&i+1<len) i++;///暴力求next[1]
15     nt[1]=i;
16  
17     po=1;///从此点出发next数组延伸位置最远
18     for(i=2;i<len;i++)
19     {
20         if(nt[i-po]< nt[po]+po-i )///第一种情况，可以直接得到next[i]的值
21         nt[i]=nt[i-po];
22         else///第二种情况，要继续匹配才能得到next[i]的值
23         {
24             j=nt[po]+po-i;
25             if(j<0)j=0; ///小于0表示没有已知相同部分，重新开始匹配
26             while(i+j<len&&str[j]==str[j+i])
27             j++;
28             nt[i]=j;
29             po=i;///更新po的位置x
30         }
31     }
32 }
33 ///计算extend数组
34 void EXKMP(char *s1,char *s2)
35 {
36     int i=0,j,po,len=strlen(s1),l2=strlen(s2);
37     GETNEXT(s2);
38     while(s1[i]==s2[i]&&i<l2&&i<len)
39     i++;
40     ex[0]=i;
41     po=0;
42     for(i=1;i<len;i++)
43     {
44         if(nt[i-po]<ex[po]+po-i)
45         ex[i]=nt[i-po];
46         else
47         {
48             j=ex[po]+po-i;
49             if(j<0)j=0;
50             while(i+j<len&&j<l2&&s1[j+i]==s2[j])
51             j++;
52             ex[i]=j;
53             po=i;
54         }
55     }
56 }
57 char S[maxn],T[maxn];
58 
59 signed main(){
60     cin>>S>>T;
61     GETNEXT(S);
62     int Slen=strlen(S);
63     for(int i=0;i<Slen;i++) cout<<nt[i]<<" ";cout<<endl;
64     EXKMP(S,T);
65     for(int i=0;i<Slen;i++) cout<<ex[i]<<" ";cout<<endl; 
66     return 0;
67 }
68 /*
69 ababaca 
70 abac
71 */
```

 
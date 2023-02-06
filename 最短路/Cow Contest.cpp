/*
题目大意：有N头牛，评以N个等级，各不相同，先给出部分牛的等级的高低关系，问最多能确定多少头牛的等级
解题思路：一头牛的等级，当且仅当它与其它N-1头牛的关系确定时确定，于是我们可以将牛的等级关系看做一张图，然后进行适当的松弛操作，得到任意两点的关系，再对没一头牛进行检查即可

*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;
int mp[450][450];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(mp[i][k]&&mp[k][j])
                    mp[i][j]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++){
            if(mp[i][j]||mp[j][i])
                sum++;
        }
        if(sum==n-1)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

/*
��Ŀ���⣺��Nͷţ������N���ȼ���������ͬ���ȸ�������ţ�ĵȼ��ĸߵ͹�ϵ���������ȷ������ͷţ�ĵȼ�
����˼·��һͷţ�ĵȼ������ҽ�����������N-1ͷţ�Ĺ�ϵȷ��ʱȷ�����������ǿ��Խ�ţ�ĵȼ���ϵ����һ��ͼ��Ȼ������ʵ����ɳڲ������õ���������Ĺ�ϵ���ٶ�ûһͷţ���м�鼴��

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

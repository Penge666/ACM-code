/*
�����ϣ��������Ĵ�ֻ��Ҫ����f[n][1]�Ϳ����ˣ��������ڴ���һЩ�߽����ݣ������Ʊ��������������ô��õľ���һ�ζ�������ô�ʹ���f[n][2]������������������������Ҫ������f[n][2]��f[n][1]֮������ֵ��
Ҫ�ǵã���ںͳ��ڶ�Ҫ���ǲ����г�ʼ����


*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
int a[N], f[N][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    memset(f,-0x3f,sizeof(f));
    f[0][2] = 0;

    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - a[i - 1]);
        f[i][1] = f[i - 1][0] + a[i - 1];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }

    cout << max(f[n][1], f[n][2]) << endl;

    return 0;
}

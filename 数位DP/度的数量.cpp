/*
K��������ͬ��B���������ݣ��ȼ���������num��B���Ʊ�ʾ���Ƿ�����K��1������λȫ��0��ɣ�������λDp������

��������num�������ÿһλ�ϵ�����(B���Ʊ�ʾ��)���Ӹ�λ���λö�٣�����ö�ٵ���iλ����iλ�ϵ�������x����ô�����¼���������ۣ�

1.x == 0
��ô��iλֻ����0��������λ�����ڶ�����ȷ����ֻ�ܼ������.
2.x == 1
�����iλ���Էֳ����������
1.��iλ��0����ô�������λ�Ͽ��Է�k-last��1��res += f[i][k-last];
2.��iλ��1����ô������λ�ϵ������������������㣬��ΪҪ��֤���е����ֱ�ԭ����ҪС
3.x > 1
ͬ����iλ�ֳ��������
1.��iλ��0����ô�������λ�Ͽ��Է�k-last��1��res += f[i][k-last];
2.��iλ��1����ô�������λ�Ͽ��Է�k-last-1��1��res += f[i][k-last-1];

��λDP
����1��[x,y] => F(y) - F(x-1)
����2�������ĽǶȿ���
���ʣ���������
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 35;

int K,B;
int f[N][N];
/*C(a,b)=C(a-1,b)+C(a-1,b-1)*/

void init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            if(!j) f[i][j]=1;
            else f[i][j]=f[i-1][j]+f[i-1][j-1];
}
int dp(int n){
    if(!n) return 0;

    vector<int> nums;
    while(n) nums.push_back(n%B),n/=B;

    int res=0;
    int last=0; // ʣ��1�ĸ���

    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        if(x){
            res+=f[i][K-last];
            if(x>1){
                if(K-last-1>=0)
                    res+=f[i][K-last-1];
                break;
            }else{
                last++;
                if(last>K) break;
            }
        }
        if(!i&&last==K) res++;//1110���������
    }
    return res;
}
int main(){
    init();

    int l,r;
    cin >> l >> r >> K >> B;

    cout << dp(r) - dp(l-1) << endl;

    return 0;
}

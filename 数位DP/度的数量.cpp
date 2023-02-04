/*
K个互不相同的B的整数次幂，等价于求数字num在B进制表示下是否是由K个1且其他位全是0组成，可用数位Dp来做。

对于数字num，存放其每一位上的数字(B进制表示下)，从高位向低位枚举，假设枚举到第i位，第i位上的数字是x，那么分以下几种情况讨论：

1.x == 0
那么第i位只能是0，后面数位上现在都不能确定，只能继续向后看.
2.x == 1
这里第i位可以分成两种情况：
1.第i位放0，那么后面的数位上可以放k-last个1，res += f[i][k-last];
2.第i位放1，那么后面数位上的情况不能用组合数计算，因为要保证答案中的数字比原数字要小
3.x > 1
同样第i位分成两种情况
1.第i位放0，那么后面的数位上可以放k-last个1，res += f[i][k-last];
2.第i位放1，那么后面的数位上可以放k-last-1个1，res += f[i][k-last-1];

数位DP
技巧1：[x,y] => F(y) - F(x-1)
技巧2：从树的角度考虑
本质：分类讨论
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
    int last=0; // 剩余1的个数

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
        if(!i&&last==K) res++;//1110的情况特判
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

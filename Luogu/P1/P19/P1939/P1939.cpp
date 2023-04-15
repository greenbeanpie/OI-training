#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 5
#define mod 1000000007
int n=3;// n<=max_matrix
struct matrix
{
    long long mat[max_matrix][max_matrix];
    matrix(){
        memset(mat,0,sizeof(mat));
    }
    void init()
    {
        for (int i = 0; i < max_matrix; i++)
        {
            mat[i][i] = 1;
        }
    }
} a;
matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % mod;
                c.mat[i][j] %= mod;
            }
        }
    }
    return c;
}
matrix mquickpower(matrix a, int b)
{
    matrix answer;
    answer.init();
    do
    {
        if (b & 1)
        {
            answer = answer * a;
        }
        a = a * a;
        b >>= 1;
    }while(b);
    return answer;
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P1939.in","r",stdin);
    #endif
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int k;
        cin >> k;
        matrix ans;
        ans.mat[1][1]=ans.mat[1][3]=ans.mat[2][1]=ans.mat[3][2]=1;
        ans=mquickpower(ans,k);
        cout << ans.mat[2][1] << endl;
    }
    return 0;
}
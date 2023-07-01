#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 105
#define mod 100000000
int p,q,a1,a2,n,m;
struct matrix
{
    long long mat[max_matrix+1][max_matrix+1];
    int *operator[](const int &x) { return mat[x]; }
    matrix()
    {
        memset(mat, 0, sizeof(mat));
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
    for (int k = 1; k <= max_matrix; k++)
    {
        for (int i = 1; i <= max_matrix; i++)
        {
            for (int j = 1; j <= max_matrix; j++)
            {
                c[i][j] += a[i][k] * b[k][j] % mod;
            }
        }
    }
    return c;
}
matrix operator%(matrix a, int b)
{
    for (int i = 1; i <= max_matrix; i++)
    {
        for (int j = 1; j <= max_matrix; j++)
        {
            a[i][j] %= b;
        }
    }
    return a;
}

matrix mquickpower(matrix a, int b)
{
    matrix answer;
    answer.init();
    do
    {
        if (b & 1)
        {
            answer = answer * a % mod;
        }
        a = a * a;
        b >>= 1;
    } while (b);
    return answer;
}
int fibonacci(int x)
{
    matrix a;
    //a[1][1] = a[1][2] = a[2][2] = a[2][3] = a[3][2] = 1;
    a[1][1]=a[2][2]=p;
    a[1][2]=a[2][3]=q;
    a[3][2]=1;
    if(x==1){
        return a1;
    }
    else if(x==2){
        return a2;
    }
    return mquickpower(a, x-2)[3][2] % mod;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("P1962.in","r",stdin);
    #endif
    cin >> p >> q >> a1 >> a2 >> n >> m;
    cout << fibonacci(n)%mod;
    return 0;
}
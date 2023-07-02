#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define max_matrix 2
#define mod m
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
} start;
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
    matrix answer=start;
    do
    {
        if (b & 1)
        {
            answer = answer * a % mod;
        }
        a = a * a%mod;
        b >>= 1;
    } while (b);
    return answer;
}
int fibonacci(int x)
{
    start[1][1]=a2;
    start[1][2]=a1;
    matrix a;
    //a[1][1] = a[1][2] = a[2][2] = a[2][3] = a[3][2] = 1;
    a[1][1]=p;
    a[2][1]=q;
    a[1][2]=1;
    if(x==1){
        return a1;
    }
    else if(x==2){
        return a2;
    }
    return mquickpower(a, x-2)[1][1] % mod;
}

signed main()
{
    cin >> p >> q >> a1 >> a2 >> n >> m;
    if(n==1){
        cout << a1;
    }
    else if(n==2){
        cout << a2;
    }
    else{
        cout << fibonacci(n)%m;
    }
    return 0;
}
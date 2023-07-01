<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 105
#define mod 100000000
=======
#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define max_matrix 2
#define mod m
>>>>>>> 3f56fc9 (上传2023.7.1-3)
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
<<<<<<< HEAD
} a;
=======
} start;
>>>>>>> 3f56fc9 (上传2023.7.1-3)
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
<<<<<<< HEAD
    matrix answer;
    answer.init();
=======
    matrix answer=start;
>>>>>>> 3f56fc9 (上传2023.7.1-3)
    do
    {
        if (b & 1)
        {
            answer = answer * a % mod;
        }
<<<<<<< HEAD
        a = a * a;
=======
        a = a * a%mod;
>>>>>>> 3f56fc9 (上传2023.7.1-3)
        b >>= 1;
    } while (b);
    return answer;
}
int fibonacci(int x)
{
<<<<<<< HEAD
    matrix a;
    //a[1][1] = a[1][2] = a[2][2] = a[2][3] = a[3][2] = 1;
    a[1][1]=a[2][2]=p;
    a[1][2]=a[2][3]=q;
    a[3][2]=1;
=======
    start[1][1]=a2;
    start[1][2]=a1;
    matrix a;
    //a[1][1] = a[1][2] = a[2][2] = a[2][3] = a[3][2] = 1;
    a[1][1]=p;
    a[2][1]=q;
    a[1][2]=1;
>>>>>>> 3f56fc9 (上传2023.7.1-3)
    if(x==1){
        return a1;
    }
    else if(x==2){
        return a2;
    }
<<<<<<< HEAD
    return mquickpower(a, x-2)[3][2] % mod;
=======
    return mquickpower(a, x-2)[1][1] % mod;
>>>>>>> 3f56fc9 (上传2023.7.1-3)
}

signed main()
{
<<<<<<< HEAD
    #ifndef ONLINE_JUDGE
        freopen("P1962.in","r",stdin);
    #endif
    cin >> p >> q >> a1 >> a2 >> n >> m;
    cout << fibonacci(n)%mod;
=======
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
>>>>>>> 3f56fc9 (上传2023.7.1-3)
    return 0;
}
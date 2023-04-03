#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 5
#define mod 1000000007
struct matrix
{
    long long mat[max_matrix][max_matrix];
    int*operator[](const int&x){return mat[x];}
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
    for (int k = 1; k <= max_matrix; k++)
    {
        for (int i = 1; i <= max_matrix; i++)
        {
            for (int j = 1; j <= max_matrix; j++)
            {
                c[i][j] += a[i][k] * b[k][j]%mod;
                
            }
        }
    }
    return c;
}
matrix operator%(matrix a,int b){
    for(int i=1;i<=max_matrix;i++){
        for(int j=1;j<=max_matrix;j++){
            a[i][j]%=b;
        }
    }return a;
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
            answer = answer % mod;
        }
        a = a * a;
        b >>= 1;
    }while(b);
    return answer;
}
int fibonacci(int x){
matrix a;
    a[1][1]=a[1][2]=a[2][2]=a[2][3]=a[3][2]=1;
    return mquickpower(a,x)[3][2]%mod;
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P1962.in","r",stdin);
    #endif
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
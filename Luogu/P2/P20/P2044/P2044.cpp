#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int long long
int m,a,c,x0,n,g;
#define max_matrix 5
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
                c.mat[i][j] += a[i][k] * b[k][j];
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
    cin >> m >> a >> c >> x0 >> n >> g;
    
}
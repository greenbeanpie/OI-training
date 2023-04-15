#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max_matrix 5
int p,q,n;// p=a+b,q=ab
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

int f(int x){// f(n)=a^n+b^n=f(n-1)(a+b)-a^(n-1)*b-a*b^(n-1)=f(n-1)(a+b)-ab(f(n-2));
    if(x==0){
        return 2;
    }
    else if(x==1){
        return p;
    }
    else{
        matrix a;
        a[1][1]=p;
        a[1][2]=2;
        matrix b;
        b[1][1]=p;
        b[2][1]=-q;
        b[1][2]=1;
        b[2][2]=0;
        a=a*mquickpower(b,n);
        return a[1][2];
    }
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("UVA10655.in","r",stdin);
    #endif
    while(cin >> p >> q >> n){
        if(n==-1){
            break;
        }
        cout << f(n) << endl;
        n=-1;
    }
    return 0;
}
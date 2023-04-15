#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define max_matrix 10
struct matrix
{
    long long mat[max_matrix+1][max_matrix+1];
    int*operator[](const int&x){return mat[x];}
    matrix(){
        memset(mat,0,sizeof(mat));
    }
    void init()
    {
        for (int i = 0; i <= max_matrix; i++)
        {
            mat[i][i] = 1;
        }
    }
} a;
matrix operator%(matrix a,int b){
    for(int i=1;i<=max_matrix;i++){
        for(int j=1;j<=max_matrix;j++){
            a[i][j]%=b;
        }
    }return a;
}
matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int k = 0; k <= max_matrix; k++)
    {
        for (int i = 0; i <= max_matrix; i++)
        {
            for (int j = 0; j <= max_matrix; j++)
            {
                c.mat[i][j] += (a[i][k] * b[k][j])%mod;
                c.mat[i][j]%=mod;
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
            answer =answer % mod;
        }
        a = a * a;
        b =b>>1;
    }while(b);
    return answer%mod;
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P2106.in","r",stdin);
    #endif
	int n;
	cin >> n;
	matrix a;
    a[0][0]=a[0][1]=a[0][2]=1;
    a[1][0]=1;
    a[1][1]=1;
    a[1][2]=1;
    a[1][3]=1;
    for(int i=2;i<=7;i++){
        a[i][i-2]=a[i][i-1]=a[i][i]=a[i][i+1]=a[i][i+2]=1;
    }
    a[8][6]=a[8][7]=a[8][8]=a[8][9]=1;
    a[9][7]=a[9][8]=a[9][9]=1;
    matrix answer;
    for(int i=1;i<=9;i++){
        answer[0][i]=1;
    }
    answer=answer*mquickpower(a,n-1);
    int sum=0;
    for(int i=0;i<10;i++){
        sum+=answer[0][i];
        sum%=mod;
    }
    if(n==1){
        sum++;
    }
    cout << sum%mod;
    return 0;
}
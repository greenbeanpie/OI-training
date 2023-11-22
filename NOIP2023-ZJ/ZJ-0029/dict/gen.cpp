#include<bits/stdc++.h>
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=5e5+5,M=N*4+5,K=1e7+5;mt19937 rnd(time(0));
int main(){
    freopen("dict.in","w",stdout);
    int n=3e3,m=3e3;printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++) printf("%c",(char)(R(26)-1+'a'));printf("b\n");
    }
}
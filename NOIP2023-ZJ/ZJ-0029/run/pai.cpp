#include<bits/stdc++.h>
#define Gc() getchar()
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=2e5+5,M=N*4+5,K=1e7+5;const ll INF=4e18;mt19937 rnd(time(0));
int main(){
    system("g++ -o bl bl.cpp -O2");
    system("g++ -o gen gen.cpp -O2");
    system("g++ -o run run.cpp -O2");
    int t=0;while(++t){
        printf("%d\n",t);
        system("./gen&&./bl&&./run");
        if(system("diff run.out run.ans")){puts("ZJAKIOI");return 0;}
    }
}
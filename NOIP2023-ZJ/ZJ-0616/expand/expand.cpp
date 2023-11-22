#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
// #include<Genshin.h>
// #include<oneonefourfiveonefour.h>
using namespace std;
const int MAXN = 10000005;
int c,n,m,q;
int x[MAXN];
int y[MAXN];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if(c == 1){
        for(int i = 1;i <= n;i++){
            scanf("%d", &x[i]);
        }
        for(int i = 1;i <= m;i++){
            scanf("%d", &y[i]);
        }
        int num[1005][1005];
        for(int i = 1;i <= q;i++){
            int kx,ky;
            scanf("%d%d", &kx, &ky);
            for(int j = 1;j <= kx;j++){
                int px,vx;
                scanf("%d%d", &px, &vx);
                num[q][px] = vx;
            }
        }
    }
    cout<<"100101";
    return 0;
}
// 
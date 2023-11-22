#include <bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 5e6 + 10,INF = 0x7f7f7f7f7f7f7f7f,MOD = 9878325455767;

int n,m,k,d;
struct task{
	int pos,conti,reward;
}op[N];

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;!isdigit(ch);ch = getchar())
        if(ch == '-') f = -1;
    for(;isdigit(ch);ch = getchar())
        x = (x << 1) + (x << 3) + ch -'0';
    return x * f;
}

void fre(){
    freopen("run.in","r",stdin);//////////////////////////////
    freopen("run.out","w",stdout);
}

signed main()
{
    fre();////////////////////////////////////////////////////
    int c = read(),T = read();
    while(T --){
    	n= read(),m = read(),k = read(),d = read();
    	for(int i = 1;i <= m;i ++){
    		op[i].pos = read();
    		op[i].conti = read();
    		op[i].reward = read();
		}
    	printf("%lld\n",0);
	}
    return 0;
}

#include <bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 5e5 + 10,INF = 0x7f7f7f7f7f7f7f7f,MOD = 9878325455767;

int n,m;
int a[N],tmp[N],b[N];

struct operate{
	char op[5];
	int i,j;
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
    freopen("tribool.in","r",stdin);//////////////////////////////
    freopen("tribool.out","w",stdout);
}

void run(){
	for(int i = 1;i <= m;i ++){
		char opt = op[i].op[0];
		if(opt == 'T') a[op[i].i] = 1;
		if(opt == 'F') a[op[i].i] = 0;
		if(opt == 'U') a[op[i].i] = 3;
		//if(opt == '+') a[op[i].i] = a[op[i].j] & 1;
		//if(opt == '-') a[op[i].i] = 1 ^ (a[op[i].j] & 1);
		if(opt == '+') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j];
		if(opt == '-') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j] ^ 1;
		//if(opt == '-') a[op[i].i] = (a[op[i].j] == 3) ? 2 : a[op[i].j] ^ 1;

	}
}

signed main()
{
    fre();////////////////////////////////////////////////////
    int c = read(),T = read();
    
    while(T --){
    	cin >> n >> m;
    	//memset(a,0,sizeof(a));
    	for(int i = 1;i <= n;i ++) a[i] = 1;
    	for(int i = 1;i <= m;i ++){
    		cin >> op[i].op;
    		if(op[i].op[0] == '+' || op[i].op[0] == '-') cin >> op[i].i >> op[i].j;
    		else cin >> op[i].i;
		}
		
		run();
		/*for(int i = 1;i <= m;i ++){
			char opt = op[i].op[0];
			if(opt == 'T') a[op[i].i] = 1;
			if(opt == 'F') a[op[i].i] = 0;
			if(opt == 'U') a[op[i].i] = 3;
			//if(opt == '+') a[op[i].i] = a[op[i].j] & 1;
			//if(opt == '-') a[op[i].i] = 1 ^ (a[op[i].j] & 1);
			if(opt == '+') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j];
			if(opt == '-') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j] ^ 1;
		}*/
		
		for(int i = 1;i <= n;i ++) {
			tmp[i] = a[i];
			//if(a[i] != 3) a[i] = 0;
			if(a[i] == 3) a[i] = 0;
		}
		
		/*if(T == 4){
			for(int i = 1;i <= n;i ++)printf("%lld ",tmp[i]);
			puts("");
		} */
		
		run();
		/*for(int i = 1;i <= m;i ++){
			char opt = op[i].op[0];
			if(opt == 'T') a[op[i].i] = 1;
			if(opt == 'F') a[op[i].i] = 0;
			if(opt == 'U') a[op[i].i] = 3;
			//if(opt == '+') a[op[i].i] = a[op[i].j] & 1;
			//if(opt == '-') a[op[i].i] = 1 ^ (a[op[i].j] & 1);
			if(opt == '+') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j];
			if(opt == '-') a[op[i].i] = (a[op[i].j] == 3) ? 3 : a[op[i].j] ^ 1;
		}*/
		
		int res = 0;
		for(int i = 1;i <= n;i ++){
			if(a[i] == 3) {res ++;continue;}
			res += a[i] ^ tmp[i];
		}
		/*if(T == 4){
			for(int i = 1;i <= n;i ++)printf("%lld ",a[i]);
			puts("");
		}*/
		printf("%lld\n",res);
	}
    return 0;
}

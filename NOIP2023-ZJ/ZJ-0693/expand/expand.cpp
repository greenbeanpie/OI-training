#include <bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 5e5 + 10,INF = 0x7f7f7f7f7f7f7f7f,MOD = 9878325455767;

int x[N],y[N];
int tmpx[N],tmpy[N];

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
    freopen("expand.in","r",stdin);//////////////////////////////
    freopen("expand.out","w",stdout);
}

signed main()
{
    fre();////////////////////////////////////////////////////
    int c = read(),n = read(),m = read(),q = read();
    int maxx = 0,maxy = 0;
    int minx = INF,miny = INF;
	for(int i = 1;i <= n;i ++) x[i] = read(),maxx = max(maxx,x[i]),minx = min(minx,x[i]);
    for(int i = 1;i <= m;i ++) y[i] = read(),maxy = max(maxy,y[i]),miny = min(miny,y[i]);
    
    bool f = 1;
    int t = (x[1] - y[1]) * (x[n] - y[m]);
    if(t <= 0) f = 0;
    if(maxx <= miny && (x[1] > y[1] || x[n] > y[m])) f = 0;
    if(minx >= maxy && (x[1] < y[1] || x[n] < y[m])) f = 0;
    
	if(!f) cout << 0;
    else cout << 1;
    
    while(q --){
    	for(int i = 1;i <= n;i ++) tmpx[i] = x[i];
		for(int i = 1;i <= m;i ++) tmpy[i] = y[i]; 
		
    	int kx = read(),ky = read();
    	
    	while(kx --){
    		int pos = read(),value = read();
    		tmpx[pos] = value; 
		}
		
		while(ky --){
			int pos = read(),value = read();
    		tmpy[pos] = value; 
		}
		
		maxx = max(tmpx[1],tmpx[n]); maxy = max(tmpy[1],tmpy[m]);minx = min(tmpx[1],tmpx[n]),miny = min(tmpy[1],tmpy[m]);
		int midmaxx = 0,midmaxy = 0,midminx = INF,midminy = INF;
		for(int i = 2;i < n;i ++) maxx = max(maxx,tmpx[i]),minx = min(minx,tmpx[i]);
		for(int i = 2;i < m;i ++) maxy = max(maxy,tmpy[i]),miny = min(miny,tmpy[i]); 
		
		bool f = 1;
    	int t = (tmpx[1] - tmpy[1]) * (tmpx[n] - tmpy[m]);
    	if(t <= 0) f = 0;
    	if(maxx == maxy || minx == miny) f = 0;
    	//bool neg = (tmpx[1] - tmpy[1]) < 0;
    	//if(neg && midminx > midmaxy) f = 0;
    	//if(!neg && midminy > midmaxx) f = 0;
    	//if(maxx < miny && (tmpx[1] > tmpy[1] || tmpx[n] > tmpy[m])) f = 0;
    	//if(minx > maxy && (tmpx[1] < tmpy[1] || tmpx[n] < tmpy[m])) f = 0;

		if(!f) cout << 0;
    	else cout << 1;
	}
    return 0;
}

#include<bits/stdc++.h>
#define _ (int)(1e5 + 4)
using namespace std;

int c,t,n,m;
int ind[_],val[_];
struct info {
	int pre,now,opt;
} p[_];

inline void init() {
	memset(val,-1,sizeof(val));
	memset(p,0,sizeof(p));
	memset(ind,0,sizeof(ind));
}
inline void read() {
	for(int i = 1; i <= m; i ++) {
		char v;
		int x,y;
		cin >> v;
		if(v == '+') {
			scanf("%d %d",&x,&y);
			ind[x] ++;
			p[i] = {y,x,1};
		} else if(v == '-') {
			scanf("%d %d",&x,&y);
			ind[x] ++;
			p[i] = {y,x,-1};
		} else {
			scanf("%d",&x);
			if(v == 'T') p[i] = {0,x,5};
			if(v == 'F') p[i] = {0,x,3};
			if(v == 'U') p[i] = {0,x,4};
		}
	}
}
inline void solve2() {
	for(int i = 1; i <= m; i ++) {
		if(!p[i].pre) val[p[i].now] = p[i].opt - 4;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(!val[i]) cnt ++;
	}
	printf("%d\n",cnt);
}
inline void solve3() {
	for(int i = 1; i <= m; i ++) {
		if(!p[i].pre) val[p[i].now] = 0;
		else val[p[i].now] = val[p[i].pre]; 
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		if(!val[i]) cnt ++;
	}
	printf("%d\n",cnt);
}
int main() {

	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	while(t --) {

		scanf("%d %d",&n,&m);
		init();
		read();
		if(c == 3 || c == 4) solve2();
		if(c == 5 || c == 6) solve3();

	}
	return 0;
}

/*
3 2
2 2
T 2
U 2
5 5
T 2
F 4
U 3
T 2
T 1

*/

#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y;
short a[300010];
char v;
int ans;

inline void init(){
	ans = 0;
	memset(a,0,sizeof(a)/sizeof(int));
	return ;
}

inline void solve34(){
	for(register int i=0;i<t;++i){
		init();
		scanf("%d%d",&n,&m);
		for(register int j=0;j<m;++j){
			cin>>v;
			if(v == 'U'){
				scanf("%d",&x);
				a[x] = -1;
			}
			else{
				scanf("%d",&x);
				a[x] = 0;
			}
		}
		for(register int j=1;j<=n;++j){
			if(a[j] == -1) ans++;
		}
		cout<<ans<<"\n";
	}
	return ;
}

inline void solve56(){
	for(register int i=0;i<t;++i){
		init();
		scanf("%d%d",&n,&m);
		for(register int j=0;j<m;++j){
			cin>>v;
			if(v == 'U'){
				scanf("%d",&x);
				a[x] = -1;
			}
			else if(v == '+'){
				scanf("%d%d",&x,&y);
				a[x] = a[y];
			}
		}
		for(register int j=0;j<=n;++j){
			if(a[j] == -1) ans++;
		}
		cout<<ans<<"\n";
	}
	return ;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c == 3 || c == 4)	solve34();
	else if(c == 5 || c == 6)	solve56();
	return 0;
}

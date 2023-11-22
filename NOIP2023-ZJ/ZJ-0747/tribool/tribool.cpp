#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int f[maxn],d[maxn],g[maxn];
int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}
int find2(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int get_fa(int x){
	if(g[x]==x) return x;
	int tmp=find(g[x]);
	d[x]^=d[g[x]];
	return g[x]=tmp;
}
int tot,T,F,U,n,m;
char c;
int check(){
	c=getchar();
	if(c=='T') return 1;
	if(c=='F') return 2;
	if(c=='U') return 3;
	if(c=='-') return 4;
	if(c=='+') return 5;
	return 0;
}
int R(int x){
	if(x==U) return U;
	if(x==T) return F;
	if(x==F) return T;
	if(x>n) return x-n;
	return x+n;
}
int ans;
void clear(){
	ans=0;
	for(int i=1;i<=2*n+20;i++){
		f[i]=i,d[i]=0,g[i]=i;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	T=2*n+1,F=2*n+2,U=2*n+3,tot=2*n+3;
	clear();
	while(m--){
		int tmp=check(),x,y;
		while(!tmp) tmp=check();
		if(tmp<=3){
			scanf("%d",&x);
			f[x]=2*n+tmp;
			f[x+n]=R(2*n+tmp);
		}
		else {
			scanf("%d%d",&x,&y);
			if(tmp==4){
				f[x]=find(y+n);
				f[x+n]=find(y);
			}
			else {
				f[x]=find(y);
				f[x+n]=find(y+n);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int disa=0,disb=0,a=find2(i),b=find2(i+n);
		int x=get_fa(a),y=get_fa(b);
		if(x==T||x==F||y==T||y==F||x==U||y==U) continue;
		disa=d[a],disb=d[b];
		if(x==y){
			if(disa^disb^1){
				g[x]=U;
			}
			continue;
		}
		g[x]=y;
		d[x]=disa^disb^1;
	}
	for(int i=1;i<=n;i++){
		if(get_fa(find2(i))==U){
			ans++;
		}
	}
	printf("%d\n",ans);
}
int T_T,tid;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d",&tid);
	scanf("%d",&T_T);
	while(T_T--){
		solve();
	}
	return 0;
}


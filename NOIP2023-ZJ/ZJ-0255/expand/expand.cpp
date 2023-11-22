#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c,n,m,q,a[N],b[N],ans[N],t1[N],t2[N],h[N],s[N];
int solve1(){
	if(a[1] != b[1]) return 1;
	else return 0;
}
int solve2(){
	if(a[1] > b[1] && a[n] > b[m] || a[1] < b[1] && a[n] < b[m]) return 1;
	else return 0;
}
bool judge(int pos,int num){
	for(int i=num;i<=m;i++)
	    if(b[i] < a[pos]) return 1;
	return 0;
}
int judge2(int l,int r,int num){
	for(int i=l;i<=r;i++)
	    if(b[num] < a[i]) return i;
	return 0;
}
int solve3(){
	if(!(a[1] > b[1] && a[n] > b[m] || a[1] < b[1] && a[n] < b[m])) return 0;
	for(int i=1;i<=n;i++) t1[i] = a[i];
	for(int i=1;i<=m;i++) t2[i] = b[i];
	if(a[1] < b[1]){
		for(int i=1;i<=n;i++) b[i] = t1[i];
		for(int i=1;i<=m;i++) a[i] = t2[i];
		swap(n,m);
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	//cout<<endl;
	int pos = 1,last = 1;
	a[n + 1] = a[n];
	for(int i=1;i<=m;i++){
		int wz = judge2(last,pos - 1,i);
		if(!judge(pos,i) && !wz) return 0;
		while(pos <= n && b[i] < a[pos]) ++ pos;
		last = wz;
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),h[i] = a[i];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),s[i] = b[i];
	if(c == 1) ans[0] = solve1();
	else if(c == 2) ans[0] = solve2();
	else ans[0] = solve3();
	for(int i=1;i<=q;i++){
		int kx,ky; scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			int px,vx; scanf("%d%d",&px,&vx);
			a[px] = vx;
		}
		for(int j=1;j<=ky;j++){
			int py,vy; scanf("%d%d",&py,&vy);
			b[py] = vy;
		}
		if(c == 1) ans[i] = solve1();
		else if(c == 2) ans[i] = solve2();
		else ans[i] = solve3();
		for(int j=1;j<=n;j++) a[j] = h[j];
		for(int j=1;j<=m;j++) b[j] = s[j];
	}
	for(int i=0;i<=q;i++) printf("%d",ans[i]);
	return 0;
}

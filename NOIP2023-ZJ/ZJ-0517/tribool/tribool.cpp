#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 20061026;
int n,m,cnt;
int f[100010],f1[100010];
int x[100010],y[100010];
int v[100010];
int res,min_res;
bool work(){
	for(int i = 1;i <= n;i++){
		f1[i] = f[i];
	}
	for(int i = 1;i <= n;i++){
		if(v[i] == 2){
		    f1[x[i]] = 1;
		} else {
			if(v[i] == 3){
				f1[x[i]] = -1;
			} else {
				if(v[i] == 4) {
					f1[x[i]] = 0;
				} else {
					f1[x[i]] = v[i] * f1[y[i]];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(f[i] != f1[i]) return false;
	}
	return true;
}
void build(int now){
	if(min_res == 0) return;
	if(now > n) {
		if(work()){
	    	min_res = min(res,min_res);
		}
		return;
	}
	if(f[now] != N) {
		build(now+1);
	}
	f[now] = 1;
	build(now+1);
	f[now] = -1;
	build(now+1);
	f[now] = 0;
	res++;
	if(res >= min_res) {
		res--;
		f[now] = N;
		return;
	}
	build(now+1);
	res--;
	f[now] = N;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t; 
	scanf("%d%d",&c,&t);
	while(t--){
		n = 0,m = 0;
		scanf("%d%d",&n,&m);
		cnt = 0;
		min_res = N;
		res = 0;
		for(int i = 1;i <= m;i++){
			x[i] = 0,y[i] = 0,v[i] = 0,f[i] = N;
			char vv;
			cin>>vv;
			if(vv == 'T'||vv == 'F'||vv == 'U'){
				scanf("%d",&x[i]);
				if(vv == 'T') v[i] = 2; else
				if(vv == 'F') v[i] = 3; else
				if(vv == 'U') v[i] = 4;
			} else {
				if(vv == '+') v[i] = 1; else v[i] = -1;
				scanf("%d%d",&x[i],&y[i]);
			}
		}
		build(1);
		printf("%d\n",min_res);
	}
	return 0;
}
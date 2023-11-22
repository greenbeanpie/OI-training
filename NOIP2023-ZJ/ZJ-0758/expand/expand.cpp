#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int i,j,m,n,c,q,x,y,t1,t2,a[N],b[N],a1[N],b1[N];
int g(){
	int minn=0x3f3f3f3f,maxn=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxn) maxn=a[i];
	}
	for(int i=1;i<=m;i++){
		if(b[i]<minn) minn=b[i];
	}
	if(b[n]>maxn and minn>b[n]) return 1;
	return 0;
}
void solve1(){
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	memcpy(a1,a,sizeof a);
	memcpy(b1,b,sizeof b);
	cout<<g();
	for(i=1;i<=q;i++){
		memcpy(a1,a,sizeof a);
		memcpy(b1,b,sizeof b);
		cin>>t1>>t2;
		for(j=1;j<=t1;j++){
			cin>>x>>y;
			a1[x]=y;
		}
		for(j=1;j<=t2;j++){
			cin>>x>>y;
			b1[x]=y;
		}
//		for(int i=1;i<=n;i++) cout<<a1[i]<<" ";
//		puts("");
//		for(int i=1;i<=m;i++) cout<<b1[i]<<" ";
//		puts("");
		cout<<g();
	}
}
int solve(int a[],int b[]){
	int i=1,j=1;
	
	while(i<=n and j<=m){
//		cout<<i<<" "<<j<<endl;
		if(a[i]<b[j]){
			i++;j++;
		}
		else{
			while(j>0 and a[i]>b[j]){
				j--;
			}
			if(j<=0) return 0;
		}
	}
	while(j<=m){
		if(a[n]>b[j]) return 0;
		j++;
	}
	while(i<=n){
		if(a[i]>b[m]) return 0;
		i++;
	}
	return 1;
	
}
int f(){
	if(a1[1]>=b1[1] and a1[n]<=b1[m]) return 0;
	if(a1[1]<=b1[1] and a1[n]>=b1[m]) return 0;

	if(a1[1]<b1[1]) {
//		puts("1");
		return solve(a1,b1);
		
	}
	else return solve(b1,a1);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>q;
	if(c>=8 and c<=14){
		solve1();
		return 0;
	}
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	memcpy(a1,a,sizeof a);
	memcpy(b1,b,sizeof b);
	cout<<f();
	for(i=1;i<=q;i++){
		memcpy(a1,a,sizeof a);
		memcpy(b1,b,sizeof b);
		cin>>t1>>t2;
		for(j=1;j<=t1;j++){
			cin>>x>>y;
			a1[x]=y;
		}
		for(j=1;j<=t2;j++){
			cin>>x>>y;
			b1[x]=y;
		}
//		for(int i=1;i<=n;i++) cout<<a1[i]<<" ";
//		puts("");
//		for(int i=1;i<=m;i++) cout<<b1[i]<<" ";
//		puts("");
		cout<<f();
	}
	return 0;
}

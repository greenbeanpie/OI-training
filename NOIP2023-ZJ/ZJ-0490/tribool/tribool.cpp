#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int node[N];
int depth[N];
int initval[N];
int finalval[N];
int fa1[N];
int fa2[N];
struct Commands{
	char v;
	int i,j;
}order[N];
int n,m;
int findfa1(int x){
	if(x==fa1[x]) return x;
	depth[fa1[x]]=depth[x];
	return x=findfa1(fa1[x]);
}
int find2(int a,int b){
	int ans=1;
	while(fa2[a]!=a&&a!=b) ans++,a=fa2[a];
	if(a==b) return ans;
	else return 1;
}
void init(){
	memset(initval,0,sizeof initval);
	memset(node,0,sizeof node);
}
int Nnot(int x){
	if(x==1) return 2;
	if(x==2) return 1;
	if(x==-1) return -1;
}
void countdi(int i){
	initval[i]+=1;
	if(initval[i]>2) initval[i]=-1;
	if(initval[i]==0) initval[i]=1,countdi(i-1);
	return;
}
bool cmp(){
	for(int i=1;i<=n;i++)
		if(initval[i]!=finalval[i]) return 0;
		return 1;
}
void crack(){
	int ans=1e9;
	for(int i=1;i<=m;i++){
		cin>>order[i].v;
		if(order[i].v=='T'||order[i].v=='F'||order[i].v=='U'){
			int x;
			scanf("%d",&x);
			order[i].i=x;
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			order[i].i=x,order[i].j=y;
		}
	}
	for(int i=1;i<=n;i++) initval[i]=1;
	while(1){
		for(int i=1;i<=n;i++) finalval[i]=initval[i];
		for(int i=1;i<=m;i++){
			if(order[i].v=='T') finalval[order[i].i]=1;
			if(order[i].v=='F') finalval[order[i].i]=2;
			if(order[i].v=='U') finalval[order[i].i]=-1;
			if(order[i].v=='+') finalval[order[i].i]=finalval[order[i].j];
			if(order[i].v=='-') finalval[order[i].i]=Nnot(finalval[order[i].j]);
		}
		if(cmp()){
			int tot=0;
			for(int i=1;i<=n;i++) if(initval[i]==-1) tot++;
			
			ans=min(ans,tot); 
			if(tot==n) break;
		}
		countdi(n);
	}
	cout<<ans<<endl;
	return;
}
void solu1(){
	for(int i=1;i<=m;i++){
		char v;
		int x;
		cin>>v>>x;
		if(v=='T') node[x]=1;
		if(v=='F') node[x]=2;
		if(v=='U') node[x]=-1; 
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(node[i]==-1) ans++;
	cout<<ans<<endl;
	return;
}
void solu2(){
	for(int i=1;i<=m;i++){
		char v;
		int x,y;
		cin>>v;
		if(v=='U') cin>>x,node[x]=-1;
		if(v=='+') cin>>x>>y,node[x]=node[y];
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(node[i]==-1) ans++;
	cout<<ans<<endl;
	return;
}
void solu3(){
	int ans=0;
	for(int i=1;i<=n;i++) fa1[i]=i,fa2[i]=i,depth[i]=1;
	for(int i=1;i<=m;i++){
		char v;
		int x,y;
		cin>>v>>x>>y;
		int xfa1=findfa1(x),yfa1=findfa1(y);
		if(v=='+') {
			if(xfa1!=yfa1) fa1[xfa1]=yfa1;
		}
		else{
			if(xfa1!=yfa1){
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<fa2[i]<<endl;
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		init();
		if(c==1||c==2) crack();
		if(c==3||c==4) solu1();
		if(c==5||c==6) solu2();
		if(c==7||c==8) solu3();
		if(c==9||c==10) solu3(); 
	}
	return 0;
}
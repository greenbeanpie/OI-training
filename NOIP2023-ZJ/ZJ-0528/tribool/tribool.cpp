#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[100001],x,y,in[100001][3],a1[100001],a2[100001],id,si[100001];
bool f[100001];
int fa[100001];
char c,inn[100001];
////////////////////////////////
bool check(){
	for(int i=1;i<=m;i++){
		if(inn[i]=='+'){
			a2[in[i][1]]=a2[in[i][2]];
		}
		else if(inn[i]=='-'){
			a2[in[i][1]]=2-a2[in[i][2]];
		}
		else{
			if(inn[i]=='U'){
				a2[in[i][1]]=1;
			}
			else if(inn[i]=='T'){
				a2[in[i][1]]=0;
			}
			else{
				a2[in[i][1]]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a1[i]!=a2[i]) return 0;
	}
	return 1;
}
void search1(){
	int nn=pow(3,n),ans=n;
	for(int i=1;i<=n;i++) a1[i]=0;
	for(int i=0;i<nn;i++){
		a1[1]++;
		int h=1;
		while(a1[h]>=3){
			a1[h]-=3;
			h++;
			a1[h]++;
		}
		for(int j=1;j<=n;j++) a2[j]=a1[j];
		if(check()){
			int sum=0;
			for(int j=1;j<=n;j++){
				if(a1[j]==1) sum++;
			}
			ans=min(ans,sum);
		}
	}
	cout<<ans<<endl;
	return;
}
////////////////////////////////
void solute2(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(inn[i]=='U') sum++;
	}
	cout<<sum<<endl;
	return;
}
////////////////////////////////
int find(int p){
	int q=fa[p];
	if(q==p) return p;
	int sum=find(q);
	fa[p]=fa[q];
	return sum;
}
void solute3(){
	int sum=0,k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		si[i]=1;
		f[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(inn[i]=='U'){
			a[in[i][1]]=0;
		}
		else{
			a[in[i][1]]=a[in[i][2]];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			f[find(i)]=1;
		}
		else{
			int u=find(i),v=find(a[i]);
			if(u-v){
				fa[u]=v;
				if(f[u]) f[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(f[find(i)]) sum++;
	}
	cout<<sum<<endl;
	return;
}
////////////////////////////////
void solute4(){
	int sum=0,k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		si[i]=1;
		f[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(inn[i]=='-'){
			a[in[i][1]]=-a[in[i][2]];
		}
		else{
			a[in[i][1]]=a[in[i][2]];
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>id>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>inn[i];
			if(inn[i]=='+'||inn[i]=='-') cin>>in[i][1]>>in[i][2];
			else cin>>in[i][1];
		}
		if(id==1||id==2){
			search1();
			continue;
		}
		if(id==3||id==4){
			solute2();
			continue;
		}
		if(id==5||id==6){
			solute3();
			continue;
		}
		if(id==7||id==8){
			solute4();
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int T=114514;
const int F=1919810;
const int U=0xCCF;
int n,m;
struct Var{
	int tfu;
	bool rev;
	int d;
	Var(int tfu,bool rev,int d){
		this->tfu=tfu;
		this->rev=rev;
		this->d=d;
	}
	Var(int tfu){
		this->tfu=tfu;
		this->rev=0;
		this->d=0;
	}
	Var(){
		this->tfu=0;
		this->rev=0;
		this->d=0;
	}
};
Var var[100005];
Var noot(Var x){
	if(x.tfu==T)x.tfu=F;
	else if(x.tfu==F)x.tfu=T;
	else if(x.tfu==U)x.tfu=U;
	else x.rev=!x.rev;
	return x;
}
Var find(int x){
	if(var[x].tfu){
		return var[x];
	}
	if(var[x].d==x){
		return var[x]=Var(0,var[x].rev,x);
	}
	if(var[x].rev){
		return var[x]=noot(find(var[x].d));
	}
	return var[x]=find(var[x].d);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		var[i].d=i;
	}
	for(int i=0;i<m;i++){
		char o;
		int x;
		cin>>o>>x;
		if(o=='T'){
			var[x]=Var(T);
		}
		if(o=='F'){
			var[x]=Var(F);
		}
		if(o=='U'){
			var[x]=Var(U);
		}
		if(o=='+'){
			int y;
			cin>>y;
			var[x]=find(y);
		}
		if(o=='-'){
			int y;
			cin>>y;
			var[x]=noot(find(y));
		}		
	}
	for(int i=1;i<=n;i++){
//		if(var[i].tfu==T)cout<<"X"<<i<<"="<<"T\n";
//		else if(var[i].tfu==F)cout<<"X"<<i<<"="<<"F\n";
//		else if(var[i].tfu==U)cout<<"X"<<i<<"="<<"U\n";
//		else if(var[i].rev)cout<<"X"<<i<<"="<<"notdX"<<var[i].d<<"\n";
//		else if(var[i].d!=0)cout<<"X"<<i<<"="<<"dX"<<var[i].d<<"\n";
		if(var[i].rev&&(var[i].d==i))var[i]=Var(U);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(find(i).tfu==U)ans++;
	}
	cout<<ans<<"\n";
}
int c,t;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(var,0,sizeof(var));
		solve();
	}
	return 0;
}

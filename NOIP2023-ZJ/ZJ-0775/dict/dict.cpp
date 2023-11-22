#include<bits/stdc++.h>
using namespace std;
int n,m,p;
string s;
char c[27],maxn[16],minx[16],mi='z',x,y;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1) cout<<"1";
	if(m==1){
		for(int i=1;i<=n;++i) cin>>c[i];
		for(int i=1;i<=n;++i){
			if(mi>c[i]){
				p=i;
				mi=c[i];
			}
		} 
		for(int i=1;i<=n;++i){
			if(i==p) cout<<"1";
			else cout<<"0";
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			minx[i]=min(x,y);
			maxn[i]=max(x,y);
		}
		mi='z';
		for(int i=1;i<=n;++i){
			mi=min(mi,maxn[i]);//the min in max
		}
		for(int i=1;i<=n;++i){
			if(minx[i]<=mi) cout<<"1";
			else cout<<"0";
		}
	}
	return 0;
}

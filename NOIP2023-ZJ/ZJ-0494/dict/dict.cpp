#include<bits/stdc++.h>
using namespace std;
#define N 3003
#define re register
#define inl inline
#define rep(i,l,r) for(re int i=l;i<=r;i++)
int n,m;
int ans[N];
string s[N];
string big[N],small[N];
inl string to_big(string ss){
	string ret="";
	int sta[27];
	rep(i,0,26) sta[i]=0;
	for(re int i=0;i<m;i++){
		sta[ss[i]-'a']++;
	}
	for(re int i=25;i>=0;--i){
		if(sta[i]){
			for(int j=1;j<=sta[i];j++) ret=ret+char(97+i);
		}
	}
	return ret;
}
void fre(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
int main(){
	fre();
	ios::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>s[i];
		big[i]=to_big(s[i]);
		for(re int j=m-1;j>=0;--j) small[i]=small[i]+big[i][j];
	}
	
	if(n==1){
		cout<<1;return 0;
	}
	/*rep(i,1,n){
		cout<<small[i]<<" "<<big[i]<<endl;
	}*/
	rep(i,1,n){
		bool flag=1;
		rep(j,1,n){
			if(i==j) continue;
			if(small[i]<big[j]) continue;
			else{flag=0;break;}
		}
		if(flag==1) ans[i]=1;
		else ans[i]=0;
	}
	rep(i,1,n) cout<<ans[i];
	return 0;
}
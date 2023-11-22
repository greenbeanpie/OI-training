#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll n,m,maxn=0x3f3f3f3f,maxnum=0x3f3f3f3f;
ll dic[3010][30];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a=getchar();
			dic[i][a-'a'+1]++;
		}
		char b=getchar();
	}
	
	for(int i=1;i<=n;i++){
		for(int j=26;j>=1;j--) {
			if(dic[i][j]!=0){
				if(maxnum>j){
					maxn=dic[i][j];
					maxnum=j;
		//			cout<<i<<" "<<j<<" "<<maxn<<endl;
				}
				if(maxnum==j){
					if(maxn>=dic[i][j]){
						maxn=dic[i][j];
						maxnum=j;
					}
				}
				break;
			}
		}
	}
	
	ll ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			ll minn;
			if(dic[i][j]!=0){
				minn=dic[i][j];
				if(maxnum>j){
					ans=1;
					break;
				}
				else if(maxnum==j){
					if(maxn>minn||(maxn==minn&&minn==m))ans=1;
					else ans=0;
					break;
				}
				else{
					ans=0;
					break;
				}
			}	
		}
		cout<<ans;
	}
	return 0;
}
//100pts......?
//I don't know
//**** ***
//never gonna give you up
//sto ccf orz

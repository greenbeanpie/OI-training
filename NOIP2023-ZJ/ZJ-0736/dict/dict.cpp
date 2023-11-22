#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3300;
int n,m;
string a[N];
int  c[N][30];
int idxx1[N];
int idxx2[N];
int idx1;
bool vis[N];
string ans;
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<a[i].length();j++){
			c[i][(a[i][j]-'a')+1]++;
		}	
	}
	int flag;
	for(int i=1;i<=n;i++){
		flag=1;
		for(int idx1=1;idx1<=n;idx1++){
		if(idx1!=i){
			int x=1;
			int y=26;
			for(int j=x;j<=26;j++){
				if(c[i][j]!=0){
					x=j;
					break;
					}
				}
			for(int j=y;j>=1;j--){
				if(c[idx1][j]!=0){
					y=j;
					break;
					}
				}
			if(x<y)	 continue;
			else if(y<x) flag=0;
			else if(y==x&&c[i][x]<c[idx1][x])continue;
			else if(y==x&&c[i][x]>c[idx1][x])flag=0;
			else flag=0;	
			}
		}
		if(flag==1)ans=ans+'1';
		else ans=ans+'0';
	}
	
	if(n==1)cout<<1<<endl;
	else{
	cout<<ans<<endl;
	}
	return 0;	
}

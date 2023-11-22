#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ton[3005][27],n,m;
string s[3005];
bool bj(int i,int j){
	int l=0,r=25;
	while(l<=r&&!ton[i][l])++l;
	while(l<=r&&!ton[j][r])--r;
	if(l<r)return true;
	if(l>=r)return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		for(auto c:s[i]){
			++ton[i][c-'a'];
		}
	}
	for(int i=1;i<=n;++i){
		int flag=1;
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(!bj(i,j)){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}

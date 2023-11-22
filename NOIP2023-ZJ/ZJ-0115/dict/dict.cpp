#include<bits/stdc++.h>
using namespace std;
int n,m,mx[3010],mn[3010];
bool flag;
string s[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i],mn[i]=100;
		for(int j=0;j<m;j++)mn[i]=min(mn[i],s[i][j]-97),mx[i]=max(mx[i],s[i][j]-97);
	}
	for(int i=1;i<=n;i++){
		flag=1;
		for(int j=1;j<=n;j++)if(mn[i]>=mx[j]&&i!=j)flag=0;
		cout<<flag;
	}
	return 0;
}
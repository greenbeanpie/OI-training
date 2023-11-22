#include<bits/stdc++.h>
using namespace std;
const int N=3010;

int n,m,Min[N],Max[N];
char s[N][N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) Min[i]=30,Max[i]=-1;
	for(int i=1;i<=n;i++){
		cin>>s[i]+1;
		for(int j=1;j<=m;j++){
			Min[i]=min(Min[i],s[i][j]-'a'+1);
			Max[i]=max(Max[i],s[i][j]-'a'+1);
		}
	}
	for(int i=1;i<=n;i++){
		bool fl=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			fl&=(Min[i]<Max[j]);
		}
		if(fl) cout<<1;
		else cout<<0;
	}
	return 0;
}

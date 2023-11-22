#include <bits/stdc++.h>
using namespace std;
int n,m,f[3010][130];
string s[3010],s1[3010],s2[3010];
bool fg;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j='a';j<='z';j++)
			f[i][j]=-1;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		for (int j=0;j<m;j++)
			if (j>f[i][s[i][j]]) 
				f[i][s[i][j]]=j;
	}	
	for (int i=1;i<=n;i++){
		s1[i]=s2[i]=s[i];
		for (int k=0;k<m-1;k++){
			fg=0;
			for (int j='z';j>s[i][k];j--)
				if (f[i][j]>k){
					s1[i][k]=j;
					s1[i][f[i][j]]=s[i][k];
					fg=1;
					break;
				}
			if (fg) break;
		}
		for (int k=0;k<m-1;k++){
			fg=0;
			for (int j='a';j<s[i][k];j++)
				if (f[i][j]>k){
					s2[i][k]=j;
					s2[i][f[i][j]]=s[i][k];
					fg=1;
					break;
				}
			if (fg) break;
		}
	}		
	for (int i=1;i<=n;i++){
		fg=true;
		for (int j=1;j<=n;j++)
			if (s1[j]<s2[i] && i!=j){
				fg=false;
				break;
			}
		if (fg)	cout<<1;
		else cout<<0;
	}
	return 0;
}

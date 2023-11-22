#include<bits/stdc++.h>
using namespace std;
int n,m,mat[35];
char s[3005][3005];
vector<int>v[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=26;j++) mat[j]=0;
		for(int j=1;j<=m;j++) mat[s[i][j]-'a'+1]++;
		for(int j=1;j<=26;j++) if(mat[j]) v[i].push_back(j);
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int l=0,r=v[j].size()-1;
			//if(i==4) cout<<(char)(v[i][l]+'a'-1)<<endl;
			if(v[i][l]<v[j][r]) continue;
			flag=false;break;
		}
		if(flag) printf("1");
		else printf("0");
	}
	return 0;
}
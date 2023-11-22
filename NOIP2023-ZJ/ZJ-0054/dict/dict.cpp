#include<bits/stdc++.h>
using namespace std;
int t[3030][50];
char s[3030][3030];
int mx[3030],mn[3030];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(mn,63,sizeof(mn));
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			t[i][s[i][j]-'a']++,mn[i]=min(mn[i],s[i][j]-'a'),mx[i]=max(mx[i],s[i][j]-'a');
	for(int i=1;i<=n;++i){
		bool flag=1;
		for(int j=1;j<=n;++j)
			if(i!=j)
				if(mn[i]>mx[j]||(mn[i]==mx[j]&&t[i][mn[i]]>=t[j][mx[i]])){
					flag=0;break;
				}
		cout<<flag;
	}
}
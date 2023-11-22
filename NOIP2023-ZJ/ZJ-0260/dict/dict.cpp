#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[3010][210],ans[3010];
string s[3010],smax[3010],smin[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			cnt[i][int(s[i][j])]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j='a';j<='z';j++){
			for(int k=1;k<=cnt[i][j];k++){
				smin[i]+=char(j);
			}
		}
		for(int j='z';j>='a';j--){
			for(int k=1;k<=cnt[i][j];k++){
				smax[i]+=char(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=1;
		for(int j=1;j<=n;j++){
			if(j!=i){
				if(smax[j]<=smin[i]){
					ans[i]=0;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	return 0;
}

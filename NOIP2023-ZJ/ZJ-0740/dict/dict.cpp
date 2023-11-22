#include<bits/stdc++.h>
using namespace std;
string s[3010],smax[3010],smin[3010];
int n,m,ans[3010];
char b[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
,'o','p','q','r','s','t','u','v','w','x','y','z'};
void check(int x){
	int a[30];
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++){
		a[s[x][i]-'a']++;
	}
	for(int i=25;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			smax[x]=smax[x]+b[i];
		}
	}
	for(int i=0;i<=25;i++){
		while(a[i]--){
			smin[x]=smin[x]+b[i];
		}
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];	
	}
	for(int i=1;i<=n;i++){
		check(i);
//		cout<<smax[i]<<endl<<smin[i]<<endl;
	}	
	for(int i=1;i<=n;i++){
		ans[i]=1;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(smin[i]>=smax[j])ans[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	return 0;
}

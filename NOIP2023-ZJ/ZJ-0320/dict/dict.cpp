#include<bits/stdc++.h>
using namespace std;

const int N=3005;
int n,m,maxn[N],minn[N],x;
char s[N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",s),maxn[i]=0,minn[i]=25;
		for(int j=0;j<m;j++) maxn[i]=max(maxn[i],s[j]-'a'),minn[i]=min(minn[i],s[j]-'a');
	}
	for(int i=1;i<=n;i++){
		x=1;
		for(int j=1;j<=n;j++) if(i!=j&&(minn[i]>=maxn[j])){x=0;break;}
		printf("%d",x);
	}
	cout<<"\n";
}

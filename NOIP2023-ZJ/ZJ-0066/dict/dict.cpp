#include<bits/stdc++.h>
using namespace std;
constexpr int M=3005;char s[M];
int n,m,Min[M],Max[M];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		Min[i]=26;Max[i]=0;
		for (int j=1;j<=m;j++)
			Min[i]=min(Min[i],s[j]-'a'),
			Max[i]=max(Max[i],s[j]-'a');
	}
	for (int i=1;i<=n;i++){
		int f=1;
		for (int j=1;f&&j<=n;j++)
			if (i!=j&&Min[i]>=Max[j])
				f=0;
		putchar(f+'0');
	}
	return 0;
}
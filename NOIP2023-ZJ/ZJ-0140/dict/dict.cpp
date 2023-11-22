#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,t[35];
char c[N],ch,c1[N];
string mn[N],mn1[N],a[N],b[N],f;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("\n%s",c+1);
		memset(t,0,sizeof(t));
		for (int j=1;j<=m;j++)
			t[c[j]-96]++;
		int k=0;
		for (int j=1;j<=26;j++)
			while(t[j])c[++k]=j+96,t[j]--,c1[m-k+1]=j+96;
		a[i]=c+1;b[i]=c1+1;
	}
	if(n==1){printf("1\n");return 0;}
	mn[1]=b[1];mn1[n]=b[n];
	for (int i=2;i<n;i++)
		mn[i]=min(b[i],mn[i-1]);
	for (int i=n-1;i>1;i--)
		mn1[i]=min(mn1[i+1],b[i]);
	for (int i=1;i<=n;i++){
		if(i==1)f=mn1[2];
		else if(i==n)f=mn[n-1];
		else f=min(mn[i-1],mn1[i+1]);
		printf("%d",a[i]<f);
	}
}

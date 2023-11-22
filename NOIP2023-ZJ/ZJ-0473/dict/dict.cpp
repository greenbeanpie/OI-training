#include<bits/stdc++.h>
using namespace std;
int n,m,to[30],f;
string a[3005],b[3005],smi,smi2;
char s[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		while((s[1]=getchar())<'a'||s[1]>'z');
		for(int j=2;j<=m;j++)s[j]=getchar();
		sort(s+1,s+m+1);
		a[i]=s+1;
		for(int j=1;j<=m;j++)
		b[i]+=a[i][m-j];
	}
	for(int i=1;i<=m+1;i++)smi=smi+'z';
	smi2=smi;
	for(int i=1;i<=n;i++)if(b[i]<smi)smi=b[i];
	else if(b[i]<smi2)smi2=b[i];
	for(int i=1;i<=n;i++){
		if(smi==b[i]){
			if(a[i]<smi2)f=1;
			else f=0;
		}
		else{
			if(a[i]<smi)f=1;
			else f=0;
		}
		printf("%d",f);
	}
	return 0;
}

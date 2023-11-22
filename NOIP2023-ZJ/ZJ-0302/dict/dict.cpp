#include<bits/stdc++.h>
#define N 3005
using namespace std;
char s[N],r[N],t[N][N],mins1[N],mins2[N];
int n,m,minf1,minf2;
int a[100],b[100];
bool f[N];
void s_min(int x){
	bool p=1;
	for (int i=1;i<=m;i++)
		if (r[i]<mins1[i]) { p=0;break; }
		else if (r[i]>mins1[i]) { p=1;break; }
	if (!p) {
		for (int i=1;i<=m;i++) swap(mins1[i],r[i]);
		swap(minf1,x);
	}
	p=1;
	for (int i=1;i<=m;i++)
		if (r[i]<mins2[i]) { p=0;break; }
		else if (r[i]>mins2[i]) { p=1;break; }
	if (!p) {
		for (int i=1;i<=m;i++) swap(mins2[i],r[i]);
		swap(minf2,x);
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	mins1[1]=mins2[1]='z'+1;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++)
			a[s[j]-'a']++,b[s[j]-'a']++;
		int num=0;
		for (int j=0;j<26;j++)
			while (a[j]) t[i][++num]=j+'a',a[j]--;
		num=0;
		for (int j=25;j>=0;j--)
			while (b[j]) r[++num]=j+'a',b[j]--;
		s_min(i);
	}
	for (int i=1;i<=n;i++)
		if (minf1==i){
			for (int j=1;j<=m;j++)
				if (mins2[j]<t[i][j]) { f[i]=0;break; }
				else if (mins2[j]>t[i][j]){	f[i]=1;break; }
		} else {
			for (int j=1;j<=m;j++)
				if (mins1[j]<t[i][j]) { f[i]=0;break; }
				else if (mins1[j]>t[i][j]){	f[i]=1;break; }
		}
	for (int i=1;i<=n;i++)
		printf("%d",f[i]);
	return 0;
}

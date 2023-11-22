#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,s,d[3005],dd[3005],d1[3005],w;
bool f[3005];
struct node{
	int d[30],t;
}a[4000],b[4000];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if (ch=='-'){
		f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;	
}
inline bool cmpd(int a,int b){
	return a>b;
}
inline bool cmpx(int a,int b){
	return a<b;
}
inline bool cmp(node a,node b){
	for (int i=26;i>=1;i--)
		if (a.d[i]>b.d[i]) return true;
		else if (a.d[i]<b.d[i]) return false;
	return true;
}
inline bool pd(int x){
	w=0;
	for (int i=1;i<=26;i++)
		while (b[x].d[i]!=0) w++,dd[w]=i,b[x].d[i]--;
	for (int i=1;i<=m;i++)
		if (d[i]>dd[i]) return true;
		else if (d[i]<dd[i]) return false;
	return false;
}
inline bool pd1(int x){
	w=0;
	for (int i=1;i<=26;i++)
		while (b[x].d[i]!=0) w++,dd[w]=i,b[x].d[i]--;
	for (int i=1;i<=m;i++)
		if (d1[i]>dd[i]) return true;
		else if (d1[i]<dd[i]) return false;
	return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	
	for (i=1;i<=n;i++){
		char ch=getchar();
		while (ch<'a'||ch>'z') ch=getchar();
		a[i].d[ch-96]++;
		a[i].t=i;
		b[i].d[ch-96]++;
		for (j=2;j<=m;j++){
			ch=getchar();
			a[i].d[ch-96]++;
			a[i].t=i;
			b[i].d[ch-96]++;
		}
	}
	
//	for (i=1;i<=n;i++){
//		sort(a[i].d+1,a[i].d+1+m,cmpd);
//		sort(a[i+n].d+1,a[i+n].d+1+m,cmpx);
//	}
	sort(a+1,a+1+n,cmp);
//	for (i=1;i<=n*2;i++){
//		for (j=1;j<=m;j++) printf("%d ",a[i].d[j]);
//		printf("\n%d\n",a[i].s);
//		printf("%d\n\n",a[i].t);
//	}
	int t=0;
	for (i=26;i>=1;i--)
		while (a[n].d[i]!=0) t++,d[t]=i,a[n].d[i]--;
	t=0;
	for (i=26;i>=1;i--)
		while (a[n-1].d[i]!=0) t++,d1[t]=i,a[n-1].d[i]--;
	
	for (i=1;i<=n;i++){
		if (a[n].t==i){
			if (pd1(i)) printf("1");
			else printf("0");
		}
		else{
			if (pd(i)) printf("1");
			else printf("0");
		}
	}
		
	printf("\n");
	return 0;
}
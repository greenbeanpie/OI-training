#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3005;
int n,m,p[N];
char c[N];
struct node{
	char minn[N],maxn[N];
	int hsminn[N],hsmaxn[N];
}a[N];
bool cmp(char l,char r){
	return l<r;
}
int Hashmaxn(int x,int l,int r){
	return a[x].hsmaxn[r]-a[x].hsmaxn[l-1]*(r-l+1);
}
int Hashminn(int x,int l,int r){
	return a[x].hsminn[r]-a[x].hsminn[l-1]*(r-l+1);
}
bool check(int x,int y){
	if(Hashmaxn(x,1,m)==Hashminn(y,1,m)){
		return 0;
	}
	if(a[x].maxn[1]!=a[y].minn[1]){
		return a[y].minn[1]<a[x].maxn[1];
	}
	int l=1,r=m,ret=m;
	while(l<=r){
		int mid=l+r>>1;
		if(Hashmaxn(x,l,mid)==Hashminn(y,l,mid)){
			l=mid+1;
			ret=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return a[y].minn[ret]<a[x].maxn[ret];
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		sort(c+1,c+m+1,cmp);
		for(int j=1;j<=m;j++){
			a[i].minn[j]=c[j];
			a[i].maxn[m-j+1]=c[j];
		}
		a[i].hsminn[0]=a[i].hsmaxn[0]=1;
		for(int j=1;j<=m;j++){
			a[i].hsminn[j]=a[i].hsminn[j-1]*131+a[i].minn[j]-'a';
			a[i].hsmaxn[j]=a[i].hsmaxn[j-1]*131+a[i].maxn[j]-'a';
		}
	}
	p[0]=1;
	for(int i=1;i<=m;i++){
		p[i]=p[i-1]*131;
	}
	for(int i=1;i<=n;i++){
		bool f=1;
		for(int j=1;j<i;j++){
			if(!check(j,i)){
				f=0;
			}
			if(!f) break;
		}
		for(int j=i+1;j<n;j++){
			if(!check(j,i)){
				f=0;
			}
			if(!f) break;
		}
		if(f) printf("1");
		else printf("0");
	}
	return 0;
}


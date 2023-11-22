#include<bits/stdc++.h>
#define M 3005
#define put putchar
#define rg register
using namespace std;
int n,m,b[30];
string x,p[M],fm,sm,o[M];
struct word{
	string ma,mi;
	int id;
}a[M];
bool cmp(word u,word v){return u.ma<v.ma;}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		put('1');
		return 0;
	}
	for(rg int i=1;i<=n;i++){
		cin>>x;
		a[i].id=i;
		for(rg int j=1;j<=26;j++) b[j]=0;
		for(rg int j=0;j<m;j++) b[x[j]-'a'+1]++;
		for(rg int j=1;j<=26;j++)
			for(rg int k=1;k<=b[j];k++)
				a[i].mi+=j+'a'-1;
		for(rg int j=26;j>=1;j--)
			for(rg int k=1;k<=b[j];k++)
				a[i].ma+=j+'a'-1;
		o[i]=a[i].mi;
	}
	sort(a+1,a+n+1,cmp);
	for(rg int i=1;i<=n;i++){
		if(i==a[1].id){
			if(o[i]<a[2].ma) put('1');
			else put('0');
		}
		else{
			if(o[i]<a[1].ma) put('1');
			else put('0');
		}
	}
	return 0;
}

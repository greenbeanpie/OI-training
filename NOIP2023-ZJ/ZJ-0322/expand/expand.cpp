#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int aa[1005],aaa[1005],bb[1005],bbb[1005];
void copp(){
	for(int i=1;i<=n;i++){
		aaa[i]=aa[i];
	}
	for(int i=1;i<=m;i++){
		bbb[i]=bb[i];
	}
}
bool check(int a,int b,int c,int d){
	if(aaa[a]==bbb[b] || aaa[c]==bbb[d]) return false;
	if(aaa[a]>bbb[b] && aaa[c]<bbb[d])
		return false;
	if(aaa[a]<bbb[b] && aaa[c]>bbb[d])
		return false;
	
	return true;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=m;i++){
		cin>>bb[i];
	}
	copp();
	putchar(check(1,1,n,m)?'1':'0');
	for(int i=1;i<=q;i++){
		copp();
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			int p,v;
			cin>>p>>v;
			aaa[p]=v;
		}
		for(int j=1;j<=ky;j++){
			int p,v;
			cin>>p>>v;
			bbb[p]=v;
		}
		putchar(check(1,1,n,m)?'1':'0');
	}
	putchar('\n');
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
struct N{
	int ind=0;
	char a[3005];
	friend bool operator <(N x1,N x2){
		if(x2.ind==-1) return true;
		if(x1.ind==-1) return false;
		for(int i=0;i<m;i++){
			if(x1.a[i]>x2.a[i]){
				return false;
			}else{
				if(x1.a[i]<x2.a[i]){
					return true;
				}	
			}
		}
		return false;
	}
}zu[3005],zu2[3005];
bool cmp(char a,char b){
	return a>b;
}
N mi1,mi2;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",zu[i].a);
		for(int j=0;j<=m;j++){
			zu2[i].a[j]=zu[i].a[j];	
		}
		zu2[i].ind=i;
		sort(zu[i].a,zu[i].a+m);
		sort(zu2[i].a,zu2[i].a+m,cmp);
	}
	mi1.ind=-1,mi2.ind=-1;
	for(int i=1;i<=n;i++){
		if(zu2[i]<mi1){
			mi1=zu2[i];
		}else{
			if(zu2[i]<mi2){
				mi2=zu2[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		if(mi1.ind!=i && mi1.ind!=-1){
			flag=(zu[i]<mi1);
		}else{
			if(mi2.ind!=i && mi2.ind!=-1)
				flag=(zu[i]<mi2);
		}
		putchar((flag?'1':'0'));
	}
	putchar('\n');
	return 0;
}
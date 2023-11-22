#include<bits/stdc++.h>
#define R read()
//#pragma GCC optimize("Ofast")
using namespace std;

int n,m,i,j;
string a[3010],c[3010],x,y;

int read(){
	int x=0,fl=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')fl=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*fl;
}

int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=R;m=R;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sort(a[i].begin(),a[i].end());
		c[i]=a[i];
		for(j=0;j<m;j++)c[i][j]=a[i][m-1-j];
//		cout<<a[i]<<"\n"<<c[i]<<"\n";
	}
//	string x=a[1],y=c[2];
//		cout<<x<<" "<<y<<"\n";
//		cout<<(x>y)<<" "<<"\n";
	for(i=1;i<=n;i++){
		x=a[i];
		for(j=1;j<=n;j++){
			y=c[j];
			if(i!=j&&y<x)break;
		}
		if(j<=n)cout<<0;
		else cout<<1;
	}
	return 0;
}
//aadddss
//syz

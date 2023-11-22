#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int x,y,t;
int c,n,m,q;
int a[N],b[N],u1[N],u2[N],v1[N],v2[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int j=1;j<=m;++j) cin>>b[j];
	if((a[1]-b[1])*(a[n]-b[m])<=0){
		putchar('0');
	}else{
		if(n<=2&&m<=2){putchar('1');
		}else{
		bool flag=true;
		int i=1,j=1;
		if(a[1]<b[1]){
			i=2;
			for(;i<=n&&j<=m;){
				while(i<=n&&a[i]<b[j]) ++i;
				++j;
			}
			if(j>m&&i<n){flag=false;}else{
			for(;j<=m;++j) if(b[j]<a[n]){flag=false;break;}}
		}else{
			j=2;
			for(;i<=n&&j<=m;++j){
				while(j<=m&&b[j]<a[i]) ++j;
				++i;
			}
			if(i>n&&j<m){flag=false;}else{
				for(;i<=n;++i) if(a[i]<b[n]){flag=false;break;}
			}
		}
		if(flag) putchar('1');else putchar('0');
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=x;++i){
			cin>>u1[i]>>t;
			v1[i]=a[u1[i]];
			a[u1[i]]=t;
		}
		for(int i=1;i<=y;++i){
			cin>>u2[i]>>t;
			v2[i]=b[u2[i]];
			b[u2[i]]=t;
		}
		
	if((a[1]-b[1])*(a[n]-b[m])<=0){
		putchar('0');
	}else{
		if(n<=2&&m<=2){
			putchar('1');
		}else{
		bool flag=true;
		int i=1,j=1;
		if(a[1]<b[1]){
			i=2;
			for(;i<=n&&j<=m;){
				while(i<=n&&a[i]<b[j]) ++i;
				++j;
			}
			if(j>m&&i<n){flag=false;}else{
			for(;j<=m;++j) if(b[j]<a[n]){flag=false;break;}}
		}else{
			j=2;
			for(;i<=n&&j<=m;++j){
				while(j<=m&&b[j]<a[i]) ++j;
				++i;
			}
			if(i>n&&j<m){flag=false;}else{
				for(;i<=n;++i) if(a[i]<b[n]){flag=false;break;}
			}
		}
		if(flag) putchar('1');else putchar('0');
		}
	}
		for(int i=1;i<=x;++i) a[u1[i]]=v1[i];
		for(int i=1;i<=y;++i) b[u2[i]]=v2[i];
	}
	return 0;
}
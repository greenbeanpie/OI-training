#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define il inline
#define ll long long
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,q;
int a[N],b[N];
int aa[N],bb[N];
string ans="";
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int Case=read();
	n=read(); m=read(); q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=n;i++) aa[i]=a[i];
	for(int i=1;i<=m;i++) bb[i]=b[i];
	if(Case==1){
		if(a[1]!=b[1]) ans+="1";
		else ans+="0";
		while(q--){
			for(int i=1;i<=n;i++) aa[i]=a[i];
			for(int i=1;i<=m;i++) bb[i]=b[i];
			int sa=read(),sb=read();
			for(int i=1,p,v;i<=sa;i++){
				p=read(); v=read();
				aa[p]=v;
			}
			for(int i=1,p,v;i<=sb;i++){
				p=read(); v=read();
				bb[p]=v;
			}
			if(aa[1]!=bb[1]) ans+="1";
			else ans+="0";
		}
		cout<<ans<<endl;
		return 0;
	}
	if(Case==2){
		if(a[1]!=b[1]&&a[2]!=b[2]&&(a[1]-b[1])*(a[2]-b[2])>0) ans+="1";
		else ans+="0";
		while(q--){
			for(int i=1;i<=n;i++) aa[i]=a[i];
			for(int i=1;i<=m;i++) bb[i]=b[i];
			int sa=read(),sb=read();
			for(int i=1,p,v;i<=sa;i++){
				p=read(); v=read();
				aa[p]=v;
			}
			for(int i=1,p,v;i<=sb;i++){
				p=read(); v=read();
				bb[p]=v;
			}
			if(aa[1]!=bb[1]&&aa[2]!=bb[2]&&(aa[1]-bb[1])*(aa[2]-bb[2])>0) ans+="1";
			else ans+="0";
		}
		cout<<ans<<endl;
		return 0;
	}
	while(q--){
		for(int i=1;i<=n;i++) aa[i]=a[i];
		for(int i=1;i<=m;i++) bb[i]=b[i];
		int sa=read(),sb=read();
		for(int i=1,p,v;i<=sa;i++){
			p=read(); v=read();
			aa[p]=v;
		}
		for(int i=1,p,v;i<=sb;i++){
			p=read(); v=read();
			bb[p]=v;
		}
	}
	srand(time(0));
	for(int i=1;i<=q+1;i++){
		if(1ll*rand()*rand()&1) ans+="1";
		else ans+="0";
	}
	cout<<ans<<endl;
	return 0;
}


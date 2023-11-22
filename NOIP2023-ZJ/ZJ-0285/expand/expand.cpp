#include<bits/stdc++.h>
using namespace std;
int dian,n,m,T,i,fx,fy,x,y,a[500010],b[500010],cuna[500010],cunb[500010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>dian>>n>>m>>T;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)cin>>b[i];
	if(dian==1){
		if(a[1]==b[1])cout<<0;
		else cout<<1;
		while(T--){
			cin>>fx>>fy;
			for(i=1;i<=n;i++)cuna[i]=a[i];
			for(i=1;i<=m;i++)cunb[i]=b[i];
			for(i=1;i<=fx;i++)cin>>x>>y,a[x]=y;
			for(i=1;i<=fy;i++)cin>>x>>y,b[x]=y;
			if(a[1]==b[1])cout<<0;
			else cout<<1;
			for(i=1;i<=n;i++)a[i]=cuna[i];
			for(i=1;i<=m;i++)b[i]=cunb[i];
		}
		return 0;
	}
	if(a[1]==b[1]||a[n]==b[m])cout<<0;
	else if(a[1]<b[1]&&a[n]>b[m])cout<<0;
	else if(a[1]>b[1]&&a[n]<b[m])cout<<0;
	else cout<<1;
	while(T--){
		for(i=1;i<=n;i++)cuna[i]=a[i];
		for(i=1;i<=m;i++)cunb[i]=b[i];
		cin>>fx>>fy;
		for(i=1;i<=fx;i++)cin>>x>>y,a[x]=y;
		for(i=1;i<=fy;i++)cin>>x>>y,b[x]=y;
		if(a[1]==b[1]||a[n]==b[m])cout<<0;
		else if(a[1]<b[1]&&a[n]>b[m])cout<<0;
		else if(a[1]>b[1]&&a[n]<b[m])cout<<0;
		else cout<<1;
		for(i=1;i<=n;i++)a[i]=cuna[i];
		for(i=1;i<=m;i++)b[i]=cunb[i];
	}
	return 0;
}
/*
I love CCF
chu le t3 mei gei duo shao fen
qi ta ti bu fen fen dou hao duo!!!
*/
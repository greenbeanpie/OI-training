#include<bits/stdc++.h>
using namespace std;
int n,m;
struct str{
	string smin="";
	string smax="";
}s[3050];
char cmin[3050][3050],cmax[3050][3050];
bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(char a,char b){
	return a>b;
}
string ans="";
bool flag=true;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cmin[i][j];
			cmax[i][j]=cmin[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		sort(cmin[i]+1,cmin[i]+m+1,cmp1);
		sort(cmax[i]+1,cmax[i]+m+1,cmp2);
		for(int j=1;j<=m;j++){
			s[i].smin+=cmin[i][j];
			s[i].smax+=cmax[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		flag=true;
		for(int j=1;j<=i-1;j++){
			if(s[i].smin>s[j].smax)flag=false;
		}
		for(int j=i+1;j<=n;j++){
		if(s[i].smin>s[j].smax)flag=false;
		}
		if(flag)ans+="1";
		else ans+="0";
	}
	cout<<ans;
	return 0;
}

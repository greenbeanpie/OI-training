#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
string s[N];
char maxx[N],minn[N];
void init(){
	for(int i=1;i<=n;i++){
		maxx[i]='a';minn[i]='z';
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]>maxx[i])maxx[i]=s[i][j];
			if(s[i][j]<minn[i])minn[i]=s[i][j];
		}
	}
	bool f;
	if(n==1)return cout<<1,0;
	for(int i=1;i<=n;i++){
		f=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(minn[i]>=maxx[j]){
				f=0;break;
			}
		}
		cout<<f;
	}
	return 0;
}
//9:02

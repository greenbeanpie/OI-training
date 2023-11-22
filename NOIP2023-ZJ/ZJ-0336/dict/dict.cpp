#include<bits/stdc++.h>
using namespace std;
string s[4111],sx,minn;
int n,m,xx;
string ca(string x){
	string f="";
	int to[177];
	memset(to,0,sizeof(to));
	for(int i=0;i<m;i++)to[int(x[i]-'a'+1)]++;
	for(int i=1;i<=26;i++){
		for(int j=1;j<=to[i];j++){
			f+=char(i+'a'-1);
		}
	}
	return f;
}
string fa(string bx){
	string ff="";
	int tou[177];
	memset(tou,0,sizeof(tou));
	for(int i=0;i<m;i++)tou[int(bx[i]-'a'+1)]++;
	for(int i=26;i>=1;i--){
		for(int j=1;j<=tou[i];j++){
			ff+=char(i+'a'-1);
		}
	}
	return ff;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) s[i]=fa(s[i]);
	minn=s[1];xx=1;
	for(int i=2;i<=n;i++)
		if(s[i]<minn)minn=s[i],xx=i;
	for(int i=1;i<=n;i++){
		if(i==xx){
			cout<<1;continue;
		}
		sx=ca(s[i]);
		if(sx<minn)cout<<1;
		else cout<<0;
	}
}

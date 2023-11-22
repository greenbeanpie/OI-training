#include<bits/stdc++.h>
using namespace std;
int n,m,c,l,flag,si[3005],sx[3005];
string s;
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		si[i]=0x7f7f7f7f;
		cin>>s;l=s.length();
		for(int j=0;j<l;j++){
			c=s[j]-'a'+1;
			if(c<si[i])si[i]=c;
			if(c>sx[i])sx[i]=c;
		}
//		cout<<si[i]<<" "<<sx[i]<<"\n";
	}
	for(int i=1;i<=n;i++){
		flag=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(si[i]>=sx[j]){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}

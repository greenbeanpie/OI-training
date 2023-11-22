#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int>pii;
const int N=3e4+10;
int i,j,m,n;
pii s[N],s2[N];
string a,t;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>t;
//		cout<<t<<endl;
		sort(t.begin(),t.end());
		s[i]={t,i};
		string temp="";
		for(j=m-1;j>=0;j--){
			temp+=t[j];
		}
		s2[i]={temp,i};
//		cout<<s2[i]<<endl;
	}
	sort(s2+1,s2+1+n);
//	for(i=1;i<=n;i++) cout<<s[i].first<<" "<<s2[i].first<<endl;
//	puts("");
//	puts("");
	if(m==1){
		string mins="z";
		for(i=1;i<=n;i++){
			if(s[i].first<mins) mins=s[i].first;
		}
		for(i=1;i<=n;i++){
			if(s[i].first==mins) cout<<"1";
			else cout<<"0";
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		bool flag=1;
		for(j=1;j<=n;j++){
			if(s[i].second==s2[j].second) continue;
			if(s[i]>s2[j]) {
				flag=0;
				break;
			}
			else break;
		}
		if(flag) cout<<"1";
		else cout<<"0";
	}
	
	
	return 0;
}

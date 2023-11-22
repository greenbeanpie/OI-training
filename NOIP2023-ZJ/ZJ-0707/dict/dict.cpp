#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char chr[3005][3005];
int cnt[3005][30];
string minn[3005],maxx[3005];
void init(){
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	   	    cnt[i][chr[i][j]-'a'+1]++;
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++)
			for(int k=1;k<=cnt[i][j];k++) minn[i]+=char(j+'a'-1);
		for(int j=26;j>=1;j--)
		    for(int k=1;k<=cnt[i][j];k++) maxx[i]+=char(j+'a'-1);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>chr[i]+1;
	if(m==1){
		char c=chr[1][1];
		for(int i=2;i<=n;i++) if(chr[i][1]<c) c=chr[i][1];
		for(int i=1;i<=n;i++) if(chr[i][1]==c) cout<<1; else cout<<0;
		return 0;
	}
    init(); solve();
    for(int i=1;i<=n;i++){
    	bool flag=true;
    	for(int j=1;j<=n;j++){
    		if(i==j) continue;
    		if(minn[i]>maxx[j]) flag=false;
		}
		if(flag) cout<<1;
		else cout<<0;
	}
	return 0;
}

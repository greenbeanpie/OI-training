#include <bits/stdc++.h>
using namespace std;
#define maxn 3030
int n,m;
int yue[maxn][40];
char s[maxn][maxn];
int q[maxn][40];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		int dx=0,minn=9999,maxx=0;
		for(int j=0; j<m; j++) {
			if(s[i][j]-'a'+1==minn)
				q[i][1]++;
			if(s[i][j]-'a'+1<minn) {
				q[i][1]=1;
				minn=s[i][j]-'a'+1;
				yue[i][1]=s[i][j]-'a'+1;
			}
			if(s[i][j]-'a'+1==maxx)
				q[i][2]++;
			if(s[i][j]-'a'+1>maxx) {
				q[i][2]=1;
				maxx=s[i][j]-'a'+1;
				yue[i][2]=s[i][j]-'a'+1;
			}
		}
	}
	if(n==1) {
		cout<<1;
		return 0;
	}
	if(m==1) {
		int h,cnt[40];
		memset(cnt,0,sizeof(cnt));
		h=1;
		for(int i=2; i<=n; i++) {
			if(s[i]==s[h])cnt[h]=1;
			if(s[i]<s[h])h=i;
		}
		for(int i=1; i<=n; i++) {
			if(i==h && !cnt[h])cout<<1;
			else cout<<0;
		}
		return 0;
	}
	for(int k=1; k<=n; k++) {
		//cout<<k<<' '<<q[k][2]<<endl;
		int ans=1;
		for(int i=1; i<=n; i++) {
			if(i==k)continue;
			if((yue[k][1]==yue[i][2] && q[k][1]>=q[i][2]) || (yue[k][1]>yue[i][2])) {
				ans=0;
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}

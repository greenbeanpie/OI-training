#include<bits/stdc++.h>
#define int long long
#define s1 first
#define id second
using namespace std;

const int N=3e3+10;

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int n,m;
char s[N][N];
int cnt[N][27];

//string s1[N],s2[N]
pair<string,int> a[N],b[N];
//struct str {
//	string s1;
//	int id;
//}a[N],b[N];

//bool operator < (const string s1,const string s2) {
//	for(int i=0;i<m;i++) {
//		if(s1[i]>s2[i]) return false;
//	}
//	return true;
//}
//
//bool operator == (const string s1,const string s2) {
//	for(int i=0;i<m;i++) {
//		if(s1[i]!=s2[i]) return false;
//	}
//	return true;
//}
//
//bool cmp(str x,str y) {
//	if(x.s1==y.s1) return x.id<y.id;
//	return x.s1<y.s1;
//}
bool ans[N];

signed main() {
	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();

	for(int i=1;i<=n;i++) {
		cin>>(s[i]+1);
		for(int j=1;j<=m;j++) {
			cnt[i][s[i][j]-'a']++;
		}
		a[i].s1="",b[i].s1="";
		a[i].id=i;
		b[i].id=i;
		for(int j=0;j<=25;j++) {
			for(int k=1;k<=cnt[i][j];k++) {
				a[i].s1+='a'+j;
			}
			for(int k=1;k<=cnt[i][25-j];k++) {
				b[i].s1+='a'+25-j;
			}
		}
//		ans[i]=1;
	}

	sort(a+1,a+n+1);
	sort(b+1,b+n+1);

	for(int i=1;i<=n;i++) {
		if(a[i].s1<=b[1].s1) ans[a[i].id]=1;
	}
	
	for(int i=1;i<=n;i++) {
		if(ans[i]) printf("1");
		else printf("0");
	}

	return 0;
}


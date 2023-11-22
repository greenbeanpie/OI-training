#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R read()
#define pc putchar
#define pb push_back
#define MT int TTT=R;while(TTT--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
inline int read()
{
	int x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') flag=1;ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(flag) return -x;
	return x;
}
template<typename T> inline void write(T x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+'0');
}
const int N=3010;
int n,m;
pair<string,int> s[N];
string tmp;
int ans[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fo(i,1,n) cin>>s[i].first,s[i].second=i;
	fo(i,1,n) sort(s[i].first.begin(),s[i].first.end(),greater<char>());
	sort(s+1,s+n+1);
	fo(i,1,n)
	{
		tmp=s[i].first;
		sort(tmp.begin(),tmp.end());
//		cout<<s[i].second<<endl;
		if(tmp<s[1].first||(m==1&&tmp==s[1].first)) ans[s[i].second]=1;
		else ans[s[i].second]=0;
//		if(s[i].second==437) cout<<tmp<<' '<<s[1].first<<' '<<ans[437]<<endl;
	}
	fo(i,1,n) write(ans[i]);
}
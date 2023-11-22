#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=3003;
int vis[N],n,m;
string st[N];
struct qwq{
	string minn,maxn;
	int num;
}s[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>st[i];
	}
	for (int i=1;i<=n;i++) {
		s[i].num=i;
		for (int j=0;j<26;j++) vis[j]=0;
		for (int j=0;j<m;j++) {
			int t=st[i][j]-97;
			vis[t]++;
		}
		for (int j=0;j<26;j++) {
			char ch=(char)(j+97);
			for (int k=1;k<=vis[j];k++) {
				s[i].minn+=ch;
			}
		}
		for (int j=25;j>=0;j--) {
			char ch=(char)(j+97);
			for (int k=1;k<=vis[j];k++) {
				s[i].maxn+=ch;
			}
		}
	}
/*
	for (int i=1;i<=n;i++) {
		cout<<"i="<<i<<" minn="<<s[i].minn<<" maxn="<<s[i].maxn<<endl;
	}
*/	
	for (int i=1;i<=n;i++) {
		bool tf=1;
		for (int j=1;j<=n;j++) {
			if (i!=j&&s[i].minn>=s[j].maxn) {
		//		cout<<"i="<<i<<" minn="<<s[i].minn<<" j="<<j<<" maxn="<<s[j].maxn<<endl;
				tf=0; break;
			}
		}
		if (tf) cout<<1;
			else cout<<0;
	}
	return 0;
}

/*
4 7
abandon
bananaa
baannaa
notnotn

1110


23 1
x
w
y
l
n
e
j
d
o
t
u
z
s
b
k
h
q
f
g
i
v
c
r

00000000000001000000000


15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql
zi
yv
md
ji
oc

000101010000101



*/


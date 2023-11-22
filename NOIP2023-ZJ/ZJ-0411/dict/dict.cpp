#include<bits/stdc++.h>
using namespace std;
inline bool _u(char x){return x>='0'&&x<='9';}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;!_u(ch);ch=='-'&&(f=-1),ch=getchar());
	for(;_u(ch);x=x*10+(ch^48),ch=getchar());
	return x*f;
}
inline void write(int num,bool flag=0){
	static int st[39],tp=0;
	num<0&&(putchar('-'),num=-num);
	do st[++tp]=num%10;while(num/=10);
	while(tp)putchar(st[tp--]|48);
	putchar(flag?'\n':' ');
	return;
}
template<typename...Args>
inline void write(int t,Args...args){
	return write(t),write(args...);
}
const int N=3010;
int n,m;
char a[N][N];
string l[N],r[N];
int cnt[27];
struct node{
	string x;
	int id;
	friend bool operator>(node x,node y){
		return x.x>y.x;
	}
}mx[2];

signed main(){
	freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>l[i];
		sort(l[i].begin(),l[i].end());
		r[i]=l[i];
		reverse(r[i].begin(),r[i].end());
		node fyn;
		fyn.x=r[i],fyn.id=i;
		for(int j=0;j<2;++j)
			if(!mx[j].id||fyn.x<mx[j].x) swap(mx[j],fyn);
	}
	for(int i=1;i<=n;++i){
		bool flag=0;
		if(mx[0].id!=i&&mx[0].x<=l[i]) flag=true;
		if(mx[0].id==i&&mx[1].x<=l[i]) flag=true;
		if(flag)putchar('0');
		else putchar('1');
	}
	
	return (39-39);
}
/*
4 3
aba
ban
baa
not
*/

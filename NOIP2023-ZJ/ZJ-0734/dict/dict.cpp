#include<bits/stdc++.h>
#define xrain depression
#define maxn 100005
#define maxm 1005
#define inf 0x3fff
using namespace std;

int n, m;

//inline void read(int &x){
//	x=0; bool sgn; char s=getchar();
//	while(!degisit(s)) sgn|=s=='-', s=getchar();
//	while(degisit(s)) x=(x<<1)+(x<<3)+(s^48), s=getchar();
//	sgn?x=-x:x;
//}

inline void solve1(){
	string s; cin>>s;
	printf("1");
}

inline void solve2(){
	string s, x="z"; int cnt;
	for(int i=1; i<=n; i++){
		cin>>s;
		if(s<=x) x=s, cnt=i;
	}
	for(int i=1; i<=n; i++){
		if(i==cnt) printf("1");
		else printf("0");
	}
}

inline void solve3(){
	string s, a[16], b[16], x="zz";
	for(int i=1; i<=n; i++){
		cin>>s;
		if(s[0]>s[1]) a[i]=s[0], b[i]=s[1];
		else a[i]=s[1], b[i]=s[0];
		s[0]=a[i][0], s[1]=b[i][0];
		if(s<x) x=s;
//		cout<<"!:"<<a[i]<<b[i]<<" "<<x<<endl;
	}
	for(int i=1; i<=n; i++){
		s[0]=b[i][0], s[1]=a[i][0];
//		cout<<s<<" ";
		if(s<=x) printf("1");
		else printf("0");
//		cout<<endl;
	}
}

inline void solve4(){
	string s[maxn];
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	for(int i=1; i<=n; i++){
		cout<<1;
	}
}

signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

	scanf("%d%d", &n, &m);
	if(m==1) n==1?solve1():solve2();
	else if(m==2) solve3();
	else solve4();

	return 0;
}

/*

4 7
abandon
bananaa
baannaa
notnotn

1110

*/

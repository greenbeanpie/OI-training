#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define mst(a,b) memset(a,b,sizeof(a))
#define kp(a,b) make_pair(a,b)
#define fi first
#define se second
inline int read() {
	int x=0;
	bool f=true;
	char c=getchar();
	for(; !isdigit(c); c=getchar())if(c=='-')f=false;
	for(; isdigit(c); c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return f?x:(~(x-1));
}
const int N=3000+100;
int n,m;
string s[N],f,g;
int pos,t[N][30];
string get(int i,bool u){ // O(m)
	string res=" ";
	if(u){
		for(int j=25;j>=0;j--){
			for(int k=1;k<=t[i][j];k++){
				res+=(char)('a'+j);
			}
		}
	}else{
		for(int j=0;j<=25;j++){
			for(int k=1;k<=t[i][j];k++){
				res+=(char)('a'+j);
			}
		}
	}
	return res;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();         
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=" "+s[i];
	}
	if(n==1){
		putchar('1');
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[i][s[i][j]-'a']++;
		}
	}
	for(int i=1;i<=n;i++){
		string tmp=get(i,1);
		if(i==1){
			f=tmp;
			pos=1;
		}else{
			if(tmp<f){
				g=f;
				f=tmp;
				pos=i;
			}else if(tmp<g){
				g=tmp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		string tmp=get(i,0);
		if(pos==i){
			putchar('0'+(tmp<g));
		}else{
			putchar('0'+(tmp<f));
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define fq(i,l,r) for(int i=(l);i<=(r);i++)
#define ffq(i,r,l) for(int i=(r);i>=(l);i--)
const int N=3007;
int n,m;
char w[N][N],sm[N][N],bi[N][N];
int t[30],rt;
bool fg;
namespace trie{
	int cnt=0;
	struct A{int son[27],f,e;} a[N*100];
	void insert(int &p,int wh,int i){
		if(!p) p=++cnt;
		a[p].f++;
		if(i==m) return (void)(a[p].e++);
		int num=bi[wh][i]-'a',cnt=0;
		fq(j,0,num-1) if(a[p].son[j]) cnt+=a[a[p].son[j]].f;
		if(cnt>=2) return ;
		insert(a[p].son[bi[wh][i]-'a'],wh,i+1);
	}
	void update(int p,int wh,int ad,int i){
		a[p].f+=ad;
		if(i==m) return ;
		update(a[p].son[bi[wh][i]-'a'],wh,ad,i+1);
	}
	void query(int p,int wh,int i){
		if(i==m) return ;
		int num=sm[wh][i]-'a',cnt=0;
		fq(i,0,num-1) cnt+=(a[p].son[i]&&a[a[p].son[i]].f);
		if(cnt) return (void)(fg=1);
		else query(a[p].son[num],wh,i+1);
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);	
	cin>>n>>m;
	fq(i,1,n) cin>>w[i];
	fq(i,1,n){
		fq(u,0,m-1) t[w[i][u]-'a']++;
		int l=0;
		fq(k,0,25) fq(j,1,t[k]) sm[i][l++]=(char)('a'+k);
		l=0;
		ffq(k,25,0) fq(j,1,t[k]) bi[i][l++]+=(char)('a'+k);
		trie::insert(rt,i,0);
		memset(t,0,sizeof(t));
	}
	fq(i,1,n){
		trie::update(rt,i,-1,0);
		trie::query(rt,i,0);
		if(fg) printf("0");
		else printf("1");
		fg=0,trie::update(rt,i,1,0);
	}
	return 0;
}
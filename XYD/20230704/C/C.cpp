#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")
#pragma GCC optimize(                                                       \
    3, "Ofast", "inline", "-fgcse", "-fgcse-lm", "-fipa-sra", "-ftree-pre", \
    "-ftree-vrp", "-fpeephole2", "-ffast-math", "-fsched-spec",             \
    "unroll-loops", "-falign-jumps", "-falign-loops", "-falign-labels",     \
    "-fdevirtualize", "-fcaller-saves", "-fcrossjumping", "-fthread-jumps", \
    "-funroll-loops", "-freorder-blocks", "-fschedule-insns",               \
    "inline-functions", "-ftree-tail-merge", "-fschedule-insns2",           \
    "-fstrict-aliasing", "-falign-functions", "-fcse-follow-jumps",         \
    "-fsched-interblock", "-fpartial-inlining", "no-stack-protector",       \
    "-freorder-functions", "-findirect-inlining", "-fhoist-adjacent-loads", \
    "-frerun-cse-after-loop", "inline-small-functions",                     \
    "-finline-small-functions", "-ftree-switch-conversion",                 \
    "-foptimize-sibling-calls", "-fexpensive-optimizations",                \
    "inline-functions-called-once", "-fdelete-null-pointer-checks")

#define int long long
#define Pii pair<int,int>
bool g[200005];
vector<int> val;
struct node{
	int l,r,d;
};
bool operator<(node a,node b){
	if(a.d==b.d){
		return a.l<b.l;
	}
	return a.d<b.d;
}
int nxt[200005],prv[200005];
signed main(){
	#ifdef CODESPACE
		freopen("C.in","r",stdin);
		freopen("C.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	val.push_back(0);
	for(int i=0;i<str.size();i++){
		if(str[i]-'A'==1){
			g[i+1]=true;
		}
	}
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		val.push_back(t);
	}
	set<node> s;
	for(int i=1;i<n;i++){
		nxt[i]=i+1;
		prv[i+1]=i;
		if(g[i]!=g[i+1]){
			s.insert({i,i+1,abs(val[i]-val[i+1])});
		}
	}
	queue<pair<int,int> > q;
	while(s.size()){
		auto now=*s.begin();
		s.erase(s.begin());
		int s2=now.l,s3=now.r;
		q.push({s2,s3});
		if(prv[s2]&&g[prv[s2]]!=g[s2]){
			s.erase({prv[s2],s2,abs(val[s2]-val[prv[s2]])});
		}
		if(nxt[s3]&&g[s3]!=g[nxt[s3]]){
			s.erase({s3,nxt[s3],abs(val[nxt[s3]]-val[s3])});
			
		}
		if(prv[s2]&&nxt[s3]&&g[prv[s2]]^g[nxt[s3]]){
				s.insert({prv[s2],nxt[s3],abs(val[nxt[s3]]-val[prv[s2]])});
			}
		nxt[prv[s2]]=nxt[s3];
		prv[nxt[s3]]=prv[s2];
	}
	cout << q.size() << endl;
	while(q.size()){
		int a=q.front().first,b=q.front().second;
		cout << min(a,b) << " " <<  max(a,b)  << endl;
		q.pop();
	}
	return 0;
}
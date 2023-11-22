#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Dict {
	char word[3010];
	int turns;
	int rank;
} strs[9050],_strs[9050];
bool cmp(Dict a,Dict b) {
	for(int j=1; j<=m; j++) if(a.word[j]!=b.word[j]) return a.word[j]<b.word[j];
}
void find_extrems(int j) {
	int k=1;
	Dict &ch=_strs[j];
	_strs[n+j].turns=n+j;
	_strs[n*2+j].turns=n*2+j;
	//min
	while(ch.word[k]=='a') k++;
	int minn=-1,place=-1;
	for(int i=k+1; i<=m; i++) {
		minn=min(minn,ch.word[i]-ch.word[k]);
		if(ch.word[i]-ch.word[k]==minn) place=i;
	}
	if(place!=-1) swap(ch.word[k],ch.word[place]);
	for(int i=1; i<=m; i++) strs[n+j].word[i]=ch.word[i],_strs[n+j].word[i]=ch.word[i];
	//max
	k=1;
	place=-1;
	while(ch.word[k]=='z') k++;
	int maxn=1;
	for(int i=k+1; i<=m; i++) {
		maxn=max(maxn,ch.word[i]-ch.word[k]);
		if(ch.word[i]-ch.word[k]==maxn) place=i;
	}
	if(place!=-1) swap(ch.word[k],ch.word[place]);
	for(int i=1; i<=m; i++) strs[n*2+j].word[i]=ch.word[i],_strs[n*2+j].word[i]=ch.word[i];

	return;
}
bool solve(int k) {
	if(m==1) {
		if(strs[n].rank==1) return 1;
		return 0;
	}
	if(strs[n+k].rank==1) return 1;
	for(int i=1; i<strs[n+k].rank; i++) {
		if(_strs[i].turns>2*n) return 0;
	}
	return 1;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);
	if(n==1) {
		cout<<1;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		_strs[i].turns=i;
		for(int j=1; j<=m; j++) {
			_strs[i].word[j]=getchar();
			if(_strs[i].word[j]=='\n'||_strs[i].word[j]=='\r') _strs[i].word[j]=getchar();
			strs[i].word[j]=_strs[i].word[j];
		}
		if(m>1) find_extrems(i);
	}
	if(m>1) sort(_strs+1,_strs+3*n+1,cmp);
	else sort(_strs+1,_strs+n+1,cmp);
	if(m>1) for(int i=1; i<=3*n; i++) strs[_strs[i].turns].rank=i;
	else for(int i=1; i<=n; i++) strs[_strs[i].turns].rank=i;
	for(int i=1; i<=n; i++) cout<<(int)solve(i);
	return 0;
}

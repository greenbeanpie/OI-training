#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
string s[3005],mi="";
int main()
{
#ifndef LOCAL
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	mi+='z'+1;
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	cin>>s[x],sort(s[x].begin(),s[x].end()),reverse(s[x].begin(),s[x].end()),mi=min(mi,s[x]);
	for(int x=1;x<=n;x++)
	sort(s[x].begin(),s[x].end()),cout<<(s[x]<=mi);
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/

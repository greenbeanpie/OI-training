#include<bits/stdc++.h>
#define LL long long
#define push_back pb
#define mk make_pair
#define debug cout<<"------------------------\n";
#define fi first
#define se second
#define ls s*2
#define rs s*2+1
#define mid (l+r)/2
#define tol ls,l,mid
#define tor rs,mid+1,r
using namespace std;
int main(){
	freopen("dict4.ans","r",stdin);
	string s;
	int ans=0;
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]=='1') ++ans;
	cout<<ans;
	return 0;
}

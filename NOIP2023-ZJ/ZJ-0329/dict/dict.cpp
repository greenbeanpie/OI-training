#include<bits/stdc++.h>
using namespace std;
int n,m,A[3010],B[3010];
string s;
vector<int>v;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(A,0x3f,sizeof(A));
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			A[i]=min(A[i],s[j]-'a');
			B[i]=max(B[i],s[j]-'a');
		}
	}
	for(int i=1;i<=n;i++){
		int f=1;
		for(int j=1;j<=n;j++){
		    if(i==j)continue;
		    if(A[i]>=B[j])f=0;
	    }
	    v.push_back(f);
	}
	for(int i:v)cout<<i;
	return 0;
}
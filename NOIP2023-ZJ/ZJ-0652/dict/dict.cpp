#include<bits/stdc++.h>
using namespace std;
#define maxc(a,b) ((a)>(b)?(a):(b))
#define minc(a,b) ((a)<(b)?(a):(b))
int n,m;
char s[3003][2];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		s[i][0]='a';
		s[i][1]='z';
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			s[i][0]=maxc(c,s[i][0]);
			s[i][1]=minc(c,s[i][1]);
		}
	}
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		bool flag=1;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(s[i][1]>=s[j][0]){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	cout<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,mapp[N][30];
string q[N],line_shout[N],line_long[N],ans="";
bool f;

int main(){
	ios::sync_with_stdio(false);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>q[i];
		for(int j=0;j<q[i].length();j++){
			mapp[i][int(q[i][j])-96]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			for(int k=1;k<=mapp[i][j];k++){
				line_shout[i]+=char(j+96);
			}
		}
		for(int j=26;j>=1;j--){
			for(int k=1;k<=mapp[i][j];k++){
				line_long[i]+=char(j+96);
			}
		}
	}
	for(int i=1;i<=n;i++){
		f=true;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(line_shout[i]>=line_long[j]){
				f=false;
				break;
			}
		}
		if(f)ans+='1';
		else ans+='0';
	}
	cout<<ans;
	return 0;
}

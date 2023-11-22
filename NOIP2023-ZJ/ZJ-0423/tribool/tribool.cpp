#include<bits/stdc++.h>
#define fo(x,l,r) for (int x=(l); x<=(r); x++)
#define dw(x,r,l) for (int x=(r); x>=(l); x--)
using namespace std;
int c,T,n,m,tt,ans,t[100005],x[100005],op[100005][3];
char v[100005];
void dfs(int k){
	if (k>n){
		fo(i,1,n) t[i]=x[i];
		fo(i,1,m){
			if (v[i]!='+'&&v[i]!='-') t[op[i][1]]=v[i];
			else{
				if (v[i]=='+') t[op[i][1]]=t[op[i][2]];
				else{
					if (t[op[i][2]]=='F') t[op[i][1]]='T';
					else{
						if (t[op[i][2]]=='T') t[op[i][1]]='F';
						else t[op[i][1]]='U';
					}
				}
			}
		}
		fo(i,1,n) if (t[i]!=x[i]) return;
		tt=0;
		fo(i,1,n) if (x[i]=='U') tt++;
		ans=min(ans,tt);
//		if (3==tt){
//			cout<<"yuanshen";
//			fo(i,1,n) cout<<char(x[i]);
//			cout<<endl;
//			cout<<"qidong";
//			fo(i,1,n) cout<<char(t[i]);
//			cout<<endl;
//		}
		return;
	}
	x[k]='T';
	dfs(k+1);
	x[k]='F';
	dfs(k+1);
	x[k]='U';
	dfs(k+1);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	if (c==1||c==2){
		while (T--){
			cin>>n>>m;
			fo(i,1,m){
				cin>>v[i];
				if (v[i]!='+'&&v[i]!='-') cin>>op[i][1];
				else cin>>op[i][1]>>op[i][2];
			}
			ans=10;
			dfs(1);
			cout<<ans<<endl;
		}
	}
	if (c==3||c==4){
		while (T--){
			cin>>n>>m;
			fo(i,1,n) t[i]='X';
			fo(i,1,m){
				cin>>v[i]>>op[i][1];
				t[op[i][1]]=v[i];
			}
			ans=0;
			fo(i,1,n) if (t[i]=='U') ans++;
			cout<<ans<<endl;
		}
	}
	if (c==5||c==6){
		while (T--){
			cin>>n>>m;
			fo(i,1,n){
				t[i]='X';
				x[i]='X';
			}
			fo(i,1,m){
				cin>>v[i];
				if (v[i]=='+'){
					cin>>op[i][1]>>op[i][2];
					dw(j,i,1)
					if (v[j]=='+'){
						if (t[op[j][1]]=='U'&&t[op[j][2]]!='U')
						t[op[j][2]]=t[op[j][1]];
						else if (t[op[j][2]]=='U'&&t[op[j][1]]!='U'&&t[op[j][2]]!='U')
						t[op[j][1]]=t[op[j][2]];
					}
				}
				else{
					t[op[i][1]]='U';
					x[op[i][1]]='U';
					cin>>op[i][1];
				}
			}
//			fo(i,1,100) fo(i,1,m)
//			if (v[i]=='+'){
//				if (t[op[i][1]]=='U'&&t[op[i][2]]!='U')
//				t[op[i][2]]=t[op[i][1]];
//				else if (t[op[i][2]]=='U'&&t[op[i][1]]!='U'&&x[op[i][2]]!='U')
//				t[op[i][1]]=t[op[i][2]];
//			}
			ans=0;
			fo(i,1,n) if (t[i]=='U') ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}
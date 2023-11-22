#include<bits/stdc++.h>
using namespace std;
int C,n,m,q;
int a[500005],b[500005];
int maxa=-1,mina=-1;
int maxb=-1,minb=-1;
vector<int>ga[5005];
vector<int>gb[5005];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mina==-1||a[i]<mina){
			mina=a[i];
		}
		if(maxa==-1||a[i]>maxa){
			maxa=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(minb==-1||b[i]<minb){
			minb=b[i];
		}
		if(maxb==-1||b[i]>maxb){
			maxb=b[i];
		}
	}
	if(maxa>maxb&&mina<minb)cout<<"0";
	else if(maxb>maxa&&minb<mina)cout<<"0";
	else if(mina==minb||maxa==maxb)cout<<"0";
	else cout<<"1";
	while(q--){
		int xx,yy;
		cin>>xx>>yy;
		for(int i=1;i<=xx;i++){
			int t1,t2;
			cin>>t1>>t2;
			a[t1]=t2;
		}
		for(int i=1;i<=yy;i++){
			int t1,t2;
			cin>>t1>>t2;
			b[t1]=t2;
		}
		mina=-1,maxa=-1,minb=-1,maxb=-1;
		for(int i=1;i<=n;i++){
			if(mina==-1||a[i]<mina){
				mina=a[i];
			}
			if(maxa==-1||a[i]>maxa){
				maxa=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(minb==-1||b[i]<minb){
				minb=b[i];
			}
			if(maxb==-1||b[i]>maxb){
				maxb=b[i];
			}
		}
		if(maxa>maxb&&mina<minb)cout<<"0";
		else if(maxb>maxa&&minb<mina)cout<<"0";
		else if(mina==minb||maxa==maxb)cout<<"0";
		else cout<<"1";
	}
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/
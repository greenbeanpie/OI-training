#include<bits/stdc++.h>
#define fo(x,l,r) for (int x=(l); x<=(r); x++)
#define dw(x,r,l) for (int x=(r); x>=(l); x--)
using namespace std;
int n,m,cnt;
char s[3005];
int maxs[30],mins[30],a[3005][30],t[3005],wc[3005];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	fo(i,1,n){
		cin>>s+1;
		fo(j,1,m) a[i][int(s[j])-'a'+1]++;
	}
//	fo(i,1,n){
//		dw(j,26,1)
//		if (a[i][j]>maxs[j]){
//			dw(k,26,1) maxs[k]=a[i][k];
//			break;
//		}
//		else if (a[i][j]<maxs[j]) break;
//	}
//	fo(i,1,26) mins[i]=3005;
//	fo(i,1,n){
//		fo(j,1,26)
//		if (a[i][j]<mins[j]){
//			fo(k,1,26) mins[k]=a[i][k];
//			break;
//		}
//		else if (a[i][j]>mins[j]) break;
//	}
	fo(i,1,26) mins[i]=3005;
	fo(i,1,n){
		dw(j,26,1)
		if (a[i][j]<mins[j]){
			dw(k,26,1) mins[k]=a[i][k];
			break;
		}
		else if (a[i][j]>mins[j]) break;
	}
	cnt=0;
	dw(j,26,1){
		while (mins[j]){
			mins[j]--;
			cnt++;
			wc[cnt]=j;
		}
	}
//	fo(i,1,m) cout<<char(wc[i]+'a'-1);
//	cout<<endl;
	fo(i,1,n){
		fo(j,1,m) t[i]=0;
		cnt=0;
		fo(j,1,26){
			while (a[i][j]){
				a[i][j]--;
				cnt++;
				t[cnt]=j;
			}
		}
		bool f=0;
		fo(j,1,m)
		if (t[j]>wc[j]){
			f=1;
			cout<<"0";
			break;
		}
		else if (t[j]<wc[j]){
			f=1;
			cout<<"1";
			break;
		}
		if (!f) cout<<"1";
	}
	return 0;
}		
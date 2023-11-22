//#include<bits/stdc++.h>
//using namespace std;
//struct point{
//	int t[3005],xu,rea;
//	bool ism;//1--max,2--min
//};
//bool cmp1(int x,int y){
//	return x>y;
//}
//
//int n,m;
//int a[3005][3005];
//point mix[6005];
////point mx[3005];
//int mic[3005],mxc[3005];
//bool cmp2(point x,point y){
//	for(int i=1;i<=m;i++){
//		if(x.t[i]<y.t[i])return 1;
//		else if(x.t[i]>y.t[i])return 0;
//	}
//}
//bool ch(int x,int y){
//	for(int i=1;i<=m;i++){
//		if(mix[x].t[i]!=mix[y].t[i]){
//			return 0;
//		}
//	}
//	return 1;
//}
//int main(){
//	freopen("dict.in","r",stdin);
//	freopen("dict.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		mix[i].xu=i,mix[i+n].xu=i;
//		mix[i].ism=0,mix[i+n].ism=1;
//		for(int j=1;j<=m;j++){
//			char tmp;
//			cin>>tmp;
//			a[i][j]=tmp-'a'+1;
//			mix[i].t[j]=a[i][j],mix[i+n].t[j]=a[i][j];
//		}
//		sort(mix[i].t+1,mix[i].t+1+m);
//		sort(mix[i+n].t+1,mix[i+n].t+1+m,cmp1);
//	}
//	//cout<<"a\n";
//	sort(mix+1,mix+1+n+n,cmp2);
//	mix[1].rea=1;
//	for(int i=2;i<=n*2;i++){
//		if(ch(i,i-1)==1){
//			mix[i].rea=mix[i-1].rea;
//		}else{
//			mix[i].rea=mix[i-1].rea+1;
//		}
//	}
//	for(int i=1;i<=n*2;i++){
//		if(mix[i].ism==0){
//			mic[mix[i].xu]=mix[i].rea;
//		}else{
//			mxc[mix[i].xu]=mix[i].rea;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		bool flag=1;
//		for(int j=1;j<=n;j++){
//			if(j==i)continue;
//			if(mic[i]>=mxc[j]){
//				flag=0;
//				break;
//			}
//		}
//		cout<<(int)flag;
//	}
//	cout<<"\n";
//	return 0;
//}
///*
//4 7
//abandon
//bananaa
//baannaa
//notnotn
//*/
#include<bits/stdc++.h>
using namespace std;
struct point{
	int t[3005],xu,rea;
	bool ism;//1--max,0--min
};
bool cmp1(int x,int y){
	return x>y;
}
int n,m;
int a[3005][3005];
point mix[6005];
//point mx[3005];
int mic[3005],mxc[3005];
bool cmp2(point x,point y){
	if(x.ism==y.ism){
		if(x.ism==0){
			for(int i=1;i<=26;i++){
				if(x.t[i]<y.t[i])return 0;
				else if(x.t[i]>y.t[i])return 1;
			}
		}else{
			for(int i=26;i>=1;i--){
				if(x.t[i]<y.t[i])return 1;
				else if(x.t[i]>y.t[i])return 0;
			}
		}
	}else{
		if(x.ism==0){
			int mis,mxe;
			for(int i=1;i<=26;i++){
				if(x.t[i]!=0){
					mis=i;
					break;
				}
			}
			for(int i=26;i>=1;i--){
				if(y.t[i]!=0){
					mxe=i;
					break;
				}
			}
			if(mxe>mis)return 1;
			else return 0;
		}else{
			int mis,mxe;
			for(int i=1;i<=26;i++){
				if(y.t[i]!=0){
					mis=i;
					break;
				}
			}
			for(int i=26;i>=1;i--){
				if(x.t[i]!=0){
					mxe=i;
					break;
				}
			}
			if(mxe>mis)return 0;
			else return 1;
		}
	}
	return 0;
}
bool ch(int x,int y){
	if(mix[x].ism==mix[y].ism){
		for(int i=1;i<=26;i++){
			if(mix[x].t[i]!=mix[y].t[i]){
				return 0;
			}
		}
		return 1;
	}else{
		int cntx=0,cnty=0;
		int xux=-1,xuy=-1;
		for(int i=1;i<=26;i++){
			if(mix[x].t[i]!=0)cntx++,xux=i;
			if(mix[y].t[i]!=0)cnty++,xuy=i;
		}
		if(cntx==1&&cnty==1&&xux==xuy)return 1;
		return 0;
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	memset(mix,0,sizeof(mix));
	for(int i=1;i<=n;i++){
		mix[i].xu=i,mix[i+n].xu=i;
		mix[i].ism=0,mix[i+n].ism=1;
		for(int j=1;j<=m;j++){
			char tmp;
			cin>>tmp;
			a[i][j]=tmp-'a'+1;
			mix[i].t[a[i][j]]++,mix[i+n].t[a[i][j]]++;
		}
//		sort(mix[i].t+1,mix[i].t+1+m);
//		sort(mix[i+n].t+1,mix[i+n].t+1+m,cmp1);
	}
	//cout<<"a\n";
	sort(mix+1,mix+1+n+n,cmp2);
	mix[1].rea=1;
	for(int i=2;i<=n*2;i++){
		if(ch(i,i-1)==1){
			mix[i].rea=mix[i-1].rea;
		}else{
			mix[i].rea=mix[i-1].rea+1;
		}
	}
	for(int i=1;i<=n*2;i++){
		if(mix[i].ism==0){
			mic[mix[i].xu]=mix[i].rea;
		}else{
			mxc[mix[i].xu]=mix[i].rea;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<mic[i]<<" / "<<mxc[i]<<"\n";
//	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(mic[i]>=mxc[j]){
				flag=0;
				break;
			}
		}
		cout<<(int)flag;
	}
	cout<<"\n";
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
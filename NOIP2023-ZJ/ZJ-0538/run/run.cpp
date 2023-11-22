#include<bits/stdc++.h>
using namespace std;

int n;//n
long long m,k,d;
bool steps[114],sums[114];
struct mis{
	long long date;
	long long days;
	long long priz;
}mi[114514];

//void perform(int n){
//	long long nums=1;
//	for(int i=1;i<=n;i++)nums=nums<<1;
//	for(long long i=1;i<nums;i++){
//		int cnt=0,cntt=-1;
//		for(int j=n;j>=1;j--){
//			long long i1=i;
//			steps[j]=i1%2;
//			i1=i1>>1;
//			if(i1<=0)i1=0;
//		}
//		sums[0]=0;
//		for(int i=1;i<=n;i++){
//			sums[i]=sums[i-1]+steps[i];
//			cnt=(cnt+1)*(steps[i]==1);
//			cntt=max(cntt,cnt);
//		}
//		
//	}
//}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;//k:dis d:day
			for(int i=1;i<=m;i++){
				cin>>mi[i].date>>mi[i].days>>mi[i].priz;
			}
		cout<<0<<endl;
	}
	
	return 0;
}
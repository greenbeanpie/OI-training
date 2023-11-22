#include<bits/stdc++.h>
using namespace std;

int a[3030][3030],n,m;
int cur1[3030],cur2[3030];
int min1[3030],cnt1;
int min2[3030],cnt2;

int tong[10010];


inline int read(){
	int x=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*k;
}

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		min1[i]=114514;
		min2[i]=114514;
	}
	for(int i=1;i<=1000;i++)
		tong[i]=0;
	for(int i=1;i<=n;i++){
		string s; cin>>s;
//		cout<<"#: "<<s<<"\n";
		for(int j=1;j<=m;j++){
			cur1[j]=s[j-1]-'a'+1;
			a[i][j]=cur1[j];
			cur2[j]=cur1[j];
			tong[cur1[j]]+=1;
		}
		int px=0;
		for(int j=1;j<=1000;j++){
			while(tong[j]>0){
				cur1[++px]=j;
				tong[j]--;
//				cout<<px<<"  "<<j<<endl;
			}
		}
//		sort(cur1+1,cur1+m+1,cmp);
		bool f=0;int minn,ct1,ct2;
		for(int j=1;j<=m;j++){
			if(a[i][j]!=cur1[j]){
				minn=cur1[j]; f=1;
				ct1=j;  break;
			}
		}
		if(f)for(int j=m;j>=1;j--){
			if(a[i][j]==minn){
				ct2=j;
				break;
			}
		}
		int tt=a[i][ct1];
		a[i][ct1]=a[i][ct2];
		a[i][ct2]=tt;
//		得到最小序列 
		
//		for(int j=1;j<=m;j++)
//			cur2[j]=cur1[m+1-j];
		
		int maxx,ct3,ct4;f=0;
		for(int j=1;j<=m;j++){
			if(cur1[m+1-j]>cur2[j]){
				maxx=cur1[m+1-j];f=1;
				ct3=j;  break;
			}
		}	
		if(f)for(int j=m;j>=1;j--){
			if(cur2[j]==maxx){
				ct4=j;
				break;
			}
		}
		tt=cur2[ct3];
		cur2[ct3]=cur2[ct4];
		cur2[ct4]=tt;
		
//		最大序列 
			
		int flag1=0,flag2=0;
		for(int j=1;j<=m;j++){
			if(cur2[j]<min1[j]){
				flag1=1;
				break;
			}
			if(cur2[j]>min1[j])
				break;
		}
		if(flag1){
			for(int j=1;j<=m;j++){
				min2[j]=min1[j],cnt2=cnt1;
				min1[j]=cur2[j],cnt1=i;
			}
			continue;
		}
		for(int j=1;j<=m;j++){
			if(cur2[j]<min2[j]){
				flag2=1;
				break;
			}
			if(a[i][j]>min2[j])
				break;
		}
		if(flag2){
			for(int j=1;j<=m;j++){
				min2[j]=cur2[j];
				cnt2=i;
			}
		}
//		找到最小的 最大序列； 
	}
	
//	cout<<"# minn : "<<cnt1<<"\n";
//	for(int i=1;i<=m;i++){
//		cout<<min1[i]<<" ";
//	}
//	cout<<"\n";
	
	for(int i=1;i<=n;i++){
		bool flag=0;
		if(i==cnt1){
			for(int j=1;j<=m;j++){
				if(a[i][j]<min2[j]){
					flag=1;	break;
				}
				if(a[i][j]>min2[j]){
					flag=0; break;
				}
			}
			if(flag) printf("1");
			else printf("0");
//			cout<<"  $: ";
//			for(int j=1;j<=m;j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
			continue;
		}
		for(int j=1;j<=m;j++){
			if(a[i][j]<min1[j]){
				flag=1;	break;
			}
			if(a[i][j]>min1[j]){
				flag=0; break;
			}
		}
		if(flag) printf("1");
		else printf("0");
//		cout<<"  $: ";
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
	} 
	return 0;
}






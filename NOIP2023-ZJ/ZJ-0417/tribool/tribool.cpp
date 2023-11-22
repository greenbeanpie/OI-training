#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int c,t;
int a[N],b[N];//a:equal to Xother  f:+-  b:U or T or F
//equal to other ,so B is not sure ,B=0
int n,m;
bool f[N];
//T=100  U=-1  F=50
//fan 0  zheng 1
int mm[N];
int eq(int x1,int x2,int t){//t-> is huan? t>n?
	if(t>n){//huan!!!
		//cout<<"there is a round!Make it 100"<<endl;
		b[x1]=100;
		return 100;
	}
	if(b[x2]==0&&a[x2]!=0&&x1!=x2){
		if(!f[x2])	f[x1]=!f[x1];
		//cout<<"find "<<x2<<"'s father"<<" now is"<<f[x1]<<endl;
		return eq(x1,a[x2],t+1);
	}	
	if(x1==x2&&f[x2]==false){
		//cout<<"equal to -xself"<<endl;
		b[x1]=-1;
		return -1;
	}
	if(x1==x2&&f[x2]==true)	{
		//cout<<"equal to itself!make it 100"<<endl;
		b[x1]=100;
		a[x1]=0;
		return 100;//equal to itself,any
	}
	if(b[x2]!=0){
		//cout<<"equal to x2's number"<<endl;
		if(b[x2]==-1)	{
			b[x1]=-1;
			return -1;
		}
		if(b[x2]=='T'&&f[x1]){
			b[x1]=100;
			return 100;
		}	
		if(b[x2]=='T'&&!f[x1]){
			b[x1]=50;
			return 50;
		}	
		if(b[x2]=='F'&&f[x1]){
			b[x1]=50;
			return 50;
		}	
		if(b[x2]=='F'&&!f[x1]){
			b[x1]=100;
			return 100;
		}	
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int jj=1;jj<=t;jj++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++){
			a[i]=0;f[i]=0;b[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			char c;cin>>c;
			if(c=='-'){
				int x1,x2;
				scanf("%d%d",&x1,&x2);
				a[x1]=x2;
				f[x1]=false;
				b[x1]=0;		
			}
			if(c=='+'){
				int x1,x2;
				scanf("%d%d",&x1,&x2);
				a[x1]=x2;
				f[x1]=true;
				b[x1]=0;// follow other x,itself haven't
			}
			if(c=='U'||c=='T'||c=='F'){
				int x;
				scanf("%d",&x);
				if(c=='U')	b[x]=-1;
				if(c=='T')	b[x]=100;
				if(c=='F')	b[x]=50;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0&&b[i]==0)	continue;//not do this x,it can be anything
			else
			if(b[i]!=0){
				if(b[i]==-1){
					sum++;continue;
				}
			}
			else{
				int check=eq(i,a[i],1);
				if(check==-1){
					sum++;continue;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
//have problem!!!!
//about to be proper ,but can't through yangli\
//remember to delect mm and jj!!!!!!!!!!!!!!
//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

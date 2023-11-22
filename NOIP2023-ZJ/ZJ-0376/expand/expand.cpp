#include<bits/stdc++.h>
using namespace std;
const int N=500020;
int c,n,m,q;
int a[N],b[N],cop[N],cop1[N]; 
int start[N],end[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&b[j]);
	}
	if(c==1)
	{
		if(a[1]!=b[1]) printf("1");
		else printf("0");
	}
	else if(c==2)
	{
		if(a[1]>b[1]&&a[2]>b[2]) printf("1");
		else if(a[1]<b[1]&&a[2]<b[2]) printf("1");
		else printf("0");
	}
	else{
		//cout<<'a';
		//for(int i=2;i<=n;i++)
		//{
		//	start[i]=2;
			//end[i]=-1e9;
		//}
		//start[1]=1;end[i]=-1e9;
		if(a[1]==b[1]||a[n]==b[n]) printf("0");
		else if(a[1]>b[1]&&a[n]<b[n]) printf("0");
		else if(a[1]<b[1]&&a[n]>b[n]) printf("0");
		else printf("1");
		/* if(a[1]>b[1]){
			bool flag=1;
			for(int i=1;i<=n;i++)
			{
				while(a[i]>b[start[i]])
				{
					start[i]++;
					
				}
			}
		}
		*/
	}
	for(int j=1;j<=n;j++) cop[j]=a[j];
	for(int j=1;j<=n;j++) cop1[j]=b[j];
	for(int i=1;i<=q;i++)
	{
		int ia,ib,ka,kb;
		scanf("%d%d",&ia,&ib);
		for(int j=1;j<=n;j++)
		{
			a[j]=cop[j],b[j]=cop1[j];
		}
		for(int j=1;j<=ia;j++)
		{
			scanf("%d%d",&ka,&kb);
			a[ka]=kb;
		}
		for(int j=1;j<=ib;j++)
		{
			scanf("%d%d",&ka,&kb);
			b[ka]=kb;
		}
		if(c==1)
		{
			if(a[1]!=b[1]) printf("1");
		    else printf("0");
		}
		else if(c==2)
		{
			if(a[1]>b[1]&&a[2]>b[2]) printf("1");
			else if(a[1]<b[1]&&a[2]<b[2]) printf("1");
			else printf("0");
		}
		else{
			//cout<<'a';
			//for(int i=1;i<=n;i++)
			//{
			//	cout<<a[i]<<" ";
			//}
			//cout<<endl;
			//for(int j=1;j<=n;j++)
			//{
			//	cout<<b[j]<<" ";
			//}
			//cout<<endl;
			if(a[1]==b[1]||a[n]==b[n]) printf("0");
			else if(a[1]>b[1]&&a[n]<b[n]) printf("0");
			else if(a[1]<b[1]&&a[n]>b[n]) printf("0");
			else printf("1");
			/* if(a[1]>b[1]){
				bool flag=1;
				for(int i=1;i<=n;i++)
				{
					while(a[i]>b[start[i]])
					{
						start[i]++;
						
					}
				}
			}
			*/
	    }
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=0,ans=0,a[N]={0},f[N]={0};
    int temp=0;
	while(cin>>temp)a[++n]=temp;
	memset(f,0x3F,sizeof(f));
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(f[mid]<=a[i]){
                l=mid+1;
            }
			else {
                r=mid;
            }
		}
		f[l]=min(f[l],a[i]);
		ans=max(ans,l);
	}
	cout<<ans<<endl;
	memset(f,0x3F,sizeof(f));
	reverse(a+1,a+n+1);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(f[mid]<a[i])
            {   
                l=mid+1;
            }
			else {
                r=mid;
            }
		}
		f[l]=min(f[l],a[i]);
		ans=max(ans,l);
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, M = 60;
int n, l1, l2;
string s, t1, t2;
int dp[N][M], a[256];
signed main()
{
	//    freopen("A.in","r",stdin);
	//    freopen("A.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> s >> t1 >> t2;
		n = s.length(), l1 = t1.length(), l2 = t2.length();
		s = " " + s, t1 = " " + t1, t2 = " " + t2;
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= l2; i++)
		{
			a[t2[i]] |= (1 << i);
		}
		//        for(int i='a',j;i<='b';i++){
		//            for(j=1;j<=l2;j++){
		//                cout<<((a[i]>>j)&1);
		//            }
		//            cout<<" ";
		//        }
		//        cout<<"\n\n";
		if (s[1] == t1[1])
			dp[1][1] |= (1ll << l2);
		if (s[1] == t2[1])
			dp[1][l1] |= (1ll << 1ll);
		//        for(int j=1;j<=l1;j++){
		//            for(int k=1;k<=l2;k++){
		//                cout<<((dp[1][j]>>k)&1ll);
		//            }
		//            cout<<" ";
		//        }
		//        cout<<'\n';
		for (int i = 2, j, k, lasj, lask; i <= n; ++i)
		{
			for (j = 1; j <= l1; ++j)
			{
				if (j != 1)
					lasj = j - 1;
				else
					lasj = l1;
				if (s[i] == t1[j])
				{
					dp[i][j] |= dp[i - 1][lasj];
				}
				//                if(i==3 && j==2){
				//                    cout<<" \nsdfsdf\n";
				//                    cout<<(dp[i-1][j]<<1ll)<<'\n';
				//                    cout<<(dp[i-1][j]>>(l2-1))<<'\n';
				//                    cout<<a[s[i]]<<'\n';
				////                    cout<<(((dp[i-1][j]<<1ll)|((dp[i-1][j]>>(l2-1))&2ll))&a[s[i]])<<" dfds\n";
				//                }
				//                int tmp=dp[i-1][j]&a[s[i]];
				//                dp[i][j]|=(((tmp<<1ll)|((tmp>>(l2-1ll))&())));
				dp[i][j] |= (((dp[i - 1][j] << 1ll) | (dp[i - 1][j] >> (l2 - 1ll))) & a[s[i]]);
				//                for(int k=1;k<=l2;k++){
				//                    cout<<((dp[i][j]>>k)&1ll);
				//                }
				//                cout<<" ";
				//                for(k=1;k<=l2;++k){
				//                    if(j!=1) lasj=j-1;
				//                    else lasj=l1;
				//                    if(k!=1) lask=k-1;
				//                    else lask=l2;
				//                    if(dp[y][lasj][k]==1 && s[i]==t1[j]) dp[x][j][k]=1;
				//                    else if(dp[y][j][lask]==1 && s[i]==t2[k]) dp[x][j][k]=1;
				//                    else dp[x][j][k]=0;
				//                }
			}
			//            cout<<'\n';
		}
		if ((dp[n][l1] >> l2) & 1ll)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}

	return 0;
}

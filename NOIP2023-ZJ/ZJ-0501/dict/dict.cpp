#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+3;
int n,m;
string s[MAXN],re[MAXN],ans;
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        re[i] = s[i];
        sort(s[i].begin(),s[i].end());
        sort(re[i].begin(),re[i].end(),[](auto a,auto b){return a>b;});
    }

    for(int i = 1;i<=n;i++){
        bool flag = true;
        for(int j = 1;j<=n;j++){
            if(j==i)continue;
            flag&=(s[i]<re[j]);
            if(s[i]>re[j])break;
        }
        if (flag)ans+='1';
        else ans+='0';
    }
    cout<<ans;
	return 0;
}
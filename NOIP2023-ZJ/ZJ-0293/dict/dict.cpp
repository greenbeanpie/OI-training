#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,cnt[N][26],id[N];
string s;int nw=1;
bool cmp(int x,int y){
    for(int i=25;i>=0;i--){
        if(cnt[x][i]>cnt[y][i])
            return 0;
        else if(cnt[x][i]<cnt[y][i])
            return 1;
    }
    return 1;
}
bool check(int id){
    int minn=100;
    for(int i=0;i<=25;i++)
        if(cnt[id][i]){
            minn=i;
            break;
        }
    for(int i=minn+1;i<=25;i++)
        if(cnt[nw][i])return 1;
    for(int i=minn+1;i<=25;i++)
        if(cnt[id][i])return 0;
    for(int i=0;i<minn;i++)
        if(cnt[nw][i])return 0;
    return 1;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(auto x:s)
            cnt[i][x-'a']++;
        id[i]=i;
    }
    for(int i=2;i<=n;i++)
        if(cmp(i,nw))
            nw=i;
    for(int i=1;i<=n;i++){
        if(check(i))cout<<"1";
        else cout<<"0";
    }cout<<"\n";
    return 0;
}

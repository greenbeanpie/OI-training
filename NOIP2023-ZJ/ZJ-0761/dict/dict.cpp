/*
    NOIP 2023 T1 词典
    Code By Konjac0629
    不念过往，不负当下，不畏将来
    个人博客：https://www.konjac.blog

    NOIP_2023_RP+=INF;
*/
#include <bits/stdc++.h>

using namespace std;

bool comp1(string &a,string &b){
    for(int qwq=0;qwq<a.size();qwq++)
    {
        if(a[qwq]>b[qwq])
            return false;
        if(a[qwq]<b[qwq])
            return true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<pair<char,char>> userStr(n+1,{'z','a'});
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tv;
            cin >> tv;
            if(tv<userStr[i].first)
                userStr[i].first=tv;
            if(tv>userStr[i].second)
                userStr[i].second=tv;
        }
    }
    for(int i=0;i<n;i++){
        char flag='1';
        for(int j=0;j<n;j++){
            if(i!=j&&userStr[i].first>=userStr[j].second)
                flag='0';
        }
        cout << flag;
    }
    cout << endl;
    return 0;
}

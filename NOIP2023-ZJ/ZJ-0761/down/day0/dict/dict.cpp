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
    /*if(n<=1&&m<=1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n<=26&&m<=1)
    {
        vector<char> userChar(n);
        for(int i=0; i<n; i++)
        {
            cin >> userChar[i];
        }
        for(int i=0; i<n; i++)
        {
            if(userChar.begin()+i!=min_element(userChar.begin(),userChar.end()))
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;
        return 0;
    }*/
    // vector<string> userStr(n+1);
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
        //cin >> userStr[i];
        // sort(userStr[i].begin(),userStr[i].end(),[&](char a,char b){return a>b;});
    }
    //for(int i=0;i<n;i++){
        //cout << "pair " << i << ": " << userStr[i].first << " " << userStr[i].second << endl;
    //}
    for(int i=0;i<n;i++){
        char flag='1';
        for(int j=0;j<n;j++){
            if(i!=j&&userStr[i].first>=userStr[j].second)
                flag='0';
        }
        cout << flag;
        //string tempStr=userStr[i];
        //sort(tempStr.begin(),tempStr.end(),[&](char a,char b){return a<b;});
        // cout << "Debug Info:" << endl;
        // cout << userStr[i] << endl;
        // for(int j=0;j<n;j++){
            //if(j!=i)
                //sort(userStr[j].begin(),userStr[j].end(),[&](char a,char b){return a>b;});
            // cout << userStr[j] << endl;
        //}
        // cout << "Now min element: " << *min_element(userStr.begin(),userStr.end(),comp1) << endl;
        //userStr[n]=tempStr;
        //if(*min_element(userStr.begin(),userStr.end(),comp1)==tempStr)
            //cout << "1";
        //else
            //cout << "0";
    }
    cout << endl;
    return 0;
}

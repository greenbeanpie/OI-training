#include <bits/stdc++.h>
using namespace std;
#define int long long
int alphabet[26];
bool cmp(string a,string b)
{
    for(int i=0;i<min(a.length(),b.length());i++){
        if(alphabet[a[i]-'A']>alphabet[b[i]-'A']){
            return false;
        }
        else if(alphabet[a[i]-'A']<alphabet[b[i]-'A']){
            return true;
        }
    }
    if(a.length()>b.length()){
        return false;
    }
    else{
        return true;
    }
}

signed main(){
    int n;
    cin >> n;
    string str[n];
    string temp;
    cin >> temp;
    for(int i=0;i<26;i++){
        alphabet[temp[i]-'A']=i;
    }
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++){
        cout << str[i] << endl;
    }
    return 0;
}
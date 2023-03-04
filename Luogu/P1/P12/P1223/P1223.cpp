#include <bits/stdc++.h>
using namespace std;

struct person{
    long long t,num;
};

bool cmp(person a,person b){
    return a.t<b.t;
}

int main(){
    freopen("P1223.in","r",stdin);
    int n;
    cin >> n;
    person people[n];
    for(int i=0;i<n;i++){
        people[i].num=i+1;
        cin >> people[i].t;
    }
    sort(people,people+n,cmp);
    for(int i=0;i<n;i++){
        cout << people[i].num << " ";
    }
    cout << endl;
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=people[i].t*(n-i-1);
    }
    cout << fixed << setprecision(2) << sum/n;
    return 0;
}
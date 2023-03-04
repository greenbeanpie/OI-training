#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    for (int i=0;i<a.length();++i){
        if(a[i]>='A'&&a[i]<='Z')
        {
            a[i]+=('a'-'A');
        }
    }
    for (int i=0;i<b.length();++i){
        if(b[i]>='A'&&b[i]<='Z')
        {
            b[i]+=('a'-'A');
        }
    }
    a=' '+a+' ';
    b=' '+b+' ';
    int first=b.find(a);
    if (first==string::npos){
        cout<<-1<<endl;
    }
    else {
        int current=b.find(a);
        int sum=0;
        while (current!=string::npos){
            sum++;
            current=b.find(a,current+1);
        }
        cout<<sum<<" "<<first<<endl;
    }
    
    return 0;
}
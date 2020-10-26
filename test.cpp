#include<set>
#include<iostream>

using namespace std;

int main() {
    multiset<int> MS;
    MS.insert(1);
    MS.insert(1);
    MS.insert(2);
    MS.insert(3);
    multiset<int>::iterator iter = MS.begin();
    for(; iter != MS.end(); iter ++) {
        cout<<*iter<<endl;
    }
    cout<<"大小未："<<MS.size()<<endl;
    MS.erase(MS.find(1));
    for(iter = MS.begin(); iter != MS.end(); iter ++) {
        cout<<*iter<<endl;
    }
    cout<<"大小未："<<MS.size()<<endl;
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
bool isPanlindrome(int x) 
{
    int s = x;
    int m = 0;
    while (s > 0) {
        m = m * 10 + s % 10; 
        s /= 10;
    }
    return m == x;
}

int main() 
{
    int t, n;
    cin >> t;

    int v0[900];
    set<int> v;
    for(int i = 0; i < 900; i++) {
        v0[i] = 100 + i; 
    }
    for(int i = 0; i < 900; i++) {
        for(int j = 0; j < 900; j++) {
            int m = v0[i] * v0[j];
            // cout << v.size() << endl;
            
            if(isPanlindrome(m)) v.insert(m);
        }
    }
    //set<int>::iterator it;
    //for(it = v.begin(); it != v.end(); it++) {
    //    cout << *it << endl;
    // }
    for(int i = 0; i < t; i++) {
        cin >> n;
        while(n > 10000) {
            if(v.find(n) != v.end()) {
                cout << n << endl;
                break;
            }
            n--;
        }
    }
    return 0;
}

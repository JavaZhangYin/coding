#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, k, n;

    cin >> t; 
    for(int i = 0; i < t; i++) {
        cin >> n >> k; 
        string s; 
        cin >> s; 
        int l = -1; 
        int p = 1; 
        for(int j = 0; j < n - k; j++) {
            p = 1; 
            for(int m = j; m < j + k; m++) {
                // cout << "letter[" << m << "] = " << s[m] << endl; 
                p *= s[m] - '0'; 

            }
            // cout << "p = " << p << endl; 
            if(p > l) l = p; 
        }
        cout << l << endl; 
    }
}

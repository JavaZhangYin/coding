#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long x)
{
    if (1 == x) return false;
     
    for(long i = 2; i <= sqrt(x); i++) 
        if(x % i == 0) return false;

    return true;
}
    

int main() {
    int t;
    long n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        long m = n;

        for(long j = 2; j <= sqrt(m); j++) {
            // cout << "m = " << m << ", j = " << j << endl; 
            if(m % j == 0) {
                //cout << "m = " << m << ", j = " << j << endl; 

                m /= j;
                j = 1; 
            }
        }
        cout << m << endl; 
    }
}

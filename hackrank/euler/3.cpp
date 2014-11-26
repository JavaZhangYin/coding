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
         
        while(n > 0) {
            if(m % n == 0 && isPrime(n)) {
                cout << n << endl;
                break;
            }
            n--;
            
        }
    }
    
}

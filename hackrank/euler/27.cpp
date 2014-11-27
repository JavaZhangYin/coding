#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i <= sqrt(n); i++) {
        if(0 == n % i) return false; 
    }
    return true; 
}

int main() {
    for(int i = 0; i < 40; i++) {
        int x = i*i + i + 41; 
        cout << x << " --> " << isPrime(x) << endl; 
    }

    for(int i = 0; i < 80; i++) {
        int x = i*i - 79*i + 1601; 
        cout << x << " -->> " << isPrime(x) << endl; 
    }
    return 0;
}

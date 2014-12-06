#include <iostream> 
#include <set> 

using namespace std; 

bool hasDigit(int n, int d) {
    while(n > 0) {
        if(d == n % 10) return true; 
        n /= 10; 
    }
    return false; 
}

bool hasDigit(set<int> s, int d) {
    return s.find(d) != s.end(); 
}

void getThreeDigits(long n) {
    int s; 
    while(n > 1000) {
        s = n % 1000; 
        cout << s << endl; 
        n /= 10; 
    }
}

int main() {
    int n;
    cin >> n; 

    int digits = n + 1; 

    // get all permutations of digits. 

    // getThreeDigits(x); 

    return 0; 
}

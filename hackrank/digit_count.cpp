// count the occurance of digits. 

#include <iostream> 

using namespace std; 

// n should be 10; 
// p is the total number of pages. 
void countDigit(int c[], int n, int p) {
    for(int i = 1; i <= p; i++) {
        int m = i; 
        while(m > 0) {
            c[m % 10]++;
            m /= 10; 
        }
    }
}

int main() {
    int p, c[10]; 
    for(int i = 0; i < 10; i++) c[i] = 0; 

    cin >> p; 
    countDigit(c, 10, p); 

    for(int i = 0;i < 10; i++) cout << c[i] << " "; 
    cout << endl; 

    return 0; 
}

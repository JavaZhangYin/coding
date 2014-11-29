// pseudo code : 
// for i \in [1, N]
//     for j \in [1, j]
//         e > \frac{\sum_j 2^{i-j} h_j}{2_i}
// 
// We should be able to find the largest e which is the result. 
// We can use extra space to save the computation time. 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int n;
    cin >> n;
    int h[n];
    long long int e = 0;
    long long int x = -1;
    long long int M = 0, N = 0;
    h[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        long long int s = 0;
        if(M * N == 0) {
            M = h[i];
            N = pow(2, i);
        }
        else {
            M = 2 * M + h[i];
            N = 2 * N;
        }
        e = ceil ((double)M / (double)N);
        e = M / N
// cout << M << ", " << N << " " << M/N << endl; 
        cout << e << endl;
         
        if(e > x) x = e;
// cout << e << endl; 
    }
    cout << x << endl;
    return 0;
}

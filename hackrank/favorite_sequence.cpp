#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; 
    }
    cout << endl; 
}

int main() {
    int n, k; 
    cin >> n; 
    
    vector<int> v[n]; 
    for(int i = 0; i < n; i++) {
        cin >> k; 
        for(int j = 0; j < k; j++) {
            int x; 
            cin >> x; 
            v[i].push_back(x);
        }
    }
    
    // build result. 
    vector<int> x = v[0];
    vector<int> tmp; // result. 
    for(int i = 1; i < n; i++) {
        int len1 = x.size(); 
        int len2 = v[i].size(); 
        int dp[len1][len2]; 
        int m1 = 0, m2 = 0; 
        int j, k; 
        for(j = 0; j < len1; j++) {
            for(k = 0; k < len2; k++) {
                if (x[j] == v[i][k]) {
                    // merge two vectors and add return value to result. 
                    while (m1 < j && m2 < k) 
                        if(x[m1] < v[i][m2]) tmp.push_back(x[m1++]);
                        else tmp.push_back(v[i][m2++]);
                    while (m1 < j) tmp.push_back(x[m1++]);
                    while (m2 < k) tmp.push_back(v[i][m2++]);
                     
                    // tmp.insert(tmp.end(), t.begin(), t.end()); 
                    tmp.push_back(x[j]); 
                    m1 = j+1, m2 = k+1; 
                }
            }
        }

        while (m1 < j && m2 < k)
            if(x[m1] < v[i][m2]) tmp.push_back(x[m1++]);
            else tmp.push_back(v[i][m2++]);
        
        while (m1 < j) tmp.push_back(x[m1++]);
        while (m2 < k) tmp.push_back(v[i][m2++]);
        
        // cout << "After merged two: " << endl;
         
        // printVector(tmp); 
        x = tmp;
        tmp.clear();
    }
    // output result. 
    // cout << "===========RESULT===========" << endl;     
    printVector(x); 
    
    return 0;
}

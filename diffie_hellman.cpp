#include <bits/stdc++.h>
using namespace std;

long long modExp(long long base, long long exp, long long mod) {
 
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
    
    
}

int main() {
    long long p = 29;   
    long long g = 10;   

    long long a = 3;   
    long long b = 7;  

    long long X = modExp(g, a, p); 
    long long Y = modExp(g, b, p); 
    cout << "Public values:\n";
    cout << "X of A = " << X << endl;
    cout << "Y by B = " << Y << endl;

    long long secretA = modExp(Y, a, p);  
    long long secretB = modExp(X, b, p);  

    cout << "\nShared secret computed by A: " << secretA << endl;
    cout << "Shared secret computed by B: " << secretB << endl;

    return 0;
}

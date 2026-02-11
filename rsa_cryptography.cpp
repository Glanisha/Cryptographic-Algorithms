/***
RSA cryptography 

p and q need to be large prime numbers
p and q need to be prime numbers and co primes (duh if two primes then they are coprime only) 
n = p * q 
here p != q 

Euler's totient function φ(n) = (p − 1)(q − 1)
public key (e, n)
private key (d, n)

Choose 1 < e < φ(n)
gcd(e, φ(n)) = 1

choose d such that (e * d) % φ(n) = 1   

d = e⁻¹ mod φ(n)

Encryption is c = p^e % n 
Decyption is p = c^d % n 
this p is the plaintext not the p we chose before
***/

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}


bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long modInverse(long long e, long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;

    while (newr != 0) {
        long long q = r / newr;
        long long temp = newt;
        newt = t - q * newt;
        t = temp;

        temp = newr;
        newr = r - q * newr;
        r = temp;
    }

    if (t < 0) t += phi;
    return t;
}

int main() {
    string plaintext = "I like cake";
    vector<long long> ciphertext;
    string decrypted = "";

    int p = 11;
    int q = 13;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 7;
    if (gcd(e, phi) != 1) return 0;

    long long d = modInverse(e, phi);

    for (char ch : plaintext) {
        long long m = (int)ch;
        long long c = modExp(m, e, n);
        ciphertext.push_back(c);
    }

    for (long long c : ciphertext) {
        long long m = modExp(c, d, n);
        decrypted += char(m);
    }

    cout << "Original: " << plaintext << endl;

    cout << "Encrypted: ";
    for (auto c : ciphertext) cout << c << " ";
    cout << endl;

    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

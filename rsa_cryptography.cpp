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

long long computeN(long long p, long long q) {
    return p * q;
}


long long phi(long long p, long long q) {
    return (p - 1) * (q - 1);
}


bool validE(long long e, long long phi_n) {
    return e > 1 && e < phi_n && gcd(e, phi_n) == 1;
}


long long modInverse(long long e, long long phi_n) {
    long long t = 0, newt = 1;
    long long r = phi_n, newr = e;

    while (newr != 0) {
        long long q = r / newr;

        long long temp = newt;
        newt = t - q * newt;
        t = temp;

        temp = newr;
        newr = r - q * newr;
        r = temp;
    }

    if (r > 1) return -1;
    if (t < 0) t += phi_n;

    return t; 
}

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

long long encrypt(long long m, long long e, long long n) {
    return modExp(m, e, n);
}

long long decrypt(long long c, long long d, long long n) {
    return modExp(c, d, n);
}


int main() {
    long long p = 3, q = 11;

    if (!isPrime(p) || !isPrime(q) || p == q) return 0;

    long long n = computeN(p, q);
    long long phi_n = phi(p, q);

    long long e = 3;
    if (!validE(e, phi_n)) return 0;

    long long d = modInverse(e, phi_n);

    long long m = 4;
    long long c = encrypt(m, e, n);
    long long original = decrypt(c, d, n);

    cout << "Encrypted: " << c << endl;
    cout << "Decrypted: " << original << endl;
    return 0;
}











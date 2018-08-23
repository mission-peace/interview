/*
    Program to find prime factorization of a number using Sieve of Eratosthenes
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define printVec(a) for (int i = 0; i < a.size(); i++) cout << a[i] << " ";

vector<int> getPrimeFactorization(ll n) {
    vector<int> prime_factors;
    bool is_composite[(int)sqrt(n) + 1];
    memset(is_composite, 0, sizeof(is_composite));

    for (int i = 2; i <= sqrt(n); i++) {
        if (!is_composite[i]) {
            for (int j = i + i; j <= sqrt(n); j += i) is_composite[j] = 1;
            while (!(n % i)) {
                n /= i;
                prime_factors.push_back(i);
            }
        }
    }
    if (n != 1) prime_factors.push_back(n);
    return prime_factors;
}

int main(){
    ll n;
    vector<int> pf;
    
    cin >> n;
    pf = getPrimeFactorization(n);
    printVec(pf);
    return 0;
}

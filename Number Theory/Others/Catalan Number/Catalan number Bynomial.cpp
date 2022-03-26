#include<iostream>
using namespace std;

unsigned long long int binomialCoeff(unsigned long long int n, unsigned long long int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long long int catalan(unsigned long long int n)
{
    unsigned long long int c = binomialCoeff(2*n, n);

    // return 2nCn/(n+1)
    return c/(n+1);
}

int main()
{
        int num;
    cin >> num;
    for (int i = 0; i <= num; i++)
        cout << i << " : \t" <<  catalan(i) << endl;
    return 0;
}

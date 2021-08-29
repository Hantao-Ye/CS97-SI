#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 1000000

using namespace std;
vector<unsigned int> isPrime(MAX, 1);

void getPrimes()
{
    vector<unsigned int> primes;

    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i])
            primes.push_back(i);

        for (int j = 0; j < primes.size() && i * primes[j] < MAX; j++)
        {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }

}

int main()
{
    unsigned int n;

    getPrimes();
    // freopen("input.txt", "r", stdin);
    while (cin >> n && n != 0)
    {
        bool pairExist = false;
        unsigned int outputPair[2] = {0, 0};

        for (int i = 2; i < n && !pairExist; i++)
        {
            if (isPrime[i] && isPrime[n - i])
            {
                pairExist = true;
                outputPair[0] = i;
                outputPair[1] = n - i;
            }
        }

        if (pairExist)
            cout << n << " = " << outputPair[0] << " + " << outputPair[1] << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}
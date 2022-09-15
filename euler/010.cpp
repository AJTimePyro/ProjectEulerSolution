// Project Euler #10: Summation of primes

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes not greater than given N.
*/

/*
    # Approach to solve it
    * Find prime numbers upto limit and just add them.
Note: How to find Prime numbers, already explained previously
in 3rd problem and 5th problem.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAXLIMIT 1000000    // Max Limit in HackerRank
vector <int> prime;

long long prime_sum(const int num) {
    long long sum = 0;
    int iter = 0;
    int _num = prime[iter];
    while (_num <= num) {
        sum += _num;
        iter++;
        _num = prime[iter];
    }
    return sum;
}


int main(){

    // Getting all prime numbers upto limit (for the sake of time)
    prime.push_back(2);
    int num = 3;
    while (num <= MAXLIMIT) {
        bool count = true;
        for (int factor = 2; factor <= sqrt(num); factor++) {
            if (num % factor == 0) {
                count = false;
                break;
            }
        }
        if (count) {
            prime.push_back(num);
        }
        num += 2;
    }

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << prime_sum(n) << endl;
    }
    return 0;
}
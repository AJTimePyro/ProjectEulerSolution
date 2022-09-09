// Project Euler #7: 10001st prime

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.
What is the Nth prime number?
*/

/*
    # Approach to solve it
    1. Generate max limit of prime numbers and store them in array
       or whatever.
    2. How to generate prime numbers? Well just find those number
       who are not divisible in range of 2 to square root of this
       given number.
    3. Now simply get prime number of asked position/index/rank.
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

// To generate Prime Number to Max limit
map <int, int> get_prime(long long num) {

    map <int, int> prime;
    long long th = 1, number = 1; // th is position of prime number

    prime[1] = 2;   // Intialising First Prime number as 2
    while (th != num) {
        number += 2;
        long long count = 0;
        for (long long i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                count++;
                if (count > 0) {
                    break;
                }
            }
        }
        if (!count) {
            th++;
            prime[th] = number;
        }
    }
    return prime;
}

// According to question max limit is 10,000.
map <int, int> all_prime = get_prime(10000);

// Returning Prime Number at given position
long long nth_prime_num(long long num) {
    return all_prime[num];
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        cout << nth_prime_num(n) << endl;
    }
    return 0;
}
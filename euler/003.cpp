// Project Euler #3: Largest prime factor
/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of a given number N?
*/

/*
    # Approach to solve it
    1. Divide given number by 2 until it is not divisibe
       (Remainder = 0) by 2, and set largest prime number 
       to 2 (initially).
    2. Run a loop from 3 to square root of given number, and 
       iterator should increase by 2 in each round of loop.
       (Because there exist only 1 even prime (2) and rest is odd)
    3. In each iteration if given number is divisble by iterator,
       set largest prime number to by iterator and then divide
       given number by iterator till it is not divisible
       (remainder != 0) by that iterator.
    4. If given number (after being divided in above process)
       turnout to be greater than 2, then set original given
       number to largest prime number.
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

long long get_largest_prime_factor(long long num) {
    long long largest;
    while (num % 2 == 0) {
        largest = 2;
        num /= 2;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            num /= i;
            largest = i;
        }
    }
    if (num > 2) {
        largest = num;
    }
    return largest;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        cout << get_largest_prime_factor(n) << endl;
    }
    return 0;
}
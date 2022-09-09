// Project Euler #1: Multiples of 3 and 5

/*
If we list all the natural numbers below  that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.
*/

/*
    # Approach to solve it
    1. Find individual sum of all multiples of 3, 5 and 15 using
       Arithmetic Progression concept.
    2. Add the sum of multiples of 3 and 5.
    3. Subtract the sum of multiple of 15. (Because 3 and 5 have 
       some common terms (15, 30, 45, ...) that should be removed)
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

long long sum_3_5(long long num) {

    // Total number of multiples of 3, 5 and 15
    long long total_3 = (num - 1)/3;
    long long total_5 = (num - 1)/5;
    long long total_15 = (num - 1)/15;

    // Individual sum of multiples of 3, 5 and 15 
    long long sum_of_3 = (total_3 * (6 + (total_3 - 1) * 3))/2;
    long long sum_of_5 = (total_5 * (10 + (total_5 - 1) * 5))/2;
    long long sum_of_15 = (total_15 * (30 + (total_15 - 1) * 15))/2;

    // Adding sum of multiples of 3 and 5, and subracting sum of
    // multiple of 15 from it.
    long long sum = sum_of_3 + sum_of_5 - sum_of_15;
    
    return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        cout << sum_3_5(n) << endl;
    }
    return 0;
}
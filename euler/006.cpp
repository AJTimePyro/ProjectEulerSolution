// Project Euler #6: Sum square difference

/*
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385. The square of the sum of the first ten natural numbers is, (1 + 2 + 3 + ... + 10)^2 = 3025. Hence the absolute difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the absolute difference between the sum of the squares of the first N natural numbers and the square of the sum.
*/

/*
    # Approach to solve it
    1. Find the sum of square of first N natural number
    2. Find the square of sum of first N natural number.
    3. Now get absolute difference between them.

Note:Sum of square of fist N natural number = (N*(N+1)*((2*N)+1))/6
     Sum of first N natural number = (N*(N+1))/2
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

long long sum_square_diff(long long num) {
    long long sum1, sum2, _sum;

    // Common term + (sum of first num natural numbers)
    _sum = (num * (num + 1)) / 2;
    
    // Sum of squares and Square of sum
    sum1 = (_sum * ((2 * num) + 1)) / 3;
    sum2 = _sum * _sum;

    // Difference of Sum of Squares and Square of Sum
    long long ans = sum1 - sum2;

    // To make answer always postive
    ans = ans < 0 ? ans * -1 : ans;

    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        cout << sum_square_diff(n) << endl;
    }
    return 0;
}
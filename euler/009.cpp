// Project Euler #9: Special Pythagorean triplet

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2
For example, 
    3^2 + 4^2 = 5^2
Given N, Check if there exists any Pythagorean triplet for which 
a + b + c = N
Find maximum product (a*b*c) for possible value of a, b, c among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.
*/

/*
    # Approach to solve it
    1. Break down given number into 3 numbers(n = a + b + c)
       several times.
    2. Now check if a, b, c satisfies the Pythagorean theorem.
    3. If it satisfies, then find the product of a, b & c and
       get maximum product.
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

#define MAX_LIMIT 3000

int max_triplet(int num) {
    int max_product = -1;
    int max_side = num - 2;
    int a, b, c;
    int product;
    for (a = 3; a <= num/3; a++) {  // No Pythagorean triplet has 0, 1 or 2.
        for (b = a + 1; b <= max_side/2; b++) {
            c = num - a - b;
            if (c*c == a*a + b*b) {
                product = a * b * c;
                if (product > max_product) {
                    max_product = product;
                }
            }
        }
        max_side--;
    }
    return max_product;
}

int main(){

    // To get all product during compilation, becuase of time limit
    int* max_triplet_product = new int[MAX_LIMIT + 1];
    for (int i = 0; i <= MAX_LIMIT; i++) {
        int product = max_triplet(i);
        max_triplet_product[i] = product;
    }

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << max_triplet_product[n] << endl;
        max_triplet(n);
    }
    return 0;
}
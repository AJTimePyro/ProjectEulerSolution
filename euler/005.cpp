// Project Euler #5: Smallest multiple

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
*/

/*
    # Approach to solve it
    1. Store all numbers from 2 to N(given number) in array
       (all_num).
    2. Get all Prime Numbers from 2 to N and store them in
       array (all_prime).
    3. Now iterate array of prime numbers and in each iteration 
       divide all divisible numbers of array (all_num) by
       iterator and store that single prime number in array
       (It will be factors of given number) and repeat this
       divison until no divisible number is left in array
       (all_num), if any element of array after being divided
       turn out to be 1, then remove that element from array
       (all_num). But if no number is divisible by iterator,
       then don't store prime number and continue in next
       iteration of prime numbers.
    4. After storing all factors, multiple all factors to
       get answer.

Note: It is similar to finding LCM (Least Common Multiple)
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

// Getting all Numbers from 2 to num
vector <int> get_all_num(int num) {
    vector <int> all_num;
    for (int i = 2; i <= num; i++) {
        all_num.push_back(i);
    }
    return all_num;
}

// Getting all prime numbers from 2 to num
vector <int> get_prime(int num) {
    vector <int> prime_num;
    for (int j = 2; j <= num; j++) {
        int count = 0;
        for (int k = 1; k <= j; k++) {
            if (j % k == 0) {
                count++;
            }
        }

        // Meaning of 2 is given iterator is divisble by 1 and it's own.
        if (count == 2) {
            prime_num.push_back(j);
        }
    }
    return prime_num;
}

int smallest_multiple(int num) {
    int res = 1;
    vector <int> vec, factors, prime;

    // Getting all numbers and Prime numbers
    vec = get_all_num(num);
    prime = get_prime(num);

    // Iterating through all prime numbers
    for (int iter = 0; iter < prime.size(); iter++) {
        int temp = prime[iter];
        int count = 1;
        int round = 1;

        // Divide all divisble numbers of vec until no divisible number is left
        while (count != 0) {
            count--;
            int i = 0;
            while (i < vec.size()) {
                if (vec[i] % temp == 0) {
                    vec[i] /= temp;
                    count = 1;
                    if (vec[i] == 1) {  // Removing it because is 1
                        vec.erase(vec.begin() + i);
                    }
                }
                i++;
            }
            round++;
            if (count != 0) {
                factors.push_back(temp);    // add factors in array
            }
        }
    }

    for (int happy = 0; happy < factors.size(); happy++) {
        res *= factors[happy];  // Product all factors to get LCM
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << smallest_multiple(n) << endl;
    }
    return 0;
}
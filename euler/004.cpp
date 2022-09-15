// Project Euler #4: Largest palindrome product

/*
A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101 = 143 X 707.

Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
*/

/*
    # Approach to solve it
    1. Get all palindromes which are multiple of two numbers each
       of three digits.
    2. Now simply return greatest possible palindrome.
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

vector <int> palindrome;

bool isPalindrome(int num) {
    int temp = num, reverse = 0, count = 0;
    vector <int> digit;
    while (temp) {
        digit.push_back(temp % 10);
        temp /= 10;
    }
    for (int i = digit.size() - 1; i >= 0; i--) {
        int power = pow(10, count) + 0.5;
        reverse += digit[i] * power;
        count++;
    }
    if (reverse == num) {
        return true;
    }
    else {
        return false;
    }
}

int nearest_palindrome(int num) {
    int max = 0, iter = 0;
    int temp = palindrome[iter];
    while (temp < num) {
        if (temp > max) {
            max = temp;
        }
        iter++;
        temp = palindrome[iter];
    }
    cout << temp << endl;
    return max;
}

int main(){
    int product;
    int lower_num = 100;
    int upper_num = 999;
    for (int i = lower_num; i < upper_num; i++) {
        for (int j = lower_num; j < upper_num; j++) {
            product = i * j;
            if (isPalindrome(product)) {
                palindrome.push_back(product);
            }
        }
    }
    sort(palindrome.begin(), palindrome.end());

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << nearest_palindrome(n) << endl;
    }
    return 0;
}
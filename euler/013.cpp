// Project Euler #13: Large sum

/*
Work out the first ten digits of the sum of N 50 - digit numbers.
*/

/*
    # Approach to solve it
    1. Store each 50 digit number as string.
    2. Now add all N number which is in string, How? Like we
       generally do on paper, Adding digit by digit and passing
       carry over to next digit. Store these number in array.
    3. Now print last 10 numbers. Boom!
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define DIGIT 50
using namespace std;

void largeSum(string num[], int n) {
    vector <int> addition;
    int carryOver = 0;
    for (int j = DIGIT - 1; j >= 0; j--) {
        int add = carryOver;
        for (int m = 0; m < n; m++) {
            int temp = num[m][j] - '0';
            add += temp;
        }
        carryOver = add/10;
        add = add%10;
        addition.push_back(add);
    }
    while (carryOver) {
        addition.push_back(carryOver%10);
        carryOver = carryOver/10;
    }
    int tindex = addition.size() - 1;
    for (int iter = tindex; iter > tindex - 10; iter--) {
        cout << addition[iter];
    }
}

int main() {
    int n;
    cin >> n;
    string* num = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    largeSum(num, n);
    return 0;
}
// Project Euler #8: Largest product in a series

/*
Find the greatest product of K consecutive digits in the N digit number.
*/

/*
    # Approach to solve it
    1. Get all possible consecutive numbers of given size.
    2. Find product of digit of each consecutive number.
    3. Compare all product and get largest product.
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


// To find Product of All digits in a number
int product_of_digit(int num) {
    int product = 1;
    while (num) {
        int temp = num % 10;
        num /= 10;
        product *= temp;
    }
    return product;
}

int largest_product_in_series(string num, int n, int k) {

    int total_nums = n - k + 1; // Total no of cons. num of size k
    int max_product = 0;
    for (int i = 0; i < total_nums; i++) {
        string temp_str = num.substr(i, k); // Getting cons. num
        int new_num = stoi(temp_str);
        int product = product_of_digit(new_num);
        if (product > max_product) {
            max_product = product;
        }
    }
    return max_product;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        cout << largest_product_in_series(num, n, k) << endl;
    }
    return 0;
}
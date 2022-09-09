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
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

long long evenFibonacci(long long num) {
    long long temp;
    long long sum = 0, a = 1, b = 2;
    while (b < num) {
        if (b % 2 == 0) {
            sum += b;
        }
        temp = a;
        a = b;
        b = temp + a;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        cout << evenFibonacci(n) << endl;
    }
    return 0;
}
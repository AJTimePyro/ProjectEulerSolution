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
    long long total_3 = (num - 1)/3;
    long long total_5 = (num - 1)/5;
    long long total_15 = (num - 1)/15;

    long long sum = (total_3 * (6 + (total_3 - 1) * 3))/2;
    sum += (total_5 * (10 + (total_5 - 1) * 5))/2;
    sum -= (total_15 * (30 + (total_15 - 1) * 15))/2;
    
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
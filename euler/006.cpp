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
    _sum = (num * (num + 1)) / 2;
    sum1 = (_sum * ((2 * num) + 1)) / 3;
    sum2 = _sum * _sum;
    long long ans = sum1 - sum2;
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
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

vector <int> get_all_num(int num) {
    vector <int> all_num;
    for (int i = 2; i <= num; i++) {
        all_num.push_back(i);
    }
    return all_num;
}

vector <int> get_prime(int num) {
    vector <int> prime_num;
    for (int j = 2; j <= num; j++) {
        int count = 0;
        for (int k = 1; k <= j; k++) {
            if (j % k == 0) {
                count++;
            }
        }
        if (count == 2) {
            prime_num.push_back(j);
        }
    }
    return prime_num;
}

int smallest_multiple(int num) {
    int res = 1;
    vector <int> vec, factors, prime;
    vec = get_all_num(num);
    prime = get_prime(num);

    for (int iter = 0; iter < prime.size(); iter++) {
        int temp = prime[iter];
        int count = 1;
        int round = 1;
        while (count != 0) {
            count--;
            int i = 0;
            while (i < vec.size()) {
                if (vec[i] % temp == 0) {
                    vec[i] /= temp;
                    count = 1;
                    if (vec[i] == 1) {
                        vec.erase(vec.begin() + i);
                    }
                }
                i++;
            }
            round++;
            if (count != 0) {
                factors.push_back(temp);
            }
        }
    }

    for (int happy = 0; happy < factors.size(); happy++) {
        res *= factors[happy];
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
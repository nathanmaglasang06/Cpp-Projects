//
// Created by Nathan Maglasang on 27/9/2025.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using i64 = long long;

i64 EuclideanCount(i64 a, i64 b) {
    int count = 0;
    while (b != 0) {
        i64 temp = b;
        b = a % b;
        a = temp;
        count++;
    }
    return count;
}
i64 EuclideanCount_v2(i64 a, i64 b) {
    i64 count = 0;
    while (b != 0) {
        i64 r = a % b;
        if (r == 0) {
            count++;
            break;
        }
        if (r < (b / 2)) {
            i64 temp = b;
            b = r;
            a = temp;
        } else {
            i64 temp = b;
            b = b - r;
            a = temp;
        }
        count++;
    }
    return count;
}


int main() {
    i64 counttrue = 0;
    i64 countfalse = 0;
    i64 counttotal = 0;
    i64 n;
    vector<pair<int, int>> Pairs;
    Pairs.clear();

    cout << "Enter a n: ";
    cin >> n;

    for (i64 a = 1; a < n; ++a) {
        for (i64 b = 1; b < n; ++b) {
            Pairs.push_back(std::make_pair(a, b));
            counttotal++;
            if (a <= 10000 && b <= 10000) {
                if (EuclideanCount_v2(a,b) == EuclideanCount(a, b)) {
                    counttrue++;
                } else {
                    countfalse++;
                }
            } else {
                countfalse++;
            }

        }
    }
    float prop = float(counttrue) / float(counttotal);
    cout << "Final Proportion:  " << prop << ", Unsimplified: " << counttrue << ":" << countfalse << "\n\n";
    cout << "Total count of success  = (a, b) = 10^3 && V2 < V1: " << counttrue << "\n";
    cout << "Total count of fail: " << countfalse << "\n";




    cout << "Total count of (success && fail): " << counttotal << "\n";

}
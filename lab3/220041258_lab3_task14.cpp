#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N;
     cin >> N;

     vector<int> A(N);
    for (int i = 0; i < N; ++i) {
         cin >> A[i];
    }


     multiset<int> top3;

    for (int i = 0; i < N; ++i) {

        top3.insert(A[i]);

        if (top3.size() > 3) {
            top3.erase(top3.begin());
        }

        if (top3.size() < 3) {
             cout << "-1" <<  endl;
        } else {

             vector<int> topElements(top3.rbegin(), top3.rend());
            int product = topElements[0] * topElements[1] * topElements[2];
             cout << product <<  endl;
        }
    }

    return 0;
}


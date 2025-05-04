#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long maxBlocks = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] > maxBlocks) {
                maxBlocks += (a[i] - maxBlocks);
            }
        }

        cout << maxBlocks << endl;
    }

    return 0;
}
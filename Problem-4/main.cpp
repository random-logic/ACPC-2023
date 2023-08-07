#include <iostream>
#include <vector>
#include <bitset>
#include <tgmath.h>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < N; ++i) {
        int x = v[i], count = 0;

        bitset<32> b(x);

        for (long long i = 0; i < 32; ++i)
            if (b[i]) ++count;

        if (count > 4 || x == 0) {
            cout << -1 << endl;
        }
        else if (count == 4) {
            for (long long i = 0; i < 32; ++i) {
                if (b[i]) {
                    cout << pow(2, i);
                    --count;
                    if (count > 0)
                        cout << " ";
                    else break;
                }
            }

            cout << endl;
        }
        else if (count == 3) {
            // Find one bit to move once
            long long i = 31;
            bool found = false;

            for (; i >= 1; --i) {
                if (b[i]) {
                    long long y = pow(2, i - 1);
                    cout << y << " " << y << " ";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << -1 << endl;
            else {
                for (--i; i >= 0; --i) {
                    if (b[i]) {
                        cout << pow(2, i);
                        --count;
                        if (count > 1)
                            cout << " ";
                        else
                            break;
                    }
                }

                cout << endl;
            }
        }
        else if (count == 2) {
            bool found = false;
            long long i;

            for (i = 31; i >= 2; --i) {
                if (b[i]) {
                    long long y = pow(2, i - 1), // represent once
                        z = pow(2, i - 2); // represented twice

                    found = true;

                    cout << y << " " << z << " " << z << " ";

                    break;
                }
            }

            if (!found)
                cout << -1 << endl;
            else
                for (--i; i >= 0; --i) {
                    if (b[i]) {
                        cout << pow(2, i) << endl;
                        break;
                    }
                }
        }
        else {// count == 1
            bool found = false;
            for (long long i = 2; i < 31; ++i) {
                if (b[i]) {
                    found = true;
                    long long y = pow(2, i - 2);
                    cout << y << " " << y << " " << y << " " << y << endl;
                    break;
                }
            }

            if (!found)
                cout << -1 << endl;
        }
    }

    return 0;
}

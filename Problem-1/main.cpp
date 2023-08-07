#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K, N;
    std::cin >> N >> K;

    std::vector<int> v(N);

    for (int i = 0; i < N; ++i)
        std::cin >> v[i];

    std::sort(v.begin(), v.end(), std::greater<int>());

    long long sum = 0;
    int i = 0;

    for (; i < K; ++i)
        sum += v[i];

    std::cout << sum << std::endl;

    for (--i; i >= 0; --i) {
        std::cout << v[i];
        if (i > 0)
            std::cout << " ";
    }

    return 0;
}

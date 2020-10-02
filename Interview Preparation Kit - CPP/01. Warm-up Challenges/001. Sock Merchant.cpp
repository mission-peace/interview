// Problem: https://www.hackerrank.com/challenges/sock-merchant/problem
// Score: 10


#include <iostream>


int main() {
    int n, element;
    int arr[101] = {0};
    int ans = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> element;
        arr[element]++;

        ans += arr[element] / 2;
        arr[element] = arr[element] % 2;
    }

    std::cout << ans << std::endl;
    return 0;
}

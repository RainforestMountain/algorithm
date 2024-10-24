#include <iostream>
#include <bits/stdc++.h>
#include <complex>

int main() {
    // 创建复数
    std::complex<double> a(3.0, 4.0); // 3 + 4i
    std::complex<double> b(1.0, 2.0); // 1 + 2i

    // 复数加法
    std::complex<double> sum = a + b;
    std::cout << "Sum: " << sum << std::endl; // 输出: Sum: (4,6)

    // 复数乘法
    std::complex<double> product = a * b;
    std::cout << "Product: " << product << std::endl; // 输出: Product: (-5,10)

    // 复数的模
    double magnitude = std::abs(a);
    std::cout << "Magnitude of a: " << magnitude << std::endl; // 输出: Magnitud e of a: 5

    return 0;
}

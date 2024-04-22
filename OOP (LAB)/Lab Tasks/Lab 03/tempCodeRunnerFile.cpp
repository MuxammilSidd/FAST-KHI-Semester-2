#include <iostream>
using namespace std;

int main() {
    int count = 0, num = 2; // Start with the first prime number, 2

    while (count < 50) {
        bool is_prime = true;

        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            cout << num << endl;
            ++count;
        }

        ++num;
    }

    return 0;
}

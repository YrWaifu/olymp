#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        result = to_string(digit) + result;
        i--;
        j--;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string num, res;
    while (cin >> num) {
        num.erase(num.find('.'), 1); 
        res = addStrings(res, num);
    }
    res.insert(res.length() - 15, ".");

    cout << res << '\n';

    return 0;
}

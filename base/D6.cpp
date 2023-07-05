#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll postf(string exp) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<ll> operands;
    stringstream ss(exp);

    string k;
    while (ss >> k) {
        if (isdigit(k[0])) {
            operands.push(stoll(k));
        } else {
            ll op2 = operands.top();
            operands.pop();
            ll op1 = operands.top();
            operands.pop();

            if (k == "+") {
                operands.push(op1 + op2);
            } else if (k == "-") {
                operands.push(op1 - op2);
            } else if (k == "*") {
                operands.push(op1 * op2);
            }
        }
    }

    return operands.top();
}

int main() {
    string exp;
    getline(cin, exp);

    ll result = postf(exp);
    cout << result << endl;

    return 0;
}

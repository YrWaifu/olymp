#include <bits/stdc++.h>

using namespace std;

int getValue(char elem) {
    vector<char> zn{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < zn.size(); i++) {
        if (zn[i] == elem) {
            return i;
        }
    }
    return -1;
}

long long toBase(int a, string nach) {
    long long res = 0;
    for (int i = nach.size() - 1; i >= 0; i--) {
        int val = getValue(nach[i]);
        res += val * pow(a, nach.size() - i - 1);
    }
    return res;
}

string fromBase(int b, long long nach) {
    string res = "";
    if (nach == 0) {
        return "0";
    }
    vector<char> zn{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while (nach > 0) {
        int l = nach % b;
        res += zn[l];
        nach /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    string nach;
    cin >> nach;
    long long sr = toBase(a, nach);
    string res = fromBase(b, sr);
    cout << res << '\n';
}
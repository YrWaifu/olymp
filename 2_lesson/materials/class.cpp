#include <bits/stdc++.h>

using namespace std;

class item {
    // private изначально
    public:
    int num;
    char word;
    void privet() {
        cout << word;
    }
    item(int n) { // конструктор, можно еще item(int n) : num(n) { word = 'a' } - список инициализации
        num = n;
        word = 'a';
    }
    ~item() {} // деструктор
};
// struct - изначально все паблик

int main() {
    int n;
    cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].num >> a[i].word;
    }
    for (item elem : a) {
        elem.privet();
        // cout << elem.num << ' ' << elem.word << '\n';
    }
}
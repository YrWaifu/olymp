#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n == 1) {
        cout << "1 1\n1 1\n1 1\n";
        return 0;
    }
    vector<int> lmin;
    vector<int> lmax;
    int kgmax = 0, gmax = -2147483647;
    int kgmin = 0, gmin = 2147483647; 
    
    if (a[0] < a[1]) {
        lmin.push_back(1);
        if (a[0] < gmin) {
            gmin = a[0];
            kgmin = 1;
        }
    }
    if (a[0] > a[1]) {
        lmax.push_back(1);
        if (a[0] > gmax) {
            gmax = a[0];
            kgmax = 1;
        }
    }
    
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            lmin.push_back(i + 1);
            if (a[i] < gmin) {
                gmin = a[i];
                kgmin = i + 1;
            }
        }
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            lmax.push_back(i + 1);
            if (a[i] > gmax) {
                gmax = a[i];
                kgmax = i + 1;
            }
        }
    }
    
    if (a[n-1] < a[n-2]) {
        lmin.push_back(n);
        if (a[n-1] < gmin) {
            gmin = a[n-1];
            kgmin = n;
        }
    }
    if (a[n-1] > a[n-2]) {
        lmax.push_back(n);
        if (a[n-1] > gmax) {
            gmax = a[n-1];
            kgmax = n;
        }
    }
    
    cout << lmin.size() << ' ';
    for (int i = 0; i < lmin.size(); i++) {
        cout << lmin[i] << ' ';
    }
    cout << '\n';
    cout << lmax.size() << ' ';
    for (int i = 0; i < lmax.size(); i++) {
        cout << lmax[i] << ' ';
    }
    cout << '\n';
    cout << kgmin << ' ' << kgmax;
}
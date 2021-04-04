#include <bits/stdc++.h>

using namespace std;

int main ()
{
    stack <int> s1, s2;
    int n, t;
    cin >> n;
    cin >> t;
    for (int i=n; i>=1; i--) {
        s1.push(i);
    }
    while(t--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            while(b > 0 && !s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                b--;
            }
        }
        else if (a == 2) {
            while(b > 0 && !s2.empty()) {
                s1.push(s2.top());
                s2.pop();
                b--;
            }
        }
        else {
            cout << "TumpukAnnya saLah! :(" << endl;
            return 0;
        }
    }
    if (s1.size() == 0 && s2.size() == 0) {
        cout << "MudMud SangaT MaraH!" << endl;
        return 0;
    }
    int cek = 2, sudah1 = 0, sudah2 = 0, done = 0;
    if (s1.size() > s2.size()) {
        cek = 1;
    }
    else if (s1.size() == s2.size()) {
        cek = 0;
    }
    while (s1.size() > 0 || s2.size() > 0) {
        if (s1.size() > 0) {
            cout << s1.top();
            s1.pop();
        }
        else {
            if (sudah1 == 0) {
                sudah1 = 1;
                if (cek == 2) {
                    cout << "-";
                }
            }
        }
        if (s2.size() > 0) {
            cout << " " << s2.top();
            s2.pop();
        }
        else {
            if (sudah2 == 0) {
                sudah2 = 1;
                if (cek == 1) {
                    cout << " :(";
                }
            }
        }
        cout << endl;
    }
}


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
fstream inp("input.txt");
ofstream out("output.txt");

vector<long long> t;
const int del = 1000003;
int N;

void build(const vector<int> &a, int i = 1, int l = 0, int r = N - 1) {
    if(l == r) {
        t[i] = a[l] % del;
        return;
    }
    else
    {
        int m = (l + r) / 2;
        build(a, i * 2, l, m);
        build(a, i * 2 + 1, m + 1, r);
        t[i] = t[i * 2] * t[i * 2 + 1] % del;
    }
}

// long long sum(int l, int r, int i = 1, int tl = 0, int tr = n - 1)
// {
//     if (l == tl && r == tr)
//         return t[i];
//     int m = (tl + tr) / 2;
//     if (r <= m)
//         return sum(l, r, i * 2, tl, m);
//     if (l > m)
//         return sum(l, r, i * 2 + 1, m + 1, tr);
//     return sum(l, m, i * 2, tl, m) + sum(m + 1, r, i * 2 + 1, m + 1, tr);
// }

int mul(int i, int l, int r, int tl, int tr) {
    if (l == tl && r == tr)
        return t[i];
    if (tl > tr)
        return 1;
    int m = (l + r) / 2;
    return 1LL * mul(i * 2, l, m, tl, min(tr, m)) * mul(i * 2 + 1, m + 1, r, max(tl, m + 1), tr) % del;
}

void update(int pos, int newval, int i = 1, int l = 0, int r = N - 1) {
    if (pos > newval) return;
    if (l == r)
        t[i] = (t[i] + 1) % del;
    else
    {
        int m = (l + r) / 2;
        update(pos, min(newval, m), i * 2, l, m);
        update(max(m + 1, pos), newval, i * 2 + 1, m + 1, r);
        t[i] = 1LL * t[i * 2] * t[i * 2 + 1] % del;
    }
}

int main() {
    int ans;
    int q;
    vector<int> a;

    inp >> N;
    a.resize(N);
    t.resize(N * 4 + 1);
    for(int i = 0; i < N; i++){
        inp >> a[i];
    }

    build(a);
    inp >> q;
    for (int i = 0; i < q; i++) {
        int aLetter, l, r;
        inp >> aLetter >> l >> r;
        if(aLetter == 1){
            ans = mul(1, 0, N - 1, l - 1, r - 1);
            out << ans << endl;
        }
        if(aLetter == 0)
            update(l - 1, r - 1);
    }
}

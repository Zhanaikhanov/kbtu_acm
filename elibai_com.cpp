#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int p[100000];
int s[100000];

int ffind(int x) {
    if (p[x] == x)
        return x;
    return ffind (p[x]);
}
void uunion (int x, int y) {
    int p1 = ffind (x);
    int p2 = ffind (y);
    if (p1 == p2)
        return;
    if (s[p1] > s[p2]) {
        p[p2] = p1;
        s[p1] += s[p2];
        s[p2] = 0;
    }
    else {
        p[p1] = p2;
        s[p2] += s[p1];
        s[p1] = 0;
    }
}
int ssize (int x) {
    return s[ffind (x)];
}
int main() {
    int n1, n2;
    cin >> n1 >> n2;
    set < int > S;
    for (int i = 1; i <= n1; ++ i)
    {
        S.insert(i);
        p[i] = i, s[i] = 1;
    }

    for (int i = 1; i <= n2; ++ i) {
        string in;
        cin>>in;
        if (in == "Q")
        {
            int x;
            cin>>x;
            cout<<ssize(x)<<endl;
        }
        else if(in == "M")
        {
            int x, y;
            cin >> x >> y;
            uunion (x, y);         
        }

    }
    return 0;
}

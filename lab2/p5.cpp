// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distintos parametros aqui.

    */
    unordered_map<string, string> m;
    string in, eng, wat;
    while (getline(cin, in)) {
        if (in == "") break;
        eng = in.substr(0, in.find(' '));
        wat = in.substr(in.find(' ') + 1);
        m[wat] = eng;
    }
    while (getline(cin, wat)) {
        if (m.find(wat) == m.end())
            cout << "eh" << endl;
        else
            cout << m[wat] << endl;
    }
    return 0;
}
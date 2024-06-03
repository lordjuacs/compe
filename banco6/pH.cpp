#include <bits/stdc++.h>
using namespace std;
/*
The only difference between easy and hard versions is the size of the input.

You are given a string s consisting of n characters, each character is 'R', 'G' or 'B'.

You are also given an integer k
. Your task is to change the minimum number of characters in the initial string s so that after the changes there will be a string of length k that is a substring of s
, and is also a substring of the infinite string "RGBRGBRGB ...".

A string a is a substring of string b if there exists a positive integer i such that a1=bi
, a2=bi+1
, a3=bi+2
, ..., a|a|=bi+|a|−1
. For example, strings "GBRG", "B", "BR" are substrings of the infinite string "RGBRGBRGB ..." while "GR", "RGR" and "GGG" are not.

You have to answer q independent queries.

*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    /// bibliografia: guide to competitive programming
    /*
        revisar:
        getline() ///hay distlong long intos parametros aqui.

    */
    string rgb = "RGB";
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int min_change = 1000000000;
        string a;
        cin >> a;
        for (int i = 0; i < 3; i++) {
            vector<char> v(n);
            for (int j = 0; j < n; j++)
                v[j] = rgb[(i + j) % 3];
            vector<int> diff(n);
            int curr = 0;
            for (int j = 0; j < n; j++)
                diff[j] = (v[j] != a[j]);
            for (int j = 0; j < k; j++)
                curr += diff[j];
            min_change = min(min_change, curr);
            for (int j = k; j < n; j++) {
                curr += (diff[j] - diff[j - k]);
                min_change = min(min_change, curr);
            }
        }
        cout << min_change << "\n";
    }

    return 0;
}
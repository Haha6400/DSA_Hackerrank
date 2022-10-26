#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findParent(int a, int parents[]) {
    if(a == parents[a]) return a;
    else return findParent(parents[a], parents);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n; cin >> n;
    int parents[n + 1], size[n + 1];
    for(int i = 0; i < n;i ++) {
        parents[i] = i;
        size[i] = 1;
    }
    int a; cin >> a;
    cin.ignore();
    string str[a];
    for(int i = 0; i < a; i++) getline(cin, str[i]);
    for(int i = 0; i < a; i++) {
        if(str[i][0] == 'M') {
            string n1 = "", n2 = "";
            int index = 2;
            for(; str[i][index] != ' '; index++) n1 += str[i][index];
            for(index += 1; index < str[i].length(); index++) n2 += str[i][index];
            int p1 = findParent(stoi(n1), parents);
            int p2 = findParent(stoi(n2), parents);
            if(p1 != p2 && size[p1] < size[p2]) swap(p1, p2);
            else if(p1 != p2) {
                size[a] += size[b];
                parents[b] = a;
            } 
        } 
        else if(str[i][0] == 'Q') {
            string num = "";
            for(int j = 2; j < str[i].size(); j++) num += str[i][j];
        }
        cout<<size[findParents(stoi(num), parents))<<endl;
        return 0;
    }
}
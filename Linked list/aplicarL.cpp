#include <bits/stdc++.h>
#include "Linked_list.hpp"

using namespace std;

int main(){
    int n, x; cin >> n;
    Linked_list lista;
    for (int i = 0; i < n ; i++){
        cin >> x;
        lista.push_back(x);
    }
    lista.pop_front();
    lista.insert_at(5,5);
    lista.remove_at(1);
    cout << lista.sum() << endl;
    for (unsigned int i = 0; i < lista.size() ; i++){
        cout << lista.get_at(i) << " ";
    }

    return 0;
}
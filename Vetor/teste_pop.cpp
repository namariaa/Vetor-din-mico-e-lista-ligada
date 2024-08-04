#include <bits/stdc++.h>
#include "Vetor_dinamico.hpp"

using namespace std;

int main(){
    Vetor_dinamico array; //é o objeto não apenas simplismente o array em si
    int x, n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        array.push_front(x); // pois estamos usando o metódo do objeto que nternamente usa um array 
    }
    auto beg = std::chrono::high_resolution_clock::now();
    array.pop_back();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Quantidade de números lidos: " << array.size() << std::endl;
    std::cout << "Tamanho do vetor: " << array.capacity() << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cerr << "Tempo de processamento: " << duration.count() << " microseconds(s)"<< std::endl;

    return 0;
}
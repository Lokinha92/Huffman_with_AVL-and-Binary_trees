#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct DataPair {
    string palavra;
    int freq;

    DataPair(const string &p, int f) : palavra(p), freq(f) {}
};

class HeapMAX {
private:
    vector<DataPair> heap;

    void prop(int index); // responsavel por manter a propriedade de Heap maxima após inserção e remoção
public:
    HeapMAX(){}

    void inserir(const DataPair& pair);

    DataPair PesquisaMAX();

    bool Vazia();

    void RemoveSugestao(const string& palavra, HeapMAX& heap, int k);

    void cleanHEAP(HeapMAX& heap);

};

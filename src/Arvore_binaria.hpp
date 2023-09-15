#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct No {
    string palavra;
    int freq;

    No *esq;
    No *dir;

    No(const string& palavra, int freq): palavra(palavra), freq(freq), esq(nullptr), dir(nullptr){}
};

class Arvore_binaria
{
private:
    No* InserirRecursivamente(No* no, const string& palavra, int freq);
public:
    No* raiz;
    Arvore_binaria();

    void Inserir(const string& palavra, int freq);
    void Imprimir(No *no, ofstream &arquivo);
    
};


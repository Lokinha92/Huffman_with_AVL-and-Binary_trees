#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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
    No* raiz;
    No* InserirRecursivamente(No* no, const string& palavra, int freq);
    bool BuscaRecursiva(No* no, const string& palavra, int& freqEncontrada);
public:
    Arvore_binaria();

    void Inserir(const string& palavra, int freq);
    bool BuscarPalavra(const string& palavra, int& frequenciaEncontrada);
    
};


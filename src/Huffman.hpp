#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct NoHuffmann
{
    string palavra;
    int freq;

    NoHuffmann* esq;
    NoHuffmann* dir;

    NoHuffmann(string p, int f) : palavra(p), freq(f), esq(nullptr), dir(nullptr){}
};

struct Compara_NO {
    bool operator()(NoHuffmann* a, NoHuffmann* b){
        return a->freq > b->freq;
    }
};

NoHuffmann* ConstruirArvore(const unordered_map<string, int>& frequencia);

void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<string, string>& codigos);

string Codificar(const string& palavra, unordered_map<string, string>& codigos);

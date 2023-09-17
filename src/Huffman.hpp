#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct NoHuffmann
{
    char letra;
    int peso;

    NoHuffmann* esq;
    NoHuffmann* dir;

    NoHuffmann(char l, int p) : letra(l), peso(p), esq(nullptr), dir(nullptr){}
};

struct Compara_NO {
    bool operator()(NoHuffmann* a, NoHuffmann* b){
        return a->peso > b->peso;
    }
};

NoHuffmann* ConstruirArvore(const unordered_map<char, int>& frequencia);

void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<char, string>& codigos);

string Codificar(const string& palavra, unordered_map<char, string>& codigos);

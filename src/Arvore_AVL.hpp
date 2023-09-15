#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct No_AVL {
    string palavra;
    int freq;

    int altura;

    No_AVL *esq;
    No_AVL *dir;

    No_AVL(const string& palavra, int freq): palavra(palavra), freq(freq), altura(0), esq(nullptr), dir(nullptr){}
};

class Arvore_AVL
{
private:
    No_AVL* Inserir_Recursivamente(No_AVL* no, const string& palavra, int freq);
public:

    No_AVL* raiz;
    Arvore_AVL();

    No_AVL* Rot_Esquerda(No_AVL* no);
    No_AVL* Rot_Direita(No_AVL* no);

    int get_altura(No_AVL* no);
    void Inserir(const string& palavra, int freq);
    void Imprimir(No_AVL* no, ofstream &arquivo);
    
};
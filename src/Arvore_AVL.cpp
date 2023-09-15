#include "Arvore_AVL.hpp"

Arvore_AVL::Arvore_AVL(){
    raiz = NULL;    
}

int Arvore_AVL::get_altura(No_AVL* no){
    if (no == NULL){
        return -1;
    }

    return no->altura;
}

No_AVL* Arvore_AVL::Rot_Direita(No_AVL* no){
    No_AVL* aux = no->esq;
    No_AVL* aux_fd = aux->dir;

    aux->dir = no;
    no->esq = aux_fd;

    no->altura = max(get_altura(no->esq), get_altura(no->dir)) + 1;
    aux->altura = max(get_altura(aux->esq), get_altura(aux->dir)) + 1;

    return aux;
}

No_AVL* Arvore_AVL::Rot_Esquerda(No_AVL* no){
    No_AVL* aux = no->dir;
    No_AVL* aux_fe = aux->esq;

    aux->esq = no;
    no->dir = aux_fe;

    no->altura = max(get_altura(no->esq), get_altura(no->dir)) + 1;
    aux->altura = max(get_altura(aux->esq), get_altura(aux->dir)) + 1;

    return aux;
}

No_AVL* Arvore_AVL::Inserir_Recursivamente(No_AVL* no, const string& palavra, int freq){
    if(no == NULL){
        return new No_AVL{palavra ,freq};
    }

    int score = freq - (2 * palavra.length());

    int compara_score = score - (no->freq - (2 * no->palavra.length()));

    if(compara_score <= 0){
        no->esq = Inserir_Recursivamente(no->esq, palavra, freq);
    } else{
        no->dir = Inserir_Recursivamente(no->dir, palavra, freq);
    }

    no->altura = 1 + max(get_altura(no->esq), get_altura(no->dir)); // atualizando altura do nó

    int fat_balanco = get_altura(no->esq) - get_altura(no->dir); // calculando fator de balanço

    // rotações

    if(fat_balanco > 1 && compara_score <=0){ // o nó foi inserido na sub-arvore esquerda do filho da esquerda
        return Rot_Direita(no);
    }

    if(fat_balanco < -1 && compara_score > 0){ // o nó foi inserido na sub-arvore direita do filho da direita
        return Rot_Esquerda(no);
    }

    if(fat_balanco > 1 && compara_score > 0){ // o nó foi inserido na sub-arvore direita do filho a esquerda
        no->esq = Rot_Esquerda(no->esq);
        return Rot_Direita(no);
    }

    if(fat_balanco < -1 && compara_score <=0){ // o nó foi inserido na sub-arvore esquerda do filho a direita
        no->dir = Rot_Direita(no->dir);
        return Rot_Esquerda(no);
    }

    return no;
}

void Arvore_AVL::Inserir(const string& palavra, int freq){
    raiz = Inserir_Recursivamente(raiz, palavra, freq);
}

void Arvore_AVL::Imprimir(No_AVL* no, ofstream &arquivo) {

    if(arquivo.is_open()){
        if (no != nullptr) {
        arquivo << no->palavra << " : " << no->freq << ", ";
        Imprimir(no->esq, arquivo);
        Imprimir(no->dir, arquivo);
    }
    }
}
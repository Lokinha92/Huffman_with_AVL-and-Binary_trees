#include "Arvore_binaria.hpp"

Arvore_binaria::Arvore_binaria(){
    raiz = NULL;
}

No* Arvore_binaria::InserirRecursivamente(No* no, const string& palavra, int freq){
    if(no == NULL){
        return new No{palavra,freq};
    }

    int compara_palavra = palavra.compare(no->palavra);

    if(compara_palavra < 0){
        no->esq = InserirRecursivamente(no->esq, palavra, freq);
    } else if(compara_palavra > 0){
        no->dir = InserirRecursivamente(no->dir, palavra, freq);
    } else{
        no->freq = freq;
    }

    return no;
}

void Arvore_binaria::Inserir(const string& palavra, int freq){
    raiz = InserirRecursivamente(raiz, palavra, freq);
}

bool Arvore_binaria::BuscaRecursiva(No* no, const string& palavra, int& freqEncontrada) {
    if (no == nullptr) {
        return false; // Palavra não encontrada na árvore.
    }

    int comparacao = palavra.compare(no->palavra);

    if (comparacao == 0) {
        // A palavra foi encontrada na árvore.
        freqEncontrada = no->freq;
        return true;
    } else if (comparacao < 0) {
        // A palavra pode estar na subárvore esquerda.
        return BuscaRecursiva(no->esq, palavra, freqEncontrada);
    } else {
        // A palavra pode estar na subárvore direita.
        return BuscaRecursiva(no->dir, palavra, freqEncontrada);
    }
}

bool Arvore_binaria::BuscarPalavra(const string& palavra, int& frequenciaEncontrada){
    return BuscaRecursiva(raiz, palavra, frequenciaEncontrada);
}

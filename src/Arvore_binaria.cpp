#include "Arvore_binaria.hpp"

Arvore_binaria::Arvore_binaria() {
    raiz = NULL;
}

No *Arvore_binaria::InserirRecursivamente(No *no, const string &palavra, int freq) {
    if (no == NULL) {
        return new No{ palavra, freq };
    }

    int score = freq - (2 * palavra.length());

    int compara_score = score - (no->freq - (2 * no->palavra.length()));

    if (compara_score <= 0) {
        no->esq = InserirRecursivamente(no->esq, palavra, freq);
    } else {
        no->dir = InserirRecursivamente(no->dir, palavra, freq);
    }

    return no;
}

void Arvore_binaria::Inserir(const string &palavra, int freq) {
    raiz = InserirRecursivamente(raiz, palavra, freq);
}

bool Arvore_binaria::BuscaRecursiva(No *no, const string &palavra, int &freqEncontrada) {
    if (no == NULL) {
        return false;
    }

    int comparacao = palavra.compare(no->palavra);

    if (comparacao == 0) {
        freqEncontrada = no->freq;
        return true;
    } else if (comparacao < 0) {
        return BuscaRecursiva(no->esq, palavra, freqEncontrada);
    } else {
        return BuscaRecursiva(no->dir, palavra, freqEncontrada);
    }
}

bool Arvore_binaria::BuscarPalavra(const string &palavra, int &frequenciaEncontrada) {
    return BuscaRecursiva(raiz, palavra, frequenciaEncontrada);
}
void Arvore_binaria::Imprimir(No *no, ofstream &arquivo) {
    if (arquivo.is_open()) {
        if (no != NULL) {
            arquivo << no->palavra << " : " << no->freq << ", ";
            Imprimir(no->esq, arquivo);
            Imprimir(no->dir, arquivo);
        }
    }
}
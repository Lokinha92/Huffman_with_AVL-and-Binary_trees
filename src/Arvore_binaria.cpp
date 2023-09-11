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

void Arvore_binaria::BuscaRecursiva(No* no, const string& prefix, vector<string>& sugestoes, int numsugestoes){
    if(no == NULL || sugestoes.size() >= numsugestoes){
        return;
    }

    int compara = no->palavra.compare(0, prefix.length(), prefix); // compara o prefixo com a palavra do no atual

    if(compara >=0){
        sugestoes.push_back(no->palavra);
    }

    if(compara >=0 || prefix.compare(0, no->palavra.length(), no->palavra) >=0){ // se o prefixo é menor ou igual a palavra, continua a buscar nos filhos
        BuscaRecursiva(no->esq, prefix, sugestoes, numsugestoes);
        BuscaRecursiva(no->dir, prefix, sugestoes, numsugestoes);
    }
}

vector<string> Arvore_binaria::Recomendar_Palavras(const string& prefix, int numsugestoes){
    vector<string> sugestoes;
    BuscaRecursiva(raiz, prefix, sugestoes, numsugestoes);

    return sugestoes;
}


// funções de teste da estrutura

bool Arvore_binaria::BuscarPalavraRecursivamente(No* no, const string& palavra, int& freqEncontrada) {
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
        return BuscarPalavraRecursivamente(no->esq, palavra, freqEncontrada);
    } else {
        // A palavra pode estar na subárvore direita.
        return BuscarPalavraRecursivamente(no->dir, palavra, freqEncontrada);
    }
}

bool Arvore_binaria::BuscarPalavra(const string& palavra, int& frequenciaEncontrada){
    return BuscarPalavraRecursivamente(raiz, palavra, frequenciaEncontrada);
}

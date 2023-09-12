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

void Arvore_binaria::BuscaPrefix(No* no, const string& prefix, vector<string>& sugestoes, int numsugestoes){
    if(no == NULL || sugestoes.size() >= numsugestoes){
        return;
    }

    int compara = no->palavra.compare(0, prefix.length(), prefix); // compara o prefixo com a palavra do no atual

    if(compara >=0){
        sugestoes.push_back(no->palavra);
    }

    if(compara >=0 || prefix.compare(0, no->palavra.length(), no->palavra) >=0){ // se o prefixo é menor ou igual a palavra, continua a buscar nos filhos
        BuscaPrefix(no->esq, prefix, sugestoes, numsugestoes);
        BuscaPrefix(no->dir, prefix, sugestoes, numsugestoes);
    }
}

int Arvore_binaria::CorrespondenciaComPrefixo(const string& sugestao, const string& prefixo){
    int correspondencia = 0;

    // Determinar o limite do loop com base no tamanho da sugestão ou do prefixo (o menor deles).
    int limite = min(sugestao.length(), prefixo.length());

    // Comparar os caracteres um a um até encontrar uma diferença.
    for (int i = 0; i < limite; ++i) {
        if (sugestao[i] == prefixo[i]) {
            correspondencia++; // Caracteres correspondem.
        } else {
            break; // Encontrou uma diferença, parar a verificação.
        }
    }

    return correspondencia;
}

vector<string> Arvore_binaria::Recomendar_Palavras(const string& prefix, int numsugestoes){
    vector<string> sugestoes;
    vector<pair<string, int>> sugestoesPontuadas;

    BuscaPrefix(raiz, prefix, sugestoes, numsugestoes);

    for (const string& sugestao : sugestoes) {
        int freqEncontrada = 0;
        if (BuscarPalavra(sugestao, freqEncontrada)) {
            // Calcule a pontuação com base na frequência e na correspondência com o prefixo.
            int correspondencia = CorrespondenciaComPrefixo(sugestao, prefix);
            float aplha = 0.32, beta = sugestao.length()*2.75;
            int pontuacao = (freqEncontrada * aplha) + (correspondencia * beta); // se a recomendação ficar zuada, mexer aq

            // Adicione a sugestão ponderada à lista de sugestões com pontuação.
            sugestoesPontuadas.push_back(make_pair(sugestao, pontuacao));

            // for(const auto& par: sugestoesPontuadas){
            //     cout << par.first << " " << par.second << endl;
            // } // testando a pontuação
        }
    }

    // Ordene as sugestões com base nas pontuações, da maior para a menor.
    sort(sugestoesPontuadas.begin(), sugestoesPontuadas.end(),[](const pair<string, int>& a, const pair<string, int>& b) {return a.second > b.second;});

    // Transforme as sugestões ponderadas de volta em uma lista de strings.
    vector<string> sugestoesFinais;
    for (const auto& sugestaoPontuada : sugestoesPontuadas) {
        sugestoesFinais.push_back(sugestaoPontuada.first);
    }

    return sugestoesFinais;
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

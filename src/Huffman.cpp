#include "Huffman.hpp"

NoHuffmann* ConstruirArvore(const unordered_map<string, int>& frequencia){
    priority_queue<NoHuffmann*, vector<NoHuffmann*> ,Compara_NO> filaPrioridade;

    for(const auto& item : frequencia){
        filaPrioridade.push(new NoHuffmann(item.first, item.second));
    }

    while(filaPrioridade.size() > 1){
        NoHuffmann* esq = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* dir = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* pai = new NoHuffmann("", esq->freq + dir->freq);
        pai->esq = esq;
        pai->dir = dir;

        filaPrioridade.push(pai);
    }

    return filaPrioridade.top();
}

void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<string, string>& codigos){
    if(!raiz){
        return;
    }

    if(!raiz->palavra.empty()){
        codigos[raiz->palavra] = codigo;
    }

    gerarCodigosHuffman(raiz->esq, codigo + "0", codigos);
    gerarCodigosHuffman(raiz->dir, codigo + "1", codigos);
}

string Codificar(const string& palavra, unordered_map<string, string>& codigos) {
    if (codigos.find(palavra) != codigos.end()) {
        return codigos.at(palavra);
    } else {
        return palavra;
    }
}
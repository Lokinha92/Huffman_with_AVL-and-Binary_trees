#include "Huffman.hpp"

NoHuffmann* ConstruirArvore(const unordered_map<char, int>& frequencia){
    priority_queue<NoHuffmann*, vector<NoHuffmann*> ,Compara_NO> filaPrioridade;

    for(const auto& item : frequencia){
        filaPrioridade.push(new NoHuffmann(item.first, item.second));
    }

    while(filaPrioridade.size() > 1){
        NoHuffmann* esq = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* dir = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* pai = new NoHuffmann('\0', esq->peso + dir->peso);
        pai->esq = esq;
        pai->dir = dir;

        filaPrioridade.push(pai);
    }

    return filaPrioridade.top();
}

void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<char, string>& codigos){
    if(!raiz){
        return;
    }

    if(raiz->letra != '\0'){
        codigos[raiz->letra] = codigo;
    }

    gerarCodigosHuffman(raiz->esq, codigo + "0", codigos);
    gerarCodigosHuffman(raiz->dir, codigo + "1", codigos);
}

string Codificar(const string& palavra, unordered_map<char, string>& codigos){
    string codigo = "";

    for(char c : palavra){
        if(codigos.find(c) != codigos.end()){
            codigo += codigos.at(c);
        }
    }

    return codigo;
}
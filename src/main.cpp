#include "functions.hpp"
#include <chrono>

#define NUM_SUGESTOES 5

int main() {
    Apaga_output("../output");

    string loc_nomes = "../dataset/nome_txt.txt";
    string prefix = "../dataset/";
    string nomes;
    vector<string> caminhos;
    vector<string> nome_arquivos;

    fstream arquivos(loc_nomes);

    if (arquivos.is_open()) {
        while (arquivos >> nomes) {
            string caminho = prefix + nomes;

            caminhos.push_back(caminho);
            nome_arquivos.push_back(nomes);

            caminho = "";
        }

        arquivos.close();
    }

    unordered_set<string> Stopwords = LeStopwords("../dataset/stopwords.txt");
    vector<string> textos = LeTexto(caminhos);

    vector<string> textos_tratados;

    for (const auto &texto : textos) {
        string texto_tratado = Tratamento(texto);
        string texto_final = RemoveSW(texto_tratado, Stopwords);

        textos_tratados.push_back(texto_final);

        texto_tratado = "";
        texto_final = "";
    }

    vector<pair<string, string>> par_nome_texto;

    for (int i = 0; i < textos_tratados.size(); i++) {
        par_nome_texto.push_back(make_pair(nome_arquivos[i], textos_tratados[i]));
    }

    fstream palavras("../dataset/palavra.txt");

    if (palavras.is_open()) {
        string palavra_pesq;
        double tempo_total_binaria = 0.0;
        double tempo_total_avl = 0.0;
        double tempo_total_huff = 0.0;

        while (palavras >> palavra_pesq) {
            auto start_binaria = chrono::high_resolution_clock::now();
            ProcessarPalavrasArvoreBinaria(par_nome_texto, palavra_pesq, NUM_SUGESTOES);
            auto end_binaria = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_binaria = end_binaria - start_binaria;
            tempo_total_binaria += elapsed_binaria.count();

            auto start_avl = chrono::high_resolution_clock::now();
            ProcessarPalavrasArvoreAVL(par_nome_texto, palavra_pesq, NUM_SUGESTOES);
            auto end_avl = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_avl = end_avl - start_avl;
            tempo_total_avl += elapsed_avl.count();

            auto start_huff = chrono::high_resolution_clock::now();
            ProcessarPalavrasHuffman(par_nome_texto, palavra_pesq, NUM_SUGESTOES);
            auto end_huff = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_huff = end_huff - start_huff;
            tempo_total_huff += elapsed_huff.count();
        }

        cout << "Tempo total decorrido com Árvore Binária: " << tempo_total_binaria << " segundos" << endl;
        cout << "Tempo total decorrido com Árvore AVL: " << tempo_total_avl << " segundos" << endl;
        cout << "Tempo total decorrido com Codificação de Huffman: " << tempo_total_huff << " segundos" << endl;

        palavras.close();
    }
    return 0;
}

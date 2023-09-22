#include "functions.hpp"
#include <chrono>

#define NUM_SUGESTOES 10

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

        while (palavras >> palavra_pesq) {
            ProcessarPalavrasArvoreBinaria(par_nome_texto, palavra_pesq, NUM_SUGESTOES);

            ProcessarPalavrasArvoreAVL(par_nome_texto, palavra_pesq, NUM_SUGESTOES);
        }
        palavras.close();
    }
    return 0;
}

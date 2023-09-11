#include "functions.hpp"
#include "Arvore_binaria.hpp"
#include <chrono>

#define NUM_SUGESTOES 4

int main() {

    string loc_nomes = "../dataset/nome_txt.txt";
    string prefix = "../dataset/";
    string nomes;
    vector<string> caminhos;

    fstream arquivos(loc_nomes);

    if (arquivos.is_open()) {
        while (arquivos >> nomes) {
            string caminho = prefix + nomes;

            caminhos.push_back(caminho);

            caminho = "";
        }

        arquivos.close();

    }


    vector<string> textos = LeTexto(caminhos);

    string textos_concatenados = Concatena(textos);

    unordered_set<string> stopwords = LeStopwords("../dataset/stopwords.txt");

    string texto_tratado = Tratamento(textos_concatenados);

    string texto_semSW = RemoveSW(texto_tratado, stopwords);

    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);

    //------------------------------------------------- arvore binaria

    chrono::high_resolution_clock::time_point inicio_bt;
    chrono::high_resolution_clock::time_point fim_bt;

    inicio_bt = chrono::high_resolution_clock::now();

    Arvore_binaria Binary_tree;

    for (const auto &item : frequencia) {
        Binary_tree.Inserir(item.first, item.second);
    }


    // TESTE DA ESTRUTURA

    // int frequenciaEncontrada;
    // string palavraVerificar = "cria"; // Substitua com a palavra que você deseja verificar.

    // if (Binary_tree.BuscarPalavra(palavraVerificar, frequenciaEncontrada)) {
    //     cout << "Palavra encontrada na árvore com frequência: " << frequenciaEncontrada << endl;
    // } else {
    //     cout << "Palavra não encontrada na árvore." << endl;
    // }

    // FIM DO TESTE

    string prefixo = "cod";

    vector<string> sugestoes = Binary_tree.Recomendar_Palavras(prefixo, NUM_SUGESTOES);

    cout << "Sugestão de palavras com base no prefixo " << prefixo << ":" << endl;
    for(const string& sugestao : sugestoes){
        cout << sugestao << endl;
    }

    fim_bt = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::microseconds>(fim_bt - inicio_bt);

    cout<<"Tempo total para execução do algoritmo utilizando arvore binária em microsegundos: "<<duracao.count()<< "ms" << endl;

    // ------------------------------------------------------------------ fim arvore binaria

    return 0;
}
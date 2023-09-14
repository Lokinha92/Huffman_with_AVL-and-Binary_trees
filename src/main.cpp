#include "functions.hpp"
#include "Arvore_binaria.hpp"
#include <chrono>

int main() {

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

    string palavra_pesq;
    cout << "Informe a palavra a ser pesquisada: ";
    cin >> palavra_pesq; cout << endl << endl;

    auto inicio_bt = chrono::high_resolution_clock::now();
    for (const auto &par : par_nome_texto) {
        if (NoTexto(par.second, palavra_pesq)) {
            cout << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;

            unordered_map<string, int> frequencia = ContaFrequencia(par.second);
            Arvore_binaria Binary_tree = Arvore_binaria();

            for (const auto &item : frequencia) {
                Binary_tree.Inserir(item.first, item.second);
            }

            int freq_encontrada = 0;
            if(Binary_tree.BuscarPalavra(palavra_pesq, freq_encontrada)){
                cout << " A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl << endl;
            }

            freq_encontrada = 0;
            frequencia.clear();

            cout << "Arvore Binária em Pré-Ordem: " << endl;
            cout << "[ ";
            Binary_tree.Imprimir(Binary_tree.raiz);
            cout << "]" << endl;
            cout << "----------------------------------------------------" << endl << endl;
        }
    }
    auto fim_bt = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::milliseconds>(fim_bt - inicio_bt);
    cout << "Tempo decorrido: " << duracao.count() << " ms" << endl;




    return 0;
}
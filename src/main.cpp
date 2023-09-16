#include "functions.hpp"
#include "Arvore_binaria.hpp"
#include "Arvore_AVL.hpp"
#include "HeapMAX.hpp"
#include <algorithm>
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

        while (palavras >> palavra_pesq) {
            for (const auto &par : par_nome_texto) {
                if (NoTexto(par.second, palavra_pesq)) {


                    unordered_map<string, int> frequencia = ContaFrequencia(par.second);

                    int freq_encontrada = 0;

                    if (frequencia.find(palavra_pesq) != frequencia.end()) {
                        freq_encontrada = frequencia[palavra_pesq];
                    }


                    // ^^^ verifica se a palavra está no texto e armazena a frequencia

                    HeapMAX Heap_bt;
                    HeapMAX Heap_avl;

                    for (const auto &item : frequencia) {
                        Heap_bt.inserir(DataPair(item.first, item.second));
                    }

                    for (const auto &item : frequencia) {
                        Heap_avl.inserir(DataPair(item.first, item.second));
                    }


                    Heap_bt.RemoveSugestao(palavra_pesq, Heap_bt, NUM_SUGESTOES);
                    Heap_avl.RemoveSugestao(palavra_pesq, Heap_avl, NUM_SUGESTOES);

                    // ^^^ monta a heap e remove a palavra pesq das k mais freq se ela tiver lá

                    Arvore_binaria Binary_tree = Arvore_binaria();
                    Arvore_AVL AVL_tree = Arvore_AVL();

                    for (int i = 0; i < NUM_SUGESTOES && !Heap_bt.Vazia(); ++i) {
                        DataPair pair_bt = Heap_bt.PesquisaMAX();
                        Binary_tree.Inserir(pair_bt.palavra, pair_bt.freq);
                    }

                    for (int i = 0; i < NUM_SUGESTOES && !Heap_avl.Vazia(); ++i) {
                        DataPair pair_avl = Heap_avl.PesquisaMAX();
                        AVL_tree.Inserir(pair_avl.palavra, pair_avl.freq);
                    }


                    Heap_bt.cleanHEAP(Heap_bt);
                    Heap_avl.cleanHEAP(Heap_avl);

                    // joga os k mais frequentes pras arvores e limpa a heap ^^^

                    frequencia.clear();

                    // daqui pra baixo, só impressão do output

                    string caminho = "../output/output_" + par.first;

                    ofstream output(caminho, ios::app);

                    if (output.is_open()) {
                        output << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;
                        output << "A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl;
                        output << "\nArvore Binária em Pré-Ordem: " << endl;
                        output << "[ ";
                        Binary_tree.Imprimir(Binary_tree.raiz, output);
                        output << "]" << endl;

                        output << "\nArvore AVL em Pré-Ordem: " << endl;
                        output << "[ ";
                        AVL_tree.Imprimir(AVL_tree.raiz, output);
                        output << "]" << endl;

                        output << "------------------------------------------------" << endl << endl;

                        output.close();
                    }
                }
            }
        }

        palavras.close();
    }
    return 0;
}
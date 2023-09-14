#include "functions.hpp"
#include "Arvore_binaria.hpp"
#include "HeapMAX.hpp"
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


                    // ^^^ verifica se a palavra está no texto e se tiver mostra em que texto foi encontrado, e a freq.

                    HeapMAX Heap;

                    for (const auto &item : frequencia) {
                        Heap.inserir(DataPair(item.first, item.second));
                    }

                    Heap.RemoveSugestao(palavra_pesq, Heap, NUM_SUGESTOES);

                    // ^^^ monta a heap e remove a palavra pesq das k mais freq se ela tiver lá

                    Arvore_binaria Binary_tree = Arvore_binaria();

                    for (int i = 0; i < NUM_SUGESTOES && !Heap.Vazia(); ++i) {
                        DataPair pair = Heap.PesquisaMAX();
                        Binary_tree.Inserir(pair.palavra, pair.freq);
                    }

                    Heap.cleanHEAP(Heap);

                    // joga os k mais frequentes pra arvore e limpa a heap ^^^

                    frequencia.clear();

                    string caminho = "../output/output_" + par.first;

                    ofstream output(caminho, ios::app);

                    if (output.is_open()) {
                        output << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;
                        output << "A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl;
                        output << "\nArvore Binária em Pré-Ordem: " << endl;
                        output << "[ ";
                        Binary_tree.Imprimir(Binary_tree.raiz, output);
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
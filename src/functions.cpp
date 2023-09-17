#include "functions.hpp"


vector<string> LeTexto(vector<string> entradas) {
    vector<string> textos;
    string conteudo;

    for (int i = 0; i < entradas.size(); i++) {
        fstream arquivo(entradas[i]);


        if (arquivo.is_open()) {
            string linha;

            while (getline(arquivo, linha)) {
                conteudo += linha + "\n";
            }

            textos.push_back(conteudo);

            conteudo = "";

            arquivo.close();
        } else {
            cout << "Erro ao abrir arquivo" << endl;
        }
    }

    return textos;
}

string Tratamento(const string &texto) {
    string Texto_tratado = texto;

    transform(Texto_tratado.begin(), Texto_tratado.end(), Texto_tratado.begin(), ::tolower); // minusculas

    replace(Texto_tratado.begin(), Texto_tratado.end(), '-', ' '); // substituindo hifen por espaço

    Texto_tratado.erase(remove_if(Texto_tratado.begin(), Texto_tratado.end(), ::ispunct), Texto_tratado.end()); // tirando pontos

    return Texto_tratado;
}

unordered_set<string> LeStopwords(const string &caminhoArquivo) {
    unordered_set<string> stopwords;
    ifstream arquivo(caminhoArquivo);

    if (arquivo.is_open()) {
        string palavra;

        while (arquivo >> palavra) {
            stopwords.insert(palavra);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir arquivo txt" << endl;
    }

    return stopwords;
}

string RemoveSW(const string &textoTratado, unordered_set<string> &stopwords) {
    stringstream separador(textoTratado);
    string palavra;
    string texto_semSW;

    while (separador >> palavra) {
        if (stopwords.find(palavra) == stopwords.end()) {
            texto_semSW += palavra + " ";
        }
    }

    return texto_semSW;
}

unordered_map<string, int> ContaFrequencia(const string &texto) {
    unordered_map<string, int> palavras;

    istringstream separador(texto);
    string palavra;

    while (separador >> palavra) {
        if (palavras.find(palavra) == palavras.end()) {
            palavras[palavra] = 1;
        } else {
            palavras[palavra]++;
        }
    }

    return palavras;
}

unordered_map<char, int> ContaFrequencia_char(const string &texto) {
    unordered_map < char, int > caracteres;

    for (char c : texto) {
        if (caracteres.find(c) == caracteres.end()) {
            caracteres[c] = 1;
        } else {
            caracteres[c]++;
        }
    }

    return caracteres;
}

bool NoTexto(const string &texto, const string &palavra) {
    istringstream separador(texto);
    string palavra_notxt;

    while (separador >> palavra_notxt) {
        if (palavra == palavra_notxt) {
            return true;
        }
    }

    return false;
}

void Apaga_output(const string &caminho) {

    namespace fs = filesystem;


    try {
        if (fs::is_empty(caminho)) {
            cout << "A pasta está vazia, a execução pode começar" << endl;
            return;
        }

        for (const auto &entry : fs::directory_iterator(caminho)) {
            if (fs::is_regular_file(entry)) {
                fs::remove(entry);
            } else if (fs::is_directory(entry)) {
                fs::remove_all(entry);
            }
        }

        cout << "Itens da pasta excluídos com sucesso! Execução começando..." << endl;
    }
    catch (const exception &ex) {
        cerr << "Erro ao excluir itens da pasta de output: " << ex.what() << endl;
    }
}

void ProcessarPalavrasArvoreBinaria(const vector<pair<string, string>> &par_nome_texto, const string &palavra_pesq, int NUM_SUGESTOES) {
    for (const auto &par : par_nome_texto) {
        if (NoTexto(par.second, palavra_pesq)) {
            unordered_map<string, int> frequencia = ContaFrequencia(par.second);
            int freq_encontrada = 0;

            if (frequencia.find(palavra_pesq) != frequencia.end()) {
                freq_encontrada = frequencia[palavra_pesq];
            }

            HeapMAX Heap_bt;

            for (const auto &item : frequencia) {
                Heap_bt.inserir(DataPair(item.first, item.second));
            }

            Heap_bt.RemoveSugestao(palavra_pesq, Heap_bt, NUM_SUGESTOES);

            Arvore_binaria Binary_tree = Arvore_binaria();

            for (int i = 0; i < NUM_SUGESTOES && !Heap_bt.Vazia(); ++i) {
                DataPair pair_bt = Heap_bt.PesquisaMAX();
                Binary_tree.Inserir(pair_bt.palavra, pair_bt.freq);
            }

            Heap_bt.cleanHEAP(Heap_bt);

            frequencia.clear();

            string caminho = "../output/output_" + par.first;

            ofstream output(caminho, ios::app);

            if (output.is_open()) {
                output << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;
                output << "A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl;
                output << "\nArvore Binária em Pré-Ordem: " << endl;
                output << "[ ";
                Binary_tree.Imprimir(Binary_tree.raiz, output);
                output << "]" << endl << endl;;
                output.close();
            }
        }
    }
}

void ProcessarPalavrasArvoreAVL(const vector<pair<string, string>> &par_nome_texto, const string &palavra_pesq, int NUM_SUGESTOES) {
    for (const auto &par : par_nome_texto) {
        if (NoTexto(par.second, palavra_pesq)) {
            unordered_map<string, int> frequencia = ContaFrequencia(par.second);
            int freq_encontrada = 0;

            if (frequencia.find(palavra_pesq) != frequencia.end()) {
                freq_encontrada = frequencia[palavra_pesq];
            }

            HeapMAX Heap_avl;

            for (const auto &item : frequencia) {
                Heap_avl.inserir(DataPair(item.first, item.second));
            }

            Heap_avl.RemoveSugestao(palavra_pesq, Heap_avl, NUM_SUGESTOES);

            Arvore_AVL AVL_tree = Arvore_AVL();

            for (int i = 0; i < NUM_SUGESTOES && !Heap_avl.Vazia(); ++i) {
                DataPair pair_avl = Heap_avl.PesquisaMAX();
                AVL_tree.Inserir(pair_avl.palavra, pair_avl.freq);
            }

            Heap_avl.cleanHEAP(Heap_avl);

            frequencia.clear();

            string caminho = "../output/output_" + par.first;

            ofstream output(caminho, ios::app);

            if (output.is_open()) {
                output << "Arvore AVL em Pré-Ordem: " << endl;
                output << "[ ";
                AVL_tree.Imprimir(AVL_tree.raiz, output);
                output << "]" << endl << endl;
                output.close();
            }
        }
    }
}

void ProcessarPalavrasHuffman(const vector<pair<string, string>> &par_nome_texto, const string &palavra_pesq, int NUM_SUGESTOES) {
    for (const auto &par : par_nome_texto) {
        if (NoTexto(par.second, palavra_pesq)) {
            unordered_map<string, int> frequencia = ContaFrequencia(par.second);
            int freq_encontrada = 0;

            if (frequencia.find(palavra_pesq) != frequencia.end()) {
                freq_encontrada = frequencia[palavra_pesq];
            }

            HeapMAX Heap_huff;

            for (const auto &item : frequencia) {
                Heap_huff.inserir(DataPair(item.first, item.second));
            }

            Heap_huff.RemoveSugestao(palavra_pesq, Heap_huff, NUM_SUGESTOES);

            unordered_map<char, int> freq_char = ContaFrequencia_char(par.second);

            NoHuffmann *raiz = ConstruirArvore(freq_char);

            unordered_map<char, string> codigos;
            gerarCodigosHuffman(raiz, "", codigos);

            string caminho = "../output/output_" + par.first;

            ofstream output(caminho, ios::app);

            if (output.is_open()) {
                output << NUM_SUGESTOES << " palavras mais frequentes, seguidas da sua codificação: " << endl;

                for (int i = 0; i < NUM_SUGESTOES && !Heap_huff.Vazia(); i++) {
                    DataPair pair_huff = Heap_huff.PesquisaMAX();
                    string codigo_pal = Codificar(pair_huff.palavra, codigos);

                    output << pair_huff.palavra << " : " << codigo_pal << endl;
                }

                output << "------------------------------------------------" << endl << endl;
                output.close();
            }

            frequencia.clear();
            Heap_huff.cleanHEAP(Heap_huff);
            freq_char.clear();
            codigos.clear();
        }
    }
}

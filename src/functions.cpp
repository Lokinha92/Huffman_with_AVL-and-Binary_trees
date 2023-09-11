#include "functions.hpp"


vector<string> LeTexto(vector<string> entradas){
    vector<string> textos;
    string conteudo;

    for(int i=0; i<entradas.size(); i++){
        fstream arquivo(entradas[i]);
        

        if(arquivo.is_open()){
            string linha;

            while(getline(arquivo, linha)){
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

string Concatena(vector<string> textos){
    string textos_concatenados;

    for(int i=0; i<textos.size(); i++){
        textos_concatenados += textos[i] + "\n";
    }

    return textos_concatenados;
}

string Tratamento(const string& texto){
    string Texto_tratado = texto;

    transform(Texto_tratado.begin(), Texto_tratado.end(), Texto_tratado.begin(), ::tolower); // minusculas

    replace(Texto_tratado.begin(), Texto_tratado.end(), '-', ' '); // substituindo hifen por espaço

    Texto_tratado.erase(remove_if(Texto_tratado.begin(), Texto_tratado.end(), ::ispunct), Texto_tratado.end()); // tirando pontos

    return Texto_tratado;
}

unordered_set<string> LeStopwords(const string& caminhoArquivo){
    unordered_set<string> stopwords;
    ifstream arquivo(caminhoArquivo);

    if(arquivo.is_open()){
        string palavra;

        while(arquivo >> palavra){
            stopwords.insert(palavra);
        }
        arquivo.close();
    } else{
        cout << "Erro ao abrir arquivo txt" << endl;
    }

    return stopwords;
}

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords){
    stringstream separador(textoTratado);
    string palavra;
    string texto_semSW;

    while(separador >> palavra){
        if(stopwords.find(palavra) == stopwords.end()){
            texto_semSW += palavra + " ";
        }
    }

    return texto_semSW;
}

unordered_map<string, int> ContaFrequencia(const string& texto){
    unordered_map<string, int> palavras;

    istringstream separador(texto);
    string palavra;

    while(separador >> palavra){
        palavras[palavra]++;
    }

    return palavras;
}
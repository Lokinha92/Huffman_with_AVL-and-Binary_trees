#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <filesystem>
#include "Arvore_AVL.hpp"
#include "Arvore_binaria.hpp"
#include "Huffman.hpp"
#include "HeapMAX.hpp"
#include <algorithm>
#include <chrono>

using namespace std;


vector<string> LeTexto(vector<string> entradas);
string Tratamento(const string& texto);

unordered_set<string> LeStopwords(const string& caminhoArquivo);

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords);

unordered_map<string, int> ContaFrequencia(const string& texto);

unordered_map<char, int> ContaFrequencia_char(const string &texto);

bool NoTexto(const string& texto, const string& palavra);

void Apaga_output(const string& caminho);

void ProcessarPalavrasArvoreBinaria(const vector<pair<string, string>>& par_nome_texto, const string& palavra_pesq, int NUM_SUGESTOES);

void ProcessarPalavrasArvoreAVL(const vector<pair<string, string>>& par_nome_texto, const string& palavra_pesq, int NUM_SUGESTOES);

void ProcessarPalavrasHuffman(const vector<pair<string, string>>& par_nome_texto, const string& palavra_pesq, int NUM_SUGESTOES);
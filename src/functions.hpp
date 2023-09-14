#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <filesystem>
using namespace std;


vector<string> LeTexto(vector<string> entradas);
string Concatena(vector<string> textos);
string Tratamento(const string& texto);

unordered_set<string> LeStopwords(const string& caminhoArquivo);

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords);

unordered_map<string, int> ContaFrequencia(const string& texto);

bool NoTexto(const string& texto, const string& palavra);

void Apaga_output(const string& caminho);
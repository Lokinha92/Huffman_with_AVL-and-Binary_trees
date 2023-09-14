#include "HeapMAX.hpp"

void HeapMAX::prop(int index){

    int maior = index;
    long unsigned int esq = 2 * index + 1; // calculando valor do filho da esquerda do indice em questao (index)
    long unsigned int dir = 2 * index + 2; // calculando valor do filho da direita

    if(esq < heap.size() && heap[esq].freq > heap[maior].freq){
        maior = esq;
    }

    if(dir < heap.size() && heap[dir].freq > heap[maior].freq){
        maior = dir;
    }

    if(maior != index){
        swap(heap[index], heap[maior]);
        prop(maior); // recursividade aq, e é repetida até que a propriedade seja mantida para todos os nós
    }
}


void HeapMAX::inserir(const DataPair& pair){

    heap.push_back(pair);

    int index = heap.size() - 1; // posicao do novo elemento

    while(index > 0 && heap[index].freq > heap[(index - 1)/2].freq){ // executa enquanto o indice não é o nó raiz (0)
                                                                     // e enquanto a freq do atual é maior que o do pai
        swap(heap[index], heap[(index - 1)/2]); // troca o nó de lugar
        index = (index - 1)/2; // atualiza o indice do atual pro do maior anterior (pai)
    }
}

DataPair HeapMAX::PesquisaMAX(){

    DataPair Max = heap.front(); // elemento maximo
    heap[0] = heap.back(); // substitui a raiz pelo ultimo nó da heap
    heap.pop_back(); // remove o ultimo nó da heap
    prop(0); // reorganiza

    return Max;
}

bool HeapMAX::Vazia(){
    return heap.empty();
}

void HeapMAX::RemoveSugestao(const string& palavra, HeapMAX& heap, int k){
    int index = -1;
    bool encontrou = false;

    for(int i=0; i < (min(k, static_cast<int>(heap.heap.size()))); i++){
        if(heap.heap[i].palavra == palavra){
            index = i;
            encontrou = true;

            break;
        }
    }

    if(encontrou){
        heap.heap[index] = heap.heap.back();
        heap.heap.pop_back();
        heap.prop(index);
    }
}

void HeapMAX::cleanHEAP(HeapMAX& heap){
    heap.heap.clear();
}
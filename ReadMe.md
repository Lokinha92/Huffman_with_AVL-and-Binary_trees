<h1 align = center> AEDS II</h1>
<h1 align = center>ÁRVORES BINÁRIA E AVL + CODIFICAÇÃO DE HUFFMAN</h1>

<strong><p align = center> GUSTAVO HENRIQUE D'ANUNCIAÇÃO FERREIRA</p></strong>

<h2 align = center>  🧩 OBJETIVO </h2>

<p><strong>Demonstrar e comparar o funcionamento dos métodos de inserção e impressão. nas estruturas de Arvore Binária e Arvore AVL. Neste algoritmo também é demonstrado o funcionamento da codificação de Huffman para codificação binária de palavras. </strong></p>

<h2 align = center>  ❓ APRESENTAÇÃO DO PROBLEMA: </h2> 

Dado um conjunto de textos e palavras, é necessário verificar a ocorrência dessa palavra em cada um dos textos. Caso ela esteja presente no texto, o processamento desse texto ocorre da seguinte forma:

1 - Contagem das K palavras mais frequentes nesse texto utilizando a estrutura do contador de palavras (ja implementado anteriormente), caso a palavra em questão esteja entre essas k mais frequentes, ela deve ser removida e a proxima palavra mais frequente deve ser adicionada a contagem.

2 - As K palavras mais frequentes são adicionadas à arvore em questão (AVL ou Binária), acompanhadas da sua frequencia no texto.

3 - Com as palavras inseridas na sua respectiva estrutura de árvore, a árvore é impressa em pré-ordem. Após esse processo, as palavras presentes na árvore recebem uma codificação binária dada pela Árvore de Huffman gerada para o texto em questão.

obs: O processamento gera 2 arquivos de output: output_avl.txt e output_binario.txt. Nesses arquivos, todas as operações envolvendo as arvores avl e binaria, respectivamente, podem ser visualizados para conferência. Para cada palavra em questão, o processamento gera a seguinte saída:

A palavra (palavra em questao) foi encontrado no arquivo (arquivo em questao)

A palavra (palavra em questão) aparece (X) vezes no arquivo:

Arvore (AVL ou Binaria) em Pré-ordem:
[palavra : frequencia, ...]

(Y) palavras mais frequentes, seguidas da sua codificação: 
palavra : codigo
...

<h2 align = center>🌳 A ESTRUTURA DE ARVORE 🌳</h2>
    A maioria dos métodos de armazenamento de dados vistos até agora, são métodos que armazenam dados de forma linear, ou seja, armazenam dados "um ao lado do outro" como listas encadeadas ou duplamente encadeadas.

   <div align = center> <img align src = /img/lista.png> </div>

   Para realizar uma busca em estruturas lineares, o custo, no pior caso, é de <b>O(n)</b>, ou seja, todos os elementos da estrutura serão visitados a fim de encontrar um certo elemento. O problema é que, para grandes conjuntos de dados, esse custo para pesquisa se torna inviável.

   A fim de armazenar dados de forma mais eficiente para pesquisa, surgiram as estruturas de árvore.
   As árvores são amplamente utilizadas para organizar e armazenar dados de maneira hierárquica. Elas consistem em um conjunto de elementos chamados "nós" que estão conectados por "arestas". Cada árvore tem um "nó raiz" a partir do qual todas as outras conexões se estendem, e os nós são organizados em níveis, com os nós mais próximos ao topo da árvore sendo chamados de "nós pai" e os nós abaixo deles sendo chamados de "nós filhos".

   <div align = center> <img align src = /img/ArvoreEX.png> </div>

   <h3 align = center>Arvore binária de pesquisa (BST)</h3>
   O método de inserção de elementos na árvore consiste em comparar o elemento a ser inserido com a raíz, e caso ele seja maior é inserido na sub-árvore direita, se não, é inserido na sub-árvore esquerda.
   Dessa forma, a árvore se torna uma árvore binária de pesquisa ou BST.

   <div align = center> <img align src = /img/insere_bt.gif> </div>

   Dizemos que uma árvore está balanceada, quando todos os nós da árvore, exceto os nós do ultimo nível tem 2 filhos.

   Ao realizar uma busca em uma BST, o valor que está sendo procurado é comparado com o valor do nó raiz. Com base nessa comparação, é possível determinar em qual subárvore (esquerda ou direita) continuar a busca. Isso efetivamente divide o espaço de busca pela metade em cada etapa, pois metade dos elementos em cada comparação é descartado.

   Para uma árvore balanceada, o custo de pesquisa se torna <b>O(log n)</b> que é um custo muito mais viável em termos de tempo.

   Porém, no seu pior caso, a arovre binária de pesquisa pode ser montada em um formato como esse:

   <div align = center> <img align src = /img/piorcaso.png> </div>

   Tomemos como exemplo de elemento a ser buscado o 9. Observe que, primeiro, a estrutura não está balanceada, isso já interferiria no custo da busca, além disso, é possível perceber que, para chegar até o elemento alvo, é necessário percorrer toda a sub-árvore direita a partir da raiz, isso faz com que o custo da pesquisa volte a ser linear, ou seja <b>O(n)</b>.

   Mas, enfim, como manter uma árvore balanceada?

   <h3 align = center>Arvore AVL</h3>

   Árvores AVL são árvores binárias de pesquisa, porém, com uma propriedade especial, que é a de se manter balanceada após inserções e remoções.

   O conceito de Arvore AVL foi proposto em 1962 pelos matemáticos soviéticos G.M Adelson-Vesky e E.M Landis com a publicação do artigo "An algorithm for the organization of information" (Um algoritmo para a organização da informação). Nesse artigo, eles propuseram um novo conceito de árvore balanceada, baseando-se no conceito de altura.

   A altura em uma árvore AVL refere-se à medida da distância máxima entre o nó raiz e a folha sem filhos mais profunda nas suas sub-árvores.

   O cálculo da altura de uma árvore é dado pela soma do tamanho da sua maior sub-árvore + 1:

   $$T = T_s + 1$$

   Baseado nesse conceito, Adelsom-Vesky e Landis observaram a seguinte propriedade: Se para todos os nós da árvore a diferença de altura entre a sub-árvore direita e esquerda for no máximo 1 (essa diferença é chamada fator de balanço), o custo de busca se torna proporcional a <b>O(logn)</b>.

   Após cada inserção, a arvore AVL percorre todos os nós atualizando as alturas, caso o módulo do fator de balanço seja diferente de 0 ou |-1|, a árvore realiza rotações para que ela obedeça ao conceito de balanceamento.

   <h5 align = center>Rotações</h5>

   Existem dois tipos de rotação: Para a esquerda e para a direita.

   <b>Rotação a esquerda: Caso o novo nó seja inserido na sub-árvore direita do filho a direita</b>

   <div align = center> <img align src = /img/rot_esq.png> </div>

   Neste exemplo, C foi inserido na subárvore direita do filho a direita de A, deixando o fator de balanço do nó A em |-2|.

   Na rotação a esquerda, A passa a ser filho esquerdo de B, C permanece como filho a direita de B. Caso B tivesse um filho a esquerda (nesse caso é NULL) ele passaria a ser o filho a direita de A (que nesse caso também é NULL).

   Dessa forma, todos os nós passam a ter fator de balanço 0, deixando a estrutura balanceada.

   <b>Rotação a direita: Caso o novo nó seja inserido na sub-árvore esquerda do filho a esquerda</b>

   <div align = center> <img align src = /img/rot_dir.png> </div>

   Nesse exemplo, A foi inserido na sub-árvore esquerda do filho a esquerda de C, deixando o fator de balanço do nó C em |-2|

   Na rotação a direita, C passa a ser filho direito de B, A permanece como filho a esquerda de B. Caso B tivesse um filho a direita (nesse caso é NULL) ele passaria a ser o filho esquerdo de C (que nesse caso também é NULL);

   Dessa forma, todos os nós passam a ter fator de balanço 0, deixando a estrutura balanceada.

   Quando o nó é inserido na parte externa da árvore, uma rotação simples para a esquerda ou para a direita é suficiente para deixar a árvore balanceada, porém quando a inserção é feita na parte externa da árvore, são necessárias rotações duplas para que a estrutura fique novamente balanceada

   <b>Rotação direita-esquerda: Caso o novo nó seja inserido na sub-árvore esquerda do filho a direita</b>

   <div align = center> <img align src = /img/rot_dir_esq.png> </div>

   Nesse exemplo, 20 foi inserido na sub-arvore esquerda do filho direito de 10, deixando o nó 10 com fator de balanço |-2|. 

   Para que a estrutura fique novamente balanceada, uma rotação para a direita foi feita entre os nós 20 e 30, e depois, uma rotação a esquerda foi feita, deixando todos os nós com fator de balanço 0.

   <b>Rotação esquerda-direita: Caso o novo nó seja inserido na sub-árvore direita do filho a esquerda</b>

   <div align = center> <img align src = /img/rot_esq_dir.png> </div>

   Nesse exemplo, 20 foi inserido na sub-arvore direita do filho a esquerda de 30, deixando o fator de carga do nó 30 em |-2|.

   Para que a estrutura fique novamente balanceada, uma rotação a esquerda é feita entre os nós 20 e 10, e depois uma rotação a direita foi feita, deixando todos os nós com fator de balanço 0.

   A cada inserção e remoção, a árvore é percorrida verificando o fator de balanço de todos os nós, rotações acontecem até que o fator de balanço de todos os nós obedeçam à propriedade de balanceamento.

   <h4 align = center>👨‍💻 CODIFICAÇÃO DAS ESTRUTURAS DE ARVORE</h4>


   <h6 align=center>📚BIBLIOTECAS UTILIZADAS</h6>

   <table align=center>
     <tr>
        <td>iostream </td>    
    </tr>
    <tr>
        <td>string </td>    
    <tr>
        <td>fstream</td>
    </tr>
        <tr>
        <td>vector</td>
    </tr>
        </tr>
        <tr>
        <td>algorithm</td>
    </tr>    
   </table>

   <h5 align = center>Arvore binária de pesquisa (BST)</h5>

   <b><p align = center>Arvore_binaria.hpp</p></b>

   Nesse arquivo, a definição da estrutura que vai representar os nós é feita, assim como a construção da classe que vai representar a estrutura de árvore.

```c++
struct No {
    string palavra;
    int freq;

    No *esq;
    No *dir;

    No(const string& palavra, int freq): palavra(palavra), freq(freq), esq(nullptr), dir(nullptr){}
};
```
O problema descrito anteriormente, exige que o conteúdo de um nó seja, além de uma string para representar a palavra, um valor inteiro que representa a frequencia dessa palavra em um texto. Além disso, a struct "No" contém os ponteiros para os filhos à esquerda e à direita.

O construtor da struct define que um nó é inicializado a partir de uma dada string e um valor inteiro. Os ponteiros são apontados inicialmente para NULL, já que, quando um nó é inserido, ele não tem "nós filhos". 
```c++
class Arvore_binaria
{
private:
    No* InserirRecursivamente(No* no, const string& palavra, int freq);
public:
    No* raiz;
    Arvore_binaria();

    void Inserir(const string& palavra, int freq);
    void Imprimir(No *no, ofstream &arquivo);
    
};
```
A BST é representada a partir de uma classe, que contém 3 funções, um construtor e um objeto do tipo "No" que representa a raiz da árvore.

A seguir, a implementação das funções referidas acima:
<b><p align = center>Arvore_binaria.cpp</p></b>

Primeiramente, o construtor da classe é implementado, definindo a raiz da árvore como NULL, ou seja, uma árvore vazia.

```c++
Arvore_binaria::Arvore_binaria() {
    raiz = NULL;
}
```
O método de inserção envolve 2 funções. A primeira função contém a lógica da inserção própriamente dita:

```c++
No *Arvore_binaria::InserirRecursivamente(No *no, const string &palavra, int freq) {
    if (no == NULL) {
        return new No{ palavra, freq };
    }

    int score = freq - (2 * palavra.length());

    int compara_score = score - (no->freq - (2 * no->palavra.length()));

    if (compara_score <= 0) {
        no->esq = InserirRecursivamente(no->esq, palavra, freq);
    } else {
        no->dir = InserirRecursivamente(no->dir, palavra, freq);
    }

    return no;
}
```
Essa função recebe um nó, que será a referência de onde o processo de inserção começará a verificar a possibilidade de inserção de um novo nó, e o conteúdo do novo nó (string palavra e int frequencia) como parâmetro. Caso o nó de referência esteja definido como NULL, significa que é possível inserir um nó naquela posição, logo, o nó é simplesmente inserido ali.

Caso contrário, a regra de inserção é seguida até encontrar uma posição vazia possível para o novo nó.

A regra de inserção envolve a tanto o atributo de frequencia, quanto o número de caracteres presentes no atributo palavra. Um "score" foi calculado para que sirva de referência, e é dado pela frequencia, menos 2 vezes o tamanho da palavra:

$$score = freq - (2*T_p)$$

O score do nó a ser inserido é comparado ao score do nó de referência atual, caso o score do novo nó for menor ou igual ao nó de referência atual, a função é chamada recursivamente passando o filho esquerdo como nó de referência, caso contrário, a função é chamada recursivamente passando o filho direito como nó de referência. A recursividade ocorre até que o nó seja inserido na árvore.

```c++
void Arvore_binaria::Inserir(const string &palavra, int freq) {
    raiz = InserirRecursivamente(raiz, palavra, freq);
}
```
A função Inserir recebe, realmente, os atributos do novo nó a ser inserido como parâmetro. Ela chama a função de Inserção recursiva passando a raiz como nó primário de referência, assim como os atributos do novo nó. Isso significa que o processo de verificação de possibilidade de inserção será inicializado na raiz, e percorrerá suas respectivas sub-árvores em busca de uma posição adequada para a inserção do novo nó.

```c++
void Arvore_binaria::Imprimir(No *no, ofstream &arquivo) {
    if (arquivo.is_open()) {
        if (no != NULL) {
            arquivo << no->palavra << " : " << no->freq << ", ";
            Imprimir(no->esq, arquivo);
            Imprimir(no->dir, arquivo);
        }
    }
}
```
Por fim, a função de impressão recebe um nó primário de referência e o aqruivo de output onde a árvore deverá ser impressa. A função percorre todos os nós da árvore a partir do nó primário de referência e imprime os atributos de cada nó da árvore em pré-ordem.

<h5 align = center>Arvore AVL</h5>
<b><p align = center>Arvore_AVL.hpp</p></b>

Pelo fato de uma árvore AVL ser uma BST, as diferenças na implementação são referentes às rotaçõees.

Primeiramente, a struct que representará o nó é criada:

```c++
struct No_AVL {
    string palavra;
    int freq;

    int altura;

    No_AVL *esq;
    No_AVL *dir;

    No_AVL(const string& palavra, int freq): palavra(palavra), freq(freq), altura(0), esq(nullptr), dir(nullptr){}
};
```

É possível notar que, em relação ao nó que compõe a BST simples, a única diferença é que o nó da árvore AVL contém um atributo para representar a altura que este nó se encontra na árvore. Com relação ao construtor, quando um nó é inserido na árvore, ele é inicializado com o atributo de altura com o valor 0.

```c++
class Arvore_AVL
{
private:
    No_AVL* Inserir_Recursivamente(No_AVL* no, const string& palavra, int freq);
public:

    No_AVL* raiz;
    Arvore_AVL();

    No_AVL* Rot_Esquerda(No_AVL* no);
    No_AVL* Rot_Direita(No_AVL* no);

    int get_altura(No_AVL* no);
    void Inserir(const string& palavra, int freq);
    void Imprimir(No_AVL* no, ofstream &arquivo);
};
```
Assim como na BST, a árvore AVL é representada com uma classe. A classe da Arvore AVL é composta por 6 funções, 1 construtor, e um objeto do tipo "No_AVL" que representa a raíz da árvore.

A seguir, a implementação das funções referenciadas acima:

<b><p align = center>Arvore_AVL.cpp</p></b>

De início, assim como na BST, o construtor da classe é implementado, definindo a raiz da árvore como NULL, ou seja, uma árvore vazia.

```c++
Arvore_AVL::Arvore_AVL(){
    raiz = NULL;    
}
```

A função get_altura recebe um nó como parâmetro, e verifica a altura desse nó.
```c++
int Arvore_AVL::get_altura(No_AVL* no){
    if (no == NULL){
        return -1;
    }

    return no->altura;
}
```
Para um nó definido como NULL, consideramos a altura como -1.

Depois, as funções de rotação são implementadas:

```c++
No_AVL* Arvore_AVL::Rot_Direita(No_AVL* no){
    No_AVL* aux = no->esq;
    No_AVL* aux_fd = aux->dir;

    aux->dir = no;
    no->esq = aux_fd;

    no->altura = max(get_altura(no->esq), get_altura(no->dir)) + 1;
    aux->altura = max(get_altura(aux->esq), get_altura(aux->dir)) + 1;

    return aux;
}

No_AVL* Arvore_AVL::Rot_Esquerda(No_AVL* no){
    No_AVL* aux = no->dir;
    No_AVL* aux_fe = aux->esq;

    aux->esq = no;
    no->dir = aux_fe;

    no->altura = max(get_altura(no->esq), get_altura(no->dir)) + 1;
    aux->altura = max(get_altura(aux->esq), get_altura(aux->dir)) + 1;

    return aux;
}
```
As funções de rotação recebem o nó com o fator de balanço incoerente. Elas operam atualizando os ponteiros de acordo com a lógica de rotação já vista anteriormente, e, após essa atualização dos ponteiros, a altura dos nós da nova sub-arvore gerada é atualizada de acordo com a fórmula do calculo de altura. As funções retornam o ponteiro para a raíz na nova sub-árvore gerada.

Com respeito ao método de inserção, ele não se difere muito da implementação da BST, exceto pela aplicação da propriedade de rotações para manter a árvore equilibrada.

```c++
No_AVL* Arvore_AVL::Inserir_Recursivamente(No_AVL* no, const string& palavra, int freq){
    if(no == NULL){
        return new No_AVL{palavra ,freq};
    }

    int score = freq - (2 * palavra.length());

    int compara_score = score - (no->freq - (2 * no->palavra.length()));

    if(compara_score <= 0){
        no->esq = Inserir_Recursivamente(no->esq, palavra, freq);
    } else{
        no->dir = Inserir_Recursivamente(no->dir, palavra, freq);
    }

    no->altura = 1 + max(get_altura(no->esq), get_altura(no->dir)); // atualizando altura do nó

    int fat_balanco = get_altura(no->esq) - get_altura(no->dir); // calculando fator de balanço

    // rotações

    if(fat_balanco > 1 && compara_score <=0){ // o nó foi inserido na sub-arvore esquerda do filho da esquerda
        return Rot_Direita(no);
    }

    if(fat_balanco < -1 && compara_score > 0){ // o nó foi inserido na sub-arvore direita do filho da direita
        return Rot_Esquerda(no);
    }

    if(fat_balanco > 1 && compara_score > 0){ // o nó foi inserido na sub-arvore direita do filho a esquerda
        no->esq = Rot_Esquerda(no->esq);
        return Rot_Direita(no);
    }

    if(fat_balanco < -1 && compara_score <=0){ // o nó foi inserido na sub-arvore esquerda do filho a direita
        no->dir = Rot_Direita(no->dir);
        return Rot_Esquerda(no);
    }

    return no;
}
```
Note que, até certo ponto, a implementação do método de inserção é idêntica à BST. Após isso, a implementação do auto-balanceamento utilizando as rotações começa. 

Primeiro, a altura do nó primário de referência é atualizada e o fator de balanço do nó é calculado. Por fim, é feita uma verificação conjunta da posição onde o novo nó foi inserido, e o fator de balanço do nó primário de referência. De acordo com a posição onde o novo nó foi inserido, a devida rotação para que a sub-árvore que contém o nó primário de referência como raiz fique equilibrada é realizada.

```c++
void Arvore_AVL::Inserir(const string& palavra, int freq){
    raiz = Inserir_Recursivamente(raiz, palavra, freq);
}

void Arvore_AVL::Imprimir(No_AVL* no, ofstream &arquivo) {

    if(arquivo.is_open()){
        if (no != nullptr) {
        arquivo << no->palavra << " : " << no->freq << ", ";
        Imprimir(no->esq, arquivo);
        Imprimir(no->dir, arquivo);
    }
    }
}
```
Tanto a segunda função de Inserção, quanto a função de impressão, funcionam exatamente igual à BST.

<h2 align = center>👾 CODIFICAÇÃO DE HUFFMAN 👾</h2>

A codificação de Huffman é uma técnica de compressão de dados que foi desenvolvida por David A. Huffman em 1952. Ela é amplamente usada para compactar dados, como texto e arquivos de mídia, reduzindo seu tamanho para economizar espaço de armazenamento e melhorar a eficiência na transmissão de dados.

Ela é eficiente para dados que contêm símbolos com diferentes frequências de ocorrência, pois permite que os símbolos mais comuns sejam representados por códigos mais curtos, economizando espaço.

A codificação de huffman ocorre seguindo os seguintes passos:

- Frequência de Ocorrência: Inicialmente, é feita uma análise do conjunto de dados a ser comprimido para determinar a frequência de ocorrência de cada símbolo, no caso dessa implementação, caracteres no texto.

- Construção da Árvore de Huffman: Com base nas frequências, uma árvore de Huffman é construída. Esta árvore tem o formato de uma BST, onde os nós folha representam os símbolos e os nós internos representam combinações de símbolos. A árvore é construída de maneira a garantir que os símbolos mais frequentes tenham caminhos mais curtos na árvore.

    Eis um exemplo visual da construção da árvore de Huffman:
<div align = center> <img align src = /img/huff.png> </div>

Neste exemplo, a árvore de huffman foi montada para um conjunto contendo os caracteres 'A', 'B', 'C' 'D', 'E', 'F'. Note que os nós contendo os caracteres propriamente ditos estão sempre em nós folhas, como foi dito anteriormente.

- Atribuição de Códigos: Cada símbolo é atribuído a um código binário único com base na árvore de Huffman. Os códigos são atribuídos seguindo o caminho da raiz da árvore até o símbolo desejado, onde 0 representa uma ramificação para a esquerda e 1 representa uma ramificação para a direita.

- Codificação: O conjunto de dados original é então substituído pelos códigos de Huffman correspondentes. Os símbolos são substituídos pelos códigos binários ao realizar a compressão. Por exemplo, a codificação binária para o conjuto da letra E + F é 011, pois, partindo da raíz da árvore, até chegar ao nó que contém o conjunto E + F, o caminho é 1 para a esquerda e 2 para a direita.

É possível expandir a lógica da construção da árvore de huffman para um texto todo. A partir da contagem da ocorrência das palavras em um texto, a árvore é montada seguindo os mesmos passos descritos acima, garantindo que as palavras com maior ocorrência esejam mais próximas da raiz, enquanto palavras com menor ocorrência esão mais profundos.

Essa foi a lógica aplicada para essa implementação.

<h4 align = center>👨‍💻 IMPLEMENTAÇÂO DA CODIFICAÇÃO DE HUFFMAN</h4>

<b><p align = center>Huffman.hpp</p></b>

Nesse arquivo, as estruturas que vão compor a construção da árvore de Huffman são criadas:

```c++
struct NoHuffmann
{
    string palavra;
    int freq;

    NoHuffmann* esq;
    NoHuffmann* dir;

    NoHuffmann(string p, int f) : palavra(p), freq(f), esq(nullptr), dir(nullptr){}
};
```
A struct NoHuffman contém a estrutura do nós que vão compor a árvore. A variável do tipo string armaneza a palavra, e a variável inteira armazena a frequencia daquela palavra/conjunto na árvore.

```c++
struct Compara_NO {
    bool operator()(NoHuffmann* a, NoHuffmann* b){
        return a->freq > b->freq;
    }
};
```
A struct Compara_NO apenas armazena a função que será usada para comparar a frequencia armazenada em dois nós. Ela será usada no processo de construção da árvore.

<b><p align = center>Huffman.cpp</p></b>

Nesse arquivo, a implementação das funções que compõem a codificação de Huffman é realizada

```c++
NoHuffmann* ConstruirArvore(const unordered_map<string, int>& frequencia){
    priority_queue<NoHuffmann*, vector<NoHuffmann*> ,Compara_NO> filaPrioridade;

    for(const auto& item : frequencia){
        filaPrioridade.push(new NoHuffmann(item.first, item.second));
    }

    while(filaPrioridade.size() > 1){
        NoHuffmann* esq = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* dir = filaPrioridade.top();
        filaPrioridade.pop();

        NoHuffmann* pai = new NoHuffmann("", esq->freq + dir->freq);
        pai->esq = esq;
        pai->dir = dir;

        filaPrioridade.push(pai);
    }

    return filaPrioridade.top();
}

```
De forma geral, essa função cria a árvore de Huffman usando uma fila de prioridade. Essa fila de prioridade armazena ponteiros para os nós, e é representada por um vector. Note que, a struct Compara_NO é utilizada para definir a regra de prioridade na fila. A árvore é montada de forma que os nós com frequências mais baixas têm prioridade mais alta na fila. Ela combina os nós de menor frequência até que toda a árvore seja construída e, em seguida, retorna a raiz da árvore que conterá uma string vazia, apenas com o endereçamento dos ponteiros para que a árvore tenha a referência de início. 

Com a árvore montada, o próximo passo é construir uma espécie de dicionário, esse dicionário será usado para consultar o código binário de uma referida palavra gerado pela árvore de huffman.

```c++
void gerarCodigosHuffman(NoHuffmann* raiz, string codigo, unordered_map<string, string>& codigos){
    if(!raiz){
        return;
    }

    if(!raiz->palavra.empty()){
        codigos[raiz->palavra] = codigo;
    }

    gerarCodigosHuffman(raiz->esq, codigo + "0", codigos);
    gerarCodigosHuffman(raiz->dir, codigo + "1", codigos);
}
```

A primeira verificação serve para conferir se um nó é nulo, isso serve como condição de parada da recurssão.

A proxima verificação verifica se a string de um nó não é vaiza, nesse caso, atribuímos o código à palavra em um unordered_map.

A recursividade faz justamente o papel de "mapear" idas para a esquerda com o código 0 e idas para a direita com o código 1.

Com os códigos para cada palavra já armazenados em um unordered_map, a consulta para a codificação binária de uma dada palavra pode ocorrer.

```c++
string Codificar(const string& palavra, unordered_map<string, string>& codigos) {
    if (codigos.find(palavra) != codigos.end()) {
        return codigos.at(palavra);
    } else {
        return palavra;
    }
}
```
É justamente isso que a função Codificar faz, ela recebe a palavra a ser codificada e verifica se há um código associado à essa palavra na árvore de huffman. Caso exista, o código é retornado, se não, a própria palavra é retornada.

<h2 align = center>💡 RESOLUÇÃO DO PROBLEMA</h2>

Para a realização do processamento do/dos textos, todas as estruturas descritas anteriormente serão utilizadas.

Além das estruturas já descritas, a estrutura do contador de palavras será utilizado. A documentação do contador de palavras pode ser acessado <a href="https://github.com/Lokinha92/counting_word_frequency">AQUI</a>

Uma função auxiliar foi adicionada à estrutura de HeapMax para remover uma palavra caso ela esteja entre as K mais frequentes:

```c++
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
```
Outra funcionalidade adicionada à estrutura do contador de palavras, é a de verificar se uma palavra está presente no texto:

```c++
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
```
Por fim, funções que percorrem as árvores binária e AVL e realizam a codificação binária da palavra presente no nó utilizando a árvore de huffman também foram adicionadas:

```c++
void Huff_bt(No *no, unordered_map<string, string> codigos, ofstream &arquivo) {
    if (no == nullptr) {
        return;
    }

    string codigo = Codificar(no->palavra, codigos);

    arquivo << no->palavra << " : " << codigo << endl;

    Huff_bt(no->esq, codigos, arquivo);
    Huff_bt(no->dir, codigos, arquivo);
}

void Huff_AVL(No_AVL *no, unordered_map<string, string> codigos, ofstream &arquivo) {
    if (no == nullptr) {
        return;
    }

    string codigo = Codificar(no->palavra, codigos);

    arquivo << no->palavra << " : " << codigo << endl;

    Huff_AVL(no->esq, codigos, arquivo);
    Huff_AVL(no->dir, codigos, arquivo);
}
```

Com essas adições, o processamento já tem todas as ferramentas disponíveis para que ele aconteça.

As funções responsáveis pelo processamento estão referenciadas no arquivo <b>functions.hpp</b> e implementadas no arquivo <b>functions.cpp</b>

O processamento é realizado da seguinte forma:

Primeiro, a ocorrência da palavra dada é verificada nos textos de referência. Para cada texto onde essa palavra exista, a estrutura do contador de palavras é usada para contar a frequência de todas as palavras no texto, dessa forma, a frequência da palavra em questão pode ser acessada. 

Com a contagem das palavras realizada, elas são inseridas na estrutura de Heap máxima para que as K palavras mais frequentes sejam classificadas. Caso a palavra em questão esteja entre as K mais frequentes, ela é removida e a proxima palavra mais frequente é adicionada à contagem.

Após a heap estar devidamente montada, as k palavras são passadas para a árvore em questão. Com as árvores contendo as K palavras mais frequentes, a árvore de huffman é montada e os códigos gerados referentes a cada palavra do texto é armazenado em um unordered_map.

Dessa forma, é possível realizar o processo de pesquisa, fazendo a codificação binária das palavras presentes na árvore usando a arvore de huffman gerada para aquele texto.

Por fim, todos os processos são printados de acordo com o formato já descrito anteriormente para conferência em seu respectivo arquivo de output. Um arquivo de output vai ser gerado para cada tipo de árvore (AVL ou binária).

```c++
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

            NoHuffmann *raiz = ConstruirArvore(frequencia);

            unordered_map<string, string> codigos;
            gerarCodigosHuffman(raiz, "", codigos);

            string caminho = "../output/output_binario.txt";

            ofstream output(caminho, ios::app);

            if (output.is_open()) {
                output << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;
                output << "A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl << endl;;
                output << "Arvore Binária em Pré-Ordem: " << endl;
                output << "[ ";
                Binary_tree.Imprimir(Binary_tree.raiz, output);
                output << "]" << endl << endl;

                output << NUM_SUGESTOES << " palavras mais frequentes, seguidas da sua codificação: " << endl;
                Huff_bt(Binary_tree.raiz, codigos, output);
                output << "---------------------------------------------------------" << endl << endl;
                output.close();
            }

            frequencia.clear();
            codigos.clear();
        }
    }
}
```
---

```c++
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

            unordered_map<char, int> freq_char = ContaFrequencia_char(par.second);

            NoHuffmann *raiz = ConstruirArvore(frequencia);

            unordered_map<string, string> codigos;
            gerarCodigosHuffman(raiz, "", codigos);

            string caminho = "../output/output_avl.txt";

            ofstream output(caminho, ios::app);

            if (output.is_open()) {
                output << " A palavra " << palavra_pesq << " foi encontrada no arquivo: " << par.first << endl << endl;
                output << "A palavra " << palavra_pesq << " aparece " << freq_encontrada << " vezes no arquivo" << endl << endl;;
                output << "Arvore AVL em Pré-Ordem: " << endl;
                output << "[ ";
                AVL_tree.Imprimir(AVL_tree.raiz, output);
                output << "]" << endl << endl;

                output << NUM_SUGESTOES << " palavras mais frequentes, seguidas da sua codificação: " << endl;
                Huff_AVL(AVL_tree.raiz, codigos, output);
                output << "---------------------------------------------------------" << endl << endl;
                output.close();
            }

            frequencia.clear();
            codigos.clear();
        }
    }
}
```
A única diferença entre as duas implementações é, justamente, a árvore utilizada. A variável NUM_SUGESTOES indica qual será o range de palavras a serem consideradas as mais frequentes.

<h2 align = center>⚙️ ALGORITMO</h2>
<b><p align = center>main.cpp</p></b>

<h4 align = center>ARQUIVOS UTILIZADOS</h4>
<table align=center>
     <tr>
        <td>filosofia.txt / filosofia2.txt </td>    
    </tr>
    <tr>
        <td>globalização.txt </td>    
    <tr>
        <td>politica.txt</td>
    </tr>
        <tr>
        <td>ti.txt / ti2.txt</td>
    </tr>
</table>

<b><p align = center>Esses são os arquivos contendo os textos de referência. </p></b>

<table align = center>
        </tr>
        <tr>
        <td>palavra.txt</td>
    </tr>
        </tr>
        <tr>
        <td>nome_txt.txt</td>
    </tr>
        </tr>
        <tr>
        <td>stopwords.txt</td>
    </tr> 
</table>
<b><p align = center>palavra.txt : Contém as palavras que serão pesquisadas nos textos para condicionar o processamento </p></b>

<b><p align = center>nome_txt.txt : Contém o nome dos arquivos de texto que deverão ser considerados para a pesquisa e o processamento.</p></b>

<b><p align = center>stopwords.txt : Contém as palavras sem relevância semântica que deverão ser removidas dos textos. </p></b>

- --

O range das palavras mais frequentes a serem consideradas pode ser alterado definindo o valor desejado à variável NUM_SUGESTOES localizada no cabeçalho do arquivo <b>main.cpp</b>

```c++
#define NUM_SUGESTOES 10
```

Antes do processamento, o tratamento dos textos e a montagem do vector que vai armazenar o par contendo texto juntamente com o seu nome de arquivo deve ser realizada:

```c++
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
```

A função "Apaga_output" é apenas uma função auxiliar que apaga o conteúdo da pasta dataset para que não haja sobreposição de output entre execuções distintas do algorítmo.

Primeiramente, o arquivo "nome_txt.txt" é acessado e o caminho correto para o arquivo é montado, e armazenado em um vector.

Com os caminhos devidamente armazenados, as stopwords e os textos são lidos e armazenados para o tratamento.

Enfim, o texto é tratado, e a estrutura que vai armazenar o par contendo o texto tratado juntamente com o nome do arquivo do texto pode ser montada.

Após esses processos, o arquivo que contém as palavras a serem pesquisadas é acessado, e o processamento é feito para cada palavra presente no arquivo "palavras.txt" usando árvores binárias e AVL, separadamente.

```c++
 fstream palavras("../dataset/palavra.txt");

    if (palavras.is_open()) {
        string palavra_pesq;

        while (palavras >> palavra_pesq) {
            ProcessarPalavrasArvoreBinaria(par_nome_texto, palavra_pesq, NUM_SUGESTOES);

            ProcessarPalavrasArvoreAVL(par_nome_texto, palavra_pesq, NUM_SUGESTOES);
        }
        palavras.close();
    }
```

<h2 align = center>📈 TESTES E RESULTADOS</h2>

Durante os testes, todos os textos de referência e as seguintes palavras para pesquisa foram usadas:

<table align = center>
        <tr>
            <td>teoria</td>
        </tr>
        <tr>
            <td>filosofia</td>
        </tr>
        <tr>
            <td>codificação</td>
        </tr>
        <tr>
            <td>estrutura</td>
        </tr>
        <tr>
            <td>programação</td>
        </tr>
        <tr>
            <td>política</td>
        </tr>
    </table>

Após a execução, o output contendo o processamento para todas as palavras em cada um dos textos onde ela existe é gerado no formato já anteriormente descrito. Por exemlo, eis as saídas para o processamento da palavra "teoria":

<div align = center> <img align src = /img/outBIN.png> </div>

-- -
<div align = center> <img align src = /img/outAVL.png> </div>

O processamento ocorre da mesma forma em ambos os casos. A diferença pode ser notada ao reparar na ordem em que os elementos estão distribuídos na árvore. Essa diferença se dá devido às rotações realizadas pela árvore AVL a fim de se tornar balanceada.

Apesar de ser a palavra mais frequente nos textos onde ela aparece, a palavra teoria não aparece na árvore, pois ela não deve ser "recomendada" 2 vezes. Isso mostra um bom funcionamento na estrutura de remoção da palavra caso ela esteja presente nas K mais frequentes.

Também é notável que, para os textos correspondentes em cada arquivo de output, a codficação binária das palavras correspondem. Isso mostra um funcionamento compatível da montagem da árvore de Huffman.

O mesmo processo é repetido para todas as palavras presentes no arquivo "palavras.txt".

<h2 align = center>🔧 Compilação e execução </h2>
</h2>
      

<b>No terminal, navegue até a pasta src:</b>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `g++ main.cpp functions.cpp Arvore_binaria.cpp HeapMAX.cpp Arvore_AVL.cpp Huffman.cpp`                | Executa a compilação do programa utilizando o g++
|  `./a.out`            | Executa o programa após a compilação         
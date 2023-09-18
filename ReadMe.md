<h1 align = center> AEDS II</h1>
<h1 align = center>ÁRVORES BINÁRIA E AVL + CODIFICAÇÃO DE HUFFMAN</h1>

<strong><p align = center> GUSTAVO HENRIQUE D'ANUNCIAÇÃO FERREIRA</p></strong>

<h2 align = center>  🧩 OBJETIVO </h2>

<p><strong>Demonstrar e comparar o funcionamento dos métodos de inserção, impressão e pesquisa nas estruturas de Arvore Binária e Arvore AVL. Neste algoritmo também é demonstrado o funcionamento da codificação de Huffman para codificação binária de palavras. </strong></p>

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

   <h3 align = center>Arvore Binaria de pesquisa (BST)</h3>
O método de inserção de elementos na árvore consiste em comparar o elemento a ser inserido com a raíz, e caso ele seja maior é inserido na sub-árvore direita, se não, é inserido na sub-árvore esquerda.
Dessa forma, a árvore se torna uma árvore binária de pesquisa ou BST.

   <div align = center> <img align src = /img/insere_bt.gif> </div>

Dizemos que uma árvore está balanceada, quando todos os nós da árvore, exceto os nós do ultimo nível tem 2 filhos.

Ao realizar uma busca em uma BST, o valor que está sendo procurado é comparado com o valor do nó raiz. Com base nessa comparação, é possível determinar em qual subárvore (esquerda ou direita) continuar a busca. Isso efetivamente divide o espaço de busca pela metade em cada etapa, pois metade dos elementos em cada comparação é descartado.

 Para uma árvore balanceada, o custo de pesquisa se torna <b>O(log n)</b> que é um custo muito mais viável em termos de tempo.

 Porém, no seu pior caso, a arovre binária de pesquisa pode ser montada em um formato como esse:

<div align = center> <img align src = /img/piorcaso.png> </div>

Tomemos como exemplo de elemento a ser buscado o 9. Observe que, primeiro, a estrutura não está balanceada, isso já interferiria no custo da busca, além disso, é possível perceber que, para chegar até o elemento alvo, é necessário percorrer toda a sub-árvore direita a partir da raiz, isso volta a fazer com que o custo da pesquisa seja <b>O(n)</b>.
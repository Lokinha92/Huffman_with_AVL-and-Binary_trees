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

Tomemos como exemplo de elemento a ser buscado o 9. Observe que, primeiro, a estrutura não está balanceada, isso já interferiria no custo da busca, além disso, é possível perceber que, para chegar até o elemento alvo, é necessário percorrer toda a sub-árvore direita a partir da raiz, isso faz com que o custo da pesquisa volte a ser linear, ou seja <b>O(n)</b>.

Mas, enfim, como manter uma árvore balanceada?

<h3 align = center>Arvore AVL</h3>

Árvores AVL são árvores binárias de pesquisa, porém, com uma propriedade especial, que é a de se manter balanceada após inserções e remoções.

O conceito de Arvore AVL foi proposto em 1962 pelos matemáticos soviéticos G.M Adelson-Vesky e E.M Landis com a publicação do artigo "An algorithm for the organization of information" (Um algoritmo para a organização da informação). Nesse artigo, eles propuseram um novo conceito de árvore balanceada, baseando-se no conceito de altura.

A altura em uma árvore AVL refere-se à medida da distância máxima entre o nó raiz e a folha sem filhos mais profunda nas suas sub-árvores.

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


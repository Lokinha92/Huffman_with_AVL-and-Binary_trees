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
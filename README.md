# Atividade Avaliativa 02 – Criptografia Simples

## Disciplina
Algoritmo e Pensamento Computacional

## Professor
Francisco de Assis Cavallaro

## Objetivo

Desenvolver um programa em linguagem C que una criptografia simples, matemática aplicada e conceitos computacionais.

O programa utiliza duas camadas de criptografia:

1. Cifra de César, utilizando um SHIFT definido pelo usuário.
2. Deslocamento dinâmico utilizando uma sequência matemática.

## Sequências disponíveis

- PA: 1, 2, 3, 4...
- PG: 1, 2, 4, 8...
- Fibonacci: 1, 1, 2, 3, 5, 8...
- Números primos: 2, 3, 5, 7, 11, 13...

## Funcionamento

Para cada letra da palavra, o programa calcula:

deslocamento total = SHIFT + valor da sequência

Depois, a letra é deslocada no alfabeto utilizando aritmética modular com 26 posições.

## Exemplo

Palavra: coracao

SHIFT: 3

Sequência: Fibonacci

Sequência utilizada:

1, 1, 2, 3, 5, 8, 13

Resultado:

gswgkle

## Arquivo gerado

Após a execução, o programa gera o arquivo:

resultado_criptografia.txt

O arquivo registra a palavra original, a palavra codificada, o SHIFT, a sequência escolhida e a quantidade de letras.

## Taxonomia de Bloom

- Lembrar: reconhecer alfabeto, ASCII e sequências numéricas.
- Compreender: entender a Cifra de César e os deslocamentos.
- Aplicar: implementar o algoritmo em C.
- Analisar: comparar os resultados das diferentes sequências.
- Avaliar: observar padrões e diferenças entre os métodos.
- Criar: desenvolver um sistema completo e personalizável.

## Conceitos computacionais

O projeto utiliza variáveis, funções, estruturas condicionais, estruturas de repetição, vetores de caracteres, manipulação de caracteres, aritmética modular e arquivos.

## Conclusão

O projeto integra lógica de programação, matemática e criptografia em uma única aplicação, mostrando como conceitos matemáticos podem ser utilizados na construção de algoritmos computacionais.
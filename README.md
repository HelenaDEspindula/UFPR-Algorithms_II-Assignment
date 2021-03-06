# UFPR - Algorithms II - Assgnment
(in Portuguese)

Equipe:
=======
O trabalho pode ser feito em grupos de até 2 alunos.


Parte 1:
========

Implementar as operações + - = * da especificação do trabalho.


Parte 2:
========

Implementar toda a especificação do trabalho.


Entrega:
========

O trabalho deve ser entregue por email para fabiano@inf.ufpr.br até
23:59 do dia da entrega de cada parte do trabalho.

O email deve conter a identificação completa dos alunos da equipe
(nome completo, GRR e login no sistema) e um arquivo em anexo com o
trabalho.

O arquivo com o trabalho deve ser um .tar.gz com o nome dado por:

  login_aluno_1-login_aluno_2.tar.gz

onde [login_aluno_i] é o login no sistema do aluno i da equipe.

O arquivo (.tar.gz) com o trabalho deve conter um diretorio com o
mesmo nome do arquivo sem a extensão .tar.gz com:
  - o código fonte do programa (*.[ch]);
  - Makefile para compilar o código fonte;
  - Leiame.txt com a identificação completa dos alunos da equipe e uma
    breve documentação e/ou considerações sobre o trabalho, como erros
    e dificuldades encontradas.


Especificação:
==============

Você deve implementar um programa, na linguagem C, que seja capaz de
armazenar e tratar operações, de maneira eficiente, em uma coleção de
conjuntos de números inteiros.

O programa deve ler da entrada padrão a listagem das operações a serem
realizadas sobre a coleção de conjuntos. A cada operação lida da
entrada padrão o programa deve gerar na saída padrão a resposta
correspondente. Por exemplo, o programa deve ser executado por:

  $ programa < arq_com_as_operacoes.txt > arq_de_saida.txt

O arquivo de entrada é dividido em linhas e os componentes de cada
linha são separados por espaços em branco. A estrutura do arquivo é
dada por:

  - A primeira linha do arquivo contém um número inteiro K indicando o
    valor do maior elemento que pode aparecer nos conjuntos;

  - Cada linha seguinte contém uma operação que deve ser realizada
    sobre a coleção de conjuntos armazenada, onde cada linha tem os 
    seguintes componentes separados por espaço:
    
      - A linha inicia com um caracter que indica o tipo da operação
        que deve ser realizada: '+', '-', '=', '*', '/', '<' e '>';
	
      - Após o tipo vem a descrição de um conjunto, que é dada por:
      
          - Um número inteiro positivo N que indica o tamanho do 
            conjunto envolvido na operação. O tamanho do conjunto é 
            menor ou igual a K;
	    
          - Após o tamanho vem uma sequência ordenada de N números
            inteiros positivos que são os elementos do conjunto
            envolvido na operação. Os elementos do conjunto são 
            números inteiros do intervalo [1..K];
	    
      - No caso do operador '*' o restante da linha é vazio.
      
  - Uma linha iniciando com o número 0 (zero) termina a listagem de
    operações e encerra o arquivo de entrada.

As operações sobre a coleção de conjuntos são:

  '+' O conjunto envolvido na operação deve ser incluído na coleção.
      Caso a inclusão não seja possível o programa deve gerar como
      saída duas linhas, uma contendo o caracter 'E', indicando erro,
      e outra com 0, indicando o final da resposta da operação. Caso
      a inclusão seja bem sucedida apenas a linha com 0 deve ser
      gerada como saída;
      
  '-' O conjunto envolvido na operação deve ser removido da coleção. 
      Caso a operação seja bem sucedida a saída deve conter apenas
      uma linha com 0. Caso contrário, duas linhas devem ser geradas, 
      uma com o caracter 'E' e outra com 0;
      
  '=' Esta operação deve verificar se o conjunto envolvido está na
      coleção. Caso a operação seja bem sucedida a saída deve conter
      apenas uma linha com 0. Caso contrário, duas linhas devem ser
      geradas, uma com o caracter 'E' e outra com 0;
      
  '*' Esta operação deve listar todos os conjuntos da coleção. A lista
      de conjuntos gerada deve estar ordenada de forma crescente pelo
      tamanho dos conjuntos. Os elementos de cada conjunto também
      devem estar ordenados de forma crescente. Conjuntos com o mesmo
      tamanho devem estar ordenados segundo os valores do seus
      elementos, por exemplo, o conjunto "2 12 999" deve vir antes do
      conjunto "2 12 4000". A saída deve ter cada conjunto em uma
      linha, terminando com uma linha com 0. Caso a lista seja vazia,
      apenas a linha com 0 deve ser gerada;
      
  '/' Esta operação deve remover da coleção todos os conjuntos que
      são superconjuntos próprios do conjunto envolvido na operação. 
      Caso algum conjunto seja removido, a operação é considerada
      bem sucedida e a saída deve conter apenas uma linha com 0. Caso 
      contrário, duas linhas devem ser geradas, uma com o caracter
      'E' e outra com 0;
      
  '<' Esta operação deve listar todos os conjuntos da coleção que são
      subconjuntos próprios do conjunto envolvido na operação. A saída
      deve ter cada conjunto em uma linha, seguida de uma linha com
      0. Os conjuntos devem ser listados na ordem crescente de seus
      tamanhos, sendo que os conjuntos com o mesmo tamanho devem estar
      ordenados segundo os valores do seus elementos. Para cada
      conjunto listado, seus elementos também devem estar ordenados de
      forma crescente. Caso a lista seja vazia, apenas a linha com 0
      deve ser gerada;
      
  '>' Esta operação deve listar todos os conjuntos da coleção que são
      superconjuntos próprios do conjunto envolvido na operação. A
      saída deve ter cada conjunto em uma linha, seguida de uma linha
      com 0. Os conjuntos devem ser listados na ordem crescente de
      seus tamanhos, sendo que os conjuntos com o mesmo tamanho devem
      estar ordenados segundo os valores do seus elementos. Para cada
      conjunto listado, seus elementos também devem estar ordenados de
      forma crescente. Caso a lista seja vazia, apenas a linha com 0
      deve ser gerada


Exemplo:
========

Considere o seguinte exemplo de arquivo de entrada:

5000
+ 3 12 1340 4455
+ 2 12 4000
+ 2 12 4000
+ 3 666 1122 1340
- 1 666
= 1 666
- 3 666 1122 1340
< 4 12 1340 4000 4455
> 1 666
> 2 12 4000
> 2 12 1340
0

A saída correspondente para esta entrada deve ser:

0
0
E
0
0
E
0
E
0
0
2 12 4000
3 12 1340 4455
0
0
0
3 12 1340 4455
0

Observações:

  - Para cada operação da entrada existe um 0 na saída indicando o
    final da resposta da operação;
    
  - A terceira operação "+ 2 12 4000" resultou em 'E' pois o conjunto
    {12,4000} já estava na coleção;
    
  - A penúltima operação "> 2 12 4000" resultou em uma lista vazia
    pois o conjunto {12,4000} não é um superconjunto próprio dele
    mesmo;
    

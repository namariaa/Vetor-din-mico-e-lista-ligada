# Vetor-din-mico-e-lista-ligada
O trabalho consiste em duas implementações uma com vetor dinâmico utilizando alocação dinâmica de memória e outra com lista ligada. Para a aplicação do vetor houve a criação de 4 arquivos .cpp, 1 arquivo .hpp e 11 .txt.
Os arquivos .cpp consistem em: Gerar_numeros, teste_pop, teste_pushV e teste_remove que foram utilizados respectivamente para gerar casos testes e os outros três para testar o uso e contabilização de tempo que a função demorou para compilar e sair os resultados. 
O arquivo .hpp: Vetor_dinamico que contém todos os métodos e atributos para a realização de armazenamento e manipulação de dados.
Os arquivos .txt: Eles possuem os diferentes casos testes, onde os que possuem _push após a númeração do caso teste formam aqueles que foram usados para os testes dos métodos push_back e push_front e os que tem o _remove após a numeração do caso teste foram usados como entradas de testes no metódo remove. Para o .txt do teste_pop foram usados para teste os mesmos que o _push.
Quando falamos de lista ligada ela possui uma estrutura muito parecida na organização dos arquivos com o vetor dinâmico possuindo 5 arquivos .cpp, 1 arquivo .hpp e 11 .txt. As pontuais difereças com a estrutura dos arquivos de vetor dinâmico é o fato do linked list possuir um arquivo .cpp a mais que tem como finalidade pequenos testes para conferir o funcionamento correto de todos os métodos, os arquivos .txt em vez de ser e1.txt por exemplo aqui é a1.txt, o teste do push front e remove é respectivamente teste_pushfront e teste_removeat e por último o arquivo .hpp se chama Linked_list. 
OBS: No relatório todos os nomes do arquivos .txt são correspondende aos que estão nos arquivos. Por exemplo, o e1.txt na tabela do push_front no relatório está como e1_push.txt nos arquivos de códigos. 
Para realizar os testes basta compilar o arquivos .cpp colocando cada teste corresponte ao seu arquivo, abaixo conterá um exemplo prático de como compilar e testar cada arquivo:
--Vetor dinâmico--
°Push_back e push_front
g++ -Wall -o p teste_pushV.cpp
  ./p < e1_push.txt
°Remove_at
g++ -Wall -o r teste_remove.cpp
  ./r < e1_remove.txt
° Pop_back
g++ -Wall -o b teste_pop.cpp
  ./b < e1_push.txt
  
--Lista ligada--
°Push_back e push_front
g++ -Wall -o p teste_pushfront.cpp
  ./p < a1_push.txt
°Remove_at
g++ -Wall -o r teste_removeat.cpp
  ./r < a1_remove.txt
° Pop_back
g++ -Wall -o b teste_pop.cpp
  ./b < a1_push.txt

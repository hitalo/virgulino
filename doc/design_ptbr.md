# Virgulino C version Project Design (PT-BR).


Introdução
---

Bem, os nomes de arquivos nos cabeçalhos e as funções dos arquivos 
são cuidadosamente escolhidos para ajudar o programador a entender 
o que cada função faz e para uma melhor compreensão sobre as
responsabilidades no projeto como um todo.

Definições de projeto em cabeçalhos
---

 **color_set.h** -
 
   Um conjunto de códigos para definir as cores na saída. Pode ser útil
   por muitas razões.

 **definitions.h** -

   Um grupo de macros e definições pré-compiladas para serem 
   usados em diferentes cabeçalhos. 

 **output.h** -

   Tem todas as funções para lidar com qualquer saída fornecida 
   pelo Virgulino.

 **virgulinho.h** -

   Onde argumentos de linha de comando são tratados e variáveis 
   são configuradas para satisfazer os argumentos apropriados
   fornecidos pelo usuário final.

 **cypher_utils.h** -

   Um conjunto de funções utilitárias para ajudar nos processos de
   cifrar/criptografar decifrar/descriptografar.

 **cypher.h** -

   As funções que irão, de fato, criptografar/descriptografar 
   a mensagem.
 
 **main.c** -

   Onde tudo acontece.

Conclusão
---

Este é o grupo de cabeçalhos e suas respectivas responsabilidades.
Eu desenhei o projeto dessa forma porque acredito que isso irá 
ajudar qualquer um a entender a estrutura do projeto e, consequen-
temente, contribuir.


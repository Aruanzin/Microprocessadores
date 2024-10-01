# Atividade Semanal 5 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |

## Questão 10

Responda com **Verdadeiro (V)** ou **Falso (F)** às seguintes afirmações sobre a Pilha (Stack):

- ( **F** ) A pilha é uma memória RAM sequencial do tipo FIFO.

- ( **V** ) A pilha geralmente é utilizada para armazenar endereço de retorno de sub-rotinas e também de interrupções.

- ( **F** ) O ponteiro de pilha (Stack Pointer) é um registrador que aponta para um endereço da memória ROM, que é o endereço de retorno do programa após o atendimento a uma interrupção ou sub-rotina.

- ( **V** ) As instruções PUSH e POP são exclusivas para operações com pilha.

- ( **F** ) A instrução CALL <endereço> deve ser usada para indicar qual endereço o programa deve desviar no caso de um atendimento à interrupção ou chamada de sub-rotina.

- ( **V** ) A instrução RET, colocada no final de uma sub-rotina, faz com que o último endereço armazenado na pilha seja carregado no registrador PC (program counter).

- ( **F** ) A área da RAM interna dedicada à pilha é determinada pelo ponteiro SP, um dos SFRs, que possui tamanho 8 bits, mesmo tamanho do barramento de endereço da CPU.

- ( **F** ) Geralmente são baseadas em flip-flops tipo D.

## Questão 11

### Refletir se existe diferença entre o endereço armazenado em um espaço de pilha e o endereço armazenado no Stack Pointer (SP)?

Sim existe diferença, enquanto o espaço de pilha representa a localização de onde o dado foi armazenado, o Stack Pointer mostra o topo da pilha, o endereço exato que será operado ao por exemplo se usar um PUSH ou PULL

## Questão 12
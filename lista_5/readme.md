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

### Supondo que um banco de 8 LEDs foi conectado à Porta P1 e um banco de 8 Switches conectado à P2 (EdSim51). Acender o LED 0 (pode ser qualquer outro) ao acionar o Switch 7 (pode ser qualquer outro). Apagar o LED ao desligar o Switch.

```
    JNB     P2.7,   LIGAR_LED   ;Pula para LIGAR_LED caso não bit 7 (LED desligado) da Porta P2
    CLR     P1.0    ; Limpa bit 0 da porta P1 (desliga LED 0)
    SJMP    FIM     ; Pula para FIM incondicionalmente
    LIGAR_LED:
    SETB    P1.0    ; Liga LED 0 da porta P1
    FIM:
```

## Questão 13

### Supondo que foram conectados um banco de 8 switches na Porta P2 (EdSim51). Escrever um programa em Assembly para monitorar, quando uma das chaves for pressionada, e indicar o número da chave pressionada em R0 (Se SW3 foi pressionada, então R0 = 3).

```
MONITORAR:
    MOV A, P2        ; Carrega o estado da Porta P2 no acumulador
    JNB P2.0, CHAVE0 ; Verifica se a chave 0 foi pressionada
    JNB P2.1, CHAVE1 ; Verifica se a chave 1 foi pressionada
    JNB P2.2, CHAVE2 ; Verifica se a chave 2 foi pressionada
    JNB P2.3, CHAVE3 ; Verifica se a chave 3 foi pressionada
    JNB P2.4, CHAVE4 ; Verifica se a chave 4 foi pressionada
    JNB P2.5, CHAVE5 ; Verifica se a chave 5 foi pressionada
    JNB P2.6, CHAVE6 ; Verifica se a chave 6 foi pressionada
    JNB P2.7, CHAVE7 ; Verifica se a chave 7 foi pressionada
    SJMP MONITORAR   ; Se nenhuma chave foi pressionada, volta a monitorar

CHAVE0:
    MOV R0, #0       ; Se a chave 0 foi pressionada, coloca 0 em R0
    SJMP MONITORAR

CHAVE1:
    MOV R0, #1       ; Se a chave 1 foi pressionada, coloca 1 em R0
    SJMP MONITORAR

CHAVE2:
    MOV R0, #2       ; Se a chave 2 foi pressionada, coloca 2 em R0
    SJMP MONITORAR

CHAVE3:
    MOV R0, #3       ; Se a chave 3 foi pressionada, coloca 3 em R0
    SJMP MONITORAR

CHAVE4:
    MOV R0, #4       ; Se a chave 4 foi pressionada, coloca 4 em R0
    SJMP MONITORAR

CHAVE5:
    MOV R0, #5       ; Se a chave 5 foi pressionada, coloca 5 em R0
    SJMP MONITORAR

CHAVE6:
    MOV R0, #6       ; Se a chave 6 foi pressionada, coloca 6 em R0
    SJMP MONITORAR

CHAVE7:
    MOV R0, #7       ; Se a chave 7 foi pressionada, coloca 7 em R0
    SJMP MONITORAR
```


## Questão 14

### Criar uma subrotina de delay de 50 milissegundos a partir da contagem de ciclos de instruções e intervalo de tempo. Essa estrutura poderá servir para piscar um LED a cada 50 ms (ver exemplo na aula correspondente).

```
DELAY_50MS:
    MOV R2, #250   ; R2 = 250 (número de loops internos)
DELAY_LOOP:
    MOV R3, #200   ; R3 = 200 (número de ciclos no loop interno)
INNER_LOOP:
    DJNZ R3, INNER_LOOP   ; Decrementa R3 até zero, 200 ciclos
    DJNZ R2, DELAY_LOOP   ; Decrementa R2, 250 loops
    RET
```

## Questão 15

**Resposta:** O programa verifica qual chave foi pressionada e executa as seguintes ações:

* Pressionar P2.0 apaga os LEDs.
* Pressionar P2.1 acende os LEDs P1.0 e P1.2.
* Pressionar P2.2 inverte o estado de todos os LEDs em P1.
# Atividade Semanal 4 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |


## Questões sobre Transferência de Dados:

1. **Qual foi o tempo gasto em cada linha de instrução e quantos ciclos de máquina esse programa contém? Justifique sua resposta.**
```
    MOV A, #12h          ; 1us
    MOV A, #0             ; 1us
    MOV R2, #34h           ; 1us
    MOV B, #56            ; 2us
    MOV 0x40, P1        ; 2us
    MOV R4, P1         ; 2us
    MOV 0x50, R4          ; 2us
    MOV R1, #0x50   ; 1us
    MOV A, @R1            ; 1us
    MOV DPTR, #0x9A5B     ; 2us
```

Acima temos o código com o tempo de cada instrução (us = microssegundos). Ou seja temos 15 ciclos de máquina ao total.

2. **O que aconteceu ao mover uma porta inteira de 8 registradores (ex.: MOV A, P1) para um destino e por que seu valor é FF?**

Por padrão todas as portas de entrada e saída (P0, P1, P2, P3) tem o valor 1 em todas as suas casas em binário, sendo isso o equivalente a FF em binário, e o que a gente fez no código foi atribuir o valor dessa porta no local de R4

3. **Qual valor apareceu no acumulador após ter movido R1 de forma indireta para ele?**

No R1 havia o valor 0x50 e ao mover de forma indireta, não foi o valor de 0x50 e sim o valor que estaria nesse endereço, e no fim estava 0xFF que era o que tinha armazenado no data memory

4. **Por que foi possível mover um valor de 4 dígitos para DPTR? Em quaisregistradores especiais do simulador foi possível verificar mudanças quando essa operação foi realizada? Qual o maior valor que pode ser movido para DPTR em hexadecimal?**

O DPTR é um registrador de 16 bits, ou seja, é possível mover um valor de 4 digitos hexadecimal para lá, o maior de todos é 0xFFFF.



## Questões sobre e Instruções Aritméticas:

1. **Por que ao mover o valor 4 para ACC, o bit menos significativo de PSW resulta em 1; e ao mover o valor 3, esse bit resulta em 0?**

O PSW serve para mostrar a "paridade" da quantidade de bits que é necessário para representar o número, se for par é 0 e ímpar é 1

nesse caso por exemplo: 4 -> 100 PSW=1.
nesse caso por exemplo: 3 -> 11 PSW=0.

2. **Tente decrementar 1 unidade de algum registrador ou endereço de memória cujo valor é igual a zero (ex. DEC A, DEC Rn, ou DEC 60h, sendo A, Rn, ou 60h iguais a zero). Por que a operação resulta em FF?**

Essa operação resulta em 0xFF mesmo, pois não há nenhum número menor que zero possível para decrementar então é atribuido o maior.

## Atividade 2

```
ORG 00h          ; Origem no endereço 00h
SJMP MAIN        ; Ir para a main

ORG 33h          ; Origem no endereço 33h

MAIN:
    MOV R0, #20h ; Inicializar R0 com valor #20h (ponteiro para a primeira posição de memória)
    MOV R1, #0   ; Inicializar R1 com #0 (contador de valores menores que #45h)

LACO:
    MOV A, @R0   ; Armazenamento indireto de R0 para A
    SUBB A, #45h ; Subtrai #45h de A
    JNC FIMLACO     ; Ir para FIMLACO se tiver PSW=0
    INC R1       ; Adiciona 1 unidade em R1 

FIMLACO:
    INC R0       ; Adiciona 1 unidade em R0
    CJNE R0, #24h, LACO ; Comparar R0 com #24h e saltar para LOOP se não forem iguais

    SJMP $       ; Nenhuma operação, segurar o programa nesta linha

END              ; Fim do programa
```



O programa compara todas as posições de memória de 20h a 23h, contando quantos valores são menores a 45h. A informação é registrada no registrador R1. Depois de verificar todas as posições de memória, o programa entra em um loop sem fim, possibilitando a leitura ou verificação do valor em R1. Este comportamento é benéfico para aplicações que necessitam contar os valores que cumprem uma condição específica dentro de um intervalo de memória específico.

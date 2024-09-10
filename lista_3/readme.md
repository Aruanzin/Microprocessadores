# Atividade Semanal 3 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |

## Questão 8

### Instruções:
1. **MOV R0, #22h**: 
   - Carrega o valor imediato `22h` no registrador `R0`.
   
2. **MOV 00h, #22h**: 
   - Carrega o valor imediato `22h` na posição de memória `00h`.

#### Diferença entre as duas instruções:
- **MOV R0, #22h** utiliza um registrador para armazenar o valor.
- **MOV 00h, #22h** armazena o valor diretamente na RAM (posição `00h`).
- A diferença nos ciclos de máquina ocorre porque acessar diretamente a RAM pode ser mais lento do que utilizar um registrador, dependendo da arquitetura do microcontrolador.

---

3. **MOV A, #22h**: 
   - Carrega o valor imediato `22h` no Acumulador (`A`).
   
4. **MOV ACC, #22h**: 
   - Carrega o valor imediato `22h` no Acumulador (`ACC`).

#### Diferença entre as duas instruções:
- **MOV A, #22h** e **MOV ACC, #22h** são equivalentes, pois `A` e `ACC` referem-se ao mesmo registrador.
- Possuem o mesmo ciclo de máquina, porém em algumas arquiteturas, a codificação das instruções pode variar levemente, sem impacto funcional.

---


## Questão 9

Baseado na figura do microcontrolador genérico de 8 bits, responda às seguintes afirmações com **Verdadeiro (V)** ou **Falso (F)**:

- ( **V** ) Trata-se de um microcontrolador de arquitetura Harvard.
  - A arquitetura Harvard tem memórias separadas para instruções e dados.

- ( **V** ) A memória EEPROM é de 4Kbytes e armazena as instruções que comandam o microcontrolador.
  - EEPROM é usada para armazenar o código do programa.

- ( **V** ) A memória SRAM é de 512 bytes e armazena dados voláteis.
  - A SRAM é a memória volátil usada para armazenar dados temporários.

- ( **F** ) O registrador IR tem a função de armazenar a instrução lida da memória SRAM.
  - O IR armazena a instrução vinda da memória de programa (EEPROM), não da SRAM.

- ( **V** ) Para esse microcontrolador, o registrador IR deve ser de 8 bits.
  - Microcontroladores de 8 bits geralmente têm um IR de 8 bits.

- ( **V** ) O registrador PC armazena o endereço da instrução lida da memória EEPROM.
  - O PC (Program Counter) aponta para o endereço da próxima instrução a ser executada.

- ( **F** ) Para esse microcontrolador, o registrador PC deve ser de 10 bits.
  - Com 4K de EEPROM, o PC precisaria de pelo menos 12 bits para endereçar todas as instruções.

- ( **V** ) Para esse microcontrolador, o registrador ACC deve ser de 8 bits.
  - O Acumulador (ACC) é de 8 bits em microcontroladores de 8 bits.

- ( **F** ) O registrador DPTR é um ponteiro que aponta para a última instrução lida da memória.
  - O DPTR (Data Pointer) aponta para dados, não para instruções.

- ( **F** ) Para esse microcontrolador, o registrador DPTR deve ser de 10 bits.
  - O DPTR normalmente é de 16 bits, usado para endereçamento de dados em memória externa.

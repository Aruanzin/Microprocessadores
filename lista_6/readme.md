# Atividade Semanal 6 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |

-------

* A atividade semanal foi um roteiro seguido em sala para nos introduzir à IDE Mikro C, ao simulador SimulIDE e ao PIC, o usado em aula foi o PIC18F4550.

Abaixo está o código corrigido em questão do delay para que ele não ficasse acendendo e apagando quando se mantesse o botão pressionado

```bash
void main() {
    unsigned char FlagAux = 0; // Variável para controlar o estado do botão e evitar múltiplas mudanças no LED

    ADCON1 |= 0xF; // Configura os pinos como digitais

    trisb.rb0 = 1; // Configura RB0 como entrada (botão)
    PORTB.RB0 = 1; // Ativa pull-up em RB0

    TRISD.RD0 = 0; // Configura RD0 como saída (LED)
    PORTD.RD0 = 0; // LED inicialmente apagado

    while(1) {
        if(PORTB.RB0 == 0 && FlagAux == 0) { // Se o botão for pressionado e a FlagAux for 0
            PORTD.RD0 = ~LATD.RD0; // Inverte o estado do LED
            FlagAux = 1; // Atualiza a FlagAux para indicar que o botão foi
```

Junto a essa pasta da lista 6 está anexado duas imagens que ilustram o ambiente de simulação do SimulIDE mostrando o circuito.
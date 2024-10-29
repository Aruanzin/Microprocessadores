# Atividade Semanal 6 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |

-------

* A atividade semanal foi um roteiro seguido em sala para nos introduzir à IDE Mikro C, ao simulador SimulIDE e ao PIC, o usado em aula foi o PIC18F4550.

## Parte 1

Com base no exemplo 5 de aula foi simulado pelo SimulIDE o programa que ligava e desligava um LED conforme um clock, relacionado a TMR0. Código abaixo

```
void ConfigMCU()   // função de config. do microcontrolador
{
  // Configurando os pinos como digitais
  ADCON1 |= 0x0F;
  
 // Config. das portas
   TRISC = 0;    // PORTD como saída  (usar LED)
   PORTC = 0;    // LED inicialmente OFF

}

void ConfigTIMER()    // função p/ config. o timer
{
 // Programaçao do TMR0

  T0CON = 0B00000110;  // inicialmente desligado, opera como timer, uso do clock
//  não usa borda, uso do prescaler (ativo em 0), e razão do prescaler: 110 (128)
 // ver configuração dos bits do registrador no datasheet
 
// valores iniciais carregados no timer para contagem até 1s na razão 128 e modo 16 bits
   TMR0L = 0xF7;
   TMR0H = 0xC2;
   
   INTCON.TMR0IF = 0 ; //Flag de overflow inicialmente zerada
   // vai para 1 automaticamente quando ocorre o overflow

   T0CON.TMR0ON = 1; //Liga do timer no registrador T0CON
   // seria o mesmo que T0CON = 0B10000110  (MSB = 1)
   // TMR0ON é nome do bit7, i.e.m TIMR0ON_bit =1; ou T0CON.f7
}

void main() {

// chamada das fuções definidas anteriormente
ConfigMCU();
ConfigTIMER();

while(1)
{
        if (INTCON.TMR0IF == 1)  // verifica Se houve o "overflow" da contagem
        {  // se sim:
           PORTC.RC2 = ~LATC.RC2;// inverte nível lógico do LED

           // Recarrega o timer  para o ciclo se repetir (LED piscar a cada 1s)
           // o Timer0 deve ser recarregado manualmente p/ reiniciar a contagem
            TMR0L = 0xF7;
            TMR0H = 0xC2;
            INTCON.TMR0IF = 0; // zera o flag de overflow da contagem  
            //(sempre é necessário zerar manualmente p/ reiniciar a contagem)

        } // if
          // ver configuração dos bits do registrador no datasheet PIC18F4550

} // while

}  // main
```

A partir desse primeiro foram testado novamente o programa só que desta vez utilizando o o TMR3 que fazia com que o período que o LED ficasse dimunuísse

```
void ConfigMCU()   // função de configuração do microcontrolador
{
  // Configurando os pinos como digitais
  ADCON1 |= 0x0F;

  // Configuração das portas
  TRISC = 0;    // Configura o PORTC como saída
  PORTC = 0;    // LED inicialmente OFF
}

void ConfigTIMER()    // função para configurar o timer3
{
  // Configuração do TMR3
  T3CON = 0B00110101;  // Configuração do Timer3:
                       // TMR3 inicialmente desligado, opera como timer, usa o clock,
                       // e razão do prescaler: 8 (bits T3CKPS1:T3CKPS0 = 11)

  TMR3L = 0x00;        // Carrega valor inicial zero no registrador TMR3L
  TMR3H = 0x00;        // Carrega valor inicial zero no registrador TMR3H

  PIR2.TMR3IF = 0;     // Flag de overflow do TMR3 zerada inicialmente
  T3CON.TMR3ON = 1;    // Ativa o Timer3
}

void main() {

  // Configurações iniciais
  ConfigMCU();
  ConfigTIMER();

  while(1)
  {
    if (PIR2.TMR3IF == 1)  // Verifica se houve overflow (tempo máximo atingido)
    {
      PORTC.RC2 = ~LATC.RC2; // Inverte o estado do LED (pisca a cada 262 ms)

      // Recarrega o timer para o ciclo se repetir
      TMR3L = 0x00;   // Reinicia o valor do registrador TMR3L para zero
      TMR3H = 0x00;   // Reinicia o valor do registrador TMR3H para zero
      PIR2.TMR3IF = 0; // Zera a flag de overflow do Timer3
    }
  }
}
```

E para última parte foi utilizado o TMR2:

```
void ConfigMCU()   // função de configuração do microcontrolador
{
  // Configurando os pinos como digitais
  ADCON1 |= 0x0F;

  // Configuração das portas
  TRISC = 0;    // Configura o PORTC como saída
  PORTC = 0;    // LED inicialmente OFF
}

void ConfigTIMER()    // função para configurar o timer2
{
  // Configuração do TMR2
  T2CON = 0B01111111;  // Configuração do Timer2:
                       // Prescaler = 16 (T2CKPS1:T2CKPS0 = 11),
                       // Postscaler = 16 (T2OUTPS3:T2OUTPS0 = 1111)

  PR2 = 0xFF;          // Carrega o valor máximo no registrador de período PR2
  TMR2 = 0x00;         // Inicia o Timer2 com valor zero

  PIR1.TMR2IF = 0;     // Flag de overflow do TMR2 zerada inicialmente
  T2CON.TMR2ON = 1;    // Ativa o Timer2
}

void main() {

  // Configurações iniciais
  ConfigMCU();
  ConfigTIMER();

  while(1)
  {
    if (PIR1.TMR2IF == 1)  // Verifica se houve overflow (tempo máximo atingido)
    {
      PORTC.RC2 = ~LATC.RC2; // Inverte o estado do LED (pisca a cada 327,68 ms)

      // Reinicia o Timer2 para o próximo ciclo
      TMR2 = 0x00;          // Reinicia o valor do registrador TMR2 para zero
      PIR1.TMR2IF = 0;      // Zera a flag de overflow do Timer2
    }
  }
}
```

As imagens correspondentes a esses resultados estarão destro da pasta


## Parte 2

Já aqui foi requerido que ao apertar um botão ocorresse um interrupt que fizesse com que a luz trocasse seu estado

```
void Interrupt() iv 0x0008 ics ICS_AUTO {

     if(INTCON.INT0IF == 1){
           LATD.RD1 ^= 1;
           Delay_ms(2000);
           INTCON.INT0IF = 0;
     }
}


void main() {
      ADCON1 = 0x0F;
      TRISB.RB0 = 1;
      TRISD.RD1 = 0;
      
      PORTD.RD1 = 0;
      
      INTCON2.RBPU = 0;  //PULL-UP INTERNO PORTB
      
      //CONFIG INTERRUPT
      
      INTCON.GIE = 1;
      
      INTCON.INT0IE = 1;
      INTCON.INT0IF = 0;
      INTCON2.INTEDG0 = 1;
      
      while(1){

      
      
      }
           
}
```

Imagens anexadas na pasta referente a simulação

E para última parte temos um contador que fará com que o LED acenda após 10 eventos, que na simulação foi o clique do botão, fazendo com que o LED acendesse por 1 segundo e zerasse o acumulador para reinício da contagem


```
void main() {

ADCON1=0x0F;   // Pinos digitais

TRISC.RC0=1; // RC0 como entrada pois corresponde ao pino T1CK1 que incrementa a 
//contagem do TMR1
// É um pino fixo - ou seja, deve-se obrigatoriamente usar este pino para contar no
//timer 1 - portanto é nele que deve-se ligar um sensor ou botão ou algum outro
//dispositivo que se desejar contar eventos

PORTC.RC0=1;  // em pull-up

TRISD=0;   // PORTD como entrada
PORTD=0;   //inicialmente zero (LED)

PORTD.RD1=0;

T1CON =0B10000011; // Config. do timer1 no modo contador, 16 bits, ligado

// valores iniciais para contar até 10 eventos > 65526 = FFF6 em hexadecimal
TMR1H=0xFF;
TMR1L=0xF6;

PIR1.TMR1IF=0;//Flag do timer 1 em zero (vai para 1 quando ocorre overflow)


while(1){
         if(TMR1IF_bit){  // monitora a flag - se igual 1
               PORTD.RD1=1; //ação quando totalizar 10 eventos
               TMR1H=0xFF;   //recarrega o timer para nova contagem
               TMR1L=0xF6;
               PIR1.TMR1IF=0;   //zera flag para nova contagem
               Delay_ms(1000);    // aguarda um tempo com a sinalização acionada
               }
         else{
         PORTD.RD1=0; // LED desligado caso contrário
         }
 
 }

}
```

imagens referentes a simulação serão anexadas na pasta
void ConfigMCU() // funcao de config. do microcontrolador
{
  // Configurando os pinos como digitais
  ADCON1 |= 0x0F;

  // Config. das portas
  TRISD = 0; // PORTD como saida  (usar LED)
  PORTD = 0; // LED inicialmente OFF

  INTCON2.RDPU = 0;
}

void ConfigTIMER() // fun??o p/ config. o timer
{
  // Programacao do TMR0
  T0CON = 0B00000010; // TIMER_OFF, MOD_16BITS, TIMER, PRES_1:32

  // Carga do valor inicial
  TMR0H = 0X0B;
  TMR0L = 0XDC;

  INTCON.TMR0IF = 0; // zera a Flag  (vai p/ 1 quando ocorrer o overflow)
}

void INTERRUPCAO_HIGH() iv 0x0008 ics ICS_AUTO
{
  // vetor de tratamento da interrup??o (endereco fixo 0x0008)
  // Definir em Tools > Interrupt Assistant
  // HIGH = interrupcao de alta prioridade
  // LOW = interrupcao de baixa prioridade (endereco 0x0018)
  // ics = servico de acionamento/tratamento da interrup??o

  // tratamento - acionar LED
  if (INTCON.INT0IF == 1) // verifica se a INT0 ocorreu
  {                       // se sim:
    T0CON.TMR0ON = 0;     // Desliga o contador TMR0 p/ configuração
    T0CON = 0B00000100;   // TIMER_OFF, MOD_16BITS, TIMER, PRES_1:32

    INTCON.INT0IF = 0; //  zera flag (precisa sempre zerar manualmente para que o
                       // programa volte a sua execucao normal e trate novas interrupcoes
    T0CON.TMR0ON = 1;  // Liga o contador TMR0 após a configuração
  }
  if (INTCON3.INT1IF == 1) // verifica se a INT1 ocorreu
  {
    T0CON.TMR0ON = 0;   // Desliga o contador TMR0 p/ configuração
    T0CON = 0B00000010; // TIMER_OFF, MOD_16BITS, TIMER, PRES_1:8

    INTCON3.INT1IF = 0; //  zera flag
    T0CON.TMR0ON = 1;   // Liga o contador TMR0 após a configuração
  }
}
void ConfigInterrupt()
{
  INTCON.GIE = 1; // Chave Geral, Habilita o uso de interrup??o
  RCON.IPEN = 0;  // 0 -> (default) heran?a da fam?lia PIC16F, onde existe apenas

  INTCON.INT0IF = 0; // zera flag de interrupcao INT0
  INTCON.INT0IE = 1; // habilita interrupcao INT0

  INTCON3.INT1IE = 1; // habilita interrupcao INT1
  INTCON3.INT1IP = 1; // coloca INT1 como alta prioridade
  INTCON3.INT1IF = 0; // zera flag de interrupcao INT1

  INTCON2.INTEDG1 = 1; // configura INT1 para borda de subida
  INTCON2.INTEDG0 = 1; // configura INT0 para borda de subida

  TRISB.RB0 = 1; // Pino RB0/INT0 como entrada
  TRISB.RB1 = 1; // Pino RB1/INT1 como entrada
}

signed char ucContador = -1; // var global  para incremento

void Incremento(unsigned char Contador) // Bloco de incremento
{
  switch (Contador)
  {
  case 0:
  {
    latd = 0b00111111;
    break;
  } // 0 no display de 7 seg.
  case 1:
  {
    latd = 0b00000110;
    break;
  } // 1 no display de 7 seg.
  case 2:
  {
    latd = 0b01011011;
    break;
  } // 2 no display de 7 seg.
  case 3:
  {
    latd = 0b01001111;
    break;
  } // 3 no display de 7 seg.
  case 4:
  {
    latd = 0b01100110;
    break;
  } // 4 no display de 7 seg.
  case 5:
  {
    latd = 0b01101101;
    break;
  } // 5 no display de 7 seg.
  case 6:
  {
    latd = 0b01111101;
    break;
  } // 6 no display de 7 seg.
  case 7:
  {
    latd = 0b00000111;
    break;
  } // 7 no display de 7 seg.
  case 8:
  {
    latd = 0b01111111;
    break;
  } // 8 no display de 7 seg.
  case 9:
  {
    latd = 0b01101111;
    break;
  } // 9 no display de 7 seg.
  case 10:
  {
    latd = 0b00111111;
    ucContador = 0;
    break;
  } // 0 no display de 7 seg. e reinicia contador
  default:
  {
    ucContador = -1;
    break;
  } // zera PORTD e reinicia contador
  }
}

void main()
{

  // chamada das fucoes definidas anteriormente
  ConfigMCU();
  ConfigTIMER();
  ConfigInterrupt();

  while (1)
  {
    if (INTCON.TMR0IF == 1)     // verifica Se houve o "overflow" da contagem
    {                           // se sim:
      Incremento(++ucContador); // recebe o Incremento do contador p/ o display de 7 segmentos

      // Recarrega o timer  para o ciclo se repetir (LED piscar a cada 1s)
      // o Timer0 deve ser recarregado manualmente p/ reiniciar a contagem

      // Carga do valor inicial
      TMR0H = 0X0B;
      TMR0L = 0XDC;

      INTCON.TMR0IF = 0; // zera o flag de overflow da contagem
      //(sempre eh necessario zerar manualmente p/ reiniciar a contagem)
    }

  } // while

} // main
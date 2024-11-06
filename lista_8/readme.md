# Atividade Semanal 8 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |


---

Essa lista é referente a atividade semanal 8, onde foi simulado alguns códigos em sala, e após isso foi recomendado que fizessemos rodar os códigos dados de exemplo pelo professor. Os códigos dos exemplos exemplo_10 e exemplo_11 estarão abaixo a a foto relacionada aos exemplos anexadas na pasta:


### Exemplo_10_ADC_LCD:
 ```
    sbit LCD_RS at LATB4_bit; // pino 4 do PORTB interligado ao RS do display
sbit LCD_EN at LATB5_bit; // pino 5 do PORTB " " ao EN do display
sbit LCD_D4 at LATB0_bit; // pino 0 do PORTB ao D4
sbit LCD_D5 at LATB1_bit;  // " "
sbit LCD_D6 at LATB2_bit;  // " "
sbit LCD_D7 at LATB3_bit;  // " "
// direção do fluxo de dados nos pinos selecionados
sbit LCD_RS_Direction at TRISB4_bit;  // direção do fluxo de dados do pino RB4
sbit LCD_EN_Direction at TRISB5_bit;  // " "
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


 // inicio do programa
void main() {
  unsigned int Leitura_ADC;   // variav. de leitura ADC
  unsigned char Texto[10];//Display LCD - tipo char - int 8 bits (lembrando: Arranjo= tipo nome [n° de elementos])


TRISA.RA0 = 1;  // pino AN0 como entrada (canal analógico escolhido neste ex.)
//PORTA.RA0 = 1;  // opcional   (pull-up)

// 3 reg. responsáveis pela config. do módulo ADC: ADCON0, ADCON1 e ADCON2
// ver config. dos bits no datasheet  https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/39632e.pdf

ADCON0 = 0B00001101;  // AN0 -> AD ligado, leitura deslig., canal AN0
ADCON1 = 0B00000000; // tensões de ref. internas = VDD e Vss

ADCON2 = 0B10101010; // Justificativa para direita, FOSC/32 (tempo entre 2 e 25 us)
//... e 12 TAD (tempo de conversão de cada bit + 2 TAD)

// Config. do módulo LCD
  Lcd_Init();                        //Inicializa display no modo 4 bits
  Lcd_Cmd(_LCD_CLEAR);               //Apaga display
  Lcd_Cmd(_LCD_CURSOR_OFF);          //Desliga cursor
  Lcd_Out(1,1,"ADC: ");              // escrita: Linha x Coluna

 while(1)
 {
   ADCON0.GO_DONE = 1;           //liga a leitura e inicia a conversão do ADC
     while(ADCON0.GO_DONE == 1);   //Aguardar o término da conversão - após a
     //conversão terminar esse bit será  = 0 e essa condição não é mais
     // verdadeira. Sendo assim, o programa vai para a próxima linha


     //Leitura_ADC = ADRESH + ADRESL;//0 a 1023; em que: '|' = OR bit a bit
    Leitura_ADC = ((ADRESH << 8)| ADRESL);
    /*
     ex.: se ADRESH = 0B00000011;
     ( ADRESH << 8) =>  00000011 00000000   // rotação de 8 bits a esquerda para
     que o valor de ADRESH fique na parte alta
     Lembrando que Leitura ADC é uma variável de 16 bits que receberá a combinação
     de ADRESH (8bits) com ADRESL(8bits) por meio do OR bitwise "|"   entre eles
     
     Lembrando também que somente 10 bits serão usados para leitura do ADC, já que
     sua resolução é 10 bits. A operação acima, portanto, usará 2 bits do ADRESH
     e 8 bits do ADRESL (justificando o valor da coversão a direita)
     
     Portanto, supondo ADRESH = 0B00000011; e ADRESL =  0B10011101 ; é necessário
     a operação acima para formar a palavra de 10 bits "11 + 10011101" = 1110011101

    Dessa forma, o OR bitwise de ADRESH e ADRESL sera:

                      00000011 00000000
                    | 00000000 10011101
    leitura_ADC =  <- 00000011 10011101 (resultado da Op. OR) - 10 bits justificado a direita

    */

      
    // mostrar os valores no display LCD = necessaio habilitar bibliotecas de
    //LCD (as linhas de código foram apresentadas anteriomente)
    // e de conversão dos dados (Leitura_ADC) para texto, apresentadas abaixo
    WordToStr(Leitura_ADC, Texto);  // conversão
    LCD_Out(1,5, Texto); // coloca o texto em determinada linha e posição 1, 5
    Delay_ms(20);       // delay para dar tempo para o LCD atualizar

   }

}
 ```

### Exemplo_11_ADC_LCD:

 ```
    #define TRUE  1  // assim: while(TRUE) = while(1)

// config. dos pinos para o LCD

// pinos utilizados para comunicação com o display LCD
sbit LCD_RS at LATB4_bit; // pino 4 do PORTB interligado ao RS do display
sbit LCD_EN at LATB5_bit; // pino 5 do PORTB " " ao EN do display
sbit LCD_D4 at LATB0_bit; // pino 0 do PORTB ao D4
sbit LCD_D5 at LATB1_bit;  // " "
sbit LCD_D6 at LATB2_bit;  // " "
sbit LCD_D7 at LATB3_bit;  // " "
// direção do fluxo de dados nos pinos selecionados
sbit LCD_RS_Direction at TRISB4_bit;  // direção do fluxo de dados do pino RB4
sbit LCD_EN_Direction at TRISB5_bit;  // " "
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

/*Programa Principal*/

void main(){

  unsigned int Valor_ADC = 0;  // var. para leitura
  unsigned char Tensao[10];    // arranjo textual para exibir no display

    //lembrando que os pinos agora devem ser configurados como analógicos
  TRISA.RA5 = 1;
  ADCON1 = 0B00000000; //Configura todos os canais como ADC no PIC18F4450


 // Configuração do módulo LCD
  Lcd_Init();                 // Inicializa a lib. Lcd
  Lcd_Cmd(_LCD_CLEAR);       // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);  // Cursor off
  Lcd_Out(1,1,"ADC0:");   //Escreve na Linha x Coluna do LCD o texto(valor do ADC)

  ADC_Init();  // uso da função da biblioteca ADC do próprio compilador
  //- incializa o módulo ADC

 while(TRUE)
  {
    Valor_ADC = ADC_Read(4); // função da biblioteca ADC do compilador para
    //leitura dos valores de 0 a 1023 (10 bits)  - ex.:  valor_ADC = 1023;
    // onde: 4 é o n° do canal analógico usado, no caso AN4, no pino RA5

    // Ajustes de escala dos valores de conversão para colocar no formato float
    // de 2 casas após a virgula. Tomando como exemplo valores de 0 a 12.34 para
    // a escala de 0 a 1023 do conversor:

    Valor_ADC = Valor_ADC * (1234/1023.); // formata o valor de entrada (neste caso o valor de exemplo '1234')
    // para 0 a 1023 -> com ponto no final para n° float,i.e.,o display mostrará: '12.34'

    // Formatando cada valor a ser exibido no display como "12.34"
    Tensao[0] = (Valor_ADC/1000) + '0';// div. de 2 n° inteiros - em programação
    // resulta na parte inteira do primeiro n° (ex.: 1234/1000 = 1)
    // E '1' + '0'  = 1; ou seja,  converte o valor para ASCI  para exibir no display

    Tensao[1] = (Valor_ADC/100)%10 + '0'; // div. de n° inteiros => 1234/100 = 12
    // '%' em ling. C é operação "mod"  c/ resto da divisão, ou seja, 12%10 = 2
    // portanto, formata o segundo n° no display no padrão ASCI ( '2' + '0' = 2)

    Tensao[2] = '.';    //3° valor corresponde ao ponto - ex. 12.34

    Tensao[3] = (Valor_ADC/10)%10 + '0'; // 4° valor é a 1ªcasa decimal, portanto:
    // 1234/10 = 123%10 = 3  - formata no padrão ASCI
    Tensao[4] = (Valor_ADC/1)%10 + '0';  // formata o valor da 2ª casa decimal

    Tensao[5] = 0; //terminador NULL (ultima posição da matriz - zero indica o
    //final opeação e limita a exibição dos 5 valores anteriores: 12.34), ou seja
    // a partir daqui, não serão mais exibidos valores, os quais poderão ser
    //adicionados caso se deseja exibir, por ex., mais casas decimais

    //floatToStr(Valor_ADC , Tensao);
    //Tensao[5] = 0;


     // Exibir os valores na config. acima no display LCD:
    Lcd_Out(1,6,Tensao); // Mostra os valores no display
    Delay_ms(20);   // atualizar display
  }
}
 ```


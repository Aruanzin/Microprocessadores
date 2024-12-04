# Atividade Semanal 9 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |



## Simulações:

```c++
#include <Arduino.h>

#define ledpin 32
void setup() { // configurações

pinMode(ledpin, OUTPUT); // pino 2 como saída (LED onboard da ESP32)
digitalWrite(ledpin,LOW); // escreve na saída  valor LOW (LED inicialmente desligado)

}

void loop() { // programa principal
  

digitalWrite(ledpin, HIGH);  // liga o LED (escreve valor lógio HIGH na saída - pino 2)
delay(500); // delay de 200 ms (Tempo que o LED fica ligado)
digitalWrite(ledpin, LOW); // desliga o LED (escreve valór lógico LOW na saída - pino 2)
delay(500); // delay de 200 ms (Tempo que o LED fica desligado)
// loop

}
```

![](LED_Blink.png)





## Comparação entre Recursos da ESP32 e PIC18F4550

### Timers
- **ESP32:** 
  - Timers são usados para contar eventos ou gerar atrasos.
  - Altamente configuráveis, permitindo precisão de microssegundos.
  - Podem ser configurados em modo de interrupção para executar ações periódicas automaticamente.

- **PIC18F4550:** 
  - Timers de 8 ou 16 bits com funcionalidade limitada.

---

### Interrupções
- **ESP32:** 
  - Suporta múltiplas fontes de interrupção, como GPIO, timers, UART, e ADC.
  - Gerenciadas por uma unidade de prioridade que garante execução eficiente e ordenada.

- **PIC18F4550:** 
  - Sistema básico com menor flexibilidade.

---

### ADC (Conversor Analógico-Digital)
- **ESP32:** 
  - Possui múltiplos canais ADC de 12 bits.
  - Pode ser configurado para leitura contínua ou pontual.
  - Suporte a calibração automática para maior precisão.

- **PIC18F4550:** 
  - ADC de 10 bits, menos preciso.

---

### DAC (Conversor Digital-Analógico)
- **ESP32:** 
  - Oferece dois canais DAC integrados de 8 bits.
  - Útil para gerar sinais analógicos a partir de valores digitais, como em aplicações de geração de áudio.

- **PIC18F4550:** 
  - Não possui DAC integrado, necessitando de circuitos externos para essa funcionalidade.

---

### Conclusão
As diferenças entre a ESP32 e o PIC18F4550 refletem o avanço da ESP32 como um microcontrolador moderno, com mais recursos integrados e maior flexibilidade.

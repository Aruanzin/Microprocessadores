# Atividade Semanal 9 - Aplicação de Microprocessadores

| Autor                          | NUSP      |
| ------------------------------ | --------- |
| Aruan Bretas de Oliveira Filho | 12609731  |
| Johnatas Santos                | 13676388  |
| Gabriel Garcia                 | 13677160  |




## Comparativo entre PIC18F4550, STM32F103C8T6, e ESP32 WROOM

#### 1. *Arquitetura e Desempenho*
- *PIC18F4550:*
  - Arquitetura RISC com modelo de memória Harvard.
  - Clock máximo de 40 MHz.
  - Desempenho adequado para aplicações simples a moderadas.

- *STM32F103C8T6:*
  - Arquitetura ARM Cortex-M3 de 32 bits.
  - Clock máximo de 72 MHz.
  - Oferece maior desempenho computacional comparado ao PIC18F4550, ideal para aplicações mais complexas.

- *ESP32 WROOM:*
  - Dual-Core Xtensa LX6 microprocessador de 32 bits.
  - Clock máximo de 240 MHz (160 MHz geralmente usado).
  - Excelente desempenho, especialmente para aplicações de processamento de dados e IoT.

#### 2. *Memória*
- *PIC18F4550:*
  - Flash: 44 KB.
  - RAM: 4 KB.
  - Memória suficiente para aplicações de menor porte.

- *STM32F103C8T6:*
  - Flash: 64 KB.
  - RAM: 20 KB.
  - Memória mais generosa, adequada para aplicações mais complexas.

- *ESP32 WROOM:*
  - Flash integrada: 432 KB (ROM) e 520 KB (RAM).
  - Possui suporte a Flash externa via SPI.
  - Memória abundante para aplicações de IoT e processamento intensivo.

#### 3. *Periféricos*
- *PIC18F4550:*
  - ADC de 10 bits com 8 canais.
  - USART, I2C, SPI.
  - PWM (CCP).
  - Timers de 8 e 16 bits.
  - GPIOs limitados.

- *STM32F103C8T6:*
  - ADC de 12 bits com 16 canais.
  - Vários USART (UART), I2C, SPI.
  - Timers de 16 e 32 bits.
  - USB On-The-Go (OTG).
  - GPIOs abundantes e flexíveis.
  - Conversor analógico-digital (ADC) de alta precisão.

- *ESP32 WROOM:*
  - ADC de 12 bits com múltiplos canais.
  - Wi-Fi e Bluetooth integrados.
  - GPIOs com suporte a touch sensing.
  - Hall sensor integrado.
  - PWM, I2C, SPI, UART.
  - RTC (Relógio de Tempo Real).

#### 4. *Consumo de Energia*
- *PIC18F4550:*
  - Baixo consumo em modos de baixa potência.
  - Adequado para aplicações com bateria, mas menos flexível em termos de modos de operação.

- *STM32F103C8T6:*
  - Modos de baixa potência eficientes, mas consumo pode ser maior em operação full-speed devido à arquitetura 32 bits.

- *ESP32 WROOM:*
  - Excelente suporte a modos de baixa potência, especialmente quando combinado com suas funcionalidades de Wi-Fi e Bluetooth.
  - Ideal para aplicações IoT com alimentação por bateria.

#### 5. *Desenvolvimento e Ferramentas*
- *PIC18F4550:*
  - Suporte através do MPLAB X IDE.
  - Compilador C gratuito (Microchip XC8).
  - Community e recursos extensos, mas curva de aprendizado pode ser mais íngreme para iniciantes.

- *STM32F103C8T6:*
  - Suporte através do STM32CubeIDE e Arduino IDE.
  - Compilador GCC (Arm GCC) gratuito.
  - Extensa documentação e exemplos, com uma grande comunidade de usuários.

- *ESP32 WROOM:*
  - Suporte através do Arduino IDE e ESP-IDF (Espressif IoT Development Framework).
  - Compilador GCC gratuito.
  - Muito popular na comunidade IoT, com uma vasta gama de bibliotecas e exemplos disponíveis.

#### 6. *Custo*
- *PIC18F4550:*
  - Geralmente mais econômico, especialmente em quantidades maiores.
  - Baixo custo de entrada, ideal para projetos de baixo orçamento.

- *STM32F103C8T6:*
  - Ligeiramente mais caro que o PIC18F4550, mas ainda muito competitivo.
  - Bom custo-benefício considerando a quantidade de recursos oferecidos.

- *ESP32 WROOM:*
  - Slightly more expensive than the other two, especially when considering the integrated Wi-Fi and Bluetooth.
  - Justificável para aplicações IoT onde a conectividade sem fio é essencial.

#### 7. *Curva de Aprendizado e Simplicidade*
- *PIC18F4550:*
  - Arquitetura mais simples, ideal para projetos de menor porte.
  - Menos complexidade em termos de recursos, o que pode simplificar o desenvolvimento.

- *STM32F103C8T6:*
  - Mais complexo devido à arquitetura 32 bits e à quantidade de recursos.
  - Requer maior familiaridade com a plataforma ARM.

- *ESP32 WROOM:*
  - Curva de aprendizado pode ser mais íngreme devido às funcionalidades de Wi-Fi e Bluetooth.
  - No entanto, a integração com o Arduino IDE e bibliotecas simplificadas pode facilitar o desenvolvimento.

### Conclusão
- *PIC18F4550:* Ideal para aplicações simples, com orçamento limitado e onde a simplicidade é um fator crítico.
  
- *STM32F103C8T6:* Uma escolha versátil para uma ampla gama de aplicações, oferecendo um bom balanceamento entre desempenho, recursos e custo.
  
- *ESP32 WROOM:* A melhor escolha para aplicações IoT que requerem conectividade sem fio, oferecendo uma combinação poderosa de desempenho, recursos e eficiência energética.

Cada microcontrolador tem suas próprias vantagens e desvantagens, e a escolha depende das necessidades específicas do projeto.

## 
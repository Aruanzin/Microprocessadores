org 0000h  ; Define o ponto de início do programa na memória

; Inicialização dos registradores
MOV R2, #00  ; Inicializa R2 com 0 (contador)
MOV R3, #2   ; Inicializa R3 com 2 (registrador usado para guardar o valor atual do delay)
MOV R4, #00  ; Inicializa R4 com 0 (flag para botão SW0 ou SW1 estiver pressionado)

JMP espera  ; Pula para "espera" para aguardar o inicio do programa

org 0033h 

espera:
    JNB P2.1, main  ; Verifica se o botão P2.1 estiver pressionado, pulando para o programa principal
    JNB P2.0, main  ; Verifica se o botão P2.0 estiver pressionado, pulando para o programa principal
    JMP espera      ; Repete a verificação dos botões

main:
    MOV DPTR, #display  ; Carrega o endereço base da tabela de display em DPTR
    MOV A, R2           ; Move o valor de R2 para o acumulador (A)
    MOVC A, @A+DPTR     ; Obtém o valor correspondente ao dígito atual da tabela de display
    MOV P1, A           ; Exibe o valor no display conectado ao P1

    JNB P2.1, seta_bit  ; Se o botão P2.1 não estiver pressionado, pula para "seta_bit"
    JNB P2.0, seta_bit  ; Se o botão P2.0 não estiver pressionado, pula para "seta_bit"

    MOV A, R4           ; Verifica o valor de R4
    JNZ checa_ou_troca  ; Se R4 não for zero, pula para "checa_ou_troca"

    CALL delay          ; Usa a sub-rotina de delay para aguardar o proximo digito
    CALL aum_contador   ; Usa a sub-rotina para incrementar o contador

    JMP main            ; Retorna ao início do loop principal

checa_ou_troca:
    MOV A, R3           ; Move o valor de R3 para o acumulador (A)
    CJNE A, #2, diferente  ; Compara A com 2; se não for igual, pula para "diferente"
    MOV R3, #8          ; Se for igual, define R3 como 8
    MOV R4, #0          ; Reseta R4
    JMP main            ; Retorna ao início do loop principal

diferente:
    MOV R3, #2         ; Define R3 como 2
    MOV R4, #0          ; Reseta R4
    JMP main            ; Retorna ao início do loop principal

seta_bit:
    MOV R4, #1          ; Define R4 como 1 para indicar que um botão foi pressionado
    JMP main            ; Retorna ao início do loop principal

aum_contador:
    INC R2              ; Incrementa o valor de R2 (contador)
    CJNE R2, #0Ah, fim_reset  ; Compara R2 com 10; se não for igual, pula para "fim_reset"
    CALL reset_se_nove  ; Se for igual, chama a sub-rotina para resetar o contador

fim_reset:
    RET                 ; Retorna da sub-rotina

reset_se_nove:
    MOV R2, #00         ; Reseta R2 para 0
    RET                 ; Retorna da sub-rotina

delay:
    MOV A, R3           ; Move o valor de R3 para o acumulador (A)
    MOV R0, A           ; Move o valor de A para R0 (contador de delay)
	MOV r1, #250		  ; Move para o registrador r1 para criar um ciclo
	mov r5, #250 		  ; Move para o registrador r1 para criar um ciclo
delay_loop:
	DJNZ r1, delay_loop
	DJNZ r5, delay_loop
    DJNZ R0, delay_loop ; Decrementa R0 e repete o loop até que R0 seja zero
    RET                 ; Retorna da sub-rotina

display:
    DB 0C0h  ; Valor para exibir '0' no display
    DB 0F9h  ; Valor para exibir '1' no display
    DB 0A4h  ; Valor para exibir '2' no display
    DB 0B0h  ; Valor para exibir '3' no display
    DB 99h   ; Valor para exibir '4' no display
    DB 92h   ; Valor para exibir '5' no display
    DB 82h   ; Valor para exibir '6' no display
    DB 0F8h  ; Valor para exibir '7' no display
    DB 80h   ; Valor para exibir '8' no display
    DB 90h   ; Valor para exibir '9' no display

end  ; Fim do código
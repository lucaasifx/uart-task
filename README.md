# 📌 Controle de LEDS WS2812, Display SSD1306 e Comunicação Serial com RP2040
## 📖 Descrição do Projeto
Este projeto tem como objetivo consolidar os conceitos de comunicação serial (UART e I2C) e manipulação de LEDs com a placa BitDogLab (RP2040). Ele inclui o controle de uma matriz 5x5 de LEDs WS2812, um display OLED SSD1306 e a interação com botões físicos via interrupções.

### 🎯 Objetivos do Projeto:
- Compreender e aplicar comunicação serial (UART e I2C) em microcontroladores.
- Manipular LEDs endereçáveis WS2812 e LEDs comuns (RGB).
- Implementar um sistema de debouncing via software para os botões.
- Desenvolver um sistema eficiente utilizando interrupções (IRQ) para eventos.
- Integrar entrada de caracteres via PC (Serial Monitor do VS Code) e exibição no display SSD1306.

## 🖥️ Requisitos
- Placa BitDogLab
- VS Code
- Extensão Raspberry Pi Pico
- SDK do Raspberry Pi Pico configurado
- CMake para compilar o projeto
- MinGW (Windows) ou GCC (Linux/macOS) para compilar

## 🛠 Componentes Utilizados
- Placa BitDogLab (RP2040)
- Matriz de LEDs WS2812 (5x5) → GPIO 7
- LED RGB → GPIOs 11, 12 e 13
- Botão A → GPIO 5
- Botão B → GPIO 6
- Display SSD1306 (I2C) → GPIOs 14 e 15

## 🔧 Funcionalidades Implementadas
1️⃣ Modificação da Biblioteca font.h 
- ✅ Adição de caracteres minúsculos à biblioteca de fontes.

2️⃣ Entrada de Caracteres via UART (Serial Monitor)<br>
- ✅ Caracteres digitados no Serial Monitor são exibidos no display SSD1306.<br>
- ✅ Números (0-9) também acendem símbolos na matriz 5x5 WS2812.

3️⃣ Interação com o Botão A<br>
- ✅ Pressionar o Botão A alterna o LED Verde (ligado/desligado).<br>
- ✅ O estado do LED é mostrado no display SSD1306 e enviado ao Serial Monitor.

4️⃣ Interação com o Botão B<br>
- ✅ Pressionar o Botão B alterna o LED Azul (ligado/desligado).<br>
- ✅ O estado do LED é mostrado no display SSD1306 e enviado ao Serial Monitor.

## 📂 Estrutura do Projeto
O projeto foi desenvolvido em C e utiliza o simulador Wokwi para emular o circuito. A estrutura de diretórios é organizada para facilitar o desenvolvimento e a compilação com a extensão Raspberry Pi Pico no VS Code.

Diretórios Principais
- ```src/```: Contém o arquivo principal do código-fonte (main.c).
- ```src/lib/```: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.

## 🚀 Como Executar o Projeto
1. Clone este repositório:
   
```bash
   git clone https://github.com/lucaasifx/uart-task.git
```


2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** está instalada e configurada corretamente.
4. Clique no ícone da extensão da Pico<br>
  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)
5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Import:<br>
![image](https://github.com/user-attachments/assets/13751bd3-93a4-41bd-8278-51e60bff51ce)

6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)
7. Coloque a BitDogLab no modo BOOTSELL e carregue o software:<br>
![image](https://github.com/user-attachments/assets/ea3cc647-49e4-4803-a10f-d5afc3cdfae0)
   - Acesse o monitor serial do VS Code.<br>
   - Habilite a opção Toggle Terminal Mode para permitir inputs do teclado no terminal da Pico<br>
![image](https://github.com/user-attachments/assets/73e4a436-7124-433d-af02-82d905ae0e03)
   - Selecione a opção Start Monitoring e pressione ```ENTER``` para exibir o Menu Principal<br>
![image](https://github.com/user-attachments/assets/877104d3-25f2-4f56-8aeb-bc32831c099d)



## 🎥 Demonstração
📌 Um vídeo de demonstração foi gravado, apresentando:
- ✅ Explicação das funcionalidades.
- ✅ Execução do código na placa BitDogLab.
- ✅ Interação com botões e LEDs.
- 🔗 [Vídeo de demonstração no hardware](https://youtu.be/jjjKSBAi-HM)
##

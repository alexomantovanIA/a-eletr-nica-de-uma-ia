# FIAP - Faculdade de Informática e Administração Paulista

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# A Eletrônica de uma IA

## Nome do grupo

## 👨‍🎓 Integrantes:

- <a href="https://www.linkedin.com/company/">Edmar Ferreira Souza</a>
- <a href="https://www.linkedin.com/company/">Thiago Lima Bernardes</a>
- <a href="https://www.linkedin.com/company/">Alexandre Oliveira Mantovani</a>
- <a href="https://www.linkedin.com/company/">Ricardo Lourenço Coube</a>

## 👩‍🏫 Professores:

### Tutor(a)

- <a href="https://www.linkedin.com/in/lucas-gomes-moreira-15a8452a/">Lucas Gomes Moreira</a>

### Coordenador(a)

- <a href="https://www.linkedin.com/in/profandregodoi/">André Godoi</a>

## 📜 Descrição

Este projeto visa a criação de um sistema de monitoramento e controle ambiental usando um ESP32 e diversos sensores para leitura de temperatura, umidade, luminosidade, movimento e nível de água. A partir dessas informações, o sistema pode acionar um relé para irrigação automática e um buzzer para alerta de presença detectada.

## 📁 Estrutura de pastas

Dentre os arquivos e pastas presentes na raiz do projeto, definem-se:

- <b>assets</b>: aqui estão os arquivos relacionados a elementos não-estruturados deste repositório, como imagens.

- <b>docs</b>: aqui estão os arquivos relacionados a documentação do projeto, incluindo a descrição do sistema e explicações sobre cada sensor.

- <b>src</b>: aqui estão os arquivos códigos-fonte do projeto.

- <b>tests</b>: aqui estão os arquivos relacionados a testes manuais para validar o funcionamento do projeto.

- <b>README.md</b>: arquivo que serve como guia e explicação geral sobre o projeto (o mesmo que você está lendo agora).

## 🔧 Como executar o código

Instruções de Instalação, Dependências, Configuração e execução no Wokwi e ESP32

1. Instale o [Arduino IDE](https://www.arduino.cc/en/software).
2. Adicione a placa ESP32 no gerenciador de placas.
3. Instale a biblioteca `DHT sensor library` para leitura de temperatura e umidade.
4. Conecte o ESP32 e faça o upload do código.
5. Abra o [Wokwi](https://wokwi.com/) e selecione o ESP32.
6. Adicione os componentes DHT22, PIR, LDR, HC-SR04, relé e buzzer.
7. Conecte os pinos conforme o diagrama fornecido.
8. Carregue o código e inicie a simulação.

### Funcionalidades

O circuito inclui os seguintes sensores e atuadores conectados ao ESP32:

- DHT22 para leitura de temperatura e umidade.
- PIR para detecção de movimento.
- LDR para medir luminosidade.
- HC-SR04 para monitoramento do nível de água.
- Relé para controle de uma bomba de água (irrigação).
- Buzzer para alerta sonoro.

- <a href="https://wokwi.com/projects/413022790721733633">Circuito Wokwi e ESP32</a>

Pinos Utilizados

- DHT22: GPIO 15
- PIR: GPIO 18
- LDR: GPIO 32
- Relé: GPIO 19
- Buzzer: GPIO 22
- HC-SR04: Trig - GPIO 4, Echo - GPIO 5

Descrição do Papel de Cada Sensor no Sistema

- DHT22: Captura a temperatura e umidade do ambiente.
- PIR (Passive Infrared): Detecta movimento no ambiente, ativando o buzzer para alertas de intrusos.
- LDR (Light Dependent Resistor): Mede a intensidade de luz para evitar irrigação em condições de alta luminosidade.
- HC-SR04: Mede a distância até a superfície da água, determinando o nível de água e permitindo irrigação caso o nível seja suficiente.
- Relé: Controla a bomba de água para irrigação com base nas condições lidas.
- Buzzer: Emite um som de alerta ao detectar movimento.

Testes Realizados

- Leitura de sensores: Verificação de leituras no Monitor Serial.
- Controle de irrigação: Teste das condições para ativação e desativação do relé.
- Detecção de movimento: Verificação do alerta sonoro com o buzzer.

Prints do Monitor Serial

- Mensagens de leitura de temperatura, umidade e luminosidade.
- Distância medida pelo sensor ultrassônico.
- Alertas de irrigação ativada e desativada.
- Detecção de movimento.

Funções Principais

setup(): Configura o sistema e inicializa os pinos do ESP32 para cada sensor e atuador. Configura a comunicação serial para exibir as leituras e define o estado inicial dos pinos, como o relé (irrigação) e o buzzer (alerta de movimento).

loop(): Função principal do sistema, responsável por:

- Leitura dos Sensores: Lê a temperatura e umidade (DHT22), luminosidade (LDR), nível de água (HC-SR04) e detecta movimento (PIR).
- Controle de Irrigação: Verifica as condições de temperatura, umidade, luminosidade e nível de água para ativar ou desativar o sistema de irrigação automaticamente.
- Alerta de Movimento: Aciona o buzzer quando o sensor PIR detecta movimento no ambiente.

lerTemperaturaUmidade(): Realiza a leitura da temperatura e umidade do ambiente através do sensor DHT22. Retorna os valores de temperatura e umidade para serem utilizados no controle de irrigação e monitoramento.

lerLuminosidade(): Lê o valor da luminosidade ambiente usando o sensor LDR. O valor retornado ajuda a evitar a ativação da irrigação durante períodos de alta luminosidade (indicando luz do dia).

lerNivelAgua(): Calcula a distância até a superfície da água usando o sensor ultrassônico HC-SR04. Retorna a distância, que indica o nível de água, para garantir que o sistema de irrigação só seja ativado se houver água suficiente.

detectarMovimento(): Verifica o estado do sensor PIR para identificar se há movimento no ambiente. Se movimento for detectado, o buzzer é acionado por um curto período para alertar.

## 🗃 Histórico de lançamentos

- 1.0.0 - 10/11/2024

## 📋 Licença

<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/agodoi/template">MODELO GIT FIAP</a> por <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://fiap.com.br">Fiap</a> está licenciado sobre <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">Attribution 4.0 International</a>.</p>

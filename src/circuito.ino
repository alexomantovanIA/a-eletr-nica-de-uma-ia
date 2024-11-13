
#include <DHT.h>
#define DHTPIN 15         // GPIO para o sensor DHT22
#define DHTTYPE DHT22     // Tipo do sensor DHT
#define PIR_PIN 18        // GPIO para o sensor PIR
#define LDR_PIN 32        // GPIO para o sensor LDR
#define RELAY_PIN 19      // GPIO para o relé da bomba de água
#define BUZZER_PIN 22     // GPIO para o buzzer
#define TRIG_PIN 4        // GPIO para o Trig do HC-SR04
#define ECHO_PIN 5        // GPIO para o Echo do HC-SR04

DHT dht(DHTPIN, DHTTYPE);  // Inicializa o sensor DHT

float temperatura, umidade;  // Variáveis para armazenar temperatura e umidade
int luminosidade;            // Variável para armazenar a luminosidade lida pelo LDR
bool movimentoDetectado = false; // Flag para indicar movimento detectado pelo PIR
long duracao;                // Duração do pulso do sensor ultrassônico
int distancia;               // Distância medida pelo sensor ultrassônico

void setup() {
  Serial.begin(115200);      // Inicializa a comunicação serial
  dht.begin();               // Inicializa o sensor DHT
  pinMode(PIR_PIN, INPUT);   // Configura o pino PIR como entrada
  pinMode(LDR_PIN, INPUT);   // Configura o pino LDR como entrada
  pinMode(RELAY_PIN, OUTPUT);// Configura o pino do relé como saída
  pinMode(BUZZER_PIN, OUTPUT); // Configura o pino do buzzer como saída
  pinMode(TRIG_PIN, OUTPUT); // Configura o pino TRIG do ultrassônico como saída
  pinMode(ECHO_PIN, INPUT);  // Configura o pino ECHO do ultrassônico como entrada

  digitalWrite(RELAY_PIN, LOW);  // Desativa o relé (irrigação)
  digitalWrite(BUZZER_PIN, LOW); // Desativa o buzzer
}

void loop() {
  // Leitura do sensor DHT22 para obter temperatura e umidade
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.print(" °C");
  Serial.print(" - Umidade: "); Serial.print(umidade); Serial.println(" %");

  // Leitura do sensor LDR para medir a intensidade de luz
  luminosidade = analogRead(LDR_PIN);
  Serial.print("Luminosidade: "); Serial.println(luminosidade);

  // Leitura do sensor ultrassônico HC-SR04 para medir o nível de água
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duracao = pulseIn(ECHO_PIN, HIGH);
  distancia = duracao * 0.034 / 2;
  Serial.print("Distância do nível de água: "); Serial.print(distancia); Serial.println(" cm");

  // Verifica o estado do sensor PIR para detecção de movimento
  movimentoDetectado = digitalRead(PIR_PIN);
  if (movimentoDetectado) {
    Serial.println("Movimento detectado!");
    digitalWrite(BUZZER_PIN, HIGH); // Ativa o buzzer ao detectar movimento
    delay(1000);  
    digitalWrite(BUZZER_PIN, LOW);  // Desativa o buzzer após o alerta
  }

  // Controle de irrigação com base nas leituras dos sensores
  if (umidade < 50 && temperatura > 25 && distancia < 20) { // Condições para irrigação
    if (luminosidade < 600) {
      digitalWrite(RELAY_PIN, HIGH);  // Ativa a bomba de água
      Serial.println("Irrigação ativada.");
    }
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Desativa a bomba de água
    Serial.println("Irrigação desativada.");
  }

  delay(2000);  // Intervalo entre leituras e atualizações
}

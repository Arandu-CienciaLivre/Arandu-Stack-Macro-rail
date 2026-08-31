/*
 * Arandu Stack Macro Rail
 * Firmware v1.0.0
 *
 * Copyright (C) 2026 Pedro José Vieira de Souza
 *
 * Autor / Author: Pedro José Vieira de Souza
 * Citação acadêmica / Academic citation: SOUZA, P. J. V.
 *
 * [PT-BR]
 * Este programa é software livre: você pode redistribuí-lo e/ou
 * modificá-lo sob os termos da GNU General Public License,
 * versão 3 (GPL v3.0).
 *
 * Este programa é distribuído na expectativa de que seja útil,
 * porém SEM QUALQUER GARANTIA, na extensão permitida pela
 * legislação aplicável.
 *
 * [EN]
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 (GPL v3.0).
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, to the extent permitted by applicable law.
 *
 * See the LICENSE file included with this project for the full
 * GNU General Public License v3.0 terms.
 *
 * Projeto / Project: Arandu Stack Macro Rail
 */

#include <Wire.h>                  // Inclui biblioteca de comunicacao I2C.
#include <LiquidCrystal_I2C.h>     // Inclui biblioteca do LCD I2C.
#include <AccelStepper.h>          // Inclui biblioteca para motor de passo com aceleracao.
#include <EEPROM.h>                // Inclui biblioteca para salvar configuracoes na EEPROM.

// ============================================================
// LCD
// ============================================================

LiquidCrystal_I2C lcd(0x27, 20, 4); // Define LCD I2C no endereco 0x27, com 20 colunas e 4 linhas.

// ============================================================
// PINAGEM - ARDUINO NANO
// ============================================================

const byte STEP_PIN       = 2;      // Pino STEP do driver.
const byte DIR_PIN        = 3;      // Pino DIR do driver.
const byte ENABLE_PIN     = 4;      // Pino ENABLE do driver; LOW habilita o driver.
const byte SHUTTER_PIN    = 5;      // Pino que aciona o optoacoplador da camera.
const byte ENDSTOP_HOME   = 6;      // Fim de curso inicial, usado somente como seguranca.
const byte ENDSTOP_FINAL  = 7;      // Fim de curso final, usado somente como seguranca.
const byte ENC_CLK        = 8;      // Pino CLK do encoder KY-040.
const byte ENC_DT         = 9;      // Pino DT do encoder KY-040.
const byte ENC_SW         = 10;     // Pino SW do encoder KY-040.
const byte BTN_A          = 11;     // Botao fisico A.
const byte BTN_B          = 12;     // Botao fisico B.
const byte BATTERY_PIN    = A0;     // Entrada analogica para leitura da bateria.

// A4 = SDA do LCD I2C.
// A5 = SCL do LCD I2C.

// ============================================================
// LEITURA DE BATERIA 3S
// ============================================================

const float BAT_R1 = 100000.0;      // Resistor superior do divisor ligado ao positivo da bateria.
const float BAT_R2 = 33000.0;       // Resistor inferior do divisor ligado ao GND.
const float ADC_REF = 5.0;          // Tensao de referencia do ADC do Nano.
const float ADC_MAX = 1023.0;       // Valor maximo do ADC de 10 bits.

// ============================================================
// MOTOR
// ============================================================

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN); // Cria controle do motor em modo STEP/DIR.

// ============================================================
// CONFIGURACOES GERAIS
// ============================================================

float passosPorMM = 800.0;          // Define passos por milimetro para fuso de 2 mm com 1/8 microstep.
long cursoTotalAtual = 50000;       // Define limite logico relativo para movimento sem HOME.
const float velocidadeRapida = 1200; // Define velocidade rapida geral em passos por segundo.
const float velocidadeLenta  = 200;  // Define velocidade lenta geral em passos por segundo.
const float aceleracaoMotor  = 800;  // Define aceleracao geral do motor.
long passoManualLentoUm  = 10;       // Define movimento lento como 10 micrometros por click do encoder.
long passoManualMedioUm  = 250;      // Define movimento medio como 250 micrometros por click do encoder.
long passoManualRapidoUm = 4000;     // Define movimento rapido como 4000 micrometros, ou 4 mm, por click do encoder.
float velMoverLentaMMs   = 0.25;     // Define velocidade do mover lento em milimetros por segundo.
float velMoverMediaMMs   = 2.00;     // Define velocidade do mover medio em milimetros por segundo.
float velMoverRapidaMMs  = 20.00;    // Define velocidade do mover rapido em milimetros por segundo.
byte modoMover = 1;                  // Define velocidade inicial do mover: 0=LENTO, 1=MEDIO, 2=RAPIDO.

// ============================================================
// POSICOES
// ============================================================

long posicaoAtual = 0;              // Guarda posicao logica atual.
long pontoA = 0;                    // Guarda ponto A.
long pontoB = 0;                    // Guarda ponto B.
bool pontoADefinido = false;        // Indica se ponto A foi definido.
bool pontoBDefinido = false;        // Indica se ponto B foi definido.

// ============================================================
// PARAMETROS DO STACKING
// ============================================================

int stackFotos = 20;                                // Define numero inicial de fotos.
long stackPassosPorFoto = 80;                     // Define passo interno por foto; interface mostra em micrometros.
unsigned long stackAtrasoInicialMs = 2000;          // Define atraso antes da primeira foto.
unsigned long stackTempoDisparoMs = 500;           // Define tempo de disparo.
unsigned long stackTempoPosFotoMs = 3000;           // Define espera depois do disparo.
unsigned long stackTempoEstabilizacaoMs = 500;     // Define espera depois do movimento.
bool stackSentidoAB = true;                         // Define direcao inicial A>B.
byte stackRetorno = 0;                              // Define retorno: 0=Nao, 1=A, 2=B.

// ============================================================
// PARAMETROS DO BULB
// ============================================================

int bulbDisparos = 1;                       // Define quantidade de fotos no modo Bulb.
unsigned long bulbTempoMs = 5000;           // Define tempo de exposicao Bulb.
unsigned long bulbTempoPosFotoMs = 500;     // Define espera depois de cada foto Bulb.
unsigned long bulbAtrasoInicialMs = 2000;   // Define atraso inicial do Bulb.
unsigned long bulbIntervaloMs = 2000;       // Define intervalo entre fotos Bulb.

// ============================================================
// PARAMETROS DO SLIDER
// ============================================================

bool sliderSentidoAB = true;                        // Define direcao inicial do Slider: A>B.
float sliderVelocidadeMMs = 0.50;                    // Define velocidade do Slider em milimetros por segundo.
float sliderAceleracao = 300;                       // Define aceleracao do Slider em passos por segundo ao quadrado.
int sliderCiclos = 1;                               // Define quantidade de ciclos no modo Loop.
unsigned long sliderPausaPontasMs = 1000;           // Define pausa nas pontas do Loop.
unsigned long sliderAtrasoMs = 10000;                 // Define atraso antes de iniciar o movimento do Slider.

// ============================================================
// EEPROM
// ============================================================

struct ConfigEEPROM {                       // Cria estrutura de configuracoes salvas.
  unsigned long assinatura;                 // Guarda assinatura de validade.
  float passosPorMM;                        // Guarda passos por milimetro.
  long cursoTotalAtual;                     // Guarda curso logico.
  long passoManualLentoUm;                  // Guarda deslocamento lento manual em micrometros.
  long passoManualMedioUm;                  // Guarda deslocamento medio manual em micrometros.
  long passoManualRapidoUm;                 // Guarda deslocamento rapido manual em micrometros.
  float velMoverLentaMMs;                   // Guarda velocidade lenta manual em mm/s.
  float velMoverMediaMMs;                   // Guarda velocidade media manual em mm/s.
  float velMoverRapidaMMs;                  // Guarda velocidade rapida manual em mm/s.
  int stackFotos;                           // Guarda fotos do stacking.
  long stackPassosPorFoto;                  // Guarda passos por foto.
  unsigned long stackAtrasoInicialMs;       // Guarda atraso inicial do stacking.
  unsigned long stackTempoDisparoMs;        // Guarda tempo de disparo do stacking.
  unsigned long stackTempoPosFotoMs;        // Guarda pos-foto do stacking.
  unsigned long stackTempoEstabilizacaoMs;  // Guarda estabilizacao do stacking.
  bool stackSentidoAB;                      // Guarda direcao do stacking.
  byte stackRetorno;                        // Guarda retorno do stacking.
  int bulbDisparos;                         // Guarda disparos Bulb.
  unsigned long bulbTempoMs;                // Guarda tempo Bulb.
  unsigned long bulbTempoPosFotoMs;         // Guarda pos-foto Bulb.
  unsigned long bulbAtrasoInicialMs;        // Guarda atraso inicial Bulb.
  unsigned long bulbIntervaloMs;            // Guarda intervalo Bulb.
  bool sliderSentidoAB;                    // Guarda direcao do Slider.
  float sliderVelocidadeMMs;               // Guarda velocidade do Slider em mm/s.
  float sliderAceleracao;                  // Guarda aceleracao do Slider.
  int sliderCiclos;                        // Guarda ciclos do Slider Loop.
  unsigned long sliderPausaPontasMs;       // Guarda pausa nas pontas do Slider Loop.
  unsigned long sliderAtrasoMs;            // Guarda atraso antes de iniciar o movimento do Slider.
};

const int EEPROM_ADDR = 0;                          // Define endereco inicial da EEPROM.
const unsigned long EEPROM_ASSINATURA = 0x41535637; // Define assinatura desta versao.

// ============================================================
// TELAS E MENUS
// ============================================================

enum Tela {                         // Enumera telas principais.
  TELA_PRINCIPAL,                   // Tela do menu principal.
  TELA_STACKING,                    // Tela do menu Stacking.
  TELA_BULB,                        // Tela do menu Bulb.
  TELA_SLIDER,                      // Tela do menu Slider.
  TELA_CONFIG,                      // Tela do menu Config.
  TELA_EXECUTANDO                   // Tela de rotina em execucao.
};

Tela telaAtual = TELA_PRINCIPAL;    // Guarda tela atual.
byte itemMenu = 0;                  // Guarda item selecionado do menu atual.
byte submenuStack = 0;              // Guarda submenu do Stacking.
byte submenuSlider = 0;             // Guarda submenu do Slider.
byte itemSubmenu = 0;               // Guarda item dentro do submenu atual.
bool dentroSubmenu = false;         // Indica se esta dentro de um submenu.
bool modoEdicao = false;            // Indica se esta editando valor.
bool modoMoverAtivo = false;        // Indica se o modo mover esta ativo.

// ============================================================
// ENCODER KY-040
// ============================================================

int encoderDelta = 0;                       // Guarda deslocamento acumulado do encoder.
bool encoderClick = false;                  // Guarda evento de clique curto.
bool encoderLongo = false;                  // Guarda evento de clique longo.
bool ultimoCLK = HIGH;                      // Guarda ultimo estado de CLK.
bool ultimoSW = HIGH;                       // Guarda ultimo estado do botao.
unsigned long swMudouEm = 0;                // Guarda tempo da ultima mudanca do botao.
unsigned long swPressionadoEm = 0;          // Guarda tempo em que o botao foi pressionado.
bool swPressionando = false;                // Indica se o botao esta pressionado.
bool swLongoDisparado = false;              // Evita repetir clique longo.
bool ignorarEncoderAteSoltar = false;          // Ignora o botao do encoder ate soltar apos cancelamento.
const unsigned long botaoDebounceMs = 35;   // Define debounce do botao.
const unsigned long cliqueLongoMs = 800;    // Define tempo de clique longo.

// ============================================================
// BOTOES A/B
// ============================================================

struct BotaoSimples {               // Cria estrutura para debounce e clique curto/longo.
  byte pino;                        // Guarda pino do botao.
  bool estadoEstavel;               // Guarda estado estavel.
  bool ultimoLido;                  // Guarda ultima leitura bruta.
  unsigned long mudouEm;            // Guarda tempo da ultima mudanca bruta.
  unsigned long pressionadoEm;      // Guarda quando o pressionamento estavel comecou.
  bool eventoClique;                // Gera clique curto somente ao soltar.
  bool eventoPressionou;            // Gera evento quando o pressionamento fica estavel.
  bool eventoSoltou;                // Gera evento quando a soltura fica estavel.
  bool longoDisparado;              // Indica que o pressionamento virou movimento continuo.
};

BotaoSimples botaoA = {BTN_A, HIGH, HIGH, 0, 0, false, false, false, false}; // Cria botao A.
BotaoSimples botaoB = {BTN_B, HIGH, HIGH, 0, 0, false, false, false, false}; // Cria botao B.

const unsigned long botaoABLongoMs = 500; // Tempo segurando A/B para iniciar movimento continuo.
byte movimentoContinuoAB = 0;             // 0=parado, 1=sentido A, 2=sentido B.

// ============================================================
// FLAGS
// ============================================================

bool cancelado = false;             // Guarda estado de cancelamento.
bool lcdSujo = true;                // Indica que o LCD precisa atualizar.
unsigned long ultimaAtualizacaoBateria = 0; // Guarda quando a bateria foi atualizada no LCD.

// ============================================================
// SETUP
// ============================================================

void setup() {                                      // Executa uma vez ao ligar.
  lcd.init();                                      // Inicializa LCD.
  lcd.backlight();                                 // Liga luz de fundo.
  pinMode(STEP_PIN, OUTPUT);                       // Configura STEP como saida.
  pinMode(DIR_PIN, OUTPUT);                        // Configura DIR como saida.
  pinMode(ENABLE_PIN, OUTPUT);                     // Configura ENABLE como saida.
  digitalWrite(ENABLE_PIN, LOW);                   // Habilita driver.
  pinMode(SHUTTER_PIN, OUTPUT);                    // Configura disparo como saida.
  digitalWrite(SHUTTER_PIN, LOW);                  // Mantem disparo desligado.
  pinMode(ENDSTOP_HOME, INPUT_PULLUP);             // Configura fim inicial como entrada pullup.
  pinMode(ENDSTOP_FINAL, INPUT_PULLUP);            // Configura fim final como entrada pullup.
  pinMode(ENC_CLK, INPUT_PULLUP);                  // Configura CLK do encoder.
  pinMode(ENC_DT, INPUT_PULLUP);                   // Configura DT do encoder.
  pinMode(ENC_SW, INPUT_PULLUP);                   // Configura botao do encoder.
  pinMode(BTN_A, INPUT_PULLUP);                    // Configura botao A.
  pinMode(BTN_B, INPUT_PULLUP);                    // Configura botao B.
  pinMode(BATTERY_PIN, INPUT);                     // Configura leitura da bateria.
  carregarConfigEEPROM();                          // Carrega configuracoes salvas.
  pontoADefinido = false;                          // Limpa ponto A ao ligar.
  pontoBDefinido = false;                          // Limpa ponto B ao ligar.
  posicaoAtual = 0;                                // Define posicao inicial relativa.
  stepper.setMaxSpeed(velocidadeRapida);           // Define velocidade maxima.
  stepper.setAcceleration(aceleracaoMotor);        // Define aceleracao.
  stepper.setEnablePin(ENABLE_PIN);                // Informa ENABLE para AccelStepper.
  stepper.setPinsInverted(false, false, true);     // Inverte ENABLE ativo em LOW.
  stepper.enableOutputs();                         // Habilita saidas do motor.
  stepper.setCurrentPosition(0);                   // Zera posicao interna.
  ultimoCLK = digitalRead(ENC_CLK);                // Inicializa estado do encoder.
  lcd.clear();                                     // Limpa LCD.
  lcd.setCursor(0, 0);                             // Posiciona linha 0.
  lcd.print("ARANDU STACK V1");                    // Mostra nome do sistema.
  lcd.setCursor(0, 1);                             // Posiciona linha 1.
  lcd.print("A CIENCIA CRESCE");                   // Mostra frase.
  lcd.setCursor(0, 2);                             // Posiciona linha 2.
  lcd.print("QUANDO O SABER");                     // Mostra frase.
  lcd.setCursor(0, 3);                             // Posiciona linha 3.
  lcd.print("CIRCULA");                            // Mostra frase.
  delay(3000);                                     // Mantem frase.
  lcd.clear();                                     // Limpa LCD.
  lcd.setCursor(0, 2);                             // Posiciona linha 2.
  lcd.print("INICIANDO...");                       // Mostra inicializacao.
  delay(1500);                                     // Mantem inicializacao.
  lcd.clear();                                     // Limpa LCD.
  lcdSujo = true;                                  // Forca desenho inicial.
}

// ============================================================
// LOOP
// ============================================================

void loop() {                                      // Loop principal.
  atualizarEntradas();                             // Atualiza encoder e botoes.
  switch (telaAtual) {                             // Seleciona tela atual.
    case TELA_PRINCIPAL: telaPrincipal(); break;   // Executa menu principal.
    case TELA_STACKING:  telaStacking(); break;    // Executa Stacking.
    case TELA_BULB:      telaBulb(); break;        // Executa Bulb.
    case TELA_SLIDER:   telaSlider(); break;      // Executa Slider.
    case TELA_CONFIG:    telaConfig(); break;      // Executa Config.
    case TELA_EXECUTANDO: break;                   // Nao desenha durante execucao.
  }
  tratarBotoesAB();                                // Trata botoes A/B depois da tela.
  atualizarBateriaPeriodica();                     // Atualiza apenas o indicador de bateria.
}

// ============================================================
// EEPROM
// ============================================================

ConfigEEPROM criarConfigFabrica() {                // Cria configuracao padrao.
  ConfigEEPROM cfg;                                // Cria estrutura temporaria.
  cfg.assinatura = EEPROM_ASSINATURA;              // Define assinatura.
  cfg.passosPorMM = 800.0;                         // Define passos/mm padrao.
  cfg.cursoTotalAtual = 50000;                     // Define curso padrao.
  cfg.passoManualLentoUm = 10;                     // Define mover lento padrao em micrometros por click.
  cfg.passoManualMedioUm = 250;                    // Define mover medio padrao em micrometros por click.
  cfg.passoManualRapidoUm = 4000;                  // Define mover rapido padrao em micrometros por click.
  cfg.velMoverLentaMMs = 0.25;                     // Define velocidade lenta padrao em mm/s.
  cfg.velMoverMediaMMs = 2.00;                     // Define velocidade media padrao em mm/s.
  cfg.velMoverRapidaMMs = 20.00;                   // Define velocidade rapida padrao em mm/s.
  cfg.stackFotos = 20;                             // Define fotos padrao.
  cfg.stackPassosPorFoto = 80;                    // Define passos/foto padrao.
  cfg.stackAtrasoInicialMs = 2000;                 // Define atraso inicial padrao.
  cfg.stackTempoDisparoMs = 500;                   // Define disparo padrao.
  cfg.stackTempoPosFotoMs = 3000;                   // Define pos-foto padrao.
  cfg.stackTempoEstabilizacaoMs = 500;             // Define estabilizacao padrao.
  cfg.stackSentidoAB = true;                       // Define direcao padrao.
  cfg.stackRetorno = 0;                            // Define retorno padrao.
  cfg.bulbDisparos = 1;                            // Define fotos Bulb padrao.
  cfg.bulbTempoMs = 5000;                          // Define tempo Bulb padrao.
  cfg.bulbTempoPosFotoMs = 500;                    // Define pos-foto Bulb padrao.
  cfg.bulbAtrasoInicialMs = 2000;                  // Define atraso Bulb padrao.
  cfg.bulbIntervaloMs = 2000;                      // Define intervalo Bulb padrao.
  cfg.sliderSentidoAB = true;                      // Define direcao Slider padrao.
  cfg.sliderVelocidadeMMs = 0.50;                  // Define velocidade Slider padrao em mm/s.
  cfg.sliderAceleracao = 300;                      // Define aceleracao Slider padrao.
  cfg.sliderCiclos = 1;                            // Define ciclos Slider padrao.
  cfg.sliderPausaPontasMs = 1000;                  // Define pausa Slider padrao.
  cfg.sliderAtrasoMs = 10000;                       // Define atraso Slider padrao em 10 segundos.
  return cfg;                                      // Retorna configuracao.
}

void aplicarConfig(ConfigEEPROM cfg) {             // Aplica configuracao.
  passosPorMM = cfg.passosPorMM;                   // Aplica passos/mm.
  cursoTotalAtual = cfg.cursoTotalAtual;           // Aplica curso.
  passoManualLentoUm = cfg.passoManualLentoUm;     // Aplica deslocamento lento manual.
  passoManualMedioUm = cfg.passoManualMedioUm;     // Aplica deslocamento medio manual.
  passoManualRapidoUm = cfg.passoManualRapidoUm;   // Aplica deslocamento rapido manual.
  velMoverLentaMMs = cfg.velMoverLentaMMs;         // Aplica velocidade lenta manual.
  velMoverMediaMMs = cfg.velMoverMediaMMs;         // Aplica velocidade media manual.
  velMoverRapidaMMs = cfg.velMoverRapidaMMs;       // Aplica velocidade rapida manual.
  stackFotos = cfg.stackFotos;                     // Aplica fotos.
  stackPassosPorFoto = cfg.stackPassosPorFoto;     // Aplica passos/foto.
  stackAtrasoInicialMs = cfg.stackAtrasoInicialMs; // Aplica atraso inicial.
  stackTempoDisparoMs = cfg.stackTempoDisparoMs;   // Aplica disparo.
  stackTempoPosFotoMs = cfg.stackTempoPosFotoMs;   // Aplica pos-foto.
  stackTempoEstabilizacaoMs = cfg.stackTempoEstabilizacaoMs; // Aplica estabilizacao.
  stackSentidoAB = cfg.stackSentidoAB;             // Aplica direcao.
  stackRetorno = cfg.stackRetorno;                 // Aplica retorno.
  bulbDisparos = cfg.bulbDisparos;                 // Aplica fotos Bulb.
  bulbTempoMs = cfg.bulbTempoMs;                   // Aplica tempo Bulb.
  bulbTempoPosFotoMs = cfg.bulbTempoPosFotoMs;     // Aplica pos-foto Bulb.
  bulbAtrasoInicialMs = cfg.bulbAtrasoInicialMs;   // Aplica atraso Bulb.
  bulbIntervaloMs = cfg.bulbIntervaloMs;           // Aplica intervalo Bulb.
  sliderSentidoAB = cfg.sliderSentidoAB;           // Aplica direcao Slider.
  sliderVelocidadeMMs = cfg.sliderVelocidadeMMs;   // Aplica velocidade Slider em mm/s.
  sliderAceleracao = cfg.sliderAceleracao;         // Aplica aceleracao Slider.
  sliderCiclos = cfg.sliderCiclos;                 // Aplica ciclos Slider.
  sliderPausaPontasMs = cfg.sliderPausaPontasMs;   // Aplica pausa Slider.
  sliderAtrasoMs = cfg.sliderAtrasoMs;             // Aplica atraso Slider.
}

void carregarConfigEEPROM() {                      // Carrega EEPROM.
  ConfigEEPROM cfg;                                // Cria estrutura temporaria.
  EEPROM.get(EEPROM_ADDR, cfg);                    // Le EEPROM.
  if (cfg.assinatura != EEPROM_ASSINATURA) {       // Verifica assinatura.
    cfg = criarConfigFabrica();                    // Cria padrao se invalida.
    EEPROM.put(EEPROM_ADDR, cfg);                  // Salva padrao.
  }
  aplicarConfig(cfg);                              // Aplica configuracao.
}

void salvarConfigEEPROM() {                        // Salva configuracao atual.
  ConfigEEPROM cfg;                                // Cria estrutura temporaria.
  cfg.assinatura = EEPROM_ASSINATURA;              // Salva assinatura.
  cfg.passosPorMM = passosPorMM;                   // Salva passos/mm.
  cfg.cursoTotalAtual = cursoTotalAtual;           // Salva curso.
  cfg.passoManualLentoUm = passoManualLentoUm;     // Salva deslocamento lento manual.
  cfg.passoManualMedioUm = passoManualMedioUm;     // Salva deslocamento medio manual.
  cfg.passoManualRapidoUm = passoManualRapidoUm;   // Salva deslocamento rapido manual.
  cfg.velMoverLentaMMs = velMoverLentaMMs;         // Salva velocidade lenta manual.
  cfg.velMoverMediaMMs = velMoverMediaMMs;         // Salva velocidade media manual.
  cfg.velMoverRapidaMMs = velMoverRapidaMMs;       // Salva velocidade rapida manual.
  cfg.stackFotos = stackFotos;                     // Salva fotos.
  cfg.stackPassosPorFoto = stackPassosPorFoto;     // Salva passos/foto.
  cfg.stackAtrasoInicialMs = stackAtrasoInicialMs; // Salva atraso inicial.
  cfg.stackTempoDisparoMs = stackTempoDisparoMs;   // Salva disparo.
  cfg.stackTempoPosFotoMs = stackTempoPosFotoMs;   // Salva pos-foto.
  cfg.stackTempoEstabilizacaoMs = stackTempoEstabilizacaoMs; // Salva estabilizacao.
  cfg.stackSentidoAB = stackSentidoAB;             // Salva direcao.
  cfg.stackRetorno = stackRetorno;                 // Salva retorno.
  cfg.bulbDisparos = bulbDisparos;                 // Salva fotos Bulb.
  cfg.bulbTempoMs = bulbTempoMs;                   // Salva tempo Bulb.
  cfg.bulbTempoPosFotoMs = bulbTempoPosFotoMs;     // Salva pos-foto Bulb.
  cfg.bulbAtrasoInicialMs = bulbAtrasoInicialMs;   // Salva atraso Bulb.
  cfg.bulbIntervaloMs = bulbIntervaloMs;           // Salva intervalo Bulb.
  cfg.sliderSentidoAB = sliderSentidoAB;           // Salva direcao Slider.
  cfg.sliderVelocidadeMMs = sliderVelocidadeMMs;   // Salva velocidade Slider em mm/s.
  cfg.sliderAceleracao = sliderAceleracao;         // Salva aceleracao Slider.
  cfg.sliderCiclos = sliderCiclos;                 // Salva ciclos Slider.
  cfg.sliderPausaPontasMs = sliderPausaPontasMs;   // Salva pausa Slider.
  cfg.sliderAtrasoMs = sliderAtrasoMs;             // Salva atraso Slider.
  EEPROM.put(EEPROM_ADDR, cfg);                    // Grava EEPROM.
}

void restaurarFabricaEEPROM() {                    // Restaura fabrica.
  ConfigEEPROM cfg = criarConfigFabrica();         // Cria padrao.
  EEPROM.put(EEPROM_ADDR, cfg);                    // Salva padrao.
  aplicarConfig(cfg);                              // Aplica padrao.
}

// ============================================================
// ENTRADAS
// ============================================================

void atualizarEntradas() {                         // Atualiza entradas.
  atualizarEncoder();                              // Atualiza encoder.
  atualizarBotaoSimples(botaoA);                   // Atualiza botao A.
  atualizarBotaoSimples(botaoB);                   // Atualiza botao B.
}

void atualizarEncoder() {                          // Atualiza encoder.
  bool clkAtual = digitalRead(ENC_CLK);            // Le CLK.
  if (clkAtual != ultimoCLK) {                     // Detecta mudanca.
    if (clkAtual == LOW) {                         // Usa borda de descida.
      if (digitalRead(ENC_DT) != clkAtual) encoderDelta++; // Soma giro para direita.
      else encoderDelta--;                         // Soma giro para esquerda.
    }
    ultimoCLK = clkAtual;                          // Atualiza ultimo CLK.
  }

  bool swAtual = digitalRead(ENC_SW);              // Le botao do encoder.
  unsigned long agora = millis();                  // Guarda tempo atual.
  encoderClick = false;                            // Limpa clique curto.
  encoderLongo = false;                            // Limpa clique longo.

  if (ignorarEncoderAteSoltar) {                   // Depois de cancelar, ignora o botao ainda pressionado.
    if (swAtual == HIGH) {                         // So libera quando o usuario soltar o encoder.
      ignorarEncoderAteSoltar = false;             // Libera leitura normal.
      ultimoSW = HIGH;                             // Sincroniza estado solto.
      swPressionando = false;                      // Garante botao solto internamente.
      swLongoDisparado = false;                    // Libera novo clique longo futuro.
      swMudouEm = agora;                           // Reinicia debounce.
    }
    return;                                        // Ignora click/long enquanto ainda estiver pressionado.
  }

  if (swAtual != ultimoSW) {                       // Detecta mudanca bruta.
    ultimoSW = swAtual;                            // Atualiza ultimo estado.
    swMudouEm = agora;                             // Marca tempo.
  }

  if ((agora - swMudouEm) > botaoDebounceMs) {     // Verifica estabilidade.
    if (swAtual == LOW && !swPressionando) {       // Detecta inicio do clique.
      swPressionando = true;                       // Marca pressionando.
      swPressionadoEm = agora;                     // Marca tempo inicial.
      swLongoDisparado = false;                    // Libera clique longo.
    }

    if (swAtual == LOW && swPressionando && !swLongoDisparado) { // Verifica segurando.
      if ((agora - swPressionadoEm) > cliqueLongoMs) { // Verifica tempo longo.
        encoderLongo = true;                       // Gera clique longo.
        swLongoDisparado = true;                   // Bloqueia repeticao.
      }
    }

    if (swAtual == HIGH && swPressionando) {       // Detecta soltura.
      if (!swLongoDisparado) encoderClick = true;  // Gera clique curto.
      swPressionando = false;                      // Limpa pressionando.
    }
  }
}

void atualizarBotaoSimples(BotaoSimples &b) {      // Atualiza botao A/B com debounce e eventos de borda.
  unsigned long agora = millis();                  // Guarda tempo atual.
  b.eventoClique = false;                          // Limpa clique curto da passagem anterior.
  b.eventoPressionou = false;                      // Limpa evento de pressionamento.
  b.eventoSoltou = false;                          // Limpa evento de soltura.
  bool leitura = digitalRead(b.pino);              // Le pino.

  if (leitura != b.ultimoLido) {                   // Detecta mudanca bruta.
    b.ultimoLido = leitura;                        // Atualiza ultima leitura bruta.
    b.mudouEm = agora;                             // Reinicia tempo de debounce.
  }

  if ((agora - b.mudouEm) > botaoDebounceMs) {     // Aceita somente estado estavel.
    if (leitura != b.estadoEstavel) {              // Detecta uma nova borda estavel.
      b.estadoEstavel = leitura;                   // Atualiza o estado confirmado.

      if (leitura == LOW) {                        // Botao acabou de ser pressionado.
        b.pressionadoEm = agora;                   // Marca inicio do pressionamento.
        b.longoDisparado = false;                  // Libera novo pressionamento longo.
        b.eventoPressionou = true;                 // Informa a borda de pressionamento.
      } else {                                     // Botao acabou de ser solto.
        b.eventoSoltou = true;                     // Informa a borda de soltura.
        if (!b.longoDisparado) b.eventoClique = true; // So gera clique se nao houve movimento continuo.
      }
    }
  }
}

int consumirEncoderDelta() {                       // Consome giro do encoder.
  int delta = encoderDelta;                        // Copia valor.
  encoderDelta = 0;                                // Zera acumulado.
  return delta;                                    // Retorna giro.
}

void tratarBotoesAB() {                            // Trata clique curto e movimento continuo dos botoes A/B.
  unsigned long agora = millis();                  // Usa uma unica referencia de tempo nesta passagem.

  if (!modoMoverAtivo) {                           // Movimento continuo so pode existir dentro do MOVER ativo.
    if (movimentoContinuoAB != 0) pararMovimentoContinuoAB(); // Garante parada ao sair do MOVER.

    if (botaoA.eventoClique) {                     // Fora do MOVER, clique curto em A mantem funcao antiga.
      if (pontoADefinido) moverParaBloqueante(pontoA, velocidadeRapida); // Vai para A se definido.
      lcdSujo = true;                              // Atualiza LCD.
    }
    if (botaoB.eventoClique) {                     // Fora do MOVER, clique curto em B mantem funcao antiga.
      if (pontoBDefinido) moverParaBloqueante(pontoB, velocidadeRapida); // Vai para B se definido.
      lcdSujo = true;                              // Atualiza LCD.
    }
    return;                                        // Nao executa logica continua fora do MOVER.
  }

  bool aPressionado = (botaoA.estadoEstavel == LOW); // Le estado estavel de A.
  bool bPressionado = (botaoB.estadoEstavel == LOW); // Le estado estavel de B.

  // A parada usa a leitura bruta, sem esperar o debounce de soltura.
  // Ruido nessa leitura pode apenas antecipar uma parada; nunca inicia movimento sozinho.
  if ((movimentoContinuoAB == 1 && digitalRead(BTN_A) == HIGH) ||
      (movimentoContinuoAB == 2 && digitalRead(BTN_B) == HIGH)) {
    pararMovimentoContinuoAB();                    // Para no primeiro loop que detectar a soltura fisica.
  }

  if (aPressionado && bPressionado && movimentoContinuoAB == 0) { // Dois botoes juntos nunca movimentam o trilho.
    if ((agora - botaoA.pressionadoEm >= botaoABLongoMs) ||
        (agora - botaoB.pressionadoEm >= botaoABLongoMs)) {
      botaoA.longoDisparado = true;                // Consome A para nao salvar por engano ao soltar.
      botaoB.longoDisparado = true;                // Consome B para nao salvar por engano ao soltar.
    }
  } else {                                         // Somente um botao pode iniciar deslocamento.
    if (aPressionado && !botaoA.longoDisparado && movimentoContinuoAB == 0 &&
        (agora - botaoA.pressionadoEm >= botaoABLongoMs)) {
      botaoA.longoDisparado = true;                // Marca A como pressionamento longo.
      iniciarMovimentoContinuoAB(1);               // Inicia no sentido A.
    }

    if (bPressionado && !botaoB.longoDisparado && movimentoContinuoAB == 0 &&
        (agora - botaoB.pressionadoEm >= botaoABLongoMs)) {
      botaoB.longoDisparado = true;                // Marca B como pressionamento longo.
      iniciarMovimentoContinuoAB(2);               // Inicia no sentido B.
    }
  }

  if ((movimentoContinuoAB == 1 && botaoA.eventoSoltou) ||
      (movimentoContinuoAB == 2 && botaoB.eventoSoltou)) {
    pararMovimentoContinuoAB();                    // Soltou o botao ativo: para imediatamente.
  }

  if (movimentoContinuoAB != 0) {                  // Se ha deslocamento continuo ativo.
    if (limiteFisicoBloqueiaMovimento()) {         // Fim de curso correspondente tem prioridade.
      pararMovimentoContinuoAB();                  // Para imediatamente no limite fisico.
    } else {
      stepper.run();                               // Executa aceleracao e passos sem bloquear o loop.
      posicaoAtual = stepper.currentPosition();    // Mantem posicao logica sincronizada.
    }
  }

  if (botaoA.eventoClique) {                       // Clique curto confirmado somente na soltura.
    salvarPontoA();                                // Salva A na posicao atual.
    lcdSujo = true;                                // Atualiza LCD.
  }
  if (botaoB.eventoClique) {                       // Clique curto confirmado somente na soltura.
    salvarPontoB();                                // Salva B na posicao atual.
    lcdSujo = true;                                // Atualiza LCD.
  }
}

void iniciarMovimentoContinuoAB(byte sentido) {    // Prepara movimento continuo com parametros atuais do MOVER.
  cancelado = false;                               // Remove eventual cancelamento antigo.
  movimentoContinuoAB = sentido;                   // Guarda qual botao controla o movimento.
  stepper.enableOutputs();                         // Garante driver habilitado.
  stepper.setMaxSpeed(velocidadeManualAtual());    // Usa a velocidade selecionada no MOVER.
  stepper.setAcceleration(aceleracaoMotor);        // Reutiliza a aceleracao geral existente.

  if (sentido == 1) stepper.moveTo(-cursoTotalAtual); // A corresponde ao sentido negativo.
  else stepper.moveTo(cursoTotalAtual);            // B corresponde ao sentido positivo.
}

void pararMovimentoContinuoAB() {                  // Interrompe o continuo sem rampa de desaceleracao.
  long pos = stepper.currentPosition();            // Captura a ultima posicao realmente executada.
  stepper.moveTo(pos);                             // Remove imediatamente o destino distante.
  stepper.setSpeed(0);                             // Elimina velocidade residual interna.
  stepper.setCurrentPosition(pos);                 // Sincroniza posicao e destino do AccelStepper.
  posicaoAtual = pos;                              // Sincroniza a posicao logica do sistema.
  movimentoContinuoAB = 0;                        // Marca continuo como encerrado.
  lcdSujo = true;                                  // Atualiza a posicao mostrada no LCD.
}

void salvarPontoA() {                              // Salva ponto A.
  pontoA = posicaoAtual;                           // Copia posicao atual.
  pontoADefinido = true;                           // Marca A definido.
}

void salvarPontoB() {                              // Salva ponto B.
  pontoB = posicaoAtual;                           // Copia posicao atual.
  pontoBDefinido = true;                           // Marca B definido.
}

// ============================================================
// MENU PRINCIPAL
// ============================================================

void telaPrincipal() {                             // Controla menu principal.
  const byte totalItens = 4;                       // Define quantidade de itens.
  int giro = consumirEncoderDelta();               // Le giro.

  if (giro > 0) {                                  // Se girou para direita.
    itemMenu = (itemMenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (giro < 0) {                                  // Se girou para esquerda.
    itemMenu = (itemMenu + 1) % totalItens;        // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou.
    if (itemMenu == 0) telaAtual = TELA_STACKING;  // Entra em Stacking.
    if (itemMenu == 1) telaAtual = TELA_BULB;      // Entra em Bulb.
    if (itemMenu == 2) telaAtual = TELA_SLIDER;    // Entra em Slider.
    if (itemMenu == 3) telaAtual = TELA_CONFIG;    // Entra em Config.
    itemMenu = 0;                                  // Reinicia item.
    itemSubmenu = 0;                               // Reinicia item interno.
    submenuStack = 0;                              // Reinicia submenu.
    submenuSlider = 0;                             // Reinicia submenu Slider.
    dentroSubmenu = false;                         // Sai de submenu.
    modoEdicao = false;                            // Sai de edicao.
    modoMoverAtivo = false;                        // Sai do mover.
    lcd.clear();                                   // Limpa LCD.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa redesenhar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirItem(0, itemMenu == 0, "STACK");       // Mostra Stack.
    imprimirItem(1, itemMenu == 1, "BULB");        // Mostra Bulb.
    imprimirItem(2, itemMenu == 2, "SLIDER");      // Mostra Slider.
    imprimirItem(3, itemMenu == 3, "CONFIG");      // Mostra Config.
    imprimirCabecalhoBateria();                    // Mostra bateria no canto direito.
  }
}

// ============================================================
// MENU STACKING
// ============================================================

void telaStacking() {                              // Controla menu Stacking.
  if (!dentroSubmenu) telaStackingPrincipal();      // Mostra lista de submenus.
  else if (submenuStack == 0) telaStackMover();     // Mostra Mover.
  else if (submenuStack == 1) telaStackSequencia(); // Mostra Sequencia.
  else if (submenuStack == 2) telaStackMovimento(); // Mostra Movimento.
  else if (submenuStack == 3) telaStackTempos();    // Mostra Tempos.
  else if (submenuStack == 4) telaStackFotografar();// Mostra Fotografar.
}

void telaStackingPrincipal() {                     // Controla submenus do Stacking.
  const byte totalItens = 5;                       // Define 5 submenus.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarMenuPrincipal();                         // Volta ao menu principal.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (giro > 0) {                                  // Se girou para direita.
    submenuStack = (submenuStack + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (giro < 0) {                                  // Se girou para esquerda.
    submenuStack = (submenuStack + 1) % totalItens; // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou.
    dentroSubmenu = true;                          // Entra no submenu.
    itemSubmenu = 0;                               // Reinicia subitem.
    modoEdicao = false;                            // Sai de edicao.
    modoMoverAtivo = false;                        // Sai do mover.
    lcd.clear();                                   // Limpa LCD.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK");                       // Imprime titulo.
    if (submenuStack <= 2) {                       // Se esta nos primeiros itens.
      imprimirItem(1, submenuStack == 0, "MOVER"); // Mostra MOVER.
      imprimirItem(2, submenuStack == 1, "SEQUENCIA"); // Mostra SEQUENCIA.
      imprimirItem(3, submenuStack == 2, "MOVIMENTO"); // Mostra MOVIMENTO.
    } else {                                       // Se esta nos ultimos itens.
      imprimirItem(1, submenuStack == 3, "TEMPOS"); // Mostra TEMPOS.
      imprimirItem(2, submenuStack == 4, "FOTOGRAFAR"); // Mostra FOTOGRAFAR.
    }
  }
}

void telaStackMover() {                            // Controla submenu MOVER.
  const byte totalItens = 2;                       // Define Velocidade e Mover.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuStack();                          // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && !modoMoverAtivo && giro > 0) { // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && !modoMoverAtivo && giro < 0) { // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && itemSubmenu == 0 && giro != 0) { // Se editando velocidade.
    modoMover = constrain((int)modoMover + giro, 0, 2); // Ajusta velocidade.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoMoverAtivo && giro != 0) {               // Se modo mover ativo.
    cancelado = false;                             // Garante que cancelamento anterior nao bloqueie o MOVER.
    moverRelativoBloqueante(giro * passoManualAtual(), velocidadeManualAtual()); // Move trilho com deslocamento e velocidade do modo atual.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 0) {          // Se clicou em velocidade.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 1) {          // Se clicou em mover.
    modoMoverAtivo = !modoMoverAtivo;              // Entra/sai do modo mover.
    modoEdicao = false;                            // Garante edicao desligada.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK-MOVER");                 // Imprime titulo.
    imprimirCampoTexto(1, itemSubmenu == 0, modoEdicao, "Vel:", nomeVelocidade()); // Mostra velocidade.
    imprimirCampoMicrometro(2, itemSubmenu == 1, modoMoverAtivo, "Mover:", posicaoAtual); // Mostra posicao em micrometros.
    lcd.setCursor(0, 3);                           // Vai para linha 3.
    lcd.print("A:");                               // Imprime rotulo A.
    lcd.print(passosParaMicrometros(pontoA));      // Imprime ponto A em micrometros.
    lcd.print("um B:");                            // Imprime unidade e rotulo B.
    lcd.print(passosParaMicrometros(pontoB));      // Imprime ponto B em micrometros.
    lcd.print("um");                               // Imprime unidade.
  }
}

void telaStackSequencia() {                        // Controla submenu SEQUENCIA.
  const byte totalItens = 3;                       // Define Fotos, Distancia e Passo.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuStack();                          // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 2) {          // Se clicou em passo editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 2) { // Se editando passo em micrometros.
    long passoAtualUm = passosParaMicrometros(stackPassosPorFoto); // Converte passo atual para micrometros.
    passoAtualUm += (long)giro * 10L;               // Ajusta micrometros em incrementos de 10.
    if (passoAtualUm < 10L) passoAtualUm = 10L;    // Garante valor minimo de 10 micrometros.
    stackPassosPorFoto = micrometrosParaPassos(passoAtualUm); // Converte imediatamente para passos do motor.
    long dist = distanciaStackingAB();              // Calcula a distancia total fixa entre A e B em passos.
    if (dist > 0 && stackPassosPorFoto > 0) {       // Verifica se distancia e passo sao validos.
      stackFotos = (dist / stackPassosPorFoto) + 1; // Calcula fotos somente a partir do passo convertido.
    }
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK-SEQUENCIA");             // Imprime titulo.
    imprimirCampoInt(1, false, false, "Fotos:", stackFotos); // Mostra fotos somente para leitura.
    imprimirCampoDistanciaMM(2, false, false, "Dist:", distanciaStackingAB()); // Mostra distancia somente para leitura.
    imprimirCampoUmValor(3, itemSubmenu == 2, modoEdicao, "Passo:", passosParaMicrometros(stackPassosPorFoto)); // Mostra passo e permite editar somente este campo.
  }
}

void telaStackMovimento() {                        // Controla submenu MOVIMENTO.
  const byte totalItens = 2;                       // Define Direcao e Retorno.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuStack();                          // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 0) { // Se editando direcao.
    stackSentidoAB = !stackSentidoAB;              // Alterna direcao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 1) { // Se editando retorno.
    stackRetorno = (stackRetorno + 3 + giro) % 3;  // Alterna retorno.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK-MOV");                   // Imprime titulo.
    imprimirCampoTexto(1, itemSubmenu == 0, modoEdicao, "Dir:", stackSentidoAB ? "A>B" : "B>A"); // Mostra direcao.
    imprimirCampoTexto(2, itemSubmenu == 1, modoEdicao, "Ret:", textoRetorno()); // Mostra retorno.
  }
}

void telaStackTempos() {                           // Controla submenu TEMPOS.
  const byte totalItens = 4;                       // Define quatro tempos.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuStack();                          // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 0) { // Se editando atraso.
    stackAtrasoInicialMs = ajustarTempo(stackAtrasoInicialMs, giro * 500L, 0UL); // Ajusta atraso.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 1) { // Se editando disparo.
    stackTempoDisparoMs = ajustarTempo(stackTempoDisparoMs, giro * 50L, 50UL); // Ajusta disparo.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 2) { // Se editando pos-foto.
    stackTempoPosFotoMs = ajustarTempo(stackTempoPosFotoMs, giro * 100L, 0UL); // Ajusta pos-foto.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 3) { // Se editando estabilizacao.
    stackTempoEstabilizacaoMs = ajustarTempo(stackTempoEstabilizacaoMs, giro * 100L, 0UL); // Ajusta estabilizacao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK-TEMPOS");                // Imprime titulo.
    if (itemSubmenu <= 2) {                        // Se esta na primeira pagina.
      imprimirCampoTempo(1, itemSubmenu == 0, modoEdicao, "Atraso:", stackAtrasoInicialMs); // Mostra atraso.
      imprimirCampoTempo(2, itemSubmenu == 1, modoEdicao, "Disp:", stackTempoDisparoMs); // Mostra disparo.
      imprimirCampoTempo(3, itemSubmenu == 2, modoEdicao, "PosFoto:", stackTempoPosFotoMs); // Mostra pos-foto.
    } else {                                       // Se esta na segunda pagina.
      imprimirCampoTempo(1, false, false, "Disp:", stackTempoDisparoMs); // Mostra disparo.
      imprimirCampoTempo(2, false, false, "PosFoto:", stackTempoPosFotoMs); // Mostra pos-foto.
      imprimirCampoTempo(3, true, modoEdicao, "Estab:", stackTempoEstabilizacaoMs); // Mostra estabilizacao.
    }
  }
}

void telaStackFotografar() {                       // Controla submenu FOTOGRAFAR.
  int giro = consumirEncoderDelta();               // Consome giro sem uso.
  (void)giro;                                      // Evita aviso de variavel nao usada.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuStack();                          // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (encoderClick) {                              // Se clicou.
    executarStacking();                            // Executa Stacking.
    lcdSujo = true;                                // Marca LCD para redesenhar.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("STACK-FOTO");                  // Imprime titulo.
    lcd.setCursor(0, 1);                           // Vai para linha 1.
    lcd.print("Fotos:");                           // Imprime rotulo fotos.
    lcd.print(stackFotos);                         // Imprime fotos.
    lcd.print(" P:");                              // Imprime rotulo passo.
    lcd.print(passosParaMicrometros(stackPassosPorFoto)); // Imprime passo em micrometros.
    lcd.print("um");                               // Imprime unidade.
    lcd.setCursor(0, 2);                           // Vai para linha 2.
    lcd.print("A:");                               // Imprime A.
    lcd.print(passosParaMicrometros(pontoA));      // Imprime ponto A em micrometros.
    lcd.print("um B:");                            // Imprime unidade e B.
    lcd.print(passosParaMicrometros(pontoB));      // Imprime ponto B em micrometros.
    lcd.print("um");                               // Imprime unidade.
    lcd.setCursor(0, 3);                           // Vai para linha 3.
    lcd.print(">INICIAR");                         // Mostra iniciar.
  }
}

// ============================================================
// MENU BULB
// ============================================================

void telaBulb() {                                  // Controla menu Bulb.
  const byte totalItens = 6;                       // Define seis itens.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarMenuPrincipal();                         // Volta ao menu principal.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemMenu = (itemMenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemMenu = (itemMenu + 1) % totalItens;        // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemMenu < 5) {              // Se clicou em item editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemMenu == 5) {             // Se clicou em iniciar.
    executarBulb();                                // Executa Bulb.
    lcdSujo = true;                                // Marca LCD para redesenhar.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (modoEdicao && giro != 0) {                   // Se editando e girou.
    ajustarBulb(giro);                             // Ajusta valor.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("BULB");                        // Imprime titulo.
    if (itemMenu <= 2) {                           // Se esta na primeira pagina.
      imprimirCampoInt(1, itemMenu == 0, modoEdicao, "Fotos:", bulbDisparos); // Mostra fotos.
      imprimirCampoTempo(2, itemMenu == 1, modoEdicao, "Bulb:", bulbTempoMs); // Mostra Bulb.
      imprimirCampoTempo(3, itemMenu == 2, modoEdicao, "PosFoto:", bulbTempoPosFotoMs); // Mostra PosFoto.
    } else {                                       // Se esta na segunda pagina.
      imprimirCampoTempo(1, itemMenu == 3, modoEdicao, "Atraso:", bulbAtrasoInicialMs); // Mostra atraso.
      imprimirCampoTempo(2, itemMenu == 4, modoEdicao, "Intervalo:", bulbIntervaloMs); // Mostra intervalo.
      imprimirItem(3, itemMenu == 5, "Iniciar");   // Mostra iniciar.
    }
  }
}

void ajustarBulb(int direcao) {                    // Ajusta parametros Bulb.
  if (itemMenu == 0) bulbDisparos = constrain(bulbDisparos + direcao, 1, 999); // Ajusta fotos.
  if (itemMenu == 1) bulbTempoMs = ajustarTempo(bulbTempoMs, direcao * 1000L, 1000UL); // Ajusta Bulb.
  if (itemMenu == 2) bulbTempoPosFotoMs = ajustarTempo(bulbTempoPosFotoMs, direcao * 100L, 0UL); // Ajusta PosFoto.
  if (itemMenu == 3) bulbAtrasoInicialMs = ajustarTempo(bulbAtrasoInicialMs, direcao * 500L, 0UL); // Ajusta atraso.
  if (itemMenu == 4) bulbIntervaloMs = ajustarTempo(bulbIntervaloMs, direcao * 1000L, 0UL); // Ajusta intervalo.
}


// ============================================================
// MENU SLIDER
// ============================================================

void telaSlider() {                                // Controla menu Slider.
  if (!dentroSubmenu) telaSliderPrincipal();       // Mostra lista de submenus.
  else if (submenuSlider == 0) telaSliderMover();  // Mostra Mover do Slider.
  else if (submenuSlider == 1) telaSliderVideo();  // Mostra Video.
  else if (submenuSlider == 2) telaSliderLoop();   // Mostra Loop.
  else if (submenuSlider == 3) telaSliderConfig(); // Mostra Config Slider.
}

void telaSliderPrincipal() {                       // Controla submenus do Slider.
  const byte totalItens = 4;                       // Define Mover, Video, Loop e Config.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarMenuPrincipal();                         // Volta ao menu principal.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (giro > 0) {                                  // Se girou para direita.
    submenuSlider = (submenuSlider + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (giro < 0) {                                  // Se girou para esquerda.
    submenuSlider = (submenuSlider + 1) % totalItens; // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou.
    dentroSubmenu = true;                          // Entra no submenu.
    itemSubmenu = 0;                               // Reinicia subitem.
    modoEdicao = false;                            // Sai de edicao.
    modoMoverAtivo = false;                        // Sai do mover.
    lcd.clear();                                   // Limpa LCD.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("SLIDER");                      // Imprime titulo.
    imprimirItem(0, submenuSlider == 0, "MOVER");  // Mostra Mover.
    imprimirItem(1, submenuSlider == 1, "VIDEO");  // Mostra Video.
    imprimirItem(2, submenuSlider == 2, "LOOP");   // Mostra Loop.
    imprimirItem(3, submenuSlider == 3, "CONFIG SLIDER"); // Mostra Config Slider.
  }
}


void telaSliderMover() {                           // Controla submenu MOVER dentro do Slider.
  const byte totalItens = 2;                       // Define Velocidade e Mover.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuSlider();                         // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && !modoMoverAtivo && giro > 0) { // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && !modoMoverAtivo && giro < 0) { // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && itemSubmenu == 0 && giro != 0) { // Se editando velocidade manual.
    modoMover = constrain((int)modoMover + giro, 0, 2); // Ajusta modo de movimento.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoMoverAtivo && giro != 0) {               // Se modo mover ativo.
    cancelado = false;                             // Garante que cancelamento anterior nao bloqueie o MOVER.
    moverRelativoBloqueante(giro * passoManualAtual(), velocidadeManualAtual()); // Move com deslocamento e velocidade do modo atual.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 0) {          // Se clicou em velocidade.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 1) {          // Se clicou em mover.
    modoMoverAtivo = !modoMoverAtivo;              // Entra/sai do modo mover.
    modoEdicao = false;                            // Garante edicao desligada.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("SLIDER-MOVER");                // Imprime titulo.
    imprimirCampoTexto(1, itemSubmenu == 0, modoEdicao, "Vel:", nomeVelocidade()); // Mostra modo de movimento.
    imprimirCampoMicrometro(2, itemSubmenu == 1, modoMoverAtivo, "Mover:", posicaoAtual); // Mostra posicao atual.
    lcd.setCursor(0, 3);                           // Vai para linha 3.
    lcd.print("A:");                               // Imprime rotulo A.
    lcd.print(passosParaMM(pontoA), 1);             // Imprime ponto A em milimetros.
    lcd.print(" B:");                              // Imprime rotulo B.
    lcd.print(passosParaMM(pontoB), 1);             // Imprime ponto B em milimetros.
    lcd.print("mm");                               // Imprime unidade.
  }
}

void telaSliderVideo() {                           // Controla modo Slider Video.
  const byte totalItens = 3;                       // Define iniciar, direcao e velocidade.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuSlider();                         // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 0) {          // Se clicou em iniciar.
    executarSliderVideo();                         // Executa Video.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (encoderClick && itemSubmenu > 0) {           // Se clicou em item editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 1) { // Se editando direcao.
    sliderSentidoAB = !sliderSentidoAB;            // Alterna direcao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 2) { // Se editando velocidade.
    sliderVelocidadeMMs = constrain(sliderVelocidadeMMs + giro * 0.05, 0.05, 10.00); // Ajusta velocidade em mm/s.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("SLIDER-VIDEO");                // Imprime titulo.
    imprimirItem(1, itemSubmenu == 0, "Iniciar");  // Mostra iniciar.
    imprimirDirecaoSliderComDistancia(2, itemSubmenu == 1, modoEdicao); // Mostra direcao e distancia A-B.
    imprimirCampoVelocidadeMMs(3, itemSubmenu == 2, modoEdicao, "Vel:", sliderVelocidadeMMs); // Mostra velocidade em mm/s.
  }
}

void telaSliderLoop() {                            // Controla modo Slider Loop.
  const byte totalItens = 4;                       // Define iniciar, ciclos, velocidade e pausa.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuSlider();                         // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemSubmenu == 0) {          // Se clicou em iniciar.
    executarSliderLoop();                          // Executa Loop.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (encoderClick && itemSubmenu > 0) {           // Se clicou em item editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 1) { // Se editando ciclos.
    sliderCiclos = constrain(sliderCiclos + giro, 1, 999); // Ajusta ciclos.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 2) { // Se editando velocidade.
    sliderVelocidadeMMs = constrain(sliderVelocidadeMMs + giro * 0.05, 0.05, 10.00); // Ajusta velocidade em mm/s.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 3) { // Se editando pausa.
    sliderPausaPontasMs = ajustarTempo(sliderPausaPontasMs, giro * 100L, 0UL); // Ajusta pausa.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("SLIDER-LOOP");                 // Imprime titulo.
    if (itemSubmenu <= 2) {                        // Se primeira pagina.
      imprimirItem(1, itemSubmenu == 0, "Iniciar"); // Mostra iniciar.
      imprimirCampoInt(2, itemSubmenu == 1, modoEdicao, "Ciclos:", sliderCiclos); // Mostra ciclos.
      imprimirCampoVelocidadeMMs(3, itemSubmenu == 2, modoEdicao, "Vel:", sliderVelocidadeMMs); // Mostra velocidade em mm/s.
    } else {                                       // Se segunda pagina.
      imprimirCampoInt(1, false, false, "Ciclos:", sliderCiclos); // Mostra ciclos.
      imprimirCampoVelocidadeMMs(2, false, false, "Vel:", sliderVelocidadeMMs); // Mostra velocidade em mm/s.
      imprimirCampoTempo(3, true, modoEdicao, "Pausa:", sliderPausaPontasMs); // Mostra pausa.
    }
  }
}

void telaSliderConfig() {                          // Controla configuracoes do Slider.
  const byte totalItens = 3;                       // Define velocidade, aceleracao e atraso.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarSubmenuSlider();                         // Volta para lista de submenus.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemSubmenu = (itemSubmenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemSubmenu = (itemSubmenu + 1) % totalItens;  // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick) {                              // Se clicou em item editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 0) { // Se editando velocidade.
    sliderVelocidadeMMs = constrain(sliderVelocidadeMMs + giro * 0.05, 0.05, 10.00); // Ajusta velocidade em mm/s.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 1) { // Se editando aceleracao.
    sliderAceleracao = constrain(sliderAceleracao + giro * 10.0, 10.0, 3000.0); // Ajusta aceleracao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (modoEdicao && giro != 0 && itemSubmenu == 2) { // Se editando atraso.
    long novoAtraso = (long)sliderAtrasoMs + giro * 1000L; // Ajusta em passos de 1 segundo.
    if (novoAtraso < 0) novoAtraso = 0;            // Limita minimo em 0 segundo.
    if (novoAtraso > 300000L) novoAtraso = 300000L; // Limita maximo em 300 segundos.
    sliderAtrasoMs = (unsigned long)novoAtraso;    // Aplica atraso.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("SLIDER-CONFIG");               // Imprime titulo.
    imprimirCampoVelocidadeMMs(1, itemSubmenu == 0, modoEdicao, "Vel:", sliderVelocidadeMMs); // Mostra velocidade em mm/s.
    imprimirCampoFloat(2, itemSubmenu == 1, modoEdicao, "Acel:", sliderAceleracao); // Mostra aceleracao.
    imprimirCampoTempo(3, itemSubmenu == 2, modoEdicao, "Atraso:", sliderAtrasoMs); // Mostra atraso antes do movimento.
  }
}

void voltarSubmenuSlider() {                       // Volta para lista de submenus do Slider.
  dentroSubmenu = false;                           // Sai do submenu.
  itemSubmenu = 0;                                 // Reinicia subitem.
  modoEdicao = false;                              // Sai de edicao.
  modoMoverAtivo = false;                          // Sai do mover.
  lcd.clear();                                     // Limpa LCD.
  lcdSujo = true;                                  // Atualiza LCD.
}


// ============================================================
// MENU CONFIG
// ============================================================

void telaConfig() {                                // Controla menu Config.
  const byte totalItens = 10;                      // Define dez itens de configuracao.
  int giro = consumirEncoderDelta();               // Le giro.

  if (encoderLongo) {                              // Se clique longo.
    voltarMenuPrincipal();                         // Volta ao menu principal.
    return;                                        // Sai para nao redesenhar tela antiga.
  }

  if (!modoEdicao && giro > 0) {                   // Se navegando e girou direita.
    itemMenu = (itemMenu + totalItens - 1) % totalItens; // Sobe.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (!modoEdicao && giro < 0) {                   // Se navegando e girou esquerda.
    itemMenu = (itemMenu + 1) % totalItens;        // Desce.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemMenu <= 7) {             // Se clicou em item editavel.
    modoEdicao = !modoEdicao;                      // Entra/sai da edicao.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (encoderClick && itemMenu == 8) {             // Se clicou em salvar.
    salvarConfigEEPROM();                          // Salva EEPROM.
    mostrarMensagem("EEPROM", "SALVA", "", "", 900); // Mostra aviso.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para evitar redesenho antigo.
  }

  if (encoderClick && itemMenu == 9) {             // Se clicou em fabrica.
    restaurarFabricaEEPROM();                      // Restaura fabrica.
    mostrarMensagem("PADRAO", "RESTAURADO", "", "", 900); // Mostra aviso.
    lcdSujo = true;                                // Atualiza LCD.
    return;                                        // Sai para evitar redesenho antigo.
  }

  if (modoEdicao && giro != 0) {                   // Se editando.
    ajustarConfig(giro);                           // Ajusta valor.
    lcdSujo = true;                                // Atualiza LCD.
  }

  if (precisaAtualizarLCD()) {                     // Se precisa atualizar.
    limparTodasLinhas();                           // Limpa linhas.
    imprimirTitulo("CONFIG");                      // Imprime titulo.

    if (itemMenu <= 2) {                           // Primeira pagina.
      imprimirCampoFloat(1, itemMenu == 0, modoEdicao, "Passos/mm:", passosPorMM); // Mostra calibracao.
      imprimirCampoDistanciaMM(2, itemMenu == 1, modoEdicao, "Curso:", cursoTotalAtual); // Mostra curso.
      imprimirCampoUmValor(3, itemMenu == 2, modoEdicao, "MovL:", passoManualLentoUm); // Mostra mover lento.
    }
    else if (itemMenu <= 5) {                      // Segunda pagina.
      imprimirCampoUmValor(1, itemMenu == 3, modoEdicao, "MovM:", passoManualMedioUm); // Mostra mover medio.
      imprimirCampoUmValor(2, itemMenu == 4, modoEdicao, "MovR:", passoManualRapidoUm); // Mostra mover rapido.
      imprimirCampoVelocidadeMMs(3, itemMenu == 5, modoEdicao, "VelL:", velMoverLentaMMs); // Mostra velocidade lenta.
    }
    else if (itemMenu <= 8) {                      // Terceira pagina.
      imprimirCampoVelocidadeMMs(1, itemMenu == 6, modoEdicao, "VelM:", velMoverMediaMMs); // Mostra velocidade media.
      imprimirCampoVelocidadeMMs(2, itemMenu == 7, modoEdicao, "VelR:", velMoverRapidaMMs); // Mostra velocidade rapida.
      imprimirItem(3, itemMenu == 8, "Salvar");   // Mostra salvar.
    }
    else {                                         // Quarta pagina.
      imprimirCampoVelocidadeMMs(1, false, false, "VelM:", velMoverMediaMMs); // Mostra referencia.
      imprimirCampoVelocidadeMMs(2, false, false, "VelR:", velMoverRapidaMMs); // Mostra referencia.
      imprimirItem(3, true, "Fabrica");           // Mostra fabrica.
    }
  }
}

void ajustarConfig(int direcao) {                  // Ajusta Config.
  if (itemMenu == 0) passosPorMM = max(1.0, passosPorMM + direcao * 10.0); // Ajusta passos/mm.
  if (itemMenu == 1) cursoTotalAtual = max(1L, cursoTotalAtual + direcao * 100L); // Ajusta curso.
  if (itemMenu == 2) passoManualLentoUm = constrain(passoManualLentoUm + direcao, 1L, 1000L); // Ajusta mover lento.
  if (itemMenu == 3) passoManualMedioUm = constrain(passoManualMedioUm + direcao * 10L, 10L, 5000L); // Ajusta mover medio.
  if (itemMenu == 4) passoManualRapidoUm = constrain(passoManualRapidoUm + direcao * 100L, 100L, 20000L); // Ajusta mover rapido.
  if (itemMenu == 5) velMoverLentaMMs = constrain(velMoverLentaMMs + direcao * 0.05, 0.05, 2.00); // Ajusta velocidade lenta.
  if (itemMenu == 6) velMoverMediaMMs = constrain(velMoverMediaMMs + direcao * 0.10, 0.10, 10.00); // Ajusta velocidade media.
  if (itemMenu == 7) velMoverRapidaMMs = constrain(velMoverRapidaMMs + direcao * 0.50, 1.00, 30.00); // Ajusta velocidade rapida.
}

// ============================================================
// ROTINAS AUTOMATICAS
// ============================================================

void executarStacking() {                          // Executa Stacking.
  if (!validarStacking()) return;                  // Sai se invalido.
  cancelado = false;                               // Limpa cancelamento.
  telaAtual = TELA_EXECUTANDO;                     // Marca executando.
  stepper.enableOutputs();                         // Habilita motor.
  mostrarMensagem("STACKING", "Atraso inicial", "", "", 0); // Mostra atraso.
  esperarComCancelamento(stackAtrasoInicialMs);    // Aguarda atraso.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  long inicio = stackSentidoAB ? pontoA : pontoB;  // Define inicio.
  long fim = stackSentidoAB ? pontoB : pontoA;     // Define fim.
  long sentido = (fim > inicio) ? 1 : -1;          // Define sentido numerico.
  mostrarMensagem("STACKING", "Indo ao inicio", "", "", 0); // Mostra status.
  moverParaBloqueante(inicio, velocidadeRapida);   // Move ao inicio.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  for (int foto = 1; foto <= stackFotos; foto++) { // Percorre fotos.
    atualizarDisplayExecucao("STACKING", foto, stackFotos); // Mostra progresso.
    dispararCameraNormal();                        // Dispara camera.
    esperarComCancelamento(stackTempoPosFotoMs);   // Espera pos-foto.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
    if (foto < stackFotos) {                       // Se nao for ultima.
      moverParaBloqueante(posicaoAtual + sentido * stackPassosPorFoto, velocidadeRapida); // Move para proxima.
      esperarComCancelamento(stackTempoEstabilizacaoMs); // Espera estabilizar.
    }
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
  }
  executarRetornoStacking();                       // Executa retorno.
  telaAtual = TELA_STACKING;                       // Volta ao Stacking.
  dentroSubmenu = true;                            // Mantem dentro do submenu.
  submenuStack = 4;                                // Volta para FOTOGRAFAR.
  mostrarMensagem("STACKING OK", "Rotina final", "concluida", "", 1200); // Mostra fim.
  lcdSujo = true;                                  // Atualiza LCD.
}

bool validarStacking() {                           // Valida Stacking.
  if (!pontoADefinido || !pontoBDefinido) {        // Verifica pontos.
    mostrarMensagem("ERRO", "Defina A e B", "", "", 1200); // Mostra erro.
    lcdSujo = true;                                // Atualiza LCD.
    return false;                                  // Bloqueia.
  }
  if (pontoA == pontoB) {                          // Verifica distancia zero.
    mostrarMensagem("ERRO", "A igual a B", "", "", 1200); // Mostra erro.
    lcdSujo = true;                                // Atualiza LCD.
    return false;                                  // Bloqueia.
  }
  return true;                                     // Autoriza.
}

void executarRetornoStacking() {                   // Executa retorno.
  if (stackRetorno == 1) moverParaBloqueante(pontoA, velocidadeRapida); // Retorna A.
  if (stackRetorno == 2) moverParaBloqueante(pontoB, velocidadeRapida); // Retorna B.
}

void executarBulb() {                              // Executa Bulb.
  cancelado = false;                               // Limpa cancelamento.
  telaAtual = TELA_EXECUTANDO;                     // Marca executando.
  mostrarMensagem("BULB", "Atraso inicial", "", "", 0); // Mostra atraso.
  esperarComCancelamento(bulbAtrasoInicialMs);     // Aguarda atraso.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  for (int i = 1; i <= bulbDisparos; i++) {        // Percorre fotos.
    atualizarDisplayExecucao("BULB", i, bulbDisparos); // Mostra progresso.
    digitalWrite(SHUTTER_PIN, HIGH);               // Aciona disparo.
    esperarComCancelamento(bulbTempoMs);           // Mantem bulb.
    digitalWrite(SHUTTER_PIN, LOW);                // Solta disparo.
    esperarComCancelamento(bulbTempoPosFotoMs);    // Espera pos-foto.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
    if (i < bulbDisparos) esperarComCancelamento(bulbIntervaloMs); // Espera intervalo.
  }
  telaAtual = TELA_BULB;                           // Volta ao Bulb.
  mostrarMensagem("BULB OK", "Rotina final", "concluida", "", 1200); // Mostra fim.
  lcdSujo = true;                                  // Atualiza LCD.
}


void executarSliderVideo() {                       // Executa Slider em video continuo.
  if (!validarSlider()) return;                    // Sai se invalido.
  cancelado = false;                               // Limpa cancelamento.
  telaAtual = TELA_EXECUTANDO;                     // Marca executando.
  stepper.enableOutputs();                         // Habilita motor.
  long inicio = sliderSentidoAB ? pontoA : pontoB; // Define inicio.
  long fim = sliderSentidoAB ? pontoB : pontoA;    // Define fim.
  mostrarMensagem("SLIDER VIDEO", "Indo ao inicio", "", "", 0); // Mostra status.
  moverParaBloqueante(inicio, velocidadeRapida);   // Move ao inicio.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  esperarAtrasoSlider("SLIDER VIDEO");             // Aguarda atraso configurado antes do take.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  atualizarDisplaySlider("SLIDER VIDEO", 1, 1);    // Mostra execucao.
  moverParaBloqueanteSlider(fim);                  // Move ate o fim em velocidade do Slider.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  telaAtual = TELA_SLIDER;                         // Volta ao Slider.
  dentroSubmenu = true;                            // Mantem dentro do submenu.
  submenuSlider = 1;                               // Volta para Video.
  mostrarMensagem("SLIDER OK", "Video concluido", "", "", 1200); // Mostra fim.
  lcdSujo = true;                                  // Atualiza LCD.
}

void executarSliderLoop() {                        // Executa Slider em Loop A-B.
  if (!validarSlider()) return;                    // Sai se invalido.
  cancelado = false;                               // Limpa cancelamento.
  telaAtual = TELA_EXECUTANDO;                     // Marca executando.
  stepper.enableOutputs();                         // Habilita motor.
  long inicio = sliderSentidoAB ? pontoA : pontoB; // Define inicio.
  long fim = sliderSentidoAB ? pontoB : pontoA;    // Define fim.
  mostrarMensagem("SLIDER LOOP", "Indo ao inicio", "", "", 0); // Mostra status.
  moverParaBloqueante(inicio, velocidadeRapida);   // Move ao inicio.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  esperarAtrasoSlider("SLIDER LOOP");              // Aguarda atraso configurado antes do primeiro ciclo.
  if (cancelado) { pararRotina(); return; }        // Cancela se necessario.
  for (int ciclo = 1; ciclo <= sliderCiclos; ciclo++) { // Percorre ciclos.
    atualizarDisplaySlider("SLIDER LOOP", ciclo, sliderCiclos); // Mostra progresso.
    moverParaBloqueanteSlider(fim);                // Vai para a ponta final.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
    esperarComCancelamento(sliderPausaPontasMs);   // Pausa na ponta.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
    moverParaBloqueanteSlider(inicio);             // Volta para a ponta inicial.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
    if (ciclo < sliderCiclos) esperarComCancelamento(sliderPausaPontasMs); // Pausa antes do proximo ciclo.
    if (cancelado) { pararRotina(); return; }      // Cancela se necessario.
  }
  telaAtual = TELA_SLIDER;                         // Volta ao Slider.
  dentroSubmenu = true;                            // Mantem dentro do submenu.
  submenuSlider = 2;                               // Volta para Loop.
  mostrarMensagem("SLIDER OK", "Loop concluido", "", "", 1200); // Mostra fim.
  lcdSujo = true;                                  // Atualiza LCD.
}

bool validarSlider() {                             // Valida pontos do Slider.
  if (!pontoADefinido || !pontoBDefinido) {        // Verifica pontos.
    mostrarMensagem("ERRO", "Defina A e B", "", "", 1200); // Mostra erro.
    lcdSujo = true;                                // Atualiza LCD.
    return false;                                  // Bloqueia.
  }
  if (pontoA == pontoB) {                          // Verifica distancia zero.
    mostrarMensagem("ERRO", "A igual a B", "", "", 1200); // Mostra erro.
    lcdSujo = true;                                // Atualiza LCD.
    return false;                                  // Bloqueia.
  }
  return true;                                     // Autoriza.
}

void moverParaBloqueanteSlider(long destino) {     // Move com parametros proprios do Slider.
  destino = constrain(destino, -cursoTotalAtual, cursoTotalAtual); // Limita destino.
  stepper.setMaxSpeed(sliderVelocidadePassosPorSegundo()); // Converte mm/s para passos/s e define velocidade do Slider.
  stepper.setAcceleration(sliderAceleracao);       // Define aceleracao do Slider.
  stepper.moveTo(destino);                         // Define destino.
  while (stepper.distanceToGo() != 0) {            // Enquanto nao chegou.
    atualizarEntradas();                           // Atualiza entradas.
    if (encoderLongo) cancelado = true;            // Clique longo cancela.
    if (cancelado) {                                // Para se cancelado.
      stepper.stop();                              // Solicita parada.
      stepper.setCurrentPosition(stepper.currentPosition()); // Remove destino pendente.
      break;                                      // Sai do movimento.
    }
    if (limiteFisicoBloqueiaMovimento()) {         // Para se fim acionado.
      stepper.stop();                              // Solicita parada.
      stepper.setCurrentPosition(stepper.currentPosition()); // Remove destino pendente.
      break;                                      // Sai do movimento.
    }
    stepper.run();                                 // Executa passo.
    posicaoAtual = stepper.currentPosition();      // Atualiza posicao.
  }
  posicaoAtual = stepper.currentPosition();        // Garante posicao.
  stepper.setAcceleration(aceleracaoMotor);        // Restaura aceleracao geral.
}


// ============================================================
// CONVERSOES DO SLIDER
// ============================================================

float sliderVelocidadePassosPorSegundo() {         // Converte velocidade do Slider de mm/s para passos/s.
  return sliderVelocidadeMMs * passosPorMM;        // Usa a calibracao atual de passos por milimetro.
}

unsigned long tempoSliderABSegundos() {            // Calcula tempo aproximado do percurso A-B.
  if (sliderVelocidadeMMs <= 0.0) return 0;        // Evita divisao por zero.
  float distanciaMM = passosParaMM(distanciaStackingAB()); // Calcula distancia A-B em milimetros.
  return (unsigned long)(distanciaMM / sliderVelocidadeMMs); // Retorna tempo em segundos.
}

// ============================================================
// CALCULOS
// ============================================================

long distanciaStackingAB() {                       // Calcula distancia A-B em passos internos.
  return abs(pontoB - pontoA);                     // Retorna modulo da distancia em passos.
}

float micrometrosPorPasso() {                      // Calcula quantos micrometros existem em cada passo interno.
  return 1000.0 / passosPorMM;                     // Converte passos/mm para micrometros/passo.
}

long passosParaMicrometros(long passos) {          // Converte passos internos para micrometros.
  return lround((float)passos * micrometrosPorPasso()); // Retorna valor arredondado em micrometros.
}

long micrometrosParaPassos(long micrometros) {     // Converte micrometros para passos internos.
  long passos = lround((float)micrometros / micrometrosPorPasso()); // Calcula passos equivalentes.
  if (passos < 1) passos = 1;                      // Garante pelo menos 1 passo.
  return passos;                                   // Retorna passos internos.
}

float passosParaMM(long passos) {                  // Converte passos internos para milimetros.
  return (float)passos / passosPorMM;              // Retorna distancia em milimetros.
}

void recalcularPassosPorFotos() {                  // Recalcula passos por foto a partir da quantidade de fotos.
  long dist = distanciaStackingAB();               // Calcula distancia em passos.
  if (dist <= 0) return;                           // Sai se invalido.
  if (stackFotos < 2) stackFotos = 2;              // Garante minimo.
  stackPassosPorFoto = dist / (stackFotos - 1);    // Calcula passos internos por foto.
  if (stackPassosPorFoto < 1) stackPassosPorFoto = 1; // Garante minimo.
}

void recalcularFotosPorPassos() {                  // Recalcula fotos a partir do passo em micrometros convertido para passos.
  long dist = distanciaStackingAB();               // Calcula distancia em passos.
  if (dist <= 0) return;                           // Sai se invalido.
  if (stackPassosPorFoto < 1) stackPassosPorFoto = 1; // Garante minimo.
  stackFotos = (dist / stackPassosPorFoto) + 1;    // Calcula fotos.
  if (stackFotos < 2) stackFotos = 2;              // Garante minimo.
}

// ============================================================
// MOTOR E SEGURANCA
// ============================================================

void moverParaBloqueante(long destino, float velocidade) { // Move para posicao absoluta.
  destino = constrain(destino, -cursoTotalAtual, cursoTotalAtual); // Limita destino.
  stepper.setMaxSpeed(velocidade);                  // Define velocidade.
  stepper.setAcceleration(aceleracaoMotor);         // Define aceleracao.
  stepper.moveTo(destino);                          // Define destino.
  while (stepper.distanceToGo() != 0) {             // Enquanto nao chegou.
    atualizarEntradas();                            // Atualiza entradas.
    if (encoderLongo) cancelado = true;             // Clique longo cancela.
    if (cancelado) {                                // Para se cancelado.
      stepper.stop();                              // Solicita parada.
      stepper.setCurrentPosition(stepper.currentPosition()); // Remove destino pendente.
      break;                                      // Sai do movimento.
    }
    if (limiteFisicoBloqueiaMovimento()) {         // Para se fim acionado.
      stepper.stop();                              // Solicita parada.
      stepper.setCurrentPosition(stepper.currentPosition()); // Remove destino pendente.
      break;                                      // Sai do movimento.
    }
    stepper.run();                                  // Executa passo.
    posicaoAtual = stepper.currentPosition();       // Atualiza posicao.
  }
  posicaoAtual = stepper.currentPosition();         // Garante posicao.
}

void moverRelativoBloqueante(long delta, float velocidade) { // Move relativo.
  moverParaBloqueante(stepper.currentPosition() + delta, velocidade); // Soma delta.
}

bool limiteFisicoBloqueiaMovimento() {             // Verifica limites fisicos.
  if (homeAcionado() && stepper.distanceToGo() < 0) return true; // Bloqueia HOME.
  if (finalAcionado() && stepper.distanceToGo() > 0) return true; // Bloqueia FINAL.
  return false;                                    // Permite movimento.
}

bool homeAcionado() {                              // Le fim inicial.
  return digitalRead(ENDSTOP_HOME) == HIGH;        // HIGH indica acionado em NC com pullup.
}

bool finalAcionado() {                             // Le fim final.
  return digitalRead(ENDSTOP_FINAL) == HIGH;       // HIGH indica acionado em NC com pullup.
}

// ============================================================
// DISPARO E ESPERA
// ============================================================

void dispararCameraNormal() {                      // Dispara camera.
  digitalWrite(SHUTTER_PIN, HIGH);                 // Liga disparo.
  esperarComCancelamento(stackTempoDisparoMs);     // Espera tempo.
  digitalWrite(SHUTTER_PIN, LOW);                  // Desliga disparo.
}

void esperarComCancelamento(unsigned long tempoMs) { // Espera com cancelamento.
  unsigned long inicio = millis();                 // Guarda inicio.
  while (millis() - inicio < tempoMs) {            // Aguarda tempo.
    atualizarEntradas();                           // Atualiza entradas.
    if (encoderLongo) cancelado = true;             // Clique longo cancela.
    if (cancelado) return;                         // Sai se cancelado.
    delay(2);                                      // Pequena pausa.
  }
}

void esperarAtrasoSlider(const char* titulo) {      // Aguarda atraso configurado do Slider.
  if (sliderAtrasoMs == 0) return;                 // Sem atraso, inicia imediatamente.
  mostrarMensagem(titulo, "Atraso...", "", "Segure p/cancelar", 0); // Mostra atraso.
  esperarComCancelamento(sliderAtrasoMs);          // Aguarda com possibilidade de cancelamento.
}

void limparEstadoAposCancelamento() {              // Limpa estados que podem travar o MOVER depois de cancelar.
  long pos = stepper.currentPosition();            // Le a posicao real atual do AccelStepper.
  stepper.stop();                                  // Garante parada solicitada.
  stepper.moveTo(pos);                             // Remove qualquer destino antigo pendente.
  stepper.setCurrentPosition(pos);                 // Sincroniza posicao e destino interno.
  posicaoAtual = pos;                              // Atualiza a posicao logica.
  encoderDelta = 0;                                // Descarta giros acumulados durante o cancelamento.
  encoderClick = false;                            // Limpa clique curto pendente.
  encoderLongo = false;                            // Limpa clique longo pendente.
  swPressionando = false;                          // Reinicia o estado interno do botao do encoder.
  swLongoDisparado = false;                        // Libera novo clique longo somente apos nova leitura.
  ignorarEncoderAteSoltar = true;                  // Evita que o mesmo clique longo continue ativo apos cancelar.
  ultimoSW = digitalRead(ENC_SW);                  // Sincroniza o estado atual do botao.
  swMudouEm = millis();                            // Reinicia debounce do botao.
  cancelado = false;                               // Garante cancelamento limpo.
}

void pararRotina() {                               // Para rotina.
  digitalWrite(SHUTTER_PIN, LOW);                  // Solta camera.
  stepper.stop();                                  // Para motor.
  limparEstadoAposCancelamento();                  // Limpa estados para nao travar o MOVER.
  telaAtual = TELA_PRINCIPAL;                      // Volta ao principal.
  modoMoverAtivo = false;                          // Sai do mover.
  modoEdicao = false;                              // Sai da edicao.
  mostrarMensagem("CANCELADO", "Rotina parada", "", "", 1200); // Mostra aviso.
  lcdSujo = true;                                  // Atualiza LCD.
}

// ============================================================
// NAVEGACAO
// ============================================================

void voltarMenuPrincipal() {                       // Volta para menu principal.
  telaAtual = TELA_PRINCIPAL;                      // Define tela principal.
  itemMenu = 0;                                    // Reinicia item.
  itemSubmenu = 0;                                 // Reinicia subitem.
  dentroSubmenu = false;                           // Sai de submenu.
  modoEdicao = false;                              // Sai de edicao.
  modoMoverAtivo = false;                          // Sai do mover.
  lcd.clear();                                     // Limpa LCD.
  lcdSujo = true;                                  // Atualiza LCD.
}

void voltarSubmenuStack() {                        // Volta para lista de submenus.
  dentroSubmenu = false;                           // Sai do submenu.
  itemSubmenu = 0;                                 // Reinicia subitem.
  modoEdicao = false;                              // Sai de edicao.
  modoMoverAtivo = false;                          // Sai do mover.
  lcd.clear();                                     // Limpa LCD.
  lcdSujo = true;                                  // Atualiza LCD.
}

// ============================================================
// DISPLAY E UTILITARIOS
// ============================================================

bool precisaAtualizarLCD() {                       // Verifica se LCD precisa atualizar.
  if (lcdSujo) {                                   // Se esta sujo.
    lcdSujo = false;                               // Limpa flag.
    return true;                                   // Autoriza desenho.
  }
  return false;                                    // Nao desenha.
}

void limparLinha(byte linha) {                     // Limpa uma linha.
  lcd.setCursor(0, linha);                         // Vai ao inicio.
  lcd.print("                    ");               // Imprime 20 espacos.
  lcd.setCursor(0, linha);                         // Volta ao inicio.
}

void limparTodasLinhas() {                         // Limpa todas as linhas.
  limparLinha(0);                                  // Limpa linha 0.
  limparLinha(1);                                  // Limpa linha 1.
  limparLinha(2);                                  // Limpa linha 2.
  limparLinha(3);                                  // Limpa linha 3.
}

void imprimirTitulo(const char* titulo) {          // Imprime titulo com bateria.
  lcd.setCursor(0, 0);                             // Vai para linha 0.
  lcd.print(titulo);                               // Imprime titulo.
  imprimirCabecalhoBateria();                      // Imprime bateria.
}

void atualizarBateriaPeriodica() {                // Atualiza a bateria sem redesenhar a tela inteira.
  if (movimentoContinuoAB != 0) return;             // Evita pausas de ADC durante movimento continuo.
  if (millis() - ultimaAtualizacaoBateria >= 1000) { // Verifica se passou 1 segundo.
    ultimaAtualizacaoBateria = millis();          // Atualiza o marcador de tempo.
    imprimirCabecalhoBateria();                   // Reescreve apenas o canto superior direito.
  }
}

void imprimirCabecalhoBateria() {                  // Imprime bateria no canto direito.

  float v = lerTensaoBateria();                    // Le a tensao da bateria.

  lcd.setCursor(15, 0);                            // Vai para os ultimos caracteres.
  lcd.print("     ");                              // Limpa a area.

  lcd.setCursor(15, 0);                            // Volta para o inicio da area.

  if (v <= 10.5) {                                 // Verifica bateria baixa.
    lcd.print("LOW");                              // Mostra aviso.
  }
  else {                                           // Caso contrario.
    lcd.print(v, 1);                               // Mostra tensao.
    lcd.print("V");                                // Mostra unidade.
  }
}

void imprimirItem(byte linha, bool selecionado, const char* texto) { // Imprime item simples.
  lcd.setCursor(0, linha);                         // Vai para linha.
  lcd.print(selecionado ? ">" : " ");              // Imprime cursor.
  lcd.print(texto);                                // Imprime texto.
}

void imprimirPrefixo(byte linha, bool selecionado, bool editando) { // Imprime prefixo.
  lcd.setCursor(0, linha);                         // Vai para linha.
  if (editando) lcd.print("*");                    // Imprime asterisco se editando.
  else lcd.print(selecionado ? ">" : " ");         // Imprime cursor se selecionado.
}

void imprimirCampoLong(byte linha, bool selecionado, bool editando, const char* rotulo, long valor) { // Campo long.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valor);                                // Imprime valor.
}

void imprimirCampoInt(byte linha, bool selecionado, bool editando, const char* rotulo, int valor) { // Campo int.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valor);                                // Imprime valor.
}

void imprimirCampoUmValor(byte linha, bool selecionado, bool editando, const char* rotulo, long valorUm) { // Campo em micrometros.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valorUm);                              // Imprime valor em micrometros.
  lcd.print("um");                                 // Imprime unidade ASCII para micrometros.
}

void imprimirCampoMicrometro(byte linha, bool selecionado, bool editando, const char* rotulo, long passos) { // Campo que recebe passos e mostra micrometros.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(passosParaMicrometros(passos));        // Converte e imprime micrometros.
  lcd.print("um");                                 // Imprime unidade ASCII para micrometros.
}

void imprimirCampoDistanciaMM(byte linha, bool selecionado, bool editando, const char* rotulo, long passos) { // Campo de distancia em milimetros.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(passosParaMM(passos), 2);              // Converte e imprime milimetros.
  lcd.print("mm");                                 // Imprime unidade em milimetros.
}

void imprimirCampoFloat(byte linha, bool selecionado, bool editando, const char* rotulo, float valor) { // Campo float.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valor, 1);                             // Imprime valor.
}

void imprimirCampoVelocidadeMMs(byte linha, bool selecionado, bool editando, const char* rotulo, float valor) { // Campo de velocidade em mm/s.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valor, 2);                             // Imprime velocidade com duas casas decimais.
  lcd.print("mm/s");                              // Imprime unidade.
}

void imprimirCampoTexto(byte linha, bool selecionado, bool editando, const char* rotulo, const char* valor) { // Campo texto.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  lcd.print(valor);                                // Imprime valor.
}

void imprimirDirecaoSliderComDistancia(byte linha, bool selecionado, bool editando) { // Mostra direcao do Slider junto com distancia A-B.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime cursor ou asterisco.
  lcd.print("Dir:");                               // Imprime rotulo da direcao.
  lcd.print(sliderSentidoAB ? "A>B" : "B>A");      // Imprime direcao atual.
  lcd.print(" D:");                                // Imprime rotulo da distancia.
  lcd.print(passosParaMM(distanciaStackingAB()), 1); // Imprime distancia A-B em milimetros.
  lcd.print("mm");                                 // Imprime unidade.
}

void imprimirCampoTempo(byte linha, bool selecionado, bool editando, const char* rotulo, unsigned long valor) { // Campo tempo.
  imprimirPrefixo(linha, selecionado, editando && selecionado); // Imprime prefixo.
  lcd.print(rotulo);                               // Imprime rotulo.
  if (valor >= 1000) {                             // Se maior que 1 segundo.
    lcd.print(valor / 1000.0, 1);                  // Imprime em segundos.
    lcd.print("s");                                // Imprime unidade segundos.
  } else {                                         // Se menor que 1 segundo.
    lcd.print(valor);                              // Imprime em milissegundos.
    lcd.print("ms");                               // Imprime unidade ms.
  }
}

void mostrarMensagem(const char* l0, const char* l1, const char* l2, const char* l3, unsigned long tempo) { // Mostra mensagem.
  lcd.clear();                                     // Limpa LCD.
  lcd.setCursor(0, 0); lcd.print(l0);              // Imprime linha 0.
  lcd.setCursor(0, 1); lcd.print(l1);              // Imprime linha 1.
  lcd.setCursor(0, 2); lcd.print(l2);              // Imprime linha 2.
  lcd.setCursor(0, 3); lcd.print(l3);              // Imprime linha 3.
  if (tempo > 0) delay(tempo);                     // Aguarda se houver tempo.
}

void atualizarDisplayExecucao(const char* titulo, int atual, int total) { // Mostra execucao.
  lcd.clear();                                     // Limpa LCD.
  lcd.setCursor(0, 0); lcd.print(titulo);          // Imprime titulo.
  lcd.setCursor(0, 1); lcd.print("Foto:"); lcd.print(atual); lcd.print("/"); lcd.print(total); // Imprime foto.
  lcd.setCursor(0, 2); lcd.print("Pos:"); lcd.print(posicaoAtual); // Imprime posicao.
  lcd.setCursor(0, 3); lcd.print("Segure p/ cancelar"); // Imprime cancelar.
}

void atualizarDisplaySlider(const char* titulo, int atual, int total) { // Mostra execucao do Slider.
  lcd.clear();                                     // Limpa LCD.
  lcd.setCursor(0, 0); lcd.print(titulo);          // Imprime titulo.
  lcd.setCursor(0, 1); lcd.print("Ciclo:"); lcd.print(atual); lcd.print("/"); lcd.print(total); // Imprime ciclo.
  lcd.setCursor(0, 2); lcd.print("Pos:"); lcd.print(posicaoAtual); // Imprime posicao.
  lcd.setCursor(0, 3); lcd.print("Segure p/ cancelar"); // Imprime cancelar.
}

float lerTensaoBateria() {                         // Le tensao da bateria.
  long soma = 0;                                   // Cria acumulador.
  for (byte i = 0; i < 10; i++) {                  // Faz 10 leituras.
    soma += analogRead(BATTERY_PIN);               // Soma leitura.
    delay(2);                                      // Aguarda pequeno tempo.
  }
  float leitura = soma / 10.0;                     // Calcula media.
  float vPino = (leitura * ADC_REF) / ADC_MAX;     // Converte para tensao no A0.
  float vBat = vPino * ((BAT_R1 + BAT_R2) / BAT_R2); // Calcula tensao real.
  return vBat;                                     // Retorna tensao.
}

const char* nomeVelocidade() {                     // Retorna nome da velocidade.
  if (modoMover == 0) return "LENTO";              // Retorna LENTO.
  if (modoMover == 1) return "MEDIO";              // Retorna MEDIO.
  return "RAPIDO";                                 // Retorna RAPIDO.
}

long passoManualAtual() {                          // Retorna deslocamento do modo mover em passos internos.
  if (modoMover == 0) return micrometrosParaPassos(passoManualLentoUm);  // Retorna deslocamento lento.
  if (modoMover == 1) return micrometrosParaPassos(passoManualMedioUm);  // Retorna deslocamento medio.
  return micrometrosParaPassos(passoManualRapidoUm);                     // Retorna deslocamento rapido.
}

float velocidadeManualAtual() {                    // Retorna velocidade do modo mover em passos por segundo.
  if (modoMover == 0) return velMoverLentaMMs * passosPorMM;  // Converte velocidade lenta para passos/s.
  if (modoMover == 1) return velMoverMediaMMs * passosPorMM;  // Converte velocidade media para passos/s.
  return velMoverRapidaMMs * passosPorMM;                     // Converte velocidade rapida para passos/s.
}

const char* textoRetorno() {                       // Retorna texto do retorno.
  if (stackRetorno == 0) return "Nao";             // Retorna Nao.
  if (stackRetorno == 1) return "A";               // Retorna A.
  return "B";                                      // Retorna B.
}

void imprimirRetorno() {                           // Imprime retorno.
  lcd.print(textoRetorno());                       // Imprime texto retorno.
}

unsigned long ajustarTempo(unsigned long valor, long delta, unsigned long minimo) { // Ajusta tempo.
  long novoValor = (long)valor + delta;            // Soma delta.
  if (novoValor < (long)minimo) novoValor = minimo; // Aplica minimo.
  return (unsigned long)novoValor;                 // Retorna valor.
}

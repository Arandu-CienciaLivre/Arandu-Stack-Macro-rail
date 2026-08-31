# Eletrônica e Ligações — Arandu Stack Macro Rail v1.0.0

[Português](#português) | [English](#english)

---

# Português

## 1. Visão geral

O sistema eletrônico do Arandu Stack Macro Rail é baseado em um Arduino Nano responsável pelo controle da interface, acionamento do motor de passo e disparo da câmera.

A eletrônica principal é composta por:

- Arduino Nano;
- driver TMC2209;
- placa de extensão/breakout para o TMC2209;
- motor de passo NEMA 17;
- LCD 20×4 com interface I²C;
- encoder rotativo KY-040;
- dois botões auxiliares;
- módulo relé para disparo da câmera;
- regulador de tensão para alimentação da eletrônica;
- bateria Li-ion 3S4P;
- sistema opcional de leitura da tensão da bateria pelo Arduino;
- voltímetro dedicado no protótipo;
- cabo de interligação de 8 vias entre o módulo de controle e o trilho.

---

## 2. Arduino Nano

O Arduino Nano executa o firmware principal e controla o driver do motor, o relé, a interface de usuário e o display.

### 2.1 Pinagem

| Pino Arduino | Função |
|---|---|
| D2 | STEP — driver do motor |
| D3 | DIR — driver do motor |
| D4 | ENABLE — driver do motor |
| D5 | Acionamento do módulo relé |
| D8 | CLK — encoder KY-040 |
| D9 | DT — encoder KY-040 |
| D10 | SW — botão do encoder |
| D11 | Botão auxiliar 1 |
| D12 | Botão auxiliar 2 |
| A0 | Leitura opcional da tensão da bateria |
| A4 | SDA — LCD I²C |
| A5 | SCL — LCD I²C |
| 5V | Alimentação lógica dos módulos compatíveis |
| GND | Referência comum do circuito |

A entrada A0 é reservada para o sistema opcional de monitoramento da tensão da bateria.

---

## 3. Controle do motor de passo

O movimento do trilho é realizado por um motor de passo NEMA 17 controlado por um driver TMC2209.

O TMC2209 é instalado em uma placa de extensão/breakout, utilizada para facilitar a conexão do driver com a alimentação, sinais de controle e motor.

### 3.1 Sinais de controle

As conexões principais entre o Arduino Nano e o driver são:

| Arduino Nano | Driver |
|---|---|
| D2 | STEP |
| D3 | DIR |
| D4 | ENABLE |

O firmware utiliza esses sinais para controlar o deslocamento, sentido de movimento e habilitação do motor.

### 3.2 Ligações do motor

O motor utiliza quatro condutores correspondentes às duas bobinas do motor.

As quatro saídas do driver são conectadas através da placa de extensão do TMC2209 e seguem pelos pinos 1–4 do cabo principal de 8 vias até o motor instalado no trilho.

A associação entre as quatro saídas do driver e as bobinas deve respeitar a identificação do motor utilizado.

> Antes de energizar o sistema, verifique a identificação das duas bobinas e a ordem dos quatro condutores.

---

## 4. Interface de usuário

### 4.1 LCD 20×4

O display utiliza comunicação I²C.

| LCD I²C | Arduino Nano |
|---|---|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

O módulo adaptador I²C reduz a quantidade de conexões necessárias entre o display e o controlador.

### 4.2 Encoder KY-040

O encoder rotativo é utilizado para navegação e ajuste dos parâmetros do sistema.

| KY-040 | Arduino Nano |
|---|---|
| CLK | D8 |
| DT | D9 |
| SW | D10 |
| VCC | 5V |
| GND | GND |

### 4.3 Botões auxiliares

Dois botões adicionais são utilizados pela interface.

| Botão | Arduino Nano |
|---|---|
| Botão 1 | D11 |
| Botão 2 | D12 |

Os botões utilizam o GND como referência comum.

---

## 5. Disparo da câmera

O disparo da câmera é realizado através de um módulo relé controlado pelo Arduino Nano.

| Arduino Nano | Módulo relé |
|---|---|
| D5 | IN |

No lado de saída do relé são utilizados os contatos:

- **COM — Common (comum)**
- **NO — Normally Open (normalmente aberto)**

Os contatos COM e NO seguem pelos pinos 5 e 6 do cabo principal de 8 vias.

Em repouso, o circuito permanece aberto. Quando o relé é acionado pelo firmware, COM e NO são conectados, fechando o circuito de disparo da câmera.

No protótipo, o cabo de disparo utiliza:

- conector P1 no lado da câmera;
- conector P4 no lado do controlador/trilho.

A ligação pode ser adaptada para câmeras que utilizem outros padrões de conector ou disparo remoto.

---

## 6. Cabo principal de 8 vias

A interligação elétrica entre o módulo de controle e o conjunto instalado no trilho é realizada através de um cabo de 8 vias com conectores destacáveis de 8 pinos.

### 6.1 Distribuição dos pinos

| Pino | Função |
|---|---|
| 1 | Motor de passo |
| 2 | Motor de passo |
| 3 | Motor de passo |
| 4 | Motor de passo |
| 5 | Disparo da câmera |
| 6 | Disparo da câmera |
| 7 | Alimentação auxiliar positiva (+) |
| 8 | Alimentação auxiliar negativa (−) |

O cabo é dividido funcionalmente em:

- **4 vias** para o motor de passo;
- **2 vias** para o disparo da câmera;
- **2 vias** para alimentação auxiliar.

### 6.2 Alimentação auxiliar

Os pinos 7 e 8 funcionam como um bypass direto da alimentação principal da bateria.

Essa saída não realiza regulação ou conversão da tensão para a câmera ou para o acessório conectado.

Consequentemente, equipamentos que não sejam compatíveis diretamente com a tensão da bateria devem utilizar um sistema externo de conversão ou regulação apropriado.

---

## 7. Alimentação

O protótipo utiliza uma bateria Li-ion 3S4P.

A tensão nominal de um conjunto 3S é aproximadamente:

**11,1 V**

e sua tensão máxima quando completamente carregado é:

**12,6 V**

A alimentação é distribuída para os diferentes elementos do sistema conforme suas necessidades.

A eletrônica que requer tensão inferior utiliza regulação apropriada antes da alimentação dos módulos.

### 7.1 Monitoramento da bateria

O firmware possui suporte funcional para monitoramento da tensão da bateria através de uma entrada analógica do Arduino Nano.

Na configuração prevista, a leitura é realizada pelo pino A0.

Para utilizar essa função, deve ser instalado um divisor resistivo dimensionado de acordo com a tensão máxima da bateria utilizada, garantindo que a tensão aplicada à entrada analógica permaneça dentro da faixa segura do Arduino.

O firmware possui uma seção destinada à calibração da leitura da tensão. Essa calibração permite ajustar o valor indicado pelo sistema de acordo com as características reais do divisor resistivo e da montagem.

Dessa forma, o projeto permite duas formas de monitoramento:

- **monitoramento pelo Arduino:** bateria → divisor resistivo → A0 → leitura e calibração pelo firmware;
- **monitoramento independente:** voltímetro dedicado conectado à bateria.

No protótipo v1.0.0 foi utilizada a segunda opção, com um voltímetro dedicado conectado diretamente à saída da bateria.

O divisor resistivo é, portanto, opcional e necessário apenas quando se deseja utilizar a função de leitura de tensão integrada ao firmware.

---

## 8. Alimentação externa da câmera e acessórios

Os pinos 7 e 8 do cabo principal permitem levar a alimentação da bateria até a região da câmera.

Essa conexão pode ser utilizada para alimentar:

- câmera;
- iluminação;
- módulos auxiliares;
- outros acessórios instalados no trilho.

A tensão disponível nesses pinos corresponde diretamente à alimentação proveniente da bateria e deve ser adaptada às necessidades do equipamento conectado.

### 8.1 Exemplo utilizado no protótipo

Na configuração utilizada com uma Canon EOS T5i, a alimentação da câmera é realizada utilizando um sistema externo composto por:

**bateria do trilho → conversor PD → dummy battery USB → câmera**

O conversor e o dummy battery realizam a adaptação necessária entre a alimentação disponível no sistema e a requerida pela câmera.

Essa configuração é apenas um exemplo de implementação e não constitui requisito do Arandu Stack Macro Rail.

Outras câmeras podem exigir tensões, conectores, conversores ou sistemas de dummy battery diferentes.

---

## 9. Verificações antes da energização

Antes de energizar o sistema:

1. verificar a continuidade dos oito condutores do cabo principal;
2. confirmar a correspondência dos pinos nos conectores das duas extremidades;
3. verificar a identificação das duas bobinas do motor;
4. verificar a polaridade dos pinos 7 e 8;
5. verificar a tensão de saída dos reguladores e conversores utilizados;
6. confirmar a tensão exigida pela câmera ou acessório antes de utilizar a alimentação auxiliar;
7. verificar se não existem curtos entre alimentação, motor e circuito de disparo;
8. caso seja utilizado o monitoramento pelo Arduino, verificar a tensão de saída do divisor resistivo antes de conectá-lo ao pino A0.

A pinagem dos conectores deve ser mantida consistente em todas as extensões, cabos ou módulos adicionais utilizados com o sistema.

---

# English

## 1. Overview

The Arandu Stack Macro Rail electronic system is based on an Arduino Nano responsible for user-interface control, stepper motor operation, and camera triggering.

The main electronics consist of:

- Arduino Nano;
- TMC2209 driver;
- TMC2209 extension/breakout board;
- NEMA 17 stepper motor;
- 20×4 LCD with I²C interface;
- KY-040 rotary encoder;
- two auxiliary push buttons;
- relay module for camera triggering;
- voltage regulator for the electronics;
- 3S4P Li-ion battery pack;
- optional Arduino-based battery voltage monitoring system;
- dedicated voltmeter in the prototype;
- 8-wire interconnection cable between the control module and the rail.

---

## 2. Arduino Nano

The Arduino Nano runs the main firmware and controls the motor driver, relay, user interface, and display.

### 2.1 Pinout

| Arduino pin | Function |
|---|---|
| D2 | STEP — motor driver |
| D3 | DIR — motor driver |
| D4 | ENABLE — motor driver |
| D5 | Relay module control |
| D8 | CLK — KY-040 encoder |
| D9 | DT — KY-040 encoder |
| D10 | SW — encoder push button |
| D11 | Auxiliary button 1 |
| D12 | Auxiliary button 2 |
| A0 | Optional battery voltage measurement |
| A4 | SDA — I²C LCD |
| A5 | SCL — I²C LCD |
| 5V | Logic supply for compatible modules |
| GND | Common circuit reference |

Analog input A0 is reserved for the optional battery-voltage monitoring system.

---

## 3. Stepper motor control

Rail movement is provided by a NEMA 17 stepper motor controlled by a TMC2209 driver.

The TMC2209 is installed on an extension/breakout board used to simplify connections between the driver, power supply, control signals, and motor.

### 3.1 Control signals

The main connections between the Arduino Nano and the driver are:

| Arduino Nano | Driver |
|---|---|
| D2 | STEP |
| D3 | DIR |
| D4 | ENABLE |

The firmware uses these signals to control movement, direction, and motor enable state.

### 3.2 Motor connections

The stepper motor uses four conductors corresponding to its two motor coils.

The four driver outputs are connected through the TMC2209 extension board and routed through pins 1–4 of the main 8-wire cable to the motor installed on the rail.

The correspondence between the four driver outputs and motor coils must follow the identification of the motor used in the assembly.

> Before powering the system, verify the two motor coils and the order of the four conductors.

---

## 4. User interface

### 4.1 20×4 LCD

The display uses I²C communication.

| I²C LCD | Arduino Nano |
|---|---|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

The I²C adapter reduces the number of connections required between the display and controller.

### 4.2 KY-040 rotary encoder

The rotary encoder is used for menu navigation and parameter adjustment.

| KY-040 | Arduino Nano |
|---|---|
| CLK | D8 |
| DT | D9 |
| SW | D10 |
| VCC | 5V |
| GND | GND |

### 4.3 Auxiliary buttons

Two additional push buttons are used by the interface.

| Button | Arduino Nano |
|---|---|
| Button 1 | D11 |
| Button 2 | D12 |

The buttons use GND as their common reference.

---

## 5. Camera trigger

Camera triggering is performed through a relay module controlled by the Arduino Nano.

| Arduino Nano | Relay module |
|---|---|
| D5 | IN |

The relay output uses the following contacts:

- **COM — Common**
- **NO — Normally Open**

The COM and NO contacts are routed through pins 5 and 6 of the main 8-wire cable.

At rest, the circuit remains open. When the relay is activated by the firmware, COM and NO are connected, closing the camera trigger circuit.

In the prototype, the trigger cable uses:

- P1 connector on the camera side;
- P4 connector on the controller/rail side.

The connection can be adapted for cameras using different remote-trigger connector standards.

---

## 6. Main 8-wire cable

Electrical interconnection between the control module and the rail assembly is provided by an 8-wire cable with detachable 8-pin connectors.

### 6.1 Pin distribution

| Pin | Function |
|---|---|
| 1 | Stepper motor |
| 2 | Stepper motor |
| 3 | Stepper motor |
| 4 | Stepper motor |
| 5 | Camera trigger |
| 6 | Camera trigger |
| 7 | Auxiliary power positive (+) |
| 8 | Auxiliary power negative (−) |

The cable therefore contains:

- **4 wires** for the stepper motor;
- **2 wires** for the camera trigger;
- **2 wires** for auxiliary power.

### 6.2 Auxiliary power

Pins 7 and 8 provide a direct bypass from the main battery supply.

This output does not regulate or convert the voltage for the connected camera or accessory.

Equipment that is not directly compatible with the battery voltage must therefore use an appropriate external voltage-conversion or regulation system.

---

## 7. Power supply

The prototype uses a 3S4P Li-ion battery pack.

The nominal voltage of a 3S pack is approximately:

**11.1 V**

and its maximum fully charged voltage is:

**12.6 V**

Power is distributed to the different system components according to their electrical requirements.

Electronics requiring a lower voltage use appropriate regulation before being powered.

### 7.1 Battery monitoring

The firmware provides functional support for battery-voltage monitoring through an Arduino Nano analog input.

In the intended configuration, voltage measurement is performed through pin A0.

To use this function, a resistor divider must be installed and dimensioned according to the maximum voltage of the battery being used. The divider must ensure that the voltage applied to the Arduino analog input remains within its safe operating range.

The firmware includes a dedicated voltage-reading calibration section. This allows the displayed voltage to be adjusted according to the actual characteristics of the resistor divider and physical assembly.

The project therefore supports two battery-monitoring methods:

- **Arduino monitoring:** battery → resistor divider → A0 → firmware measurement and calibration;
- **independent monitoring:** dedicated voltmeter connected to the battery.

The v1.0.0 prototype uses the second option, with a dedicated voltmeter connected directly to the battery output.

The resistor divider is therefore optional and is only required when using the firmware-integrated voltage monitoring function.

---

## 8. External camera and accessory power

Pins 7 and 8 of the main cable allow battery power to be routed to the camera area.

This connection may be used to power:

- cameras;
- lighting;
- auxiliary modules;
- other accessories installed on the rail.

The voltage available on these pins corresponds directly to the battery supply and must be adapted to the requirements of the connected equipment.

### 8.1 Prototype example

With the Canon EOS T5i used in the prototype, camera power is provided through an external system consisting of:

**rail battery → PD converter → USB dummy battery → camera**

The converter and dummy battery provide the required adaptation between the system power supply and the voltage required by the camera.

This configuration is only an implementation example and is not a requirement of the Arandu Stack Macro Rail.

Other cameras may require different voltages, connectors, converters, or dummy battery systems.

---

## 9. Checks before powering the system

Before powering the system:

1. check continuity of all eight conductors in the main cable;
2. confirm pin correspondence at both connector ends;
3. verify the two stepper motor coils;
4. verify the polarity of pins 7 and 8;
5. verify the output voltage of any regulators or converters;
6. confirm the voltage required by the camera or accessory before using the auxiliary power output;
7. check for shorts between the power, motor, and camera-trigger circuits;
8. when using Arduino-based battery monitoring, verify the resistor-divider output voltage before connecting it to pin A0.

Connector pinout should remain consistent across any additional cables, extensions, or modules used with the system.

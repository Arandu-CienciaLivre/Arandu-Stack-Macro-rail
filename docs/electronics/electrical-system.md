# Sistema elétrico / Electrical System

[Português](#português) | [English](#english)

---

# Português

## 1. Visão geral

O sistema elétrico do **Arandu Stack Macro Rail** foi desenvolvido para integrar o controle do motor de passo, a interface do usuário, o disparo da câmera, a alimentação elétrica e os dispositivos opcionais de segurança em um único módulo de controle.

A arquitetura utiliza módulos eletrônicos comerciais integrados ao sistema, permitindo manutenção, substituição e reprodução com componentes de fácil acesso.

Os principais elementos são:

- Arduino Nano;
- placa de expansão para Arduino Nano com terminais;
- display LCD 20×4;
- módulo adaptador I²C para o LCD;
- encoder rotativo KY-040;
- dois botões físicos A/B;
- driver TMC2209;
- placa de expansão para o TMC2209;
- dissipador de calor para o driver;
- módulo regulador/conversor de tensão;
- módulo de relé para disparo da câmera;
- voltímetro;
- chave geral ON/OFF;
- bateria Li-ion 3S4P;
- conector P4 de alimentação/carga no módulo de controle;
- conector de 8 vias para interligação entre o módulo de controle e o trilho;
- conector P2 para disparo da câmera no trilho;
- conector P4 para alimentação auxiliar no trilho;
- dois fins de curso NC opcionais.

---

## 2. Controlador principal

O sistema utiliza um **Arduino Nano** como unidade principal de controle.

O Arduino é instalado sobre uma placa de expansão com terminais, utilizada para facilitar as conexões elétricas e permitir a montagem e manutenção do sistema sem a necessidade de soldar diretamente nos pinos do microcontrolador.

O controlador é responsável por:

- leitura do encoder;
- leitura dos botões A/B;
- leitura dos fins de curso;
- controle do driver do motor;
- controle do disparo da câmera;
- comunicação com o LCD;
- execução das rotinas de focus stacking;
- execução das rotinas de slider;
- controle do modo Bulb;
- armazenamento das configurações na EEPROM;
- monitoramento opcional da tensão da bateria.

---

## 3. Interface do usuário

A interface utiliza:

- display LCD 20×4;
- adaptador I²C;
- encoder rotativo KY-040;
- dois botões físicos identificados como **A** e **B**.

O LCD é conectado ao Arduino através do barramento I²C.

No Arduino Nano:

- A4 = SDA;
- A5 = SCL.

O encoder é utilizado para navegação, seleção e ajuste dos parâmetros do sistema.

Os botões A/B são utilizados para definição e acesso às posições A e B e, no modo MOVER, também permitem o deslocamento contínuo do carro quando mantidos pressionados.

---

## 4. Controle do motor

O motor de passo NEMA 17 é controlado através de um **driver TMC2209** instalado em uma placa de expansão.

O controle utiliza a interface convencional:

- STEP;
- DIR;
- ENABLE.

O driver deve utilizar dissipador de calor adequado.

A configuração elétrica do driver, incluindo corrente do motor e microstepping, deve ser compatível com o motor e com a calibração utilizada no firmware.

O sistema utiliza um fuso trapezoidal T8×2, com:

- diâmetro nominal: 8 mm;
- passo: 2 mm;
- avanço: 2 mm por revolução.

A calibração final do deslocamento é realizada no firmware através do parâmetro **Passos/mm**.

---

## 5. Fins de curso

O sistema possui entradas para dois fins de curso:

- fim de curso inicial;
- fim de curso final.

Os fins de curso são um **recurso adicional e opcional de segurança**. Eles não são utilizados para executar uma rotina automática de HOME e não são necessários para estabelecer a referência de posição do trilho.

Sua função é impedir que o motor continue movimentando o carro além dos limites mecânicos do sistema.

### 5.1 Tipo de chave

O firmware foi projetado para utilizar fins de curso **NC — normalmente fechados**.

Em condição normal de operação, cada entrada de fim de curso permanece conectada ao **GND** através do contato fechado da chave.

Quando o carro aciona o fim de curso, o contato é aberto. A entrada deixa de estar conectada ao GND e o firmware interpreta essa condição como limite físico acionado.

O movimento é então bloqueado apenas na direção correspondente ao fim de curso acionado. O movimento no sentido oposto permanece disponível, permitindo afastar o carro do limite.

### 5.2 Utilização sem fins de curso

> **IMPORTANTE — NÃO DEIXE AS ENTRADAS DOS FINS DE CURSO DESCONECTADAS.**
>
> Os fins de curso são opcionais, mas suas entradas elétricas precisam permanecer em um estado definido.
>
> Caso os fins de curso não sejam instalados, **cada entrada de fim de curso deve ser conectada diretamente ao GND através de um jumper**, simulando permanentemente o estado de uma chave NC fechada.
>
> Se as entradas forem deixadas desconectadas, o `INPUT_PULLUP` do Arduino mantém os pinos em nível HIGH. O firmware interpreta HIGH como fim de curso acionado e, consequentemente, o movimento do trilho poderá ser bloqueado.

Portanto, existem duas configurações válidas:

**Com fins de curso:**

```text
Entrada ENDSTOP ─── chave NC ─── GND
```

**Sem fins de curso:**

```text
Entrada ENDSTOP ─── jumper ─── GND
```

Esse procedimento deve ser realizado independentemente para as duas entradas de fim de curso.

---

## 6. Disparo da câmera

O disparo da câmera é realizado através de um módulo de relé.

O Arduino controla a entrada do módulo e o contato do relé realiza o fechamento elétrico necessário para acionar o obturador da câmera.

São utilizados os contatos:

- COM;
- NO (Normally Open).

O relé permanece aberto durante o funcionamento normal e fecha durante o comando de disparo.

O circuito de disparo é transportado pelas vias 5 e 6 do cabo de 8 vias entre o módulo de controle e o trilho.

Na caixa instalada no trilho, essas duas vias são conectadas a uma saída **P2**, utilizada exclusivamente para o disparo da câmera.

O cabo externo de disparo deve possuir:

- conector **P2** no lado do trilho;
- conector de disparo remoto específico para o modelo de câmera utilizado na outra extremidade.

Portanto, o P2 constitui o padrão de conexão de disparo no lado do Arandu, enquanto o conector da extremidade da câmera pode variar de acordo com o equipamento utilizado.

### 6.1 Configuração utilizada com a Canon EOS T5i

Na configuração documentada neste projeto, utilizada com uma **Canon EOS T5i**, o cabo possui:

```text
TRILHO                         CÂMERA

P2 ─────────── cabo ─────────── P1
```

Assim:

- **P2** = conector de disparo no lado do Arandu;
- **P1** = conector utilizado no lado da Canon EOS T5i.

Para utilizar outra câmera, a extremidade correspondente à câmera deve ser adaptada ao padrão de disparo remoto exigido pelo modelo.

O sistema pode executar tanto disparos convencionais quanto manter o contato fechado durante exposições no modo Bulb.

> **O conector P2 do trilho é destinado exclusivamente ao circuito de disparo e não deve receber alimentação elétrica.**

---

## 7. Alimentação

O sistema utiliza uma bateria **Li-ion 3S4P**.

Características gerais:

- tensão nominal aproximada: 11,1 V;
- tensão máxima de carga: 12,6 V.

O conjunto utilizado possui quatro condutores externos, organizados como:

- dois condutores de entrada;
- dois condutores de saída.

A entrada da bateria é utilizada para conexão ao conector **P4 localizado no módulo de controle**, destinado à alimentação/carga.

Na saída:

- o negativo é conectado ao GND comum do sistema;
- o positivo passa pela chave geral ON/OFF antes de alimentar a distribuição VCC do controlador.

O carregador utilizado deve ser apropriado para bateria Li-ion 3S, com tensão final de carga de **12,6 V**.

### 7.1 Identificação dos conectores de alimentação

O sistema possui dois conectores P4 com funções distintas:

- **P4 no módulo de controle:** entrada de alimentação/carga;
- **P4 no trilho:** saída de alimentação auxiliar.

A posição física dos conectores determina sua função.

O conector P2 existente no trilho é reservado ao disparo da câmera e não faz parte do circuito de alimentação.

---

## 8. Regulação de tensão

Um módulo regulador/conversor DC-DC é utilizado quando necessário para fornecer tensões adequadas aos diferentes componentes do sistema.

A bateria não deve ser conectada diretamente a dispositivos que exijam tensão diferente daquela fornecida pelo conjunto 3S.

A tensão de saída de qualquer conversor deve ser ajustada e verificada antes da conexão do equipamento correspondente.

---

## 9. Monitoramento da bateria

O protótipo atual utiliza um voltímetro para monitoramento direto da tensão da bateria.

O firmware também possui suporte para leitura da tensão através de uma entrada analógica do Arduino.

Para utilizar essa função, a tensão da bateria deve ser aplicada à entrada analógica **através de um divisor resistivo corretamente dimensionado**. A tensão da bateria 3S não deve ser conectada diretamente ao pino analógico do Arduino.

O dimensionamento e a calibração do divisor devem corresponder à configuração utilizada no firmware.

---

## 10. Cabo de interligação de 8 vias

O módulo de controle e o conjunto instalado no trilho são conectados através de um cabo de **8 vias**.

A distribuição funcional utilizada é:

| Vias | Função |
|---|---|
| 1–4 | Motor de passo |
| 5–6 | Disparo da câmera |
| 7–8 | Alimentação auxiliar |

Os quatro primeiros condutores transportam as conexões das duas bobinas do motor.

As vias 5 e 6 transportam o circuito de disparo da câmera até a saída P2 localizada no trilho.

As vias 7 e 8 transportam alimentação proveniente da bateria até a saída P4 localizada no trilho.

A polaridade específica das vias 7 e 8 deve seguir a montagem elétrica adotada no equipamento.

### 10.1 Organização funcional

```text
MÓDULO DE CONTROLE
│
├── P4
│   └── entrada de alimentação/carga
│
└── conector de 8 vias
         │
         │
         │ 1–4 → motor
         │ 5–6 → disparo
         │ 7–8 → alimentação auxiliar
         │
         ▼
TRILHO / CAIXA DO MOTOR
│
├── conector de 8 vias
│
├── P2
│   └── saída de disparo da câmera
│
└── P4
    └── saída de alimentação auxiliar
```

---

## 11. Alimentação auxiliar pelo cabo de 8 vias

As vias de alimentação auxiliar permitem transportar a alimentação da bateria até o conjunto instalado no trilho sem a necessidade de um segundo cabo externo.

No trilho, essas vias são conectadas a uma saída **P4**, disponibilizando alimentação próxima à câmera.

Essa saída pode ser utilizada para alimentar acessórios, desde que sejam respeitadas suas exigências elétricas.

Quando o equipamento conectado exigir tensão diferente da bateria, deve ser utilizado um conversor apropriado.

Um exemplo é a alimentação de uma câmera através de:

**bateria do sistema → vias 7–8 → P4 do trilho → conversor apropriado → alimentação da câmera**

No protótipo, essa arquitetura pode ser utilizada com um módulo de alimentação compatível e uma dummy battery adequada à câmera.

> A saída P4 do trilho disponibiliza alimentação proveniente do sistema. A tensão e a polaridade devem ser verificadas antes da conexão de qualquer equipamento.

---

## 12. Conectores externos e interligação

O módulo de controle e o trilho são interligados através de conectores removíveis de **8 vias**, do tipo utilizado na montagem do protótipo.

Eles permitem separar fisicamente:

- módulo de controle;
- cabo de interligação;
- conjunto do trilho.

A utilização de conectores removíveis facilita transporte, manutenção e substituição dos módulos.

Antes de conectar o cabo, deve-se verificar a correspondência da pinagem nos dois lados.

### 12.1 Conectores do módulo de controle

O módulo possui externamente:

| Conector | Função |
|---|---|
| 8 vias | Interligação com o trilho |
| P4 | Entrada de alimentação/carga |

### 12.2 Conectores do trilho

A caixa instalada no trilho possui:

| Conector | Função |
|---|---|
| 8 vias | Interligação com o módulo de controle |
| P2 | Saída de disparo da câmera |
| P4 | Saída de alimentação auxiliar |

### 12.3 Convenção adotada

Para reduzir a possibilidade de conexões incorretas, a versão documentada utiliza a seguinte convenção:

```text
8 VIAS = INTERLIGAÇÃO MÓDULO ↔ TRILHO

P2 = DISPARO DA CÂMERA

P4 = ALIMENTAÇÃO
```

O cabo externo entre o trilho e a câmera segue:

```text
P2 (Arandu) → conector específico da câmera
```

Na configuração com a Canon EOS T5i:

```text
P2 (Arandu) → P1 (Canon EOS T5i)
```

---

## 13. Aterramento comum

Os módulos eletrônicos do controlador que dependem de referência comum devem compartilhar o **GND** adequado.

Isso inclui especialmente:

- Arduino Nano;
- driver do motor;
- módulos de interface;
- reguladores;
- entradas dos fins de curso.

Conexões incorretas de GND podem causar comportamento imprevisível, falhas de leitura ou impossibilidade de movimentação.

---

## 14. Observações de montagem

Antes da primeira energização:

1. verificar a polaridade da alimentação;
2. verificar a tensão de saída dos conversores;
3. verificar a conexão do motor;
4. verificar as conexões STEP, DIR e ENABLE;
5. verificar a conexão do LCD e do encoder;
6. verificar o circuito de disparo da câmera;
7. verificar se o P2 do trilho está conectado exclusivamente ao circuito de disparo;
8. verificar a continuidade do cabo de 8 vias;
9. verificar a correspondência das vias nas duas extremidades do cabo;
10. verificar a polaridade da alimentação auxiliar nas vias 7 e 8;
11. verificar a tensão presente no P4 de alimentação auxiliar antes de conectar acessórios;
12. verificar se os fins de curso NC estão corretamente conectados;
13. caso os fins de curso não sejam utilizados, verificar se **as duas entradas estão conectadas ao GND por jumpers**;
14. verificar se não existem curtos entre alimentação e GND.

O conector IEC existente no gabinete atual é proveniente de uma configuração anterior do protótipo e **não faz parte do sistema elétrico atual**.

---

# English

## 1. Overview

The **Arandu Stack Macro Rail** electrical system integrates stepper motor control, the user interface, camera triggering, power distribution, and optional safety devices into a single control module.

The architecture uses commercially available electronic modules integrated into the system, making maintenance, replacement, and reproduction easier.

The main components are:

- Arduino Nano;
- Arduino Nano terminal expansion board;
- 20×4 LCD;
- I²C LCD adapter;
- KY-040 rotary encoder;
- two physical A/B buttons;
- TMC2209 driver;
- TMC2209 expansion board;
- driver heatsink;
- voltage regulator/DC-DC converter;
- camera trigger relay module;
- voltmeter;
- main ON/OFF switch;
- 3S4P Li-ion battery;
- P4 power/charging connector on the control module;
- 8-wire interconnection cable between the control module and rail;
- P2 camera shutter connector on the rail;
- P4 auxiliary power connector on the rail;
- two optional NC endstop switches.

---

## 2. Main controller

An **Arduino Nano** is used as the main controller.

The Arduino is installed on a terminal expansion board to simplify electrical connections and maintenance without requiring direct soldering to the microcontroller pins.

The controller handles:

- encoder input;
- A/B button input;
- endstop input;
- stepper driver control;
- camera triggering;
- LCD communication;
- focus stacking routines;
- slider routines;
- Bulb operation;
- EEPROM configuration storage;
- optional battery voltage monitoring.

---

## 3. User interface

The interface consists of:

- 20×4 LCD;
- I²C adapter;
- KY-040 rotary encoder;
- two physical buttons identified as **A** and **B**.

The LCD communicates with the Arduino through I²C.

On the Arduino Nano:

- A4 = SDA;
- A5 = SCL.

The encoder is used for menu navigation, selection, and parameter adjustment.

The A/B buttons are used to define and access positions A and B. In MOVER mode, holding either button also provides continuous carriage movement.

---

## 4. Motor control

The NEMA 17 stepper motor is controlled by a **TMC2209 driver** installed on an expansion board.

The control interface uses:

- STEP;
- DIR;
- ENABLE.

An appropriate heatsink should be installed on the driver.

Driver current and microstepping configuration must be compatible with the motor and with the firmware calibration.

The system uses a T8×2 trapezoidal lead screw:

- nominal diameter: 8 mm;
- pitch: 2 mm;
- lead: 2 mm per revolution.

Final movement calibration is performed through the firmware **Steps/mm** parameter.

---

## 5. Endstops

The system provides inputs for two endstop switches:

- initial endstop;
- final endstop.

The endstops are an **optional additional safety feature**. They are not used for an automatic HOME routine and are not required to establish the rail position reference.

Their purpose is to prevent the motor from driving the carriage beyond the mechanical travel limits.

### 5.1 Switch type

The firmware is designed for **NC — normally closed** endstop switches.

During normal operation, each endstop input remains connected to **GND** through the closed switch.

When the carriage activates an endstop, the contact opens. The input is no longer connected to GND and the firmware interprets this condition as an active physical limit.

Movement is blocked only in the direction of the activated endstop. Movement in the opposite direction remains available so the carriage can be moved away from the limit.

### 5.2 Operation without endstops

> **IMPORTANT — DO NOT LEAVE THE ENDSTOP INPUTS DISCONNECTED.**
>
> The endstop switches are optional, but their electrical inputs must remain in a defined state.
>
> If endstop switches are not installed, **each endstop input must be connected directly to GND with a jumper**, permanently simulating the closed state of an NC switch.
>
> If these inputs are left disconnected, the Arduino `INPUT_PULLUP` keeps them HIGH. The firmware interprets HIGH as an activated endstop and rail movement may consequently be blocked.

Therefore, there are two valid configurations:

**With endstops:**

```text
ENDSTOP input ─── NC switch ─── GND
```

**Without endstops:**

```text
ENDSTOP input ─── jumper ─── GND
```

This must be done independently for both endstop inputs.

---

## 6. Camera trigger

Camera triggering is performed through a relay module.

The Arduino controls the relay input, while the relay contact provides the electrical closure required to activate the camera shutter.

The following relay contacts are used:

- COM;
- NO (Normally Open).

The relay remains open during normal operation and closes during a shutter command.

The shutter circuit is carried through wires 5 and 6 of the 8-wire cable between the control module and the rail.

At the enclosure installed on the rail, these two wires are connected to a **P2 output**, used exclusively for camera triggering.

The external shutter cable must have:

- a **P2 connector** on the rail side;
- the appropriate remote shutter connector for the camera model on the other end.

P2 therefore serves as the standardized shutter connection on the Arandu side, while the connector at the camera end may vary depending on the equipment being used.

### 6.1 Configuration used with the Canon EOS T5i

In the configuration documented for this project using a **Canon EOS T5i**, the cable is:

```text
RAIL                           CAMERA

P2 ─────────── cable ───────── P1
```

Therefore:

- **P2** = shutter connector on the Arandu side;
- **P1** = connector used on the Canon EOS T5i side.

For another camera, the camera-side end must be adapted to the remote shutter connection required by that model.

The system supports both conventional shutter pulses and extended contact closure for Bulb exposures.

> **The P2 connector on the rail is exclusively intended for the shutter circuit and must not receive electrical power.**

---

## 7. Power supply

The system uses a **3S4P Li-ion battery pack**.

General characteristics:

- nominal voltage: approximately 11.1 V;
- maximum charging voltage: 12.6 V.

The battery assembly used in the prototype has four external conductors:

- two input conductors;
- two output conductors.

The battery input is connected to the **P4 connector located on the control module**, used for power/charging.

On the output side:

- negative is connected to the system common GND;
- positive passes through the main ON/OFF switch before reaching the controller VCC distribution.

The charger must be suitable for a 3S Li-ion battery pack with a final charging voltage of **12.6 V**.

### 7.1 Power connector identification

The system contains two P4 connectors with different functions:

- **P4 on the control module:** power/charging input;
- **P4 on the rail:** auxiliary power output.

Their physical location determines their function.

The P2 connector on the rail is reserved for camera triggering and is not part of the power circuit.

---

## 8. Voltage regulation

A DC-DC regulator/converter is used where necessary to provide suitable voltages to different system components.

The battery must not be connected directly to devices requiring a voltage different from that supplied by the 3S pack.

Converter output voltage must be adjusted and verified before connecting the corresponding equipment.

---

## 9. Battery monitoring

The current prototype uses a voltmeter for direct battery voltage monitoring.

The firmware also supports battery voltage measurement through an Arduino analog input.

To use this function, battery voltage must be connected to the analog input **through an appropriately dimensioned voltage divider**. The 3S battery voltage must not be connected directly to the Arduino analog input.

Divider design and calibration must correspond to the firmware configuration.

---

## 10. 8-wire interconnection cable

The control module and rail assembly are connected through an **8-wire cable**.

The functional allocation is:

| Wires | Function |
|---|---|
| 1–4 | Stepper motor |
| 5–6 | Camera trigger |
| 7–8 | Auxiliary power |

The first four conductors carry the two stepper motor coil connections.

Wires 5 and 6 carry the camera shutter circuit to the P2 output located on the rail.

Wires 7 and 8 carry battery-derived power to the P4 auxiliary output located on the rail.

The specific polarity of wires 7 and 8 must follow the wiring arrangement used in the equipment.

### 10.1 Functional organization

```text
CONTROL MODULE
│
├── P4
│   └── power/charging input
│
└── 8-wire connector
         │
         │
         │ 1–4 → motor
         │ 5–6 → shutter
         │ 7–8 → auxiliary power
         │
         ▼
RAIL / MOTOR ENCLOSURE
│
├── 8-wire connector
│
├── P2
│   └── camera shutter output
│
└── P4
    └── auxiliary power output
```

---

## 11. Auxiliary power through the 8-wire cable

The auxiliary power wires allow battery power to be carried to the rail assembly without requiring a second external cable.

At the rail, these wires are connected to a **P4 output**, making power available near the camera.

This output may be used to power accessories provided their electrical requirements are respected.

If the connected equipment requires a voltage different from the battery voltage, an appropriate converter must be used.

For example:

**system battery → wires 7–8 → rail P4 → appropriate converter → camera power**

In the prototype, this architecture can be used with a compatible power module and a suitable camera dummy battery.

> The rail P4 output provides power derived from the system. Voltage and polarity must be verified before connecting any equipment.

---

## 12. External connectors and interconnection

The control module and rail are interconnected through removable **8-wire connectors** of the type used in the prototype.

They allow physical separation between:

- control module;
- interconnection cable;
- rail assembly.

Removable connectors simplify transportation, maintenance, and module replacement.

Pin correspondence on both sides must be verified before connecting the cable.

### 12.1 Control module connectors

The control module externally provides:

| Connector | Function |
|---|---|
| 8-wire | Interconnection with the rail |
| P4 | Power/charging input |

### 12.2 Rail connectors

The enclosure installed on the rail provides:

| Connector | Function |
|---|---|
| 8-wire | Interconnection with the control module |
| P2 | Camera shutter output |
| P4 | Auxiliary power output |

### 12.3 Adopted convention

To reduce the possibility of incorrect connections, the documented version uses the following convention:

```text
8-WIRE = CONTROL MODULE ↔ RAIL INTERCONNECTION

P2 = CAMERA SHUTTER

P4 = POWER
```

The external cable between the rail and camera follows:

```text
P2 (Arandu) → camera-specific connector
```

For the Canon EOS T5i configuration:

```text
P2 (Arandu) → P1 (Canon EOS T5i)
```

---

## 13. Common ground

Electronic modules that require a shared electrical reference must use the appropriate common **GND**.

This is particularly important for:

- Arduino Nano;
- motor driver;
- interface modules;
- regulators;
- endstop inputs.

Incorrect GND connections may cause unpredictable behavior, incorrect input readings, or prevent rail movement.

---

## 14. Assembly checks

Before first power-up:

1. verify power polarity;
2. verify converter output voltages;
3. verify motor wiring;
4. verify STEP, DIR, and ENABLE connections;
5. verify LCD and encoder connections;
6. verify the camera trigger circuit;
7. verify that the rail P2 is connected exclusively to the shutter circuit;
8. verify continuity of the 8-wire cable;
9. verify wire correspondence at both ends of the cable;
10. verify auxiliary power polarity on wires 7 and 8;
11. verify the voltage present at the auxiliary P4 before connecting accessories;
12. verify that NC endstop switches are correctly connected;
13. if endstops are not used, verify that **both endstop inputs are jumpered to GND**;
14. verify that there are no shorts between power and GND.

The IEC connector present on the current enclosure belongs to an earlier prototype configuration and **is not part of the current electrical system**.

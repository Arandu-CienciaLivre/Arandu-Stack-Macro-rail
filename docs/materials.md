# Materiais / Materials

[Português](#português) | [English](#english)

---

# Português

## 1. Controle e eletrônica

| Componente | Quantidade | Observação |
|---|---:|---|
| Arduino Nano | 1 | Unidade principal de controle |
| Placa de expansão para Arduino Nano | 1 | Modelo com bornes de parafuso para facilitar as conexões |
| LCD 20×4 | 1 | Interface de usuário |
| Módulo I²C para LCD | 1 | Adaptador utilizado com o LCD 20×4 |
| Encoder rotativo KY-040 | 1 | Navegação e ajuste de parâmetros |
| Botão de painel | 2 | Comandos auxiliares |
| TMC2209 | 1 | Driver do motor de passo |
| Placa de extensão para TMC2209 | 1 | Facilita as conexões entre driver, motor, alimentação e sinais de controle |
| Dissipador para TMC2209 | 1 | Dissipação térmica do driver |
| Módulo relé de 1 canal | 1 | Utilizado para o disparo da câmera através dos contatos COM e NO |
| Módulo conversor/regulador DC-DC | 1 | Adequação da tensão para os elementos eletrônicos que necessitam de tensão inferior |
| Chave liga/desliga | 1 | Chave geral de alimentação do sistema |
| Jack P4 | 1 | Conectado diretamente à entrada da bateria |
| Voltímetro | 1 | Monitoramento independente da tensão da bateria no protótipo |

### Monitoramento opcional da bateria

O firmware também permite monitorar a tensão da bateria através da entrada analógica do Arduino Nano.

Para utilizar essa função, deve ser instalado um divisor resistivo dimensionado para a tensão máxima da bateria utilizada.

O divisor resistivo não é obrigatório na configuração apresentada neste projeto, pois o protótipo utiliza um voltímetro dedicado.

O firmware possui parâmetros para calibração da leitura de tensão.

---

## 2. Motor e sistema de movimento

| Componente | Quantidade | Observação |
|---|---:|---|
| Motor de passo NEMA 17 | 1 | Acionamento do movimento linear |
| Atuador linear C-Beam | 1 | Comprimento nominal de 250 mm; curso útil aproximado de 150 mm |
| Fuso trapezoidal T8×2 | 1 | Diâmetro de 8 mm, passo de 2 mm e avanço de 2 mm por revolução |
| Acoplador flexível | 1 | Acoplamento entre o eixo do motor e o fuso; fornecido com o conjunto C-Beam |
| Bucha de cobre | 1 | Aproximadamente 1 mm de espessura; utilizada para compensar a diferença de diâmetro entre o eixo do motor e o acoplador |

A transmissão mecânica utilizada é:

**NEMA 17 → bucha de cobre → acoplador flexível → fuso T8×2**

---

## 3. Estrutura e montagem

| Componente | Quantidade | Observação |
|---|---:|---|
| Gabinete do módulo de controle | 1 | Gabinete utilizado para alojar a eletrônica; modelo pode ser adaptado conforme disponibilidade |
| Caixa elétrica de alumínio 4×2" | 1 | Adaptada como suporte e alojamento para a conexão entre motor e C-Beam |
| Placa de liberação rápida Ulanzi U-KA2 | 1 | Interface de fixação da câmera ao carro do trilho |

O gabinete do módulo de controle utilizado no protótipo foi reaproveitado de outro equipamento. Elementos existentes no gabinete que não fazem parte do Arandu Stack Macro Rail, como a antiga entrada IEC, não são necessários para a construção do sistema.

---

## 4. Elementos de fixação

| Componente | Quantidade | Observação |
|---|---:|---|
| Parafuso M3 × 8 mm | 2 | Fixação do motor NEMA 17 à caixa de alumínio |
| Arruela para parafuso M3 | 2 | Aumenta a área de apoio sobre os furos com folga utilizados para ajuste da posição do motor |
| Parafuso fotográfico 1/4" × 12 mm | 1 | Fixação da placa de liberação rápida ao carro do trilho |
| Porca T para perfil de alumínio 2020, canal de 6 mm | Conforme necessário | Instalação de acessórios no perfil do trilho |
| Parafuso M5 compatível com porca T | Conforme necessário | Instalação de acessórios no perfil; comprimento depende do acessório |
| Parafusos e elementos de fixação do conjunto C-Beam | Conforme o conjunto | Elementos utilizados na montagem original do atuador |

Os furos utilizados pelos dois parafusos M3 × 8 mm possuem folga suficiente para permitir pequeno ajuste lateral da posição do motor durante o alinhamento entre eixo, acoplador e fuso.

---

## 5. Alimentação

| Componente | Quantidade | Observação |
|---|---:|---|
| Bateria Li-ion 3S4P | 1 | Alimentação principal do sistema; aproximadamente 11,1 V nominal e 12,6 V completamente carregada |
| Carregador para bateria Li-ion 3S | 1 | Tensão final de carga de 12,6 V |

A bateria utilizada possui conexões separadas de entrada e saída, totalizando quatro condutores:

- 2 vias de entrada;
- 2 vias de saída.

O jack P4 é conectado diretamente à entrada da bateria.

Na saída:

- `OUT−` segue diretamente para a distribuição GND;
- `OUT+` passa pela chave liga/desliga antes da distribuição positiva do sistema.

---

## 6. Cabos e conectores externos

| Componente | Quantidade | Observação |
|---|---:|---|
| Cabo de interligação de 8 vias | 1 | Interliga o módulo de controle ao conjunto instalado no trilho |
| Conector destacável de 8 pinos tipo Mike | 2 pares | Quatro conectores no total, utilizados nas extremidades da interligação destacável |
| Cabo de disparo da câmera | 1 | Conector P4 no lado do sistema e P1 no lado da câmera utilizada no protótipo |
| Fios elétricos internos | Conforme necessário | Interligações internas do sistema |
| Terminais e conectores elétricos | Conforme necessário | Bornes, terminais, conectores destacáveis e elementos auxiliares de montagem |

### Pinagem do cabo de 8 vias

| Pino | Função |
|---:|---|
| 1 | Motor de passo |
| 2 | Motor de passo |
| 3 | Motor de passo |
| 4 | Motor de passo |
| 5 | Disparo da câmera |
| 6 | Disparo da câmera |
| 7 | Alimentação |
| 8 | Alimentação |

Os pinos 7 e 8 fornecem um bypass da saída da bateria para a região do trilho. A tensão não é regulada especificamente para a câmera ou acessório conectado.

---

## 7. Acessórios e expansão

Os seguintes elementos podem ser utilizados conforme a aplicação e não são obrigatórios para o funcionamento básico do trilho:

| Componente | Quantidade | Observação |
|---|---:|---|
| Base/sapata Arca-Swiss | Opcional | Pode ser instalada no perfil para fixação do trilho ao tripé |
| Iluminação auxiliar | Opcional | Pode utilizar os pontos de montagem disponíveis no perfil |
| Braços ou suportes auxiliares | Opcional | Para iluminação, difusores ou outros acessórios |
| Sistema de alimentação externa da câmera | Opcional | Necessário quando se deseja alimentar a câmera através da bateria do trilho |

Para acessórios instalados diretamente no perfil, podem ser utilizadas porcas T para perfil 2020 com canal de 6 mm e parafusos M5 adequados ao acessório.

### Exemplo de alimentação da câmera

No protótipo com uma Canon EOS T5i é utilizado:

**bateria do trilho → conversor PD → dummy battery USB → câmera**

Esse conjunto é apenas um exemplo de implementação e deve ser adaptado de acordo com a tensão e o sistema de alimentação da câmera utilizada.

---

## 8. Observações

Os materiais apresentados correspondem à configuração do protótipo Arandu Stack Macro Rail v1.0.0.

O projeto utiliza módulos eletrônicos e componentes mecânicos comerciais integrados e adaptados para a aplicação.

Componentes equivalentes podem ser utilizados desde que sejam eletricamente e mecanicamente compatíveis com o sistema.

As especificações de componentes comerciais podem variar entre fabricantes. Sempre verifique pinagem, tensão, corrente e dimensões do componente utilizado antes da montagem.

---

# English

## 1. Control and electronics

| Component | Quantity | Notes |
|---|---:|---|
| Arduino Nano | 1 | Main control unit |
| Arduino Nano expansion board | 1 | Screw-terminal version used to simplify connections |
| 20×4 LCD | 1 | User interface |
| I²C LCD module | 1 | Adapter used with the 20×4 LCD |
| KY-040 rotary encoder | 1 | Menu navigation and parameter adjustment |
| Panel push button | 2 | Auxiliary controls |
| TMC2209 | 1 | Stepper motor driver |
| TMC2209 extension board | 1 | Simplifies connections between the driver, motor, power and control signals |
| TMC2209 heat sink | 1 | Driver heat dissipation |
| Single-channel relay module | 1 | Camera shutter triggering through COM and NO contacts |
| DC-DC converter/regulator module | 1 | Voltage adaptation for electronics requiring a lower supply voltage |
| ON/OFF switch | 1 | Main system power switch |
| P4 jack | 1 | Connected directly to the battery input |
| Voltmeter | 1 | Independent battery voltage monitoring in the prototype |

### Optional battery monitoring

The firmware also supports battery voltage monitoring through an Arduino Nano analog input.

To use this function, a resistive voltage divider properly dimensioned for the maximum battery voltage must be installed.

The voltage divider is not required in the configuration presented here because the prototype uses a dedicated voltmeter.

The firmware includes parameters for voltage-reading calibration.

---

## 2. Motor and motion system

| Component | Quantity | Notes |
|---|---:|---|
| NEMA 17 stepper motor | 1 | Linear motion drive |
| C-Beam linear actuator | 1 | 250 mm nominal length; approximately 150 mm usable travel |
| T8×2 trapezoidal lead screw | 1 | 8 mm diameter, 2 mm pitch and 2 mm lead per revolution |
| Flexible coupler | 1 | Connects the motor shaft to the lead screw; supplied with the C-Beam assembly |
| Copper bushing | 1 | Approximately 1 mm thick; compensates for the diameter difference between the motor shaft and coupler |

The mechanical transmission is:

**NEMA 17 → copper bushing → flexible coupler → T8×2 lead screw**

---

## 3. Structure and assembly

| Component | Quantity | Notes |
|---|---:|---|
| Control module enclosure | 1 | Houses the electronics; enclosure model may be adapted according to availability |
| 4×2" aluminum electrical box | 1 | Adapted as the motor-to-C-Beam support and coupling enclosure |
| Ulanzi U-KA2 quick-release plate | 1 | Camera mounting interface on the rail carriage |

The control enclosure used in the prototype was repurposed from another device. Existing enclosure features that are not part of the Arandu Stack Macro Rail, such as the unused IEC inlet, are not required for system construction.

---

## 4. Mounting hardware

| Component | Quantity | Notes |
|---|---:|---|
| M3 × 8 mm screw | 2 | Secures the NEMA 17 motor to the aluminum box |
| M3 washer | 2 | Increases the bearing area over the oversized adjustment holes |
| 1/4" × 12 mm photographic screw | 1 | Secures the quick-release plate to the rail carriage |
| T-nut for 2020 aluminum profile, 6 mm slot | As required | Installation of accessories on the rail profile |
| M5 screw compatible with T-nut | As required | Accessory installation; screw length depends on the accessory |
| C-Beam mounting hardware | As supplied | Hardware used in the original actuator assembly |

The holes used by the two M3 × 8 mm motor screws provide sufficient clearance for minor lateral adjustment during motor shaft, coupler and lead-screw alignment.

---

## 5. Power supply

| Component | Quantity | Notes |
|---|---:|---|
| 3S4P Li-ion battery pack | 1 | Main system power source; approximately 11.1 V nominal and 12.6 V fully charged |
| 3S Li-ion battery charger | 1 | 12.6 V final charging voltage |

The battery used in the prototype has separate input and output connections, with four conductors in total:

- 2 input wires;
- 2 output wires.

The P4 jack is connected directly to the battery input.

At the battery output:

- `OUT−` is connected directly to the GND distribution;
- `OUT+` passes through the main ON/OFF switch before reaching the positive power distribution.

---

## 6. External cables and connectors

| Component | Quantity | Notes |
|---|---:|---|
| 8-wire interconnection cable | 1 | Connects the control module to the rail assembly |
| Detachable 8-pin Mike-type connector | 2 pairs | Four connectors in total, used at the ends of the detachable interconnection |
| Camera shutter cable | 1 | P4 connector on the system side and P1 connector on the prototype camera side |
| Internal electrical wire | As required | Internal system wiring |
| Electrical terminals and connectors | As required | Screw terminals, detachable connectors and auxiliary assembly hardware |

### 8-wire cable pinout

| Pin | Function |
|---:|---|
| 1 | Stepper motor |
| 2 | Stepper motor |
| 3 | Stepper motor |
| 4 | Stepper motor |
| 5 | Camera shutter |
| 6 | Camera shutter |
| 7 | Power |
| 8 | Power |

Pins 7 and 8 provide a bypass from the battery output to the rail area. The voltage is not specifically regulated for the connected camera or accessory.

---

## 7. Accessories and expansion

The following items may be used depending on the application and are not required for basic rail operation:

| Component | Quantity | Notes |
|---|---:|---|
| Arca-Swiss base/plate | Optional | May be installed on the profile for tripod mounting |
| Auxiliary lighting | Optional | May use available mounting points on the rail profile |
| Auxiliary arms or supports | Optional | For lighting, diffusers or other accessories |
| External camera power system | Optional | Required when powering the camera from the rail battery |

Accessories mounted directly to the profile may use T-nuts for 2020 aluminum profile with a 6 mm slot and appropriate M5 screws.

### Camera power example

The Canon EOS T5i prototype uses:

**rail battery → PD converter → USB dummy battery → camera**

This is only an implementation example and must be adapted according to the voltage and power system required by the camera being used.

---

## 8. Notes

The materials listed here correspond to the Arandu Stack Macro Rail v1.0.0 prototype configuration.

The project integrates and adapts commercially available electronic modules and mechanical components for this application.

Equivalent components may be used provided they are electrically and mechanically compatible with the system.

Commercial component specifications may vary between manufacturers. Always verify pinout, voltage, current and physical dimensions before assembly.

# Materials — Arandu Stack Macro Rail v1.0.0

[Português](#português) | [English](#english)

Este documento apresenta os principais materiais e componentes utilizados na construção do **Arandu Stack Macro Rail v1.0.0**.

Alguns componentes utilizados são módulos comerciais prontos, enquanto outros foram adaptados ou integrados especificamente para esta implementação do sistema.

---

# Português

## 1. Controle e eletrônica

| Componente | Quantidade | Observações |
|---|---:|---|
| Arduino Nano | 1 | Microcontrolador principal do sistema |
| Placa de expansão para Arduino Nano | 1 | Placa com terminais de parafuso utilizada para facilitar as conexões |
| Display LCD 20×4 | 1 | Interface de visualização |
| Módulo I²C para LCD | 1 | Interface entre o LCD e o Arduino |
| Encoder rotativo KY-040 | 1 | Navegação pelos menus e ajuste de parâmetros |
| Botão de pressão | 2 | Comandos auxiliares do sistema |
| Driver TMC2209 | 1 | Controle do motor de passo |
| Placa de expansão para TMC2209 | 1 | Facilita a instalação e conexão do driver |
| Regulador de tensão | 1 | Alimentação dos circuitos eletrônicos |
| Módulo relé | 1 | Utilizado no acionamento das funções de disparo da câmera |
| Fios elétricos | Conforme necessário | Ligações internas do sistema |
| Terminais e conectores elétricos | Conforme necessário | Acabamento e interligação dos circuitos |

## 2. Motor e sistema de movimento

| Componente | Quantidade | Observações |
|---|---:|---|
| Motor de passo NEMA 17 | 1 | Responsável pelo acionamento do trilho |
| Atuador linear C-Beam | 1 | Comprimento nominal de 250 mm e aproximadamente 150 mm de curso útil |
| Fuso trapezoidal T8×2 | 1 | 8 mm de diâmetro, passo de 2 mm e avanço de 2 mm por revolução |
| Acoplador flexível | 1 | Fornecido com o conjunto C-Beam |
| Bucha de cobre | 1 | Aproximadamente 1 mm de espessura; utilizada para compatibilizar o eixo do motor com o acoplador |
| Carro móvel C-Beam | 1 | Parte móvel utilizada como base para instalação da câmera |

## 3. Estrutura e montagem

| Componente | Quantidade | Observações |
|---|---:|---|
| Caixa elétrica de alumínio 4×2" | 1 | Adaptada como suporte do motor e proteção do sistema de acoplamento |
| Caixa para o módulo de controle | 1 | Modelo definitivo ainda a ser definido |
| Placa de liberação rápida Ulanzi U-KA2 | 1 | Sistema de montagem e remoção rápida da câmera |

## 4. Elementos de fixação

| Componente | Quantidade | Aplicação |
|---|---:|---|
| Parafuso M3 × 8 mm | 2 | Fixação do motor NEMA 17 à caixa de alumínio |
| Arruela para parafuso M3 | 2 | Aumenta a área de apoio sobre os furos com folga utilizados para ajuste da posição do motor |
| Parafuso fotográfico 1/4" × 12 mm | 1 | Fixação da placa de liberação rápida ao carro do trilho |
| Porca T para perfil de alumínio 2020, canal de 6 mm | Conforme necessário | Instalação de acessórios no perfil do trilho |
| Parafuso M5 compatível com porca T | Conforme necessário | Instalação de acessórios no perfil do trilho |
| Parafusos e elementos de fixação do conjunto C-Beam | Conforme o conjunto | Incluem os elementos utilizados na montagem original do atuador |

As porcas T e os parafusos M5 são utilizados como pontos auxiliares de montagem e permitem instalar acessórios no perfil do trilho, como bases Arca-Swiss, suportes de iluminação e outros componentes.

O comprimento dos parafusos M5 depende do acessório instalado.

## 5. Alimentação

| Componente | Quantidade | Observações |
|---|---:|---|
| Pack de baterias Li-ion 3S4P | 1 | Tensão nominal aproximada de 11,1 V e 12,6 V totalmente carregado |
| Carregador para bateria Li-ion 3S | 1 | Tensão final de carga de 12,6 V |

## 6. Cabos e conectores externos

| Componente | Quantidade | Observações |
|---|---:|---|
| Cabo de interligação de 8 vias | 1 | Conecta o módulo de controle ao conjunto do trilho |
| Conectores de 8 pinos tipo Mike | 2 pares | Quatro conectores no total, permitindo a desconexão do cabo nas duas extremidades |
| Cabo de disparo da câmera | 1 | Construído especificamente para interligar a câmera ao módulo de controle |
| Conector P1 | 1 | Utilizado no lado da câmera no cabo de disparo |
| Conector P4 | 1 | Utilizado no lado do controlador no cabo de disparo |

## 7. Acessórios e possibilidades de expansão

O perfil do C-Beam permite a instalação de acessórios utilizando porcas T para perfil 2020 com canal de 6 mm e parafusos M5.

Entre os acessórios que podem ser instalados estão:

- base ou sapata Arca-Swiss para fixação do trilho em tripé;
- suportes de iluminação;
- braços auxiliares;
- outros acessórios compatíveis com o perfil.

Esses acessórios não são obrigatórios para o funcionamento básico do Macro Rail e podem variar conforme a aplicação.

## 8. Observações

Os componentes eletrônicos e mecânicos listados neste documento são componentes comerciais utilizados como base para a construção do sistema.

O **Arandu Stack Macro Rail** documenta a seleção, integração, adaptação e configuração desses componentes, juntamente com o firmware e as soluções desenvolvidas para sua utilização como sistema de posicionamento linear para macrofotografia, focus stacking e outras aplicações experimentais.

Componentes equivalentes podem ser utilizados desde que sejam eletricamente e mecanicamente compatíveis com o sistema.

---

# English

## 1. Control and Electronics

| Component | Quantity | Notes |
|---|---:|---|
| Arduino Nano | 1 | Main system microcontroller |
| Arduino Nano expansion board | 1 | Screw-terminal breakout board used to simplify connections |
| 20×4 LCD | 1 | User interface display |
| I²C LCD module | 1 | Interface between the LCD and Arduino |
| KY-040 rotary encoder | 1 | Menu navigation and parameter adjustment |
| Push button | 2 | Auxiliary system controls |
| TMC2209 driver | 1 | Stepper motor control |
| TMC2209 expansion board | 1 | Simplifies driver installation and connections |
| Voltage regulator | 1 | Provides regulated power for the electronic circuits |
| Relay module | 1 | Used for camera shutter control functions |
| Electrical wire | As required | Internal system wiring |
| Electrical terminals and connectors | As required | Circuit interconnection and finishing |

## 2. Motor and Motion System

| Component | Quantity | Notes |
|---|---:|---|
| NEMA 17 stepper motor | 1 | Drives the linear rail |
| C-Beam linear actuator | 1 | 250 mm nominal length and approximately 150 mm usable travel |
| T8×2 trapezoidal lead screw | 1 | 8 mm diameter, 2 mm pitch and 2 mm travel per revolution |
| Flexible coupler | 1 | Supplied with the C-Beam assembly |
| Copper bushing | 1 | Approximately 1 mm thick; used to match the motor shaft to the coupler |
| C-Beam moving carriage | 1 | Moving platform used for camera mounting |

## 3. Structure and Assembly

| Component | Quantity | Notes |
|---|---:|---|
| 4×2" aluminum electrical box | 1 | Adapted as the motor support and coupling enclosure |
| Control module enclosure | 1 | Final enclosure model still to be defined |
| Ulanzi U-KA2 quick-release plate | 1 | Quick camera mounting and removal system |

## 4. Mounting Hardware

| Component | Quantity | Application |
|---|---:|---|
| M3 × 8 mm screw | 2 | Mounting the NEMA 17 motor to the aluminum enclosure |
| M3 washer | 2 | Increases the bearing area over the enlarged motor adjustment holes |
| 1/4" × 12 mm photographic screw | 1 | Mounting the quick-release plate to the rail carriage |
| T-nut for 2020 aluminum profile, 6 mm slot | As required | Accessory mounting on the rail profile |
| M5 screw compatible with T-nut | As required | Accessory mounting on the rail profile |
| C-Beam mounting hardware | As supplied | Includes the original fasteners used in the actuator assembly |

The T-nuts and M5 screws provide auxiliary mounting points for accessories such as Arca-Swiss bases, lighting supports, and other components.

The required M5 screw length depends on the accessory being installed.

## 5. Power Supply

| Component | Quantity | Notes |
|---|---:|---|
| 3S4P Li-ion battery pack | 1 | Approximately 11.1 V nominal and 12.6 V when fully charged |
| 3S Li-ion battery charger | 1 | 12.6 V final charging voltage |

## 6. External Cables and Connectors

| Component | Quantity | Notes |
|---|---:|---|
| 8-wire interconnection cable | 1 | Connects the control module to the rail assembly |
| 8-pin Mike-type connectors | 2 pairs | Four connectors in total, allowing the cable to be disconnected at both ends |
| Camera trigger cable | 1 | Custom cable connecting the camera to the control module |
| P1 connector | 1 | Used on the camera side of the trigger cable |
| P4 connector | 1 | Used on the controller side of the trigger cable |

## 7. Accessories and Expansion

The C-Beam profile allows accessories to be installed using T-nuts for 2020 aluminum profiles with 6 mm slots and compatible M5 screws.

Possible accessories include:

- Arca-Swiss base or plate for mounting the rail on a tripod;
- lighting supports;
- auxiliary arms;
- other accessories compatible with the profile.

These accessories are not required for basic Macro Rail operation and may vary according to the intended application.

## 8. Notes

The electronic and mechanical components listed in this document are commercial components used as the basis for construction of the system.

The **Arandu Stack Macro Rail** documents the selection, integration, adaptation, and configuration of these components, together with the firmware and solutions developed for their use as a linear positioning system for macro photography, focus stacking, and other experimental applications.

Equivalent components may be used provided that they are electrically and mechanically compatible with the system.

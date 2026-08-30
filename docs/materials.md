# Bill of Materials — Arandu Stack Macro Rail v1.0.0

[Português](#português) | [English](#english)

Esta lista apresenta os principais componentes utilizados na construção da versão **1.0.0** do Arandu Stack Macro Rail.

Alguns componentes podem ser substituídos por modelos equivalentes, desde que sejam eletricamente e mecanicamente compatíveis com o sistema.

---

# Português

## 1. Controle e interface

| Quantidade | Componente                          | Especificação / função                                                   |
| ---------: | ----------------------------------- | ------------------------------------------------------------------------ |
|          1 | Arduino Nano                        | Microcontrolador principal do sistema                                    |
|          1 | Placa de expansão para Arduino Nano | Breakout com bornes para facilitar as conexões aos pinos do Arduino Nano |
|          1 | Display LCD 20×4                    | Interface visual do sistema                                              |
|          1 | Módulo I²C para LCD                 | Interface entre o Arduino e o display LCD 20×4                           |
|          1 | Encoder rotativo KY-040             | Navegação pelos menus e ajuste de parâmetros                             |
|          2 | Botões de pressão                   | Comandos dedicados da interface                                          |

## 2. Controle de movimento

| Quantidade | Componente                      | Especificação / função                      |
| ---------: | ------------------------------- | ------------------------------------------- |
|          1 | Motor de passo NEMA 17          | Responsável pelo movimento do trilho        |
|          1 | Driver TMC2209                  | Controle do motor de passo                  |
|          1 | Módulo de expansão para TMC2209 | Facilita as conexões elétricas com o driver |

## 3. Acionamento da câmera

| Quantidade | Componente                | Especificação / função                                                                                  |
| ---------: | ------------------------- | ------------------------------------------------------------------------------------------------------- |
|          1 | Módulo de relé            | Acionamento elétrico do disparo da câmera                                                               |
|          1 | Cabo de disparo da câmera | Cabo confeccionado para o projeto, utilizando conector P1 no lado da câmera e P4 no lado do controlador |

A pinagem do cabo de disparo deve seguir o esquema elétrico documentado para o projeto.

## 4. Alimentação

| Quantidade | Componente                        | Especificação / função                                                                                 |
| ---------: | --------------------------------- | ------------------------------------------------------------------------------------------------------ |
|          1 | Pack de baterias Li-ion 3S4P      | Fonte de alimentação principal do sistema; tensão nominal de aproximadamente 11,1 V e máxima de 12,6 V |
|          1 | Regulador de tensão               | Regulação da tensão utilizada pelos componentes eletrônicos                                            |
|          1 | Carregador para bateria Li-ion 3S | Carregador compatível com pack 3S, com tensão final de carga de 12,6 V                                 |

> O sistema de bateria deve possuir proteção adequada para as células utilizadas. A configuração e o carregamento do pack devem respeitar as especificações das células e do circuito de proteção empregado.

## 5. Estrutura mecânica

| Quantidade | Componente                             | Especificação / função                                                                          |
| ---------: | -------------------------------------- | ----------------------------------------------------------------------------------------------- |
|          1 | Trilho linear C-Beam                   | Estrutura linear com curso de aproximadamente 150 mm                                            |
|          1 | Fuso trapezoidal T8×2                  | Diâmetro de 8 mm e avanço de 2 mm por revolução                                                 |
|          1 | Caixa elétrica de alumínio 4×2"        | Adaptada como suporte e estrutura de acoplamento entre o motor NEMA 17 e o conjunto C-Beam/fuso |
|          1 | Placa de liberação rápida Ulanzi U-KA2 | Utilizada para fixação e remoção rápida da câmera no carro do trilho                            |

A Ulanzi U-KA2 pode ser substituída por outro sistema de fixação de câmera mecanicamente compatível.

## 6. Conexões

|          Quantidade | Componente                     | Especificação / função                                                                |
| ------------------: | ------------------------------ | ------------------------------------------------------------------------------------- |
|                   1 | Cabo de interligação de 8 vias | Interligação entre o módulo de controle e o conjunto do trilho                        |
|             2 pares | Conectores tipo Mike de 8 vias | Conexões destacáveis utilizadas na interligação entre o módulo de controle e o trilho |
| Conforme necessário | Cabos elétricos                | Alimentação e sinais entre os módulos internos                                        |
| Conforme necessário | Terminais para bornes          | Terminação dos cabos utilizados nas conexões por borne                                |

A pinagem dos conectores de 8 vias deve seguir o esquema de conexão específico do Arandu Stack Macro Rail e não deve ser considerada uma pinagem padrão para conectores desse tipo.

## 7. Gabinete

| Quantidade | Componente                    | Especificação / função                                                              |
| ---------: | ----------------------------- | ----------------------------------------------------------------------------------- |
|          1 | Caixa para módulo de controle | Gabinete para acomodar display, Arduino, controles e demais componentes eletrônicos |

O gabinete utilizado durante o desenvolvimento poderá ser substituído por outro modelo com dimensões adequadas aos componentes.

## Observações

Os componentes apresentados nesta lista correspondem à configuração utilizada no desenvolvimento do **Arandu Stack Macro Rail v1.0.0**.

Componentes comerciais pertencem aos seus respectivos fabricantes. Sua inclusão nesta lista indica apenas sua utilização e integração ao sistema.

Pequenas adaptações mecânicas ou elétricas podem ser necessárias dependendo dos modelos específicos de componentes utilizados.

---

# English

This list presents the main components used to build **Arandu Stack Macro Rail version 1.0.0**.

Some components may be replaced by equivalent models, provided that they are electrically and mechanically compatible with the system.

## 1. Control and User Interface

| Quantity | Component                    | Specification / function                                                           |
| -------: | ---------------------------- | ---------------------------------------------------------------------------------- |
|        1 | Arduino Nano                 | Main system microcontroller                                                        |
|        1 | Arduino Nano expansion board | Breakout board with screw terminals for easier connection to the Arduino Nano pins |
|        1 | 20×4 LCD display             | System visual interface                                                            |
|        1 | I²C LCD module               | Interface between the Arduino and the 20×4 LCD                                     |
|        1 | KY-040 rotary encoder        | Menu navigation and parameter adjustment                                           |
|        2 | Push buttons                 | Dedicated interface controls                                                       |

## 2. Motion Control

| Quantity | Component                | Specification / function                         |
| -------: | ------------------------ | ------------------------------------------------ |
|        1 | NEMA 17 stepper motor    | Provides rail movement                           |
|        1 | TMC2209 driver           | Stepper motor driver                             |
|        1 | TMC2209 expansion module | Facilitates electrical connections to the driver |

## 3. Camera Trigger

| Quantity | Component            | Specification / function                                                                       |
| -------: | -------------------- | ---------------------------------------------------------------------------------------------- |
|        1 | Relay module         | Electrical camera shutter triggering                                                           |
|        1 | Camera trigger cable | Custom cable using a P1 connector on the camera side and a P4 connector on the controller side |

The camera trigger cable pinout must follow the electrical wiring documentation provided for the project.

## 4. Power Supply

| Quantity | Component                 | Specification / function                                                           |
| -------: | ------------------------- | ---------------------------------------------------------------------------------- |
|        1 | 3S4P Li-ion battery pack  | Main system power source; approximately 11.1 V nominal and 12.6 V fully charged    |
|        1 | Voltage regulator         | Regulates the voltage supplied to the electronic components                        |
|        1 | 3S Li-ion battery charger | Charger compatible with a 3S battery pack, with a final charging voltage of 12.6 V |

> The battery system must include appropriate protection for the cells used. Pack configuration and charging must comply with the specifications of the cells and protection circuit.

## 5. Mechanical Structure

| Quantity | Component                        | Specification / function                                                                                 |
| -------: | -------------------------------- | -------------------------------------------------------------------------------------------------------- |
|        1 | C-Beam linear rail               | Linear structure with approximately 150 mm of travel                                                     |
|        1 | T8×2 lead screw                  | 8 mm diameter with 2 mm of linear travel per revolution                                                  |
|        1 | 4×2" aluminum electrical box     | Adapted as a support and coupling structure between the NEMA 17 motor and the C-Beam/lead screw assembly |
|        1 | Ulanzi U-KA2 quick-release plate | Used for quick camera attachment and removal from the rail carriage                                      |

The Ulanzi U-KA2 may be replaced by another mechanically compatible camera mounting system.

## 6. Connections

|    Quantity | Component                    | Specification / function                                                          |
| ----------: | ---------------------------- | --------------------------------------------------------------------------------- |
|           1 | 8-wire interconnection cable | Connects the control module to the rail assembly                                  |
|     2 pairs | 8-pin Mike-type connectors   | Detachable connectors used for the connection between the control module and rail |
| As required | Electrical wires             | Power and signal connections between internal modules                             |
| As required | Terminal connectors          | Wire termination for screw-terminal connections                                   |

The 8-pin connector pinout must follow the specific Arandu Stack Macro Rail wiring diagram and should not be considered a standard pinout for this connector type.

## 7. Enclosure

| Quantity | Component                | Specification / function                                                      |
| -------: | ------------------------ | ----------------------------------------------------------------------------- |
|        1 | Control module enclosure | Enclosure for the display, Arduino, controls, and other electronic components |

The enclosure used during development may be replaced by another model with dimensions suitable for the components.

## Notes

The components listed in this document correspond to the configuration used in the development of **Arandu Stack Macro Rail v1.0.0**.

Commercial components remain the property of their respective manufacturers. Their inclusion in this list only indicates their use and integration into the system.

Minor mechanical or electrical adaptations may be required depending on the specific component models used.

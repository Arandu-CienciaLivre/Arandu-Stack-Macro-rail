# Mechanical Assembly — Arandu Stack Macro Rail v1.0.0

[Português](#português) | [English](#english)

Este documento descreve a montagem mecânica do **Arandu Stack Macro Rail v1.0.0**.

O sistema utiliza como base um atuador linear C-Beam comercial, modificado e integrado aos demais componentes necessários para sua utilização como trilho motorizado para macrofotografia e focus stacking.

---

# Português

## 1. Visão geral

A estrutura mecânica do **Arandu Stack Macro Rail** é baseada em um conjunto de atuador linear **C-Beam de 250 mm**, equipado com fuso trapezoidal **T8×2**.

O conjunto possui aproximadamente **150 mm de curso útil**.

O movimento é produzido por um motor de passo **NEMA 17** acoplado ao fuso. A câmera é instalada sobre o carro móvel do trilho através de um sistema de liberação rápida.

A montagem utilizada no projeto também inclui uma adaptação construída a partir de uma **caixa elétrica de alumínio 4×2"**, utilizada para a integração mecânica entre o motor e o conjunto do trilho.

![Visão geral do conjunto montado](images/rail-assembly-overview.jpg)

*Visão geral do Arandu Stack Macro Rail montado.*

## 2. Principais componentes mecânicos

Os principais componentes utilizados nesta montagem são:

- atuador linear C-Beam de 250 mm;
- fuso trapezoidal T8×2;
- carro móvel do conjunto C-Beam;
- motor de passo NEMA 17;
- acoplador flexível fornecido com o conjunto C-Beam;
- bucha de cobre de aproximadamente 1 mm de espessura;
- caixa elétrica de alumínio 4×2";
- placa de liberação rápida Ulanzi U-KA2;
- 2 parafusos M3 × 8 mm;
- 2 arruelas para os parafusos M3;
- 1 parafuso fotográfico 1/4" × 12 mm;
- porcas T para perfil 2020 com canal de 6 mm e parafusos M5, conforme necessário para instalação de acessórios.

A lista geral de componentes do projeto está disponível em [`../materials.md`](../materials.md).

## 3. Conjunto C-Beam

O atuador C-Beam constitui a estrutura principal do trilho.

A versão utilizada possui comprimento nominal de **250 mm** e aproximadamente **150 mm de deslocamento útil**.

O sistema de transmissão utiliza um fuso trapezoidal **T8×2**, com:

- diâmetro nominal de 8 mm;
- passo de 2 mm;
- avanço de 2 mm por revolução.

O carro móvel se desloca longitudinalmente sobre o perfil C-Beam e constitui a superfície sobre a qual é instalado o sistema de fixação da câmera.

O conjunto C-Beam utilizado é um componente comercial. O projeto Arandu Stack Macro Rail utiliza sua estrutura e mecanismo de deslocamento como base para a implementação do sistema motorizado.

## 4. Montagem e acoplamento do motor

O movimento do trilho é realizado por um motor de passo **NEMA 17**.

Para integrar o motor ao conjunto C-Beam foi utilizada uma **caixa elétrica de alumínio 4×2"**, modificada para funcionar como estrutura de suporte do motor e proteção do sistema de acoplamento.

![Conjunto do motor e caixa de acoplamento](images/motor-enclosure-side.jpg)

*Motor NEMA 17 instalado sobre a caixa de alumínio 4×2" utilizada na adaptação mecânica.*

### 4.1 Fixação da caixa ao trilho

A caixa de alumínio foi posicionada sobre a extremidade do C-Beam e centralizada em relação ao eixo do fuso.

Com a caixa posicionada, os pontos correspondentes aos furos de fixação existentes na extremidade do trilho foram marcados diretamente sobre a caixa.

Após a furação, a caixa foi fixada ao conjunto utilizando os **próprios parafusos de fixação do trilho**.

Esse método utiliza a própria geometria do conjunto C-Beam como referência para o posicionamento da caixa, dispensando um gabarito específico de furação.

![Fixação do conjunto do motor ao trilho](images/motor-mount-front.jpg)

*Detalhe da montagem da caixa de alumínio na extremidade do conjunto C-Beam.*

### 4.2 Fixação e centralização do motor

O NEMA 17 foi posicionado sobre a caixa de alumínio aproveitando uma das **aberturas laterais já existentes na caixa elétrica** para a passagem do eixo do motor.

Essa abertura é uma característica original da caixa e, nesta adaptação, permite que o eixo do motor alcance o interior da caixa, onde é realizado o acoplamento com o fuso.

O motor foi fixado à caixa utilizando **dois parafusos M3 × 8 mm**.

Os furos destinados a esses parafusos foram feitos com diâmetro maior que o estritamente necessário, criando uma pequena folga ao redor dos parafusos.

Essa folga permite pequenos deslocamentos do motor durante a montagem. Dessa forma, sua posição pode ser ajustada até obter o melhor alinhamento possível entre o eixo do motor, o acoplador e o fuso T8×2.

Foram utilizadas **arruelas nos dois parafusos M3** para aumentar a área de apoio sobre os furos com folga. As arruelas permitem que os parafusos sejam apertados adequadamente depois que o motor é colocado na posição desejada, mantendo o ajuste realizado.

Antes do aperto definitivo, o motor deve ser reposicionado conforme necessário até que seu eixo esteja adequadamente alinhado ao conjunto de transmissão.

![Ajuste de alinhamento do motor](images/motor-shaft-alignment.jpg)

*Detalhe da fixação do NEMA 17. A abertura já existente na caixa é utilizada para a passagem do eixo, enquanto a folga nos furos dos dois parafusos M3 permite ajustar a posição do motor.*

### 4.3 Adaptação do acoplamento

O acoplador flexível fornecido com o conjunto C-Beam foi mantido para transmitir o movimento do motor ao fuso T8×2.

O diâmetro do eixo do motor utilizado não era diretamente compatível com o diâmetro interno do acoplador.

Para compensar essa diferença foi utilizada uma **bucha de cobre de aproximadamente 1 mm de espessura**, instalada entre o eixo do motor e o acoplador.

A sequência de transmissão utilizada no sistema é:

**NEMA 17 → bucha de cobre → acoplador flexível → fuso T8×2**

![Visão interna do acoplamento](images/coupler-internal-view-01.jpg)

*Visão interna da caixa mostrando o sistema de acoplamento entre o motor e o fuso.*

![Detalhe do acoplador](images/coupler-internal-view-02.jpg)

*Detalhe do acoplador flexível instalado entre o eixo do motor e o fuso T8×2.*

![Conjunto de acoplamento e conexões](images/coupler-and-wiring.jpg)

*Vista interna do conjunto mostrando o acoplamento e parte das conexões elétricas.*

A bucha permite o encaixe adequado do eixo no acoplador e a transmissão do movimento do motor para o fuso.

A necessidade e as dimensões dessa adaptação podem variar caso sejam utilizados motores ou acopladores com dimensões diferentes.

### 4.4 Alinhamento do conjunto

O alinhamento entre o eixo do motor, o acoplador e o fuso é importante para o funcionamento adequado do trilho.

O desalinhamento pode introduzir esforço lateral, vibração, aumento da resistência mecânica e irregularidades durante o deslocamento.

Para realizar o alinhamento, os dois parafusos M3 × 8 mm devem permanecer parcialmente soltos.

A folga existente nos furos de fixação permite pequenos deslocamentos do motor. Sua posição pode então ser ajustada até que o eixo esteja adequadamente alinhado ao acoplador e ao fuso.

Após encontrar a posição adequada, os dois parafusos podem ser apertados. As arruelas aumentam a área de apoio sobre os furos com folga e permitem manter o motor firmemente preso na posição definida.

Após a centralização e verificação do alinhamento, também deve ser verificado o aperto do acoplador.

![Visão geral do acoplamento do motor](images/motor-coupling-overview.jpg)

*Visão geral do conjunto motor, caixa de adaptação e C-Beam após a montagem.*

### 4.5 Conectores do conjunto

A caixa de adaptação também serve como ponto de instalação dos conectores utilizados para a interligação elétrica entre o conjunto do trilho e o módulo de controle.

![Conectores instalados na caixa](images/enclosure-connectors.jpg)

*Conectores instalados na caixa de adaptação para interligação entre o trilho e o módulo de controle.*

A função e a pinagem desses conectores são descritas separadamente na documentação elétrica do projeto.

## 5. Fixação da câmera

A câmera é instalada sobre o carro móvel do C-Beam utilizando uma placa de liberação rápida **Ulanzi U-KA2**.

![Sistema de liberação rápida da câmera](images/camera-quick-release.jpg)

*Placa de liberação rápida Ulanzi U-KA2 instalada sobre o carro móvel do trilho.*

A base do sistema de liberação rápida é fixada diretamente sobre a placa do carro utilizando **um parafuso fotográfico de 1/4" × 12 mm**.

O sistema permite instalar e remover a câmera sem desmontar os demais componentes do Macro Rail.

Outros sistemas de fixação podem ser utilizados desde que sejam mecanicamente compatíveis com o carro do trilho e proporcionem fixação adequada e estável para a câmera utilizada.

### 5.1 Fixação de acessórios ao trilho

O perfil do conjunto também pode ser utilizado como ponto de montagem para acessórios.

Para isso são utilizadas **porcas T compatíveis com perfil de alumínio 2020 e canal de 6 mm**, associadas a parafusos **M5**.

Esses elementos de fixação são independentes do mecanismo de movimentação e podem ser utilizados conforme a configuração necessária.

Entre as aplicações possíveis estão:

- instalação de uma base ou sapata Arca-Swiss para fixação do trilho em um tripé;
- instalação de suportes de iluminação;
- instalação de braços ou suportes auxiliares;
- fixação de outros acessórios compatíveis.

A quantidade de porcas T e o comprimento dos parafusos M5 dependem do acessório instalado.

## 6. Verificação mecânica

Antes de conectar e operar o sistema eletrônico, deve-se verificar manualmente a montagem mecânica.

Verifique:

- fixação da caixa de alumínio ao C-Beam;
- fixação dos dois parafusos M3 × 8 mm do motor;
- posicionamento adequado das arruelas;
- alinhamento entre o eixo do motor, o acoplador e o fuso;
- posicionamento da bucha de cobre;
- fixação do acoplador;
- ausência de deformação lateral excessiva do acoplador;
- rotação livre do fuso;
- movimentação livre do carro;
- ausência de pontos de travamento ao longo do curso;
- fixação da placa de liberação rápida;
- aperto do parafuso fotográfico de 1/4";
- estabilidade da câmera sobre o carro;
- aperto dos demais elementos de fixação.

Caso seja percebido aumento de resistência ou irregularidade durante o movimento, o alinhamento do motor deve ser verificado novamente.

Pequenos ajustes podem ser realizados afrouxando parcialmente os dois parafusos M3, reposicionando o motor utilizando a folga disponível nos furos de montagem e realizando novamente o aperto após o alinhamento.

## 7. Adaptações do projeto

O atuador C-Beam, o motor de passo, o acoplador, o sistema de liberação rápida e os demais componentes comerciais utilizados não foram desenvolvidos especificamente para o Arandu Stack Macro Rail.

O projeto utiliza esses componentes como base para a construção do sistema.

A integração mecânica realizada para esta versão inclui, entre outras adaptações:

- utilização da caixa elétrica de alumínio 4×2" como suporte do motor e proteção do acoplamento;
- adaptação da caixa aos pontos de fixação existentes no C-Beam;
- aproveitamento de uma abertura lateral já existente na caixa para a passagem do eixo do motor;
- utilização de dois parafusos M3 × 8 mm para fixação do motor;
- utilização de furos com folga para permitir pequenos ajustes de posicionamento e alinhamento;
- utilização de arruelas para aumentar a área de apoio dos parafusos sobre os furos com folga;
- utilização de uma bucha de cobre para compatibilizar o eixo do motor com o acoplador;
- integração da placa de liberação rápida ao carro do trilho através de parafuso fotográfico de 1/4";
- utilização dos canais do perfil para instalação opcional de acessórios através de porcas T e parafusos M5.

Essas adaptações, juntamente com a configuração do conjunto e sua integração ao firmware e sistema eletrônico do **Arandu Stack Macro Rail**, são documentadas neste repositório para facilitar a reprodução, estudo e modificação do equipamento.

---

# English

## 1. Overview

The mechanical structure of the **Arandu Stack Macro Rail** is based on a commercial **250 mm C-Beam linear actuator** equipped with a **T8×2 lead screw**.

The assembly provides approximately **150 mm of usable travel**.

Movement is provided by a **NEMA 17 stepper motor** coupled to the lead screw. The camera is mounted on the moving carriage using a quick-release system.

The project also uses an adapted **4×2" aluminum electrical box** as part of the mechanical integration between the motor and the linear rail assembly.

![Overview of the assembled system](images/rail-assembly-overview.jpg)

*Overview of the assembled Arandu Stack Macro Rail.*

## 2. Main Mechanical Components

The main mechanical components used in this assembly are:

- 250 mm C-Beam linear actuator;
- T8×2 lead screw;
- C-Beam moving carriage;
- NEMA 17 stepper motor;
- flexible coupler supplied with the C-Beam assembly;
- approximately 1 mm thick copper bushing;
- 4×2" aluminum electrical box;
- Ulanzi U-KA2 quick-release plate;
- 2 M3 × 8 mm screws;
- 2 washers for the M3 screws;
- 1 photographic 1/4" × 12 mm screw;
- T-nuts for 2020 aluminum profile with 6 mm slot and M5 screws, as required for accessory mounting.

The complete project component list is available in [`../materials.md`](../materials.md).

## 3. C-Beam Assembly

The C-Beam actuator forms the main structure of the rail.

The version used has a nominal length of **250 mm** and approximately **150 mm of usable travel**.

The transmission system uses a **T8×2 trapezoidal lead screw** with:

- 8 mm nominal diameter;
- 2 mm pitch;
- 2 mm linear travel per revolution.

The moving carriage travels longitudinally along the C-Beam profile and provides the mounting surface for the camera attachment system.

The C-Beam assembly used in this project is a commercial component. The Arandu Stack Macro Rail uses its structure and linear motion mechanism as the basis for the motorized system.

## 4. Motor Mounting and Coupling

Rail movement is provided by a **NEMA 17 stepper motor**.

A modified **4×2" aluminum electrical box** is used to mechanically integrate the motor with the C-Beam assembly and protect the coupling system.

![Motor and coupling enclosure assembly](images/motor-enclosure-side.jpg)

*NEMA 17 motor installed on the 4×2" aluminum enclosure used for the mechanical adaptation.*

### 4.1 Attaching the Enclosure to the Rail

The aluminum enclosure was positioned at the end of the C-Beam and centered relative to the lead screw axis.

With the enclosure positioned, the existing mounting holes at the end of the rail were used as references to mark the corresponding drilling locations on the enclosure.

After drilling, the enclosure was attached to the assembly using the **rail's original mounting screws**.

This method uses the C-Beam assembly itself as a positioning reference and does not require a separate drilling template.

![Rail and motor enclosure mounting](images/motor-mount-front.jpg)

*Detail of the aluminum enclosure mounted at the end of the C-Beam assembly.*

### 4.2 Motor Mounting and Alignment

The NEMA 17 was positioned on the aluminum enclosure using one of the **existing side openings of the electrical box** for the passage of the motor shaft.

This opening is an original feature of the electrical enclosure and allows the motor shaft to enter the enclosure, where it connects to the lead screw through the coupling system.

The motor is attached to the enclosure using **two M3 × 8 mm screws**.

The mounting holes for these screws were drilled slightly larger than strictly required, creating a small amount of clearance around the screws.

This clearance allows small positional adjustments of the motor during assembly, making it possible to align the motor shaft with the coupler and the T8×2 lead screw.

**Washers are used with both M3 screws** to increase the bearing area over the enlarged mounting holes. Once the desired motor position has been established, the screws can therefore be tightened while maintaining the selected alignment.

Before final tightening, the motor should be repositioned as required until its shaft is properly aligned with the transmission assembly.

![Motor alignment adjustment](images/motor-shaft-alignment.jpg)

*Detail of the NEMA 17 mounting. The existing opening in the enclosure is used for shaft passage, while clearance in the two M3 mounting holes allows the motor position to be adjusted.*

### 4.3 Coupling Adaptation

The flexible coupler supplied with the C-Beam assembly was retained to transmit motor rotation to the T8×2 lead screw.

The shaft diameter of the motor used in this build was not directly compatible with the internal diameter of the coupler.

To compensate for this difference, an approximately **1 mm thick copper bushing** was installed between the motor shaft and the coupler.

The resulting transmission arrangement is:

**NEMA 17 → copper bushing → flexible coupler → T8×2 lead screw**

![Internal view of the coupling](images/coupler-internal-view-01.jpg)

*Internal view of the enclosure showing the coupling system between the motor and lead screw.*

![Flexible coupler detail](images/coupler-internal-view-02.jpg)

*Detail of the flexible coupler installed between the motor shaft and the T8×2 lead screw.*

![Coupling and wiring assembly](images/coupler-and-wiring.jpg)

*Internal view showing the coupling assembly and part of the electrical connections.*

The bushing provides the required fit between the motor shaft and the coupler, allowing the motor to transmit motion to the lead screw.

The need for this adaptation and its dimensions may vary if motors or couplers with different dimensions are used.

### 4.4 Assembly Alignment

Alignment between the motor shaft, coupler, and lead screw is important for proper rail operation.

Misalignment may introduce lateral loads, vibration, increased mechanical resistance, and irregular movement.

For alignment, the two M3 × 8 mm mounting screws should remain partially loose.

The clearance in the mounting holes allows small positional adjustments of the motor. Its position can then be adjusted until the shaft is properly aligned with the coupler and lead screw.

Once the correct position has been established, the two screws can be tightened. The washers increase the bearing area over the enlarged holes and allow the motor to remain securely fixed in the selected position.

After alignment and tightening of the motor, the coupler attachment should also be checked.

![Motor coupling overview](images/motor-coupling-overview.jpg)

*Overview of the motor, adaptation enclosure, and C-Beam assembly after installation.*

### 4.5 Assembly Connectors

The adaptation enclosure also provides mounting points for the connectors used to electrically connect the rail assembly to the control module.

![Connectors installed on the enclosure](images/enclosure-connectors.jpg)

*Connectors installed on the adaptation enclosure for connection between the rail and control module.*

The function and pinout of these connectors are described separately in the project's electrical documentation.

## 5. Camera Mounting

The camera is attached to the C-Beam moving carriage using an **Ulanzi U-KA2 quick-release plate**.

![Camera quick-release system](images/camera-quick-release.jpg)

*Ulanzi U-KA2 quick-release plate installed on the moving rail carriage.*

The quick-release base is attached directly to the carriage plate using a **1/4" × 12 mm photographic screw**.

The system allows the camera to be installed and removed without disassembling the other Macro Rail components.

Other camera mounting systems may be used provided that they are mechanically compatible with the rail carriage and provide adequate and stable support for the camera being used.

### 5.1 Accessory Mounting

The rail profile can also be used as a mounting point for accessories.

For this purpose, **T-nuts compatible with 2020 aluminum profiles with 6 mm slots** are used together with **M5 screws**.

These mounting points are independent of the rail movement mechanism and can be used according to the required configuration.

Possible applications include:

- installation of an Arca-Swiss base or plate for mounting the rail on a tripod;
- lighting supports;
- auxiliary arms or brackets;
- other compatible accessories.

The number of T-nuts and the required M5 screw length depend on the accessory being installed.

## 6. Mechanical Inspection

Before connecting and operating the electronic system, the mechanical assembly should be manually inspected.

Check:

- attachment of the aluminum enclosure to the C-Beam;
- tightening of the two M3 × 8 mm motor screws;
- correct positioning of the washers;
- alignment between the motor shaft, coupler, and lead screw;
- copper bushing positioning;
- coupler attachment;
- absence of excessive lateral deformation of the coupler;
- free rotation of the lead screw;
- free movement of the carriage;
- absence of mechanical binding throughout the travel;
- quick-release plate mounting;
- tightening of the 1/4" photographic screw;
- camera stability on the carriage;
- tightness of the remaining mounting hardware.

If increased resistance or irregular movement is detected, the motor alignment should be checked again.

Small adjustments can be made by partially loosening the two M3 screws, repositioning the motor using the clearance available in the mounting holes, and tightening the screws again after alignment.

## 7. Project Adaptations

The C-Beam actuator, stepper motor, coupler, quick-release system, and other commercial components used in the system were not specifically developed for the Arandu Stack Macro Rail.

The project uses these components as the mechanical basis for the system.

Mechanical integration implemented in this version includes, among other adaptations:

- use of a 4×2" aluminum electrical box as the motor support and coupling enclosure;
- adaptation of the enclosure to the existing C-Beam mounting points;
- use of an existing side opening in the electrical enclosure for motor shaft passage;
- use of two M3 × 8 mm screws for motor mounting;
- use of enlarged mounting holes to allow small motor positioning and alignment adjustments;
- use of washers to increase the screw bearing area over the enlarged mounting holes;
- use of a copper bushing to match the motor shaft to the coupler;
- integration of the quick-release plate with the rail carriage using a 1/4" photographic screw;
- optional use of the profile slots for accessory mounting using T-nuts and M5 screws.

These adaptations, together with the overall system configuration and its integration with the **Arandu Stack Macro Rail** firmware and electronic system, are documented in this repository to facilitate reproduction, study, and modification of the equipment.

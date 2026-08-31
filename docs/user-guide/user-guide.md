# Arandu Stack Macro Rail — Manual do Usuário

[Português](user-guide.md) | [English](user-guide_EN.md)

Manual de operação do **Arandu Stack Macro Rail v1.0.0**.

---

## Sumário

1. [Introdução](#1-introdução)
2. [Controles](#2-controles)
3. [Inicialização e menu principal](#3-inicialização-e-menu-principal)
4. [Navegação geral](#4-navegação-geral)
5. [STACK](#5-stack)
   - [5.1 MOVER](#51-mover)
   - [5.2 SEQUÊNCIA](#52-sequência)
   - [5.3 MOVIMENTO](#53-movimento)
   - [5.4 TEMPOS](#54-tempos)
   - [5.5 FOTOGRAFAR](#55-fotografar)
   - [5.6 Execução e cancelamento](#56-execução-e-cancelamento)
6. [BULB](#6-bulb)
7. [SLIDER](#7-slider)
   - [7.1 MOVER](#71-mover)
   - [7.2 VIDEO](#72-video)
   - [7.3 LOOP](#73-loop)
   - [7.4 CONFIG SLIDER](#74-config-slider)
8. [CONFIG](#8-config)
9. [Fins de curso e segurança](#9-fins-de-curso-e-segurança)
10. [Configurações salvas](#10-configurações-salvas)
11. [Valores padrão](#11-valores-padrão)
12. [Fluxos rápidos de utilização](#12-fluxos-rápidos-de-utilização)

---

## 1. Introdução

O **Arandu Stack Macro Rail** é um sistema motorizado de posicionamento linear desenvolvido principalmente para **macrofotografia, fotografia científica e focus stacking automatizado**.

O equipamento controla o deslocamento da câmera ao longo de um trilho motorizado e permite definir posições, distâncias, velocidades, tempos e sequências de disparo diretamente através de sua interface.

O sistema também pode ser utilizado para movimentos contínuos de câmera, sequências temporizadas e exposições prolongadas.

A operação é realizada através de:

- display LCD 20×4;
- encoder rotativo com botão;
- botão A;
- botão B.

O firmware é organizado em quatro modos principais:

- **STACK** — posicionamento e execução de sequências automatizadas de focus stacking;
- **BULB** — controle de exposições prolongadas e sequências temporizadas de disparo;
- **SLIDER** — movimentos contínuos e repetitivos entre posições definidas;
- **CONFIG** — configuração dos parâmetros gerais de movimento e calibração do sistema.

### Sistema de referência

O Arandu Stack Macro Rail trabalha com **posições relativas**.

Ao ligar ou reiniciar o controlador, a posição atual do carro é utilizada como referência inicial do sistema.

O equipamento **não executa uma rotina automática de HOME**. Portanto, a referência de posição utilizada pelo firmware não corresponde necessariamente a uma extremidade física do trilho.

Os pontos **A** e **B** são definidos pelo usuário durante a operação e são utilizados como referências para diferentes funções dos modos STACK e SLIDER.

> **Importante:** antes de iniciar qualquer movimento, verifique se o percurso do carro está livre e se cabos, câmera, acessórios ou outros componentes não podem limitar mecanicamente o deslocamento.

---

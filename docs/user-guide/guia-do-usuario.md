# Arandu Stack Macro Rail — Guia do Usuário

[Português](guia-do-usuario.md) | [English](user-guide_EN.md)

Guia de operação do **Arandu Stack Macro Rail v1.0.0**.

---

## Sumário

1. [Introdução](#1-introdução)
2. [Controles](#2-controles)
   - [2.1 Encoder rotativo](#21-encoder-rotativo)
   - [2.2 Botão do encoder](#22-botão-do-encoder)
   - [2.3 Botões A e B](#23-botões-a-e-b)
   - [2.4 Pontos A e B](#24-pontos-a-e-b)
3. [Inicialização e menu principal](#3-inicialização-e-menu-principal)
   - [3.1 Inicialização](#31-inicialização)
   - [3.2 Menu principal](#32-menu-principal)
   - [3.3 Indicador de bateria](#33-indicador-de-bateria)
4. [Navegação geral](#4-navegação-geral)
   - [4.1 Navegação](#41-navegação)
   - [4.2 Edição de parâmetros](#42-edição-de-parâmetros)
   - [4.3 Retornar](#43-retornar)
   - [4.4 Cancelar uma rotina](#44-cancelar-uma-rotina)
5. [STACK](#5-stack)
   - [5.1 MOVER](#51-mover)
   - [5.2 Definição dos pontos A e B](#52-definição-dos-pontos-a-e-b)
   - [5.3 SEQUÊNCIA](#53-sequência)
   - [5.4 MOVIMENTO](#54-movimento)
   - [5.5 TEMPOS](#55-tempos)
   - [5.6 FOTOGRAFAR](#56-fotografar)
   - [5.7 Execução do stacking](#57-execução-do-stacking)
6. [BULB](#6-bulb)
   - [6.1 Parâmetros](#61-parâmetros)
   - [6.2 Execução](#62-execução)
7. [SLIDER](#7-slider)
   - [7.1 MOVER](#71-mover)
   - [7.2 VIDEO](#72-video)
   - [7.3 LOOP](#73-loop)
   - [7.4 CONFIG SLIDER](#74-config-slider)
8. [CONFIG](#8-config)
   - [8.1 Passos/mm](#81-passosmm)
   - [8.2 Curso](#82-curso)
   - [8.3 Movimentos manuais](#83-movimentos-manuais)
   - [8.4 Velocidades manuais](#84-velocidades-manuais)
   - [8.5 Salvar](#85-salvar)
   - [8.6 Fábrica](#86-fábrica)
9. [Fins de curso e segurança](#9-fins-de-curso-e-segurança)
10. [Configurações salvas](#10-configurações-salvas)
11. [Valores padrão](#11-valores-padrão)
12. [Fluxos rápidos de utilização](#12-fluxos-rápidos-de-utilização)
   - [12.1 Focus stacking](#121-focus-stacking)
   - [12.2 Slider de vídeo](#122-slider-de-vídeo)
   - [12.3 Movimento repetitivo](#123-movimento-repetitivo)
   - [12.4 Exposição longa](#124-exposição-longa)

---

## 1. Introdução

O **Arandu Stack Macro Rail** é um sistema motorizado de posicionamento linear desenvolvido principalmente para **macrofotografia, fotografia científica e focus stacking automatizado**.

O equipamento controla o deslocamento da câmera ao longo de um trilho motorizado e permite configurar posições, distâncias, velocidades, tempos e sequências de disparo diretamente através de sua interface.

O sistema também possui funções para:

- movimentação manual de precisão;
- movimentação contínua;
- slider motorizado para vídeo;
- movimentos repetitivos entre dois pontos;
- sequências temporizadas de fotografia;
- exposições prolongadas.

A interface utiliza:

- display LCD 20×4;
- encoder rotativo com botão;
- botão A;
- botão B.

O firmware é organizado em quatro modos principais:

- **STACK** — posicionamento e execução de sequências automatizadas de focus stacking;
- **BULB** — exposições prolongadas e sequências temporizadas de disparo;
- **SLIDER** — movimentos contínuos ou repetitivos entre dois pontos;
- **CONFIG** — calibração e configuração dos parâmetros gerais do sistema.

### Sistema de referência

O Arandu Stack Macro Rail utiliza um sistema de **posição relativa**.

Ao ligar ou reiniciar o controlador, a posição em que o carro se encontra é definida como posição **0**.

O sistema **não executa uma rotina automática de HOME**. Portanto, a posição 0 não corresponde necessariamente a uma extremidade física do trilho.

Os pontos **A** e **B** são definidos pelo usuário durante cada sessão e servem como referências para as rotinas STACK e SLIDER.

> **Importante:** antes de iniciar qualquer movimento, verifique se o percurso do carro está livre e se cabos, câmera, acessórios ou outros componentes não podem limitar mecanicamente o deslocamento.

---

## 2. Controles

### 2.1 Encoder rotativo

O encoder é o principal controle de navegação do sistema.

Ele possui três funções:

- **girar** — navegar pelos menus ou alterar valores;
- **clique curto** — selecionar itens, entrar ou sair da edição e iniciar determinadas funções;
- **pressionamento longo** — retornar à tela anterior ou cancelar uma rotina em execução.

Quando o modo **MOVER** está ativo, o giro do encoder também movimenta fisicamente o carro.

Cada passo do encoder desloca o carro de acordo com o modo selecionado:

- **LENTO**;
- **MEDIO**;
- **RAPIDO**.

Os deslocamentos e velocidades correspondentes podem ser alterados no menu **CONFIG**.

---

### 2.2 Botão do encoder

Um clique curto seleciona o item indicado pelo cursor `>`.

Nos parâmetros editáveis, o primeiro clique entra no modo de edição e o segundo clique encerra a edição.

Durante a edição, o símbolo apresentado no início da linha muda de:

```text
>
```

para:

```text
*
```

O pressionamento longo é reconhecido após aproximadamente **800 ms**.

Ele é utilizado para:

- sair de um submenu;
- retornar ao menu anterior;
- retornar ao menu principal;
- cancelar rotinas automáticas em execução.

---

### 2.3 Botões A e B

Os botões A e B possuem funções diferentes dependendo do estado do modo **MOVER**.

#### Dentro do MOVER ativo

**Clique curto em A**

Salva a posição atual como ponto **A**.

**Clique curto em B**

Salva a posição atual como ponto **B**.

**Manter A pressionado por aproximadamente 0,5 s**

Inicia movimento contínuo no sentido A.

**Manter B pressionado por aproximadamente 0,5 s**

Inicia movimento contínuo no sentido B.

O movimento continua somente enquanto o respectivo botão permanecer pressionado.

Ao soltar o botão, o movimento é interrompido imediatamente, sem executar uma rampa programada de desaceleração.

A velocidade utilizada é determinada pelo modo atualmente selecionado em MOVER:

- LENTO;
- MEDIO;
- RAPIDO.

Um pressionamento longo utilizado para movimentar o carro **não salva o ponto A ou B ao ser solto**.

Se A e B forem mantidos pressionados simultaneamente, o sistema não inicia movimento contínuo.

#### Fora do MOVER ativo

Um clique curto em **A** movimenta o carro até o ponto A previamente definido.

Um clique curto em **B** movimenta o carro até o ponto B previamente definido.

Se o respectivo ponto ainda não tiver sido definido, o comando não produz movimento.

---

### 2.4 Pontos A e B

Os pontos A e B determinam posições de referência ao longo do trilho.

Eles são utilizados para:

- estabelecer os limites de uma sequência de focus stacking;
- calcular a distância da sequência;
- determinar o início e o fim de movimentos do SLIDER;
- executar movimentos automáticos para posições previamente marcadas.

Os pontos A e B são independentes da posição 0 do sistema.

Eles **não são gravados permanentemente na EEPROM**.

Sempre que o controlador é ligado ou reiniciado:

- a posição atual passa a ser 0;
- o ponto A é apagado;
- o ponto B é apagado.

Portanto, A e B devem ser definidos novamente em cada sessão.

---

## 3. Inicialização e menu principal

### 3.1 Inicialização

Ao ligar o controlador, o sistema inicializa o display, as entradas, o controle do motor e carrega da EEPROM as configurações armazenadas.

O LCD apresenta inicialmente:

```text
ARANDU STACK V1
A CIENCIA CRESCE
QUANDO O SABER
CIRCULA
```

Essa tela permanece por aproximadamente 3 segundos.

Em seguida é apresentada a mensagem:

```text
INICIANDO...
```

Após a inicialização, o menu principal é exibido.

Durante esse processo:

- não ocorre movimento automático;
- não é realizada uma rotina HOME;
- a posição atual é definida como 0;
- os pontos A e B são apagados.

---

### 3.2 Menu principal

O menu principal possui quatro opções:

```text
STACK
BULB
SLIDER
CONFIG
```

**STACK**

Configuração e execução de sequências de focus stacking.

**BULB**

Controle de exposições prolongadas e sequências temporizadas de disparo.

**SLIDER**

Movimentação contínua ou repetitiva entre os pontos A e B.

**CONFIG**

Calibração e configuração dos parâmetros gerais do equipamento.

---

### 3.3 Indicador de bateria

O firmware possui um sistema de leitura da tensão da bateria.

Quando o circuito de monitoramento está instalado e corretamente calibrado, a tensão é apresentada no canto superior direito do LCD.

Exemplo:

```text
11.8V
```

A leitura é atualizada periodicamente.

Quando a tensão medida é igual ou inferior a **10,5 V**, o valor é substituído por:

```text
LOW
```

Durante o movimento contínuo comandado pelos botões A ou B, a atualização periódica da leitura é temporariamente suspensa para evitar pequenas pausas causadas pela leitura analógica.

> O funcionamento correto desse indicador depende da instalação adequada do circuito de monitoramento de tensão. Consulte a documentação elétrica do projeto.

---

## 4. Navegação geral

### 4.1 Navegação

O símbolo:

```text
>
```

indica o item atualmente selecionado.

Exemplo:

```text
>STACK
 BULB
 SLIDER
 CONFIG
```

Gire o encoder para percorrer os itens e pressione-o para selecionar.

Nos menus, o firmware utiliza:

- giro para a direita — desloca a seleção para cima;
- giro para a esquerda — desloca a seleção para baixo.

Ao chegar ao primeiro ou último item, a navegação continua ciclicamente para a outra extremidade da lista.

---

### 4.2 Edição de parâmetros

Quando um parâmetro editável estiver selecionado:

1. pressione o encoder;
2. o símbolo `>` muda para `*`;
3. gire o encoder para alterar o valor;
4. pressione novamente para encerrar a edição.

Exemplo:

```text
*Vel:MEDIO
```

Nem todos os valores apresentados na tela são editáveis. Alguns são calculados automaticamente pelo sistema.

---

### 4.3 Retornar

Mantenha o botão do encoder pressionado por aproximadamente **800 ms** para retornar.

Dependendo da tela atual, o comando retorna:

- de um submenu para o menu STACK ou SLIDER;
- do menu STACK para o menu principal;
- do menu SLIDER para o menu principal;
- de BULB para o menu principal;
- de CONFIG para o menu principal.

---

### 4.4 Cancelar uma rotina

Durante uma rotina automática, mantenha o encoder pressionado para cancelar.

Quando o cancelamento é reconhecido, o sistema:

- interrompe a rotina;
- interrompe o movimento;
- libera o disparo da câmera;
- limpa o estado de execução;
- retorna ao menu principal.

O LCD apresenta temporariamente:

```text
CANCELADO
Rotina parada
```

O botão do encoder deve ser solto antes que um novo comando de clique possa ser reconhecido.

---

## 5. STACK

O modo **STACK** controla a preparação e execução das sequências automatizadas de focus stacking.

Ao entrar em STACK são apresentados cinco submenus:

```text
MOVER
SEQUENCIA
MOVIMENTO
TEMPOS
FOTOGRAFAR
```

---

### 5.1 MOVER

O submenu MOVER é utilizado para posicionar manualmente a câmera e definir os pontos A e B.

A tela possui os campos:

```text
Vel:
Mover:
A:        B:
```

#### Vel

Seleciona um dos três modos de movimento:

- **LENTO**;
- **MEDIO**;
- **RAPIDO**.

Para alterar:

1. selecione `Vel`;
2. pressione o encoder;
3. gire para escolher o modo;
4. pressione novamente para encerrar a edição.

#### Mover

Selecione `Mover` e pressione o encoder para ativar o movimento manual.

Com Mover ativo, o giro do encoder desloca o carro.

Cada giro utiliza:

- o deslocamento configurado para o modo atual;
- a velocidade configurada para o modo atual.

Pressione novamente o encoder para sair do Mover ativo.

O valor apresentado em `Mover` corresponde à posição relativa atual, exibida em micrômetros.

---

### 5.2 Definição dos pontos A e B

Com **MOVER ativo**, posicione o carro no primeiro limite desejado.

Pressione brevemente:

```text
A
```

A posição atual será armazenada como ponto A.

Posicione então o carro no outro limite e pressione brevemente:

```text
B
```

A posição atual será armazenada como ponto B.

Também é possível utilizar o movimento contínuo:

- mantenha A pressionado para deslocar no sentido A;
- mantenha B pressionado para deslocar no sentido B;
- solte o botão para parar;
- depois utilize um clique curto para registrar a posição.

Os valores dos pontos aparecem na última linha da tela MOVER.

No STACK, eles são apresentados em micrômetros.

> A e B representam posições. Eles não precisam corresponder às extremidades físicas do trilho.

---

### 5.3 SEQUÊNCIA

O submenu SEQUÊNCIA apresenta:

```text
Fotos:
Dist:
Passo:
```

#### Fotos

Quantidade de fotografias calculada automaticamente pelo sistema.

Esse campo é somente leitura.

#### Dist

Distância absoluta entre os pontos A e B.

Esse campo é somente leitura e é apresentado em milímetros.

#### Passo

Distância nominal entre fotografias consecutivas.

Esse é o parâmetro editável da sequência.

O valor é apresentado em micrômetros e pode ser alterado em incrementos de **10 µm**.

O valor mínimo configurável é **10 µm**.

Ao alterar o Passo, o número de fotos é recalculado automaticamente a partir da distância A–B.

A relação utilizada pelo firmware é, em termos gerais:

```text
Fotos = (Distância / Passo) + 1
```

considerando a conversão interna para passos do motor e divisão inteira.

Por esse motivo, quando a distância A–B não é exatamente divisível pelo passo escolhido, a última fotografia pode ficar antes do ponto final B (ou A, quando a sequência ocorre no sentido inverso).

---

### 5.4 MOVIMENTO

O submenu MOVIMENTO controla o sentido da sequência e o comportamento após sua conclusão.

São apresentados:

```text
Dir:
Ret:
```

#### Dir

Define a direção:

```text
A>B
```

ou:

```text
B>A
```

Em `A>B`, a rotina começa em A e avança em direção a B.

Em `B>A`, começa em B e avança em direção a A.

#### Ret

Define o que acontece após a última fotografia.

Opções:

```text
Nao
A
B
```

**Nao**

O carro permanece na posição em que a sequência terminou.

**A**

Após a sequência, o carro retorna ao ponto A.

**B**

Após a sequência, o carro retorna ao ponto B.

---

### 5.5 TEMPOS

O submenu TEMPOS possui quatro parâmetros:

```text
Atraso:
Disp:
PosFoto:
Estab:
```

#### Atraso

Tempo aguardado antes do início da rotina.

Ajuste em incrementos de **500 ms**.

Valor mínimo: **0 ms**.

#### Disp

Tempo durante o qual a saída de disparo permanece acionada para cada fotografia.

Ajuste em incrementos de **50 ms**.

Valor mínimo: **50 ms**.

#### PosFoto

Tempo aguardado após o disparo.

Ajuste em incrementos de **100 ms**.

Valor mínimo: **0 ms**.

Esse tempo permite que a câmera conclua operações associadas à captura antes do próximo deslocamento.

#### Estab

Tempo aguardado depois de cada movimento e antes da próxima fotografia.

Ajuste em incrementos de **100 ms**.

Valor mínimo: **0 ms**.

Esse intervalo pode ser utilizado para permitir a estabilização mecânica do conjunto após o deslocamento.

---

### 5.6 FOTOGRAFAR

O submenu FOTOGRAFAR apresenta um resumo da sequência:

- número de fotos;
- passo em micrômetros;
- ponto A;
- ponto B.

Na última linha é apresentada a opção:

```text
>INICIAR
```

Pressione o encoder para iniciar.

A rotina somente é iniciada se:

- A estiver definido;
- B estiver definido;
- A e B forem posições diferentes.

Caso contrário, o sistema apresenta uma mensagem de erro.

---

### 5.7 Execução do stacking

Quando a rotina é iniciada, o sistema executa a seguinte sequência:

1. aguarda o tempo `Atraso`;
2. movimenta o carro até o ponto inicial definido em `Dir`;
3. realiza a primeira fotografia;
4. aguarda `PosFoto`;
5. desloca o carro pelo valor definido em `Passo`;
6. aguarda `Estab`;
7. realiza a fotografia seguinte;
8. repete o processo até completar o número calculado de fotografias;
9. executa o comportamento definido em `Ret`.

Durante a execução, o display informa o progresso da sequência e permite cancelamento mantendo o encoder pressionado.

Ao concluir normalmente, o sistema apresenta uma mensagem de conclusão e retorna à tela FOTOGRAFAR.

---

## 6. BULB

O modo **BULB** controla diretamente a saída de disparo da câmera e não depende dos pontos A e B.

Ele pode ser utilizado para exposições prolongadas e sequências temporizadas.

O menu possui:

```text
Fotos:
Bulb:
PosFoto:
Atraso:
Intervalo:
Iniciar
```

---

### 6.1 Parâmetros

#### Fotos

Quantidade de exposições da sequência.

Faixa:

```text
1 a 999
```

#### Bulb

Tempo durante o qual a saída de disparo permanece acionada.

Ajuste em incrementos de **1 segundo**.

Valor mínimo: **1 segundo**.

#### PosFoto

Tempo aguardado após cada exposição.

Ajuste em incrementos de **100 ms**.

Valor mínimo: **0 ms**.

#### Atraso

Tempo aguardado antes da primeira exposição.

Ajuste em incrementos de **500 ms**.

Valor mínimo: **0 ms**.

#### Intervalo

Tempo adicional aguardado entre uma fotografia e a próxima.

Ajuste em incrementos de **1 segundo**.

Valor mínimo: **0 s**.

---

### 6.2 Execução

Selecione:

```text
Iniciar
```

e pressione o encoder.

O sistema:

1. aguarda o `Atraso`;
2. aciona a saída da câmera;
3. mantém o disparo pelo tempo `Bulb`;
4. libera a saída;
5. aguarda `PosFoto`;
6. quando houver outra fotografia, aguarda `Intervalo`;
7. repete até completar o número definido em `Fotos`.

O movimento do trilho não faz parte da rotina BULB.

A rotina pode ser cancelada mantendo o encoder pressionado.

---

## 7. SLIDER

O modo **SLIDER** utiliza os pontos A e B para realizar movimentos contínuos ou repetitivos.

Possui quatro submenus:

```text
MOVER
VIDEO
LOOP
CONFIG SLIDER
```

---

### 7.1 MOVER

O funcionamento é equivalente ao MOVER existente no STACK.

Ele permite:

- selecionar LENTO, MEDIO ou RAPIDO;
- mover o carro através do encoder;
- manter A ou B pressionado para movimento contínuo;
- salvar A e B com cliques curtos.

No SLIDER, as posições A e B são apresentadas em **milímetros**.

Os pontos definidos no STACK e no SLIDER são os mesmos. Portanto, não existem conjuntos separados de A/B para cada modo.

---

### 7.2 VIDEO

O submenu VIDEO realiza um único deslocamento contínuo entre A e B.

A tela apresenta:

```text
Iniciar
Dir:
Vel:
```

#### Iniciar

Inicia o movimento.

#### Dir

Seleciona:

```text
A>B
```

ou:

```text
B>A
```

A tela também apresenta a distância entre A e B.

#### Vel

Velocidade do deslocamento em milímetros por segundo.

Faixa:

```text
0,05 a 10,00 mm/s
```

Incremento:

```text
0,05 mm/s
```

#### Execução

Ao iniciar:

1. o sistema verifica se A e B estão definidos e são diferentes;
2. movimenta o carro até o ponto inicial da direção escolhida;
3. aguarda o atraso configurado em CONFIG SLIDER;
4. percorre o trajeto até o ponto final utilizando a velocidade e aceleração configuradas para o SLIDER;
5. encerra a rotina.

O deslocamento até o ponto inicial utiliza a velocidade rápida geral do sistema. A velocidade de SLIDER é aplicada ao movimento principal entre A e B.

---

### 7.3 LOOP

O modo LOOP realiza ciclos de ida e volta entre A e B.

A tela apresenta:

```text
Iniciar
Ciclos:
Vel:
Pausa:
```

#### Ciclos

Quantidade de ciclos completos.

Faixa:

```text
1 a 999
```

Um ciclo corresponde ao movimento:

```text
início → fim → início
```

A posição considerada como início depende da direção configurada para o SLIDER.

#### Vel

Velocidade dos movimentos entre as extremidades.

Faixa:

```text
0,05 a 10,00 mm/s
```

Incremento:

```text
0,05 mm/s
```

#### Pausa

Tempo de espera nas extremidades.

Ajuste em incrementos de **100 ms**.

Valor mínimo: **0 ms**.

#### Execução

Ao iniciar:

1. o carro vai até o ponto inicial;
2. aguarda o atraso configurado;
3. movimenta-se até o ponto final;
4. aguarda a pausa;
5. retorna ao ponto inicial;
6. quando houver outro ciclo, aguarda novamente a pausa;
7. repete até completar o número de ciclos.

Ao final, o carro permanece no ponto inicial.

---

### 7.4 CONFIG SLIDER

O submenu CONFIG SLIDER possui:

```text
Vel:
Acel:
Atraso:
```

#### Vel

Velocidade utilizada pelos movimentos principais do SLIDER.

Faixa:

```text
0,05 a 10,00 mm/s
```

Incremento:

```text
0,05 mm/s
```

O mesmo valor também pode ser ajustado diretamente nos submenus VIDEO e LOOP.

#### Acel

Aceleração utilizada pelo movimento do SLIDER.

Faixa:

```text
10 a 3000 passos/s²
```

Incremento:

```text
10 passos/s²
```

#### Atraso

Tempo aguardado depois que o carro chega à posição inicial e antes de começar o movimento principal.

Faixa:

```text
0 a 300 segundos
```

Incremento:

```text
1 segundo
```

Esse atraso pode ser utilizado, por exemplo, para permitir que o operador inicie uma gravação antes que o movimento do slider comece.

---

## 8. CONFIG

O menu **CONFIG** reúne os parâmetros gerais de calibração e movimento.

Os itens são:

```text
Passos/mm
Curso
MovL
MovM
MovR
VelL
VelM
VelR
Salvar
Fabrica
```

---

### 8.1 Passos/mm

Define quantos passos internos do controlador correspondem a 1 mm de deslocamento linear.

Esse parâmetro influencia todas as conversões entre:

- passos;
- micrômetros;
- milímetros;
- velocidades em mm/s.

O ajuste ocorre em incrementos de:

```text
10 passos/mm
```

Valor mínimo:

```text
1 passo/mm
```

A configuração padrão da versão 1.0.0 é:

```text
800 passos/mm
```

> Alterar esse valor modifica a calibração dimensional de todo o sistema. Faça alterações somente quando necessário para adequar o firmware à configuração mecânica e ao microstepping utilizado.

---

### 8.2 Curso

Define o limite lógico relativo permitido para os destinos de movimento.

O sistema trabalha em torno da referência 0 criada durante a inicialização, permitindo coordenadas positivas e negativas dentro do limite configurado.

Esse parâmetro **não mede automaticamente o curso físico do trilho** e não substitui os fins de curso.

A alteração ocorre internamente em incrementos de 100 passos e o valor é apresentado na interface convertido para milímetros conforme a calibração atual de `Passos/mm`.

> O limite lógico deve ser configurado de forma compatível com a montagem mecânica utilizada.

---

### 8.3 Movimentos manuais

Os parâmetros:

```text
MovL
MovM
MovR
```

definem o deslocamento realizado por cada incremento do encoder quando MOVER está ativo.

#### MovL

Deslocamento do modo LENTO.

Faixa:

```text
1 a 1000 µm
```

Incremento:

```text
1 µm
```

#### MovM

Deslocamento do modo MEDIO.

Faixa:

```text
10 a 5000 µm
```

Incremento:

```text
10 µm
```

#### MovR

Deslocamento do modo RAPIDO.

Faixa:

```text
100 a 20000 µm
```

Incremento:

```text
100 µm
```

---

### 8.4 Velocidades manuais

Os parâmetros:

```text
VelL
VelM
VelR
```

definem a velocidade utilizada pelos três modos de movimento manual.

#### VelL

Velocidade do modo LENTO.

Faixa:

```text
0,05 a 2,00 mm/s
```

Incremento:

```text
0,05 mm/s
```

#### VelM

Velocidade do modo MEDIO.

Faixa:

```text
0,10 a 10,00 mm/s
```

Incremento:

```text
0,10 mm/s
```

#### VelR

Velocidade do modo RAPIDO.

Faixa:

```text
0,50 a 30,00 mm/s
```

Incremento:

```text
0,50 mm/s
```

---

### 8.5 Salvar

As alterações realizadas nos parâmetros ficam disponíveis durante a operação atual.

Para armazenar as configurações permanentemente, selecione:

```text
Salvar
```

O sistema grava na EEPROM os parâmetros configuráveis e apresenta:

```text
EEPROM
SALVA
```

Essas configurações serão carregadas automaticamente na próxima inicialização.

---

### 8.6 Fábrica

A opção:

```text
Fabrica
```

restaura os valores padrão definidos no firmware v1.0.0.

Ao selecionar essa opção, o sistema apresenta:

```text
PADRAO
RESTAURADO
```

Os valores padrão são aplicados e gravados na EEPROM.

---

## 9. Fins de curso e segurança

O Arandu Stack Macro Rail pode utilizar dois fins de curso físicos:

- limite inicial;
- limite final.

Eles são utilizados **somente como dispositivos de segurança**.

O firmware não utiliza esses sensores para:

- executar HOME;
- definir automaticamente a posição 0;
- medir o curso do trilho.

Quando um fim de curso é acionado, o sistema bloqueia movimentos que continuariam naquela direção.

O movimento no sentido oposto permanece possível, permitindo afastar o carro do limite.

### Ligação

O firmware foi desenvolvido para fins de curso **normalmente fechados (NC)** utilizando as entradas com `INPUT_PULLUP`.

Em operação normal:

```text
entrada → contato NC → GND
```

Com o contato fechado, a entrada permanece em nível LOW.

Quando o fim de curso é acionado e o contato abre, a entrada passa para HIGH através do pull-up interno e o firmware interpreta o sensor como acionado.

### Operação sem fins de curso

Os fins de curso são opcionais.

Entretanto, caso eles não sejam instalados, **as duas entradas de fim de curso devem ser conectadas ao GND através de jumpers**.

Não deixe essas entradas desconectadas.

Uma entrada desconectada será mantida em HIGH pelo `INPUT_PULLUP` e poderá ser interpretada pelo sistema como um fim de curso acionado, bloqueando movimentos.

Consulte também:

```text
docs/electronics/electrical-system.md
```

para as instruções elétricas completas.

### Segurança mecânica

Antes de utilizar o equipamento:

- verifique se o carro pode percorrer a região desejada sem colisões;
- verifique cabos conectados à câmera;
- verifique a fixação da câmera e dos acessórios;
- não utilize o limite lógico como única proteção contra colisões;
- utilize fins de curso físicos quando a aplicação exigir proteção adicional;
- evite configurar velocidades ou acelerações incompatíveis com a montagem mecânica.

---

## 10. Configurações salvas

O sistema utiliza a EEPROM do controlador para armazenar as configurações.

Entre os parâmetros armazenados estão:

- passos por milímetro;
- limite lógico de curso;
- deslocamentos LENTO, MEDIO e RAPIDO;
- velocidades LENTA, MEDIA e RAPIDA;
- parâmetros do STACK;
- direção e retorno do STACK;
- parâmetros do BULB;
- parâmetros do SLIDER;
- velocidade e aceleração do SLIDER;
- ciclos e pausa do LOOP;
- atraso do SLIDER.

Para gravar as alterações realizadas durante a operação, utilize:

```text
CONFIG → Salvar
```

### Dados que não são salvos

Os pontos:

```text
A
B
```

não são armazenados na EEPROM.

A posição relativa atual também não é preservada após reinicialização.

Sempre que o equipamento é ligado:

```text
posição atual = 0
A = não definido
B = não definido
```

Isso evita utilizar automaticamente posições físicas definidas em uma sessão anterior.

---

## 11. Valores padrão

A restauração de fábrica da versão 1.0.0 utiliza os seguintes valores.

### Sistema

| Parâmetro | Valor padrão |
|---|---:|
| Passos/mm | 800 |
| Limite lógico | 50000 passos |
| Mover inicial | MEDIO |

### Movimento manual

| Parâmetro | Valor padrão |
|---|---:|
| MovL | 10 µm |
| MovM | 250 µm |
| MovR | 4000 µm |
| VelL | 0,25 mm/s |
| VelM | 2,00 mm/s |
| VelR | 20,00 mm/s |

### STACK

| Parâmetro | Valor padrão |
|---|---:|
| Fotos | 20 |
| Passo interno inicial | 80 passos |
| Atraso | 2,0 s |
| Disp | 500 ms |
| PosFoto | 3,0 s |
| Estab | 500 ms |
| Direção | A>B |
| Retorno | Não |

Com a calibração padrão de 800 passos/mm, 80 passos internos correspondem a aproximadamente:

```text
100 µm
```

O número de fotos é recalculado quando o passo da sequência é alterado após a definição de A e B.

### BULB

| Parâmetro | Valor padrão |
|---|---:|
| Fotos | 1 |
| Bulb | 5,0 s |
| PosFoto | 500 ms |
| Atraso | 2,0 s |
| Intervalo | 2,0 s |

### SLIDER

| Parâmetro | Valor padrão |
|---|---:|
| Direção | A>B |
| Velocidade | 0,50 mm/s |
| Aceleração | 300 passos/s² |
| Ciclos | 1 |
| Pausa | 1,0 s |
| Atraso | 10,0 s |

> Os valores apresentados nesta seção correspondem aos padrões definidos no firmware v1.0.0. Configurações gravadas pelo usuário na EEPROM substituem esses valores durante a inicialização.

---

## 12. Fluxos rápidos de utilização

Esta seção resume os procedimentos mais comuns.

---

### 12.1 Focus stacking

#### 1. Posicionar e definir A

Entre em:

```text
STACK → MOVER
```

Escolha a velocidade desejada.

Ative `Mover`.

Posicione a câmera no primeiro limite da sequência utilizando o encoder ou mantendo o botão A/B pressionado.

Pressione brevemente **A** para salvar o ponto A.

#### 2. Posicionar e definir B

Desloque a câmera até o outro limite da sequência.

Pressione brevemente **B** para salvar o ponto B.

#### 3. Definir o passo

Entre em:

```text
STACK → SEQUENCIA
```

Edite:

```text
Passo
```

O sistema calcula automaticamente a distância e o número de fotografias.

#### 4. Definir o sentido

Entre em:

```text
STACK → MOVIMENTO
```

Escolha:

```text
A>B
```

ou:

```text
B>A
```

Defina também o retorno desejado:

```text
Nao
A
B
```

#### 5. Configurar os tempos

Entre em:

```text
STACK → TEMPOS
```

Configure:

```text
Atraso
Disp
PosFoto
Estab
```

#### 6. Iniciar

Entre em:

```text
STACK → FOTOGRAFAR
```

Confira os valores apresentados e pressione:

```text
INICIAR
```

---

### 12.2 Slider de vídeo

#### 1. Definir A e B

Entre em:

```text
SLIDER → MOVER
```

Posicione e salve os dois limites utilizando os botões A e B.

#### 2. Configurar o movimento

Entre em:

```text
SLIDER → VIDEO
```

Configure:

```text
Dir
Vel
```

Se necessário, ajuste também:

```text
SLIDER → CONFIG SLIDER
```

para configurar:

```text
Acel
Atraso
```

#### 3. Iniciar

Selecione:

```text
Iniciar
```

O carro irá primeiro até a posição inicial, aguardará o atraso configurado e então realizará o movimento principal até a outra extremidade.

---

### 12.3 Movimento repetitivo

Defina A e B em:

```text
SLIDER → MOVER
```

Depois entre em:

```text
SLIDER → LOOP
```

Configure:

```text
Ciclos
Vel
Pausa
```

Ajuste, se necessário:

```text
SLIDER → CONFIG SLIDER
```

e então selecione:

```text
Iniciar
```

Cada ciclo corresponde a uma ida e uma volta completas.

---

### 12.4 Exposição longa

Entre em:

```text
BULB
```

Configure:

```text
Fotos
Bulb
PosFoto
Atraso
Intervalo
```

Selecione:

```text
Iniciar
```

O sistema executará a sequência de disparos sem movimentar o trilho.

---

## Cancelamento de emergência durante uma rotina

Durante STACK, BULB, VIDEO ou LOOP, mantenha pressionado o botão do encoder para cancelar a rotina.

O sistema interromperá a execução e retornará ao menu principal.

Se houver risco de colisão mecânica, falha de controle ou comportamento inesperado, desligue a alimentação do sistema.

---

## Documentação relacionada

Para informações sobre componentes:

```text
docs/materials.md
```

Para montagem mecânica:

```text
docs/assembly/instructions.md
```

Para montagem e conexões elétricas:

```text
docs/electronics/electrical-system.md
```

Para o firmware:

```text
firmware/Arandu_Stack_Macro_Rail.ino
```

---

**Arandu Stack Macro Rail — Firmware v1.0.0**

Projeto e firmware: **Pedro José Vieira de Souza**

Citação acadêmica: **SOUZA, P. J. V.**

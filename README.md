# Arandu Stack Macro Rail

[Português](README.md) | [English](README_EN.md)

## Sobre o projeto

O **Arandu Stack Macro Rail** é um trilho motorizado de precisão desenvolvido para macrofotografia e automação de sequências de **focus stacking**.

O sistema permite controlar de forma precisa e repetível o deslocamento linear da câmera, automatizando a captura de sequências de imagens em diferentes planos de foco. O projeto foi concebido como uma alternativa aberta e acessível a sistemas comerciais de trilhos automatizados, utilizando componentes amplamente disponíveis e permitindo sua construção, modificação e manutenção pelo próprio usuário.

O Macro Rail integra o **Arandu Stack**, uma iniciativa voltada ao desenvolvimento de ferramentas abertas, acessíveis e reproduzíveis para fotografia, documentação e aplicações científicas.

## Objetivos

O projeto foi desenvolvido tendo como princípios:

* **Acessibilidade:** utilização de componentes de baixo custo e fácil obtenção;
* **Precisão:** controle de pequenos deslocamentos necessários à macrofotografia;
* **Repetibilidade:** execução automatizada de sequências de movimento e captura;
* **Modularidade:** possibilidade de alteração, manutenção e expansão do sistema;
* **Reprodutibilidade:** documentação suficiente para permitir que outras pessoas construam e adaptem o equipamento;
* **Código aberto:** acesso ao firmware para estudo, modificação e desenvolvimento;
* **Ciência aberta:** facilitar o acesso a ferramentas para fotografia e documentação científica.

## Principais funcionalidades

O Arandu Stack Macro Rail foi desenvolvido para oferecer controle manual e automatizado do deslocamento da câmera.

Entre as principais funcionalidades do sistema estão:

- macrofotografia;
- focus stacking automatizado;
- fotografia científica;
- rastreamento de estrelas para astrofotografia;
- testes ópticos;
- automação experimental;
- desenvolvimento de sistemas de posicionamento linear.
  
As funcionalidades podem sofrer alterações entre diferentes versões do firmware.

## Estrutura do sistema

O equipamento é composto por três conjuntos principais:

### Mecânica

A estrutura mecânica é responsável pelo deslocamento linear preciso da câmera e utiliza um motor de passo associado a um sistema de transmissão por fuso.

O projeto foi pensado para permitir construção com componentes comerciais facilmente encontrados e possibilitar adaptações de acordo com os materiais e equipamentos disponíveis.

### Eletrônica

O sistema eletrônico realiza o controle do motor, leitura dos comandos do usuário, monitoramento do equipamento e acionamento da câmera.

Os esquemas, conexões e demais informações necessárias para reprodução da eletrônica serão disponibilizados neste repositório.

### Firmware

O firmware controla a interface, movimentação do motor, armazenamento dos parâmetros de operação e execução automática das sequências fotográficas.

O código-fonte é disponibilizado para permitir estudo, modificação e desenvolvimento de novas funcionalidades.

## Aplicações

Embora tenha sido desenvolvido principalmente para **macrofotografia com focus stacking**, o sistema pode ser adaptado para outras aplicações que necessitem de deslocamento linear controlado e repetível.

Entre as possíveis aplicações estão:

* macrofotografia;
* fotografia científica;
* documentação de espécimes;
* fotografia de pequenos objetos;
* digitalização e documentação técnica;
* testes ópticos;
* automação experimental;
* desenvolvimento de sistemas de posicionamento linear.

## Estrutura do repositório

A documentação do projeto será organizada para separar os diferentes componentes do sistema.

```text
Arandu-Stack-Macro-Rail/
│
├── README.md
├── README_EN.md
├── LICENSE
├── CITATION.cff
│
├── firmware/
│
├── hardware/
│
├── mechanical/
│
├── docs/
│
└── images/
```

### `firmware/`

Código-fonte utilizado no controle do equipamento.

### `hardware/`

Esquemas eletrônicos, placas, diagramas de conexão e demais arquivos relacionados à eletrônica.

### `mechanical/`

Desenhos, medidas, peças e arquivos relacionados à construção mecânica do trilho.

### `docs/`

Documentação complementar, instruções de montagem, configuração, operação e manutenção.

### `images/`

Fotografias, diagramas e imagens utilizadas na documentação do projeto.

## Status do projeto

O **Arandu Stack Macro Rail** encontra-se em desenvolvimento ativo.

O equipamento já possui versões funcionais utilizadas durante o desenvolvimento e os arquivos serão organizados e publicados progressivamente neste repositório.

Alterações de hardware, firmware e documentação poderão ocorrer durante o desenvolvimento.

Versões estáveis serão identificadas por meio das **Releases** do repositório.

## Construção e documentação

Os arquivos necessários para reprodução do equipamento serão disponibilizados progressivamente neste repositório.

A documentação deverá incluir:

* lista de componentes;
* montagem mecânica;
* montagem eletrônica;
* conexões;
* instalação do firmware;
* configuração inicial;
* operação do equipamento;
* descrição da interface;
* solução de problemas;
* arquivos auxiliares para fabricação.

## Autor

**Pedro José Vieira de Souza**

Forma de citação acadêmica:

**SOUZA, P. J. V.**

Currículo Lattes:
http://lattes.cnpq.br/1385276444101459

## Como citar

Se o **Arandu Stack Macro Rail** for utilizado em pesquisa científica, trabalhos acadêmicos, desenvolvimento de metodologias ou publicações, solicita-se que o projeto seja devidamente citado.

Os metadados de citação estão disponíveis no arquivo [`CITATION.cff`](CITATION.cff).

Uma referência permanente por DOI poderá ser disponibilizada para versões publicadas do projeto.

## Licença

O firmware do **Arandu Stack Macro Rail** é distribuído sob os termos da **GNU General Public License v3.0 (GPL-3.0)**.

Isso permite que o código seja utilizado, estudado, modificado e redistribuído de acordo com os termos estabelecidos pela licença.

**Copyright © 2026 Pedro José Vieira de Souza.**

Os arquivos de hardware, projetos mecânicos e documentação poderão possuir licenças específicas indicadas em seus respectivos diretórios.

## Contribuições

Contribuições, correções, testes e melhorias são bem-vindos.

Modificações e contribuições devem respeitar as licenças aplicáveis aos diferentes componentes do projeto e preservar os avisos de autoria e licenciamento correspondentes.

## Aviso

Este é um projeto aberto e em desenvolvimento. A reprodução, montagem ou modificação do equipamento é de responsabilidade do usuário.

Antes da utilização em aplicações críticas ou científicas, recomenda-se verificar experimentalmente a precisão, repetibilidade e adequação do equipamento à aplicação pretendida.

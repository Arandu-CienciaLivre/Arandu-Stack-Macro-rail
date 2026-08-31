# Arandu Stack Macro Rail

[Português](README.md) | [English](README_EN.md)

[![DOI](https://zenodo.org/badge/1351705239.svg)](https://doi.org/10.5281/zenodo.22212884)

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

* movimentação manual do trilho;
* controle de movimento em diferentes níveis de precisão;
* definição independente dos pontos **A** e **B**;
* deslocamento automatizado entre os pontos definidos;
* execução automática de sequências de focus stacking;
* configuração do número de fotografias e/ou deslocamento entre capturas;
* controle do sentido da sequência;
* controle dos tempos envolvidos na captura;
* acionamento automatizado da câmera;
* retorno configurável após a execução da sequência;
* interface local para configuração e operação do equipamento;
* funcionamento independente de computador durante a captura.

As funcionalidades podem sofrer alterações entre diferentes versões do firmware.

## Estrutura do sistema

O Arandu Stack Macro Rail foi desenvolvido a partir da integração e adaptação de componentes eletrônicos e mecânicos comerciais, coordenados por um firmware desenvolvido especificamente para o sistema.

Essa abordagem permite construir o equipamento utilizando componentes amplamente disponíveis, reduzindo custos e facilitando sua reprodução, manutenção e adaptação.

### Componentes e montagem

O sistema utiliza módulos eletrônicos, elementos mecânicos e componentes comerciais selecionados e integrados para formar o trilho automatizado.

A documentação do projeto apresenta os componentes utilizados, suas conexões, adaptações e procedimentos de montagem necessários para reproduzir o sistema.

### Firmware

O firmware do Arandu Stack Macro Rail foi desenvolvido especificamente para controlar o funcionamento integrado do equipamento.

Ele é responsável pela interface com o usuário, controle de movimento, configuração dos parâmetros de operação, acionamento da câmera e execução das sequências automatizadas.

## Aplicações

Embora tenha sido desenvolvido principalmente para **macrofotografia com focus stacking**, o sistema pode ser adaptado para outras aplicações que necessitem de deslocamento linear controlado e repetível.

Entre as possíveis aplicações estão:

* macrofotografia;
* focus stacking automatizado;
* fotografia científica;
* rastreamento de estrelas para astrofotografia;
* testes ópticos;
* automação experimental;
* desenvolvimento de sistemas de posicionamento linear.

## Estrutura do repositório

A documentação do projeto é organizada para separar o firmware dos materiais necessários para construção, configuração e utilização do sistema.

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
├── docs/
│   ├── assembly/
│   ├── wiring/
│   └── user-guide/
│
└── images/
```

### `firmware/`

Código-fonte utilizado no controle do equipamento.

### `docs/`

Documentação técnica do projeto, incluindo lista de componentes, instruções de montagem, adaptações mecânicas, conexões elétricas, configuração, operação e manutenção.

### `images/`

Fotografias, diagramas e imagens utilizadas na documentação do projeto.

## Status do projeto

O **Arandu Stack Macro Rail** encontra-se em desenvolvimento ativo.

O equipamento já possui versões funcionais utilizadas durante o desenvolvimento e os arquivos serão organizados e publicados progressivamente neste repositório.

Alterações de configuração, firmware e documentação poderão ocorrer durante o desenvolvimento.

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
* arquivos auxiliares necessários à reprodução do sistema.

## Autor

**Pedro José Vieira de Souza**

Forma de citação acadêmica:

**SOUZA, P. J. V.**

Currículo Lattes:
http://lattes.cnpq.br/1385276444101459

### Escopo da autoria

O Arandu Stack Macro Rail utiliza componentes eletrônicos e mecânicos comerciais de diferentes fabricantes.

A autoria atribuída neste repositório refere-se ao desenvolvimento do sistema **Arandu Stack Macro Rail**, incluindo sua integração, adaptações desenvolvidas para sua implementação, firmware e documentação original.

Os direitos sobre componentes, módulos, bibliotecas e projetos de terceiros permanecem pertencentes aos seus respectivos autores e fabricantes.

## Como citar

Se o **Arandu Stack Macro Rail** for utilizado em pesquisa científica, trabalhos acadêmicos, desenvolvimento de metodologias ou publicações, solicita-se que o projeto seja devidamente citado.

Os metadados de citação estão disponíveis no arquivo [`CITATION.cff`](CITATION.cff).

## Licença

O firmware original do **Arandu Stack Macro Rail** é distribuído sob os termos da **GNU General Public License v3.0 (GPL-3.0)**.

Isso permite que o firmware seja utilizado, estudado, modificado e redistribuído de acordo com os termos estabelecidos pela licença.

**Copyright © 2026 Pedro José Vieira de Souza.**

A documentação original produzida para o projeto poderá ser disponibilizada sob licença específica, indicada nos respectivos arquivos ou diretórios.

Componentes comerciais, bibliotecas de software e demais materiais de terceiros utilizados ou mencionados no projeto permanecem sujeitos às licenças e aos termos estabelecidos por seus respectivos autores, desenvolvedores ou fabricantes.

## Contribuições

Contribuições, correções, testes e melhorias são bem-vindos.

Modificações e contribuições devem respeitar as licenças aplicáveis aos diferentes componentes do projeto e preservar os avisos de autoria e licenciamento correspondentes.

## Aviso

Este é um projeto aberto e em desenvolvimento. A reprodução, montagem ou modificação do equipamento é de responsabilidade do usuário.

Antes da utilização em aplicações críticas ou científicas, recomenda-se verificar experimentalmente a precisão, repetibilidade e adequação do equipamento à aplicação pretendida.

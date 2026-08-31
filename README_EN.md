# Arandu Stack Macro Rail

[Português](README.md) | [English](README_EN.md)

[![DOI](https://zenodo.org/badge/1351705239.svg)](https://doi.org/10.5281/zenodo.22212884)

## About the Project

The **Arandu Stack Macro Rail** is a precision motorized rail developed for macro photography and automated **focus stacking** sequences.

The system provides precise and repeatable control of linear camera movement, automating the capture of image sequences at different focal planes. The project was conceived as an open and accessible alternative to commercial automated rail systems, using widely available components and allowing users to build, modify, and maintain the system themselves.

The Macro Rail is part of **Arandu Stack**, an initiative focused on the development of open, accessible, and reproducible tools for photography, documentation, and scientific applications.

## Objectives

The project was developed according to the following principles:

* **Accessibility:** use of affordable and readily available components;
* **Precision:** control of small displacements required for macro photography;
* **Repeatability:** automated execution of movement and capture sequences;
* **Modularity:** ability to modify, maintain, and expand the system;
* **Reproducibility:** documentation designed to allow others to build and adapt the equipment;
* **Open source:** access to the firmware for study, modification, and further development;
* **Open science:** facilitating access to tools for photography and scientific documentation.

## Main Features

The Arandu Stack Macro Rail was developed to provide both manual and automated camera movement control.

Its main features include:

* manual rail movement;
* movement control at different precision levels;
* independent definition of **A** and **B** positions;
* automated movement between defined positions;
* automated focus stacking sequences;
* configuration of the number of photographs and/or displacement between captures;
* sequence direction control;
* configurable capture timing;
* automated camera triggering;
* configurable return behavior after sequence completion;
* local interface for system configuration and operation;
* standalone operation without requiring a computer during image capture.

Features may change between firmware versions.

## System Structure

The Arandu Stack Macro Rail was developed through the integration and adaptation of commercially available electronic and mechanical components, coordinated by firmware developed specifically for the system.

This approach makes it possible to build the equipment using widely available components, reducing costs and facilitating reproduction, maintenance, and adaptation.

### Components and Assembly

The system uses electronic modules, mechanical elements, and commercial components selected and integrated to form the automated rail.

Project documentation describes the components used, their connections, adaptations, and assembly procedures required to reproduce the system.

### Firmware

The Arandu Stack Macro Rail firmware was developed specifically to control the integrated operation of the equipment.

It is responsible for the user interface, motion control, configuration of operating parameters, camera triggering, and execution of automated sequences.

## Applications

Although primarily developed for **macro photography with focus stacking**, the system can be adapted to other applications requiring controlled and repeatable linear movement.

Possible applications include:

* macro photography;
* automated focus stacking;
* scientific photography;
* star tracking for astrophotography;
* optical testing;
* experimental automation;
* development of linear positioning systems.

## Repository Structure

Project documentation is organized to separate the firmware from the materials required to build, configure, and operate the system.

```text id="uq6rsk"
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

Source code used to control the equipment.

### `docs/`

Technical project documentation, including the bill of materials, assembly instructions, mechanical adaptations, electrical connections, configuration, operation, and maintenance.

### `images/`

Photographs, diagrams, and images used in the project documentation.

## Project Status

The **Arandu Stack Macro Rail** is under active development.

Functional versions of the equipment have already been used during development, and project files will be progressively organized and published in this repository.

Configuration, firmware, and documentation may change throughout development.

Stable versions will be identified through repository **Releases**.

## Building and Documentation

The files required to reproduce the equipment will be progressively made available in this repository.

Documentation is intended to include:

* bill of materials;
* mechanical assembly;
* electronic assembly;
* connections and wiring;
* firmware installation;
* initial configuration;
* equipment operation;
* user interface documentation;
* troubleshooting;
* auxiliary files required to reproduce the system.

## Author

**Pedro José Vieira de Souza**

Academic citation name:

**SOUZA, P. J. V.**

Lattes CV:
http://lattes.cnpq.br/1385276444101459

### Scope of Authorship

The Arandu Stack Macro Rail uses commercially available electronic and mechanical components from different manufacturers.

Authorship attributed in this repository refers to the development of the **Arandu Stack Macro Rail** system, including its integration, adaptations developed for its implementation, firmware, and original documentation.

Rights related to third-party components, modules, libraries, and designs remain with their respective authors and manufacturers.

## How to Cite

If the **Arandu Stack Macro Rail** is used in scientific research, academic work, methodology development, or publications, please cite the project appropriately.

Citation metadata is available in the [`CITATION.cff`](CITATION.cff) file.


## License

The original **Arandu Stack Macro Rail** firmware is distributed under the **GNU General Public License v3.0 (GPL-3.0)**.

The firmware may be used, studied, modified, and redistributed according to the terms established by the license.

**Copyright © 2026 Pedro José Vieira de Souza.**

Original documentation produced for the project may be distributed under a specific license indicated in the corresponding files or directories.

Commercial components, software libraries, and other third-party materials used or referenced by the project remain subject to the licenses and terms established by their respective authors, developers, or manufacturers.

## Contributions

Contributions, corrections, testing, and improvements are welcome.

Modifications and contributions must comply with the licenses applicable to each component of the project and preserve the corresponding authorship and licensing notices.

## Disclaimer

This is an open project under active development. Building, assembling, modifying, or operating the equipment is the user's responsibility.

Before use in critical or scientific applications, the precision, repeatability, and suitability of the equipment for the intended application should be experimentally verified.

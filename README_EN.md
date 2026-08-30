# Arandu Stack Macro Rail

[Português](README.md) | [English](README_EN.md)

## About the Project

The **Arandu Stack Macro Rail** is a precision motorized rail developed for macro photography and automated **focus stacking** sequences.

The system provides precise and repeatable control of linear camera movement, automating the capture of image sequences at different focal planes. The project was conceived as an open and accessible alternative to commercial automated rail systems, using widely available components and allowing users to build, modify, and maintain the equipment themselves.

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

The equipment consists of three main subsystems:

### Mechanics

The mechanical structure provides precise linear camera movement using a stepper motor coupled to a lead screw transmission system.

The project was designed around readily available commercial components while allowing adaptations according to locally available materials and equipment.

### Electronics

The electronic system controls the motor, reads user commands, monitors the equipment, and triggers the camera.

Schematics, connections, and other information required to reproduce the electronics will be made available in this repository.

### Firmware

The firmware controls the user interface, motor movement, operating parameters, and automated photographic sequences.

The source code is provided to allow study, modification, and development of additional features.

## Applications

Although primarily developed for **macro photography and focus stacking**, the system can be adapted to other applications requiring controlled and repeatable linear movement.

Possible applications include:

* macro photography;
* automated focus stacking;
* scientific photography;
* star tracking for astrophotography;
* optical testing;
* experimental automation;
* development of linear positioning systems.

## Repository Structure

Project documentation is organized to separate the different components of the system.

```text id="ng7m0i"
Arandu-Stack-Macro-Rail/
│
├── README.md
├── README_EN.md
├── LICENSE
├── CITATION.cff
│
├── firmware/
├── hardware/
├── mechanical/
├── docs/
└── images/
```

### `firmware/`

Source code used to control the equipment.

### `hardware/`

Electronic schematics, circuit boards, wiring diagrams, and other electronics-related files.

### `mechanical/`

Drawings, dimensions, parts, and files related to the mechanical construction of the rail.

### `docs/`

Additional documentation, assembly instructions, configuration, operation, and maintenance information.

### `images/`

Photographs, diagrams, and images used in the project documentation.

## Project Status

The **Arandu Stack Macro Rail** is under active development.

Functional versions of the equipment have already been developed and tested, and project files will be progressively organized and published in this repository.

Hardware, firmware, and documentation may change throughout development.

Stable versions will be identified through repository **Releases**.

## Building and Documentation

The files required to reproduce the equipment will be progressively made available in this repository.

Documentation is intended to include:

* bill of materials;
* mechanical assembly;
* electronic assembly;
* wiring;
* firmware installation;
* initial configuration;
* equipment operation;
* user interface documentation;
* troubleshooting;
* auxiliary manufacturing files.

## Author

**Pedro José Vieira de Souza**

Academic citation name:

**SOUZA, P. J. V.**

Lattes CV:
http://lattes.cnpq.br/1385276444101459

## How to Cite

If the **Arandu Stack Macro Rail** is used in scientific research, academic work, methodology development, or publications, please cite the project appropriately.

Citation metadata is available in the [`CITATION.cff`](CITATION.cff) file.

A permanent DOI reference may be provided for released versions of the project.

## License

The **Arandu Stack Macro Rail** firmware is distributed under the **GNU General Public License v3.0 (GPL-3.0)**.

The source code may be used, studied, modified, and redistributed according to the terms of the license.

**Copyright © 2026 Pedro José Vieira de Souza.**

Hardware files, mechanical designs, and documentation may be distributed under specific licenses indicated in their respective directories.

## Contributions

Contributions, corrections, testing, and improvements are welcome.

Modifications and contributions must comply with the licenses applicable to each component of the project and preserve the corresponding authorship and licensing notices.

## Disclaimer

This is an open project under active development. Building, assembling, modifying, or operating the equipment is the user's responsibility.

Before use in critical or scientific applications, the precision, repeatability, and suitability of the equipment for the intended application should be experimentally verified.

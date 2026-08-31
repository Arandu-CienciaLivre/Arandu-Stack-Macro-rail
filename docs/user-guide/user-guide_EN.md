# Arandu Stack Macro Rail — User Guide

[Português](guia-do-usuario.md) | [English](user-guide_EN.md)

Operating manual for the **Arandu Stack Macro Rail v1.0.0**.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Controls](#2-controls)
3. [Startup and Main Menu](#3-startup-and-main-menu)
4. [General Navigation](#4-general-navigation)
5. [STACK](#5-stack)
   - [5.1 MOVE](#51-move)
   - [5.2 SEQUENCE](#52-sequence)
   - [5.3 MOVEMENT](#53-movement)
   - [5.4 TIMING](#54-timing)
   - [5.5 SHOOT](#55-shoot)
   - [5.6 Execution and Cancellation](#56-execution-and-cancellation)
6. [BULB](#6-bulb)
7. [SLIDER](#7-slider)
   - [7.1 MOVE](#71-move)
   - [7.2 VIDEO](#72-video)
   - [7.3 LOOP](#73-loop)
   - [7.4 SLIDER CONFIG](#74-slider-config)
8. [CONFIG](#8-config)
9. [Limit Switches and Safety](#9-limit-switches-and-safety)
10. [Saved Settings](#10-saved-settings)
11. [Default Values](#11-default-values)
12. [Quick Workflows](#12-quick-workflows)

---

## 1. Introduction

The **Arandu Stack Macro Rail** is a motorized linear positioning system developed primarily for **macro photography, scientific photography, and automated focus stacking**.

The system controls camera movement along a motorized rail and allows positions, distances, speeds, timing parameters, and shooting sequences to be configured directly through its interface.

The system can also be used for continuous camera movement, timed shooting sequences, and long exposures.

Operation is performed through:

- 20×4 LCD display;
- rotary encoder with push button;
- A button;
- B button.

The firmware is organized into four main modes:

- **STACK** — positioning and automated focus stacking sequences;
- **BULB** — long-exposure control and timed shooting sequences;
- **SLIDER** — continuous and repetitive movement between defined positions;
- **CONFIG** — configuration of general movement and system calibration parameters.

### Reference system

The Arandu Stack Macro Rail uses **relative positioning**.

When the controller is powered on or restarted, the current carriage position is used as the system's initial reference.

The system **does not perform an automatic HOME routine**. Therefore, the position reference used by the firmware does not necessarily correspond to a physical end of the rail.

Points **A** and **B** are defined by the user during operation and are used as references by different STACK and SLIDER functions.

> **Important:** before starting any movement, make sure the carriage path is clear and that cables, the camera, accessories, or other components cannot mechanically restrict its travel.

---

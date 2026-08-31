# Arandu Stack Macro Rail — User Guide

[Português](guia-do-usuario.md) | [English](user-guide_EN.md)

Operating guide for the **Arandu Stack Macro Rail v1.0.0**.

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Controls](#2-controls)
   - [2.1 Rotary encoder](#21-rotary-encoder)
   - [2.2 Encoder button](#22-encoder-button)
   - [2.3 A and B buttons](#23-a-and-b-buttons)
   - [2.4 A and B points](#24-a-and-b-points)
3. [Startup and main menu](#3-startup-and-main-menu)
   - [3.1 Startup](#31-startup)
   - [3.2 Main menu](#32-main-menu)
   - [3.3 Battery indicator](#33-battery-indicator)
4. [General navigation](#4-general-navigation)
   - [4.1 Navigation](#41-navigation)
   - [4.2 Editing parameters](#42-editing-parameters)
   - [4.3 Returning](#43-returning)
   - [4.4 Cancelling a routine](#44-cancelling-a-routine)
5. [STACK](#5-stack)
   - [5.1 MOVE](#51-move)
   - [5.2 Defining A and B](#52-defining-a-and-b)
   - [5.3 SEQUENCE](#53-sequence)
   - [5.4 MOVEMENT](#54-movement)
   - [5.5 TIMING](#55-timing)
   - [5.6 SHOOT](#56-shoot)
   - [5.7 Stacking execution](#57-stacking-execution)
6. [BULB](#6-bulb)
   - [6.1 Parameters](#61-parameters)
   - [6.2 Execution](#62-execution)
7. [SLIDER](#7-slider)
   - [7.1 MOVE](#71-move)
   - [7.2 VIDEO](#72-video)
   - [7.3 LOOP](#73-loop)
   - [7.4 SLIDER CONFIG](#74-slider-config)
8. [CONFIG](#8-config)
   - [8.1 Steps/mm](#81-stepsmm)
   - [8.2 Travel limit](#82-travel-limit)
   - [8.3 Manual movement increments](#83-manual-movement-increments)
   - [8.4 Manual movement speeds](#84-manual-movement-speeds)
   - [8.5 Save](#85-save)
   - [8.6 Factory defaults](#86-factory-defaults)
9. [Limit switches and safety](#9-limit-switches-and-safety)
10. [Saved settings](#10-saved-settings)
11. [Default values](#11-default-values)
12. [Quick workflows](#12-quick-workflows)
   - [12.1 Focus stacking](#121-focus-stacking)
   - [12.2 Video slider](#122-video-slider)
   - [12.3 Repetitive movement](#123-repetitive-movement)
   - [12.4 Long exposure](#124-long-exposure)

---

## 1. Introduction

The **Arandu Stack Macro Rail** is a motorized linear positioning system developed primarily for **macro photography, scientific photography, and automated focus stacking**.

The system controls camera movement along a motorized rail and allows positions, distances, speeds, timing parameters, and shooting sequences to be configured directly through its interface.

The system also provides functions for:

- precision manual movement;
- continuous movement;
- motorized video slider operation;
- repetitive movement between two points;
- timed photography sequences;
- long exposures.

The interface uses:

- 20×4 LCD display;
- rotary encoder with push button;
- A button;
- B button.

The firmware is organized into four main operating modes:

- **STACK** — positioning and automated focus stacking sequences;
- **BULB** — long exposures and timed shooting sequences;
- **SLIDER** — continuous or repetitive movement between two points;
- **CONFIG** — calibration and configuration of general system parameters.

### Reference system

The Arandu Stack Macro Rail uses a **relative positioning system**.

When the controller is powered on or restarted, the current carriage position is defined as position **0**.

The system **does not perform an automatic HOME routine**. Therefore, position 0 does not necessarily correspond to a physical end of the rail.

Points **A** and **B** are defined by the user during each operating session and are used as references by STACK and SLIDER routines.

> **Important:** before starting any movement, make sure the carriage path is clear and that cables, the camera, accessories, or other components cannot mechanically restrict its travel.

---

## 2. Controls

### 2.1 Rotary encoder

The rotary encoder is the primary navigation control.

It has three functions:

- **rotate** — navigate menus or change values;
- **short press** — select items, enter or exit edit mode, and start specific functions;
- **long press** — return to the previous screen or cancel a running routine.

When **MOVE** is active, rotating the encoder also physically moves the carriage.

Each encoder increment moves the carriage according to the selected mode:

- **SLOW**;
- **MEDIUM**;
- **FAST**.

The corresponding movement increments and speeds can be changed in the **CONFIG** menu.

---

### 2.2 Encoder button

A short press selects the item indicated by the `>` cursor.

For editable parameters, the first press enters edit mode and the second press exits edit mode.

While editing, the symbol displayed at the beginning of the line changes from:

```text
>
```

to:

```text
*
```

A long press is recognized after approximately **800 ms**.

It is used to:

- leave a submenu;
- return to the previous menu;
- return to the main menu;
- cancel automatic routines in progress.

---

### 2.3 A and B buttons

The A and B buttons perform different functions depending on whether **MOVE** is active.

#### While MOVE is active

**Short press on A**

Stores the current position as point **A**.

**Short press on B**

Stores the current position as point **B**.

**Hold A for approximately 0.5 s**

Starts continuous movement in the A direction.

**Hold B for approximately 0.5 s**

Starts continuous movement in the B direction.

Movement continues only while the corresponding button remains pressed.

When the button is released, movement stops immediately, without a programmed deceleration ramp.

The movement speed is determined by the currently selected MOVE mode:

- SLOW;
- MEDIUM;
- FAST.

A long press used for movement **does not save point A or B when the button is released**.

If A and B are held simultaneously, the system does not start continuous movement.

#### While MOVE is not active

A short press on **A** moves the carriage to the previously defined A point.

A short press on **B** moves the carriage to the previously defined B point.

If the corresponding point has not yet been defined, no movement occurs.

---

### 2.4 A and B points

Points A and B define reference positions along the rail.

They are used to:

- establish the limits of a focus stacking sequence;
- calculate sequence distance;
- define the beginning and end of SLIDER movements;
- automatically move to previously stored positions.

Points A and B are independent of the system's position 0.

They **are not permanently stored in EEPROM**.

Whenever the controller is powered on or restarted:

- the current position becomes 0;
- point A is cleared;
- point B is cleared.

Therefore, A and B must be defined again for each operating session.

---

## 3. Startup and main menu

### 3.1 Startup

When the controller is powered on, the system initializes the display, inputs, motor control, and loads stored settings from EEPROM.

The LCD initially displays:

```text
ARANDU STACK V1
A CIENCIA CRESCE
QUANDO O SABER
CIRCULA
```

This screen remains visible for approximately 3 seconds.

The following message is then displayed:

```text
INICIANDO...
```

After startup, the main menu is shown.

During this process:

- no automatic movement occurs;
- no HOME routine is performed;
- the current position is set to 0;
- points A and B are cleared.

---

### 3.2 Main menu

The main menu contains four options:

```text
STACK
BULB
SLIDER
CONFIG
```

**STACK**

Configuration and execution of focus stacking sequences.

**BULB**

Control of long exposures and timed shutter sequences.

**SLIDER**

Continuous or repetitive movement between points A and B.

**CONFIG**

Calibration and configuration of general system parameters.

---

### 3.3 Battery indicator

The firmware includes a battery voltage monitoring function.

When the monitoring circuit is installed and correctly calibrated, the voltage is displayed in the upper-right corner of the LCD.

Example:

```text
11.8V
```

The reading is updated periodically.

When the measured voltage is equal to or below **10.5 V**, the value is replaced by:

```text
LOW
```

During continuous movement controlled by the A or B buttons, periodic battery updates are temporarily suspended to avoid small pauses caused by analog voltage measurements.

> Correct operation of this indicator depends on proper installation of the voltage monitoring circuit. Refer to the electrical documentation for details.

---

## 4. General navigation

### 4.1 Navigation

The symbol:

```text
>
```

indicates the currently selected item.

Example:

```text
>STACK
 BULB
 SLIDER
 CONFIG
```

Rotate the encoder to move through the available items and press it to select.

In the menus, the firmware uses:

- clockwise rotation — moves the selection upward;
- counterclockwise rotation — moves the selection downward.

When the first or last item is reached, navigation wraps around to the opposite end of the list.

---

### 4.2 Editing parameters

When an editable parameter is selected:

1. press the encoder;
2. the `>` symbol changes to `*`;
3. rotate the encoder to change the value;
4. press the encoder again to exit edit mode.

Example:

```text
*Vel:MEDIO
```

Not all values shown on the display are editable. Some are calculated automatically by the system.

---

### 4.3 Returning

Hold the encoder button for approximately **800 ms** to return.

Depending on the current screen, this command returns:

- from a submenu to the STACK or SLIDER menu;
- from STACK to the main menu;
- from SLIDER to the main menu;
- from BULB to the main menu;
- from CONFIG to the main menu.

---

### 4.4 Cancelling a routine

During an automatic routine, hold the encoder button to cancel it.

When cancellation is recognized, the system:

- interrupts the routine;
- stops movement;
- releases the camera shutter output;
- clears the execution state;
- returns to the main menu.

The LCD briefly displays:

```text
CANCELADO
Rotina parada
```

The encoder button must be released before a new press can be recognized.

---

## 5. STACK

The **STACK** mode controls preparation and execution of automated focus stacking sequences.

When STACK is opened, five submenus are available:

```text
MOVER
SEQUENCIA
MOVIMENTO
TEMPOS
FOTOGRAFAR
```

The interface labels remain in Portuguese because they correspond directly to the labels displayed by the firmware.

---

### 5.1 MOVE

The MOVER submenu is used to manually position the camera and define points A and B.

The screen contains:

```text
Vel:
Mover:
A:        B:
```

#### Vel

Selects one of the three movement modes:

- **LENTO**;
- **MEDIO**;
- **RAPIDO**.

To change it:

1. select `Vel`;
2. press the encoder;
3. rotate to select a mode;
4. press again to exit edit mode.

#### Mover

Select `Mover` and press the encoder to activate manual movement.

With Mover active, rotating the encoder moves the carriage.

Each encoder increment uses:

- the movement increment configured for the current mode;
- the speed configured for the current mode.

Press the encoder again to leave active Mover mode.

The value shown in `Mover` represents the current relative position, displayed in micrometers.

---

### 5.2 Defining A and B

With **MOVER active**, position the carriage at the first desired limit.

Briefly press:

```text
A
```

The current position is stored as point A.

Move the carriage to the other limit and briefly press:

```text
B
```

The current position is stored as point B.

Continuous movement can also be used:

- hold A to move in the A direction;
- hold B to move in the B direction;
- release the button to stop;
- then use a short press to store the position.

The A and B values are shown on the last line of the MOVER screen.

In STACK, they are displayed in micrometers.

> A and B represent positions. They do not need to correspond to the physical ends of the rail.

---

### 5.3 SEQUENCE

The SEQUENCIA submenu displays:

```text
Fotos:
Dist:
Passo:
```

#### Fotos

Number of photographs calculated automatically by the system.

This field is read-only.

#### Dist

Absolute distance between A and B.

This field is read-only and displayed in millimeters.

#### Passo

Nominal distance between consecutive photographs.

This is the editable sequence parameter.

The value is shown in micrometers and can be adjusted in **10 µm** increments.

Minimum configurable value:

```text
10 µm
```

When Passo is changed, the number of photographs is recalculated automatically from the A–B distance.

The firmware relationship is generally:

```text
Photos = (Distance / Step) + 1
```

using the internal motor-step conversion and integer division.

Therefore, when the A–B distance is not exactly divisible by the selected step, the final photograph may be taken before reaching point B, or point A when moving in the opposite direction.

---

### 5.4 MOVEMENT

The MOVIMENTO submenu controls sequence direction and post-sequence behavior.

It displays:

```text
Dir:
Ret:
```

#### Dir

Defines the direction:

```text
A>B
```

or:

```text
B>A
```

With `A>B`, the routine starts at A and moves toward B.

With `B>A`, it starts at B and moves toward A.

#### Ret

Defines what happens after the final photograph.

Options:

```text
Nao
A
B
```

**Nao**

The carriage remains where the sequence ended.

**A**

The carriage returns to point A.

**B**

The carriage returns to point B.

---

### 5.5 TIMING

The TEMPOS submenu contains four parameters:

```text
Atraso:
Disp:
PosFoto:
Estab:
```

#### Atraso

Delay before the routine begins.

Adjustment increment:

```text
500 ms
```

Minimum:

```text
0 ms
```

#### Disp

Time during which the shutter output remains active for each photograph.

Adjustment increment:

```text
50 ms
```

Minimum:

```text
50 ms
```

#### PosFoto

Delay after the shutter activation.

Adjustment increment:

```text
100 ms
```

Minimum:

```text
0 ms
```

This delay allows the camera to complete operations associated with the capture before the next movement.

#### Estab

Delay after each movement and before the next photograph.

Adjustment increment:

```text
100 ms
```

Minimum:

```text
0 ms
```

This interval can be used to allow the camera and rail assembly to mechanically settle after movement.

---

### 5.6 SHOOT

The FOTOGRAFAR submenu displays a sequence summary:

- number of photographs;
- step size in micrometers;
- point A;
- point B.

The final line shows:

```text
>INICIAR
```

Press the encoder to start.

The routine only starts if:

- A has been defined;
- B has been defined;
- A and B are different positions.

Otherwise, an error message is displayed.

---

### 5.7 Stacking execution

When the routine starts, the system performs the following sequence:

1. waits for the configured `Atraso`;
2. moves the carriage to the starting point defined by `Dir`;
3. takes the first photograph;
4. waits for `PosFoto`;
5. moves the carriage by the configured `Passo`;
6. waits for `Estab`;
7. takes the next photograph;
8. repeats until the calculated number of photographs is completed;
9. performs the behavior configured in `Ret`.

During execution, the display shows sequence progress and allows cancellation by holding the encoder button.

When completed normally, the system displays a completion message and returns to the FOTOGRAFAR screen.

---

## 6. BULB

The **BULB** mode directly controls the camera shutter output and does not depend on points A and B.

It can be used for long exposures and timed shooting sequences.

The menu contains:

```text
Fotos:
Bulb:
PosFoto:
Atraso:
Intervalo:
Iniciar
```

---

### 6.1 Parameters

#### Fotos

Number of exposures in the sequence.

Range:

```text
1 to 999
```

#### Bulb

Time during which the shutter output remains active.

Adjustment increment:

```text
1 second
```

Minimum:

```text
1 second
```

#### PosFoto

Delay after each exposure.

Adjustment increment:

```text
100 ms
```

Minimum:

```text
0 ms
```

#### Atraso

Delay before the first exposure.

Adjustment increment:

```text
500 ms
```

Minimum:

```text
0 ms
```

#### Intervalo

Additional delay between one photograph and the next.

Adjustment increment:

```text
1 second
```

Minimum:

```text
0 s
```

---

### 6.2 Execution

Select:

```text
Iniciar
```

and press the encoder.

The system:

1. waits for `Atraso`;
2. activates the camera shutter output;
3. keeps it active for the configured `Bulb` time;
4. releases the output;
5. waits for `PosFoto`;
6. if another photograph remains, waits for `Intervalo`;
7. repeats until the configured number of `Fotos` is completed.

Rail movement is not part of the BULB routine.

The routine can be cancelled by holding the encoder button.

---

## 7. SLIDER

The **SLIDER** mode uses points A and B to perform continuous or repetitive movements.

It contains four submenus:

```text
MOVER
VIDEO
LOOP
CONFIG SLIDER
```

---

### 7.1 MOVE

Operation is equivalent to the MOVER submenu in STACK.

It allows the user to:

- select LENTO, MEDIO, or RAPIDO;
- move the carriage using the encoder;
- hold A or B for continuous movement;
- store A and B with short button presses.

In SLIDER, A and B positions are displayed in **millimeters**.

The A and B points used by STACK and SLIDER are the same. There are no separate A/B sets for each operating mode.

---

### 7.2 VIDEO

The VIDEO submenu performs one continuous movement between A and B.

The screen displays:

```text
Iniciar
Dir:
Vel:
```

#### Iniciar

Starts the movement.

#### Dir

Selects:

```text
A>B
```

or:

```text
B>A
```

The screen also displays the distance between A and B.

#### Vel

Movement speed in millimeters per second.

Range:

```text
0.05 to 10.00 mm/s
```

Increment:

```text
0.05 mm/s
```

#### Execution

When started:

1. the system verifies that A and B are defined and different;
2. moves the carriage to the initial point selected by the direction;
3. waits for the delay configured in CONFIG SLIDER;
4. moves to the final point using the configured SLIDER speed and acceleration;
5. ends the routine.

Movement to the starting point uses the system's general fast movement speed. SLIDER speed is applied to the main movement between A and B.

---

### 7.3 LOOP

LOOP performs repeated back-and-forth cycles between A and B.

The screen displays:

```text
Iniciar
Ciclos:
Vel:
Pausa:
```

#### Ciclos

Number of complete cycles.

Range:

```text
1 to 999
```

One cycle corresponds to:

```text
start → end → start
```

The starting position depends on the direction configured for SLIDER.

#### Vel

Movement speed between the endpoints.

Range:

```text
0.05 to 10.00 mm/s
```

Increment:

```text
0.05 mm/s
```

#### Pausa

Delay at the endpoints.

Adjustment increment:

```text
100 ms
```

Minimum:

```text
0 ms
```

#### Execution

When started:

1. the carriage moves to the starting point;
2. waits for the configured delay;
3. moves to the final point;
4. waits for the pause;
5. returns to the starting point;
6. if another cycle remains, waits again;
7. repeats until the configured number of cycles is completed.

At the end, the carriage remains at the starting point.

---

### 7.4 SLIDER CONFIG

The CONFIG SLIDER submenu contains:

```text
Vel:
Acel:
Atraso:
```

#### Vel

Speed used for the main SLIDER movements.

Range:

```text
0.05 to 10.00 mm/s
```

Increment:

```text
0.05 mm/s
```

The same value can also be adjusted directly in the VIDEO and LOOP submenus.

#### Acel

Acceleration used by SLIDER movement.

Range:

```text
10 to 3000 steps/s²
```

Increment:

```text
10 steps/s²
```

#### Atraso

Delay after the carriage reaches the starting position and before the main movement begins.

Range:

```text
0 to 300 seconds
```

Increment:

```text
1 second
```

This delay can be used, for example, to allow the operator to start video recording before the slider begins moving.

---

## 8. CONFIG

The **CONFIG** menu contains the general calibration and movement parameters.

The available items are:

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

### 8.1 Steps/mm

Defines how many internal controller steps correspond to 1 mm of linear travel.

This parameter affects all conversions between:

- steps;
- micrometers;
- millimeters;
- speeds in mm/s.

Adjustment increment:

```text
10 steps/mm
```

Minimum:

```text
1 step/mm
```

The default setting for firmware v1.0.0 is:

```text
800 steps/mm
```

> Changing this value changes the dimensional calibration of the entire system. Modify it only when required to match the mechanical configuration and microstepping used.

---

### 8.2 Travel limit

Defines the relative logical limit allowed for movement destinations.

The system operates around the position 0 reference created during startup, allowing both positive and negative coordinates within the configured limit.

This parameter **does not automatically measure the physical rail travel** and does not replace the limit switches.

Internally, the value is adjusted in increments of 100 steps and displayed in the interface as millimeters according to the current `Passos/mm` calibration.

> The logical limit should be configured to match the mechanical assembly being used.

---

### 8.3 Manual movement increments

The parameters:

```text
MovL
MovM
MovR
```

define the distance moved by each encoder increment while MOVER is active.

#### MovL

Movement increment for LENTO mode.

Range:

```text
1 to 1000 µm
```

Increment:

```text
1 µm
```

#### MovM

Movement increment for MEDIO mode.

Range:

```text
10 to 5000 µm
```

Increment:

```text
10 µm
```

#### MovR

Movement increment for RAPIDO mode.

Range:

```text
100 to 20000 µm
```

Increment:

```text
100 µm
```

---

### 8.4 Manual movement speeds

The parameters:

```text
VelL
VelM
VelR
```

define the speed used by the three manual movement modes.

#### VelL

Speed for LENTO mode.

Range:

```text
0.05 to 2.00 mm/s
```

Increment:

```text
0.05 mm/s
```

#### VelM

Speed for MEDIO mode.

Range:

```text
0.10 to 10.00 mm/s
```

Increment:

```text
0.10 mm/s
```

#### VelR

Speed for RAPIDO mode.

Range:

```text
0.50 to 30.00 mm/s
```

Increment:

```text
0.50 mm/s
```

---

### 8.5 Save

Changes made to parameters remain active during the current session.

To store the settings permanently, select:

```text
Salvar
```

The system writes the configurable parameters to EEPROM and displays:

```text
EEPROM
SALVA
```

These settings are automatically loaded during the next startup.

---

### 8.6 Factory defaults

The option:

```text
Fabrica
```

restores the default values defined in firmware v1.0.0.

When selected, the system displays:

```text
PADRAO
RESTAURADO
```

The default values are applied and written to EEPROM.

---

## 9. Limit switches and safety

The Arandu Stack Macro Rail can use two physical limit switches:

- initial limit;
- final limit.

They are used **only as safety devices**.

The firmware does not use these switches to:

- perform HOME;
- automatically define position 0;
- measure the rail travel.

When a limit switch is activated, the system blocks movements that would continue in that direction.

Movement in the opposite direction remains possible, allowing the carriage to move away from the limit.

### Wiring

The firmware is designed for **normally closed (NC)** limit switches using `INPUT_PULLUP`.

During normal operation:

```text
input → NC contact → GND
```

With the contact closed, the input remains LOW.

When the limit switch is activated and the contact opens, the input becomes HIGH through the internal pull-up and the firmware interprets the switch as active.

### Operation without limit switches

The limit switches are optional.

However, if they are not installed, **both corresponding inputs must be connected to GND using jumpers**.

Do not leave these inputs disconnected.

A disconnected input will be held HIGH by `INPUT_PULLUP` and may be interpreted as an activated limit switch, blocking movement.

Also refer to:

```text
docs/electronics/electrical-system.md
```

for the complete electrical connection instructions.

### Mechanical safety

Before operating the system:

- make sure the carriage can travel through the intended region without collisions;
- check all cables connected to the camera;
- verify that the camera and accessories are securely mounted;
- do not rely on the logical travel limit as the only collision protection;
- use physical limit switches when additional protection is required;
- avoid configuring speeds or accelerations that are incompatible with the mechanical assembly.

---

## 10. Saved settings

The system uses the controller EEPROM to store configuration data.

Stored parameters include:

- steps per millimeter;
- logical travel limit;
- LENTO, MEDIO, and RAPIDO movement increments;
- LENTO, MEDIO, and RAPIDO speeds;
- STACK parameters;
- STACK direction and return behavior;
- BULB parameters;
- SLIDER parameters;
- SLIDER speed and acceleration;
- LOOP cycles and pause;
- SLIDER delay.

To save changes made during operation, use:

```text
CONFIG → Salvar
```

### Data that is not saved

The points:

```text
A
B
```

are not stored in EEPROM.

The current relative position is also not preserved after restart.

Whenever the system is powered on:

```text
current position = 0
A = undefined
B = undefined
```

This prevents physical positions from a previous operating session from being reused automatically.

---

## 11. Default values

The factory reset function in firmware v1.0.0 uses the following values.

### System

| Parameter | Default value |
|---|---:|
| Steps/mm | 800 |
| Logical limit | 50000 steps |
| Initial MOVER mode | MEDIO |

### Manual movement

| Parameter | Default value |
|---|---:|
| MovL | 10 µm |
| MovM | 250 µm |
| MovR | 4000 µm |
| VelL | 0.25 mm/s |
| VelM | 2.00 mm/s |
| VelR | 20.00 mm/s |

### STACK

| Parameter | Default value |
|---|---:|
| Photos | 20 |
| Initial internal step | 80 steps |
| Atraso | 2.0 s |
| Disp | 500 ms |
| PosFoto | 3.0 s |
| Estab | 500 ms |
| Direction | A>B |
| Return | Nao |

With the default calibration of 800 steps/mm, 80 internal steps correspond to approximately:

```text
100 µm
```

The number of photographs is recalculated when the sequence step is changed after A and B are defined.

### BULB

| Parameter | Default value |
|---|---:|
| Photos | 1 |
| Bulb | 5.0 s |
| PosFoto | 500 ms |
| Atraso | 2.0 s |
| Intervalo | 2.0 s |

### SLIDER

| Parameter | Default value |
|---|---:|
| Direction | A>B |
| Speed | 0.50 mm/s |
| Acceleration | 300 steps/s² |
| Cycles | 1 |
| Pause | 1.0 s |
| Delay | 10.0 s |

> The values shown in this section correspond to the defaults defined in firmware v1.0.0. Settings stored by the user in EEPROM override these values during startup.

---

## 12. Quick workflows

This section summarizes the most common procedures.

---

### 12.1 Focus stacking

#### 1. Position and define A

Open:

```text
STACK → MOVER
```

Select the desired movement mode.

Activate `Mover`.

Position the camera at the first sequence limit using the encoder or by holding the A/B buttons.

Briefly press **A** to store point A.

#### 2. Position and define B

Move the camera to the other sequence limit.

Briefly press **B** to store point B.

#### 3. Define the step

Open:

```text
STACK → SEQUENCIA
```

Edit:

```text
Passo
```

The system automatically calculates the distance and number of photographs.

#### 4. Define the direction

Open:

```text
STACK → MOVIMENTO
```

Select:

```text
A>B
```

or:

```text
B>A
```

Also configure the desired return behavior:

```text
Nao
A
B
```

#### 5. Configure timing

Open:

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

#### 6. Start

Open:

```text
STACK → FOTOGRAFAR
```

Check the displayed values and select:

```text
INICIAR
```

---

### 12.2 Video slider

#### 1. Define A and B

Open:

```text
SLIDER → MOVER
```

Position and store both limits using the A and B buttons.

#### 2. Configure movement

Open:

```text
SLIDER → VIDEO
```

Configure:

```text
Dir
Vel
```

If necessary, also open:

```text
SLIDER → CONFIG SLIDER
```

to configure:

```text
Acel
Atraso
```

#### 3. Start

Select:

```text
Iniciar
```

The carriage first moves to the starting position, waits for the configured delay, and then performs the main movement to the opposite endpoint.

---

### 12.3 Repetitive movement

Define A and B in:

```text
SLIDER → MOVER
```

Then open:

```text
SLIDER → LOOP
```

Configure:

```text
Ciclos
Vel
Pausa
```

If necessary, adjust:

```text
SLIDER → CONFIG SLIDER
```

and then select:

```text
Iniciar
```

Each cycle corresponds to one complete outward and return movement.

---

### 12.4 Long exposure

Open:

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

Select:

```text
Iniciar
```

The system performs the shutter sequence without moving the rail.

---

## Emergency cancellation during a routine

During STACK, BULB, VIDEO, or LOOP, hold the encoder button to cancel the routine.

The system stops execution and returns to the main menu.

If there is a risk of mechanical collision, control failure, or unexpected behavior, disconnect system power.

---

## Related documentation

For component information:

```text
docs/materials.md
```

For mechanical assembly:

```text
docs/assembly/instructions.md
```

For electrical assembly and connections:

```text
docs/electronics/electrical-system.md
```

For the firmware:

```text
firmware/Arandu_Stack_Macro_Rail.ino
```

---

**Arandu Stack Macro Rail — Firmware v1.0.0**

Project and firmware: **Pedro José Vieira de Souza**

Academic citation: **SOUZA, P. J. V.**

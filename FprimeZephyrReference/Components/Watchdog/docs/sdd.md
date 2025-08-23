# Components::Watchdog Component

## 1. Introduction

The `Components::Watchdog` component provides the mechanism to "pet" the physical watchdog circuit on the PROVES FC Board and provides a visual indicator by blinking an LED at a fixed interval. The component is driven by a rate group and oscillates the watchdog GPIO every rategroup tick. 

## 2. Requirements

The requirements for `Components::Watchdog` are as follows:

Requirement | Description | Verification Method
----------- | ----------- | -------------------
WD-001 | The `Components::Watchdog` component shall activate upon startup. | Unit Test
WD-002 | The `Components::Watchdog` component shall oscillate the watchdog GPIO pin (24) on/off on each rategroup tick. | Unit Test
WD-003 | The `Components::Watchdog` component shall provide telemetry for watchdog transition count. | Unit Test
WD-004 | The `Components::Watchdog` component shall respond to stop signals to halt the watchdog petting. | Unit Test
WD-005 | The `Components::Watchdog` component shall provide a test command to stop the watchdog petting. | Unit Test
WD-006 | The `Components::Watchdog` component shall emit an event when the watchdog petting stops. | Unit Test

## 3. Design

### 3.1 Context

#### 3.1.1 Component Diagram

The `Components::Watchdog` component has the following component diagram:

![`Components::Watchdog` Diagram](img/diagram.svg)

#### 3.1.2 Ports

Port Data Type | Name | Direction | Kind | Usage
-------------- | ---- | --------- | ---- | -----
[`Svc::Sched`]| run | Input | Synchronous | Receive periodic calls from rate group
[`Fw::Signal`]| stop | Input | Synchronous | Receive stop signal to stop watchdog petter
[`Drv::GpioWrite`]| gpioSet | Output | n/a | Control GPIO state through driver

#### 3.1.3 Commands

Name | Kind | Description 
---- | ---- | -----
TEST_STOP_WATCHDOG | Synchronous | calls the port `stop_runhandler` to stop the watchdog petter. 

#### 3.1.4 Events

Name | Description 
---- | -----
WatchdogStop | Emits once the watchdog petting has stopped. . 

#### 3.1.5 Telemetry 

Name | Type | Description 
---- | ---- | -----
WatchdogTransitions | U32 | Number of times the GPIO has oscillated from on/off during watchdog petting

## 4. Unit Testing

TODO
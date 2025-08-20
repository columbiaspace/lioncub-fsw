# Proves Core Reference Project

This is a reference software implementation for the [Proves Kit](https://docs.proveskit.space/en/latest/). 

## System Requirements
- F Prime System Requirements listed [here](https://fprime.jpl.nasa.gov/latest/docs/getting-started/installing-fprime/#system-requirements)
- Zephyr dependencies listed [here](https://docs.zephyrproject.org/latest/develop/getting_started/index.html#install-dependencies) (NOTE: Only complete the install dependencies step, as we run through the rest of the steps in this readme.)

## Installation

> [!TIP]
> Always source the virtual environment when building by running `. fprime-venv/bin/activate` in the `proves-core-reference` directory,

First, clone the Proves Core Reference repository and ensure all submodules are properly checked-out. 

```
fprime-bootstrap clone https://github.com/Open-Source-Space-Foundation/proves-core-reference
```

By using `fprime-bootstrap` the following several tasks are accomplished:

- The repository and submodules are cloned
-  A virtual environment is created and depenencies are installed

Next update Zephyr modules.  This will take a long time.

```
cd proves-core-reference/lib/zephyr-workspace
west update
```

Export a Zephyr CMake package. This allows CMake to automatically load boilerplate code required for building Zephyr applications.

```
west zephyr-export
```

The Zephyr west extension command, west packages can be used to install Python dependencies.

```
west packages pip --install
```

Finally, install the Zephyr SDK.

```
west sdk install
```

## Running the code

if its the first time or you are updating and adding components and ports, run generate from the `proves-core-reference` directory. When you regenerate append a -f, this will purge the previous deployment
```
fprime-util generate
```

Then, and everytime you change code, run

```
fprime-util build
```

Next, plug in your board! You want to find the location of the board on your computer. It should be called something like RP2350 but you want to find the path to to

For Mac:
```
ls -lah /Volumes
```


For Windows:
Check the letter said to be the mount (ex D) 

For Linux:
```
findmnt
```


Now you want to copy the code from the deployment we just made. Before you run this command you have to make this board writable by pressing the two buttons in succesion 
```
cp build-fprime-automatic-zephyr/zephyr/zephyr.uf2 [path-to-your-board]
```

Finally, run the fprime-gds. You dont have to start and trop it everytime you 
```
fprime-gds -n -–dictionary ./build-fprime-automatic-zephyr/FPrimeZephyrReference/ReferenceDeployment/Top/ReferenceDeploymentTopologyDictionary.json -–communication-selection uart –-uart-baud 115200
```


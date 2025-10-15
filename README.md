# LionCub Flight Software

This is based on the [Proves Kit](https://docs.proveskit.space/en/latest/).

## System Requirements
- F Prime System Requirements listed [here](https://fprime.jpl.nasa.gov/latest/docs/getting-started/installing-fprime/#system-requirements)
- Zephyr dependencies listed [here](https://docs.zephyrproject.org/latest/develop/getting_started/index.html#install-dependencies) (NOTE: Only complete the install dependencies step, as we run through the rest of the steps in this readme.)

## Installation

First, clone the Proves Core Reference repository.

```shell
git clone https://github.com/columbiaspace/lioncub-fsw
```

> [!Note]
> Before proceeding to the next step, you need to have the following dependencies installed: `cmake ninja gperf python3 python-tk ccache qemu dtc libmagic wget openocd`. If you are on macOS, you can install these using the following command: `brew install cmake ninja gperf python3 python-tk ccache qemu dtc libmagic wget openocd`.

Next, navigate to the `lioncub-fsw` directory and run `make` to set up the project.

```shell
cd lioncub-fsw
make
```

## Running the code

Run generate from the `lioncub-fsw` directory. This generates the build cache for FPrime. You only need to do generate if something in the core FPrime package has changed
```shell
make generate
```

Then, and every time you change code, run

```shell
make build
```

### Find the path to your board

Next, plug in your board! If you have previously installed a firmware on your board you may not see it show up as a drive. In that case you'll want to put the board into boot loader mode. Then you'll be able to find the location of the board on your computer. It should be called something like RP2350 but you want to find the path to it

For Mac:
```shell
ls -lah /Volumes
```

For Windows:
Check the letter said to be the mount (ex /d/) and then the name of the removable drive (ex /d/RP2350)

For Linux:
```shell
findmnt
```

Now you want to install the firmware to the board.
```shell
cp build-artifacts/zephyr.uf2 [path-to-your-board]
```

Finally, run the fprime-gds.
```shell
make gds
```

## Running Integration Tests

First, start GDS with:
```sh
make gds
```

Then, in another terminal, run the following command to execute the integration tests:
```sh
make test-integration
```

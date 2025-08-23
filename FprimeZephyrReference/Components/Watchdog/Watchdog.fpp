module Components {
    @ Component to blink an LED as a watchdog petter, driven by a rate group
    passive component Watchdog {

        @ Command to stop the watchdog petter
        sync command TEST_STOP_WATCHDOG(
        )

        @ Telemetry channel counting watchdog petter transitions
        telemetry WatchdogTransitions: U32

        @ Event logged when the watchdog petter LED turns on or off
        event WatchdogStop() \
            severity activity high \
            format "Watchdog no longer being pet!"

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port to stop the watchdog petting
        sync input port stop: Fw.Signal

        @ Port sending calls to the GPIO driver
        output port gpioSet: Drv.GpioWrite

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

    }
}
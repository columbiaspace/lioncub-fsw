module Components {
    @ Component to blink an LED as a watchdog petter, driven by a rate group
    passive component Watchdog {

        @ Command to stop the watchdog petter
        sync command STOP_WATCHDOG(
        )

        @ Telemetry channel to report watchdog petter state.
        telemetry WatchdogState: Fw.On

        @ Telemetry channel counting watchdog petter transitions
        telemetry WatchdogTransitions: U64

        @ Reports the state we set for the watchdog petter.
        event SetWatchdogState($state: Fw.On) \
            severity activity high \
            format "Set watchdog state to {}."

        @ Event logged when the watchdog petter LED turns on or off
        event WatchdogState(onOff: Fw.On) \
            severity activity low \
            format "Watchdog is {}"

        @ Event logged when the watchdog petter blink interval is updated
        event WatchdogIntervalSet(interval: U32) \
            severity activity high \
            format "Watchdog blink interval set to {}"

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
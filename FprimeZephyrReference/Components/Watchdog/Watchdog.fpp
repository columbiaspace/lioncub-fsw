module Components {
    @ Component to blink an LED as a watchdog petter, driven by a rate group
    passive component Watchdog {

        @ Command to turn on or off the watchdog petter LED
        sync command BLINKING_ON_OFF(
                onOff: Fw.On @< Indicates whether the blinking should be on or off
        )

        @ Telemetry channel to report watchdog petter state.
        telemetry BlinkingState: Fw.On

        @ Telemetry channel counting watchdog petter transitions
        telemetry LedTransitions: U64

        @ Reports the state we set for the watchdog petter.
        event SetBlinkingState($state: Fw.On) \
            severity activity high \
            format "Set blinking state to {}."

        @ Event logged when the watchdog petter LED turns on or off
        event LedState(onOff: Fw.On) \
            severity activity low \
            format "LED is {}"

        @ Event logged when the watchdog petter blink interval is updated
        event BlinkIntervalSet(interval: U32) \
            severity activity high \
            format "LED blink interval set to {}"

        @ Watchdog petter blinking interval in rate group ticks
        param BLINK_INTERVAL: U32 default 10

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

        @ Port to return the value of a parameter
        param get port prmGetOut

        @ Port to set the value of a parameter
        param set port prmSetOut

    }
}
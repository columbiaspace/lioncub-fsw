module Components {
    @ Component that delivers data from the VEML 6031 using the zephyr driver
    passive component LightSensorManager {

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"
        
        # Event to report if light is detected
        event LightDetected(
            lux : I32 @<Measured Light Level in Lux>
        ) severity activity high format "Light detected: {} lux";

        # Event to report if light sensor is turned on
        event LightSensorTurnedOn() severity activity high format "Light sensor turned on";

        # Event to report if light sensor is turned off
        event LightSensorTurnedOff() severity activity high format "Light sensor turned off";

        # Event to report if light sensor reset
        event LightSensorReset() severity activity high format "Light sensor reset";

        # Event to report if light sensor entered to error state
        event LightSensorError(
            error_msg: string size 40 @<Error message to output>
        ) severity warning high format "Light sensor error: {}";

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

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

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}
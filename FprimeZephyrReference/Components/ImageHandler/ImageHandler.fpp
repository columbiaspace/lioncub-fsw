module Components {
    @ Handles Images, including saving different sizes and downlinking
    active component ImageHandler {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @Delete specified image
        async command delete(imageId: U32)

        @Downlink an image
        async command downlink(imageId: U32, imageSize: U8)

        @List all images
        async command list()

        @Failed to open dir
        event OpenDirError severity warning high format "Deirectory failed to open"
        
        @Failed to open file
        event FileOpenError severity warning high format "File failed to open"

        @Failed to write to file
        event FileWriteError severity warning high format "File failed to write"

        @List entry for ls
        event ListImage() severity activity high format "File failed to write"

        @Image received
        event ReceivedImage() severity activity high format "Image received"

        @Downlink request received
        event ReceivedDownlinkRequest() severity activity high format "Downlink request received"

        @Processed Image
        event ProcessImage() severity activity high format "Processing image"

        @Confirm Image deletion status
        event Confirmation(status: U32) severity activity high format "Image confirmation with status {}"

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

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

        @ Port to set the value of a parameter
        param set port prmSetOut

        @ Port to receive images
        sync input port ImageRec: Fw.BufferSend
    }
}
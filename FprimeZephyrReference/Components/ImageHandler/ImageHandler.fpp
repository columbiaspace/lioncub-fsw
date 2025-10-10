module Components {
    @ Receives images from the camera, and stores them on the file system for later use
    active component ImageHandler {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @ TODO
        async command TODO opcode 0

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

        @Port to set the value of a parameter
        param set port prmSetOut

        @Port to receive img data

	@Port to send a file
	output port sendFile: Fw.BufferSend

	@Port to receive a file
	input port receiveFile: Fw.BufferReceive

	@ Port to receive image from the camera
	input port imageReceive: Fw.BufferReceive


	###############################################################################
        # Parameters 
        ###############################################################################        

	@Halfsize image
	param midSize: U32

	@Smallest image
	param smallSize: U32

	###############################################################################
        # Commands
        ###############################################################################
	
	@Delete specified image
	async command delete(imageId: U32)

	@Downlink an image
	async command downlink(imageId: U32, imageSize: U8)

	@List all images
	async command list()

	###############################################################################
        # Events
        ###############################################################################

	@Image received
	event ReceivedImage() severity activity high format "Image received"

	@Downlink request received
	event ReceivedDownlinkRequest() severity activity high format "Downlink request received"

	@Processed Image
	event ProcessImage() severity activity high format "Processing image"

	@Confirm Image deletion status
	event Confirmation(status: U32) severity avtivity high format "Image confirmation with status {}"

        ###############################################################################
        # Telemetry
        ###############################################################################
	
	@Total space used
	temetry TotalSize: U32

	@Number of images currently stored
	telemetry NumberOfCurrentImages: U32

	@Total number of images taken
	telemetry TotalImagesTaken: U32

    }
}

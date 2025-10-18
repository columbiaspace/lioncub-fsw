module ReferenceDeployment {

  # ----------------------------------------------------------------------
  # Base ID Convention
  # ----------------------------------------------------------------------
  #
  # All Base IDs follow the 8-digit hex format: 0xDSSCCxxx
  #
  # Where:
  #   D   = Deployment digit (1 for this deployment)
  #   SS  = Subtopology digits (00 for main topology, 01-05 for subtopologies)
  #   CC  = Component digits (00, 01, 02, etc.)
  #   xxx = Reserved for internal component items (events, commands, telemetry)
  #

  # ----------------------------------------------------------------------
  # Defaults
  # ----------------------------------------------------------------------

  module Default {
    constant QUEUE_SIZE = 10
    constant STACK_SIZE = 8 * 1024 # Must match prj.conf thread stack size
  }

  # ----------------------------------------------------------------------
  # Active component instances
  # ----------------------------------------------------------------------

  instance rateGroup10Hz: Svc.ActiveRateGroup base id 0x10001000 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 3

  instance rateGroup1Hz: Svc.ActiveRateGroup base id 0x10002000 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 4

  instance prmDb: Svc.PrmDb base id 0x10003000 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 6

  instance imageHandler: Components.ImageHandler base id 0x10004000 \
    queue size Default.QUEUE_SIZE \
    stack size Default.STACK_SIZE \
    priority 5


  # ----------------------------------------------------------------------
  # Queued component instances
  # ----------------------------------------------------------------------


  # ----------------------------------------------------------------------
  # Passive component instances
  # ----------------------------------------------------------------------

  instance chronoTime: Svc.ChronoTime base id 0x10010000

  instance rateGroupDriver: Svc.RateGroupDriver base id 0x10011000

  instance version: Svc.Version base id 0x10012000

  instance timer: Zephyr.ZephyrRateDriver base id 0x10013000

  instance comDriver: Zephyr.ZephyrUartDriver base id 0x10014000

  instance gpioDriver: Zephyr.ZephyrGpioDriver base id 0x10015000

  instance watchdog: Components.Watchdog base id 0x10016000

  instance imuManager: Components.ImuManager base id 0x10017000

  instance lis2mdlManager: Drv.Lis2mdlManager base id 0x10018000

  instance lsm6dsoManager: Drv.Lsm6dsoManager base id 0x10019000
}

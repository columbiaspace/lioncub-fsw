// ======================================================================
// \title  Watchdog.cpp
// \author moisesmata
// \brief  cpp file for Watchdog component implementation class
// ======================================================================

#include "FprimeZephyrReference/Components/Watchdog/Watchdog.hpp"
#include "config/FpConfig.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Watchdog ::Watchdog(const char* const compName) : WatchdogComponentBase(compName) {}

Watchdog ::~Watchdog() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Watchdog ::run_handler(FwIndexType portNum, U32 context) {
    // Only perform actions when stop not requested
    if (!this->m_stopRequested) {
        // Toggle state every rate group call
        this->m_state = (this->m_state == Fw::On::ON) ? Fw::On::OFF : Fw::On::ON;
        this->m_transitions++;
        this->tlmWrite_WatchdogTransitions(this->m_transitions);

        this->gpioSet_out(0, (Fw::On::ON == this->m_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);

        this->log_ACTIVITY_LO_WatchdogState(this->m_state);
    }
}

void Watchdog ::stop_handler(FwIndexType portNum) {
    // Set the stop flag to stop watchdog petting
    this->m_stopRequested = true;
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

//test
void Watchdog ::STOP_WATCHDOG_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    // Set the stop flag to stop watchdog petting
    this->m_stopRequested = true;

    //rather, call stop handler here and emit event`
    // Provide command response
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components
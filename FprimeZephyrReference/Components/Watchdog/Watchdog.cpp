// ======================================================================
// \title  Watchdog.cpp
// \author ortega
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
        // If toggling state
        if (this->m_toggleCounter == 0) {
            // Toggle state
            this->m_state = (this->m_state == Fw::On::ON) ? Fw::On::OFF : Fw::On::ON;
            this->m_transitions++;
            this->tlmWrite_WatchdogTransitions(this->m_transitions);

            // Port may not be connected, so check before sending output
            if (this->isConnected_gpioSet_OutputPort(0)) {
                this->gpioSet_out(0, (Fw::On::ON == this->m_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);
            }

            this->log_ACTIVITY_LO_WatchdogState(this->m_state);
        }

        this->m_toggleCounter = (this->m_toggleCounter + 1);
    }
    // If stop requested, turn off LED
    else {
        if (this->m_state == Fw::On::ON) {
            // Port may not be connected, so check before sending output
            if (this->isConnected_gpioSet_OutputPort(0)) {
                this->gpioSet_out(0, Fw::Logic::LOW);
            }

            this->m_state = Fw::On::OFF;
            this->log_ACTIVITY_LO_WatchdogState(this->m_state);
        }
    }
}

void Watchdog ::stop_handler(FwIndexType portNum) {
    // Set the stop flag to stop watchdog petting
    this->m_stopRequested = true;
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------



}  // namespace Components
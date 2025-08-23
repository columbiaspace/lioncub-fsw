// ======================================================================
// \title  Watchdog.hpp
// \author ortega
// \brief  hpp file for Watchdog component implementation class
// ======================================================================

#ifndef Components_Watchdog_HPP
#define Components_Watchdog_HPP

#include "FprimeZephyrReference/Components/Watchdog/WatchdogComponentAc.hpp"

namespace Components {

class Watchdog : public WatchdogComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct Watchdog object
    Watchdog(const char* const compName  //!< The component name
    );

    //! Destroy Watchdog object
    ~Watchdog();

    private :
        //! Emit parameter updated EVR
        //!
        void
        parameterUpdated(FwPrmIdType id  //!< The parameter ID
                         ) override;

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for run
        //!
        //! Port receiving calls from the rate group
        void
        run_handler(FwIndexType portNum,  //!< The port number
                    U32 context  //!< The call order
                    ) override;

        //! Handler implementation for stop
        //!
        //! Port to stop the watchdog petting
        void
        stop_handler(FwIndexType portNum) override;

    private :
        // ----------------------------------------------------------------------
        // Handler implementations for commands
        // ----------------------------------------------------------------------

        //! Handler implementation for command BLINKING_ON_OFF
        //!
        //! Command to turn on or off the blinking LED
        void
        BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                                   U32 cmdSeq,           //!< The command sequence number
                                   Fw::On onOff          //!< Indicates whether the blinking should be on or off
                                   ) override;

    Fw::On m_state = Fw::On::OFF;  //! Keeps track if LED is on or off
    U64 m_transitions = 0;         //! The number of on/off transitions that have occurred
                                   //! from FSW boot up
    U32 m_toggleCounter = 0;       //! Keeps track of how many ticks the LED has been on for
    bool m_blinking = false;       //! Flag: if true then LED blinking will occur else
                                   //! no blinking will happen
    bool m_stopRequested = false;  //! Flag to stop the watchdog petting
};

}  // namespace Components

#endif
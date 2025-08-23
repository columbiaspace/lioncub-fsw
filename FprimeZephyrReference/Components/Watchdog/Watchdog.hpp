// ======================================================================
// \title  Watchdog.hpp
// \author moisesmata 
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

        void STOP_WATCHDOG_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) override;



    Fw::On m_state = Fw::On::OFF;  //! Keeps track if LED is on or off
    U64 m_transitions = 0;         //! The number of on/off transitions that have occurred
                                   //! from FSW boot up
    bool m_stopRequested = false;  //! Flag to stop the watchdog petting
};

}  // namespace Components

#endif
// ======================================================================
// \title  LightSensorManager.hpp
// \author adriano
// \brief  hpp file for LightSensorManager component implementation class
// ======================================================================

#ifndef Components_LightSensorManager_HPP
#define Components_LightSensorManager_HPP

#include "FprimeZephyrReference/Components/LightSensorManager/LightSensorManagerComponentAc.hpp"

namespace Components {

class LightSensorManager final : public LightSensorManagerComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------
    enum LightSensorState {
        OFF ,    //!< Light sensor is turned off
        ON ,     //!< Light sensor is powered on and running
        RESET    //!< Light sensor encountered an error and is resetting
    };

    //!< Current state of the light sensor
    LightSensorState sensor_state = OFF;

    //! Construct LightSensorManager object
    LightSensorManager(const char* const compName  //!< The component name
    );

    //! Destroy LightSensorManager object
    ~LightSensorManager();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command RESET
    void RESET_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                          U32 cmdSeq            //!< The command sequence number
                          ) override;


    Fw::On m_state = Fw::On::OFF; //! Keeps track if sensor is on or off
};

}  // namespace Components

#endif

// ======================================================================
// \title  ImageHandler.hpp
// \author wisaac
// \brief  hpp file for ImageHandler component implementation class
// ======================================================================

#ifndef Components_ImageHandler_HPP
#define Components_ImageHandler_HPP

#include "FprimeZephyrReference/Components/ImageHandler/ImageHandlerComponentAc.hpp"

namespace Components {

class ImageHandler final : public ImageHandlerComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ImageHandler object
    ImageHandler(const char* const compName  //!< The component name
    );

    //! Destroy ImageHandler object
    ~ImageHandler();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command TODO
    //!
    //! TODO
    void TODO_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq            //!< The command sequence number
                         ) override;
};

}  // namespace Components

#endif

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
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for ImageRec
    void ImageRec_handler(FwIndexType portNum,  //!< The port number
                          Fw::Buffer& fwBuffer  //!< The buffer
                          ) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command delete
    //!
    //! Delete specified image
    void delete_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                           U32 cmdSeq,           //!< The command sequence number
                           U32 imageId) override;

    //! Handler implementation for command downlink
    //!
    //! Downlink an image
    void downlink_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                             U32 cmdSeq,           //!< The command sequence number
                             U32 imageId,
                             U8 imageSize) override;

    //! Handler implementation for command list
    //!
    //! List all images
    void list_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq            //!< The command sequence number
                         ) override;
};

}  // namespace Components

#endif

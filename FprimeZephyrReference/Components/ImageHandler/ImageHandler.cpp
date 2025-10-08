// ======================================================================
// \title  ImageHandler.cpp
// \author wisaac
// \brief  cpp file for ImageHandler component implementation class
// ======================================================================

#include "FprimeZephyrReference/Components/ImageHandler/ImageHandler.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ImageHandler ::ImageHandler(const char* const compName) : ImageHandlerComponentBase(compName) {}

ImageHandler ::~ImageHandler() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void ImageHandler ::TODO_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components

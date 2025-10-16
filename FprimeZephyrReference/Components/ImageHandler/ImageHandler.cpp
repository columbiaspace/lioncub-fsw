// ======================================================================
// \title  ImageHandler.cpp
// \author Rohan
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
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void ImageHandler ::ImageRec_handler(FwIndexType portNum, Fw::Buffer& fwBuffer) {
    this->log_ACTIVITY_HI_ReceivedImage();
    
    // Generate a unique ID and filenames for the new image
    U32 imageId = m_nextImageId++;
    char image_path[256];

    snprintf(image_path, sizeof(image_path), "%s/img_%u.bin", IMAGE_DIR, imageId);

    // Save the raw buffer to the "full" size file
    FILE* file = fopen(image_path, "wb");
    if (!file) {
        // TODO: handle error
        return;
    }
    
    const size_t bytesWritten = fwrite(fwBuffer.getData(), 1, fwBuffer.getSize(), file);
    fclose(file);
    
    // Deallocate the buffer now that we are done with it
    // fwBuffer.deallocate() ?

    if (bytesWritten != fwBuffer.getSize()) {
        // TODO: handle error
        return;
    }

    this->log_ACTIVITY_HI_ProcessImage();
    
    // TODO: Process the image 
    // Store metadata - probably keep a map of imageId or something
    
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void ImageHandler ::delete_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 imageId) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::downlink_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 imageId, U8 imageSize) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::list_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components

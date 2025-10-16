// ======================================================================
// \title  ImageHandler.cpp
// \author Rohan
// \brief  cpp file for ImageHandler component implementation class
// ======================================================================

#include "FprimeZephyrReference/Components/ImageHandler/ImageHandler.hpp"
#include <Os/File.hpp>
#include <OS/Directory.hpp>
#include <Os/FileSystem.hpp>


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

    snprintf(image_path, sizeof(image_path), "%s/img_%u.bin", IMAGE_DIR, imageId); //may not want to save as a bin, and this may change with pathing things.
    Os::File file;
    if(file.open(image_path, Os::File::OPEN_WRITE) != Os::File::OP_OK) {
        this->log_WARNING_HI_FileOpenError(image_path);
        return;
    }
    // Save the raw buffer to the "full" size file
    FwSizeType size = fwBuffer.getSize();
    if(file.write(fwBuffer.getData(), size) != Os::File::OP_OK) {
        this->log_WARNING_HI_FileWriteError(image_path);
        return;
    }
    
    this->log_ACTIVITY_HI_ProcessImage();
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void ImageHandler ::delete_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 imageId) {
    
    // Generate a unique ID and filenames for the new image
    char image_path[256];

    snprintf(image_path, sizeof(image_path), "%s/img_%u.bin", IMAGE_DIR, imageId); //may not want to save as a bin, and this may change with pathing things.
    
    Os::FileSystem::removeFile(image_path);
    this->log_ACTIVITY_HI_DeletedImage(image_path);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::downlink_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 imageId, U8 imageSize) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::list_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    
    Os::Directory directory;
    if(directory.open(IMAGE_DIR, Os::Directory::OPEN_READ) != Os::Directory::OP_OK) {
        this->log_WARNING_HI_DirectoryOpenError(IMAGE_DIR);
        return;
    }
    while(directory.read(image_path, 250) == Os::Directory::OP_OK) {
        char entry_info[256];
        snprintf(entry_info, sizeof(entry_info), "%d %s", i, image_path);
        this->log_ACTIVITY_HI_ListImage(entry_info);
        i++;
    }
    directory.close();
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    }

}  // namespace Components

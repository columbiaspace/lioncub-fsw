// ======================================================================
// \title  ImageHandler.cpp
// \author Rohan
// \brief  cpp file for ImageHandler component implementation class
// ======================================================================

#include "FprimeZephyrReference/Components/ImageHandler/ImageHandler.hpp"
#include <Os/File.hpp>
#include <Os/FileSystem.hpp>
#include <Os/Directory.hpp>


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
    Fw::String fp_string = image_path;
    if(file.open(image_path, Os::File::OPEN_WRITE) != Os::File::OP_OK) {
        this->log_WARNING_HI_FileOpenError(fp_string);
        return;
    }
    // Save the raw buffer to the "full" size file
    FwSizeType size = fwBuffer.getSize();
    if(file.write(fwBuffer.getData(), size) != Os::File::OP_OK) {
        this->log_WARNING_HI_FileWriteError(fp_string);
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
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::downlink_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 imageId, U8 imageSize) {
    this->log_ACTIVITY_HI_ReceivedDownlinkRequest();
    
    // Generate source and destination filenames
    char sourceFileName[100];
    char destFileName[100];
    
    snprintf(sourceFileName, sizeof(sourceFileName), "%s/img_%u.bin", IMAGE_DIR, imageId);
    snprintf(destFileName, sizeof(destFileName), "img_%u.bin", imageId);
    
    // Create file downlink request
    Fw::String sourceFile(sourceFileName);
    Fw::String destFile(destFileName);
    U32 offset = 0;  // Start from beginning of file
    U32 length = 0;  // 0 means read until end of file
    
    // Send the file downlink request
    this->fileDownlink_out(0, sourceFile, destFile, offset, length);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void ImageHandler ::list_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    
    Os::Directory directory;
    if(directory.open(IMAGE_DIR.toChar(), Os::Directory::READ) != Os::Directory::OP_OK) {
        this->log_WARNING_HI_OpenDirError(IMAGE_DIR);
        return;
    }
    
    Os::File file;
    if(file.open(IMAGE_LIST.toChar(), Os::File::OPEN_WRITE) != Os::File::OP_OK) {
        this->log_WARNING_HI_FileOpenError(IMAGE_LIST);
        return;
    }
    // Save the raw buffer to the "full" size file
    Fw::String filePath = "";
    FwSizeType size = 250;
    
    while(directory.read(filePath) == Os::Directory::OP_OK) {
        const char* s = filePath.toChar();
        if(file.write((unsigned char *) s, size) != Os::File::OP_OK) {
            this->log_WARNING_HI_FileWriteError(IMAGE_LIST);
            return;
        }
        
    }
    directory.close();
    file.close();
    //Downlinke the thing
}
}  // namespace Components

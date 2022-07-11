// FileViewer.h

#ifndef _FileViewer_h_
#define _FileViewer_h_

#include <cstdlib>
#include <iostream>
#include <string>

#include "Buffer.h"

const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's

class FileViewer
{
public:
    void run();

private:
    void display();
    void execute_command(char command, bool & done);

    Buffer buffer_;
    int window_height_;
    int line_length_;
    std::string error_message_;
};

#endif

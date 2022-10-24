/*
 * Copyright (C) 2022 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#include "Utils.h"

#include <stdarg.h>

std::string Sprintf(const char* fmt, ...)
{
    const int LOG_BUFFER_SIZE = 512;

    char buffer[LOG_BUFFER_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, LOG_BUFFER_SIZE - 1, fmt, args);
    va_end(args);

    return std::string(buffer);
}

/*************************************************************************
*  Console script
* ------------------------------------------------------------------------
*  Copyright (c) 2014-2018 Vladimir Sviridov <v.shtille@gmail.com>
*
*  This software is provided 'as-is', without any express or implied
*  warranty. In no event will the authors be held liable for any damages
*  arising from the use of this software.
*
*  Permission is granted to anyone to use this software for any purpose,
*  including commercial applications, and to alter it and redistribute it
*  freely, subject to the following restrictions:
*
*  1. The origin of this software must not be misrepresented; you must not
*     claim that you wrote the original software. If you use this software
*     in a product, an acknowledgment in the product documentation would
*     be appreciated but is not required.
*
*  2. Altered source versions must be plainly marked as such, and must not
*     be misrepresented as being the original software.
*
*  3. This notice may not be removed or altered from any source
*     distribution.
*
**************************************************************************/

#pragma once
#ifndef __CONSOLE_SCRIPT_DEFINES_H__
#define __CONSOLE_SCRIPT_DEFINES_H__

#include <string>

namespace console_script {

#ifndef CS_WIDE_STRING
#define CS_CHAR char
#define CS_TEXT(str) str
	typedef std::string String;
#else
#define CS_CHAR wchar_t
#define CS_TEXT(str) L##str
	typedef std::wstring String;
#endif

#ifndef CS_HIGHP_FLOAT
	typedef float Float;
#else
	typedef double Float;
#endif

} // namespace console_script

#endif
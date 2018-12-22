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
#ifndef __CONSOLE_SCRIPT_H__
#define __CONSOLE_SCRIPT_H__

#include "script_defines.h"
#include "script_lexem.h"
#include "script_base.h"

namespace console_script {

	//! Main class for parsing
	class Parser {
		typedef std::list<Lexem*> LexemList;

	public:
		Parser();
		~Parser();

		bool Compile(const String& str);
		void Execute();

		bool Evaluate(const String& str);
		bool Evaluate(const String& str, bool* val);
		bool Evaluate(const String& str, int* val);
		bool Evaluate(const String& str, Float* val);
		bool Evaluate(const String& str, String* val);

		void AddVariable(const String& str, bool* ptr);
		void AddVariable(const String& str, int* ptr);
		void AddVariable(const String& str, Float* ptr);
		void AddVariable(const String& str, String* ptr);

		template <typename R, typename... Args>
		void AddFunction(const String& str, R(*func)(Args...)) {
			Base& base = Base::GetInstance();
			base.AddFunction<R, Args...>(str, func);
		}
		template <typename R, typename C, typename... Args>
		void AddClassFunction(const String& str, R(C::*func)(Args...), C * object) {
			Base& base = Base::GetInstance();
			base.AddClassFunction<R, C, Args...>(str, func, object);
		}

		const String& error() const { return error_; }

	private:
		void Clear();
		void AddLexem(const String& str, Lexem::Type type, int pos);
		bool ParseLexems(const String& str);
		bool RecognizeLexems();
		bool BuildTree();
		bool CheckTree();

		LexemList elements_;	//!< elements list
		String error_;		//!< error message of parsed text
		class Node * root_;
	};

} // namespace console_script

#endif
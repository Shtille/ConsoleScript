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
#ifndef __CONSOLE_SCRIPT_NODE_H__
#define __CONSOLE_SCRIPT_NODE_H__

#include "script_value.h"

#include <list>

namespace console_script {

	class Node {
		friend class Parser;

	public:
		Node();
		Node(Lexem* lexem);
		Node(Lexem* lexem, Node * parent);
		~Node();

		void Add(Node* node);
		void EvaluateTree();
		void DeleteTree();
		bool CheckTree(String& error);

		Value& data() { return data_; }
		const Value& data() const { return data_; }
		Node * parent() { return parent_; }

		bool IsOperatorBinary(class Operator * op);
		bool IsOperatorBinary();
		bool IsOperatorFormPrefix();

	protected:
		inline void CreationCheck();

	private:
		Value data_;
		Lexem * lexem_;
		Node * parent_;
		std::list<Node*> childs_;
	};

} // namespace console_script

#endif
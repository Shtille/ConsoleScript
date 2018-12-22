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

#include "script_lexem.h"
#include "script_base.h"
#include <assert.h>

namespace console_script {

	Lexem::Lexem()
	{
	}
	Lexem::Lexem(const String& str, Type type) :
		str(str), priority(kLowestPriority), type(type)
	{
	}
	Lexem::~Lexem()
	{
	}
	bool Lexem::is_l_value() const
	{
		return type == Lexem::kVariable || type == Lexem::kUnknownVariable;
	}
	bool Lexem::is_evaluatable() const
	{
		return type != Lexem::kOperator;
	}
	bool Lexem::SortPredicate(Lexem* first, Lexem* second)
	{
		if (first->priority == second->priority && first->type == Lexem::kOperator) // second will be operator too
		{
			// first and second have equal associativity, so we will use first's one
			Operator * op_first = dynamic_cast<Operator*>(first);
			Operator * op_second = dynamic_cast<Operator*>(second);
			if (op_first->associativity) // left-to-right
				return op_first->pos < op_second->pos;
			else // right-to-left
				return op_first->pos > op_second->pos;
		}
		else
			return first->priority > second->priority;
	}
	bool Lexem::OperatorPredicate(Lexem* first)
	{
		return first->type == Lexem::kOperator;
	}
	bool Lexem::ReferencePredicate(Lexem* first)
	{
		return first->type == Lexem::kReference || first->type == Lexem::kFunction;
	}
	Operator::Operator(const String& str, int pos) :
		Lexem(str, Lexem::kOperator), pos(pos)
	{
		Base& base = Base::GetInstance();
		OperatorInfo *op_info = base.GetOperatorInfo(str);
		assert(op_info);
		priority = op_info->priority();
		form = op_info->form();
		associativity = op_info->associativity();
		info = op_info;
	}
	bool Operator::is_indefinite_form() const
	{
		return (form & (Operator::kBinary | Operator::kUnaryPrefix)) == (Operator::kBinary | Operator::kUnaryPrefix) ||
			   (form & (Operator::kBinary | Operator::kUnaryPostfix)) == (Operator::kBinary | Operator::kUnaryPostfix);
	}
	const int Operator::UnaryPriority()
	{
		return 15;
	}
	const bool Operator::UnaryAssociativity()
	{
		return false;
	}
	Reference::Reference()
	{
		type = kReference;
		priority = kLowestPriority;
		list_ptr = new std::list<Lexem*>;
	}
	Reference::~Reference()
	{
		if (list_ptr)
		{
			delete list_ptr;
			list_ptr = nullptr;
		}
	}
	FunctionReference::FunctionReference(const String& str) :
		Lexem(str, Lexem::kFunction), arguments()
	{

	}
	FunctionReference::~FunctionReference()
	{

	}
	Variable::Variable(const String& str) :
		Lexem(str, Lexem::kVariable)
	{
		Base& base = Base::GetInstance();
		info = base.GetVariableInfo(str);
	}

} // namespace script
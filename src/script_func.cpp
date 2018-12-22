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

#include "script_func.h"

namespace console_script {

#define TWO_FUNC_PARAMS \
	std::list<Node*>::const_iterator it = list.begin(); \
	const Value& first = (*it)->data(); \
	const Value& second = (*++it)->data();
#define ASSIGNMENT_PARAMS \
	std::list<Node*>::const_iterator it = list.begin(); \
	Value& first = (*it)->data(); \
	const Value& second = (*++it)->data();
#define ONE_PARAM_FUNC \
	std::list<Node*>::const_iterator it = list.begin(); \
	const Value& first = (*it)->data();

	void FuncAddition(const std::list<Node*>& list, Value* value)
	{
		std::list<Node*>::const_iterator it = list.begin();
		const Value& first = (*it)->data();
		if ((*it)->parent()->IsOperatorBinary())
		{
			const Value& second = (*++it)->data();
			switch (value->type())
			{
			case Value::kInteger:
				*value = first.AsInteger() + second.AsInteger();
				break;
			case Value::kFloat:
				*value = first.AsFloat() + second.AsFloat();
				break;
			case Value::kString:
				*value = first.AsString() + second.AsString();
				break;
			default:
				break;
			}
		}
		else // unary
		{
			*value = first;
		}
	}
	void FuncSubtraction(const std::list<Node*>& list, Value* value)
	{
		std::list<Node*>::const_iterator it = list.begin();
		const Value& first = (*it)->data();
		if ((*it)->parent()->IsOperatorBinary())
		{
			const Value& second = (*++it)->data();
			switch (value->type())
			{
			case Value::kInteger:
				*value = first.AsInteger() - second.AsInteger();
				break;
			case Value::kFloat:
				*value = first.AsFloat() - second.AsFloat();
				break;
			default:
				break;
			}
		}
		else // unary operator
		{
			switch (value->type())
			{
			case Value::kInteger:
				*value = - first.AsInteger();
				break;
			case Value::kFloat:
				*value = - first.AsFloat();
				break;
			default:
				break;
			}
		}
	}
	void FuncMultiplication(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (value->type())
		{
		case Value::kInteger:
			*value = first.AsInteger() * second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() * second.AsFloat();
			break;
		default:
			break;
		}
	}
	void FuncDivision(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (value->type())
		{
		case Value::kInteger:
			*value = first.AsInteger() / second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() / second.AsFloat();
			break;
		default:
			break;
		}
	}
	void FuncModulus(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() % second.AsInteger();
	}
	void FuncBitwiseAnd(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() & second.AsInteger();
	}
	void FuncBitwiseInclusiveOr(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() | second.AsInteger();
	}
	void FuncBitwiseExclusiveOr(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() ^ second.AsInteger();
	}
	void FuncLogicalAnd(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsBool() && second.AsBool();
	}
	void FuncLogicalOr(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsBool() || second.AsBool();
	}
	void FuncEquality(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() == second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() == second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() == second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncNotEqual(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() != second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() != second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() != second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncLessThan(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() < second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() < second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() < second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncLessThanOrEqual(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() <= second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() <= second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() <= second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncGreaterThan(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() > second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() > second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() > second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncGreaterThanOrEqual(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		switch (first.type())
		{
		case Value::kInteger:
			*value = first.AsInteger() >= second.AsInteger();
			break;
		case Value::kFloat:
			*value = first.AsFloat() >= second.AsFloat();
			break;
		case Value::kString:
			*value = first.AsString() >= second.AsString();
			break;
		default:
			break;
		}
	}
	void FuncLeftShift(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() << second.AsInteger();
	}
	void FuncRightShift(const std::list<Node*>& list, Value* value)
	{
		TWO_FUNC_PARAMS;
		*value = first.AsInteger() >> second.AsInteger();
	}
	void FuncLogicalNegation(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = ! first.AsBool();
	}
	void FuncOnesComplement(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = ~ first.AsInteger();
	}
	void FuncIncrement(const std::list<Node*>& list, Value* value)
	{
		std::list<Node*>::const_iterator it = list.begin();
		Value& first = (*it)->data();
		if ((*it)->parent()->IsOperatorFormPrefix())
			*value = ++first;
		else
			*value = first++;
	}
	void FuncDecrement(const std::list<Node*>& list, Value* value)
	{
		std::list<Node*>::const_iterator it = list.begin();
		Value& first = (*it)->data();
		if ((*it)->parent()->IsOperatorFormPrefix())
			*value = --first;
		else
			*value = first--;
	}
	void FuncCastBoolean(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = first.AsBool();
	}
	void FuncCastInteger(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = first.AsInteger();
	}
	void FuncCastFloat(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = first.AsFloat();
	}
	void FuncCastString(const std::list<Node*>& list, Value* value)
	{
		ONE_PARAM_FUNC;
		*value = first.AsString();
	}
	void FuncAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first = second;
		*value = first;
	}
	void FuncAdditionAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first += second;
		*value = first;
	}
	void FuncSubtractionAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first -= second;
		*value = first;
	}
	void FuncMultiplicationAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first *= second;
		*value = first;
	}
	void FuncDivisionAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first /= second;
		*value = first;
	}
	void FuncModulusAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first %= second;
		*value = first;
	}
	void FuncBitwiseInclusiveOrAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first |= second;
		*value = first;
	}
	void FuncBitwiseExclusiveOrAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first ^= second;
		*value = first;
	}
	void FuncBitwiseAndAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first &= second;
		*value = first;
	}
	void FuncLeftShiftAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first <<= second;
		*value = first;
	}
	void FuncRightShiftAssignment(const std::list<Node*>& list, Value* value)
	{
		ASSIGNMENT_PARAMS;
		first >>= second;
		*value = first;
	}

#undef ASSIGNMENT_PARAMS
#undef ONE_PARAM_FUNC
#undef TWO_FUNC_PARAMS

} // namespace script
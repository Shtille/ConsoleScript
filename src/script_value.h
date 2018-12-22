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
#ifndef __CONSOLE_SCRIPT_VALUE_H__
#define __CONSOLE_SCRIPT_VALUE_H__

#include "script_defines.h"

#include <string>

namespace console_script {

	class Lexem;
	class ValueData;

	class Value {
		friend class Node;

	public:
		enum Type {
			kUnknown	= 0x00,
			kBoolean	= 0x01,
			kInteger	= 0x02,
			kFloat		= 0x04,
			kString		= 0x08,
			kAll		= 0x0F,
			kVoid		= 0xFF
		};

		Value();
		Value(const Value& value);
		Value(Lexem* lexem);
		~Value();

		void Assign(void *data);

		Value& operator = (bool b);
		Value& operator = (int i);
		Value& operator = (Float d);
		Value& operator = (const String& str);

		// lvalue operators
		Value& operator = (const Value& value);
		Value& operator += (const Value& value);
		Value& operator -= (const Value& value);
		Value& operator *= (const Value& value);
		Value& operator /= (const Value& value);
		Value& operator %= (const Value& value);
		Value& operator |= (const Value& value);
		Value& operator ^= (const Value& value);
		Value& operator &= (const Value& value);
		Value& operator <<= (const Value& value);
		Value& operator >>= (const Value& value);

		Value& operator ++(); // prefix
		Value operator ++(int); // postfix
		Value& operator --(); // prefix
		Value operator --(int); // postfix
		Value operator -(); // unary

		void set_type(Type type);
		Type type() const;
		bool valid() const;

		bool AsBool() const;
		int AsInteger() const;
		Float AsFloat() const;
		String AsString() const;

		static bool IsGoodFunctionName(const String& str);
		static bool IsGoodVariableName(const String& str);

	private:
		void Evaluate(const String& str); // for constants
		bool FromString(const String& str);
		bool FromInteger(const String& str);
		bool FromFloat(const String& str);
		bool FromBool(const String& str);

	private:
		ValueData * data_;
		Type type_;
	};

	template <typename T>
	class ValueTypeSetter;
	template <>
	class ValueTypeSetter <void> {
	public:
		static void Set(Value* v) {
		}
		static void Fill(Value::Type &type) {
			type = Value::kVoid;
		}
	};
	template <>
	class ValueTypeSetter <bool> {
	public:
		static void Set(Value* v) {
			v->set_type(Value::kBoolean);
		}
		static void Fill(Value::Type &type) {
			type = Value::kBoolean;
		}
	};
	template <>
	class ValueTypeSetter <int> {
	public:
		static void Set(Value* v) {
			v->set_type(Value::kInteger);
		}
		static void Fill(Value::Type &type) {
			type = Value::kInteger;
		}
	};
	template <>
	class ValueTypeSetter <Float> {
	public:
		static void Set(Value* v) {
			v->set_type(Value::kFloat);
		}
		static void Fill(Value::Type &type) {
			type = Value::kFloat;
		}
	};
	template <>
	class ValueTypeSetter <String> {
	public:
		static void Set(Value* v) {
			v->set_type(Value::kString);
		}
		static void Fill(Value::Type &type) {
			type = Value::kString;
		}
	};

} // namespace console_script

#endif
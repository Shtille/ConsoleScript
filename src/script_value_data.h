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
#ifndef __CONSOLE_SCRIPT_VALUE_DATA_H__
#define __CONSOLE_SCRIPT_VALUE_DATA_H__

#include "script_defines.h"

#include <string>

namespace console_script {

	class ValueData {
	public:
		ValueData();
		virtual ~ValueData();

		virtual void Assign(void *data) = 0;

		virtual void operator = (bool b);
		virtual void operator = (int i);
		virtual void operator = (Float d);
		virtual void operator = (const String& str);

		virtual void operator = (const ValueData& data) = 0;
		virtual void operator += (const ValueData& data);
		virtual void operator -= (const ValueData& data);
		virtual void operator *= (const ValueData& data);
		virtual void operator /= (const ValueData& data);
		virtual void operator %= (const ValueData& data);
		virtual void operator |= (const ValueData& data);
		virtual void operator ^= (const ValueData& data);
		virtual void operator &= (const ValueData& data);
		virtual void operator <<= (const ValueData& data);
		virtual void operator >>= (const ValueData& data);

		virtual void operator ++();
		virtual void operator --();
		virtual void operator -();

		virtual bool AsBool() const = 0;
		virtual int AsInteger() const = 0;
		virtual Float AsFloat() const = 0;
		virtual String AsString() const = 0;

		bool is_reference() const;

	protected:
		bool is_reference_; //!< is it just a reference to the outer value (like variable)
	};

	class BooleanValueData : public ValueData {
	public:
		BooleanValueData();
		BooleanValueData(bool b);
		~BooleanValueData();

		void Assign(void *data);

		void operator = (bool b);

		void operator = (const ValueData& data);

		bool AsBool() const;
		int AsInteger() const;
		Float AsFloat() const;
		String AsString() const;

	private:
		bool *data_;
	};

	class IntegerValueData : public ValueData {
	public:
		IntegerValueData();
		IntegerValueData(int i);
		~IntegerValueData();

		void Assign(void *data);

		void operator = (int i);

		void operator = (const ValueData& data);
		void operator += (const ValueData& data);
		void operator -= (const ValueData& data);
		void operator *= (const ValueData& data);
		void operator /= (const ValueData& data);
		void operator %= (const ValueData& data);
		void operator |= (const ValueData& data);
		void operator ^= (const ValueData& data);
		void operator &= (const ValueData& data);
		void operator <<= (const ValueData& data);
		void operator >>= (const ValueData& data);

		void operator ++();
		void operator --();
		void operator -();

		bool AsBool() const;
		int AsInteger() const;
		Float AsFloat() const;
		String AsString() const;

	private:
		int *data_;
	};

	class FloatValueData : public ValueData {
	public:
		FloatValueData();
		FloatValueData(Float d);
		~FloatValueData();

		void Assign(void *data);

		void operator = (Float d);

		void operator = (const ValueData& data);
		void operator += (const ValueData& data);
		void operator -= (const ValueData& data);
		void operator *= (const ValueData& data);
		void operator /= (const ValueData& data);
		void operator -();

		bool AsBool() const;
		int AsInteger() const;
		Float AsFloat() const;
		String AsString() const;

	private:
		Float *data_;
	};

	class StringValueData : public ValueData {
	public:
		StringValueData();
		StringValueData(const String& str);
		~StringValueData();

		void Assign(void *data);

		void operator = (const String& str);

		void operator = (const ValueData& data);
		void operator += (const ValueData& data);

		bool AsBool() const;
		int AsInteger() const;
		Float AsFloat() const;
		String AsString() const;

	private:
		String *data_;
	};

} // namespace console_script

#endif
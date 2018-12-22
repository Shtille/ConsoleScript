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

#include "script_value_data.h"

#include <float.h>
#include <assert.h>
#include <cstdlib>

namespace console_script {

	ValueData::ValueData() :
		is_reference_(false)
	{
	}
	ValueData::~ValueData()
	{
	}
	void ValueData::operator = (bool b)
	{
		assert(false);
	}
	void ValueData::operator = (int i)
	{
		assert(false);
	}
	void ValueData::operator = (Float d)
	{
		assert(false);
	}
	void ValueData::operator = (const String& str)
	{
		assert(false);
	}
	void ValueData::operator += (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator -= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator *= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator /= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator %= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator |= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator ^= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator &= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator <<= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator >>= (const ValueData& data)
	{
		assert(false);
	}
	void ValueData::operator ++()
	{
		assert(false);
	}
	void ValueData::operator --()
	{
		assert(false);
	}
	void ValueData::operator -()
	{
		assert(false);
	}
	bool ValueData::is_reference() const
	{
		return is_reference_;
	}
	BooleanValueData::BooleanValueData() :
		data_(new bool)
	{
	}
	BooleanValueData::BooleanValueData(bool b) :
		data_(new bool)
	{
		*data_ = b;
	}
	BooleanValueData::~BooleanValueData()
	{
		if (!is_reference_)
			delete data_;
	}
	void BooleanValueData::Assign(void *data)
	{
		is_reference_ = true;
		delete data_;
		data_ = reinterpret_cast<bool*>(data);
	}
	void BooleanValueData::operator = (bool b)
	{
		*data_ = b;
	}
	void BooleanValueData::operator = (const ValueData& data)
	{
		*data_ = *dynamic_cast<const BooleanValueData&>(data).data_;
	}
	bool BooleanValueData::AsBool() const
	{
		return *data_;
	}
	int BooleanValueData::AsInteger() const
	{
		return *data_ ? 1 : 0;
	}
	Float BooleanValueData::AsFloat() const
	{
		return *data_ ? static_cast<Float>(1.0) : static_cast<Float>(0.0);
	}
	String BooleanValueData::AsString() const
	{
		return *data_ ? CS_TEXT("true") : CS_TEXT("false");
	}
	IntegerValueData::IntegerValueData() :
		data_(new int)
	{
	}
	IntegerValueData::IntegerValueData(int i) :
		data_(new int)
	{
		*data_ = i;
	}
	IntegerValueData::~IntegerValueData()
	{
		if (!is_reference_)
			delete data_;
	}
	void IntegerValueData::Assign(void *data)
	{
		is_reference_ = true;
		delete data_;
		data_ = reinterpret_cast<int*>(data);
	}
	void IntegerValueData::operator = (int i)
	{
		*data_ = i;
	}
	void IntegerValueData::operator = (const ValueData& data)
	{
		*data_ = *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator += (const ValueData& data)
	{
		*data_ += *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator -= (const ValueData& data)
	{
		*data_ -= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator *= (const ValueData& data)
	{
		*data_ *= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator /= (const ValueData& data)
	{
		*data_ /= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator %= (const ValueData& data)
	{
		*data_ %= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator |= (const ValueData& data)
	{
		*data_ |= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator ^= (const ValueData& data)
	{
		*data_ ^= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator &= (const ValueData& data)
	{
		*data_ &= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator <<= (const ValueData& data)
	{
		*data_ <<= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator >>= (const ValueData& data)
	{
		*data_ >>= *dynamic_cast<const IntegerValueData&>(data).data_;
	}
	void IntegerValueData::operator ++()
	{
		++(*data_);
	}
	void IntegerValueData::operator --()
	{
		--(*data_);
	}
	void IntegerValueData::operator -()
	{
		*data_ = -*data_;
	}
	bool IntegerValueData::AsBool() const
	{
		return *data_ != 0;
	}
	int IntegerValueData::AsInteger() const
	{
		return *data_;
	}
	Float IntegerValueData::AsFloat() const
	{
		return static_cast<Float>(*data_);
	}
	String IntegerValueData::AsString() const
	{
#ifndef CS_WIDE_STRING
		return std::to_string(*data_);
#else
		return std::to_wstring(*data_);
#endif
	}
	FloatValueData::FloatValueData() :
		data_(new Float)
	{
	}
	FloatValueData::FloatValueData(Float d) :
		data_(new Float)
	{
		*data_ = d;
	}
	FloatValueData::~FloatValueData()
	{
		if (!is_reference_)
			delete data_;
	}
	void FloatValueData::Assign(void *data)
	{
		is_reference_ = true;
		delete data_;
		data_ = reinterpret_cast<Float*>(data);
	}
	void FloatValueData::operator = (Float d)
	{
		*data_ = d;
	}
	void FloatValueData::operator = (const ValueData& data)
	{
		*data_ = *dynamic_cast<const FloatValueData&>(data).data_;
	}
	void FloatValueData::operator += (const ValueData& data)
	{
		*data_ += *dynamic_cast<const FloatValueData&>(data).data_;
	}
	void FloatValueData::operator -= (const ValueData& data)
	{
		*data_ -= *dynamic_cast<const FloatValueData&>(data).data_;
	}
	void FloatValueData::operator *= (const ValueData& data)
	{
		*data_ *= *dynamic_cast<const FloatValueData&>(data).data_;
	}
	void FloatValueData::operator /= (const ValueData& data)
	{
		*data_ /= *dynamic_cast<const FloatValueData&>(data).data_;
	}
	void FloatValueData::operator -()
	{
		*data_ = -*data_;
	}
	bool FloatValueData::AsBool() const
	{
		return static_cast<int>(*data_) != 0;
	}
	int FloatValueData::AsInteger() const
	{
		return static_cast<int>(*data_);
	}
	Float FloatValueData::AsFloat() const
	{
		return *data_;
	}
	String FloatValueData::AsString() const
	{
#ifndef CS_WIDE_STRING
		return std::to_string(*data_);
#else
		return std::to_wstring(*data_);
#endif
	}
	StringValueData::StringValueData() :
		data_(new String)
	{
	}
	StringValueData::StringValueData(const String& str) :
		data_(new String)
	{
		*data_ = str;
	}
	StringValueData::~StringValueData()
	{
		if (!is_reference_)
			delete data_;
	}
	void StringValueData::Assign(void *data)
	{
		is_reference_ = true;
		delete data_;
		data_ = reinterpret_cast<String*>(data);
	}
	void StringValueData::operator = (const String& str)
	{
		*data_ = str;
	}
	void StringValueData::operator = (const ValueData& data)
	{
		*data_ = *dynamic_cast<const StringValueData&>(data).data_;
	}
	void StringValueData::operator += (const ValueData& data)
	{
		*data_ += *dynamic_cast<const StringValueData&>(data).data_;
	}
	bool StringValueData::AsBool() const
	{
		return *data_ == CS_TEXT("true");
	}
	int StringValueData::AsInteger() const
	{
		return std::stoi(*data_);
	}
	Float StringValueData::AsFloat() const
	{
#ifndef CS_HIGHP_FLOAT
		return std::stof(*data_);
#else
		return std::stod(*data_);
#endif
	}
	String StringValueData::AsString() const
	{
		return *data_;
	}
} // namespase script
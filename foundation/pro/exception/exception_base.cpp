﻿
#include <pro/utils/string_utils.h>
#include <pro/exception/exception_base.h>

namespace pro
{
	Exception::~Exception() throw()
	{

	}

	Exception::Exception(const string& _description, const string& _source)
	:line_(0)
	,type_(EXT_UNDEF_TYPE)
	,title_("Exception")
	,description_(_description)
	,source_(_source)
	{
	}
	Exception::Exception(const string& _description, const char* _file, long _line)
		:type_(EXT_UNDEF_TYPE)
		, title_("Exception")
		, description_(_description)
		, file_(_file)
		, line_(_line)

	{
	}

	Exception::Exception(const string& _description, const string& _source, const char* _file, long _line)
		:type_(EXT_UNDEF_TYPE)
		,title_("Exception")
		,description_(_description)
		,source_(_source)
		,file_(_file)
		,line_(_line)
		
	{
	}

	Exception::Exception(int type_, const string& _description, const string& _source, const char* tile_, const char* _file, long _line)
		:line_(_line)
		,type_(type_)
		,title_(tile_)
		,description_(_description)
		,source_(_source)
		,file_(_file)
	{

	}

	Exception::Exception(int type_, const string& _description, const char* tile_, const char* _file, long _line)
		:line_(_line)
		, type_(type_)
		, title_(tile_)
		, description_(_description)
		, file_(_file)
	{

	}

	Exception::Exception(const Exception& rhs)
		: line_(rhs.line_), 
		type_(rhs.type_), 
		title_(rhs.title_), 
		description_(rhs.description_), 
		source_(rhs.source_), 
		file_(rhs.file_)
	{
	}

	void Exception::operator = (const Exception& rhs)
	{
		description_ = rhs.description_;
		type_ = rhs.type_;
		source_ = rhs.source_;
		file_ = rhs.file_;
		line_ = rhs.line_;
		title_ = rhs.title_;
	}

    const string& Exception::GetFullDescription() const
	{
		if (0 == full_desc_.size())
		{	
			if( line_ > 0 )
			{
				if (source_.size())
				{
					utils::Format(full_desc_, "PRO EXCEPTION(%d:%s): \"%s\" in %s at '%s(line, %d)'",
						type_, title_.c_str(), description_.c_str(), source_.c_str(), file_.c_str(), line_);
				}
				else
				{
					utils::Format(full_desc_, "PRO EXCEPTION(%d:%s): \"%s\" at '%s(line, %d)'",
						type_, title_.c_str(), description_.c_str(), file_.c_str(), line_);
				}
			
			}
			else
			{
				if (source_.size())
				{
					utils::Format(full_desc_, "PRO EXCEPTION(%d:%s): \"%s\" in %s", type_, title_.c_str(), description_.c_str(), source_.c_str());
				}
				else
				{
					utils::Format(full_desc_, "PRO EXCEPTION(%d:%s): \"%s\".", type_, title_.c_str(), description_.c_str());
				}

			}
		}

		return full_desc_;
	}

    int Exception::GetType(void) const throw()
	{
		return type_;
	}

    const string &Exception::GetSource() const 
	{ 
		return source_;
	}

    const string &Exception::GetFile() const 
	{ 
		return file_; 
	}

    long Exception::GetLine() const 
	{ 
		return line_; 
	}

	const string &Exception::GetDescription(void) const 
	{ 
		return description_; 
	}

	const char* Exception::what() const throw() 
	{ 
		return GetFullDescription().c_str(); 
	}
}
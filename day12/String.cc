#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <string>

String::String() :pstr_(nullptr), len_(0) {}
String::String(const char* pstr)
{
	int len = 0;
	const char* temp = pstr;
	while (temp && *temp)
	{
		len++;
		temp++;
	}
	pstr_ = new char[len];
	len_ = len;
	for (int i = 0; i < len; i++)
	{
		pstr_[i] = pstr[i];
	}
}
//String::String() :String(nullptr) {}
String::String(const String& rhs)
{
	pstr_ = new char[rhs.len_];
	len_ = rhs.len_;
	for (int i = 0; i < rhs.len_; i++)
	{
		pstr_[i] = rhs.pstr_[i];
	}
}
String:: operator=

#ifndef _STRING_H_
#define _STRING_H_

class String {
public:
	String();// : pstr_(nullptr) {}
	String(const char* pstr);// :pstr_(*pstr) {}
	String(const String& rhs);
	String& operator= (const String& rhs);
	//~String();

	void print();

private:
	char* pstr_;
	int len_;
};

#endif // !_STRING_H_
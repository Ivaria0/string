#include <string.h>
#include <iostream>


class String
{
	char *d;
public:
	String(const char *s)
	{
		d = new char[strlen(s) + 1];
		strcpy(d, s);
	}
	String(const String& orig)
	{
		d = orig.d;
	}
	~String()
	{}
	String& operator=(const String &orig)
	{
		d = orig.d;
		return *this;
	}
	operator const char *() const
	{
		return d;
	}

	String operator+ (const String &second)
	{
		char *res = new char[strlen(d) + strlen(second) + 1];
		strcat(strcpy(res, d), second);
		return res;
	}
	String& operator+= (const String &other)
	{
		char *p = new char[strlen(d) + strlen(other) + 1];
		strcat(strcpy(p, d), other);
		delete d;
		d = p;
		return *this;
	}
	char operator[] (const int index) const
	{
		char *p = d;
		if ((index >= 0) && (index <= strlen(d))) {
			for (int i = 0; i < index; i++)
				p++;
			return *p;
		}
		else std::cout << "Incorrect index" << "\n";
	}
	char& operator[] (const int index)
	{
		char *p = d;
		if ((index >= 0) && (index <= strlen(d))) {
			for (int i = 0; i < index; i++)
				p++;
			return *p;
		}
		else std::cout << "Incorrect index" << "\n";
	}
	void show() const
	{
		std::cout << d << "\n";
	}
};

int main()
{
	String x("Hello");
	x.show();
	String k("");
	k.show();
	String n("Copy");
	String n1 = n;
	n1.show();
	String a("");
	a.show();
	String b("Assignment");
	a = b;
	a.show();
	String s("Const char");
	const char *p = s;
	std::cout << p << "\n";

	std::cout << "\n" << "For 4" << "\n";
	String f("First");
	String v("Second");
	String t("");
	t = f + v;
	t.show();
	String r("Something");
	String z("Plus");
	r += z;
	r.show();

	std::cout << "\n" << "For 5" << "\n";
	char g;
	g = r[5];
	std::cout << g << "\n";
	r[0] = 'c';
	r.show();
}
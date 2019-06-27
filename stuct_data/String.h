
class string {
public:
	string(const char *str = NULL)
	{
		if (str)
		{
			_str = new char[strlen(str) + 1];
			strcpy_s(_str, strlen(str) + 1, str);
		}
		else
		{
			_str = "";
		}
	}

	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	string(const string& str)
	{
		this->_str = new char[strlen(str._str) + 1];
		strcpy_s(_str, strlen(str._str) + 1, str._str);
	}

	string& operator=(const string& str)
	{
		if (this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy_s(_str, strlen(str._str) + 1, str._str);
		}
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}

private:
	char *_str;

};
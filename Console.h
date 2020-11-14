#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

namespace cl
{
	class Console
	{
	public:
		Console();

		void Clear();
		void Pause();

		template<typename T, typename ...Other>
		void WriteLine(const T&, const Other& ...);

		template<typename T, typename ...Other>
		void Write(const T&, const Other& ...);

		template <typename T>
		void Write(const T&);

	private:
		static std::string signature;
		static bool isShown;

		void WriteSignature();
		void Write() { return; }
	};

	template<typename T>
	inline void Console::Write(const T& value)
	{
		std::cout << value;
	}

	template<>
	inline void Console::Write<bool>(const bool& value)
	{
		value ? std::cout << "true" : std::cout << "false";
	}

	template<typename T, typename ...Other>
	inline void Console::Write(const T& value, const Other& ... values)
	{
		Write(value);
		Write(values...);
	}

	template<typename T, typename ...Other>
	inline void Console::WriteLine(const T& value, const Other& ... values)
	{
		Write(value);
		Write(values...);
		std::cout << std::endl;
	}
}




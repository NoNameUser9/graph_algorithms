//
// Created by User on 03.04.2024.
//

#pragma once

#include <cstdio>
#include <cstdarg>
#include <filesystem>

class Truba
{
	FILE *_pipe;
public:
	Truba() = default;
	~Truba()
	{
		flush();
		pclose(_pipe);
	}

	void
	pipe(const std::string &in)
	{

		if (!popen(in.c_str(), "w"))
			throw std::runtime_error("\npipe doesn't created\n");

		_pipe = popen(in.c_str(), "w");
	}

	int
	printf(const char *in, ...)
	{
		if (!_pipe)
			return 0;

		va_list args;
		va_start(args, in);
		int result = vfprintf(_pipe, in, args);
		va_end(args);

		return result;
	}

	void
	flush()
	{
		fflush(_pipe);
	}
};
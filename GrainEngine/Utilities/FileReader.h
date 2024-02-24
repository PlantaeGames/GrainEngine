#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Utilities/Errors/FileNotValidError.h"

namespace GrainEngine::Utilities
{
#define FILE_NOT_VALID_ERROR_MESSAGE "No File is not Valid."

	using namespace GrainEngine::Utilities::Errors;

	class FileReader
	{
	public:
		FileReader();
		FileReader(const std::string& fileName);
		~FileReader() noexcept = default;

		unsigned long long GetSize() const;

		void Open(const std::string& fileName, int openMode);
		void Close();
		void ReadAll(std::unique_ptr<byte[]>& pBuffer);

	private:
		bool ForceValid() const;

	private:
		mutable std::ifstream _file;
		bool _opened = false;
	};
}
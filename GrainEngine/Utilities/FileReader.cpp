#include "FileReader.h"

namespace GrainEngine::Utilities
{
	void FileReader::ReadAll(std::unique_ptr<byte[]>& pBuffer)
	{
		auto size = GetSize();

		if (_file.good() == false)
		{
			THROW_FILE_NOT_VALID_ERROR(FILE_NOT_VALID_ERROR_MESSAGE);
		}

		_file.seekg(0, std::ios::beg);
		_file.read(reinterpret_cast<char*>(pBuffer.get()), size);
	}

	void FileReader::Open(const std::string& fileName, int openMode)
	{
		Close();

		_file.open(fileName, openMode | std::ios::ate);	
	}

	void FileReader::Close()
	{
		ForceValid();

		_file.close();
		_opened = false;
	}

	unsigned long long FileReader::GetSize() const
	{
		ForceValid();

		return (unsigned long long)_file.tellg();
	}

	FileReader::FileReader(const std::string& fileName) :
		_file(fileName, std::ios::binary | std::ios::in | std::ios::ate),
		_opened(true)
	{}
	
	FileReader::FileReader() :
		_file(),
		_opened(false)
	{}

	bool FileReader::ForceValid() const
	{
		if (_opened)
			return true;

		THROW_FILE_NOT_VALID_ERROR(FILE_NOT_VALID_ERROR_MESSAGE);
	}
}
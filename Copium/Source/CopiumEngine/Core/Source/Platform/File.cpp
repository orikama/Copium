module;

#include <fstream>

module CopiumEngine.Core.Platform.File;


namespace Copium
{

    FileReader::FileReader(const std::filesystem::path& filePath, bool binary /*= false*/)
        : m_fileInputStream(filePath, binary ? std::ios::binary : 0)
    {}

    void FileReader::Read(void* data, int64 length)
    {
        m_fileInputStream.read(reinterpret_cast<char*>(data), length);
    }


    FileWriter::FileWriter(const std::filesystem::path& filePath, bool binary /*= false*/)
        : m_fileOutputStream(filePath, binary ? std::ios::binary : 0)
    {}

    void FileWriter::Write(const void* data, int64 length)
    {
        m_fileOutputStream.write(reinterpret_cast<const char*>(data), length);
    }

} // namespace Copium

#ifndef __DX_FILEUTILS_H__
#define __DX_FILEUTILS_H__

#include "DataBuf.h"
#include <string>
#include <vector>
#include <unordered_map>

class FileUtils {
public:
    static FileUtils* getInstance();
    bool init();
    virtual std::string getStringFromFile(const std::string& filename);
    virtual DataBuf getDataFromFile(const std::string& filename);
    unsigned char* getFileData(
            const std::string& filename,
            const char* mode,
            ssize_t *size);
    std::string getNewFilename(const std::string &filename) const;
    std::string fullPathForFilename(const std::string &filename) const;
    void setSearchPaths(const std::vector<std::string>& searchPaths);
    void addSearchPath(const std::string &searchpath,const bool front);
    std::string getFullPathForDirectoryAndFilename(
            const std::string& directory,
            const std::string& filename) const;
    bool isFileExist(const std::string& filename) const;
    bool isAbsolutePath(const std::string& path) const;
    bool isDirectoryExist(const std::string& dirPath) const;
    long getFileSize(const std::string &filepath);
    std::string getFileExtension(const std::string& filePath) const;
private:
    DataBuf getData(const std::string& filename, bool forString);
    std::string getPathForFilename(
            const std::string& filename,
            const std::string& resolutionDirectory,
            const std::string& searchPath) const;
    bool isDirectoryExistInternal(const std::string& dirPath) const;
    bool isFileExistInternal(const std::string& strFilePath) const;
    std::string getSuitableFOpen(const std::string& filenameUtf8) const;
    std::vector<std::string> m_searchPathVec;
    std::vector<std::string> m_searchResolutionsOrderVec;
    std::string m_defaultResRootPath;
    mutable std::unordered_map<std::string, std::string> m_fullPathCache;
    std::string m_writablePath;
};

#endif // __DX_FILEUTILS_H__

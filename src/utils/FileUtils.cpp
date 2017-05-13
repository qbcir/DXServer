#include "../GameServer.h"
#include <algorithm>
#include <sys/stat.h>

bool FileUtils::init() {
    // get application path
    char fullpath[256] = {0};
    ssize_t length = readlink("/proc/self/exe", fullpath, sizeof(fullpath)-1);
    if (length <= 0) {
        return false;
    }
    fullpath[length] = '\0';
    std::string appPath = fullpath;
    m_defaultResRootPath = appPath.substr(0, appPath.find_last_of("/"));
    m_defaultResRootPath += "/";
    // Set writable path to $XDG_CONFIG_HOME or ~/.config/<app name>/ if $XDG_CONFIG_HOME not exists.
    const char* xdg_config_path = getenv("XDG_CONFIG_HOME");
    std::string xdgConfigPath;
    if (xdg_config_path == NULL) {
        xdgConfigPath = getenv("HOME");
        xdgConfigPath += "/.config";
    } else {
        xdgConfigPath  = xdg_config_path;
    }
    //_writablePath = xdgConfigPath;
    //_writablePath += appPath.substr(appPath.find_last_of("/"));
    //_writablePath += "/";
    m_searchPathVec.push_back(m_defaultResRootPath);
    m_searchResolutionsOrderVec.push_back("");
    return true;
}

FileUtils* FileUtils::getInstance() {
    GameServer::getInstance()->getFileUtils();
}

DataBuf FileUtils::getData(const std::string& filename, bool forString) {
    if (filename.empty()) {
        return DataBuf();
    }
    DataBuf ret;
    unsigned char* buffer = nullptr;
    size_t size = 0;
    size_t readsize;
    const char* mode = nullptr;
    if (forString)
        mode = "rt";
    else
        mode = "rb";
    do
    {
        // Read the file from hardware
        std::string fullPath = fullPathForFilename(filename);
        FILE *fp = fopen(getSuitableFOpen(fullPath).c_str(), mode);
        if (!fp) break;
        fseek(fp,0,SEEK_END);
        size = ftell(fp);
        fseek(fp,0,SEEK_SET);
        if (forString) {
            buffer = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1));
            buffer[size] = '\0';
        }
        else {
            buffer = (unsigned char*)malloc(sizeof(unsigned char) * size);
        }
        readsize = fread(buffer, sizeof(unsigned char), size, fp);
        fclose(fp);
        if (forString && readsize < size) {
            buffer[readsize] = '\0';
        }
    } while (0);
    if (nullptr == buffer || 0 == readsize) {
        //CCLOG("Get data from file %s failed", filename.c_str());
    }
    else {
        ret.fastSet(buffer, readsize);
    }
    return ret;
}

std::string FileUtils::getStringFromFile(const std::string& filename) {
    DataBuf data = getData(filename, true);
    return data.isNull() ? "" : data.toString();
}

DataBuf FileUtils::getDataFromFile(const std::string& filename) {
    return getData(filename, false);
}

std::string FileUtils::getNewFilename(const std::string &filename) const {
    return filename;
}

std::string FileUtils::getPathForFilename(const std::string& filename, const std::string& resolutionDirectory, const std::string& searchPath) const {
    std::string file = filename;
    std::string file_path = "";
    size_t pos = filename.find_last_of("/");
    if (pos != std::string::npos)
    {
        file_path = filename.substr(0, pos+1);
        file = filename.substr(pos+1);
    }

    // searchPath + file_path + resourceDirectory
    std::string path = searchPath;
    path += file_path;
    path += resolutionDirectory;
    path = getFullPathForDirectoryAndFilename(path, file);
    //CCLOG("getPathForFilename, fullPath = %s", path.c_str());
    return path;
}


std::string FileUtils::fullPathForFilename(const std::string &filename) const {
    if (filename.empty()) {
        return "";
    }
    if (isAbsolutePath(filename)) {
        return filename;
    }
    // Already Cached ?
    auto cacheIter = m_fullPathCache.find(filename);
    if(cacheIter != m_fullPathCache.end())
    {
        return cacheIter->second;
    }
    // Get the new file name.
    const std::string newFilename(getNewFilename(filename));
    std::string fullpath;
    for (const auto& searchIt : m_searchPathVec) {
        for (const auto& resolutionIt : m_searchResolutionsOrderVec) {
            fullpath = this->getPathForFilename(newFilename, resolutionIt, searchIt);
            if (!fullpath.empty()) {
                // Using the filename passed in as key.
                m_fullPathCache.insert(std::make_pair(filename, fullpath));
                return fullpath;
            }

        }
    }
    // The file wasn't found, return empty string.
    return "";
}


unsigned char* FileUtils::getFileData(const std::string& filename, const char* mode, ssize_t *size) {
    unsigned char * buffer = nullptr;
    //CCASSERT(!filename.empty() && size != nullptr && mode != nullptr, "Invalid parameters.");
    *size = 0;
    do
    {
        // read the file from hardware
        const std::string fullPath = fullPathForFilename(filename);
        FILE *fp = fopen(getSuitableFOpen(fullPath).c_str(), mode);
        if (!fp) break;
        fseek(fp,0,SEEK_END);
        *size = ftell(fp);
        fseek(fp,0,SEEK_SET);
        buffer = (unsigned char*)malloc(*size);
        *size = fread(buffer,sizeof(unsigned char), *size,fp);
        fclose(fp);
    } while (0);

    if (!buffer)
    {
        std::string msg = "Get data from file(";
        msg.append(filename).append(") failed!");

        //CCLOG("%s", msg.c_str());
    }
    return buffer;
}

void FileUtils::setSearchPaths(const std::vector<std::string>& searchPaths) {
    bool existDefaultRootPath = false;
    m_fullPathCache.clear();
    m_searchPathVec.clear();
    for (const auto& iter : searchPaths) {
        std::string prefix;
        std::string path;

        if (!isAbsolutePath(iter))
        { // Not an absolute path
            prefix = m_defaultResRootPath;
        }
        path = prefix + (iter);
        if (!path.empty() && path[path.length()-1] != '/')
        {
            path += "/";
        }
        if (!existDefaultRootPath && path == m_defaultResRootPath)
        {
            existDefaultRootPath = true;
        }
        m_searchPathVec.push_back(path);
    }
    if (!existDefaultRootPath) {
        //CCLOG("Default root path doesn't exist, adding it.");
        m_searchPathVec.push_back(m_defaultResRootPath);
    }
}

void FileUtils::addSearchPath(const std::string &searchpath,const bool front) {
    std::string prefix;
    if (!isAbsolutePath(searchpath))
        prefix = m_defaultResRootPath;
    std::string path = prefix + searchpath;
    if (!path.empty() && path[path.length()-1] != '/') {
        path += "/";
    }
    if (front) {
        m_searchPathVec.insert(m_searchPathVec.begin(), path);
    } else {
        m_searchPathVec.push_back(path);
    }
}

std::string FileUtils::getFullPathForDirectoryAndFilename(const std::string& directory, const std::string& filename) const {
    // get directory+filename, safely adding '/' as necessary
    std::string ret = directory;
    if (directory.size() && directory[directory.size()-1] != '/'){
        ret += '/';
    }
    ret += filename;
    // if the file doesn't exist, return an empty string
    if (!isFileExistInternal(ret)) {
        ret = "";
    }
    return ret;
}

bool FileUtils::isFileExist(const std::string& filename) const {
    if (isAbsolutePath(filename)) {
        return isFileExistInternal(filename);
    }
    else {
        std::string fullpath = fullPathForFilename(filename);
        if (fullpath.empty())
            return false;
        else
            return true;
    }
}

bool FileUtils::isAbsolutePath(const std::string& path) const {
    return (path.at(0) == '/');
}

bool FileUtils::isDirectoryExist(const std::string& dirPath) const {
    //CCASSERT(!dirPath.empty(), "Invalid path");
    if (isAbsolutePath(dirPath)) {
        return isDirectoryExistInternal(dirPath);
    }
    // Already Cached ?
    auto cacheIter = m_fullPathCache.find(dirPath);
    if( cacheIter != std::end(m_fullPathCache)) {
        return isDirectoryExistInternal(cacheIter->second);
    }
    std::string fullpath;
    for (const auto& searchIt : m_searchPathVec) {
        for (const auto& resolutionIt : m_searchResolutionsOrderVec) {
            // searchPath + file_path + resourceDirectory
            fullpath = searchIt + dirPath + resolutionIt;
            if (isDirectoryExistInternal(fullpath)) {
                m_fullPathCache.insert(std::make_pair(dirPath, fullpath));
                return true;
            }
        }
    }
    return false;
}

long FileUtils::getFileSize(const std::string &filepath) {
    //CCASSERT(!filepath.empty(), "Invalid path");
    std::string fullpath = filepath;
    if (!isAbsolutePath(filepath)) {
        fullpath = fullPathForFilename(filepath);
        if (fullpath.empty())
            return 0;
    }
    struct stat info;
    // Get data associated with "crt_stat.c":
    int result = stat(fullpath.c_str(), &info);
    // Check if statistics are valid:
    if (result != 0) {
        // Failed
        return -1;
    }
    else {
        return (long)(info.st_size);
    }
}

std::string FileUtils::getFileExtension(const std::string& filePath) const {
    std::string fileExtension;
    size_t pos = filePath.find_last_of('.');
    if (pos != std::string::npos)
    {
        fileExtension = filePath.substr(pos, filePath.length());
        std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);
    }
    return fileExtension;
}

bool FileUtils::isDirectoryExistInternal(const std::string& dirPath) const {
    struct stat st;
    if (stat(dirPath.c_str(), &st) == 0)
    {
        return S_ISDIR(st.st_mode);
    }
    return false;
}

bool FileUtils::isFileExistInternal(const std::string& strFilePath) const {
    if (strFilePath.empty()) {
        return false;
    }
    std::string strPath = strFilePath;
    if (!isAbsolutePath(strPath)) { // Not absolute path, add the default root path at the beginning.
        strPath.insert(0, m_defaultResRootPath);
    }
    struct stat sts;
    return (stat(strPath.c_str(), &sts) != -1) ? true : false;
}

std::string FileUtils::getSuitableFOpen(const std::string& filenameUtf8) const {
    return filenameUtf8;
}



--------------------------------
-- @module FileUtils
-- @parent_module dx

--------------------------------
-- 
-- @function [parent=#FileUtils] isFileExist 
-- @param self
-- @param #string filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] fullPathForFilename 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getFileData 
-- @param self
-- @param #string filename
-- @param #char mode
-- @param #long size
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] setSearchPaths 
-- @param self
-- @param #array_table searchPaths
-- @return FileUtils#FileUtils self (return value: FileUtils)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getStringFromFile 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getFileExtension 
-- @param self
-- @param #string filePath
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getFileSize 
-- @param self
-- @param #string filepath
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] isDirectoryExist 
-- @param self
-- @param #string dirPath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getDataFromFile 
-- @param self
-- @param #string filename
-- @return DataBuf#DataBuf ret (return value: DataBuf)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getNewFilename 
-- @param self
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] isAbsolutePath 
-- @param self
-- @param #string path
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] addSearchPath 
-- @param self
-- @param #string searchpath
-- @param #bool front
-- @return FileUtils#FileUtils self (return value: FileUtils)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getFullPathForDirectoryAndFilename 
-- @param self
-- @param #string directory
-- @param #string filename
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#FileUtils] getInstance 
-- @param self
-- @return FileUtils#FileUtils ret (return value: FileUtils)
        
return nil

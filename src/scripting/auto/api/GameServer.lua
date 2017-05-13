
--------------------------------
-- @module GameServer
-- @parent_module dx

--------------------------------
-- 
-- @function [parent=#GameServer] sendOutgoingPackets 
-- @param self
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getFileUtils 
-- @param self
-- @return FileUtils#FileUtils ret (return value: FileUtils)
        
--------------------------------
-- 
-- @function [parent=#GameServer] run 
-- @param self
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] setOnNewClientCb 
-- @param self
-- @param #function cb
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getGameObject 
-- @param self
-- @param #unsigned long long netId
-- @return std::shared_ptr<GameObject>#std::shared_ptr<GameObject> ret (return value: std::shared_ptr<GameObject>)
        
--------------------------------
-- 
-- @function [parent=#GameServer] removeGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> obj
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] unregisterGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> obj
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getObjectManager 
-- @param self
-- @return ObjectManager#ObjectManager ret (return value: ObjectManager)
        
--------------------------------
-- 
-- @function [parent=#GameServer] checkForDisconnects 
-- @param self
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] start 
-- @param self
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getScene 
-- @param self
-- @return std::shared_ptr<Scene>#std::shared_ptr<Scene> ret (return value: std::shared_ptr<Scene>)
        
--------------------------------
-- 
-- @function [parent=#GameServer] addGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> obj
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] setStateDirty 
-- @param self
-- @param #unsigned long long netId
-- @param #unsigned int dirtyState
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] registerGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> obj
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getLuaState 
-- @param self
-- @return LuaState#LuaState ret (return value: LuaState)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getTimestamp 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#GameServer] releaseInstance 
-- @param self
-- @return GameServer#GameServer self (return value: GameServer)
        
--------------------------------
-- 
-- @function [parent=#GameServer] getInstance 
-- @param self
-- @return GameServer#GameServer ret (return value: GameServer)
        
return nil

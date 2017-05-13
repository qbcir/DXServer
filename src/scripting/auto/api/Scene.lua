
--------------------------------
-- @module Scene
-- @extend LuaRef
-- @parent_module dx

--------------------------------
-- 
-- @function [parent=#Scene] addGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> go
-- @return Scene#Scene self (return value: Scene)
        
--------------------------------
-- 
-- @function [parent=#Scene] update 
-- @param self
-- @param #float dt
-- @return Scene#Scene self (return value: Scene)
        
--------------------------------
-- 
-- @function [parent=#Scene] removeGameObject 
-- @param self
-- @param #std::shared_ptr<GameObject> go
-- @return Scene#Scene self (return value: Scene)
        
--------------------------------
-- 
-- @function [parent=#Scene] createGameObject 
-- @param self
-- @param #string key
-- @param #int objType
-- @return std::shared_ptr<GameObject>#std::shared_ptr<GameObject> ret (return value: std::shared_ptr<GameObject>)
        
--------------------------------
-- 
-- @function [parent=#Scene] create 
-- @param self
-- @return std::shared_ptr<Scene>#std::shared_ptr<Scene> ret (return value: std::shared_ptr<Scene>)
        
return nil

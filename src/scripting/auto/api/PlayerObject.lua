
--------------------------------
-- @module PlayerObject
-- @extend Vehicle
-- @parent_module dx

--------------------------------
-- 
-- @function [parent=#PlayerObject] writeTypeInfoBytes 
-- @param self
-- @param #array_table buf
-- @return unsigned long#unsigned long ret (return value: unsigned long)
        
--------------------------------
-- 
-- @function [parent=#PlayerObject] setClient 
-- @param self
-- @param #std::shared_ptr<ClientProxy> client
-- @return PlayerObject#PlayerObject self (return value: PlayerObject)
        
--------------------------------
-- 
-- @function [parent=#PlayerObject] update 
-- @param self
-- @param #float dt
-- @return PlayerObject#PlayerObject self (return value: PlayerObject)
        
--------------------------------
-- 
-- @function [parent=#PlayerObject] createFromDesc 
-- @param self
-- @param #std::shared_ptr<PlayerDesc> desc
-- @return std::shared_ptr<GameObject>#std::shared_ptr<GameObject> ret (return value: std::shared_ptr<GameObject>)
        
return nil

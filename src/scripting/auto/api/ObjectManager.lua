
--------------------------------
-- @module ObjectManager
-- @parent_module dx

--------------------------------
-- 
-- @function [parent=#ObjectManager] removeGameObjectDesc 
-- @param self
-- @param #std::shared_ptr<GameObjectDesc> obj
-- @return std::shared_ptr<GameObjectDesc>#std::shared_ptr<GameObjectDesc> ret (return value: std::shared_ptr<GameObjectDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] getGameObjectDesc 
-- @param self
-- @param #string label
-- @return std::shared_ptr<GameObjectDesc>#std::shared_ptr<GameObjectDesc> ret (return value: std::shared_ptr<GameObjectDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] removeVehicleDesc 
-- @param self
-- @param #std::shared_ptr<VehicleDesc> obj
-- @return std::shared_ptr<VehicleDesc>#std::shared_ptr<VehicleDesc> ret (return value: std::shared_ptr<VehicleDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] addBulletDesc 
-- @param self
-- @param #std::shared_ptr<BulletDesc> obj
-- @return std::shared_ptr<BulletDesc>#std::shared_ptr<BulletDesc> ret (return value: std::shared_ptr<BulletDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] clearPlayerDescs 
-- @param self
-- @return ObjectManager#ObjectManager self (return value: ObjectManager)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] getVehicleDesc 
-- @param self
-- @param #string label
-- @return std::shared_ptr<VehicleDesc>#std::shared_ptr<VehicleDesc> ret (return value: std::shared_ptr<VehicleDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] clearGameObjectDescs 
-- @param self
-- @return ObjectManager#ObjectManager self (return value: ObjectManager)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] createObject 
-- @param self
-- @param #string key
-- @param #int objType
-- @return std::shared_ptr<GameObject>#std::shared_ptr<GameObject> ret (return value: std::shared_ptr<GameObject>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] clearVehicleDescs 
-- @param self
-- @return ObjectManager#ObjectManager self (return value: ObjectManager)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] removeBulletDesc 
-- @param self
-- @param #std::shared_ptr<BulletDesc> obj
-- @return std::shared_ptr<BulletDesc>#std::shared_ptr<BulletDesc> ret (return value: std::shared_ptr<BulletDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] addGameObjectDesc 
-- @param self
-- @param #std::shared_ptr<GameObjectDesc> obj
-- @return std::shared_ptr<GameObjectDesc>#std::shared_ptr<GameObjectDesc> ret (return value: std::shared_ptr<GameObjectDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] removePlayerDesc 
-- @param self
-- @param #std::shared_ptr<PlayerDesc> obj
-- @return std::shared_ptr<PlayerDesc>#std::shared_ptr<PlayerDesc> ret (return value: std::shared_ptr<PlayerDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] getPlayerDesc 
-- @param self
-- @param #string label
-- @return std::shared_ptr<PlayerDesc>#std::shared_ptr<PlayerDesc> ret (return value: std::shared_ptr<PlayerDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] addVehicleDesc 
-- @param self
-- @param #std::shared_ptr<VehicleDesc> obj
-- @return std::shared_ptr<VehicleDesc>#std::shared_ptr<VehicleDesc> ret (return value: std::shared_ptr<VehicleDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] addPlayerDesc 
-- @param self
-- @param #std::shared_ptr<PlayerDesc> obj
-- @return std::shared_ptr<PlayerDesc>#std::shared_ptr<PlayerDesc> ret (return value: std::shared_ptr<PlayerDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] getBulletDesc 
-- @param self
-- @param #string label
-- @return std::shared_ptr<BulletDesc>#std::shared_ptr<BulletDesc> ret (return value: std::shared_ptr<BulletDesc>)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] clearBulletDescs 
-- @param self
-- @return ObjectManager#ObjectManager self (return value: ObjectManager)
        
--------------------------------
-- 
-- @function [parent=#ObjectManager] getInstance 
-- @param self
-- @return ObjectManager#ObjectManager ret (return value: ObjectManager)
        
return nil

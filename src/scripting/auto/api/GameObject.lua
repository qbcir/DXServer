
--------------------------------
-- @module GameObject
-- @extend LuaRef
-- @parent_module dx

--------------------------------
-- @overload self, std::shared_ptr<GameObject>         
-- @overload self, int         
-- @function [parent=#GameObject] canCollideWith
-- @param self
-- @param #int klass
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#GameObject] getDirection 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setCollisionMask 
-- @param self
-- @param #unsigned int mask
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] onCollision 
-- @param self
-- @param #std::shared_ptr<GameObject> obj
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setVelocity 
-- @param self
-- @param #b2Vec2 vel
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setAccel 
-- @param self
-- @param #b2Vec2 accel
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setCollisionClass 
-- @param self
-- @param #int klass
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] enableCollisionsWith 
-- @param self
-- @param #int klass
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getVelocity 
-- @param self
-- @return b2Vec2#b2Vec2 ret (return value: b2Vec2)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setDirection 
-- @param self
-- @param #float direction
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setNetId 
-- @param self
-- @param #unsigned long long id
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] isDead 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GameObject] writeStateBytes 
-- @param self
-- @param #array_table buf
-- @param #unsigned int state
-- @return unsigned long#unsigned long ret (return value: unsigned long)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setIdxInScene 
-- @param self
-- @param #int idx
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getCollisionMask 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#GameObject] update 
-- @param self
-- @param #float dt
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getFullStateMask 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setPosition 
-- @param self
-- @param #b2Vec2 pos
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] changeDirection 
-- @param self
-- @param #float delta
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getPosition 
-- @param self
-- @return b2Vec2#b2Vec2 ret (return value: b2Vec2)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getSpeed 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#GameObject] applyAccel 
-- @param self
-- @param #b2Vec2 accel
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#GameObject] setDead
-- @param self
-- @param #bool dead
-- @return GameObject#GameObject self (return value: GameObject)

--------------------------------
-- 
-- @function [parent=#GameObject] writeTypeInfoBytes 
-- @param self
-- @param #array_table buf
-- @return unsigned long#unsigned long ret (return value: unsigned long)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setSpeed 
-- @param self
-- @param #float speed
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getCollisionClass 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getNetId 
-- @param self
-- @return unsigned long long#unsigned long long ret (return value: unsigned long long)
        
--------------------------------
-- 
-- @function [parent=#GameObject] getIdxInScene 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#GameObject] setAngVelocity 
-- @param self
-- @param #float rotation
-- @return GameObject#GameObject self (return value: GameObject)
        
--------------------------------
-- 
-- @function [parent=#GameObject] createFromDesc 
-- @param self
-- @param #std::shared_ptr<GameObjectDesc> desc
-- @return std::shared_ptr<GameObject>#std::shared_ptr<GameObject> ret (return value: std::shared_ptr<GameObject>)
        
return nil

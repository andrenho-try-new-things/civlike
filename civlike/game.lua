local pp = require 'pprint'

Game = {}

function Game.new(module_name)
   assert(type(module_name) == "string")

   local G = setmetatable({}, { __index = Game })
   G:load_module(module_name)
   return G
end

function Game:load_module(module_name)
   -- love.filesystem.mount(filename .. ".zip", filename)
   self.module_name = module_name
   local chunk, err = love.filesystem.load(self.gamepath .. "/main.lua")
   if err then error(err) end
   self.module = chunk()
   self.config = self.custom.conf()
end


return Game

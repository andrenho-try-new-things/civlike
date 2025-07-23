local pp = require 'pprint'

Game = {}

function Game.new(filename)
   assert(type(filename) == "string")

   local G = setmetatable({}, { __index = Game })
   G:load(filename)
   return G
end

function Game:load(filename)
   -- love.filesystem.mount(filename .. ".zip", filename)
   self.gamepath = filename
   local chunk, err = love.filesystem.load(self.gamepath .. "/main.lua")
   if err then error(err) end
   self.conf = chunk()
   pp(self.conf.conf())
end


return Game

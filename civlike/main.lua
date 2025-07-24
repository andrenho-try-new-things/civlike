local Game = require "game"

local G = nil

function love.load()
   love.filesystem.setIdentity(love.filesystem.getIdentity(), true)
   love.graphics.setDefaultFilter("nearest")
   G = Game.new("sample")
end

function love.draw()
   love.graphics.print("Hello world", 400, 300)
end

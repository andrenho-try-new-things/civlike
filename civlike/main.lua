local Game = require "game"

G = nil

function love.load()
   love.graphics.setDefaultFilter("nearest")
   G = Game.new("sample")
end

function love.draw()
   love.graphics.print("Hello world", 400, 300)
end

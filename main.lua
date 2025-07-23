function love.load()
   love.graphics.setDefaultFilter("nearest")
end

function love.draw()
   love.graphics.print("Hello world", 400, 300)
end

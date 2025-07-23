Game = {}

function Game.new(filename)
   assert(type(filename) == "string")

   local G = setmetatable({}, { __index = Game })
   G:load(filename)
   return G
end

function Game:load(filename)
   print(filename)
end


return Game

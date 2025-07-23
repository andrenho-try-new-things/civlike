local S = {}

function S.conf()
   return {
      tile = { width = 16, height = 16 },
      default_zoom = 2,
      terrains = {
         grassland = {},
         ocean = {},
      }
   }
end

return S

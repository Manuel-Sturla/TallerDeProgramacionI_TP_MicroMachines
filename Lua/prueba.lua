--[[Empiezo la prueba de Lua
	Veamos que logramos...]]
print("Hola Mundo")


print("Creo el mapa")

local mapa = crear_mapa(5,5)
-- mapa[0][0] = 0
print("El mapa es")
print(mapa)

function obtener_nueva_posicion(mapa, posicion) --puede recibir algo mas
	if mapa[posicion[1]-1][mapa[posicion[2]]] == 0 then
		local nueva_posicion = {posicion[1]-1, posicion[2]}
		return nueva_posicion
	else return posicion
end


function crear_mapa(filas, columnas)
	local mapa = {}
	for i=0, filas-1 do
		local fila = {}
		mapa[i] = fila
		for j=0, columnas-1 do
			fila[j] = 0
		end
	end
	return mapa
end


print(obtener_nueva_posicion(mapa, {1,0}))
end
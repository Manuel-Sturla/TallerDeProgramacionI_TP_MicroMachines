--[[Empiezo la prueba de Lua
	Veamos que logramos...]]
print("Hola Mundo")





function obtener_nueva_posicion (mapa, posicion) --puede recibir algo mas
	if mapa[posicion[1]-1][mapa[posicion[1]]] == 0 then
		local nueva_posicion = {posicion[1]-1, posicion[2]}
		return nueva_posicion
	else 
		return posicion
	end
end

print("LOUSS")
function crear_mapa (filas, columnas)
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
print("Creo el mapa")

local mapa = crear_mapa(5,5)
-- mapa[0][0] = 0
print("El mapa es")
function imprimir_matriz(matriz)
	for k,v in pairs(matriz) do
		for i,j in pairs(v) do
			io.write(j)
		end
		print()
	end
end
--[[
mapa = {[{0,0}]=0,
			  [{0,1}]=0,
			  [{1,0}]=0, 
			  [{1,1}]=0
			 }
]]
imprimir_matriz(mapa)
print("Actualizo la posicion")
function imprimir_tabla(tabla)
	for k,v in pairs(tabla) do
		io.write(v)
	end
	print()
end
imprimir_tabla(obtener_nueva_posicion(mapa , {1,0}))

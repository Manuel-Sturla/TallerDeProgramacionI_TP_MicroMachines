-- Script para manejar el JugadorCPU
-- CONSTANTES

MOVER_IZQ = "A"
MOVER_DER = "D"
ACELERAR = "W"
FRENAR = "S"
PASTO = "Pasto"
CURVA = "Curva"
ASFALTO = "Asfalto"
SEPARADOR = ","

mapa = {}

-- Funciones Auxiliares
function split(cadena, separador)
	elementos = {}
	for subcad in string.gmatch(cadena, "[^"..separador.."]+") do
		table.insert(elementos, subcad)
	end	
	return elementos
end

function imprimir_matriz(matriz)
	for k,v in pairs(matriz) do
		--[[
		for i,j in pairs(v) do
			io.write(j)
		end
		]]
		imprimir_tabla(v)
		print()
	end
end
function imprimir_tabla(tabla)
	for k,v in pairs(tabla) do
		
		io.write(k)
		io.write(" = ")
		io.write(v)
		io.write(", ")
	end
end
--[[
imprimir_tabla(split('321-022', "-"))
pos1, pos2 = split("3-2", "-")
]]

function agregarPiso(tipo, x, y, ang)
	if tipo == CURVA then
		tipo = tipo .. math.floor(tonumber(ang))
	end
	x = math.floor(tonumber(x))
	y = math.floor(tonumber(y))
	mapa[x .. SEPARADOR .. y] = tipo
end
-- Funciones del Script
function MostrarMapa()
	imprimir_tabla(mapa)
end

function crearMapa(datosMapa)
	tipo = ASFALTO
	x = 0
	y = 0
	ang = 0
	for i,dato in pairs(datosMapa) do
		resto = (i-1)%4
		if resto == 0 then
			agregarPiso(tipo, x, y, ang)
			tipo = dato
		elseif resto == 1 then
			x = dato
		elseif resto == 2 then
			y = dato
		elseif resto == 3 then
			ang = dato
		end
	end	
	agregarPiso(tipo, x, y, ang)
end


function obtenerNuevaPos(posActual, mod1, mod2, dir)
	if dir == nil then 
		dir = 1
	end
	tablaNueva = {math.tointeger(posActual[1] + mod1*dir), math.tointeger(posActual[2] + mod2*dir)}
	return tablaNueva  
end

function hayPastoIzq(pos)
	elementos = split(pos, SEPARADOR)
	pos_izq = table.concat(obtenerNuevaPos(elementos, 0,-1) , SEPARADOR)
	pos_izq_adelante = table.concat(obtenerNuevaPos(elementos, -1,-1), SEPARADOR)
	--print("Posiciones a chequear: ", pos_izq, pos_izq_adelante)
	return mapa[pos_izq] == PASTO or mapa[pos_izq_adelante] == PASTO
end
function hayPastoDer(pos)
	elementos = split(pos, SEPARADOR)
	pos_der = table.concat(obtenerNuevaPos(elementos, 0, 1) , SEPARADOR)
	pos_der_adelante = table.concat(obtenerNuevaPos(elementos, -1, 1), SEPARADOR)
	return mapa[pos_der] == PASTO or mapa[pos_der_adelante] == PASTO
end

function hayPastoEnf(pos)
	elementos = split(pos, SEPARADOR)
	pos_enfrente = table.concat(obtenerNuevaPos(elementos, -1, 0) , SEPARADOR)
	return mapa[pos_enfrente] == PASTO
end

function obtenerNuevaAccion(posAuto, posOtros, posExtras)
	--local posActual = split(posAuto, separador)

	-- Necesito saber hacia que lado esta avanzando? podria ser un indicador que modifica un +/- en el resto
	-- esto no funciona bien porque podría cambiar una coordenada si esta yendo para abajo en vez de arriba, 
	-- pero ni idea de como hacer si esta yendo para uno de los costados!!
	if hayPastoIzq(posAuto) then return MOVER_DER end
	if hayPastoDer(posAuto) then return MOVER_IZQ end
	if hayPastoEnf(posAuto) then return FRENAR end
	return ACELERAR
end
--[[
crearMapa({"0-0", "0-1", "0-2"})
print(obtenerNuevaAccion("1-1"))
]]
-- Script para manejar el JugadorCPU
-- CONSTANTES

MOVER_IZQ = "A"
MOVER_DER = "D"
ACELERAR = "W"
FRENAR = "S"
PASTO = "P"
SEPARADOR = "-"

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

-- Funciones del Script
function crearMapa(posPasto)
	for i,pos in pairs(posPasto) do
		--pos = split(valor, SEPARADOR)
		mapa[pos] = PASTO
	end	
	imprimir_tabla(mapa)
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
	print("Posiciones a chequear: ", pos_izq, pos_izq_adelante)
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

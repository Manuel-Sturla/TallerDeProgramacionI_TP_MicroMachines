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

function round(x)
  return x>=0 and math.floor(x+0.5) or math.ceil(x-0.5)
end

function agregarPiso(tipo, x, y, ang)
	if tipo == CURVA then
		tipo = tipo .. math.floor(tonumber(ang))
	end
	x = math.floor(tonumber(x)/4)
	y = math.floor(tonumber(y)/4)
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

function obtenerAnguloAprox(angulo)
	aux = angulo
	while math.abs(aux // 360) > 1 do
		if aux < 0 then
			aux = aux + 360 * math.abs(aux // 360)
		else
			aux = aux - 360 * math.abs(aux // 360)
		end
	end
	print("Angulo normalizado", aux)
	if math.abs(aux) <= 15 then return 0 end
	if math.abs(aux - 90) <= 15 then return 90 end
	if math.abs(aux - 180) <= 15  then return 180 end
	if math.abs(aux - 270) <= 15 then return 270 end
	return nil
end
pos_anterior = "0,0"
ultimoMov = ACELERAR
anguloEsperado = nil
function obtenerNuevaAccion(posAuto, angulo)
	separados = split(posAuto, SEPARADOR)
	x_actual = round(tonumber(separados[1])/4)
	y_actual = round(tonumber(separados[2])/4)
	posActual = x_actual .. SEPARADOR .. y_actual
	anguloAprox = obtenerAnguloAprox(angulo)
	if not anguloAprox then return ultimoMov end
	if anguloEsperado then
		if anguloAprox ~= anguloEsperado then 
			return ultimoMov
		end
	end
	movimiento = ACELERAR
	if anguloAprox == 90 then
		--No hay pasto enfrente
		print("Que hay enfrente en el mapa: ", mapa[x_actual .. SEPARADOR .. (y_actual+1)])
		if mapa[x_actual .. SEPARADOR .. (y_actual-1)] ~= PASTO then
			movimiento = ACELERAR
		-- No hay pasto a la izq
		elseif mapa[(x_actual-1) .. SEPARADOR .. y_actual] ~= PASTO then
			anguloEsperado = 180
			movimiento = MOVER_IZQ
		-- Hay pasto a la der
		elseif mapa[(x_actual+1) .. SEPARADOR .. y_actual] ~= PASTO then
			anguloEsperado = 0
			movimiento = MOVER_DER
		else
			movimiento = FRENAR
		end
	elseif anguloAprox == 0 then
		--No hay pasto enfrente
		if mapa[x_actual+1 .. SEPARADOR .. (y_actual)] ~= PASTO then
			movimiento = ACELERAR
		-- No hay pasto a la izq
		elseif mapa[(x_actual) .. SEPARADOR .. y_actual-1] ~= PASTO then
			anguloEsperado = 90
			movimiento = MOVER_IZQ
		-- Hay pasto a la der
		elseif mapa[(x_actual) .. SEPARADOR .. y_actual+1] ~= PASTO then
			anguloEsperado = 270
			movimiento = MOVER_DER
		else
			movimiento = FRENAR
		end
	elseif anguloAprox == 180 then
		--No hay pasto enfrente
		if mapa[x_actual-1 .. SEPARADOR .. (y_actual)] ~= PASTO then
			movimiento = ACELERAR
		-- No hay pasto a la izq
		elseif mapa[(x_actual) .. SEPARADOR .. y_actual+1] ~= PASTO then
			anguloEsperado = 270
			movimiento = MOVER_IZQ
		-- Hay pasto a la der
		elseif mapa[(x_actual) .. SEPARADOR .. y_actual-1] ~= PASTO then
			anguloEsperado = 90
			movimiento = MOVER_DER
		else
			movimiento = FRENAR
		end
	elseif anguloAprox == 270 then
		--No hay pasto enfrente
		if mapa[x_actual .. SEPARADOR .. (y_actual+1)] ~= PASTO then
			movimiento = ACELERAR
		-- No hay pasto a la izq
		elseif mapa[(x_actual-1) .. SEPARADOR .. y_actual] ~= PASTO then
			anguloEsperado = 180
			movimiento = MOVER_DER
		-- Hay pasto a la der
		elseif mapa[(x_actual+1) .. SEPARADOR .. y_actual] ~= PASTO then
			anguloEsperado = 0
			movimiento = MOVER_IZQ
		else
			movimiento = FRENAR
		end					
	end


--[[]	separados = split(pos_anterior, SEPARADOR)
	x_ant = tonumber(separados[1])
	y_ant = tonumber(separados[2])

	--Faltaria chequear si la diferencia es muy grande por si exploto
	dif_x = x_actual - x_ant
	dif_y = y_actual - y_ant
	if dif_x > 1 or dif_y > 1 then
		pos_anterior = posActual
		return ACELERAR
	end
	x_sig = x_actual + dif_x
	y_sig = y_actual + dif_y

	posSiguiente = x_sig .. SEPARADOR .. y_sig
	print("Pos sig: ", posSiguiente, ".Mapa: ", mapa[posSiguiente])
	if mapa[posSiguiente] == ASFALTO then 
		movimiento = ACELERAR
	elseif mapa[posSiguiente] == (CURVA .. 0) then 
		movimiento = MOVER_DER
	elseif mapa[posSiguiente] == (CURVA .. 90) then 
		movimiento = MOVER_DER 
	elseif mapa[posSiguiente] == (CURVA .. 180) then 
		movimiento = MOVER_DER
	elseif mapa[posSiguiente] == (CURVA .. 270) then 
		movimiento = MOVER_DER
	elseif mapa[posSiguiente] == PASTO then 
		movimiento = FRENAR
	end
	pos_anterior = posActual
	--local posActual = split(posAuto, separador)

	-- Necesito saber hacia que lado esta avanzando? podria ser un indicador que modifica un +/- en el resto
	-- esto no funciona bien porque podría cambiar una coordenada si esta yendo para abajo en vez de arriba, 
	-- pero ni idea de como hacer si esta yendo para uno de los costados!!
	--if hayPastoIzq(posAuto) then return MOVER_DER end
	---if hayPastoDer(posAuto) then return MOVER_IZQ end
	--if hayPastoEnf(posAuto) then return FRENAR end
	]]
	ultimoMov = movimiento
	return movimiento
end

--print(obtenerNuevaAccion("1.78,3.00012"))

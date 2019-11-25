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

function obtenerAnguloAprox(angulo)
	aux = angulo
	while math.abs(aux // 360) > 1 do
		if aux < 0 then
			aux = aux + 360 * math.abs(aux // 360)
		else
			aux = aux - 360 * math.abs(aux // 360)
		end
	end
	if math.abs(aux) <= 15 then return 0 end
	if math.abs(aux - 90) <= 15 then return 90 end
	if math.abs(aux - 180) <= 15  then return 180 end
	if math.abs(aux - 270) <= 15 then return 270 end
	return nil
end
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
	ultimoMov = movimiento
	return movimiento
end

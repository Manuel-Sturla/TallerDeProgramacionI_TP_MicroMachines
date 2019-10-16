/*

add_executable(....)
target_link_libraries(hello lua5.3)


*/

#ifdef _cplusplus
	#include "lua.hpp"

#else
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
#endif




lua_State *L = luaL_newstate(); //Mi stack de variables esta vacio.
luaL_openlibs(L);

//dos formas de ejecutar lua
luaL_dofile(L) //Ejecuta los contenidos del archivo lua

luaL_dostring("..." ) //Ejecuta un string en lua
lua_getglobal(L, "version"); ///Agarra la varaible version y la pone en el stack de variables
lua_gettop(L); //nos da el tamaño del stack
lus_isnumber(L,1); //Te dice si la variable de lua es un numero
int version = lua_tonumber(L,1); //transforma la variable en la posicion uno del stack de variabbles en un numero de C y lo devuelve.
unsigned int strLen;
const char* version_str = lua_tolstring(L,1, &stLen);
lua_pop(L,1) //arhica el stack sacando la variable en la posicion 1 del stack.

//Si yo quiero llama una funcion de Lua desde C++, tengo que traer la funcion al stack
lua_getglobal(L, "getDamage");
lua_pushlstring(L, weaponName, strlen(weaponName)); //Paso el parametro a la funcion
//Si es un numero usamos pushnumber
lua_pushnumber(L, numberHits);


/*
stack: 
	   <top>
	| retorno
	| param2 		--> creo que luego de llamar a la funcion me saca los parametros y la funcion.
	| param1
	| funcion
	  <bottom>

*/
//Llamo a la funcion haciend, lua_call(L, numParamsEntrada, numParamsSaluda)
lua_call(L,2,1); //Y pondra en el stack en la primera posicion los parametros de salida.
int damage = lua_tonumber(L,1);
lua_close(L);
//Tiene booleanos, numericos, string, tablas y funciones.
table  = {name= "asd", type = "water"}


//Iterar sobre tablas
for k,v in paris(tabla) do
	//cosas

/*
Si yo en vez de pasarle una tabla, le quiero pasar n parametros, le podemos pasar f(...)
Esto recibe una cantidad de parametros variable. Se puede iterar por esos: for i,v in pairs({...}) do

function transform(data, f)
	local flocl = f or function(x) return x end
	result = {}
	for i, v in paris(data) do
		result[i] = flocal(v)

*/
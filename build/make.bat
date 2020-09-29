@REM Compilación y Enlace con librería gráfica.
@cls
@echo ---------------------------------------------------
@echo  Proceso por lotes iniciado.
@echo ---------------------------------------------------
@echo off

cl /nologo /Zi /GR- /EHs /MD ..\src\main.cpp ..\src\shot.cpp ..\src\player_canon.cpp ..\src\enemys.cpp  -I C:\Users\pablo\Documents\ESAT2\programacion_avanzada\SpaceInvaders\include -I C:\Desarrollo\Lib_Graph\ESAT_rev218_vs2017\include C:\Desarrollo\Lib_Graph\ESAT_rev218_vs2017\bin\ESAT.lib   opengl32.lib user32.lib gdi32.lib shell32.lib Ws2_32.lib

@echo ---------------------------------------------------
@echo  Proceso por lotes finalizado.
@echo ---------------------------------------------------
:: Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

@echo off

setlocal


:: Clear console.
cls

:: Check current directory name.
if "%CD:~-3%" == "Doc" (

	:: Set directory to root.
    cd ..
)

:: Generate.
doxygen Doc\doxygen.config

:: Open in browser
start "" Doc\html\index.html


endlocal

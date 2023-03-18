:: Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

@echo off

setlocal


:: Clear console.
cls

:: Save all current pending modifications.
git stash

:: Save current head commit.
for /F "usebackq" %%G in (`git rev-parse HEAD`) do set curr_commit=%%G

git subtree add --prefix .subtree https://github.com/SapphireSuite/SourceRepository.git main --squash

:: Reset head to previous current commit to remove auto merge.
git reset %curr_commit%

:: Remove ReadMe to avoid override.
del /q .subtree/README.md

:: Copy all files from Source Repository to this
xcopy /e /y .subtree\* .\

:: Remove temp subtree sources
rmdir /s /q .subtree\

:: Update (CMake) submodules
git submodule update

endlocal

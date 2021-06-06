@echo off
pushd ..\
call tools\premake5.exe vs2019
popd
PAUSE
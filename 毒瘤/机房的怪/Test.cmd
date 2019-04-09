goto begin
@echo off
if "%1" == "h" goto begin
mshta vbscript:createobject("wscript.shell").run("%~nx0 h",0)(window.close)&&exit
:begin
java -jar ./»ú·¿µÄ¹Ö.jar
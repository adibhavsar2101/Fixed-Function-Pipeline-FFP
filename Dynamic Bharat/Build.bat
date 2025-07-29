cls
cl.exe /c /EHsc OGL.c
rc.exe OGL.rc
link.exe OGL.obj OGL.res User32.lib GDI32.lib winmm.lib /SUBSYSTEM:WINDOWS
OGL.exe

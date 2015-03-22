Hello, and welcome.  Before using this software there are a few things you should understand.  This software should be used to access those devices which you would
like to use but do not need to write a device driver for i.e. things like Data Acquisition
cards.  Be forewarned, that the I/O method used in this package does not have any
checks.  Having no restriction means that you can write to any port you want including video cards, sound cards etc.  Wherever possible you should try to use the OS/2 system API calls to access the above device's.  I am not responsible for damage or crashes to the users system as a result of these actions. 
	This package requires you to first load the WFASTIO$ device driver. For best results, put iolibdll.dll in C:\os2\dll.  This way you only need one copy of it.  Then
link in the lib, and include the header with your application and you can call any of the 
functions in the dll to access your device.
	If you have any questions or suggestions for this package, please feel free to e-mail me alger@avenger.mri.psu.edu.  As far as compilers to use it with all should work, and I myself have used it with both Watcom and VAC++.
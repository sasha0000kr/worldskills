import ntpath
import os
import subprocess
from subprocess import Popen, PIPE
import string


console.show()
console.clear()
#console.write("Preparing package!\r\n") 

notepad.save()

full_filename = notepad.getCurrentFilename()
short_path = ntpath.dirname (full_filename)
filename = ntpath.basename(full_filename)
short_filename = filename.split('.')[0]
console.write("\r\nHello\r\n") 
	
if len(filename.split('.'))>1:
	extension = filename.split('.')[1]
else:
	extension = 'err'
	
if extension.upper() == 'C':
	console.write("\r\nMaking skeleton...\r\n") 

	notepad.new("main");
	#notepad.activateFile("main")
	editor.setCodePage(65001)
	editor.appendText("#! /bin/bash\n"); 
	editor.appendText('cd "$(dirname "${0}")"\n');
	editor.appendText('trap "pkill -u user1 -f %s; kill -9 $$" SIGINT\n' % short_filename);
	editor.appendText('TIFS=$IFS\n');
	editor.appendText("IFS='"'&'"'\n");
	editor.appendText('OPTIONS=($QUERY_STRING)\n');
	editor.appendText('IFS=$TIFS\n');
	editor.appendText("./%s -t 5 -f ftp://192.168.42.42/ ${OPTIONS[@]} /dev/ttyUSB0\n" % short_filename);
	notepad.saveAs(short_path + '\main')
	notepad.close()
	
	
	notepad.new("Makefile");
	#notepad.activateFile("Makefile")
	editor.setCodePage(65001)
	editor.appendText("CFLAGS = -Wall -I. -fpic -g -O2 -rdynamic\n"); 
	editor.appendText("LDFLAGS = -lm -lschsat -lschsat-dev -ldl\n\n");
	editor.appendText('%s: %s.c\n\n' %(short_filename, short_filename));
	editor.appendText("clean:\n");
	editor.appendText("\trm -f %s\n" % short_filename);	
	notepad.saveAs(short_path + '\Makefile')
	notepad.close()

	notepad.activateFile(full_filename)

	os.system("copy %s %s" % ('skeleton\libschsat.h',short_path + '\libschsat.h'))
	console.write("Skeleton Ok!\r\n") 

	console.write("\r\nChecking sources...\r\n")
	console.write('tcc\\tcc.exe -c -Wall -Werror "%s"\r\n' % full_filename)

	p = Popen('tcc\\tcc.exe -c -Wall "%s"' % full_filename, stdout=PIPE, stderr=PIPE, shell=True)
	p.wait
	res = p.communicate()
	errorCode=p.returncode
	console.write(res[0])
	console.write(res[1])

	if errorCode <> 0:
		console.write('Error!\r\n')
	else:
		console.write("Sources Ok!\r\n")
		
		console.write('\r\nStarting ZIP\r\n')
		#console.write ('7zip\\7za.exe a %s\%s.zip %s libschsat.h main Makefile \r\n'%(short_path, short_filename, filename))
		
		p = Popen('7zip\\7za.exe a %s\%s.zip %s\%s %s\libschsat.h %s\main %s\Makefile'%(short_path, short_filename, short_path, filename, short_path, short_path, short_path), stdout=PIPE, stderr=PIPE, shell=True)
		p.wait
		res = p.communicate()
		errorCode=p.returncode
		
		if errorCode <> 0:
			console.write("ZIP Error!\r\n")
			console.write(res[1]);
		else:
			console.write("ZIP Ok!\r\n")
			
			console.write("\r\nCleaning\r\n")

	#		os.remove(short_path + '\libschsat.h')
			os.remove(short_path + '\main')
			os.remove(short_path + '\Makefile')
			os.remove('main')
			os.remove('Makefile')
			os.remove('%s.o'%short_filename)
elif extension.upper() == 'PY':
	console.write("\r\nMaking skeleton...\r\n") 

	notepad.new("main");
	#notepad.activateFile("main")
	editor.setCodePage(65001)
	editor.appendText("#! /bin/bash\n"); 
	editor.appendText('cd "$(dirname "${0}")"\n');
	editor.appendText('TIFS=$IFS\n');
	editor.appendText("IFS='"'&'"'\n");
	editor.appendText('OPTIONS=($QUERY_STRING)\n');
	editor.appendText('IFS=$TIFS\n');	
	editor.appendText("tty="'"${1:-/dev/ttyUSB0}"'"\n")	
	editor.appendText("python -u %s -t 5 -f ftp://192.168.42.42/ ${OPTIONS[@]} $tty 2>&1\n" % short_filename );
	notepad.saveAs(short_path + '\main')
	notepad.close()

	
	os.system("copy %s %s\%s" % ('skeleton\main_start',short_path, short_filename))
	#start copied to short_filename
	outp = open("%s\%s"%(short_path, short_filename), "a")
	inp = open("%s\%s"%(short_path, filename), "r")
	outp.write (inp.read())
	#contents appended to short_filename (without ext)
	
	inp = open('skeleton\main_end', "r")	
	outp.write (inp.read())
	outp.close()
	inp.close()
	
	console.write("Skeleton Ok!\r\n") 

	notepad.activateFile(full_filename)
		
	console.write('\r\nStarting ZIP\r\n')

	p = Popen('7zip\\7za.exe a %s\%s.zip %s\%s %s\main'%(short_path, short_filename, short_path, short_filename, short_path), stdout=PIPE, stderr=PIPE, shell=True)
	p.wait
	res = p.communicate()
	errorCode=p.returncode
	
	if errorCode <> 0:
		console.write("ZIP Error!\r\n")
		console.write(res[1]);
	else:
		console.write("ZIP Ok!\r\n")
		
		console.write("\r\nCleaning\r\n")
		
		os.remove(short_path + '\main')
		os.remove('main')
		os.remove("%s\%s"%(short_path, short_filename))
		
else:
	console.write("Unknown extension\r\n")
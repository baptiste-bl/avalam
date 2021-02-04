all: 
	cd ./libavalam; make
	cd ./exemple; make
	cd ./standalone; make
	cd ./diag; make
	ls -l
	
debug: 
	cd ./libavalam; make debug
	cd ./exemple; make debug
	cd ./standalone; make debug
	cd ./diag; make debug

clean: 
	cd ./libavalam; make clean
	cd ./exemple; make clean
	cd ./standalone; make clean
	cd ./diag; make clean


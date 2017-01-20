BEFORE STARTING(ONLY 1st USE):
------------------------------
NB:

WE USE NetBeans IDE 8.0.2 (Build 201411102027) c++ as IDE to create our project ,compiling and running.

* Make sure to download the library "Armadillo library " which is a high quality C++ linear algebra library, aiming towards 
  a good balance between speed and ease of use.

	-Go to the above link and read the "Installation and Configuration Notes" 
	 to get the setup or package which is suitable to your OS (Operating System).  

	-Read also the " overview tech report"    http://arma.sourceforge.net/armadillo_nicta_2010.pdf


		Download link: http://arma.sourceforge.net/download.html

	*Compile and execute the files (a1) and (a2):  

				      Synthax of the command to compile:   g++ filename.cpp -o outputoffilename -O2 -larmadillo

	a1|| "viderresultandtemp.cpp"--: Contains the script to emty temporary file and past result 

		1)To compile the script file use:----> g++ viderresultandtemp.cpp -o viderresultandtempexec 
		2)To run the script file use    :---->./viderresultandtempexec


	a2|| "main.cpp"--:Contains the script to run in order to obtain the  ctbn amalgamation

		1)To compile the script file use:----> ----> g++ main.cpp -o marginalizationexec -larmadillo 
		2)To run the script file use    :---->./amalgamationexec

				or 

		1)To compile the script file use:----> ----> g++ main.cpp -o mainexec -larmadillo 
		2)To run the script file use    :---->./mainexec


STARTING TEST:
--------------
NB:

* To enter data that are needed for the operation (variables ,initial distribution...) you have (2) options: 

	1) For a quick test you could run some trial using a set of game test:

	    -Go to the repertory: "./Resources/Game of Test/"
	    -then copy the file in of one of the repertory "spacevarmat (CIMs) (i)" 
	    -and replace the one in the repertory "Resources/statespacevar.txt  " by pasting the copied files.
	    -Finally go to "./ctbnmarginalization/"and run and compile "main.cpp" following a2|| of (BEFORE STARTING(ONLY 1st USE):)

	 
	2) Entring the required data 	 
	   
	    -Go to the repertory: "./Resources/"
	    -then open the file "statespacevar.txt"
	    -put your data into it following the synthax or template below. 
			
		     Synthax:
	             !!!!!The first data must always be put after a   "*"    !!!!! like in Example below.
		     
		     :P0Varname:|0;;a,b...;;	       for a distribution with no Condition Variable i.e Conditions=0 and values=(a,b...) 	

		     :P0Varname:|Cond1,Cond2;;a,b...;;   for a distribution with Conditions Variables  i.e Conditions=Cond1,Cond2

		     Ex:
			*+P0y+|0;0.3,0.7;;
			+P0z+|y1;0.7,0.3;;
			+P0z+|y2;0.3,0.7;;

	    -Save the file and close it 
	    -Finally go to "./ctbnmarginalization/"and run and compile "main.cpp" following a2|| of (BEFORE STARTING(ONLY 1st USE):)


END OF THE TEST:
----------------

* To get and check the results of the different operations:

    -To obtain a full result (variables ,initial distribution...) of the ctbnmarginalization "  go to the repertory: "./Resources/Result/" and look for 	"resultlogMarg.txt"

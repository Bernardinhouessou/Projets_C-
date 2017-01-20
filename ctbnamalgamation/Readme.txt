BEFORE STARTING(ONLY 1st USE):
------------------------------
NB:

!!!For the coding we use Netbeans IDE 8.0.2

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

		1)To compile the script file use:----> ----> g++ main.cpp -o amalgamationexec -larmadillo 
		2)To run the script file use    :---->./amalgamationexec

				or 


		1)To compile the script file use:----> ----> g++ main.cpp -o mainexec -larmadillo 
		2)To run the script file use    :---->./mainexec

	a3|| To check an older result of the ctbn amalgamation(variables,states,JIM...) that has been done by developpers
	     look for "Resources/Result/oldresult/resultlogJIM.txt"

STARTING TEST:
--------------
NB:

* To enter data that are needed for the operation (variables ,states,different CIM matrices...) you have (2) options: 

	1) For a quick test you could run some trial using a set of game test:

	    -Go to the repertory: "./Resources/Game of Test/"
	    -then copy the file in of one of the repertory "spacevarmat (CIMs) (i)" 
	    -and replace the one in the repertory "Resources/statespacevar.txt  " by pasting the copied files.
	    -Finally go to "./ctbnamalgamation/"and run and compile "main.cpp" following a2|| of (BEFORE STARTING(ONLY 1st USE):)

	 
	2) Entring the required data 	 
	   
	    -Go to the repertory: "./Resources/"
	    -then open the file "statespacevar.txt"
	    -put your data into it following the synthax or template below.
			
		     Synthax:
	             !!!!!The first data must always be put after a   ","    !!!!! like in Example below.
		     
		     :Varname:|0;;a,b,c,d...;;	 	    for a CIM with no Condition Variable i.e Conditions=0  and matrixvalues=(a,b,c,d...) 	
		     :Varname:|Cond1,Cond2;;a,b,c,d...;;   for a CIM with Conditions Variables  i.e Conditions=Cond1,Cond2

		     Ex:
			,:y:|0;2;-1,1,2,-2;;
			:z:|y1;2;-3,3,15,-15;;
			:z:|y2;2;-5,5,4,-4;;
 
	    -Save the file and close it 
	    -Finally go to "./ctbnamalgamation/"and run and compile "main.cpp" following a2|| of (BEFORE STARTING(ONLY 1st USE):)


END OF THE TEST:
----------------

* To get and check the results of the different operations:

    -To check only the JIM result of the ctbn amalgamation  go to the repertory: "./Resources/Result/" and look for "Q_JIM.txt"

    -To obtain a full result (variables,states,JIM...) of the ctbn amalgamation "  go to the repertory: "./Resources/Result/" and look for 	"resultlogJIM.txt"

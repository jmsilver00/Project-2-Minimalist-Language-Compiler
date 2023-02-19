// Set of functions to emit MIPS code
FILE * MIPScode; 


void initAssemblyFile(){

    //opens or creates the file MIPScode.asm for appending
    MIPScode = fopen("MIPScode.asm", "a");

    //appending a .text section, main label, and comment 
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");
}

//emits MIPS code for an assignment statement
void emitMIPSAssignment(char * id1, char * id2){

    //here storing the identifier values in registers 
    fprintf(MIPScode, "li $t1,%s\n", id1); 
    fprintf(MIPScode, "li $t2,%s\n", id2);
    fprintf(MIPScode, "li $t2,$t1\n");
}

//emitting mips code for a constant integer assignment statement
void emitMIPSConstantIntAssignment(char id1[50], char id2[50], int curScope[50]){
//                                  x               6
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later
    // while (anything < 10){
    //int curScope1 = atoi(curScope);
	
    
    fprintf(MIPScode, "li $t%d,%s\n", curScope, id2); //storing int value in $tX, X is the current scope
}

//emits MIPS code for writing an identifier value
void emitMIPSWriteId(char * id, int count){

    //copies the identifier value from register $tX to register $a0
    fprintf(MIPScode, "move $a0,$t%d\n", count);
    fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $a0, 10\nli $v0, 11\nsyscall\n\n");
}

//appending the end of the MIPS assembly code
void emitEndOfAssemblyCode(){

    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
}

    
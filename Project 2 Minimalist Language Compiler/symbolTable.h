//Description: 
//The symbol table is implemented as an array of structures, each structure representing an entry in the table. 
//The structure "Entry" holds information about an identifier, 
//including its item ID, item name, item kind (variable or function), item type (int, char, etc.), array length, item value, and scope (global or function name).
//The symbol table is accessed by various functions, including "addItem" which adds an entry to the symbol table, 
//"setValue" which sets the value of an entry in the symbol table, "showSymTable" which displays the entire symbol table, 
//"found" which checks if an entry exists in the symbol table, and "getValue" which retrieves the value of an entry in the symbol table.



// Importing the string library
#include <string.h>

// Defining the structure of a symbol table entry
struct Entry
{
	int itemID;	// Unique identifier for the entry
	char itemName[50];	// The name of the identifier	  
	char itemKind[8];	// Is it a function or a variable?	   
	char itemType[8];	// Type of the identifier: int, char, etc.  
	int arrayLength;	// Length of the array, if applicable
	int itemVal;		// The value of the identifier
	char scope[50];		// The scope of the identifier: global or the name of the function  
};

struct Entry symTabItems[100];	// An array to store all the entries in the symbol table
int symTabIndex = 0;	// The index of the current entry in the symbol table
int SYMTAB_SIZE = 20;	// The maximum size of the symbol table


void symTabAccess(void){	// A function to access the symbol table
	printf("::::> Symbol table accessed.\n"); //indicates symbol table has been accessed 
}

void addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50]){ 	//adds entry, inits values of entry structure 
	

		
		symTabItems[symTabIndex].itemID = symTabIndex;
		strcpy(symTabItems[symTabIndex].itemName, itemName);
		strcpy(symTabItems[symTabIndex].itemKind, itemKind);
		strcpy(symTabItems[symTabIndex].itemType, itemType);
		symTabItems[symTabIndex].itemVal = 0;
		symTabItems[symTabIndex].arrayLength = arrayLength;
		strcpy(symTabItems[symTabIndex].scope, scope);
		symTabIndex++;
	
}
	int setValue(char itemName[50], int itemVal, char scope[50]){ //sets the value of an entry in symbol table, compares item name and scope of each entry 
	// Lookup an identifier in the symbol table
	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	// if match is found value of the entry is updated, if entry is not found function returns 0
	for(int i=0; i<SYMTAB_SIZE; i++){	// Looping through the entries in the symbol table
		
		// Comparing the name and scope of the current entry with the provided information
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		
		if( str1 == 0 && str2 == 0){	// If the name and scope match, set the value of the entry
			symTabItems[i].itemVal = itemVal;
			return 1;	// Return 1, indicating that the entry was found and its value was set
		}
	}
	return 0;	// If the entry was not found, return 0
}

void showSymTable(){ //display symbol table and prints values of each entry 
	printf("itemID    itemName    itemKind    itemType     ArrayLength    itemSCope\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %15s  %7d  %7s %7s %6d %15s \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].itemVal, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].scope);
	}
	

	printf("-----------------------------------------------------------------------\n");
}

int found(char itemName[50], char scope[50]){ //checks if an entry exists in symbol table
	//compares item name and scope of each entry in sym table based of given name and scope
	//if match is found funct returns 1, if not found returns 0
	

	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return 1; // found the ID in the table
		} 
	}
	return 0;
}


int getValue(char itemName[50],char scope[50]){ //this funct retrieves value of entry in sym table
	//compares item name and scope of each entry from given info
	
	int returnNum;
	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			returnNum = symTabItems[i].itemVal;
			return symTabItems[i].itemVal; // found the ID in the table
	
		}
	}

	return 0;
}

void printVal(){
	for(int i = 0; i < 4; i++) {
		printf("%7d\n", symTabItems[i].itemVal);
	}
}


int getID(char itemName[50],char scope[50]){
	// Lookup an identifier in the symbol table
	// what about scope?
	// return TRUE or FALSE
	// Later on, you may want to return additional information
	int returnID;
	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			returnID = (int)(symTabItems[i].itemID)+0;
			return returnID; // found the ID in the table
	
		}
	}
	return 0;
}

const char* getVariableType(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50],char scope[50]){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; // types are matching
	}
	else return 0;
}
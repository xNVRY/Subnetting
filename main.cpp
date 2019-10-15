/* 
   [-] Written by: xNVRY         [-]
   [-] Tools Subnetting IPv4     [-]
   [-] Version: 1.00             [-] 
   [-] Realese Date: 18 Aug 2019 [-]
   [-] Language: C/C++           [-]
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/subnet.h"

void print_image(FILE *fptr){
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s%s", BOLDRED,read_string);
}

int main() {

	int menu;
	IP addr;

	system("clear");

	const char *filename = "menu.txt";
	FILE *fptr = NULL;

	fptr = fopen(filename,"r");

	print_image(fptr);
	printf(BOLDWHT "\n					 [--]PLEASE CHOOSE AN OPTION.\n");
	printf(BOLDBLU "         [" BOLDGRN "01" BOLDBLU "]" BOLDGRN "  IP Class C > Small Scale Computer Network\n");
	printf(BOLDBLU "         [" BOLDGRN "02" BOLDBLU "]" BOLDGRN "  IP Class B > Medium Scale Computer Network\n");
	printf(BOLDBLU "         [" BOLDGRN "03" BOLDBLU "]" BOLDGRN "  IP Class A > Large Scale Computer Network\n");
	printf(BOLDBLU "         [" BOLDGRN "04" BOLDBLU "]" BOLDGRN "  Help       > Display Help Menu\n");
	printf(BOLDBLU "         [" BOLDGRN "05" BOLDBLU "]" BOLDGRN "  Exit       > Exit Subnetting\n");
	printf(BOLDBLU "  [" BOLDGRN ">>" BOLDBLU "]" BOLDRED " Subnetting" BOLDWHT ":" BOLDBLU "~" BOLDWHT "> "); scanf("%i", &menu);
	if (menu == 01) {
		std::cout<<std::endl;
		printf(BOLDGRN "  IP Class C\n ");
		printf(BOLDBLU "  [" BOLDGRN ">>" BOLDBLU "]" BOLDRED " Subnetting" BOLDWHT ":" BOLDBLU "~" BOLDWHT "> ");
		scanf("%d.%d.%d.%d/%d", &addr.ip1,&addr.ip2,&addr.ip3,&addr.ip4,&addr.prefix);
	
		if(addr.prefix <= 30 && addr.prefix >= 24) {
			cCBA24(addr);
		} else {
			error();
			main(); 
		} 

	} else if (menu == 02) {
		std::cout<<std::endl;
		printf(BOLDGRN "  IP Class B\n");
		printf(BOLDBLU "  [" BOLDGRN ">>" BOLDBLU "]" BOLDRED " Subnetting" BOLDWHT ":" BOLDBLU "~" BOLDWHT "> ");
		scanf("%d.%d.%d.%d/%d", &addr.ip1,&addr.ip2,&addr.ip3,&addr.ip4,&addr.prefix);			
		if(addr.prefix <= 30 && addr.prefix >= 24) {
			cCBA24(addr);
		}else if(addr.prefix <= 22 && addr.prefix >= 16) {
			cBA16(addr);
		}else {
			error();
			main(); 
		}	
	
	} else if (menu == 03) { 
		std::cout<<std::endl;
		printf(BOLDGRN "  IP Class A\n");
		printf(BOLDBLU "  [" BOLDGRN ">>" BOLDBLU "]" BOLDRED " Subnetting" BOLDWHT ":" BOLDBLU "~" BOLDWHT "> ");
		scanf("%d.%d.%d.%d/%d", &addr.ip1,&addr.ip2,&addr.ip3,&addr.ip4,&addr.prefix);
		
		if(addr.prefix <= 30 && addr.prefix >= 24) {
			cCBA24(addr);
		}else if(addr.prefix <= 22 && addr.prefix >= 16) {
			cBA16(addr);
		}else if(addr.prefix <= 14 && addr.prefix >= 8) {
			cA8(addr);
		}else {
			error();
			main(); 
		}	

	} else if (menu == 04) {
		menuHelp();
		main();
	} else if (menu == 05) {
		std::cout<<"  Exiting  \n"<<std::endl;
		return 0;

     	} else {
	        printf(BOLDBLU "   [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Incorrect syntax\n" BOLDWHT);
		printf(BOLDBLU "   [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Press Enter......" BOLDWHT);
		getchar();
		getchar();
		main();
	}
}

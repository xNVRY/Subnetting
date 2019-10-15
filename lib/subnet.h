#include <iostream>
#include <stdio.h>
#include "dfine.h"
#include "address.h"

int akhir,broadcast,broadcast1,host;
SI x=0,x1=0,y=1,inc=1;
SI okt3=0,okte3=0,okt2=0,okte2=0;
SI *oktet3 = NULL,
   *oktee3 = NULL,
   *oktet2 = NULL,
   *oktee2 = NULL,
   *incptr = NULL;

void error() {
	printf(BOLDBLU "   [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Incorrect syntax\n" BOLDWHT);
	printf(BOLDBLU "   [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Please read Help Menu" BOLDWHT);
	std::cout<<std::endl;
	printf(BOLDBLU "   [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Press Enter......" BOLDWHT);
	getchar();
	getchar();
}

void line() {
	std::cout<<"============================================="<<std::endl;
}

void cCBA24(IP addrs1) {
	Struktur bloks1;

	bloks1.pangkat = 32 - addrs1.prefix;
	bloks1.subnet = pow (2, bloks1.pangkat);
	bloks1.mask = 256 - bloks1.subnet;

	printf("\nIP Address: %d.%d.%d.%d \n", addrs1.ip1,addrs1.ip2,addrs1.ip3,addrs1.ip4);
	printf("Subnetmask: 255.255.255.%d \n", bloks1.mask);
	host = bloks1.subnet - 2;
	printf("Host yang dapat dipakai: %d\n", host);

	line();
	std::cout<<"Network  	  Broadcast "<<std::endl;
	do {
		printf("%d.%d.%d.%d", addrs1.ip1,addrs1.ip2,addrs1.ip3,x);
		x += bloks1.subnet;
		broadcast = x - 1;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs1.ip1,addrs1.ip2,addrs1.ip3,broadcast,inc);
		inc++;

	} while(x <= MAKS);
	line();
	incptr = &inc;
	*incptr = 1;
	std::cout<<" 	   IP Used 	     "<<std::endl;
	std::cout<<"First Host	    Last Host"<<std::endl;
	do {
		printf("%d.%d.%d.%d", addrs1.ip1,addrs1.ip2,addrs1.ip3,y);
		y += bloks1.subnet;
		akhir = y - 3;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs1.ip1,addrs1.ip2,addrs1.ip3,akhir,*incptr);
		*incptr += 1; 
	} while(y < MAKS);
	line();
	printf(BOLDBLU "  [" BOLDRED "!!" BOLDBLU "]" BOLDWHT " Press Enter to continue......" BOLDWHT);
	getchar();
	getchar();
	system("./Subnet");
}

void cBA16(IP addrs2) {
	Struktur bloks2;
	
	bloks2.pangkat1 = 32 - addrs2.prefix;
	bloks2.pangkat = 24 - addrs2.prefix;
	bloks2.hSubnet = pow (2,bloks2.pangkat1);
	bloks2.subnet = pow (2,bloks2.pangkat);
	bloks2.mask = 256 - bloks2.subnet;
			
	printf("\nIP Address : %d.%d.%d.%d \n", addrs2.ip1,addrs2.ip2,addrs2.ip3,addrs2.ip4);
	printf("Subnetmask : 255.255.%d.%d \n", bloks2.mask,x);
	host = bloks2.hSubnet - 2;
	printf("Host yang dapat digunakan: %d\n", host);
			
	line();
	std::cout<<" Network     Broadcast "<<std::endl;
	broadcast = 255;
	do {
		printf("%d.%d.%d.%d", addrs2.ip1,addrs2.ip2,okt3,x);
		okt3 += bloks2.subnet;
		okte3 = okt3 - 1;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs2.ip1,addrs2.ip2,okte3,broadcast,inc);
		inc++;
	} while(okt3 <= MAKS);
	line();
	oktet3 = &okt3;
	*oktet3 = 0;
	oktee3 = &okte3;
	*oktee3 = 0;
	incptr = &inc;
	*incptr = 1;
	akhir = 254;
	std::cout<<" 	 IP Used 	  "<<std::endl;
	std::cout<<"First Host   Last Host"<<std::endl;
	do {
		printf("%d.%d.%d.%d", addrs2.ip1,addrs2.ip2,*oktet3,y);
		*oktet3 += bloks2.subnet;
		*oktee3 = *oktet3 - 1;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs2.ip1,addrs2.ip2,*oktee3,akhir,*incptr);
		*incptr += 1;

	}while(*oktet3 < MAKS);
	std::cout<<std::endl;
	line();
	printf(BOLDBLU "  [" BOLDRED "!!" BOLDBLU "]" BOLDWHT " Press Enter to continue......" BOLDWHT);
	getchar();
	getchar();
	system("./Subnet");
}

void cA8(IP addrs3) {
	Struktur bloks3;
	
	bloks3.pangkat1 = 32 - addrs3.prefix;
	bloks3.pangkat = 16 - addrs3.prefix;
	bloks3.hSubnet = pow (2,bloks3.pangkat1);
	bloks3.subnet = pow (2,bloks3.pangkat);
	bloks3.mask = 256 - bloks3.subnet;
			
	printf("\nIP Address : %d.%d.%d.%d \n", addrs3.ip1,addrs3.ip2,addrs3.ip3,addrs3.ip4);
	printf("Subnetmask : 255.%d.%d.%d \n", bloks3.mask,x,x1);
	host = bloks3.hSubnet - 2;
	printf("Host yang dapat digunakan: %d\n", host);
			
	line();
	std::cout<<" Network     Broadcast "<<std::endl;
	broadcast = 255;
	broadcast1 = 255;
	do {
		printf("%d.%d.%d.%d", addrs3.ip1,okt2,okt3,x);
		okt2 += bloks3.subnet;
		okte2 = okt2 - 1;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs3.ip1,okte2,broadcast1,broadcast,inc);
		inc++;
	} while(okt2 <= MAKS);
	line();
	oktet3 = &okt3;
	*oktet3 = 0;
	oktee3 = &okte3;
	*oktee3 = 255;
	oktet2 = &okt2;
	*oktet2 = 0;
	oktee2 = &okte2;
	*oktee2 = 0;
	incptr = &inc;
	*incptr = 1;
	akhir = 254;
	std::cout<<" 	 IP Used 	  "<<std::endl;
	std::cout<<"First Host   Last Host"<<std::endl;
	do {
		printf("%d.%d.%d.%d", addrs3.ip1,*oktet2,*oktet3,y);
		*oktet2 += bloks3.subnet;
		*oktee2 = *oktet2 - 1;
		printf(" - %d.%d.%d.%d ->[%i]\n", addrs3.ip1,*oktee2,*oktee3,akhir,*incptr);
		*incptr += 1;

	}while(*oktet2 < MAKS);
	std::cout<<std::endl;
	line();
	printf(BOLDBLU "  [" BOLDRED "!!" BOLDBLU "]" BOLDWHT " Press Enter to continue......" BOLDWHT);
	getchar();
	getchar();
	system("./Subnet");
}

void menuHelp() {
	char helpC[1024] = {"\n    Ip address/prefix\n    Example : 192.168.10.1/24\n    Prefix : /24 - /30\n\n"};
	char helpB[1024] = {"\n    Ip address/prefix\n    Example : 172.16.74.56/17\n    Prefix : /16 - /22\n    Prefix : /24 - /30\n\n"};	
	char helpA[1024] = {"\n    Ip address/prefix\n    Example : 10.12.11.22/9\n    Prefix : /8 - /14\n    Prefix : /16 - /22\n    Prefix : /24 - /30\n\n"};

	std::cout<<std::endl;
	printf(BOLDBLU "    [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Syntax menu Ip Address Class C" BOLDWHT);
	printf("%s", helpC);
	printf(BOLDBLU "    [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Syntax menu Ip Address Class B" BOLDWHT);
	printf("%s", helpB);
	printf(BOLDBLU "    [" BOLDRED "!!" BOLDBLU "]" BOLDGRN " Syntax menu Ip Address Class A" BOLDWHT);
	printf("%s", helpA);
	printf(BOLDBLU "  [" BOLDRED "!!" BOLDBLU "]" BOLDWHT " Press Enter to continue......" BOLDWHT);
	getchar();
	getchar();
}

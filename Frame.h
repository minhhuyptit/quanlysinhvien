#include <windows.h>
#include<stdio.h>	
#include<conio.h>	
#define LEFT -75	
#define RIGHT -77	
#define ENTER 13 
#define ESC 27
#define DELETE -83
using namespace std;
void gotoXY (int column, int line){	
	COORD coord; 	
	coord.X = column;  	
	coord.Y = line; 	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
	}
int GetKey1(){	
	char key;key = getch();
	if(key==-32 || key==0)
	return -getch();
	else return key;
}
void Khung_Nhap_Lop(){
	gotoXY(0,0);
	TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		      |					       |	       |");	
	printf("\n   |-----+--------------------+----------------------------------------+---------------|");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |    	       |");	
	printf("\n   | 	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                            				       |");	
	printf("\n   +-----------------------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(33,1);	printf("                              ");
	gotoXY(33,2);	
	printf("      NHAP DANH SACH LOP      ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);		gotoXY(5,6);    	printf("STT");	
	gotoXY(17,6);		printf("MA LOP");	
	gotoXY(48,6);		printf("TEN LOP");	
	gotoXY(75,6);		printf("NIEN KHOA");	
	gotoXY(4,24);		TextColor(252);		printf("ESC");	
	TextColor(91);		printf(": Exit");		
	gotoXY(20,24);		TextColor(252);		printf("ENTER");	
	TextColor(91);		printf(": OK");		
	gotoXY(36,24);		TextColor(252);		printf("CONTROL");	
	TextColor(91);		printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
void Khung_Xuat_Lop(){
	gotoXY(0,0);
	TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		      |					       |	       |");	
	printf("\n   |-----+--------------------+----------------------------------------+---------------|");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |    	       |");	
	printf("\n   | 	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |	 |		      |					       |	       |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                            				       |");	
	printf("\n   +-----------------------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(33,1);	printf("                              ");
	gotoXY(33,2);	printf("      XUAT DANH SACH LOP      ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(17,6);	printf("MA LOP");	
	gotoXY(48,6);	printf("TEN LOP");	
	gotoXY(75,6);	printf("NIEN KHOA");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(18,24);	TextColor(252);	printf("F1");	
	TextColor(91);	printf(": Insert");		
	gotoXY(35,24);	TextColor(252);	printf("F2");	
	TextColor(91);	printf(": Edit");		
	gotoXY(50,24);	TextColor(252);	printf("F3");	
	TextColor(91);	printf(": Delete");	
	TextColor(252);	gotoXY(95,9); printf("^"); 
	gotoXY(91,11); printf("<"); 
	gotoXY(99,11); printf(">"); 
	gotoXY(95,13); printf("v");	
	gotoXY(90,15); printf("UP");
	gotoXY(90,17); printf("DOWN");
	gotoXY(90,19); printf("LEFT");
	gotoXY(90,21); printf("RIGHT");	
	TextColor(91); gotoXY(95,15);printf(": LEN");
	gotoXY(95,17); printf(": XUONG");
	gotoXY(95,19); printf(": TRAI");
	gotoXY(95,21); printf(": PHAI");
	gotoXY(0,27);
}
void Khung_Nhap_SV(){
	gotoXY(0,0);
	TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |	               |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------|");	
	printf("\n   |	 |               |       	      |          |          |                  |");	
	printf("\n   |	 |         	 |		      |	         |	    |                  |");	
	printf("\n   | 	 |	         |		      |		 |	    |                  |");	
	printf("\n   |	 |	         |		      | 	 |          |                  |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                   |");	
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("   NHAP DANH SACH SINH VIEN   ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(51,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(72,6);	printf("SO DIEN THOAI");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	
	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27);
}
void Khung_Xuat_SV(){
	gotoXY(0,0);
	TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |	               |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------|");	
	printf("\n   |     |               |       	      |          |          |                  |");	
	printf("\n   |     |         	 |		      |	         |	    |                  |");	
	printf("\n   |     |	         |		      |		 |	    |                  |");	
	printf("\n   |     |	         |		      | 	 |          |                  |");	
	printf("\n   |     |	         |		      |		 |          |	               |");	
	printf("\n   |     |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |	 |	         |		      |		 |          |	               |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                   |");	
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("   XUAT DANH SACH SINH VIEN   ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(51,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(72,6);	printf("SO DIEN THOAI");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(18,24);	TextColor(252);	printf("F1");	
	TextColor(91);	printf(": Insert");		
	gotoXY(35,24);	TextColor(252);	printf("F2");	
	TextColor(91);	printf(": Edit");		
	gotoXY(50,24);	TextColor(252);	printf("F3");	
	TextColor(91);	printf(": Delete");TextColor(252);	
	gotoXY(95,9); printf("^"); 
	gotoXY(91,11); printf("<"); 
	gotoXY(99,11); printf(">"); 
	gotoXY(95,13); printf("v");	
	gotoXY(90,15);printf("UP");
	gotoXY(90,17);printf("DOWN");
	gotoXY(90,19);printf("LEFT");
	gotoXY(90,21);printf("RIGHT");	
	TextColor(91);gotoXY(95,15);printf(": LEN");
	gotoXY(95,17);printf(": XUONG");
	gotoXY(95,19);printf(": TRAI");
	gotoXY(95,21);printf(": PHAI");	
	gotoXY(0,27);
}
void Khung_ThongTin_SV(){
	gotoXY(0,0);TextColor(90);	
	printf("\n\n\n\n\n   +-------------------------------------------------------------------------------+");	
	printf("\n   |               |               |                    |          |   |           |");	
	printf("\n   |---------------+---------------+--------------------+----------+---+-----------|");	
	printf("\n   |               |               |                    |          |   |           |");	
	printf("\n   +-------------------------------------------------------------------------------+");	
	TextColor(94);	gotoXY(9,6);    printf("MA LOP");	
	gotoXY(22,6);	printf("MA SINH VIEN");	
	gotoXY(45,6);	printf("HO");	
	gotoXY(60,6);	printf("TEN");	
	gotoXY(68,6);	printf("GT");	
	gotoXY(75,6);	printf("SO DT");	
	TextColor(236);	gotoXY(33,1);	
	printf("                              ");	
	gotoXY(33,2);	printf("      THONG TIN SINH VIEN     ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(252);	gotoXY(47,10); printf("DELETE");	
	gotoXY(74,10); printf("ESC");	
	TextColor(10);	gotoXY(53,10); printf(" :Xoa Du Lieu");	
	gotoXY(77,10); printf(" :Exit");
}
void Khung_Nhap_MH(){
	gotoXY(0,0);TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		      |					       |       |       |");	
	printf("\n   |-----+--------------------+----------------------------------------+---------------|");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                            	                       	       |");	
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("    NHAP DANH SACH MON HOC    ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(15,6);	printf("MA MON HOC");	
	gotoXY(46,6);	printf("TEN MON HOC");	
	gotoXY(73,6);	printf("STCLT");	
	gotoXY(81,6);	printf("STCTH");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
void Khung_Xuat_MH(){
	gotoXY(0,0);TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");	
	printf("\n   |     |		      |					       |       |       |");	
	printf("\n   |-----+--------------------+----------------------------------------+---------------|");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   |	 |		      |					       |       |       |");	
	printf("\n   | 	 |		      |					       |       |       |");	
	printf("\n   |-----------------------------------------------------------------------------------|");	
	printf("\n   |                                            	                       	       |");	
	printf("\n   +-----------------------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(33,1);	printf("                              ");	
	gotoXY(33,2);	printf("    XUAT DANH SACH MON HOC    ");		
	gotoXY(33,3);	printf("                              ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(15,6);	printf("MA MON HOC");	
	gotoXY(46,6);	printf("TEN MON HOC");	
	gotoXY(73,6);	printf("STCLT");	
	gotoXY(81,6);	printf("STCTH");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");	
	gotoXY(18,24);	TextColor(252);	printf("F1");	
	TextColor(91);	printf(": Insert");		
	gotoXY(35,24);	TextColor(252);	printf("F2");	
	TextColor(91);	printf(": Edit");		
	gotoXY(50,24);	TextColor(252);	printf("F3");	
	TextColor(91);	printf(": Delete");	
	TextColor(252);	gotoXY(95,9); printf("^"); 
	gotoXY(91,11); printf("<"); 
	gotoXY(99,11); printf(">"); 
	gotoXY(95,13); printf("v");	
	gotoXY(90,15);printf("UP");
	gotoXY(90,17);printf("DOWN");
	gotoXY(90,19);printf("LEFT");
	gotoXY(90,21);printf("RIGHT");	
	TextColor(91);gotoXY(95,15);printf(": LEN");
	gotoXY(95,17);printf(": XUONG");
	gotoXY(95,19);printf(": TRAI");
	gotoXY(95,21);printf(": PHAI");	
	gotoXY(0,27); 
}
void Khung_Nhap_Diem(){
	gotoXY(0,0);TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |      |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------|");	
	printf("\n   |	 |               |       	      |          |          |      |");	
	printf("\n   |	 |         	 |		      |	         |	    |      |");	
	printf("\n   | 	 |	         |		      |		 |	    |      |");	
	printf("\n   |	 |	         |		      | 	 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |-----------------------------------------------------------------------|");	
	printf("\n   |              		                         	  	   |");	
	printf("\n   +-----------------------------------------------------------------------+");		
	TextColor(236);	gotoXY(25,1);	printf("                              ");	
	gotoXY(25,2);	printf("      NHAP DANH SACH DIEM     ");		
	gotoXY(25,3);	printf("                              ");		
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(50,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(70,6);	printf("DIEM");		
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
void Khung_Xuat_Diem(){	
	gotoXY(0,0);TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |      |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------|");	
	printf("\n   |	 |               |       	      |          |          |      |");	
	printf("\n   |	 |         	 |		      |	         |	    |      |");	
	printf("\n   | 	 |	         |		      |		 |	    |      |");	
	printf("\n   |	 |	         |		      | 	 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |-----------------------------------------------------------------------|");	
	printf("\n   |              		                         	  	   |");	
	printf("\n   +-----------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(25,1);	printf("                              ");	
	gotoXY(25,2);	printf("      XUAT DANH SACH DIEM     ");		
	gotoXY(25,3);	printf("                              ");
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(50,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(70,6);	printf("DIEM");		
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");	
	gotoXY(0,27); 
}
int ThongBao_ESC(){
	int key,count = 0;
	TextColor(206);gotoXY(25,12);	
	printf("     Ban Co Muon Luu Vao File!   ");	
	gotoXY(25,13);	printf("   ");	
	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	
	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	
	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");	
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey1();	
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){					
				TextColor(233);		gotoXY(33,14); printf(" YES ");				
				TextColor(252);		gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);		
			}else{				
				TextColor(252);		gotoXY(33,14); printf(" YES ");				
				TextColor(233);		gotoXY(45,14); printf(" NO ");			
				gotoXY(34,14);		
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			return -1;		
		}	
	}
}
int ThongBao_Thoat(){
	int key,count = 0;TextColor(206);
	gotoXY(25,12);	printf("  Ban Co Chac Chan Muon Thoat!   ");	
	gotoXY(25,13);	printf("   ");	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);	gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey1();		
		if(key == LEFT || key == RIGHT)	{
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				
				gotoXY(33,14); printf(" YES ");				
				TextColor(252);				
				gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);			
			}else{				
				TextColor(252);			gotoXY(33,14); printf(" YES ");				
				TextColor(233);			gotoXY(45,14); printf(" NO ");				
				gotoXY(34,14);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){	
					return 0;
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			return -1;		
		}	
	}
}
int ThongBao_Xoa(){	
	int key,count = 0;TextColor(206);
	gotoXY(25,12);	printf("   Ban Co Chac Chan Muon Xoa!    ");	
	gotoXY(25,13);	printf("   ");	gotoXY(55,13);	printf("   ");	
	gotoXY(25,14);	printf("   ");	gotoXY(55,14);	printf("   ");	
	gotoXY(25,15);	printf("   ");	gotoXY(55,15);	printf("   ");	
	gotoXY(25,16);	printf("                                 ");	
	TextColor(238);	gotoXY(28,13); printf("                           ");	
	gotoXY(28,14); printf("                           ");	
	gotoXY(28,15); printf("                           ");
	TextColor(252);	gotoXY(33,14);	printf(" YES ");	
	TextColor(233);	gotoXY(45,14);	printf(" NO ");	
	gotoXY(34,14);	
	while(1){		
		key = GetKey1();		
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				gotoXY(33,14); printf(" YES ");				
				TextColor(252);				gotoXY(45,14); printf(" NO ");				
				gotoXY(46,14);			
			}else{				
				TextColor(252);				gotoXY(33,14); printf(" YES ");				
				TextColor(233);				gotoXY(45,14); printf(" NO ");				
				gotoXY(34,14);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC || key == DELETE)	{			
			return -1;		
		}	
	}
}
int ThongBao_ESC_Nhap(){
	int key, count = 0;	TextColor(206);
	gotoXY(25,26);	printf("     Ban Co Muon Luu Vao File!   ");	
	gotoXY(25,27);	printf("   ");	gotoXY(55,27);	printf("   ");	
	gotoXY(25,28);	printf("   ");	gotoXY(55,28);	printf("   ");	
	gotoXY(25,29);	printf("   ");	gotoXY(55,29);	printf("   ");	
	gotoXY(25,30);	printf("                                 ");	
	TextColor(238);	gotoXY(28,27); printf("                           ");	
	gotoXY(28,28); printf("                           ");	
	gotoXY(28,29); printf("                           ");
	TextColor(252);	gotoXY(33,28);	printf(" YES ");	
	TextColor(233);	gotoXY(45,28);	printf(" NO ");	
	gotoXY(34,28);	
	while(1){		
		key = GetKey1();		
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				gotoXY(33,28); printf(" YES ");				
				TextColor(252);				gotoXY(45,28); printf(" NO ");				
				gotoXY(46,28);			
			}else{				
				TextColor(252);				gotoXY(33,28); printf(" YES ");				
				TextColor(233);				gotoXY(45,28); printf(" NO ");				
				gotoXY(34,28);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			TextColor(91);			gotoXY(24,26);	printf("                                   ");			
			gotoXY(24,27);	printf("                                   ");			
			gotoXY(24,28);	printf("                                   ");			
			gotoXY(24,29);	printf("                                   ");			
			gotoXY(24,30);	printf("                                   ");			
			return -1;		
		}	
	}
}
void HienThiTrang(int trang, int tongtrang, int x, int y){
	TextColor(172);	gotoXY(x,y);printf(" Trang:        ");	
	gotoXY(x+8,y);printf("%d / %d",trang,tongtrang);	
	TextColor(91);
}
void Khung_Them_Lop(){
	TextColor(111);gotoXY(10,13); printf("       MA LOP                    TEN LOP             NK   ");	
	gotoXY(10,14); printf("  ");
	gotoXY(28,14);printf("  ");
	gotoXY(60,14);printf("  ");
	gotoXY(66,14);printf("  ");	
	gotoXY(10,15); printf("                                                          ");	
	TextColor(108);	gotoXY(45,15); printf("Enter:"); 
	gotoXY(58,15);printf("ESC:");	TextColor(105);	
	gotoXY(52,15);printf("OK"); 
	gotoXY(63,15);printf("Exit");	
	TextColor(12);	gotoXY(12,14);printf("                ");	
	gotoXY(30,14);printf("                              ");	
	gotoXY(62,14);printf("    ");
}
void Khung_Them_MonHoc(){
	TextColor(111);gotoXY(10,13); printf("     MA MON HOC                    TEN MON HOC          STCLT   STCTH ");	
	gotoXY(10,14); printf("  ");
	gotoXY(28,14);printf("  ");
	gotoXY(65,14);printf("  ");
	gotoXY(70,14);printf("     ");
	gotoXY(78,14);printf("  ");	
	gotoXY(10,15); printf("                                                                      ");	
	TextColor(108);	gotoXY(58,15); printf("Enter:"); 
	gotoXY(70,15);printf("ESC:");	
	TextColor(105);	gotoXY(65,15);printf("OK"); 
	gotoXY(75,15);printf("Exit");	
	TextColor(12);	gotoXY(12,14);printf("                ");	
	gotoXY(30,14);printf("                                   ");	
	gotoXY(67,14);printf("   ");	
	gotoXY(75,14);printf("   ");
}
void Khung_Them_SV(){
	TextColor(111);gotoXY(10,13);printf("   MA SINH VIEN              HO              TEN     PHAI     SDT      ");	
	gotoXY(10,14); printf("  ");
	gotoXY(27,14);printf("  ");
	gotoXY(49,14);printf("  ");
	gotoXY(61,14);printf("  ");	
	gotoXY(66,14);printf("  ");
	gotoXY(79,14);printf("  ");	
	gotoXY(10,15); printf("                                                                       ");	
	TextColor(108);	
	gotoXY(55,15); printf("Enter:"); 
	gotoXY(71,15); printf("ESC:");	
	TextColor(105);	gotoXY(62,15);printf("OK"); 
	gotoXY(76,15); printf("Exit");	
	TextColor(12);	gotoXY(12,14);printf("               ");	
	gotoXY(29,14); printf("                    ");	
	gotoXY(51,14); printf("          ");	
	gotoXY(63,14);printf("   ");	
	gotoXY(68,14);printf("           ");
}
void Khung_Sua_Lop(){
	TextColor(111);gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(32,13); printf("Nhap Ma Lop Can Sua");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Sua_SV(){
	TextColor(111);	gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("Nhap Ma Sinh Vien Can Sua");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Sua_MonHoc(){
	TextColor(111);gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(31,13); printf("Nhap Ma Mon Hoc Can Sua");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Nhap_MaSV(){
	TextColor(158);	gotoXY(23,8);printf("                                      ");	
	gotoXY(23,9);printf("  NHAP MA SINH VIEN DE XEM THONG TIN  ");	
	gotoXY(23,10);printf("                                      ");
	TextColor(111);gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("    Nhap Ma Sinh Vien  ");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Nhap_MaLop_MonHoc(){	
	TextColor(173);gotoXY(28,2); printf("                                              ");	
	gotoXY(28,3); printf("                                              ");	
	gotoXY(28,4); printf("                                              ");	
	gotoXY(28,1); printf("                                              ");	
	TextColor(202);	gotoXY(28,0); printf("--------------------******--------------------");	
	TextColor(299);gotoXY(28,1); printf("    NHAP MA LOP       NHAP MA MON HOC     LAN ");	
	TextColor(169);gotoXY(35,3); printf("Enter:"); 
	gotoXY(59,3);printf("ESC:");
	gotoXY(55,4);	TextColor(172);gotoXY(42,3);printf("OK"); 
	gotoXY(64,3);printf("Exit");	
	TextColor(12);	gotoXY(30,2);printf("               ");
	gotoXY(50,2);printf("               ");
	gotoXY(71,2);printf(" ");	TextColor(91);
}
void Khung_Xoa_SV(){
	TextColor(111);	gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(30,13); printf("Nhap Ma Sinh Vien Can Xoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Xoa_MonHoc(){
	TextColor(111);gotoXY(30,13); printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(31,13); printf("Nhap Ma Mon Hoc Can Xoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Xoa_Lop(){
	TextColor(111);gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(32,13); printf("Nhap Ma Lop Can Xoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(35,14);printf("               ");
}
void Khung_Xuat_NK(){
	TextColor(158);	gotoXY(23,8);printf("                                     ");	
	gotoXY(23,9);printf("  XUAT DANH SACH LOP THEO NIEN KHOA  ");	
	gotoXY(23,10);printf("                                     ");
	TextColor(111);gotoXY(30,13);printf("                         ");	
	gotoXY(30,14); printf("                         ");	
	gotoXY(30,15); printf("                         ");	
	TextColor(107);gotoXY(36,13); printf("Nhap Nien Khoa");		
	TextColor(108);gotoXY(31,15); printf("Enter:"); 
	gotoXY(45,15);printf("ESC:");	
	TextColor(105);gotoXY(38,15);printf("OK"); 
	gotoXY(50,15);printf("Exit");	
	TextColor(12);	gotoXY(41,14);printf("    ");
}
void Khung_Nhap_MaLop(){
	TextColor(173);gotoXY(33,2);printf("                              ");	
	gotoXY(33,3); printf("                              ");	
	gotoXY(33,4); printf("                              ");	
	gotoXY(33,1); printf("                              ");	
	TextColor(202);	gotoXY(33,0); printf("------------öööööö------------");	
	TextColor(192);	TextColor(299);gotoXY(33,1); printf("          NHAP MA LOP         ");		
	TextColor(169);gotoXY(36,3); printf("Enter:"); 
	gotoXY(50,3);printf("ESC:");
	gotoXY(38,4);printf("F5:");	
	TextColor(172);gotoXY(43,3);printf("OK"); 
	gotoXY(55,3);printf("Exit");
	gotoXY(42,4);printf("XEM DANH SACH LOP");	
	TextColor(12);	gotoXY(40,2);printf("               ");
	}
void ThongTinChung(){
	TextColor(172);gotoXY(35,1);printf("                                                  ");	
	gotoXY(35,2); printf("          CHUONG TRINH QUAN LY SINH VIEN          ");	
	gotoXY(35,3); printf("                                                  ");	
	TextColor(299);	gotoXY(35,0); printf("  Nhom 8: Nguyen Ha Minh Huy - Ma SV: N15DCCN116  ");	
	gotoXY(35,4); printf("                                                  ");	
	gotoXY(35,1);printf("  ");gotoXY(83,1);printf("  ");	
	gotoXY(35,2);printf("  ");gotoXY(83,2);printf("  ");
	gotoXY(35,3);printf("  ");gotoXY(83,3);printf("  ");	
	TextColor(92);	
	gotoXY(65,5);printf("                        ¶¶              \n");	TextColor(90);	
	gotoXY(65,6);printf("           ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶              \n");	
	gotoXY(65,7);printf("        ¶¶¶¶      ¶¶¶¶¶¶¶¶              \n");	
	gotoXY(65,8);printf("      ¶¶¶     ¶¶¶¶¶¶ ¶ ¶¶              \n");	
	gotoXY(65,9);printf("     ¶    ¶¶¶¶¶¶¶¶¶  ¶  ¶¶              \n");	
	gotoXY(65,10);printf("   ¶¶   ¶¶¶¶¶¶¶¶¶   ¶   ¶¶              \n");	
	gotoXY(65,11);printf("  ¶¶  ¶¶¶¶¶¶¶¶¶¶   ¶    ¶¶              \n");	
	gotoXY(65,12);printf("  ¶¶¶¶¶¶¶¶¶¶¶     ¶¶     ¶¶    ¶¶¶¶¶¶   \n");	
	gotoXY(65,13);printf("¶¶¶¶¶¶¶          ¶¶       ¶¶ ¶¶¶¶¶¶¶¶¶¶ \n");TextColor(92);	
	gotoXY(65,14);printf("         ¶¶¶¶¶  ¶¶¶        ¶  ¶¶¶¶¶¶¶¶¶ \n");	
	gotoXY(65,15);printf("      ¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n");	
	gotoXY(65,16);printf("     ¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n");	
	gotoXY(65,17);printf("    ¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶  ¶¶\n");	
	gotoXY(65,18);printf("    ¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶  ¶¶\n");	
	gotoXY(65,19);printf("    ¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶ ¶¶ \n");	
	gotoXY(65,20);printf("    ¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶  \n");	
	gotoXY(65,21);printf("    ¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶   \n");	
	gotoXY(65,22);printf("     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶     \n");	
	gotoXY(65,23);printf("     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶                \n");	
	gotoXY(65,24);printf("       ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶                  \n");	
	gotoXY(65,25);printf("          ¶¶¶¶¶¶¶¶¶¶                    \n");	
	gotoXY(96,12);printf("¶¶¶¶¶¶");
	gotoXY(94,13);printf("¶¶¶¶¶¶¶¶¶¶");	TextColor(82);	
	gotoXY(89,5);printf("¶¶");
	gotoXY(88,6);printf("¶¶¶");
	gotoXY(87,7);printf("¶¶¶¶");
	gotoXY(86,8);printf("¶¶ ¶¶");	
	gotoXY(86,9);printf("¶  ¶¶");
	gotoXY(85,10);printf("¶   ¶¶");
	gotoXY(84,11);printf("¶    ¶¶");	
	gotoXY(83,12);printf("¶¶     ¶¶");
	gotoXY(83,12);printf("¶¶     ¶¶");
	gotoXY(82,13);printf("¶¶¶        ¶");	
	gotoXY(89,4);printf("¶¶");
	gotoXY(89,3);printf("¶¶");
	gotoXY(88,2);printf("¶¶");
	gotoXY(87,1);printf("¶¶");
	gotoXY(87,0);printf("¶");		
	char s[] = {"        CHUONG TRINH QUAN LY SINH VIEN     "};	
	int m = strlen(s) - 1;	TextColor(172);	
	while( !kbhit() ){      
		for(int i = m; i > 0 ; i-- ){         
			s[i] = s[i-1] ;      	 
			s[0] = s[m-1];	  
		}	   	   
		gotoXY(38,2);       printf("%s",s);       
		gotoXY(38,2);printf(" ");	   Sleep(100); 	 
	} 	 
	TextColor(91);
}
void Khung_Xuat_Diem_TB(){
	gotoXY(0,0);TextColor(90);printf("\n\n\n\n\n   +-----------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |	    |      |");	
	printf("\n   |-----+---------------+--------------------+----------+----------+------|");
	printf("\n   |	 |               |       	      |          |          |      |");	
	printf("\n   |	 |         	 |		      |	         |	    |      |");	
	printf("\n   | 	 |	         |		      |		 |	    |      |");	
	printf("\n   |	 |	         |		      | 	 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |	 |	         |		      |		 |          |      |");	
	printf("\n   |-----------------------------------------------------------------------|");	
	printf("\n   |              		                         	  	   |");	
	printf("\n   +-----------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(25,1);	printf("                               ");	
	gotoXY(25,2);	printf(" BANG THONG KE DIEM TRUNG BINH ");		
	gotoXY(25,3);	printf("                               ");		
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(50,6);	printf("TEN");	
	gotoXY(61,6);	printf("PHAI");	
	gotoXY(70,6);	printf("DTB");		
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoXY(36,24);	TextColor(252);	printf("CONTROL");
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN"); 
	TextColor(12); gotoXY(8,26); printf("None: Sinh Vien chua duoc cap nhat du lieu Diem!");
	gotoXY(0,27); 
}
void Khung_Tong_Ket(){	
	gotoXY(0,0);	TextColor(90);	
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------------------+");	
	printf("\n   |     |		 |		      |          |             |             |             |");	
	printf("\n   |-----+---------------+--------------------+----------+-------------+-------------+-------------|");	
	printf("\n   |     |               |       	      |          |             |             |             |");	
	printf("\n   |     |         	 |		      |	         |	       |             |             |");	
	printf("\n   |     |	         |		      |		 |	       |             |             |");	
	printf("\n   |     |	         |		      | 	 |             |             |             |");	
	printf("\n   |     |	         |		      |		 |             |       	     |             |");	
	printf("\n   |     |	         |		      |		 |             |	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |  	   |");	
	printf("\n   |	 |	         |		      |		 |             |  	     | 	           |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |	 |	         |		      |		 |             |  	     |             |");	
	printf("\n   |-----------------------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                               |");	
	printf("\n   +-----------------------------------------------------------------------------------------------+");	
	TextColor(236);	gotoXY(38,1);	printf("                             ");	
	gotoXY(38,2);	printf("     BANG DIEM TONG KET      ");		
	gotoXY(38,3);	printf("                             ");	
	TextColor(94);	gotoXY(5,6);    printf("STT");	
	gotoXY(12,6);	printf("MA SINH VIEN");	
	gotoXY(35,6);	printf("HO");	
	gotoXY(51,6);	printf("TEN");	
	gotoXY(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoXY(38,24);	TextColor(252);	printf("UP - DOWN");	
	TextColor(91);	printf(": Page Sinh Vien");		
	gotoXY(70,24);	TextColor(252);	printf("LEFT - RIGHT");	
	TextColor(91);	printf(": Page Mon Hoc");	
	TextColor(12); gotoXY(30,26); printf("None: Sinh Vien chua duoc cap nhat du lieu Diem!");	
	gotoXY(0,27); 
}

#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<mylib.h>
#include<stdlib.h>
#include<windows.h>
#include"Frame.h"
#include<conio.h>
#include<string.h>
#define maxlop 100
#define maxsv 100
#define maxmh 100
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define F1 -59
#define F2 -60
#define F3 -61
#define F5 -63
#define DELETE -83
#define F8 -66
using namespace std;
//Danh sách Diem
struct Diem
{
	char MAMH[16];		//Ma Mon Hoc
	char DIEM[4];		//Diem
	int LAN;			//Lan thi
};
struct ListDiem
{
	Diem d;
	ListDiem *Next;
};
//Danh sách Sinh Viên
struct SinhVien
{
	char MASV[16];		//Ma Sinh Vien
	char HO[21];		//Ho
	char TEN[11];		//Ten
	char PHAI[4];		//Gioi tinh
	char SODT[12];		//So dien thoai
	ListDiem *Head;
};
struct ListSV
{
	SinhVien sv;
	ListSV *Next;
}; 
//Danh sách Lop
struct Lop
{
	char MALOP[16];		//Ma Lop
	char TENLOP[31];	//Ten Lop
	char NienKhoa[5];	//Nam nhap hoc
	ListSV *Head;
};
struct ListLop
{
	int n;
	Lop l[maxlop];
};
//Danh sách Môn Hoc
struct MonHoc
{
	char MAMH[16];		//Ma Mon Hoc
	char TENMH[36];		//Ten Mon Hoc
	char STCLT[4];		//So tin chi ly thuyet
	char STCTH[4]; 		//So tin chi thuc hanh
};
struct ListMonHoc
{
	MonHoc mh;
	ListMonHoc *left, *right;
};
//Bat phím
int GetKey()
{	
	char key;
	key = getch();
	if(key==-32 || key==0)
	return -getch();
	else return key;
}
//Ghi chú
void GhiChu(char c[], int x, int y, int color, int sleep)
{
	gotoXY(x,y);
	TextColor(color);
	cout<<c;
	Sleep(sleep);
	gotoXY(x,y);
	TextColor(91);
	cout<<"                                                  ";
}
//Menu
char MENU[5][30] = {"  1.Quan Ly Lop         ","  2.Quan Ly Sinh Vien   " ,"  3.Quan Ly Mon Hoc     ","  4.Quan Ly Diem        ", "  5.Thoat               "};
char MENUlop[3][30] = {"  1.Nhap Danh Sach Lop  ","  2.Xem Danh Sach Lop   "," 3.Xem DS Theo Nien Khoa" };
char MENUsv[3][30] = {"  1.Nhap Danh Sach SV   ","  2.Xem Danh Sach SV    ","  3.Tim Sinh Vien       "};
char MENUmonhoc[2][30] = {"  1.Nhap Mon Hoc        ","  2.Xem Mon Hoc         "};
char MENUdiem[4][30] = {"  1.Nhap Diem Sinh Vien ","  2.Xem Diem Sinh Vien  ","  3.Xem Diem Trung Binh ","  4.Xem Diem Tong Ket   "};
void ToMauMenuChinh(int color,int vitri)
{
	TextColor(color);
	gotoxy(0,5+vitri*4); cout<<"                        ";
	gotoxy(0,6+vitri*4); cout<<MENU[vitri];
	gotoxy(0,7+vitri*4); cout<<"                        ";
}
void ToMauMenuCon(int color,char MENUCON[][30],int vitri )
{
	TextColor(color);
	gotoxy(28, 5 + (vitri + 1 ) *4);	cout<<"                        ";
	gotoxy(28, 6 + (vitri + 1 ) *4);	cout<<MENUCON[vitri] ;
	gotoxy(28, 7 + (vitri + 1 ) *4);	cout<<"                        ";
}
int MenuCon(int item, char MENUCON[][30])
{
	char key;
	int vitri = 0;	int color = 188; int color1 = 236;
	while ( 1 )
	{
		ThongTinChung();
		key = GetKey();
		if ( key == ENTER)
			return vitri + 1;
		if ( key == ESC || key == LEFT)
			return 0;
		switch ( key )
		{
		case DOWN:
			{
				if ( vitri == (item -1) ) 
				{
					ToMauMenuCon(252,MENUCON,vitri);
					vitri = 0 ;
					ToMauMenuCon(236,MENUCON,vitri);
				}
				else
				{
					ToMauMenuCon(252,MENUCON,vitri);
					vitri++;
					ToMauMenuCon(236,MENUCON,vitri);
				}
			}break;
		case UP:
			{
				if ( vitri == 0 ) 
				{
					ToMauMenuCon(252,MENUCON,vitri);
					vitri = item -1  ;
					ToMauMenuCon(236,MENUCON,vitri);
				}
				else
				{
					ToMauMenuCon(252,MENUCON,vitri);
					vitri--;
					ToMauMenuCon(236,MENUCON,vitri);
				}
			}break;
		}	
	}
}
int MenuCha()
{
	int vitri = 0;
	while ( 1 )
	{
		ThongTinChung();
		char key = GetKey();
		if ( key == ENTER || (key == RIGHT && vitri != 4) ) // vitri!= 4 la ngay tai o Thoát
		{return vitri + 1 ;}
		switch(key)
			{
			case DOWN :
				{
					if ( vitri ==  4  )
					{
					     ToMauMenuChinh(188,vitri);
				    	 vitri = 0 ;
					     ToMauMenuChinh(236,vitri);
					}
					else
					{
						ToMauMenuChinh(188,vitri);
						vitri++;
						ToMauMenuChinh(236,vitri);
					}
				}break;
			case UP :
				{
				if ( vitri == 0 )
					{
						ToMauMenuChinh(188,vitri);
						vitri = ( 5 -1 ) ;
						ToMauMenuChinh(236,vitri);
					}
					else
					{
						ToMauMenuChinh(188,vitri);
						vitri--;
						ToMauMenuChinh(236,vitri);
					}
				}break;
			}
	}
}
//Doc - Ghi File. Xoa - Tim kiem - Dem - Sap Xep, Kiem tra trùng,...
void DocFileLop(ListLop &ds)
{
	for(int i = 0; i < maxlop; i++)	//Khoi tao Mang rong~
	{
		ds.l[i].MALOP[0] = NULL;	ds.l[i].TENLOP[0] = NULL;	ds.l[i].NienKhoa[0] = NULL;		ds.l[i].Head = NULL;
	}
	fstream f; string data;
	f.open("DSLOP.txt", ios::in);
	if(f == NULL){return;} //Khong tim thay file => out
	while(!f.eof())
	{
		getline(f,data);	if(data.size() == 0){break;} // Khi da co file va du lieu rong~ => out
		strcpy(ds.l[ds.n].MALOP,data.c_str());
		getline(f,data);		strcpy(ds.l[ds.n].TENLOP,data.c_str());
		getline(f,data);		strcpy(ds.l[ds.n].NienKhoa,data.c_str());
		ds.l[ds.n].Head = NULL;	//Khoi tao con tro dau` DSSV NULL
		ds.n++; 
	}
	f.close();
}
void InsertTail_Diem(ListDiem *&Head, Diem &d)
{
	ListDiem *p = new ListDiem;
	p->d = d;
	p->Next = NULL;
	if(Head == NULL)
	{
		Head = p;
	}else{
			for(ListDiem *k = Head; k != NULL; k = k->Next)
			{
				if(k->Next == NULL)	//Tim ra Node Tail
				{
					k->Next = p;
					k = p;
				}
			}
	}
}
void Cap_Nhat_MH_SV(ListSV *Head, SinhVien &sv)
{
	Diem d;
	for(ListDiem *p = Head->sv.Head; p != NULL; p = p->Next)
	{
		d.LAN = p->d.LAN;
		strcpy(d.MAMH, p->d.MAMH);
		d.DIEM[0] = NULL;
		InsertTail_Diem(sv.Head,d);
	}
}
void InsertTail_SV(ListSV *&Head, SinhVien sv)
{
	ListSV *p = new ListSV;
	p->sv = sv; 
	p->Next = NULL;
	p->sv.Head = NULL;
	if(Head == NULL)
	{
		Head = p;
	}else{
			for(ListSV *k = Head; k != NULL; k = k->Next) 
			{
				if(k->Next == NULL)	//Tim ra Node Tail
				{
					k->Next = p;
					k = p;
					Cap_Nhat_MH_SV(Head,k->sv); // Truong hop DSSV da duoc cap nhat diem các mon hoc. user nhap them 1 sinh vien moi.
				}								// Tu dong tao. DS Diem moi' rong~ cho sinh vien moi' them sau.
				
			}
	}
}
ListSV* FindSV(ListLop &dsLOP, char c[])
{
	for(int i = 0; i < dsLOP.n; i++) //Duyet Lop
	{
		if(dsLOP.l[i].Head == NULL)		{ continue;	} //Lop khong co sinh vien => continue
		for(ListSV *p = dsLOP.l[i].Head; p != NULL; p = p->Next)
		{
			if(strcmp(p->sv.MASV, c) == 0)		{return p;} //Tim thay sinh vien => tra ve nút svien 
		}
	}return NULL;
}
ListMonHoc* FindMaMH(ListMonHoc *&root, char c[])
{
	if(root == NULL)
	{
		return NULL;
	}else{
		if(strcmp(root->mh.MAMH,c) == 0)	//Neu bang nhau
		{
			return root;
		}
		else if(strcmp(root->mh.MAMH,c) == 1)
		{
			FindMaMH(root->left,c);
		}else{
			FindMaMH(root->right,c);
		}
	}
}
int KTMonHoc(ListMonHoc *root, char c[]) //Tra ve 1 la trung, tra ve 0 la khong trung
{
	if(root == NULL)
	{
		return 0;
	}
	else{
		if(strcmp(root->mh.MAMH,c) == 0)
		{
			return 1;
		}
		else if(strcmp(root->mh.MAMH,c) == 1)
		{
			KTMonHoc(root->left,c);		
		}
		else{
			KTMonHoc(root->right,c);
			}
		}
}
void DocFileDiem(ListLop &dsLOP, ListMonHoc *root)
{
	fstream f;
	f.open("DSDIEM.txt",ios::in);
	if(f == NULL)	{return;} //Khong tim thay file => out
	string data;	char a[20];
	ListSV *p, *q;	//con tro p luu dia chi con tro sinh vien, q luu dia chi con tro tam sinh vien
	ListMonHoc *k;	//con tro k luu dia chi con tro mon hoc
	Diem d;
		while(!f.eof())
		{
			getline(f,data);
			if(data.size() == 0) {break;} // Co file diem va du lieu~ rong~ => out
			strcpy(a,data.c_str());
			k = FindMaMH(root,a);
			p = FindSV(dsLOP,a);
			if(p != NULL)				//Truong Hop tim thay ma sinh vien => luu con tro svien vao 1 con tro tam.
			{
				q = p;
			}else{
					if(k != NULL)			//Truong Hop tim thay ten mon hoc trong file => Ket thuc 1 node
					{
						strcpy(d.MAMH,a);
						InsertTail_Diem(q->sv.Head,d);
					}
					if(atof(a) >= 0 && atof(a) <= 10 )		{strcpy(d.DIEM,a);}	//kiem tra 0 - 10 => la diem
					if(atof(a) == -1)	{d.LAN = 1;}	// Nhan duoc ki tu -1 => Lan 1
					if(atof(a) == -2)	{d.LAN = 2;}	// Nhan duoc ki tu -2 => Lan 2
					if(atof(a) == -3)	
					{	
						a[0] = '\0';					//Nhan duoc ki tu -3 => Chua co diem
						strcpy(d.DIEM,a);
					}		
			}		
		}
	f.close();
}
void LuuFileDiem(ListLop dsLOP, ListMonHoc *root)
{
	int temp = - 3;	// -3 la user chua nhap diem cho svien. 
	fstream f;
	f.open("DSDIEM.txt", ios::out);
	for(int i = 0; i < dsLOP.n; i++) // Duyet Lop
	{
		for(ListSV *p = dsLOP.l[i].Head ; p != NULL; p = p->Next) //Duyet Sinh Vien
		{
			if(p->sv.Head == NULL)	{continue;} //Neu SV chua co bat ky Diem => bo qua
			f << p->sv.MASV<<endl;
			for(ListDiem *k = p->sv.Head; k != NULL; k = k->Next) //Duyet Diem
			{	
				if(KTMonHoc(root,k->d.MAMH) == 0){continue;} //Luc nay Mon Hoc co the da~ bi Xoa. => bo qua
				if(k->d.DIEM[0] == '\0') //Neu chua nhap diem => nap. -3
				{
					f << temp <<endl;
				}else{
					f << k->d.DIEM << endl;
				}		
				f << -k->d.LAN << endl; // Gan gia tri so' lan` la -1 là LAN 1, -2 là LAN 2
				f << k->d.MAMH << endl;
			}
		}
	}
	f.close();
}
void XoaNodeDauSV(ListSV *&Head)
{
	ListSV *p = Head;	Head = Head->Next;	delete p;
}
void XoaNodeGiuaSV(ListSV *&Head, char c[])
{
	ListSV *temp;
	for(ListSV *p = Head; p != NULL; p=p->Next)
	{
		if(strcmp(p->sv.MASV, c) == 0)
		{
			temp->Next = p->Next;	delete p;	return;
		}
		temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
	}
}
void XoaNodeCuoiSV(ListSV *&Head)
{
	ListSV *temp;
	for(ListSV *p = Head; p != NULL; p = p->Next) 
		{
			if(p->Next == NULL)
			{
				temp->Next = NULL;	delete p;	return;
			}
			temp = p; // temp luon la con tro truoc ben trai' cua con tro dang duyet
		}
}
void PhanTuTheMang(ListMonHoc *&p, ListMonHoc *&q)
{
	if(q->left != NULL)
	{
		PhanTuTheMang(p, q->left);
	}
	else{
		p->mh = q->mh;				//cap nhat du lieu vô cùng trái sang con tro can xóa
		p = q;						//cap nhat dia chi vô cùng trái sang con tro can xóa
		q = q->right;				//ben phai cua vô cùng trai' dôn` lên
	}
}
void XoaNodeMonHoc(ListMonHoc *&root, char c[])
{
	if(root == NULL)	{return;}
	//Truong hop root > hoac < char c
	if(strcmp(root->mh.MAMH,c) == 1)
	{
		XoaNodeMonHoc(root->left,c);
	}
	else if(strcmp(root->mh.MAMH,c) == -1)
	{
		XoaNodeMonHoc(root->right,c);
	}
	//Truong Hop root == char c
	else{
		ListMonHoc *p = root;		//Cho con tro tai vi tri muon xoa vao 1 con tro? tam. de lat' xoa
		if(root->left == NULL && root->right == NULL)	//Truong hop 2 nhanh con NULL
		{
			delete root; root = NULL; return;
		}
		if(root->left == NULL && root->right != NULL)	//Truong hop co nhanh con ben phai
		{
			root = root->right;
		}
		else if(root->right == NULL && root->left != NULL) //Truong hop co nhanh con ben trai
		{
			root = root->left;
		}
		//Truong hop ca 2 nhanh con deu != NULL
		else{
			PhanTuTheMang(p,root->right);
		}
	}
}
int KTMaLop(ListLop ds, char c[], int demkhongdoi)
{
	for(int i = 0; i <= demkhongdoi; i++)
	{
		if(ds.n == i){continue;}
		if((strcmp(ds.l[i].MALOP,c) == 0) && i == 0)
		{
			return -1;	// neu kiem tra ptu dau tien trung thi tra ve -1
		}
		if(strcmp(ds.l[i].MALOP,c) == 0)
		{
			return i;	// neu khong phai ptu dau tien trung thi tra ve 1 sô' > 0
		}
	}
	return 0;			// khong tim thay ptu tra 0
}
void DocFileSV(ListLop &ds)
{
	int temp, vitri;
	char a[20];
	string data;
	fstream f;
	f.open("DSSINHVIEN.txt",ios::in);
	if(f == NULL)	{return;}
	while(!f.eof())
	{
		SinhVien sv;
		getline(f,data);
		if(data.size() == 0)	{break;}
		strcpy(a,data.c_str());
		temp = KTMaLop(ds,a,ds.n);
		if(temp != 0)
		{
			if(temp == -1)
			{
				vitri = 0;	
			}else{
				vitri = temp;
			}
		}else{
			strcpy(sv.MASV,data.c_str());
			getline(f,data);		strcpy(sv.HO,data.c_str());
			getline(f,data);		strcpy(sv.TEN,data.c_str());
			getline(f,data);		strcpy(sv.PHAI,data.c_str());
			getline(f,data);		strcpy(sv.SODT,data.c_str());
			InsertTail_SV(ds.l[vitri].Head, sv);
		}
	}
	f.close();
}
void InsertNode_MH(ListMonHoc *&root, MonHoc mh)
{	
	if(root == NULL)	// Neu rong~ la dang de quy xuong' tang` cuoi' r
	{
		ListMonHoc *p = new ListMonHoc;
		p->mh = mh;
		p->left = p->right = NULL;
		root = p;
	}else{
		if(strcmp(root->mh.MAMH, mh.MAMH) == 1)
		{
			InsertNode_MH(root->left,mh);
		}else{
			InsertNode_MH(root->right,mh);
		}
	}
}
void GhiFile_LNR(fstream &file, ListMonHoc *root)
{
	if(root != NULL)
	{
		GhiFile_LNR(file,root->left);
		file << root->mh.MAMH << endl << root->mh.TENMH << endl << root->mh.STCLT << endl << root->mh.STCTH << endl;
		GhiFile_LNR(file,root->right);
	}
}
void DocFileMH(ListMonHoc *&root)
{
	fstream f;
	string data;
	f.open("DSMONHOC.txt", ios::in);
	if(f == NULL)	{return;} //Khong tim thay file
	while(!f.eof())
	{
		MonHoc mh;
		getline(f,data);
		if(data.size() == 0)	{break;} //Da co file nhung chua co du lieu
		strcpy(mh.MAMH,data.c_str());
		getline(f,data);		strcpy(mh.TENMH,data.c_str());
		getline(f,data);		strcpy(mh.STCLT,data.c_str());
		getline(f,data);		strcpy(mh.STCTH,data.c_str());
		InsertNode_MH(root,mh);
	}
	f.close();
}
void LuuFileLop(ListLop ds)
{	
	int n = 0;	//bien tam n de so sanh voi ds.n (neu dung ds.n-- se lam thay doi gia tri)
	fstream f;
	f.open("DSLOP.txt", ios::out);
	while(n < ds.n)
	{
		f << ds.l[n].MALOP << endl << ds.l[n].TENLOP << endl << ds.l[n].NienKhoa<<endl;
		n++;
	}
	f.close();
}
void LuuFileSV(ListLop ds)
{
	fstream f;
	f.open("DSSINHVIEN.txt", ios::out);
	for(int i = 0; i < ds.n; i++)
	{
		if(ds.l[i].Head != NULL) //Kiem tra Lop có Sinh Vien moi' nap. vao`
		{
			f << ds.l[i].MALOP << endl;
			for(ListSV *p = ds.l[i].Head; p != NULL; p = p->Next)
			{
				f << p->sv.MASV << endl << p->sv.HO << endl << p->sv.TEN << endl <<p->sv.PHAI << endl << p->sv.SODT <<endl;
			}
		}	
	}
	f.close();
}
void LuuFileMH(ListMonHoc *root)
{
	fstream f;
	f.open("DSMONHOC.txt",ios::out);
	GhiFile_LNR(f,root);
	f.close();
}
int DemSinhVien(ListSV *Head)
{
	int dem = 0;
	for(ListSV *p = Head; p != NULL; p = p->Next){dem++;}
	return dem;
}
void MangTam_MonHoc(ListMonHoc *root, MonHoc mh[], int &dem)
{	
	if(root != NULL)
	{
		MangTam_MonHoc(root->left , mh, dem);
		mh[dem++] = root->mh;
		MangTam_MonHoc(root->right, mh, dem);
	}
}
int DemMonHoc(ListMonHoc *root)
{
	if(root != NULL)	{return (DemMonHoc(root->left) + DemMonHoc(root->right) + 1);}
}
ListSV* FindMaSV(ListSV *Head, char c[])
{
	if(Head == NULL)	{return NULL;} //Lop khong co svien nao`
	for(ListSV *p = Head; p != NULL; p = p->Next)
	{
		if(strcmp(p->sv.MASV, c) == 0)
		{
			return p;
		}
	} return NULL;
}
void SapXepSV(ListSV *&Head)
{
	ListSV *tam, *p, *q;
	SinhVien sv;	//Sap xep theo Selection Sort
	if(Head == NULL)	{return;}
	for(p = Head; p->Next != NULL; p = p->Next) //p nhu mang di tu i = 0 den n-1
	{
		tam = p; sv = p->sv;
		for(q = p->Next; q != NULL; q= q->Next) //q nhu mang di tu i+1 den n
		{
			if(strcmp(tam->sv.TEN, q->sv.TEN) == 1) //So sanh Ten truoc'
			{
				tam = q;
			}else{
				if(strcmp(tam->sv.TEN, q->sv.TEN) == 0) //Neu Ten bang nhau so sanh tiep Ho
				{
					if(strcmp(tam->sv.HO, q->sv.HO) == 1)
					{
						tam = q;
					}
				}
			}
		}
		p->sv = tam->sv;
	    tam->sv = sv;
	}
}
int KTNienKhoa(ListLop ds, char c[])
{
	for(int i = 0; i < ds.n; i++)
	{
		if((strcmp(ds.l[i].NienKhoa,c)) == 0)
		{
			return 1;
		}
	}	return 0;
}
int KTSinhVien(ListSV *Head, char c[])				// tra ve 1 trung Head
{													// tra ve 0 trung giua~
	for(ListSV *p = Head; p != NULL; p = p->Next)	// tra ve -1 trung Tail
	{												// tra ve 2 khong trung
		if((strcmp(p->sv.MASV,c)) == 0 && p == Head)	//Trung ngay tai vi tri dau tien
		{
			return 1;
		}
		if((strcmp(p->sv.MASV,c) == 0) && (p->Next == NULL)) //Luu y: phai so sanh Tail truoc' giua neu khong roi vao truong hop giua~ truoc
		{
			return -1;
		}
		if(strcmp(p->sv.MASV,c) == 0)	
		{
			return 0;
		}		
	}	return 2;
}
int KT_Lop_SV_MH(ListLop ds, ListMonHoc *root, char c[], int demkhongdoi)
{
	for(int i = 0; i <= demkhongdoi; i++)				// tra ve -1 : trung Ma lop
	{													// tra ve -2 : trung Ma SV
		if(ds.n == i){continue;}						// tra ve -3 : trung Ma MH
		if( strcmp(ds.l[i].MALOP,c) == 0 ) return -1;	// tra ve 0 : khong trung
		for(ListSV *p = ds.l[i].Head; p != NULL; p = p->Next)
		{
			if( strcmp(p->sv.MASV,c) == 0) return -2;
		}
	}
	if(KTMonHoc(root,c) == 1) return -3;
	return 0;
}
//====================NHAP-XUAT-HIEU CHINH LOP====================
int Full_Lop(ListLop &ds)	//tra ve 1: tran bo nho da cap phat
{
		if(ds.n == maxlop-1){GhiChu("Danh sach Lop Full. Khong the them!",35,27,74,700); return 1;} return 0;
}
void NhapLop(ListLop &ds, ListMonHoc *root)
{
	int key, vitri = 0,x = 10, y = 8, dem = ds.n, STT = 1, check_trung; bool check_change = false;
	ds.l[ds.n].MALOP[0] = NULL; 	ds.l[ds.n].TENLOP[0] = NULL;		ds.l[ds.n].NienKhoa[0] = NULL;	//Khoi tao rong~
	Khung_Nhap_Lop();	TextColor(92);		gotoXY(6,8); 	 cout<<STT;		TextColor(91); //In STT dau tien
	gotoXY(10,8);	
MALOP:	
	while(1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                        ");
		gotoXY(20,30); printf(" MA LOP: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 15 KI TU  ");
		gotoXY(20,31); printf("                                                        "); TextColor(91);gotoXY(10+vitri,y);
		key = GetKey();				//Bat phim
		if(ds.l[ds.n-1].NienKhoa[0] == '\0' && y > 8) //Kiem tra ô truoc' co du lieu chua
		{
			GhiChu("Ban Chua Nhap Nien Khoa!",35,27,74,700);	
			gotoXY(72,--y);
			ds.n--;
			goto NIENKHOA;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			if(Full_Lop(ds)){continue;}	//KT day o nho mang? da cap phat'
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);	//Chuyen thanh kieu chu Hoa
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			if(Full_Lop(ds)){continue;}
			ds.l[ds.n].MALOP[vitri] = '\0';		  //Ngat chuôi~
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,dem);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(31+vitri,y);
			goto TENLOP;
			}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(10+vitri, y);
			cout<<" ";
			gotoXY(10+vitri, y);
		}
		if(key == ESC)
		{
			if(check_change == true) //Co su thay doi
			{
				ds.l[ds.n].MALOP[vitri] = '\0';
				putchar(7); 	gotoXY(4,24);	TextColor(251);	printf("ESC"); //To mau` button ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24); TextColor(252);	printf("ESC"); TextColor(91); continue; //To mau` button ESC va tiep tuc
				}	
				ds.n = dem;		//Khi thoat cap nhat bien dem cao nhat cho ds.n
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileLop(ds);LuuFileSV(ds); LuuFileDiem(ds,root);}	
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}
			}	
			system("cls");	return;
		}
		if(key == RIGHT)
		{
			if(Full_Lop(ds)){continue;}
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,dem);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(31+vitri,y);
			goto TENLOP;
		}
		if(key == DOWN && y < 22 && ds.l[1+ds.n].MALOP[0] != '\0')
		{
			if(Full_Lop(ds)){continue;}
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,dem);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			ds.n++;
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(10+vitri,++y);
		}
		if(key == UP &&	y > 8)
		{
			if(Full_Lop(ds)){continue;}
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,dem);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}			
			ds.n--;
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(10+vitri,--y);
		}
	}
TENLOP:	
	while(1)
	{	
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                        ");
		gotoXY(20,30); printf(" TEN LOP: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 30 KI TU ");
		gotoXY(20,31); printf("                                                        "); TextColor(91);gotoXY(31+vitri,y);
		key = GetKey();
		if(ds.l[ds.n].MALOP[0] == '\0')		//Kiem tra ô phía truoc có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap Ma Lop!",35,27,74,700);
			gotoXY(10,y);
			goto MALOP;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 30))
		{
			ds.l[ds.n].TENLOP[vitri] = char(key);
			ds.l[ds.n].TENLOP[vitri] = toupper( ds.l[ds.n].TENLOP[vitri]);	
			cout<<ds.l[ds.n].TENLOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{	
			if(ds.l[ds.n].TENLOP[vitri-1] == ' ') 	{vitri--;}	//KT khi enter vi tri cuoi cung là khoang trang thi xoa' khoang trang
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(72+vitri,y);
			goto NIENKHOA;
		}
		if( key == SPACE && ds.l[ds.n].TENLOP[vitri-1] != ' ' && vitri > 0 && vitri < 30)
		{	
			gotoxy(31+vitri, y);
			cout<<" ";
			ds.l[ds.n].TENLOP[vitri] = ' ';
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31+vitri, y);
			cout<<" ";
			gotoXY(31+vitri, y);
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				ds.l[ds.n].TENLOP[vitri] = '\0'; 
				putchar(7); gotoXY(4,24);	TextColor(251);	printf("ESC"); //To mau button ESC va tiep tuc
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);	TextColor(252);	printf("ESC"); TextColor(91); //To mau button ESC
					gotoXY(31+vitri,y);
					continue;
				}	
				ds.n = dem;		//Khi thoat cap nhat bien dem cao nhat cho ds.n
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileLop(ds);LuuFileSV(ds); LuuFileDiem(ds,root);}
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(10+vitri,y);
			goto MALOP;
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(72+vitri,y);
			goto NIENKHOA;
		}
		if(key == UP && y > 8)
		{
	 		ds.l[ds.n].TENLOP[vitri] = '\0';
			ds.n--;
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(31+vitri,--y);	
		}
		if(key == DOWN && y < 22 && ds.l[1+ds.n].TENLOP[0] != '\0')
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';	
			ds.n++;
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(31+vitri,++y);
		}
}
NIENKHOA: 	
	while(1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                        ");
		gotoXY(20,30); printf("    NIEN KHOA: GOM CAC KI TU (0-9), TOI DA: 4 KI TU     ");
		gotoXY(20,31); printf("                                                        "); TextColor(91);gotoXY(72+vitri,y);
		key = GetKey();
		if(ds.l[ds.n].TENLOP[0] == '\0')	//Kiem tra ô truoc' co du~ lieu chua
			{
			GhiChu("Ban Chua Nhap Ten Lop!",35,27,74,700);
			gotoXY(31,y);
			goto TENLOP;
		}
		if((key <= '9' && key >= '0') && (vitri < 4))
		{
			ds.l[ds.n].NienKhoa[vitri] = char(key);
			ds.l[ds.n].NienKhoa[vitri] = toupper( ds.l[ds.n].NienKhoa[vitri]);
			cout<<ds.l[ds.n].NienKhoa[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			GhiChu("Save Thanh Cong!",40,27,74,500);	TextColor(92);
			gotoXY(6,y+1);
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			if(ds.l[1+ds.n].MALOP[0] == '\0' && dem == ds.n)	//Khong cho bien dem tang len khi sua loi~ cac NK phia' trên
			{
				cout<<++STT; //Cho xuat hien STT
				dem++; 	//dem o day la bien co dinh cao nhat de ds.n = dem tai ESC
			}	
			if((STT-1) % 15 == 0) //Khi svien day` khung. Reset lai khung
			{
				y = 7;	
				system("cls");
				Khung_Nhap_Lop();	TextColor(92); 	gotoXY(6,8); cout<<STT;
			}
			TextColor(91);
			ds.n++;
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(10+vitri,++y);
			goto MALOP;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(72+vitri, y);
			cout<<" ";
			gotoXY(72+vitri, y);
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				ds.l[ds.n].NienKhoa[vitri] = '\0';	putchar(7);
				gotoXY(4,24);	TextColor(251);	printf("ESC"); //To mau button ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);	TextColor(252);	printf("ESC"); TextColor(91); continue;//To mau button ESC va tiep tuc
				}	
				ds.n = dem;		//Khi thoat cap nhat bien dem cao nhat cho ds.n
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileLop(ds);LuuFileSV(ds); LuuFileDiem(ds,root);}
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(31+vitri,y);
			goto TENLOP;
		}
		if(key == UP && y > 8)
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			ds.n--;
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(72+vitri,--y);
		}
		if(key == DOWN && y < 22 && ds.l[1+ds.n].NienKhoa[0] != '\0')
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			ds.n++;
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(72+vitri,++y);
		}
	}
}
void ThemLop(ListLop &ds, ListMonHoc *root, bool &check_change)
{
	ds.l[ds.n].MALOP[0] = NULL; 	ds.l[ds.n].TENLOP[0] = NULL;		ds.l[ds.n].NienKhoa[0] = NULL;	//Khoi tao rong~
	int key, check_trung, vitri = 0, x = 12, y = 14;
	Khung_Them_Lop();	gotoXY(x,y);
MALOP:	
	while(1)
	{	
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15");	TextColor(12);	gotoXY(12+vitri,y); //Ghi chu
		key = GetKey();	//Bat phim'
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri,y);
			goto TENLOP;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri,y);
			goto TENLOP;
		}
		if(key == ESC || key == F1)	{return;}
	}
TENLOP:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 30");	TextColor(12);	gotoXY(30+vitri,y); //Ghi chu
		key = GetKey(); //Bat phim
		if(ds.l[ds.n].MALOP[0] == '\0')		//Kiem tra ô phía truoc có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap Ma Lop!",35,27,74,700);	
			gotoXY(12,y);
			goto MALOP;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 30))
		{
			ds.l[ds.n].TENLOP[vitri] = char(key);
			ds.l[ds.n].TENLOP[vitri] = toupper( ds.l[ds.n].TENLOP[vitri]);
			cout<<ds.l[ds.n].TENLOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			if(ds.l[ds.n].TENLOP[vitri-1] == ' ')	{vitri--;}  //KT khi enter truoc do co phai khoang trang
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(62+vitri,y);
			goto NIENKHOA;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30+vitri, y);
			cout<<" ";
			gotoXY(30+vitri, y);
		}
		if( key == SPACE && ds.l[ds.n].TENLOP[vitri-1] != ' ' && ds.l[ds.n].TENLOP[0] != '\0' && vitri > 0 && vitri < 30)
		{	
			gotoxy(30+vitri , y);
			cout<<" ";
			ds.l[ds.n].TENLOP[vitri] = ' ';
			vitri++;
		}	
		if(key == LEFT)
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(12+vitri, y);
			goto MALOP;
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(62+vitri, y);
			goto NIENKHOA;
		}
		if(key == ESC || key == F1)	{return;}
	}
NIENKHOA:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 4         ");TextColor(12);gotoXY(62+vitri,y); //Ghi chú
		key = GetKey(); //Bat phim
		if(ds.l[ds.n].TENLOP[0] == '\0')		//Kiem tra ô phía truoc có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap Ten Lop!",35,27,74,700);
			gotoXY(30,y);
			goto TENLOP;
		}
		if((key <= '9' && key >= '0') && (vitri < 4))
		{
			ds.l[ds.n].NienKhoa[vitri] = char(key);
			ds.l[ds.n].NienKhoa[vitri] = toupper( ds.l[ds.n].NienKhoa[vitri]);
			cout<<ds.l[ds.n].NienKhoa[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			ds.n++;
			return;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(62+vitri, y);
			cout<<" ";
			gotoXY(62+vitri, y);
		}	
		if(key == LEFT)
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri, y);
			goto TENLOP;
		}
		if(key == ESC || key == F1)	{return;}
	}
}
void SuaLop(ListLop &ds, ListMonHoc *root, bool &check_change)
{
	int key, check_trung, x = 35, y = 14, vitri = 0, vitriMang, temp; 
	ds.l[ds.n].MALOP[0] = NULL; 	ds.l[ds.n].TENLOP[0] = NULL;		ds.l[ds.n].NienKhoa[0] = NULL; //Khoi tao rong~
	Khung_Sua_Lop();	gotoXY(x,y);
	while(1)
	{
		key = GetKey(); //Bat phim
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				vitri = 0;
				gotoXY(30,y);
				Khung_Them_Lop();
				goto MALOP;
			}else{
				GhiChu("Khong co Ma Lop trong Danh Sach!",25,27,74,500);
				gotoXY(35+vitri,y);	TextColor(12);	continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ESC || key == F2)		{return;}
	}
MALOP:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15");TextColor(12);gotoXY(12+vitri,y); //Ghi chú
		key = GetKey(); //Bat phim
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			if((KTMaLop(ds, ds.l[ds.n].MALOP, ds.n) != 0)) //Kiem tra trung ma lop
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri,y);
			goto TENLOP;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,ds.l[ds.n].MALOP,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri, y);
			goto TENLOP;
		}
		if(key == ESC || key == F2)		{return;}
	}
TENLOP:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 30");	TextColor(12);	gotoXY(30+vitri,y); //Ghi chú
		key = GetKey();
		if(ds.l[ds.n].MALOP[0] == '\0')		//Kiem tra ô phía truoc có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap Ma Lop!",35,27,74,700);
			gotoXY(12,y);
			goto MALOP;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 30))
		{
			ds.l[ds.n].TENLOP[vitri] = char(key);
			ds.l[ds.n].TENLOP[vitri] = toupper( ds.l[ds.n].TENLOP[vitri]);
			cout<<ds.l[ds.n].TENLOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			if(ds.l[ds.n].TENLOP[vitri-1] == ' ') {vitri--;} //KT khi enter truoc do co phai khoang trang
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(62+vitri,y);
			goto NIENKHOA;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30+vitri, y);
			cout<<" ";
			gotoXY(30+vitri, y);
		}
		if( key == SPACE && ds.l[ds.n].TENLOP[vitri-1] != ' ' && ds.l[ds.n].TENLOP[0] != '\0' && vitri > 0 && vitri < 30)
		{	
			gotoxy(30+vitri, y);
			cout<<" ";
			ds.l[ds.n].TENLOP[vitri] = ' ';
			vitri++;
		}
		if(key == LEFT)
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(12+vitri,y);
			goto MALOP;
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].TENLOP[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].NienKhoa);
			gotoXY(62+vitri, y);
			goto NIENKHOA;
		}
		if(key == ESC || key == F2)		{return;}
	}
NIENKHOA:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 4         ");TextColor(12);gotoXY(62+vitri,y);//Ghi chú
		key = GetKey();
		if(ds.l[ds.n].TENLOP[0] == '\0')		//Kiem tra ô phía truoc có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap Ten Lop!",35,27,74,700);
			gotoXY(30,y);
			goto TENLOP;
		}
		if((key <= '9' && key >= '0') && (vitri < 4))
			{
				ds.l[ds.n].NienKhoa[vitri] = char(key);
				ds.l[ds.n].NienKhoa[vitri] = toupper( ds.l[ds.n].NienKhoa[vitri]);
				cout<<ds.l[ds.n].NienKhoa[vitri];
				vitri++;
			}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			strcpy(ds.l[vitriMang].MALOP, ds.l[ds.n].MALOP);
			strcpy(ds.l[vitriMang].TENLOP, ds.l[ds.n].TENLOP);
			strcpy(ds.l[vitriMang].NienKhoa, ds.l[ds.n].NienKhoa);
			return;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(62+vitri, y);
			cout<<" ";
			gotoXY(62+vitri, y);
		}	
		if(key == LEFT)
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].TENLOP);
			gotoXY(30+vitri, y);
			goto TENLOP;
		}
		if(key == ESC || key == F2)	{return;}
	}	
}
void XoaLop(ListLop &ds, bool &check_change)
{
	int key, x = 35, y = 14, vitri = 0, vitriMang, temp;	ds.l[ds.n].MALOP[0] = NULL;//Khoi tao MaLop rong~
	Khung_Xoa_Lop();	gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				if(ds.l[vitriMang].Head != NULL)
				{
					GhiChu("Lop nay da co Sinh Vien khong the Xoa!",25,27,74,500);	gotoXY(35+vitri,y);	TextColor(12);	continue;
				}
				check_change = true;
				for(int i = vitriMang; i < ds.n; i++){	ds.l[i] = ds.l[i+1];	} //dôn` lên giam? di 1 don vi
				ds.n--;
				return;
			}else{
				GhiChu("Khong co Ma Lop trong Danh Sach!",25,27,74,500);	gotoXY(35+vitri,y);	TextColor(12);	continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ESC || key == F3)		{return;}
	}
}
void XuatLop(ListLop &ds, ListMonHoc *root, int chedoxem)	// chedoxem == 1 thi chi de xem
{
 	int key, dem = 0, trang = 0, tongtrang = 0; bool check_change = false;
	while(1)
	{		
		if(ds.n == 0)
 		{
 			GhiChu("Chua co Danh Sach Lop",35,27,74,1000);
		}else{
			if(ds.n < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((ds.n-1)/15+1);
			}
		}
		TextColor(91);	system("cls");	Khung_Xuat_Lop();
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < ds.n ; i++)
		{
			TextColor(92);gotoxy(6, 8+dem); cout<< ( i+1 );TextColor(91);
			gotoxy(10,8+dem); cout<<ds.l[i].MALOP ;
			gotoxy(31,8+dem); cout<<ds.l[i].TENLOP ;
			gotoxy(72,8+dem); cout<<ds.l[i].NienKhoa ;
			dem++;
		}
		HienThiTrang(trang+1,tongtrang,73,26);
		if(chedoxem == 1)//Dang o che do xem
		{
			TextColor(94);gotoXY(18,24); printf("                 DANG O CHE DO XEM!        ");
			TextColor(236);gotoXY(33,2); printf(" NHAN ESC DE THOAT CHE DO XEM");
		}gotoXY(81,26);
		key = GetKey(); //Bat Phim
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)	{trang++;}
		if((key == LEFT || key == UP) && trang > 0) 				{trang--;}
		if(key == F1 && chedoxem != 1)
		{	
			if(Full_Lop(ds)){continue;}
			gotoXY(18,24);  TextColor(251);	printf("F1"); //To mau` F1
			ThemLop(ds,root,check_change);
		}
		if(key == F2 && chedoxem != 1)
		{
			gotoXY(35,24);	TextColor(251);	printf("F2"); //To mau` F2
			SuaLop(ds,root,check_change);
		}
		if(key == F3 && chedoxem != 1)
		{
			gotoXY(50,24);	TextColor(251);	printf("F3"); //To mau` F3 
			XoaLop(ds,check_change);
		}
		if(key == ESC)
		{
			if(chedoxem == 1){return;};
			if(check_change == true)
			{
				putchar(7);	gotoXY(4,24); TextColor(251);printf("ESC"); //To mau` ESC
				int temp = ThongBao_ESC();
				if(temp == -1)	{continue;}	//Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileLop(ds);LuuFileSV(ds); LuuFileDiem(ds,root);}
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}
			}
			system("cls");
			return;
		}
		if(key == F5 && chedoxem == 1){return;}
	}
}
void XuatLop_NienKhoa(ListLop &ds, ListMonHoc *root)
{
	int vitri = 0, x = 41, y = 14, key, trang = 0, tongtrang = 0, dem = 0, temp = 0;
	char tam[5]; ds.l[ds.n].NienKhoa[0] = NULL; bool check_change = false; 
	Khung_Xuat_NK(); gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((key <= '9' && key >= '0') && (vitri < 4))
		{
			ds.l[ds.n].NienKhoa[vitri] = char(key);
			ds.l[ds.n].NienKhoa[vitri] = toupper( ds.l[ds.n].NienKhoa[vitri]);
			cout<<ds.l[ds.n].NienKhoa[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			ds.l[ds.n].NienKhoa[vitri] = '\0';
			if(KTNienKhoa(ds,ds.l[ds.n].NienKhoa) == 1) //Ktra trùng
			{
				strcpy(tam,ds.l[ds.n].NienKhoa);
				tam[vitri] = '\0';
				goto Xuat;
			}else{
				GhiChu("Nien Khoa khong ton tai! ",30,16,74,500);TextColor(12);	gotoXY(41+vitri,y);	continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(41+vitri, y);
			cout<<" ";
			gotoXY(41+vitri, y);
		}	
		if(key == ESC)	{putchar(7);  TextColor(91);	return;	}
	}
Xuat:
	while(1)	
	{	
		dem = 0; //khoi tao ve 0
		for(int i = 0; i < ds.n; i++)
		{
			if(strcmp(ds.l[i].NienKhoa,tam) == 0)	{dem++;}
		}
		if(ds.n == 0)
	 	{
 			GhiChu("Chua co Danh Sach Lop",35,27,74,1000);
		}else{
				if(dem < 15)		// tuc la co 15 phan tu 0 1 2....14
				{
					tongtrang = 1;
					trang = 0;	
				}else{							//VD tai truong hop dem = 15
					tongtrang = ((dem-1)/15)+1; // (Neu dem/15 + 1) => 15/15 + 1 => tongtrang = 2 khi chi co 15 phan tu (SAI)  0/2
				}								// (Neu (dem-1)/15 +1 => 14/15 +1 => tongtrang = 1 khi co 15 ptu (DUNG) 0/1
		}
		TextColor(91);
		system("cls");
		Khung_Xuat_Lop();
		dem = 0;	//khoi tao ve 0 lai
		for(int i = temp*trang; i < ds.n; i++)	//temp nay chay theo so luong cua lop theo NienKhoa
		{
			if(dem == 15)		// in du 15 dong roi! thoat ra for			
			{
				temp = i;	break;
			}
			if(strcmp(ds.l[i].NienKhoa,tam) != 0 )	{continue;}	//Neu khong phai Nien Khoa can tim
			TextColor(92);gotoxy(6, 8+dem); cout<< (i+1 );TextColor(91);	//In ra So thu tu
			gotoxy(10,8+dem); cout<<ds.l[i].MALOP ;
			gotoxy(31,8+dem); cout<<ds.l[i].TENLOP ;
			gotoxy(72,8+dem); cout<<ds.l[i].NienKhoa ;
			dem++;
		}							
		HienThiTrang(trang+1,tongtrang,73,26); 
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == F1)
		{	
			if(Full_Lop(ds)){continue;}
			gotoXY(18,24);	TextColor(251);	printf("F1"); //Tô màu F1
			ThemLop(ds,root,check_change);
		}	
		if(key == F2)
		{
			gotoXY(35,24);	TextColor(251);	printf("F2"); //Tô màu F2
			SuaLop(ds,root,check_change);
		}
		if(key == F3)
		{
			gotoXY(50,24);	TextColor(251);	printf("F3"); //Tô màu F3
			XoaLop(ds,check_change);
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC();
				if(temp == -1)	{continue;} //Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileLop(ds);LuuFileSV(ds); LuuFileDiem(ds,root);}
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}	
			}
			system("cls");	return;
		}
	}
}
//====================NHAP-XUAT-HIEU CHINH SINH VIEN====================
int Full_SV(int dem)	//tra ve 1: tran bo nho da cap phat
{
	if(dem == maxsv-1){GhiChu("Danh sach Sinh Vien Full. Khong the them!",35,27,74,700); return 1;} return 0;
}
void NhapSinhVien(ListLop &ds, ListMonHoc *root)
{
	int key, check_trung, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1; bool check_change = false;	//vitriMang : vitri cua lop
	Khung_Nhap_MaLop();	gotoXY(x,y); ds.l[ds.n].MALOP[0] = NULL;	//Khoi tao rong~
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n); //Kiem tra trùng ma lop
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;	
				}else{
					vitriMang = temp;
				}
				TextColor(91);	system("cls");	break;
			}else{
				GhiChu("     Ma Lop Khong Ton Tai!    ",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);	continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40+vitri, y);
			cout<<" ";
			gotoXY(40+vitri, y);
		}
		if (key == F5)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			XuatLop(ds,root,1);
			Khung_Nhap_MaLop();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ");
			TextColor(12);	gotoXY(40,y); cout<<ds.l[ds.n].MALOP;	//In lai nhung gi da nhap
		}
		if(key == ESC)	{TextColor(91);	return;}
	}
	x = 10, y = 8, vitri = 0;
	int dem = 0, demkhongdoi = 0;
	SinhVien demsv[maxsv];
	for(int i = 0; i < maxsv; i++) // Khoi tao mang tam rong~
	{
		demsv[i].MASV[0] = NULL; demsv[i].HO[0] = NULL; demsv[i].TEN[0] = NULL; demsv[i].PHAI[0] = NULL; demsv[i].SODT[0] =NULL;
	}
	Khung_Nhap_SV();
	TextColor(92);		gotoXY(6,8); 	 cout<<STT;		TextColor(91); //In STT dau tien
MASV:
	while(1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                              ");
		gotoXY(20,30); printf(" MA SINH VIEN: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 15 KI TU  ");
		gotoXY(20,31); printf("                                                              "); TextColor(91);gotoXY(10+vitri,y);
		key = GetKey();
		if(demsv[dem-1].SODT[0] == '\0' && y > 8)		//Kiem tra ô phía truoc' có du~ lieu chua
		{
			GhiChu("Ban Chua Nhap SDT!",35,27,74,700);
			gotoXY(69,--y);
			dem--;
			goto SODT;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			if(Full_SV(dem)){continue;}
			demsv[dem].MASV[vitri] = char(key);
			demsv[dem].MASV[vitri] = toupper(demsv[dem].MASV[vitri]);
			cout<<demsv[dem].MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(10+vitri, y);
			cout<<" ";
			gotoXY(10+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			if(Full_SV(dem)){continue;} 
			demsv[dem].MASV[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{
				if(i == dem){continue;}	// khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if(strcmp(demsv[i].MASV,demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);
					goto MASV;
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,demsv[dem].MASV,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(demsv[dem].HO);
			gotoXY(26+vitri,y);
			goto HO;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				demsv[dem].MASV[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue; //Tô màu ESC
				}	
				if(temp == 1) // 1 la YES 
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}	//Do? mang? tam. vao DSLK (bo nho trong)
					LuuFileSV(ds); LuuFileDiem(ds,root);
				}
				if(temp == 0) // 0 la NO
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}	//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}
			system("cls");	return;
		}
		if(key == RIGHT)
		{
			if(Full_SV(dem)){continue;}
			demsv[dem].MASV[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{			
				if(i == dem){continue;} // khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if(strcmp(demsv[i].MASV,demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);
					goto MASV;
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,demsv[dem].MASV,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(demsv[dem].HO);
			gotoXY(26+vitri,y);
			goto HO;
		}
		if(key == DOWN && y < 22 && demsv[1+dem].MASV[0] != '\0')
		{		
			if(Full_SV(dem)){continue;}
			demsv[dem].MASV[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{	
				if(i == dem){continue;}// khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if(strcmp(demsv[i].MASV,demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);
					goto MASV;
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,demsv[dem].MASV,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			dem++;
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10+vitri,++y);
		}
		if(key == UP &&	y > 8)
		{
			if(Full_SV(dem)){continue;}
			demsv[dem].MASV[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{	
				if(i == dem){continue;}	// khi user sua loi~ cac MASV o tren bo? qua duyet bô. dêm. chính nó
				if(strcmp(demsv[i].MASV,demsv[dem].MASV) == 0) //KT trung sinh vien o mang? tam.
				{
					GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);
					goto MASV;
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,demsv[dem].MASV,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			dem--;
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10+vitri,--y);
		}
	}
HO:
	while(1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20,29); printf("                                                              ");
		gotoXY(20,30); printf("      HO: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 20 KI TU       ");
		gotoXY(20,31); printf("                                                              "); 
		TextColor(91);gotoXY(26+vitri,y);
		key = GetKey();
		if(demsv[dem].MASV[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap Ma Sinh Vien!",35,27,74,700);
			gotoXY(10,y);
			goto MASV;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 20))
		{
			demsv[dem].HO[vitri] = char(key);
			demsv[dem].HO[vitri] = toupper(demsv[dem].HO[vitri]);
			cout<<demsv[dem].HO[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(26+vitri, y);
			cout<<" ";
			gotoXY(26+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			if(demsv[dem].HO[vitri-1] == ' ') 	{vitri--;}//KT khi enter truoc do co phai khoang trang
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47+vitri, y);
			goto TEN;
		}
		if( key == SPACE && demsv[dem].HO[vitri-1] != ' ' && vitri > 0 && vitri < 20)
		{	
			gotoxy(26+vitri , y);
			cout<<" ";
			demsv[dem].HO[vitri] = ' ';
			vitri++;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				demsv[dem].HO[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue; //Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
					LuuFileSV(ds);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}		
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10+vitri,y);
			goto MASV;
		}
		if(key == RIGHT)
		{
			demsv[dem].HO[vitri] = '\0';
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47+vitri,y);
			goto TEN;
		}
		if(key == UP && y > 8)
		{
			demsv[dem].HO[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].HO);
			gotoXY(26+vitri,--y);
		}
		if(key == DOWN && y < 22 && demsv[1+dem].HO[0] != '\0')
		{
			demsv[dem].HO[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].HO);
			gotoXY(26+vitri,++y);
		}
	}
TEN:
	while(1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20,29); printf("                                                               ");
		gotoXY(20,30); printf("          TEN: GOM CAC KI TU (A-Z), TOI DA: 10 KI TU           ");
		gotoXY(20,31); printf("                                                               "); 
		TextColor(91);gotoXY(47+vitri,y);
		key = GetKey();
		if(demsv[dem].HO[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ho!",35,27,74,700);
			gotoXY(26,y);
			goto HO;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			demsv[dem].TEN[vitri] = char(key);
			demsv[dem].TEN[vitri] = toupper(demsv[dem].TEN[vitri]);
			cout<<demsv[dem].TEN[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(47+vitri, y);
			cout<<" ";
			gotoXY(47+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58+vitri,y);
			goto PHAI;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				demsv[dem].TEN[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;//Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
					LuuFileSV(ds);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].HO);
			gotoXY(26+vitri,y);
			goto HO;
		}
		if(key == RIGHT)
		{
			demsv[dem].TEN[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58+vitri,y);
			goto PHAI;
		}
		if(key == UP && y > 8)
		{
			demsv[dem].TEN[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47+vitri,--y);
		}
		if(key == DOWN && y < 22 && demsv[1+dem].TEN[0] != '\0')
		{
			demsv[dem].TEN[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47+vitri,++y);
		}
	}
PHAI:
	while(1)
	{
		TextColor(252);			//Chu thich
		gotoXY(20,29); printf("                                                                ");
		gotoXY(20,30); printf("      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ");
		gotoXY(20,31); printf("                                                                "); 	TextColor(91);gotoXY(58+vitri,y);
		key = GetKey();
		if(demsv[dem].TEN[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten!",35,27,74,700);
			gotoXY(47,y);
			goto TEN;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 3))
		{
			demsv[dem].PHAI[vitri] = char(key);
			demsv[dem].PHAI[vitri] = toupper(demsv[dem].PHAI[vitri]);
			cout<<demsv[dem].PHAI[vitri];
			vitri++;
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58+vitri, y);
			cout<<" ";
			gotoXY(58+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if((strcmp(demsv[dem].PHAI,"NAM") == 0) || (strcmp(demsv[dem].PHAI,"NU") == 0)) // So sanh
			{
				vitri = strlen(demsv[dem].SODT);
				gotoXY(69+vitri,y);
				goto SODT;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); continue;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				demsv[dem].PHAI[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;//Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
					LuuFileSV(ds);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}
			system("cls"); 	return;
		}
		if(key == LEFT)	
		{
			demsv[dem].PHAI[vitri] = '\0';
			if((strcmp(demsv[dem].PHAI,"NAM") != 0) && (strcmp(demsv[dem].PHAI,"NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500);	continue;
			}
			vitri = strlen(demsv[dem].TEN);
			gotoXY(47+vitri,y);
			goto TEN;
		}
		if(key == RIGHT)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if((strcmp(demsv[dem].PHAI,"NAM") != 0) && (strcmp(demsv[dem].PHAI,"NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500);	continue;
			}
			vitri = strlen(demsv[dem].SODT);
			gotoXY(69+vitri,y);
			goto SODT;
		}
		if(key == UP && y > 8)
		{
			demsv[dem].PHAI[vitri] = '\0';
			if((strcmp(demsv[dem].PHAI,"NAM") != 0) && (strcmp(demsv[dem].PHAI,"NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500);	continue;
			}
			dem--;
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58+vitri,--y);
		}
		if(key == DOWN && y < 22 && demsv[1+dem].PHAI[0] != '\0')
		{
			demsv[dem].PHAI[vitri] = '\0';
			if((strcmp(demsv[dem].PHAI,"NAM") != 0) && (strcmp(demsv[dem].PHAI,"NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500);	continue;
			}
			dem++;
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58+vitri,++y);
		}
	}
SODT:
	while(1)
	{
		TextColor(252);
		gotoXY(20,29); printf("                                                                 ");
		gotoXY(20,30); printf("      SO DIEN THOAI: GOM CAC KI TU (0-9), TOI DA: 11 KI TU       ");
		gotoXY(20,31); printf("                                                                 "); TextColor(91);gotoXY(69+vitri,y);
		key = GetKey();
		if(demsv[dem].PHAI[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Phai!",35,27,74,700);
			gotoXY(58,y);
			goto PHAI;
		}
		if((key <= '9' && key >= '0') && (vitri < 11))
		{
			demsv[dem].SODT[vitri] = char(key);
			demsv[dem].SODT[vitri] = toupper(demsv[dem].SODT[vitri]);
			cout<<demsv[dem].SODT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(69+vitri, y);
			cout<<" ";
			gotoXY(69+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			GhiChu("Save Thanh Cong!",40,27,74,500);	TextColor(92);
			gotoXY(6,y+1);
			demsv[dem].SODT[vitri] = '\0';
			if(demsv[1+dem].MASV[0] == '\0' && dem == demkhongdoi) // khong cho bien demkhongdoi tang khi sua loi~ cac SDT o tren
			{
				cout<<++STT; //Cho xuat hien STT
				demkhongdoi++;	// De cuoi cung ESC gan' cho dem
			}
			if((STT-1) % 15 == 0)
			{
				y = 7;
				system("cls");
				Khung_Nhap_SV();	TextColor(92);	gotoXY(6,8); cout<<STT;	
			}
			TextColor(91);	
			dem++;	//dem nay co the thay doi khi di chuyen => can bien demkhongdoi
			vitri = strlen(demsv[dem].MASV);
			gotoXY(10+vitri,++y);
			goto MASV;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				demsv[dem].SODT[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91);	continue;//Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
					LuuFileSV(ds);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertTail_SV(ds.l[vitriMang].Head,demsv[i]);}//Do? mang? tam. vao DSLK (bo nho trong)
				}
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			demsv[dem].SODT[vitri] = '\0';
			vitri = strlen(demsv[dem].PHAI);
			gotoXY(58+vitri, y);
			goto PHAI;
		}
		if(key == UP && y > 8)
		{
			demsv[dem].SODT[vitri] = '\0';
			dem--;
			vitri = strlen(demsv[dem].SODT);
			gotoXY(69+vitri, --y);
		}
		if(key == DOWN && y < 22 && demsv[1+dem].SODT[0] != '\0')
		{
			demsv[dem].SODT[vitri] = '\0';
			dem++;
			vitri = strlen(demsv[dem].SODT);
			gotoXY(69+vitri, ++y);
		}
	}
}
void ThemSinhVien(ListSV *&Head, ListLop ds, ListMonHoc *root, bool &check_change)
{
	int key, check_trung, vitri = 0, x = 12, y = 14, temp = 0;
	SinhVien sv; sv.MASV[0] = NULL; sv.HO[0] = NULL; sv.TEN[0] = NULL; sv.PHAI[0] = NULL; sv.SODT[0] = NULL;
	Khung_Them_SV(); gotoXY(x,y);
MASV:
	while(1)
	{
		TextColor(106); gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15"); TextColor(12); gotoXY(12+vitri,y); //Ghi chú
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout<<sv.MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.MASV[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,sv.MASV,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == RIGHT)
		{
			sv.MASV[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,sv.MASV,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == ESC || key == F1){return;}
	}
HO:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 20"); TextColor(12); gotoXY(29+vitri,y);//Ghi chú
		key = GetKey();
		if(sv.MASV[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap MA Sinh Vien!",35,27,74,700);
			gotoXY(12,y);
			goto MASV;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 20))
		{
			sv.HO[vitri] = char(key);
			sv.HO[vitri] = toupper(sv.HO[vitri]);
			cout<<sv.HO[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29+vitri, y);
			cout<<" ";
			gotoXY(29+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			if(sv.HO[vitri-1] == ' ') 	{vitri--;}	//KT khi enter truoc do co phai khoang trang
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if( key == SPACE && sv.HO[vitri-1] != ' ' && vitri > 0 && vitri < 20)
		{	
			gotoxy(29+vitri , y);
			cout<<" ";
			sv.HO[vitri] = ' ';
			vitri++;
		}
		if(key == LEFT)
		{
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.MASV);
			gotoXY(12+vitri, y);
			goto MASV;
		}
		if(key == RIGHT)
		{
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if(key == ESC || key == F1){return;}
	}
TEN:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z). Toi da: 10        "); TextColor(12); gotoXY(51+vitri,y);
		key = GetKey();
		if(sv.HO[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap HO Sinh Vien!",35,27,74,700);
			gotoXY(29,y);
			goto HO;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			sv.TEN[vitri] = char(key);
			sv.TEN[vitri] = toupper(sv.TEN[vitri]);
			cout<<sv.TEN[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51+vitri, y);
			cout<<" ";
			gotoXY(51+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == LEFT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == RIGHT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == ESC || key == F1){return;}
	}
PHAI:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Gioi tinh Nam / Nu. Toi da: 3         "); TextColor(12); gotoXY(63+vitri,y); //Ghi chú
		key = GetKey();
		if(sv.TEN[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap TEN Sinh Vien!",35,27,74,700);
			gotoXY(51,y);
			goto TEN;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 3))
		{
			sv.PHAI[vitri] = char(key);
			sv.PHAI[vitri] = toupper(sv.PHAI[vitri]);
			cout<<sv.PHAI[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(63+vitri, y);
			cout<<" ";
			gotoXY(63+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") == 0) || (strcmp(sv.PHAI,"NU") == 0)) // So sanh
			{
				vitri = strlen(sv.SODT);
				goto SODT;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); continue;
		}
		if(key == LEFT)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") != 0) && (strcmp(sv.PHAI,"NU") != 0))
				{
					GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); continue;
				}
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if(key == RIGHT)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") != 0) && (strcmp(sv.PHAI,"NU") != 0))
				{
					GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); continue;
				}
			vitri = strlen(sv.SODT);
			gotoXY(68+vitri, y);
			goto SODT;
		}
		if(key == ESC || key == F1){return;}
	}
SODT:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 11        ");	TextColor(12);	gotoXY(68+vitri,y); // Ghi chú
		key = GetKey();
		if(sv.PHAI[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!",35,27,74,700);
			gotoXY(63,y);
			goto PHAI;
		}
		if((key <= '9' && key >= '0') && (vitri < 11))
		{
			sv.SODT[vitri] = char(key);
			sv.SODT[vitri] = toupper(sv.SODT[vitri]);
			cout<<sv.SODT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(68+vitri, y);
			cout<<" ";
			gotoXY(68+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			sv.SODT[vitri] = '\0';
			InsertTail_SV(Head,sv);
			return;
		}
		if(key == LEFT)
		{
			sv.SODT[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == ESC || key == F1){return;}
	}
}
void SuaSinhVien(ListSV *&Head, ListLop ds, ListMonHoc *root, bool &check_change)
{
	int key, check_trung, x = 35, y = 14, vitri = 0;
	ListSV *temppointer;
	SinhVien sv; sv.MASV[0] = NULL; sv.HO[0] = NULL; sv.TEN[0] = NULL; sv.PHAI[0] = NULL; sv.SODT[0] = NULL; //Khoi tao rong~
	Khung_Sua_SV(); gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout<<sv.MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.MASV[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTSinhVien(Head,sv.MASV);//KT trung sinh vien trong List
			if(check_trung != 2)
			{
				vitri = 0;
				temppointer = FindMaSV(Head,sv.MASV); break; //Tra ve con tro? sinh vien da tim` thay'. TH NULL da~ duoc KTSinhVien phu? 
			}else{
				GhiChu("Ma Sinh Vien Khong Ton Tai!",35,27,74,500);	TextColor(12);	gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == F2){return;}
	}
	Khung_Them_SV();	x = 12, y = 14; 	gotoXY(12,y);
MASV:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15");	TextColor(12);	gotoXY(12+vitri,y); //Ghi chú
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout<<sv.MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.MASV[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,sv.MASV,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == RIGHT)
		{
			sv.MASV[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,sv.MASV,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == ESC || key == F2){return;}
	}
HO:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 20"); TextColor(12); gotoXY(29+vitri,y); //Ghi chú
		key = GetKey();
		if(sv.MASV[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap MA Sinh Vien!",35,27,74,700);
			gotoXY(12,y);
			goto MASV;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 20))
		{
			sv.HO[vitri] = char(key);
			sv.HO[vitri] = toupper(sv.HO[vitri]);
			cout<<sv.HO[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(29+vitri, y);
			cout<<" ";
			gotoXY(29+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			if(sv.HO[vitri-1] == ' ')	{vitri--;} //KT khi enter truoc do co phai khoang trang
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if( key == SPACE && sv.HO[vitri-1] != ' ' && vitri > 0 && vitri < 20)
		{
			gotoxy(29+vitri , y);
			cout<<" ";
			sv.HO[vitri] = ' ';
			vitri++;
		}
		if(key == LEFT)
		{
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.MASV);
			gotoXY(12+vitri, y);
			goto MASV;
		}
		if(key == RIGHT)
		{
			sv.HO[vitri] = '\0';
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if(key == ESC || key == F2){return;}
	}
TEN:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z). Toi da: 10        "); TextColor(12); gotoXY(51+vitri,y);//Ghi chú
		key = GetKey();
		if(sv.HO[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap HO Sinh Vien!",35,27,74,700);
			gotoXY(29,y);
			goto HO;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 10))
		{
			sv.TEN[vitri] = char(key);
			sv.TEN[vitri] = toupper(sv.TEN[vitri]);
			cout<<sv.TEN[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(51+vitri, y);
			cout<<" ";
			gotoXY(51+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == LEFT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.HO);
			gotoXY(29+vitri, y);
			goto HO;
		}
		if(key == RIGHT)
		{
			sv.TEN[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == ESC || key == F2){return;}
	}
PHAI:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Gioi tinh Nam / Nu. Toi da: 3         "); TextColor(12); gotoXY(63+vitri,y); //Ghi chú
		key = GetKey();
		if(sv.TEN[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap TEN Sinh Vien!",35,27,74,700);
			gotoXY(51,y);
			goto TEN;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 3))
		{
			sv.PHAI[vitri] = char(key);
			sv.PHAI[vitri] = toupper(sv.PHAI[vitri]);
			cout<<sv.PHAI[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(63+vitri, y);
			cout<<" ";
			gotoXY(63+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") == 0) || (strcmp(sv.PHAI,"NU") == 0)) // So sanh
			{
				vitri = strlen(sv.SODT);
				gotoXY(68+vitri, y);
				goto SODT;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); continue;
		}
		if(key == LEFT)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") != 0) && (strcmp(sv.PHAI,"NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); 	continue;
			}
			vitri = strlen(sv.TEN);
			gotoXY(51+vitri, y);
			goto TEN;
		}
		if(key == RIGHT)
		{
			sv.PHAI[vitri] = '\0';
			if((strcmp(sv.PHAI,"NAM") != 0) && (strcmp(sv.PHAI,"NU") != 0))
				{
					GhiChu("Gioi Tinh phai la Nam/Nu!",35,27,74,500); 	continue;
				}
			vitri = strlen(sv.SODT);
			gotoXY(68+vitri, y);
			goto SODT;
		}
		if(key == ESC || key == F2){return;}
	}
SODT:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 11        "); TextColor(12); gotoXY(68+vitri,y); //Ghi chú
		key = GetKey();
		if(sv.PHAI[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!",35,27,74,700);
			gotoXY(63,y);
			goto PHAI;
		}
		if((key <= '9' && key >= '0') && (vitri < 11))
		{
			sv.SODT[vitri] = char(key);
			sv.SODT[vitri] = toupper(sv.SODT[vitri]);
			cout<<sv.SODT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(68+vitri, y);
			cout<<" ";
			gotoXY(68+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			sv.SODT[vitri] = '\0';
			temppointer->sv = sv; //Cap nhat tai vi tri con tro? mot du lieu moi'
			return;
		}
		if(key == LEFT)
		{
			sv.SODT[vitri] = '\0';
			vitri = strlen(sv.PHAI);
			gotoXY(63+vitri, y);
			goto PHAI;
		}
		if(key == ESC || key == F2){return;}
	}
}
void XoaSinhVien(ListLop &ds, ListSV *&Head, bool &check_change)
{
	int key, x = 35, y = 14, vitri = 0, temp;
	SinhVien sv; 	sv.MASV[0] = NULL;
	ListSV *temppointer;
	Khung_Xoa_SV();	gotoXY(x,y);
	while(1)
	{
Reset:
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			sv.MASV[vitri] = char(key);
			sv.MASV[vitri] = toupper(sv.MASV[vitri]);
			cout<<sv.MASV[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			sv.MASV[vitri] = '\0';	//Ngat chuoi~
			temp = KTSinhVien(Head,sv.MASV);//KT trung sinh vien trong List
			temppointer = FindSV(ds,sv.MASV);
			if(temp != 2)
			{
				for(ListDiem *p = temppointer->sv.Head; p != NULL; p = p->Next)
				{
					if(p->d.DIEM[0] != NULL)	
					{
						GhiChu("Sinh Vien da co Diem khong the Xoa!",30,27,74,500);	TextColor(12);	gotoXY(35+vitri,y); goto Reset;
					}
				}
				check_change = true;
				if(temp == 1)	{XoaNodeDauSV(Head);}
				if(temp == 0)	{XoaNodeGiuaSV(Head,sv.MASV);}
				if(temp == -1)	{XoaNodeCuoiSV(Head);}
				return;
			}else{
				GhiChu("Ma Sinh Vien Khong Ton Tai!",35,27,74,500);	TextColor(12);	gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == F3){return;}
	}
}
void XuatSinhVien(ListLop &ds, ListMonHoc *root)
{
	int key, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1;	//vitriMang : vitri cua lop
	Khung_Nhap_MaLop(); ds.l[ds.n].MALOP[0] = NULL; bool check_change = false;
	gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
			{
				ds.l[ds.n].MALOP[vitri] = char(key);
				ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
				cout<<ds.l[ds.n].MALOP[vitri];
				vitri++;
			}
		if(key == ENTER && vitri != 0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n); //KT trung ma lop
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				break;
			}else{
				GhiChu("     Ma Lop Khong Ton Tai!    ",33,5,159,500);	gotoXY(40+vitri,y);		TextColor(12);
				continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40+vitri, y);
			cout<<" ";
			gotoXY(40+vitri, y);
		}
		if (key == F5)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			XuatLop(ds,root,1);
			Khung_Nhap_MaLop();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ");
			TextColor(12);	gotoXY(40,y); cout<<ds.l[ds.n].MALOP;
		}
		if(key == ESC)	{TextColor(91); return;}
	}
	int trang = 0, tongtrang = 0, soluongsv = 0, dem1 = 0, dem = 0;	//dem la dem dong`.  dem1 la vitri phan tu sv
	while(1)
	{		
		dem1 = 0;
		soluongsv = DemSinhVien(ds.l[vitriMang].Head);
		if(soluongsv == 0)
		{
			GhiChu("Chua co du lieu sinh vien",35,27,74,500);
		}else{
			if(soluongsv < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongsv-1)/15+1);
			}
		}
		SapXepSV(ds.l[vitriMang].Head); 	//Sap Xep danh sach theo Ten Ho
		SinhVien sv[soluongsv+1];
		for(ListSV *p = ds.l[vitriMang].Head; p != NULL; p = p->Next) 	{sv[dem1] = p->sv; dem1++;} //Dô? DSSV vào mang?
		TextColor(91);	system("cls");
		Khung_Xuat_SV();
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongsv ; i++)
		{
			TextColor(92);gotoxy(6, 8+dem); cout<< ( i+1 );TextColor(91);
			gotoxy(10,8+dem); cout<<sv[i].MASV;
			gotoxy(26,8+dem); cout<<sv[i].HO;
			gotoxy(47,8+dem); cout<<sv[i].TEN;
			gotoxy(58,8+dem); cout<<sv[i].PHAI;
			gotoxy(69,8+dem); cout<<sv[i].SODT;
			dem++;
		}
		TextColor(206);	gotoXY(1,0);printf("MA lOP:");gotoXY(1,2);printf("TEN LOP:");gotoXY(1,4);printf("NIEN KHOA:");
		TextColor(80); gotoXY(9,0);cout<<ds.l[vitriMang].MALOP;gotoXY(10,2);cout<<ds.l[vitriMang].TENLOP;gotoXY(12,4);cout<<ds.l[vitriMang].NienKhoa;
		HienThiTrang(trang+1,tongtrang,73,26);gotoXY(81,26);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == F1)
		{	
			gotoXY(18,24);  TextColor(251);	printf("F1"); //Tô màu F1
			ThemSinhVien(ds.l[vitriMang].Head, ds, root, check_change);
		}
		if(key == F2)
		{
			gotoXY(35,24);	TextColor(251);	printf("F2"); //Tô màu F2	
			SuaSinhVien(ds.l[vitriMang].Head, ds, root, check_change);
		}
		if(key == F3)
		{
			gotoXY(50,24);	TextColor(251);	printf("F3"); //Tô màu F3
			XoaSinhVien(ds, ds.l[vitriMang].Head, check_change);
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC();
				if(temp == -1)	{continue;} //Tra ve -1 => Bat' duoc phim' ESC 1 lân` nua~
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileSV(ds);LuuFileDiem(ds,root);} //Them 1 SV moi cap nhat lai 
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}							   // danh sach file diem
			}	
			system("cls");	return;
		}
	}
}
void TimKiem_or_Xoa_1_SV(ListLop &ds, ListMonHoc *root)
{
	int key, temp = 0, vitri = 0, x = 35, y = 14; bool check_change = false;
	SinhVien sv; ListSV *bienphu;		sv.MASV[0] = NULL; //Khoi tao rong~
	Lop l;
	Khung_Nhap_MaSV();	gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
			{
				sv.MASV[vitri] = char(key);
				sv.MASV[vitri] = toupper(sv.MASV[vitri]);
				cout<<sv.MASV[vitri];
				vitri++;
			}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			sv.MASV[vitri] = '\0';	//Ngat chuoi~
			for(int i = 0; i < ds.n; i++)	//Duyet cac Lop
			{
				temp = KTSinhVien(ds.l[i].Head,sv.MASV); //KT trung sinh vien trong List
				bienphu = FindMaSV(ds.l[i].Head,sv.MASV); // Lay dia chi con tro
				if(temp != 2)
				{
					l = ds.l[i];
					system("cls");
					TextColor(91);
					goto Xuat;
				}
			}
			if(temp == 2)
			{
				GhiChu("Ma Sinh Vien Khong Ton Tai!",29,16,74,300);	TextColor(12);	gotoXY(35+vitri,y);
			}
		}
		if(key == ESC)	{TextColor(91);	return;}
	}
Xuat:
	int flag = 0; //flag == 0 la chua xoa flag == 1 la xoa du lieu roi
	while(1)
	{
		Khung_ThongTin_SV();
		TextColor(91);
		if(flag == 0)
		{
			gotoXY(4,8); cout<<l.MALOP;	
			gotoXY(20,8); cout<<bienphu->sv.MASV;
			gotoXY(36,8); cout<<bienphu->sv.HO;
			gotoXY(57,8); cout<<bienphu->sv.TEN;
			gotoXY(68,8); cout<<bienphu->sv.PHAI;
			gotoXY(72,8); cout<<bienphu->sv.SODT;
		}else{
			gotoXY(4,8); cout<<"               ";	
			gotoXY(20,8); cout<<"              ";	
			gotoXY(36,8); cout<<"                   ";	
			gotoXY(57,8); cout<<"          ";	
			gotoXY(68,8); cout<<"   ";	
			gotoXY(72,8); cout<<"           ";	
		}
		gotoXY(74,11);
		key = GetKey();
		if(key == DELETE && flag == 0)
		{
			putchar(7);	TextColor(250);	gotoXY(47,10);printf("DELETE"); //Tô màu DELETE
			int bientam = ThongBao_Xoa();
			if(bientam == 1)
			{
				check_change = true;
				if(temp == 1) 	{XoaNodeDauSV(l.Head);}
				if(temp == -1)  {XoaNodeCuoiSV(l.Head);}
				if(temp == 0)	{XoaNodeGiuaSV(l.Head,bienphu->sv.MASV);}
				flag = 1;
				LuuFileDiem(ds,root);
			}
			TextColor(12);
			gotoXY(24,12); printf("                                    ");
			gotoXY(24,13); printf("                                    ");
			gotoXY(24,14); printf("                                    ");
			gotoXY(24,15); printf("                                    ");
			gotoXY(24,16); printf("                                    ");
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				putchar(7); TextColor(251);	gotoXY(74,10); printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC();
				if(temp == -1)
				{
					TextColor(12);
					gotoXY(24,12); printf("                                     ");
					gotoXY(24,13); printf("                                     ");
					gotoXY(24,14); printf("                                     ");
					gotoXY(24,15); printf("                                     ");
					gotoXY(24,16); printf("                                     ");
					continue;
				}
				if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileSV(ds);}
				if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}
			}	
			system("cls");	return;
		}
	}
}
//====================NHAP-XUAT-HIEU CHINH MON HOC====================
int Full_MonHoc(int dem)
{
	if(dem == maxmh-1){GhiChu("Danh sach Mon Hoc Full. Khong the them!",35,27,74,700);return 1;} return 0;
}
void NhapMonHoc(ListLop ds, ListMonHoc *&root)
{
	int key, x = 10, y = 8, vitri = 0, dem = 0, demkhongdoi = 0, check_trung, STT = 1; bool check_change = false;
	MonHoc MH[maxmh];
	for(int i = 0; i < maxmh; i++)	{MH[i].MAMH[0] = NULL; MH[i].TENMH[0] = NULL; MH[i].STCLT[0] = NULL; MH[i].STCTH[0] = NULL;} //Khoi tao rong~
	Khung_Nhap_MH();
	TextColor(92); gotoXY(6,8); cout<<STT; gotoXY(x,y); TextColor(91);
MAMH:
	while(1)
	{
		TextColor(252);
		gotoXY(20,29); printf("                                                           ");
		gotoXY(20,30); printf(" MA MON HOC: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 15 KI TU ");
		gotoXY(20,31); printf("                                                           "); TextColor(91);gotoXY(10+vitri,y);
		key = GetKey();
		if(MH[dem-1].STCTH[0] == '\0' && y > 8)
		{
			GhiChu("Ban Chua Nhap STCTH!",35,27,74,700);
			gotoXY(80,--y);
			dem--;
			goto STCTH;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			if(Full_MonHoc(dem)){continue;}
			MH[dem].MAMH[vitri] = char(key);
			MH[dem].MAMH[vitri] = toupper(MH[dem].MAMH[vitri]);
			cout<<MH[dem].MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(10+vitri, y);
			cout<<" ";
			gotoXY(10+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			if(Full_MonHoc(dem)){continue;}
			MH[dem].MAMH[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{
				if(i == dem){continue;}	//Khi dang sua va bi trung` tai vitri dem hien tai
				if(strcmp(MH[i].MAMH,MH[dem].MAMH) == 0) //KTtrung MaMH o mang? tam.
				{
					GhiChu("Trung Ma Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);
					goto MAMH;	
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,MH[dem].MAMH,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(MH[dem].TENMH);
			gotoXY(31+vitri,y);
			goto TENMH;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				MH[dem].MAMH[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); //Tô màu ESC
					gotoXY(10+vitri,y);
					continue;
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
					LuuFileMH(root);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
				}
			}
			system("cls");	return;
		}
		if(key == RIGHT)
		{
			if(Full_MonHoc(dem)){continue;}
			MH[dem].MAMH[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{
				if(i == dem){continue;}	//Khi dang sua va bi trung` tai vitri dem hien tai
				if(strcmp(MH[i].MAMH,MH[dem].MAMH) == 0) //KTtrung MaMH o mang? tam.
				{
					GhiChu("Trung Ma Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);
					goto MAMH;	
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,MH[dem].MAMH,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			vitri = strlen(MH[dem].TENMH);
			gotoXY(31+vitri,y);
			goto TENMH;
		}
		if(key == DOWN && y < 22 && MH[1+dem].MAMH[0] != '\0')
		{ 
			if(Full_MonHoc(dem)){continue;}
			MH[dem].MAMH[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{
				if(i == dem){continue;}	//Khi dang sua va bi trung` tai vitri dem hien tai
				if(strcmp(MH[i].MAMH,MH[dem].MAMH) == 0) //KTtrung MaMH o mang? tam.
				{
					GhiChu("Trung Ma Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);
					goto MAMH;	
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,MH[dem].MAMH,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			dem++;
			vitri = strlen(MH[dem].MAMH);
			gotoXY(10+vitri, ++y);		
		}
		if(key == UP &&	y > 8)
		{
			if(Full_MonHoc(dem)){continue;}
			MH[dem].MAMH[vitri] = '\0';
			for(int i = 0; i <= demkhongdoi; i++)
			{
				if(i == dem){continue;}	//Khi dang sua va bi trung` tai vitri dem hien tai
				if(strcmp(MH[i].MAMH,MH[dem].MAMH) == 0) //KTtrung MaMH o mang? tam.
				{
					GhiChu("Trung Ma Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);
					goto MAMH;	
				}
			}
			check_trung = KT_Lop_SV_MH(ds,root,MH[dem].MAMH,ds.n);
			if(check_trung == -1)	{GhiChu("Trung Ma Lop. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			if(check_trung == -2)	{GhiChu("Trung Ma Sinh Vien. Vui Long Nhap Lai!",35,27,74,500);		gotoXY(10+vitri,y);	continue;}
			if(check_trung == -3)	{GhiChu("Trung Mon Hoc. Vui Long Nhap Lai!",35,27,74,500);			gotoXY(10+vitri,y);	continue;}
			dem--;
			vitri = strlen(MH[dem].MAMH);
			gotoXY(10+vitri, --y);
		}
}
TENMH:
	while(1)
	{
		TextColor(252);
		gotoXY(20,29); printf("                                                           ");
		gotoXY(20,30); printf(" TEN MON HOC: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 35 KI TU");
		gotoXY(20,31); printf("                                                           "); TextColor(91);gotoXY(31+vitri,y);
		key = GetKey();
		if(MH[dem].MAMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ma Mon Hoc!",35,27,74,700);
			gotoXY(10,y);
			goto MAMH;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 35))
		{
			MH[dem].TENMH[vitri] = char(key);
			MH[dem].TENMH[vitri] = toupper(MH[dem].TENMH[vitri]);
			cout<<MH[dem].TENMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31+vitri, y);
			cout<<" ";
			gotoXY(31+vitri, y);
		}
		if( key == SPACE && MH[dem].TENMH[vitri-1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoxy(31+vitri , y);
			cout<<" ";
			MH[dem].TENMH[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			if(MH[dem].TENMH[vitri-1] == ' ') 	{vitri--;}	//KT khi enter truoc do co phai khoang trang
			MH[dem].TENMH[vitri] = '\0';	//Ngat' chuoi~
			vitri = strlen(MH[dem].STCLT);
			gotoXY(72+vitri,y);
			goto STCLT;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				MH[dem].TENMH[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); continue; //Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
					LuuFileMH(root);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
				}	
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			MH[dem].TENMH[vitri] = '\0';
			vitri = strlen(MH[dem].MAMH);
			gotoXY(10+vitri, y);
			goto MAMH;
		}
		if(key == RIGHT)
		{
			MH[dem].TENMH[vitri] = '\0';
			vitri = strlen(MH[dem].STCLT);
			gotoXY(72+vitri, y);
			goto STCLT;
		}
		if(key == UP && y > 8)
		{
			MH[dem].TENMH[vitri] = '\0';
			dem--;
			vitri = strlen(MH[dem].TENMH);
			gotoXY(31+vitri, --y);
		}
		if(key == DOWN && y < 22 && MH[1+dem].TENMH[0] != '\0')
		{
			MH[dem].TENMH[vitri] = '\0';
			dem++;
			vitri = strlen(MH[dem].TENMH);
			gotoXY(31+vitri, ++y);
		}
	}
STCLT:
	while(1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                           ");
		gotoXY(20,30); printf("SO TIN CHI LY THUYET: GOM CAC KI TU (0-9), TOI DA: 3 KI TU ");
		gotoXY(20,31); printf("                                                           "); TextColor(91);gotoXY(72+vitri,y);
		key = GetKey();
		if(MH[dem].TENMH[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Ten Mon Hoc!",35,27,74,700);
			gotoXY(31,y);
			goto TENMH;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			MH[dem].STCLT[vitri] = char(key);
			MH[dem].STCLT[vitri] = toupper(MH[dem].STCLT[vitri]);
			cout<<MH[dem].STCLT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(72+vitri, y);
			cout<<" ";
			gotoXY(72+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			MH[dem].STCLT[vitri] = '\0';
			vitri = strlen(MH[dem].STCTH);
			gotoXY(80+vitri,y);
			goto STCTH;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				MH[dem].STCLT[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); continue; //Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)		{InsertNode_MH(root,MH[i]);}
					LuuFileMH(root);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)		{InsertNode_MH(root,MH[i]);}
				}
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			MH[dem].STCLT[vitri] = '\0';
			vitri = strlen(MH[dem].TENMH);
			gotoXY(31+vitri, y);
			goto TENMH;
		}
		if(key == RIGHT)
		{
			MH[dem].STCLT[vitri] = '\0';
			vitri = strlen(MH[dem].STCTH);
			gotoXY(80+vitri, y);
			goto STCTH;
		}
		if(key == UP && y > 8)
		{
			MH[dem].STCLT[vitri] = '\0';
			dem--;
			vitri = strlen(MH[dem].STCLT);
			gotoXY(72+vitri, --y);
		}
		if(key == DOWN && y < 22 && MH[1+dem].STCLT[0] != '\0')
		{
			MH[dem].STCLT[vitri] = '\0';
			dem++;
			vitri = strlen(MH[dem].STCLT);
			gotoXY(72+vitri, ++y);
		}
	}
STCTH:
	while(1)
	{
		TextColor(252);				//Chu thich
		gotoXY(20,29); printf("                                                           ");
		gotoXY(20,30); printf("SO TIN CHI THUC HANH: GOM CAC KI TU (0-9), TOI DA: 3 KI TU ");
		gotoXY(20,31); printf("                                                           "); TextColor(91);gotoXY(80+vitri,y);
		key = GetKey();
		if(MH[dem].STCLT[0] == '\0')
		{
			GhiChu("Ban Chua Nhap STCLT!",35,27,74,700);
			gotoXY(72,y);
			goto STCLT;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			MH[dem].STCTH[vitri] = char(key);
			MH[dem].STCTH[vitri] = toupper(MH[dem].STCTH[vitri]);
			cout<<MH[dem].STCTH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(80+vitri, y);
			cout<<" ";
			gotoXY(80+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			GhiChu("Save Thanh Cong!",40,27,74,500);	TextColor(92);
			gotoXY(6,y+1);
			MH[dem].STCTH[vitri] = '\0';
			if(MH[1+dem].MAMH[0] == '\0' && dem == demkhongdoi)	//Ko cho demkhongdoi tang khi sua loi STCTH phia tren
			{
				cout<<++STT; //Cho xuat hien STT
				demkhongdoi++;	// De cuoi cung ESC gan' cho dem, vi dem thuong bi thay doi khi di chuyen
			}
			if((STT-1) % 15 == 0)
			{
				y = 7;
				system("cls");
				Khung_Nhap_MH();	TextColor(92);	gotoXY(6,8); cout << STT;
			}
			TextColor(91);
			dem++;			//dem nay co the thay doi khi di chuyen => can bien demkhongdoi
			vitri = strlen(MH[dem].MAMH);
			gotoXY(10+vitri,++y);
			goto MAMH;
		}
		if(key == ESC)
		{
			if(check_change == true)
			{
				MH[dem].STCTH[vitri] = '\0';
				putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoXY(4,24);  TextColor(252);	printf("ESC"); continue; //Tô màu ESC
				}	
				if(temp == 1)	
				{
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
					LuuFileMH(root);LuuFileDiem(ds,root);
				}
				if(temp == 0)
				{
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)	{InsertNode_MH(root,MH[i]);}//Do? mang? tam. vao BST (bo nho trong)
				}	
			}
			system("cls");	return;
		}
		if(key == LEFT)	
		{
			MH[dem].STCTH[vitri] = '\0';
			vitri = strlen(MH[dem].STCLT);
			gotoXY(72+vitri, y);
			goto STCLT;
		}
		if(key == UP && y > 8)
		{
			MH[dem].STCTH[vitri] = '\0';
			dem--;
			vitri = strlen(MH[dem].STCTH);
			gotoXY(80+vitri, --y);
		}
		if(key == DOWN && y < 22 && MH[1+dem].STCTH[0] != '\0')
		{
			MH[dem].STCTH[vitri] = '\0';
			dem++;
			vitri = strlen(MH[dem].STCTH);
			gotoXY(80+vitri, ++y);
		}		
	}
}
void ThemMonHoc(ListLop ds, ListMonHoc *&root, bool &check_change)
{
	int key, vitri = 0, x = 12, y = 14, check_trung;
	MonHoc mh;	mh.MAMH[0] = NULL;	mh.TENMH[0] = NULL;	mh.STCLT[0] = NULL;	mh.STCTH[0] = NULL;
	Khung_Them_MonHoc(); gotoXY(x,y);
MAMH:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15"); TextColor(12); gotoXY(12+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,mh.MAMH,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == RIGHT)
		{
			mh.MAMH[vitri]= '\0';
			check_trung = KT_Lop_SV_MH(ds,root,mh.MAMH,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == ESC || key == F1){return;}
	}
TENMH:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 35"); TextColor(12); gotoXY(30+vitri,y); //Ghi chú
		key = GetKey();
		if(mh.MAMH[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap MA Mon Hoc!",35,27,74,700);
			gotoXY(12,y);
			goto MAMH;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 35))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout<<mh.TENMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30+vitri, y);
			cout<<" ";
			gotoXY(30+vitri, y);
		}
		if( key == SPACE && mh.TENMH[vitri-1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoxy(30+vitri , y);
			cout<<" ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			if(mh.TENMH[vitri-1] == ' ')	 {vitri--;} //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == LEFT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.MAMH);
			gotoXY(12+vitri, y);
			goto MAMH;
		}
		if(key == RIGHT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == F1){return;}
	}
STCLT:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(12); gotoXY(67+vitri,y); // Ghi chú
		key = GetKey();
		if(mh.TENMH[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!",35,27,74,700);
			gotoXY(30,y);
			goto TENMH;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			mh.STCLT[vitri] = char(key);
			mh.STCLT[vitri] = toupper(mh.STCLT[vitri]);
			cout<<mh.STCLT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67+vitri, y);
			cout<<" ";
			gotoXY(67+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.STCTH);
			gotoXY(75+vitri, y);
			goto STCTH;
		}
		if(key == LEFT)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == RIGHT)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.STCTH);
			gotoXY(75+vitri, y);
			goto STCTH;
		}
		if(key == ESC || key == F1){return;}
	}
STCTH:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(12); gotoXY(75+vitri,y); // Ghi chú
		key = GetKey();
		if(mh.STCLT[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!",35,27,74,700);
			gotoXY(67,y);
			goto STCLT;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			mh.STCTH[vitri] = char(key);
			mh.STCTH[vitri] = toupper(mh.STCTH[vitri]);
			cout<<mh.STCTH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(75+vitri, y);
			cout<<" ";
			gotoXY(75+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			mh.STCTH[vitri] = '\0';
			InsertNode_MH(root,mh);
			return;
		}
		if(key == LEFT)
		{
			mh.STCTH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == F1){return;}
	}
}
void SuaMonHoc(ListLop ds, ListMonHoc *&root, bool &check_change)
{
	int key, x = 35, y = 14, vitri = 0, check_trung;
	Khung_Sua_MonHoc();
	ListMonHoc *temppointer;
	MonHoc mh;	mh.MAMH[0] = NULL;	mh.TENMH[0] = NULL;	mh.STCLT[0] = NULL;	mh.STCTH[0] = NULL;
	Khung_Sua_SV();	gotoXY(x,y);
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';	//Ngat chuoi~
			check_trung = KTMonHoc(root,mh.MAMH); //KT trung`. 1: trung	0: ko trung
			if(check_trung == 1)
			{
				vitri = 0;
				temppointer = FindMaMH(root,mh.MAMH);	break;
			}else{
				GhiChu("Ma Mon Hoc Khong Ton Tai!",35,27,74,500);	TextColor(12);	gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == F2){return;}
	}
	Khung_Them_MonHoc();	x = 12, y = 14;		gotoXY(12,y);
MAMH:
	
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 15"); TextColor(12); gotoXY(12+vitri,y); //Ghi chú
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(12+vitri, y);
			cout<<" ";
			gotoXY(12+vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			mh.MAMH[vitri] = '\0';
			check_trung = KT_Lop_SV_MH(ds,root,mh.MAMH,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == RIGHT)
		{
			mh.MAMH[vitri]= '\0';
			check_trung = KT_Lop_SV_MH(ds,root,mh.MAMH,ds.n);
			if(check_trung == -1)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Lop. Vui Long Nhap Lai!");		Sleep(500);	continue;}
			if(check_trung == -2)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Sinh Vien. Nhap Lai!");			Sleep(500); continue;}
			if(check_trung == -3)	{TextColor(78);	gotoXY(10,15); printf("Trung Ma Mon Hoc. Nhap Lai!");			Sleep(500); continue;}
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == ESC || key == F2){return;}	
	}
TENMH:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (A-Z) & (0-9). Toi da: 35"); TextColor(12); gotoXY(30+vitri,y); //Ghi chú
		key = GetKey();
		if(mh.MAMH[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap MA Mon Hoc!",35,27,74,700);
			gotoXY(12,y);
			goto MAMH;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 35))
		{
			mh.TENMH[vitri] = char(key);
			mh.TENMH[vitri] = toupper(mh.TENMH[vitri]);
			cout<<mh.TENMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30+vitri, y);
			cout<<" ";
			gotoXY(30+vitri, y);
		}
		if( key == SPACE && mh.TENMH[vitri-1] != ' ' && vitri > 0 && vitri < 35) // ko cho 2 khoang trang && vitri = 0
		{	
			gotoxy(30+vitri , y);
			cout<<" ";
			mh.TENMH[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			if(mh.TENMH[vitri-1] == ' ') 	{vitri--;} //KT khi enter truoc do co phai khoang trang
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == LEFT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.MAMH);
			gotoXY(12+vitri, y);
			goto MAMH;
		}
		if(key == RIGHT)
		{
			mh.TENMH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == F2){return;}	
	}
STCLT:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         ");	TextColor(12);	gotoXY(67+vitri,y); //Ghi chú
		key = GetKey();
		if(mh.TENMH[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap TEN Mon Hoc!",35,27,74,700);
			gotoXY(30,y);
			goto TENMH;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			mh.STCLT[vitri] = char(key);
			mh.STCLT[vitri] = toupper(mh.STCLT[vitri]);
			cout<<mh.STCLT[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(67+vitri, y);
			cout<<" ";
			gotoXY(67+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.STCTH);
			gotoXY(75+vitri, y);
			goto STCTH;
		}
		if(key == LEFT)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.TENMH);
			gotoXY(30+vitri, y);
			goto TENMH;
		}
		if(key == RIGHT)
		{
			mh.STCLT[vitri] = '\0';
			vitri = strlen(mh.STCTH);
			gotoXY(75+vitri, y);
			goto STCTH;
		}
		if(key == ESC || key == F2){return;}
	}
STCTH:
	while(1)
	{
		TextColor(106);	gotoXY(10,15); printf("Ki tu: (0-9). Toi da: 3         "); TextColor(12); gotoXY(75+vitri,y);  //Ghi chú
		key = GetKey();
		if(mh.STCLT[0] == '\0' )
		{
			GhiChu("Ban Chua Nhap STCLT Mon Hoc!",35,27,74,700);
			gotoXY(67,y);
			goto STCLT;
		}
		if(( key <= '9' && key >= '0') && (vitri < 3))
		{
			mh.STCTH[vitri] = char(key);
			mh.STCTH[vitri] = toupper(mh.STCTH[vitri]);
			cout<<mh.STCTH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(75+vitri, y);
			cout<<" ";
			gotoXY(75+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			check_change = true;
			mh.STCTH[vitri] = '\0';
			temppointer->mh = mh;	return;  //Cap nhat du lieu moi' vao con tro? dang sua~
		}
		if(key == LEFT)
		{
			mh.STCTH[vitri] = '\0';
			vitri = strlen(mh.STCLT);
			gotoXY(67+vitri, y);
			goto STCLT;
		}
		if(key == ESC || key == F2){return;}
	}
}
void XoaMonHoc(ListLop ds, ListMonHoc *&root, bool &check_change)
{
	int key, x = 35, y = 14, vitri = 0;
	MonHoc mh;	mh.MAMH[0] = NULL;
	Khung_Xoa_MonHoc();	gotoXY(x,y);
Reset:
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35+vitri, y);
			cout<<" ";
			gotoXY(35+vitri, y);
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';	//Ngat chuoi~
			int temp = KTMonHoc(root,mh.MAMH);//KT trung sinh vien trong List
			if(temp != 0)
			{
				for(int i = 0; i < ds.n; i++)
				{
					if(ds.l[i].Head == NULL)	continue;
					for(ListDiem *p = ds.l[i].Head->sv.Head; p != NULL; p = p->Next)
					{
						if(strcmp(mh.MAMH,p->d.MAMH) == 0)
						{
							GhiChu("Mon Hoc da co trong danh sach Diem khong the Xoa!",20,27,74,500); TextColor(12); gotoXY(35+vitri,y); goto Reset;
						}
					}
				}
				check_change = true;
				XoaNodeMonHoc(root,mh.MAMH);  break;
			}else{
				GhiChu("Ma Mon Hoc Khong Ton Tai!",35,27,74,500); TextColor(12); gotoXY(35+vitri,y);
			}
		}
		if(key == ESC || key == F3){return;}
	}
}
void XuatMonHoc(ListLop ds, ListMonHoc *&root, int chedoxem)
{
	int key, STT = 1, trang = 0, tongtrang = 0, soluongmh, dem = 0, demdong = 0; bool check_change = false;
	while(1)
	{
		soluongmh = DemMonHoc(root);
		if(soluongmh == 0)
 		{
 			GhiChu("Chua co du lieu Mon Hoc",35,27,74,500);
		}else{
			if(soluongmh < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongmh-1)/15+1);
			}
		}
	MonHoc MH[soluongmh+1];
	MangTam_MonHoc(root,MH,dem); //Do Cay Nhi Phan ra Mang?
	dem = 0; demdong = 0;
	TextColor(91);	system("cls");	Khung_Xuat_MH(); 
	for( int i = trang*15 ; i < 15 + trang*15 && i < soluongmh ; i++)
	{
		TextColor(92);gotoxy(6, 8+demdong); cout<< ( i+1 );TextColor(91);
		gotoxy(10,8+demdong); cout<<MH[i].MAMH;
		gotoxy(31,8+demdong); cout<<MH[i].TENMH;
		gotoxy(72,8+demdong); cout<<MH[i].STCLT;
		gotoxy(80,8+demdong); cout<<MH[i].STCTH;
		demdong++;
	}
	HienThiTrang(trang+1,tongtrang,73,26);
		if(chedoxem == 1)//Dang o che do xem
		{
			TextColor(94);gotoXY(18,24); printf("                 DANG O CHE DO XEM!        ");
			TextColor(236);gotoXY(33,2); printf(" NHAN ESC DE THOAT CHE DO XEM");
		}	gotoXY(81,26);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == F1 && chedoxem != 1)
		{	
			gotoXY(18,24);  TextColor(251);	printf("F1");	//Tô màu F1
			ThemMonHoc(ds,root,check_change);
		}
		if(key == F2 && chedoxem != 1)
		{
			gotoXY(35,24);  TextColor(251);	printf("F2");	//Tô màu F2
			SuaMonHoc(ds,root,check_change);
		}
		if(key == F3 && chedoxem != 1)
		{
			gotoXY(50,24);  TextColor(251);	printf("F3");	//Tô màu F3
			XoaMonHoc(ds,root,check_change);
		}
		if(key == ESC)
			{
				if(chedoxem == 1){return;};
				if(check_change == true)
				{
					putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
					int temp = ThongBao_ESC();
					if(temp == -1)	{continue;}
					if(temp == 1)	{GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000);LuuFileMH(root);LuuFileDiem(ds,root);}//Cap nhat lai file Diem
					if(temp == 0)	{GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);}								// khi mon hoc bi thay doi
				}
				system("cls");	return;
			}
		if(key == F5 && chedoxem == 1){return;}
	}
}
//====================NHAP-XUAT-HIEU CHINH DIEM====================
int KT_LanThi(ListDiem *Head, char c[])
{
	for(ListDiem *p = Head; p != NULL; p = p->Next)
	{
		if(strcmp(p->d.MAMH, c) == 0)		
		{
			return 1;	//Tra ve 1 la kiem tra trong ListDiem da co' ma mon hoc nay roi
		}
	}
	return 0;	//Tra ve 0 la ma mon hoc nay chua co
}
int NhapMaLop_MaMH(ListLop ds, ListMonHoc *root, int &vitrilop, int &lanthi, MonHoc &mamonhoc)
{
	Khung_Nhap_MaLop_MonHoc();	
	int x = 30, y = 2, key, vitri = 0, temp, vitriMang, temp1;	//temp: KT malop.    	temp1: KT maMH
	MonHoc mh; char LAN[2];	mh.MAMH[0] = NULL; LAN[0] = NULL; gotoXY(x,y);
MALOP:
	while(1)
	{
		TextColor(169);gotoXY(40,4);printf("F5:");
		TextColor(164);gotoXY(43,4);printf("XEM DANH SACH LOP!    "); TextColor(12);gotoXY(30+vitri,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				if(ds.l[vitriMang].Head == NULL)
				{
					GhiChu("      Lop Nay Chua Co Du Lieu Sinh Vien!      ",28,5,159,500);	continue;
				}
				vitri = strlen(mh.MAMH);
				gotoXY(50+vitri,y);
				goto MAMH;
			}else{
				GhiChu("             Ma Lop Khong Ton Tai!            ",28,5,159,500);
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(30+vitri, y);
			cout<<" ";
			gotoXY(30+vitri, y);
		}
		if (key == F5)
		{
			XuatLop(ds,root,1);
			Khung_Nhap_MaLop_MonHoc();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ");
			TextColor(12);	gotoXY(30,y);
			ds.l[ds.n].MALOP[vitri] = '\0';
			cout<<ds.l[ds.n].MALOP;	
		}
		if(key == RIGHT)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;
				}else{
					vitriMang = temp;
				}
				if(ds.l[vitriMang].Head == NULL)
				{
					GhiChu("      Lop Nay Chua Co Du Lieu Sinh Vien!      ",28,5,159,500);	continue;
				}
				vitri = strlen(mh.MAMH);
				gotoXY(50+vitri, y);
				goto MAMH;
			}else{
				GhiChu("             Ma Lop Khong Ton Tai!            ",28,5,159,500);
			}
		}
		if(key == ESC)		{TextColor(91);	return 0;}	//Tra ve 0 khi chua lay duoc 3 du lieu MaMH, LanThi, vitrilop
	}
MAMH:
	while(1)
	{
		TextColor(169);gotoXY(40,4);printf("F5:");
		TextColor(164);gotoXY(43,4);printf("XEM DANH SACH MON HOC!");	TextColor(12);gotoXY(50+vitri,y);
		key = GetKey();
		if(ds.l[ds.n].MALOP[0] == '\0' )
		{
			GhiChu("   Ban Chua Nhap Ma Lop. Vui Long Nhap Lai!   ",28,5,159,500);
			gotoXY(30,y);
			goto MALOP;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			mh.MAMH[vitri] = char(key);
			mh.MAMH[vitri] = toupper(mh.MAMH[vitri]);
			cout<<mh.MAMH[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			mh.MAMH[vitri] = '\0';
			temp1 = KTMonHoc(root,mh.MAMH);//KT trung mon hoc trong List
			if(temp1 == 1)
			{
				vitri = strlen(LAN);
				gotoXY(71+vitri,y);
				goto LAN;
			}else{
				GhiChu("          Ma Mon Hoc Khong Ton Tai!           ",28,5,159,500);
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(50+vitri, y);
			cout<<" ";
			gotoXY(50+vitri, y);
		}
		if(key == F5)
		{
			mh.MAMH[vitri] = '\0';
			XuatMonHoc(ds,root,1);
			Khung_Nhap_MaLop_MonHoc();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ");
			TextColor(12);
			gotoXY(30,2);cout<<ds.l[ds.n].MALOP;
			gotoXY(50,y);cout<<mh.MAMH;
		}
		if(key == LEFT)
		{
			mh.MAMH[vitri] = '\0';
			vitri = strlen(ds.l[ds.n].MALOP);
			gotoXY(30+vitri, y);
			goto MALOP;
		}
		if(key == RIGHT)
		{
			mh.MAMH[vitri] = '\0';
			temp1 = KTMonHoc(root,mh.MAMH);//KT trung mon hoc trong List
			if(temp1 == 1)
			{
				vitri = strlen(LAN);
				gotoXY(71+vitri,y);
				goto LAN;
			}else{
				GhiChu("          Ma Mon Hoc Khong Ton Tai!           ",28,5,159,500);
			}
		}
		if(key == ESC)		{TextColor(91);	return 0;}	//Tra ve 0 khi chua lay duoc 3 du lieu MaMH, LanThi, vitrilop
	}
LAN:
	while(1)
	{
		TextColor(164);gotoXY(40,4);printf("Chi nhap: LAN 1 or LAN 2!");  TextColor(12);gotoXY(71+vitri,y);
		key = GetKey();
		if(mh.MAMH[0] == '\0' )
		{
			GhiChu(" Ban Chua Nhap Ma Mon Hoc. Vui Long Nhap Lai! ",28,5,159,500);
			gotoXY(50,y);
			goto MAMH;
		}
		if((key == '1' || key == '2') && (vitri < 1))
		{
			LAN[vitri] = char(key);
			cout<<LAN[vitri];
			vitri++;
		}
		if(key == ENTER && vitri!=0)
		{
			LAN[vitri] = '\0';
			int err = KT_LanThi(ds.l[vitriMang].Head->sv.Head, mh.MAMH);
			if(err == 0 && atoi(LAN) == 2) //Neu khong tim thay ma mon hoc nay trong listdiem va nhap vao lan 2 => nhap lai
			{
				GhiChu("   Mon Hoc nay ban chua nhap diem LAN 1 !!!   ",28,5,159,500); 	continue;
			}
			lanthi = atoi(LAN);
			vitrilop = vitriMang;
			strcpy(mamonhoc.MAMH,mh.MAMH);
			TextColor(91);	system("cls");	return 1;	//Tra ve 1 neu da lay duoc ra 3 du lieu: vitrilop , lanthi, mamonhoc
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(71+vitri, y);
			cout<<" ";
			gotoXY(71+vitri, y);
		}
		if(key == LEFT)
		{
			LAN[vitri] = '\0';
			vitri = strlen(mh.MAMH);
			gotoXY(50+vitri, y);
			goto MAMH;
		}
		if(key == ESC)	{TextColor(91);	return 0;}	//Tra ve 0 khi chua lay duoc 3 du lieu MaMH, LanThi, vitrilop
	}
}
ListDiem* KT_trung_LanThi_MaMH(ListDiem *Head, Diem d)
{
	for(ListDiem *p = Head; p != NULL; p = p->Next)
	{
		if((strcmp(p->d.MAMH, d.MAMH) == 0) && (p->d.LAN == d.LAN))
		{
			return p;
		}
	}
	return NULL;
}
int KT_NhapDiem_Lan1(int dem, ListSV *Head, char c[])
{
	int count = 0;
	for(ListSV *p = Head; p != NULL; p = p->Next)
	{
		if(dem == count) //di den duoc sinh vien dang tim`
		{
			if(p->sv.Head == NULL){return 0;}	//Truong Hop Svien duoc them sau
			for(ListDiem *q = p->sv.Head; q != NULL; q = q->Next)
			{
				if(strcmp(q->d.MAMH, c) == 0 && q->d.LAN == 1) 
				{	
					if(q->d.DIEM[0] == NULL)
					{
						strcpy(q->d.DIEM,"0"); q->d.DIEM[1] = '\0';	//User dang nhap diem Lan 2 cho Svien neu Lan 1 chua nhap diem cho 0d Lan 1 luon
					}
					if(atof(q->d.DIEM) < 5)
					{
						return 1;	//Diem Lan 1    be hon 5d cho cai? thien diem
					}else{
						return 0;	
					}
				}
			}
		}
		count++;
	}
}
void Nhap_Xuat_Diem(ListLop &dsLOP, ListMonHoc *&root, int chedo)//Neu chedo = 1: Nhap Diem		//chedo = 0 : Xuat Diem
{
	int key, ViTriLop, LanThi, x = 69, y = 8, ktra_thoat, kt_trung;
	int trang = 0, tongtrang = 0, soluongsv = 0, dem1 = 0, dem = 0, vitri = 0, dem2 = 0; //dem1: dem sluong sv
	MonHoc mh;  mh.MAMH[0] = NULL; 	dsLOP.l[dsLOP.n].MALOP[0] = NULL; //Khoi tao rong~     //dem: dêm' dòng 	dem2: dem diem?
	ktra_thoat = NhapMaLop_MaMH(dsLOP,root,ViTriLop,LanThi,mh);
	if(ktra_thoat == 0){return;}	// Neu khong nhan dx 3 gia tri thi out ra luon.
	// Nhap Du Lieu vao va tham chieu ra 3 gia tri MaMH, LanThi, vitriLop trong mang			
	TextColor(91);
	soluongsv = DemSinhVien(dsLOP.l[ViTriLop].Head);
			if(soluongsv == 0)
 			{
 				GhiChu("Chua co du lieu sinh vien",35,27,74,500);
			}else{
				if(soluongsv < 15)
				{
					tongtrang = 1;
					trang = 0;	
				}else{
					tongtrang = ((soluongsv-1)/15+1);
				}
			}
			
		Diem diem[soluongsv+1];		//Khoi tao mang tam 
		for(int i = 0; i < soluongsv+1; i++)	{diem[i].DIEM[0] = NULL; diem[i].LAN = LanThi; strcpy(diem[i].MAMH,mh.MAMH);}	//Khoi tao rong~
		SapXepSV(dsLOP.l[ViTriLop].Head); 	//Sap Xep danh sach theo Ten Ho
		SinhVien sv[soluongsv+1];
		int j = 0;
		for(ListSV *p = dsLOP.l[ViTriLop].Head; p != NULL; p = p->Next) 
		{
			sv[dem1] = p->sv; dem1++;
			for(ListDiem *q = p->sv.Head; q != NULL; q = q->Next)
			{
				if(q->d.LAN == LanThi && strcmp(q->d.MAMH, mh.MAMH) == 0)
				{
					diem[j] = q->d;
				}	
			} j++;
		}
		
Reset:	TextColor(91);
		system("cls");
		if(chedo == 1){Khung_Nhap_Diem();}else{Khung_Xuat_Diem();}
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongsv ; i++)
			{
				TextColor(92);gotoxy(6, 8+dem); cout<< ( i+1 );TextColor(91);
				gotoxy(10,8+dem); cout<<sv[i].MASV;
				gotoxy(26,8+dem); cout<<sv[i].HO;
				gotoxy(47,8+dem); cout<<sv[i].TEN;
				gotoxy(58,8+dem); cout<<sv[i].PHAI;
				gotoXY(69,8+dem); cout<<diem[i].DIEM;
				dem++;
			}
		HienThiTrang(trang+1,tongtrang,61,26);
		TextColor(206);	gotoXY(1,0);printf("MA LOP:");gotoXY(1,2);printf("MA MON HOC:");gotoXY(1,4);printf("LAN THI:");
		TextColor(80);	gotoXY(10,0);cout<<dsLOP.l[ViTriLop].MALOP;		gotoXY(13,2);cout<<mh.MAMH;		gotoXY(10,4);cout<<LanThi;	TextColor(91);
		vitri = strlen(diem[dem2].DIEM);
		gotoXY(x+vitri,y);
while(1)
	{	
		TextColor(252);				//Chu thich
		gotoXY(15,29); printf("                                                 ");
		gotoXY(15,30); printf("     DIEM SINH VIEN: Nhap tu 0.00 den 10.00.     ");
		gotoXY(15,31); printf("                                                 "); TextColor(91);gotoXY(69+vitri,y);
		key = GetKey();
		if( ((key <= '9' && key >= '0') || key == '.') && (vitri < 3))
		{
			kt_trung = KT_NhapDiem_Lan1(dem2,dsLOP.l[ViTriLop].Head,mh.MAMH);
			if(kt_trung == 0 && LanThi == 2)
			{
				GhiChu("Diem Lan 1 lon hon 5d khong the nhap Diem Lan 2!",20,27,74,500);  continue;	
			}
			diem[dem2].DIEM[vitri] = char(key);
			diem[dem2].DIEM[vitri] = toupper(diem[dem2].DIEM[vitri]);
			cout<<diem[dem2].DIEM[vitri];
			vitri++;
		}
		if(key == ENTER && dem2 < dem1)
		{
			diem[dem2].DIEM[vitri] = '\0';
			if(atoi(diem[dem2].DIEM) > 10 || diem[dem2].DIEM[0] == '.' || diem[dem2].DIEM[2] == '.' )
			{
				GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""",20,27,74,500);	continue;
			}
			if(vitri > 0){GhiChu("Save Thanh Cong!",35,27,74,300); TextColor(91);}
			dem2++;
			vitri = strlen(diem[dem2].DIEM);
			if(dem2 % 15 == 0)
			{
				trang++;
				y = 8;
				goto Reset;
			}
			gotoXY(x+vitri, ++y);
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(69+vitri, y);
			cout<<" ";
			gotoXY(69+vitri, y);
		}
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			diem[dem2].DIEM[vitri] = '\0';
			if(atoi(diem[dem2].DIEM) > 10 || diem[dem2].DIEM[0] == '.' || diem[dem2].DIEM[2] == '.' )
			{
				GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""",20,27,74,500);	continue;
			}
			trang++;
			dem2 += 15;
			if(dem2 > soluongsv) //Neu lat qua trang va vuot qua so luong sinh vien
			{
				dem2 = soluongsv-1;
				y = dem2%15 + 8;
			}
			vitri = strlen(diem[dem2].DIEM);
			goto Reset;
		}
		if((key == LEFT) && trang > 0)
		{
			diem[dem2].DIEM[vitri] = '\0';
			if(atoi(diem[dem2].DIEM) > 10 || diem[dem2].DIEM[0] == '.' || diem[dem2].DIEM[2] == '.' )
			{
				GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""",20,27,74,500);	continue;
			}
			trang--;
			dem2 -= 15;
			vitri = strlen(diem[dem2].DIEM);
			goto Reset;
		}
		if(key == UP && y > 8)
		{
			diem[dem2].DIEM[vitri] = '\0';
			if(atoi(diem[dem2].DIEM) > 10 || diem[dem2].DIEM[0] == '.' || diem[dem2].DIEM[2] == '.' )
			{
				GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""",20,27,74,500);	continue;
			}
			dem2--;
			vitri = strlen(diem[dem2].DIEM);
			gotoXY(x+vitri,--y);
		}
		if(key == DOWN && y < 22 && dem2 < dem1-1)
		{
			diem[dem2].DIEM[vitri] = '\0';
			if(atoi(diem[dem2].DIEM) > 10 || diem[dem2].DIEM[0] == '.' || diem[dem2].DIEM[2] == '.' )
			{
				GhiChu("DIEM >= 0   &&   DIEM <= 10 && Khong "".5."" or ""5..""",20,27,74,500);	continue;
			}
			dem2++;
			vitri = strlen(diem[dem2].DIEM);
			gotoXY(x+vitri,++y);
		}
		if(key == ESC)
		{
			diem[dem2].DIEM[vitri] = '\0';
			putchar(7);	gotoXY(4,24);  TextColor(251);	printf("ESC"); //Tô màu ESC
			int i = 0;
			ListDiem *temp;	//Mot con tro tam. luu tru dia chi bi trung` MaMH && LanThi trong 1 ListDiem
			int err = ThongBao_ESC();
			if(err == -1)	//TH bat duoc them 1 phim' ESC
			{
				gotoXY(4,24);  TextColor(252);	printf("ESC"); TextColor(91); //Tô màu ESC
				goto Reset;
			}
			if(err == 1)
			{
				for(ListSV *p = dsLOP.l[ViTriLop].Head ; p != NULL; p = p->Next)
				{			
					temp = KT_trung_LanThi_MaMH( p->sv.Head , diem[i]);
					if(temp != NULL) //Kiem tra xem co trung` MAMH, LAN trong listdiem ko
					{
						strcpy(temp->d.DIEM, diem[i++].DIEM);	//Neu trung` MAMH, Lanthi, thi cap nhat diem sô' moi' vao`
						continue;
					}
					InsertTail_Diem(p->sv.Head,diem[i++]);	//Neu khong trung` them vao DSLK Don 1 Node moi'
				}
				GhiChu("Luu Vao File Thanh Cong!",30,27,74,2000); 
				LuuFileDiem(dsLOP,root); LuuFileSV(dsLOP);
				system("cls");	return;
			}
			if(err == 0)
			{
				for(ListSV *p = dsLOP.l[ViTriLop].Head ; p != NULL; p = p->Next)
				{			
					temp = KT_trung_LanThi_MaMH( p->sv.Head , diem[i]);
					if(temp != NULL) //Kiem tra xem co trung` MAMH, LAN trong listdiem ko
					{
						strcpy(temp->d.DIEM, diem[i++].DIEM);	//Neu trung` MAMH, Lan, thi cap nhat diem sô' moi' vao`
						continue;
					}
					InsertTail_Diem(p->sv.Head,diem[i++]);	//Neu khong trung` them vao DSLK Don 1 Node moi'
				}
				GhiChu("Luu Vao File Khong Thanh Cong!",25,27,74,2000); 
				system("cls");	return;
			}
		}
	}
}
float Tinh_Diem_TB(SinhVien sv, ListMonHoc *root)
{
	ListMonHoc *MH;
	float ketqua = 0;	int tongtinchi = 0;
	for(ListDiem *p = sv.Head; p != NULL; p = p->Next)
	{	
		MH = FindMaMH(root,p->d.MAMH);
		if(MH == NULL || p->d.DIEM[0] == NULL){continue;} // Kiem tra MH da bi xoa' or svien nay chua nhap diem thi bo? qua 1 buoc'
		if(p->d.LAN == 1)
			{
				int flag = 0;
				for(ListDiem *q = p->Next; q != NULL; q = q->Next)
				{
					if(strcmp(p->d.MAMH, q->d.MAMH) == 0)
					{
						if(atof(p->d.DIEM) > atof(q->d.DIEM))
						{
							ketqua += (atof(p->d.DIEM) * ( atoi(MH->mh.STCLT) + atoi(MH->mh.STCTH) )  ) ;
						}else{
							ketqua += (atof(q->d.DIEM) * ( atoi(MH->mh.STCLT) + atoi(MH->mh.STCTH) )  ) ;
						}
						tongtinchi += ( atoi(MH->mh.STCLT) + atoi(MH->mh.STCTH) );
						flag = 1;
					}	
				}
				if(flag == 0)
				{
					ketqua += (atof(p->d.DIEM) * ( atoi(MH->mh.STCLT) + atoi(MH->mh.STCTH) )  ) ;
					tongtinchi += ( atoi(MH->mh.STCLT) + atoi(MH->mh.STCTH) );	
				}
			}
	}
	if(tongtinchi == 0){return 0;}
	ketqua = ketqua/tongtinchi;
	return ketqua;
}
void Xuat_Diem_TrungBinh(ListLop ds, ListMonHoc *root)
{
	int key, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1, soluongsv = 0, trang = 0, tongtrang = 0, dem1 = 0, dem = 0;//vitriMang : vitri cua lop
	Khung_Nhap_MaLop();	gotoXY(x,y);	ds.l[ds.n].MALOP[0] = NULL;	//Khoi tao rong~
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;	
				}else{
					vitriMang = temp;
				}
				if(ds.l[vitriMang].Head == NULL)
				{
					GhiChu("  Chua co du lieu Sinh Vien!  ",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);
					continue;
				}else{
					if(ds.l[vitriMang].Head->sv.Head == NULL)
					{
						GhiChu("Sinh Vien Lop Nay chua co Diem!",33,5,159,500); gotoXY(40+vitri,y);	TextColor(12);
						continue;
					}
				}
				TextColor(91);	system("cls");	break;
			}else{
				GhiChu("     Ma Lop Khong Ton Tai!    ",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);
				continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40+vitri, y);
			cout<<" ";
			gotoXY(40+vitri, y);
		}
		if (key == F5)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			XuatLop(ds,root,1);
			Khung_Nhap_MaLop();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        ");
			TextColor(12);
			gotoXY(40,y);cout<<ds.l[ds.n].MALOP;
		}
		if(key == ESC)	{TextColor(91);	return;	}
	}	
	soluongsv = DemSinhVien(ds.l[vitriMang].Head);
	if(soluongsv == 0)
 		{
 			GhiChu("Chua co du lieu sinh vien",35,27,74,500);
		}else{
			if(soluongsv < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongsv-1)/15+1);
			}
		}		
		SapXepSV(ds.l[vitriMang].Head); 	//Sap Xep danh sach theo Ten Ho
		SinhVien sv[soluongsv+1]; 
		float DiemTB[soluongsv+1];
		for(int i = 0; i <= soluongsv; i++)
		{DiemTB[i] = 0; sv[i].MASV[0] = NULL;	sv[i].HO[0] = NULL;	 sv[i].TEN[0] = NULL;  sv[i].PHAI[0] = NULL;  sv[i].SODT[0] = NULL;} //Khoi tao mang tam. rong~
		for(ListSV *p = ds.l[vitriMang].Head; p != NULL; p = p->Next) //Do? DS Sinh Vien ra mang? tam. va Tinh diem TB do? ra mang? tam.
		{
			sv[dem1] = p->sv; 
			DiemTB[dem1] = Tinh_Diem_TB(p->sv, root);	
			dem1++;
		}
while(1)
		{
		TextColor(91);	system("cls");	Khung_Xuat_Diem_TB();
		TextColor(206);	gotoXY(1,0);printf("NIEN KHOA:");gotoXY(1,2);printf("MA lOP:");gotoXY(1,4);printf("TEN LOP:");	
		TextColor(80);	gotoXY(12,0);cout<<ds.l[vitriMang].NienKhoa;gotoXY(12,2);cout<<ds.l[vitriMang].MALOP;gotoXY(12,4);cout<<ds.l[vitriMang].TENLOP;	
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongsv ; i++)
		{
			TextColor(92);gotoxy(6, 8+dem); cout<< ( i+1 );TextColor(91);
			gotoxy(10,8+dem); cout<<sv[i].MASV;
			gotoxy(26,8+dem); cout<<sv[i].HO;
			gotoxy(47,8+dem); cout<<sv[i].TEN;
			gotoxy(58,8+dem); cout<<sv[i].PHAI;
			if(DiemTB[i] == 0)
			{
				gotoxy(70,8+dem); printf("None");
			}else{
				gotoxy(70,8+dem); printf("%.2f", DiemTB[i]);	//Lay 2 so thap phan 2 chu so
			}
			dem++;
		}
		HienThiTrang(trang+1,tongtrang,61,26);	gotoXY(69,26);
		key = GetKey();
		if((key == RIGHT || key == DOWN) && trang < tongtrang - 1)		{trang++;}
		if((key == LEFT || key == UP) && trang > 0)						{trang--;}
		if(key == ESC)
		{
			putchar(7);
			int temp = ThongBao_Thoat();
			if(temp == 1){TextColor(91); system("cls"); return;}
		}
	}
}
int SoLuong_MonHoc(ListSV *Head, ListMonHoc *root)
{
	int count = 0;
	for(ListDiem *p = Head->sv.Head; p != NULL; p = p->Next)
	{
		if(FindMaMH(root,p->d.MAMH) == NULL){continue;}
		if(p->d.LAN == 1){count++;}
	}
	return count;
}
void Xuat_Diem_TongKet(ListLop ds, ListMonHoc *root)
{
	int key, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1, soluongsv = 0;	//vitriMang : vitri cua lop
	int trang = 0, tongtrang = 0, dem1 = 0, dem = 0, trangMH = 0, tempvitri = 0, tongtrangmh = 0;
	Khung_Nhap_MaLop();		gotoXY(x,y);	ds.l[ds.n].MALOP[0] = NULL;	//Khoi tao rong~	
	while(1)
	{
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 15))
		{
			ds.l[ds.n].MALOP[vitri] = char(key);
			ds.l[ds.n].MALOP[vitri] = toupper( ds.l[ds.n].MALOP[vitri]);
			cout<<ds.l[ds.n].MALOP[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			temp = KTMaLop(ds, ds.l[ds.n].MALOP, ds.n);
			if( temp != 0)
			{
				if(temp == -1)
				{
					vitriMang = 0;	
				}else{
					vitriMang = temp;
				}
				if(ds.l[vitriMang].Head == NULL)
				{
					GhiChu("  Chua co du lieu Sinh Vien!  ",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);
					continue;
				}else{
					if(ds.l[vitriMang].Head->sv.Head == NULL)
					{
						GhiChu("Sinh Vien Lop Nay chua co Diem!",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);
						continue;
					}
				}
				TextColor(91);	system("cls");	break;
			}else{
				GhiChu("     Ma Lop Khong Ton Tai!    ",33,5,159,500);	gotoXY(40+vitri,y);	TextColor(12);
				continue;
			}
		}
		if( key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40+vitri, y);
			cout<<" ";
			gotoXY(40+vitri, y);
		}
		if (key == F5)
		{
			ds.l[ds.n].MALOP[vitri] = '\0';
			XuatLop(ds,root,1);
			Khung_Nhap_MaLop();
			TextColor(94);gotoXY(18,24); printf("           NHAN F5 DE BAT CHUC NANG DI CHUYEN        "); TextColor(12);
			gotoXY(40,y);cout<<ds.l[ds.n].MALOP;
		}
		if(key == ESC)	{TextColor(91);	return;	}
	}
		soluongsv = DemSinhVien(ds.l[vitriMang].Head);
		SapXepSV(ds.l[vitriMang].Head); 	//Sap Xep danh sach theo Ten Ho
		SinhVien sv[maxsv];
		int soluongmh = SoLuong_MonHoc(ds.l[vitriMang].Head,root);
		MonHoc MAMH[soluongmh];
		for(int i = 0; i <= soluongsv; i++)
		{sv[i].MASV[0] = NULL;	sv[i].HO[0] = NULL;	 sv[i].TEN[0] = NULL;  sv[i].PHAI[0] = NULL;  sv[i].SODT[0] = NULL;} //Khoi tao mang tam. rong~
		for(ListSV *k = ds.l[vitriMang].Head; k != NULL; k = k->Next) //Do? DSLK Sinh Vien ra mang? tam.
		{
			sv[dem1++] = k->sv;
		}
		float MaxDiem[soluongsv+1][soluongmh];
		for(int i = 0; i < soluongsv+1; i++)	// Khoi tao mang cho = -1 de cho luc dau thanh None het
		{
			for(int j = 0; j < soluongmh; j++)	{MaxDiem[i][j] = -1;}
		}
		ListMonHoc *temppointer;		//KT Ma Mon Hoc con` ton tai hay ko. TH user xoa mon hoc giua~ chung`
		for(int i = 0; i < soluongsv; i++)
		{
			int j = 0;
			for(ListDiem *p = sv[i].Head; p != NULL; p = p->Next)
			{	
				int flag = 0;	
				if(p->d.LAN == 1)
				{
					temppointer = FindMaMH(root, p->d.MAMH);
					if(temppointer == NULL){continue;}			
					strcpy(MAMH[j].TENMH, temppointer->mh.TENMH);
					strcpy(MAMH[j].MAMH, p->d.MAMH);
					for(ListDiem *q = p->Next; q != NULL; q = q->Next)
					{
						if(strcmp(p->d.MAMH, q->d.MAMH) == 0 && q->d.DIEM[0] != NULL)
						{
							if(atof(p->d.DIEM) > atof(q->d.DIEM))
							{
								MaxDiem[i][j] = atof(p->d.DIEM); j++;
							}else{
								MaxDiem[i][j] = atof(q->d.DIEM); j++;
							}
							flag = 1; //Danh dau' da~ vao dieu kien nay`
						}
					}
					if(flag == 0)
					{
						if(p->d.DIEM[0] == NULL)
						{
							MaxDiem[i][j] = -1; j++;
						}else{
							MaxDiem[i][j] = atof(p->d.DIEM); j++;	
						}
					}
				}
			}
		}
	if(soluongsv == 0)
 		{
 			GhiChu("Chua co du lieu sinh vien",35,27,74,500);
		}else{
			if(soluongsv < 15)
			{
				tongtrang = 1;
				trang = 0;	
			}else{
				tongtrang = ((soluongsv-1)/15+1);
			}
		}		
	if(soluongmh < 3)
	{
		tongtrangmh = 1;
	}else{
		tongtrangmh = ((soluongmh-1)/3+1);
	}
while(1)
	{
		TextColor(91);	system("cls");	Khung_Tong_Ket();
		TextColor(206);
		gotoXY(1,0);printf("NIEN KHOA:");gotoXY(1,2);printf("MA lOP:");gotoXY(1,4);printf("TEN LOP:");gotoXY(85,4);printf("So luong MH:");
		TextColor(80);
		gotoXY(12,0);cout<<ds.l[vitriMang].NienKhoa;
		gotoXY(12,2);cout<<ds.l[vitriMang].MALOP;
		gotoXY(12,4);cout<<ds.l[vitriMang].TENLOP;
		gotoXY(98,4);cout<<soluongmh;
		dem = 0;
		for( int i = trang*15 ; i < 15 + trang*15 && i < soluongsv ; i++)
		{
			TextColor(92);gotoxy(6, 8+dem); cout<< ( i+1 );TextColor(91);
			gotoxy(10,8+dem); cout<<sv[i].MASV;
			gotoxy(26,8+dem); cout<<sv[i].HO;
			gotoxy(47,8+dem); cout<<sv[i].TEN;
			tempvitri = 0;
			for(int j = 0 + trangMH*3 ; j < 3 + trangMH*3 && j < soluongmh ; j++)
			{
				TextColor(92); gotoxy(61 + tempvitri*14, 6); cout<<MAMH[j].MAMH; gotoXY(5,28+tempvitri*2); cout<<MAMH[j].MAMH;
				TextColor(90); cout<<": "<<MAMH[j].TENMH;	TextColor(91);
				if(MaxDiem[i][j] == -1)
				{
					gotoxy(63 + tempvitri*14, 8+dem); tempvitri++;
					cout<<"None";
				}else{
					gotoxy(63 + tempvitri*14, 8+dem); tempvitri++;
					cout<<MaxDiem[i][j];
				}
			}
			dem++;
		}
		HienThiTrang(trang+1,tongtrang,85,26);
		gotoXY(93,26);
		key = GetKey();
		if(key == DOWN && trang < tongtrang - 1)		{trang++;}
		if(key == UP && trang > 0)						{trang--;}
		if(key == LEFT && trangMH > 0)					{trangMH--;}
		if(key == RIGHT && trangMH < tongtrangmh - 1)	{trangMH++;}
		if(key == ESC)
		{
			putchar(7);
			int temp = ThongBao_Thoat();
			if(temp == 1){TextColor(91); system("cls"); return;}
		}
	}
}
void GiaiPhong_MH(ListMonHoc *&root)
{
	if(root != NULL)
	{
		GiaiPhong_MH(root->left);
		GiaiPhong_MH(root->right);
		delete root;
		root = NULL;
	}
}
void GiaiPhong(ListLop &dsLOP, ListMonHoc *&root)
{
	for(int i = 0 ; i < dsLOP.n; i++)
	{
		for(ListSV *p = dsLOP.l[i].Head; p != NULL; p = p->Next) //Giai phong bo nho Link List
		{
			for(ListDiem *q = p->sv.Head; q != NULL; q = q->Next)
			{
				delete q;
			}
			delete p; 
		}
	}
	GiaiPhong_MH(root); //Giai phong bo nho Cay Nhi Phan
}
void MenuOngNoi(ListLop &dsLOP, ListMonHoc *&root)
{
	int chonMenuCon;
	while ( 1 )
	{
		system("cls");
		for(int i = 0; i < 5; i++)
		{
			if(i == 0)	{TextColor(236);}				else{TextColor(188);}
			gotoxy(0,5+i*4); cout<<"                        ";
			gotoxy(0,6+i*4); cout<<MENU[i];
			gotoxy(0,7+i*4); cout<<"                        ";
		}
		gotoXY(24,7);
		int chon = MenuCha();
		switch(chon)
		{
		case 1:
			{
				for(int i = 0; i < 3; i++)
				{
					if(i == 0)	{TextColor(236);}		else{TextColor(252);}
					gotoxy(28, 5 + (i + 1 ) *4);	cout<<"                        ";
					gotoxy(28, 6 + (i + 1 ) *4);	cout<<MENUlop[i] ;
					gotoxy(28, 7 + (i + 1 ) *4);	cout<<"                        ";
				}
				chonMenuCon = MenuCon(3, MENUlop);
				TextColor(91);
				system("cls");
				switch ( chonMenuCon )
				{
					case 1:		{	NhapLop(dsLOP,root);	break;			}
					case 2:		{	XuatLop(dsLOP,root,0);break;			}
					case 3:		{	XuatLop_NienKhoa(dsLOP,root);break;		}
				}break;
			}
		case 2:
			{
				for(int i = 0; i < 3; i++)
				{
					if(i == 0)	{TextColor(236);}		else{TextColor(252);}
					gotoxy(28, 5 + (i + 1 ) *4);	cout<<"                        ";
					gotoxy(28, 6 + (i + 1 ) *4);	cout<<MENUsv[i] ;
					gotoxy(28, 7 + (i + 1 ) *4);	cout<<"                        ";
				}
				chonMenuCon = MenuCon(3, MENUsv);
				TextColor(91);
				system("cls");
				switch ( chonMenuCon )
				{
					case 1:		{	NhapSinhVien(dsLOP,root);break;			}
					case 2:		{	XuatSinhVien(dsLOP,root);break;			}
					case 3:		{	TimKiem_or_Xoa_1_SV(dsLOP,root);break;	}
				}break;
			}
		case 3:
			{
				for(int i = 0; i < 2; i++)
				{
					if(i == 0)	{TextColor(236);}		else{TextColor(252);}
					gotoxy(28, 5 + (i + 1 ) *4);	cout<<"                        ";
					gotoxy(28, 6 + (i + 1 ) *4);	cout<<MENUmonhoc[i] ;
					gotoxy(28, 7 + (i + 1 ) *4);	cout<<"                        ";
				}
				chonMenuCon = MenuCon( 2,MENUmonhoc);
				TextColor(91);
				system("cls");
				switch ( chonMenuCon )
				{
					case 1:		{	NhapMonHoc(dsLOP,root);break;			}
					case 2:		{	XuatMonHoc(dsLOP,root,0);break;			}
				}break;
			}
		case 4:
			{
				for(int i = 0; i < 4; i++)
				{
					if(i == 0)	{TextColor(236);}		else{TextColor(252);}
					gotoxy(28, 5 + (i + 1 ) *4);	cout<<"                        ";
					gotoxy(28, 6 + (i + 1 ) *4);	cout<<MENUdiem[i] ;
					gotoxy(28, 7 + (i + 1 ) *4);	cout<<"                        ";
				}
				chonMenuCon = MenuCon(4,MENUdiem);
				TextColor(91);
				system("cls");
				switch ( chonMenuCon )
				{
					case 1:		{	Nhap_Xuat_Diem(dsLOP,root,1);break;		}
					case 2:		{	Nhap_Xuat_Diem(dsLOP,root,0);break;		}
					case 3:		{	Xuat_Diem_TrungBinh(dsLOP,root);break;	}
					case 4:		{	Xuat_Diem_TongKet(dsLOP, root);	break;	}
				}break;
			}
		case 5:
			{
				putchar(7);
				int temp = ThongBao_Thoat();
				if(temp == 1){	GiaiPhong(dsLOP,root); TextColor(91); system("cls");exit(0); }
				TextColor(91);	break;
			}
		}
	}
}
int main()
{
	SetBGColor(5);
	ListLop dsLOP;	dsLOP.n = 0;
	ListMonHoc *root = NULL;
	//Nap du~ lieu
	DocFileLop(dsLOP);	
	DocFileSV(dsLOP); 
	DocFileMH(root);
	DocFileDiem(dsLOP,root);
	//Menu
	MenuOngNoi(dsLOP,root);	
}

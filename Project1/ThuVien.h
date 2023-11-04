
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


const int MAX = 50;
using namespace std;
struct ThanhVien
{
	int id;
	char hoTen[30];
	int namSinh;
	char queQuan[30];
	bool gioiTinh;
};
struct DSThanhVien {
	int n = 0;
	ThanhVien ds[MAX];
};
struct HoKhau
{
	int maHoKhau;
	char tenChuHo[20];
	char diaChi[20];
	DSThanhVien dsThanhVien;
	
};
struct DSHoKhau {
	int n=0;
	HoKhau ds[MAX];
};
struct Phuong
{
	char tenPhuong[20];
	DSHoKhau dsHoKhau;
};

void nhapThanhVien(ThanhVien& thanhvien);
void xuatThanhVien(ThanhVien thanhvien);

void nhapDSThanhVien(DSThanhVien& dsThanhVien);
void nhapHoKhau(HoKhau& hoKhau);
void xuatHoKhau(HoKhau hoKhau);

void nhapDSHoKhau(DSHoKhau& dsHoKhau);
void xuatDSHoKhau(DSHoKhau dsHoKhau);

void nhapPhuong(Phuong& phuong);
void xuatPhuong(Phuong phuong);
void nhapTTPhuong(Phuong& phuong);
void xuatTTPhuong(Phuong phuong);

int timThanhVien_chiSo(HoKhau& hoKhau);
int timHoKhau_chiSo(DSHoKhau& dsHoKhau);

void themThanhVien(DSHoKhau& dsHoKhau, int chiSoHoKha);
void themHoKhauMoi(DSHoKhau& dsHoKhau);

void xoaThanhVien(DSHoKhau& dsHoKhau, int chiSoHoKhau, int chiSoThanhVien);
void xoaHoKhau(DSHoKhau& dsHoKhau, int chiSoHoKhau);


// validate 

bool ktTenChuHoTrung(HoKhau hoKhau, char chuoi[20]);


//tool
void dongGachNgang();
void dongTieuDe();

void docPhuongTuFile(const char* tenFile, Phuong& phuong);
void docHoKhauTuFile(istream& file, HoKhau& hoKhau);
void docDSThanhVienTuFile(istream& file, DSThanhVien& dsThanhVien);

void ghiPhuongVaoFile(const char* File, const Phuong& phuong);
void ghiHoKhauVaoFile(ostream& file, const HoKhau& hoKhau);
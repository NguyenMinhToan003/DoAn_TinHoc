#pragma once
#pragma once
#include <iostream>

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

struct HoKhau
{
	char info[20];
	int n=0;
	ThanhVien ds[MAX];
};
struct DSHoKhau {
	int n=0;
	HoKhau ds[MAX];
};
struct Phuong
{
	char info[20];
	DSHoKhau dsHoKhau;
};
void nhapThanhVien(ThanhVien& thanhvien);
void xuatThanhVien(ThanhVien thanhvien);

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

void themThanhVien(DSHoKhau& dsHoKhau);
void themHoKhauMoi(DSHoKhau& dsHoKhau);

void xoaThanhVien(DSHoKhau& dsHoKhau);
void xoaHoKhau(DSHoKhau& dsHoKhau);
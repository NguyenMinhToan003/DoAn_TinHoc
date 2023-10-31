#include "ThuVien.h"


void nhapThanhVien(ThanhVien& thanhvien) {
    cout << "\nNhap ho va ten: ";
    cin.ignore();
    cin.getline(thanhvien.hoTen, 30);
    cout << "Nhap nam Sinh : ";
    cin >> thanhvien.namSinh;
    cin.ignore();
    cout << "Nhap que quan: ";
    cin.getline(thanhvien.queQuan, 30);
    cout << "Nhap gioi tinh(0 / 1) : ";
    int gt;
    cin >> gt;
    gt ? thanhvien.gioiTinh = 1 : thanhvien.gioiTinh = 0;
}
void xuatThanhVien(ThanhVien thanhvien) {
    cout << "|" << left << setw(15) << thanhvien.id;
    cout << "|" << left << setw(40) << thanhvien.hoTen;
    cout << "|" << left << setw(25)<< thanhvien.namSinh;
    cout << "|" << left << setw(20) << (thanhvien.gioiTinh ? "Nam" : "Nu");
    cout << "|" << left << thanhvien.queQuan;
}
void nhapHoKhau(HoKhau& hoKhau) {
    
    cout << "\nNhap Thong tin Chu Ho : ";
    cin.ignore();
    cin.getline(hoKhau.tenChuHo, 20);
    cout << "\nNhap Dia Chi Ho Khau : ";
    cin.getline(hoKhau.diaChi, 20);
    cout << "\nNhap so luong thanh vien : ";
    cin >> hoKhau.n;
    for (int i = 0; i < hoKhau.n; i++) {
        hoKhau.ds[i].id = i;
        cout << "\nNhap Thanh Vien thu " << i + 1 << endl;
        nhapThanhVien(hoKhau.ds[i]);
    }
}
void xuatHoKhau(HoKhau hoKhau) {
    for (int i = 0; i < hoKhau.n; i++) {
        dongGachNgang();
        cout << "|"
            << left << setw(5) << hoKhau.maHoKhau << "|"
            << left << setw(22) << hoKhau.tenChuHo << "|"
            << left << setw(22) << hoKhau.diaChi << "|"
            << left << setw(8) << hoKhau.ds[i].id << "|"
            << left << setw(22) << hoKhau.ds[i].hoTen << "|"
            << left << setw(10) << hoKhau.ds[i].namSinh << "|"
            << left << setw(11) << (hoKhau.ds[i].gioiTinh ? "Nam" : "Nu") << "|"
            << left << setw(24) << hoKhau.ds[i].queQuan << "|" << endl;
    }
}

void nhapDSHoKhau(DSHoKhau& dsHoKhau) {
    cout << "\nNhap so luong ho khau :";
    cin >> dsHoKhau.n;
    for (int i = 0; i < dsHoKhau.n; i++) {
        cout << "\nHo Khau Thu " << i + 1 << endl;
        dsHoKhau.ds[i].maHoKhau = i;
        nhapHoKhau(dsHoKhau.ds[i]);
    }
}
void xuatDSHoKhau(DSHoKhau dsHoKhau) {
    dongGachNgang();
    dongTieuDe();
    
    for (int i = 0; i < dsHoKhau.n; i++) {
        xuatHoKhau(dsHoKhau.ds[i]);
    }
    dongGachNgang();
}

void nhapTTPhuong(Phuong& phuong) {
    cout << "\nNhap Thong Tin Phuong : ";
    cin.ignore();
    cin.getline(phuong.tenPhuong, 20);
}
void xuatTTPhuong(Phuong phuong) {
    cout << "\nThong Tin Phuong : " << phuong.tenPhuong << endl;
}


void nhapPhuong(Phuong& phuong) {
    nhapTTPhuong(phuong);
    nhapDSHoKhau(phuong.dsHoKhau);
}
void xuatPhuong(Phuong phuong) {
    cout << "\n\t\t\t\t\t\t\tQUAN LY DAN CU CUA PHUONG " << endl;
    xuatTTPhuong(phuong);
    xuatDSHoKhau(phuong.dsHoKhau);
}

int timThanhVien_chiSo(HoKhau& hoKhau) {
    int idSearch;
    cout << "\nNhap id thanh vien : ";
    cin >> idSearch;
    for (int i = 0; i < hoKhau.n; i++) {
        if (hoKhau.ds[i].id == idSearch) return i;
    }
    return -1;
    
}
int timHoKhau_chiSo(DSHoKhau& dsHoKhau) {
    int ma;
    cout << "\nNhap Ma Ho Khau : ";
    cin >> ma;
    for (int i = 0; i < dsHoKhau.n; i++) {
        if (dsHoKhau.ds[i].maHoKhau == ma) return i;
    }
    return -1;
}



void themThanhVien(DSHoKhau& dsHoKhau) {
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "Ho Khau Khong ton tai !" << endl;
    else {
        dongGachNgang();
        dongTieuDe();
        xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
        dongGachNgang();
        dsHoKhau.ds[chiSoHoKhau].ds[dsHoKhau.ds[chiSoHoKhau].n].id = dsHoKhau.ds[chiSoHoKhau].n;
        nhapThanhVien(dsHoKhau.ds[chiSoHoKhau].ds[dsHoKhau.ds[chiSoHoKhau].n]);
        dsHoKhau.ds[chiSoHoKhau].n++;
    }
}

void themHoKhauMoi(DSHoKhau& dsHoKhau) {
    dsHoKhau.ds[dsHoKhau.n].maHoKhau = dsHoKhau.n;
    nhapHoKhau(dsHoKhau.ds[dsHoKhau.n]);
    dsHoKhau.n++;
}

void xoaThanhVien(DSHoKhau& dsHoKhau) {
    
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "\nHo Khau Khong ton tai !" << endl;
    else {
        int chiSoThanhVien = timThanhVien_chiSo(dsHoKhau.ds[chiSoHoKhau]);
        int soLuongThanhVien = dsHoKhau.ds[chiSoHoKhau].n;
        if (chiSoThanhVien == -1)
            cout << "Thanh Vien Khong ton tai !" << endl;
        else {
            dongGachNgang();
            dongTieuDe();
            xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
            dongGachNgang();
            for (int i = chiSoThanhVien; i < soLuongThanhVien; i++) {
                dsHoKhau.ds[chiSoHoKhau].ds[i] = dsHoKhau.ds[chiSoHoKhau].ds[i + 1];
            }
            dsHoKhau.ds[chiSoHoKhau].n--;
        }
    }
}
void xoaHoKhau(DSHoKhau& dsHoKhau) {
   
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "\nHo Khau Khong ton tai !" << endl;
    else {
        cout << left << setw(15) << "|id" << left << setw(40) << "|Ho va Ten" << left << setw(25) << "|Gioi Tinh" << left << setw(20) << "|Nam Sinh" << left << "|Que Quan ";
        xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
        for (int i = chiSoHoKhau; i < dsHoKhau.n; i++) {
            dsHoKhau.ds[i] = dsHoKhau.ds[i + 1];
        }
        dsHoKhau.n--;
    
    }
}

void dongGachNgang() {
    for (int i = 0; i < 133; i++) {
        cout << "-";
    }
}
void dongTieuDe() {
    cout << "|"
        << left << setw(5) << "MHK" << "|"
        << left << setw(22) << "Ten Chu Ho" << "|"
        << left << setw(22) << "Dia Chi" << "|"
        << left << setw(8) << "CCCD" << "|"
        << left << setw(22) << "Ho Va Ten" << "|"
        << left << setw(10) << "Nam Sinh" << "|"
        << left << setw(11) << "Gioi Tinh" << "|"
        << left << setw(24) << "Que Quan" << "|";
}
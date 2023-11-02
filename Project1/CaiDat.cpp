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
    cout << "Nhap gioi tinh(0=Nu /1=Nam) : ";
    int gt;
    cin >> gt;
    gt ? thanhvien.gioiTinh = 1 : thanhvien.gioiTinh = 0;
}
void xuatThanhVien(ThanhVien thanhvien) {
    cout << "|"
        << right << setw(8) <<thanhvien.id << "|"
        << left << setw(22) << thanhvien.hoTen << "|"
        << right << setw(10) << thanhvien.namSinh << "|"
        << left << setw(11) << (thanhvien.gioiTinh ? "Nam" : "Nu") << "|"
        << left << setw(24) << thanhvien.queQuan << "|" << endl;
}


void nhapDSThanhVien(DSThanhVien& dsThanhVien) {
    cout << "\nNhap so luong thanh vien : ";
    cin >> dsThanhVien.n;
    for (int i = 0; i < dsThanhVien.n; i++) {
        dsThanhVien.ds[i].id = i;
        cout << "\nNhap Thanh Vien thu " << i + 1 << endl;
        nhapThanhVien(dsThanhVien.ds[i]);
    }
}

bool ktTenChuHoTrung(HoKhau hoKhau, char chuoi[20]) {
    if (!strcmp(chuoi, hoKhau.tenChuHo)) return true;
    return false;
}

void nhapHoKhau(HoKhau& hoKhau) {
    cout << "\nNhap Thong tin Chu Ho : ";
    cin.ignore();
    cin.getline(hoKhau.tenChuHo, 20);
    cout << "\nNhap Dia Chi Ho Khau : ";
    cin.getline(hoKhau.diaChi, 20);
    nhapDSThanhVien(hoKhau.dsThanhVien);
   
}
void xuatHoKhau(HoKhau hoKhau) {
    for (int i = 0; i < hoKhau.dsThanhVien.n; i++) {
        dongGachNgang();
        cout << "|"
            << right << setw(5) << hoKhau.maHoKhau << "|"
            << left << setw(22) << hoKhau.tenChuHo << "|"
            << left << setw(22) << hoKhau.diaChi << "|"
            << right << setw(8) << hoKhau.dsThanhVien.ds[i].id << "|"
            << left << setw(22) << hoKhau.dsThanhVien.ds[i].hoTen << "|"
            << right << setw(10) << hoKhau.dsThanhVien.ds[i].namSinh << "|"
            << left << setw(11) << (hoKhau.dsThanhVien.ds[i].gioiTinh ? "Nam" : "Nu") << "|"
            << left << setw(24) << hoKhau.dsThanhVien.ds[i].queQuan << "|" << endl;
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
    for (int i = 0; i < hoKhau.dsThanhVien.n; i++) {
        if (hoKhau.dsThanhVien.ds[i].id == idSearch) return i;
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

void themThanhVien(DSHoKhau& dsHoKhau, int chiSoHoKhau) {
    
    if (chiSoHoKhau == -1)
        cout << "Ho Khau Khong ton tai !" << endl;
    else {
        dongGachNgang();
        dongTieuDe();
        xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
        dongGachNgang();
        dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n].id = dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n-1].id+1;
        nhapThanhVien(dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n]);
        dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n++;
    }
}

void themHoKhauMoi(DSHoKhau& dsHoKhau) {
    dsHoKhau.ds[dsHoKhau.n].maHoKhau = dsHoKhau.n;
    nhapHoKhau(dsHoKhau.ds[dsHoKhau.n]);
    dsHoKhau.n++;
}

void xoaThanhVien(DSHoKhau& dsHoKhau,int chiSoHoKhau, int chiSoThanhVien) {
    if (chiSoHoKhau == -1)
        cout << "\nHo Khau Khong ton tai !" << endl;
    else {
        
        int soLuongThanhVien = dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n;
        if (chiSoThanhVien == -1)
            cout << "Thanh Vien Khong ton tai !" << endl;
        else {
            dongGachNgang();
            dongTieuDe();
            xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
            dongGachNgang();
            if (ktTenChuHoTrung(dsHoKhau.ds[chiSoHoKhau], dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[chiSoThanhVien].hoTen)&& dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n>1) {
                cout << "\nNhap Id Nguoi Chu Ho Khau Moi : ";
                int id;
                cin >> id;
                strcpy(dsHoKhau.ds[chiSoHoKhau].tenChuHo, dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[id].hoTen);
            }
            for (int i = chiSoThanhVien; i < soLuongThanhVien; i++) {
                dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[i] = dsHoKhau.ds[chiSoHoKhau].dsThanhVien.ds[i + 1];
            }
            dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n--;
            if (dsHoKhau.ds[chiSoHoKhau].dsThanhVien.n == 0) {
                xoaHoKhau(dsHoKhau, chiSoHoKhau);
                cout << "\nHet Thanh Vien Nen Xoa Ho Khau ";
            }
        }
    }
}
void xoaHoKhau(DSHoKhau& dsHoKhau,int chiSoHoKhau) {
    if (chiSoHoKhau == -1)
        cout << "\nHo Khau Khong ton tai !" << endl;
    else {

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
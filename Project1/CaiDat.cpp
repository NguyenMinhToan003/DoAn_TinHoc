#include "ThuVien.h";


void nhapThanhVien(ThanhVien& thanhvien) {
    cout << "\nNhap id : ";
    cin >> thanhvien.id;
    cin.ignore();
    cout << "\nNhap ho va ten: ";
    cin.getline(thanhvien.hoTen, 30);
    cout << "Nhap tuoi: ";
    cin >> thanhvien.namSinh;
    cin.ignore();
    cout << "Nhap que quan: ";
    cin.getline(thanhvien.queQuan, 30);
    cout << "Nhap gioi tinh(0 / 1) : ";
    cin >> thanhvien.gioiTinh;
    cin.ignore();
}
void xuatThanhVien(ThanhVien thanhvien) {
    cout << "id: " << thanhvien.id << endl;
	cout << "Ho va ten: " << thanhvien.hoTen << endl;
	cout << "Nam sinh: " << thanhvien.namSinh<<endl;
	cout << "Que quan: " << thanhvien.queQuan << endl;
	cout << "Gioi tinh: " << (thanhvien.gioiTinh ? "Nam" : "Nu") << endl;
}

void nhapHoKhau(HoKhau& hoKhau) {
    cout << "\nNhap so luong thanh vien : ";
    cin >> hoKhau.n;
    cout << "\nNhap Thong tin : ";
    cin.ignore();
    cin.getline(hoKhau.info, 20);
    for (int i = 0; i < hoKhau.n; i++) {
        cout << "\nNhap Thanh Vien thu " << i + 1 << endl;
        nhapThanhVien(hoKhau.ds[i]);
    }
}
void xuatHoKhau(HoKhau hoKhau) {
    cout << "\nThong tin : " << hoKhau.info << endl;
    for (int i = 0; i < hoKhau.n; i++) {
            xuatThanhVien(hoKhau.ds[i]);
    }
}

void nhapDSHoKhau(DSHoKhau& dsHoKhau) {
    cout << "\nNhap so luong ho khau :";
    cin >> dsHoKhau.n;
    for (int i = 0; i < dsHoKhau.n; i++) {
        cout << "\nHo Khau Thu " << i + 1 << endl;
        nhapHoKhau(dsHoKhau.ds[i]);

    }
}
void xuatDSHoKhau(DSHoKhau dsHoKhau) {
    for (int i = 0; i < dsHoKhau.n; i++) {
        xuatHoKhau(dsHoKhau.ds[i]);
    }
}

void nhapTTPhuong(Phuong& phuong) {
    cout << "\nNhap Thong Tin Phuong : ";
    cin.ignore();
    cin.getline(phuong.info, 20);
}
void xuatTTPhuong(Phuong phuong) {
    cout << "\nThong Tin Phuong : " << phuong.info << endl;
}


void nhapPhuong(Phuong& phuong) {
    nhapTTPhuong(phuong);
    nhapDSHoKhau(phuong.dsHoKhau);
}
void xuatPhuong(Phuong phuong) {
    cout << "\n\t\t\t\t\t\t\tQUAN LY DAN CU CUA PHUONG " << endl;
    xuatTTPhuong(phuong);
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
    char search[20];
    cout << "\nNhap Thong tin Ho Khau : ";
    cin.ignore();
    cin.getline(search, 20);
    for (int i = 0; i < dsHoKhau.n; i++) {
        if (strcmp(search, dsHoKhau.ds[i].info) == 0) return i;
    }
    return -1;
}





void themThanhVien(DSHoKhau& dsHoKhau) {
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "Ho Khau Khong ton tai !" << endl;
    else {
        xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
        nhapThanhVien(dsHoKhau.ds[chiSoHoKhau].ds[dsHoKhau.ds[chiSoHoKhau].n]);
        dsHoKhau.ds[chiSoHoKhau].n++;
    }
}

void themHoKhauMoi(DSHoKhau& dsHoKhau) {
    nhapHoKhau(dsHoKhau.ds[dsHoKhau.n++]);
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
        for (int i = chiSoHoKhau; i < dsHoKhau.n; i++) {
            dsHoKhau.ds[i] = dsHoKhau.ds[i + 1];
        }
        dsHoKhau.n--;
    
    }
}
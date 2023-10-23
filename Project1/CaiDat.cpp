#include "ThuVien.h"


void nhapThanhVien(ThanhVien& thanhvien) {
    cout << "\nNhap ho va ten: ";
    cin.getline(thanhvien.hoTen, 30);
    cout << "Nhap tuoi: ";
    cin >> thanhvien.namSinh;
    cin.ignore();
    cout << "Nhap que quan: ";
    cin.getline(thanhvien.queQuan, 30);
    cout << "Nhap gioi tinh(0 / 1) : ";
    int gt;
    cin >> gt;
    gt ? thanhvien.gioiTinh = 1 : thanhvien.gioiTinh = 0;
    cin.ignore();
}
void xuatThanhVien(ThanhVien thanhvien) {
    cout << "|" << left << setw(15) << thanhvien.id;
    cout << "|" << left << setw(40) << thanhvien.hoTen;
    cout << "|" << left << setw(25)<< thanhvien.namSinh;
    cout << "|" << left << setw(20) << (thanhvien.gioiTinh ? "Nam" : "Nu");
    cout << "|" << left << thanhvien.queQuan;
}
void nhapHoKhau(HoKhau& hoKhau) {
    cout << "\nNhap so luong thanh vien : ";
    cin >> hoKhau.n;
    cout << "\nNhap Thong tin : ";
    cin.ignore();
    cin.getline(hoKhau.info, 20);
    for (int i = 0; i < hoKhau.n; i++) {
        hoKhau.ds[i].id = i;
        cout << "\nNhap Thanh Vien thu " << i + 1 << endl;
        nhapThanhVien(hoKhau.ds[i]);
    }
}
void xuatHoKhau(HoKhau hoKhau) {
    for (int i = 0; i < hoKhau.n; i++) {
            cout << "\n-------------------------------------------------------------------------------------------------------------------------------------" ;
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
    cout << left << setw(15) << "|id" << left << setw(40) << "|Ho va Ten" << left << setw(25) << "|Gioi Tinh" << left << setw(20) << "|Nam Sinh" << left << "|Que Quan ";
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

void hienThiThongTinHKTimKiem(DSHoKhau dsHoKhau) {
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "Ho Khau Khong ton tai !" << endl;
    else {
        cout << left << setw(15) << "|id" << left << setw(40) << "|Ho va Ten" << left << setw(25) << "|Gioi Tinh" << left << setw(20) << "|Nam Sinh" << left << "|Que Quan ";
        xuatHoKhau(dsHoKhau.ds[chiSoHoKhau]);
       
    }
    
}




void themThanhVien(DSHoKhau& dsHoKhau) {
    int chiSoHoKhau = timHoKhau_chiSo(dsHoKhau);
    if (chiSoHoKhau == -1)
        cout << "Ho Khau Khong ton tai !" << endl;
    else {
        cout << left << setw(15) << "|id" << left << setw(40) << "|Ho va Ten" << left << setw(25) << "|Gioi Tinh" << left << setw(20) << "|Nam Sinh" << left << "|Que Quan ";
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
            cout << left << setw(20) << "|id" << left << setw(40) << "|Ho va Ten" << left << setw(25) << "|Gioi Tinh" << left << setw(20) << "|Nam Sinh" << left << "|Que Quan ";
            xuatThanhVien(dsHoKhau.ds[chiSoHoKhau].ds[chiSoThanhVien]);
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


bool xuatFile(Phuong&  phuong){
    char tenFile[30];
    cout << "\nNhap Ten File muon luu : ";
    cin.ignore();
    cin.getline(tenFile, 30);
    ofstream file(tenFile);
    if(file.is_open()){
        file << "\n\t\t\t\t\t\t\tQUAN LY DAN CU CUA PHUONG " << endl;
        file << "Thong tin phuong : " << phuong.info << endl;
        file << "\n-------------------------------------------------------------------------------------------------------------------------------------" << endl;
        file << left << setw(15) << "id" << left << setw(50) << "Ho va Ten" << left << setw(25) << "Gioi Tinh" << left << setw(20) << "Nam Sinh" << left << "Que Quan " << endl;
        for (int i = 0; i < phuong.dsHoKhau.n; i++) {
            file<< "\n-------------------------------------------------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < phuong.dsHoKhau.ds[i].n; j++) {
                file << left << setw(20) << phuong.dsHoKhau.ds[i].ds[j].id;
                file << left << setw(40) << phuong.dsHoKhau.ds[i].ds[j].hoTen;
                file << left << setw(25) << phuong.dsHoKhau.ds[i].ds[j].namSinh;
                file << left << setw(20) << (phuong.dsHoKhau.ds[i].ds[j].gioiTinh ? "Nam" : "Nu");
                file << left << phuong.dsHoKhau.ds[i].ds[j].queQuan << endl;
            }
        }
        file.close();
       cout << "Ghi thanh cong vao file: " << tenFile << endl;
       return 1;
    }
    else {
     cerr << "Khong the mo file: " << tenFile << endl;
     return 0;
    }
}

bool docFile() {
    char tenFile[30];
    cout << "\nNhap Ten file muon doc : ";
    cin.ignore();
    cin.getline(tenFile,30);
    std::ifstream file(tenFile);
    if (file.is_open()) {
       string duLieu;
        while (getline(file, duLieu)) {
           cout << duLieu <<endl;
        }
        file.close();
       cout << "Doc thanh cong tu file: " << tenFile <<endl;
        return true;
    }
    else {
       cerr << "Khong the mo file: " << tenFile << endl;
        return false;
    }
}


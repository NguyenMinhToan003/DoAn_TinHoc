#include "ThuVien.h"


int main() {

    Phuong phuong;
    int option = 1;

    while (option) {
        cout << "\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n1.Tao Phuong. ";
        cout << "\n2.Quan Ly Phuong.";
        cout << "\n3.Nhap Thong Tin Phuong. ";
        cout << "\n4.Xuat Thong Tin Phuong. ";
        cout << "\n5.Tim Thong Tin Ho Khau.";
        cout << "\n6.Them Ho Khau Moi.";
        cout << "\n7.Them Thanh Vien.";
        cout << "\n8.Xoa Thanh Vien. ";
        cout << "\n9.Xoa Ho Khau.";
        cout << "\n10.Ghi File.";
        cout << "\n11.Doc File. ";
        cout << "\n0.Dung Chuong Trinh.";
        
        cout << "\nNhap Lua Chon : ";
        cin >> option;
        system("cls");
       
        if (option == 1) nhapPhuong(phuong);
        else if (option == 2)xuatPhuong(phuong);
        else if (option == 3) nhapTTPhuong(phuong);
        else if (option == 4) xuatTTPhuong(phuong);
        else if (option == 5) xuatHoKhau(phuong.dsHoKhau.ds[timHoKhau_chiSo(phuong.dsHoKhau)]);
        else if (option == 6) themHoKhauMoi(phuong.dsHoKhau);
        else if (option == 7) themThanhVien(phuong.dsHoKhau);
        else if (option == 8) xoaThanhVien(phuong.dsHoKhau);
        else if (option == 9) xoaHoKhau(phuong.dsHoKhau);
        else if (option == 10) xuatFile(phuong);
        else if (option == 11) docFile();
        else if (option == 0) break;


    }
    return 0;

}

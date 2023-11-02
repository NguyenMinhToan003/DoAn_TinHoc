#include "ThuVien.h"


int main() {
   
    Phuong phuong;
    int option = 1;
    


    while (option) {
        cout << "\n1.Tao Phuong. ";
        cout << "\n2.Quan Ly Phuong.";
        cout << "\n3.Nhap Thong Tin Phuong. ";
        cout << "\n4.Xuat Thong Tin Phuong. ";
        cout << "\n5.Tim Thong Tin Ho Khau.";
        cout << "\n6.Them Ho Khau Moi.";
        cout << "\n7.Them Thanh Vien.";
        cout << "\n8.Xoa Thanh Vien. ";
        cout << "\n9.Xoa Ho Khau.";
        cout << "\n0.Dung Chuong Trinh.";

        cout << "\nNhap Lua Chon : ";
        cin >> option;
        system("cls");

        if (option == 1) 
            nhapPhuong(phuong);
        else if (option == 2)
            xuatPhuong(phuong);
        else if (option == 3) 
            nhapTTPhuong(phuong);
        else if (option == 4) 
            xuatTTPhuong(phuong);
        else if (option == 5) {
            int chiSoHoKhau = timHoKhau_chiSo(phuong.dsHoKhau);
            if (chiSoHoKhau == -1)
                cout << "Ho Khau Khong ton tai !" << endl;
            else {
                dongGachNgang();
                dongTieuDe();
                xuatHoKhau(phuong.dsHoKhau.ds[chiSoHoKhau]);
                dongGachNgang();

            }
        }
        else if (option == 6)
        {
            cout << "\nChuc Nang Them Ho Khau : " << endl;
            themHoKhauMoi(phuong.dsHoKhau);
        }
        else if (option == 7) 
        {
            cout << "\nChuc Nang Them Thanh Vien : " << endl;
            int chiSoHoKhau = timHoKhau_chiSo(phuong.dsHoKhau);
            themThanhVien(phuong.dsHoKhau,chiSoHoKhau);
        }
        else if (option == 8) 
        {
            cout << "\nChuc Nang Xoa Thanh Vien :" << endl;
            int chiSoHoKhau = timHoKhau_chiSo(phuong.dsHoKhau);
            int chiSoThanhVien = timThanhVien_chiSo(phuong.dsHoKhau.ds[chiSoHoKhau]);
            xoaThanhVien(phuong.dsHoKhau,chiSoHoKhau,chiSoThanhVien);
        }
        else if (option == 9) 
        {
            cout << "\nChuc Nang Xoa Ho Khau" << endl;
            int chiSoHoKhau = timHoKhau_chiSo(phuong.dsHoKhau);
            if (chiSoHoKhau != -1) {
                dongGachNgang();
                dongTieuDe();
                xuatHoKhau(phuong.dsHoKhau.ds[chiSoHoKhau]);
                dongGachNgang();
                xoaHoKhau(phuong.dsHoKhau, chiSoHoKhau);
            }
            else cout << "\nHo Khau Khong ton tai! ";
            
        }

        else if (option == 0) break;
    }
  
    return 0;

}

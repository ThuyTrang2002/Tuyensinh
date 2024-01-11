
#include <bits/stdc++.h>
#include "QuanLy.cpp"

using namespace std;

int main()
{
	QuanLy ql;
	int choose;
	while(true)
	{
		cout<<"================== Menu QUAN LY TUYEN SINH 2022 =================="<<endl;
		cout<<"---------1. Nhap danh sach thi sinh va nguyen vong thi sinh-------\n";
		cout<<"---------2. Them thi sinh vao danh sach                    -------\n";
		cout<<"---------3. Hien thi danh sach ho so du thi                -------\n";
		cout<<"---------4. Chinh sua thong tin thi sinh                   -------\n";
		cout<<"---------5. Hien thi danh sach trung tuyen                 -------\n";
		cout<<"---------6. Sap xep diem thi theo diem thi giam dan        -------\n";
		cout<<"---------7. Ghi thong tin vao file                         -------\n";
		cout<<"---------8. Doc thong tin tu file                          -------\n";
		cout<<"----------------Nhan phim 0 de thoat chuong trinh !-----------"<<endl<<endl;
		cout<<"Nhap lua chon: ";
		cin>>choose;
		switch(choose)
		{
		case 1:
			ql.themDanhSachThiSinh();
			break;
		case 2:
			ql.themThiSinh();
			break;
		case 3:
			ql.hienThiDanhSachThiSinh();
			break;
		case 4:
			int option;
			cout<<"1. Sua thi sinh\n";
			cout<<"2. Xoa thi sinh\n";
			cout<<"3. Them nguyen vong\n";
			cout<<"4. Xoa nguyen vong\n";
			cout<<endl;
			cout<<"Nhap lua chon cua ban: ";
			cin>>option;
			switch(option)
			{
			case 1:
				ql.suaThiSinh();
				break;
			case 2:
				ql.xoaThiSinh();
				break;
			case 3:
				ql.themNguyenVong();
				break;
			case 4:
			    ql.xoaNguyenVong();
			}
			break;
		case 5:
			char maNganh[10];
			float diemChuan;
			cout<<"Nhap ma nganh: "; fflush(stdin); gets(maNganh);
			cout<<"Nhap diem chuan: "; cin>>diemChuan;
			ql.hienDanhSachTrungTuyen(maNganh, diemChuan);
			break;
		case 6:
			ql.sapXep();
			ql.hienThiDanhSachThiSinh();
			break;
		case 7:
			ql.ghiFile();
			break;
		case 8:
			ql.docFile();
			break;
		case 0:
			return 0;
		}
	}
}
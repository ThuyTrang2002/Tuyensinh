#include <bits/stdc++.h>
#include "Nguoi.cpp"
#include "NguyenVong.cpp"

using namespace std;

class ThiSinh : Nguoi
{
private:
	char sbd[10];
	float diemUT;
	NguyenVong *nv;
	int soNV;
	friend class QuanLy;
public:
	ThiSinh(){}

	ThiSinh(const char* hoTen, const char* queQuan, int namSinh, int gioiTinh,
			const char* sbd, float diemUT, NguyenVong *nv) : Nguoi(hoTen, queQuan, namSinh, gioiTinh)
	{
		strcpy(this->sbd, sbd);
		this->diemUT = diemUT;
		this-> nv = nv;
	}

	char* getSBD()
	{
		return this->sbd;
	}

	void setSBD(const char* sbd)
	{
		strcpy(this->sbd, sbd);
	}

	float getDiemUT()
	{
		return this->diemUT;
	}

	void setDiemUT(float diemUT)
	{
		this->diemUT = diemUT;
	}

	NguyenVong* getNguyenVong()
	{
		return this->nv;
	}

	void setNguyenVong(NguyenVong *nv)
	{
		this->nv = nv;
	}

	int getSoNV()
	{
		return this->soNV;
	}

	void setSoNV(int soNV)
	{
		this->soNV = soNV;
	}

	void nhap()
	{
		cout<<"Nhap so bao danh: "; fflush(stdin); gets(this->sbd);
		Nguoi::nhap();
		cout<<"Nhap diem uu tien: "; cin>>this->diemUT;
		cout<<"Nhap so nguyen vong: "; cin>>this->soNV;
		nv = new NguyenVong[soNV];
		for(int i = 0; i < soNV; ++ i)
		{
			cout<<"===== Nhap nguyen vong thu "<< i + 1 <<" ====="<<endl;
			nv[i].nhap();
		}
	}

	void xuat()
	{
		cout<<"======================================================================================================"<<endl;
		cout<<left<<setw(15)<<"SBD"<<setw(25)<<"Ho ten"<<setw(25)<<"Que quan"<<setw(15)<<"Nam sinh"<<setw(15)<<"Gioi tinh"<<"Diem UT"<<endl;
		cout<<setw(15)<<sbd;
		Nguoi::xuat();
		cout<<diemUT<<endl;
		cout<<"======================================== Danh sach nguyen vong ======================================="<<endl;
		cout<<setw(10)<<"Ma NV"<<setw(15)<<"Ma nganh"<<setw(15)<<"Ma truong"<<setw(25)<<"Ten nganh"<<setw(15)<<"Khoi XT"<<"Diem thi"<<endl;
		for(int i = 0; i < soNV; ++ i)
			nv[i].xuat();
	}

	void hien()
	{
		cout<<"======================================================================================================"<<endl;
		cout<<left<<setw(15)<<"SBD"<<setw(25)<<"Ho ten"<<setw(25)<<"Que quan"<<setw(15)<<"Nam sinh"<<setw(15)<<"Gioi tinh"<<"Diem UT"<<endl;
		cout<<setw(15)<<sbd;
		Nguoi::xuat();
		cout<<diemUT<<endl;
	}

	void sua()
	{
		cout<<"Nhap so bao danh: "; fflush(stdin); gets(this->sbd);
		Nguoi::nhap();
		cout<<"Nhap diem uu tien: "; cin>>this->diemUT;
	}

	void ghiFile(const char* filePath)
	{
		ofstream ofs(filePath, ios::app);
		
		ofs<<"======================================================================================================"<<endl;
		ofs<<left<<setw(15)<<"SBD"<<setw(25)<<"Ho ten"<<setw(25)<<"Que quan"<<setw(15)<<"Nam sinh"<<setw(15)<<"Gioi tinh"<<"Diem UT"<<endl;
		ofs<<setw(15)<<sbd<<setw(25)<<hoTen<<setw(25)<<queQuan<<setw(15)<<namSinh<<setw(15)<<gioiTinh<<diemUT<<endl;
		ofs<<"======================================== Danh sach nguyen vong ======================================="<<endl;
		ofs<<setw(15)<<"Ma NV"<<setw(15)<<"Ma nganh"<<setw(15)<<"Ma truong"<<setw(25)<<"Ten nganh"<<setw(15)<<"Khoi XT"<<"Diem thi"<<endl;
		for(int i = 0; i < soNV; ++ i)
			nv[i].xuat(filePath);

		ofs.close();
	}
};
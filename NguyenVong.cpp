#include <bits/stdc++.h>

using namespace std;

#define cst const char* // dung cst thay cho [const char*]

class NguyenVong;

class NguyenVong
{
private:
	char maNV[10], maNganh[10], maTruong[10], tenNganh[25], khoiXT[10];
	float diemThi;
public:
	NguyenVong(){}

	NguyenVong(cst maNV, cst maNganh, cst maTruong, cst tenNganh, cst khoiXT, float diemThi)
	{
		strcpy(this->maNV, maNV);
		strcpy(this->maNganh, maNganh);
		strcpy(this->maTruong, maTruong);
		strcpy(this->tenNganh, tenNganh);
		strcpy(this->khoiXT, khoiXT);
		this->diemThi = diemThi;
	}

	char* getMaNV()
	{
		return this->maNV;
	}

	void setMaNV(cst maNV)
	{
		strcpy(this->maNV, maNV);
	}

	char* getMaNganh()
	{
		return this->maNganh;
	}

	void setMaNganh(cst maNganh)
	{
		strcpy(this->maNganh, maNganh);
	}

	char* getMaTruong()
	{
		return this->maTruong;
	}

	void setMaTruong(cst maTruong)
	{
		strcpy(this->maTruong, maTruong);
	}

	char* getTenNganh()
	{
		return this->tenNganh;
	}

	void setTenNganh(cst tenNganh)
	{
		strcpy(this->tenNganh, tenNganh);
	}

	char* getKhoiXT()
	{
		return this->khoiXT;
	}

	void setKhoiXT(cst khoiXT)
	{
		strcpy(this->khoiXT, khoiXT);
	}

	float getDiemThi()
	{
		return this->diemThi;
	}

	void setDiemThi(float diemThi)
	{
		this->diemThi = diemThi;
	}

	void nhap()
	{
		cout<<"Nhap ma nguyen vong: "; fflush(stdin); gets(this->maNV);
		cout<<"Nhap ma nganh: "; gets(this->maNganh);
		cout<<"Nhap ma truong: "; gets(this->maTruong);
		cout<<"Nhap ten nganh: "; gets(this->tenNganh);
		cout<<"Nhap khoi xet tuyen: "; gets(this->khoiXT);
		cout<<"Nhap diem thi: "; cin>>this->diemThi;
	}

	void xuat()
	{
		cout<<left<<setw(15)<<maNV<<setw(15)<<maNganh<<setw(15)<<maTruong<<setw(25)<<tenNganh<<setw(15)<<khoiXT<<diemThi<<endl;
	}

	void xuat(const char* filePath)
	{
		ofstream ofs(filePath, ios::app);
		ofs<<left<<setw(15)<<maNV<<setw(15)<<maNganh<<setw(15)<<maTruong<<setw(25)<<tenNganh<<setw(15)<<khoiXT<<diemThi<<endl;
		ofs.close();
	}

	void sua()
	{
		cout<<"Nhap ma nguyen vong: "; fflush(stdin); gets(this->maNV);
		cout<<"Nhap ma nganh: "; gets(this->maNganh);
		cout<<"Nhap ma truong: "; gets(this->maTruong);
		cout<<"Nhap ten nganh: "; gets(this->tenNganh);
		cout<<"Nhap khoi xet tuyen: "; gets(this->khoiXT);
		cout<<"Nhap diem thi: "; cin>>this->diemThi;
	}
};
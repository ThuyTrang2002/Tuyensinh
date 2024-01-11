  #include <bits/stdc++.h>

using namespace std;

class Nguoi
{
protected:
	char hoTen[25], queQuan[25];
	int namSinh, gioiTinh;
public:
	Nguoi(){}

	Nguoi(const char* hoTen, const char* queQuan, int namSinh, int gioiTinh)
	{
		strcpy(this->hoTen, hoTen); // hàm strcpy (string copy) dùng sao chép chuỗi
		strcpy(this->queQuan, queQuan);
		this->namSinh = namSinh;
		this->gioiTinh = gioiTinh;
	}

	char* getHoTen() // sài char* là để làm việc với mảng ký tự
	{
		return this->hoTen;
	}

	void setHoTen(const char* hoTen) // sài const char* là vì khi chuyền vào đối số là một hằng ký tự không đổi, nên sài const char*
	{
		strcpy(this->hoTen, hoTen);
	}

	char* getQueQuan()
	{
		return this->queQuan;
	}

	void setQueQuan(const char* queQuan)
	{
		strcpy(this->queQuan, queQuan);
	}

	int getNamSinh()
	{
		return this->namSinh;
	}

	void setNamSinh(int namSinh)
	{
		this->namSinh = namSinh;
	}

	const char* getGioiTinh()
	{
		if(this->gioiTinh == 1)
			return "Nam";
		return "Nu";
	}

	void setGioiTinh(int gioiTinh)
	{
		this->gioiTinh = gioiTinh;
	}

	void nhap()
	{
		cout<<"Nhap ho ten: "; fflush(stdin); gets(this->hoTen); // fflush(stdin): dùng để xoá bộ nhớ đệm trước khi nhập dữ liệu kiểu chuỗi
		cout<<"Nhap que quan: "; gets(this->queQuan); // gets(dùng nhập chuỗi gồm khoảng trắng)
		cout<<"Nhap nam sinh: "; cin>>this->namSinh;
		cout<<"Nhap gioi tinh (Nam: 1/ Nu: 0): "; cin>>gioiTinh;
	}

	void xuat()
	{
		cout<<left<<setw(25)<<hoTen<<setw(25)<<queQuan<<setw(15)<<namSinh<<setw(15)<<gioiTinh; // setw() căn lề, left: căn trái
	}

	void xuat(const char* filePath)
	{
		ofstream ofs(filePath, ios::app); // ios::app: chèn
		ofs<<left<<setw(25)<<hoTen<<setw(25)<<queQuan<<setw(15)<<namSinh<<setw(15)<<gioiTinh;
		ofs.close();
	}
};
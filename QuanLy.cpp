#include <bits/stdc++.h>
#include "ThiSinh.cpp"

using namespace std;

class QuanLy
{
private:
	ThiSinh *thiSinh;
	int soTS = 0;
public:
	QuanLy(){}

	QuanLy(ThiSinh *thiSinh)
	{
		this->thiSinh = thiSinh;
	}

	void themThiSinh()
	{
		ThiSinh ts;
		ts.nhap();
		thiSinh = (ThiSinh*) realloc(thiSinh, (soTS + 1) * sizeof(ThiSinh));
		thiSinh[soTS] = ts;
		++soTS;
	}

	void themDanhSachThiSinh()
	{
		int n;
		cout<<"Nhap so luong thi sinh muon them: ";
		cin>>n;
		while(n--)
		{
			cout<<"===== Nhap thong tin thi sinh ====="<<endl;
			themThiSinh();
		}
	}

	void suaThiSinh()
	{
		char sbd[10];
		bool flag = false;
		cout<<"Nhap so bao danh thi sinh can sua: "; fflush(stdin); gets(sbd);
		for(int i = 0; i < soTS; ++ i)
		{
			if(strcmp(thiSinh[i].getSBD(), sbd) == 0)
			{
				thiSinh[i].sua();
				flag = true;
				break;
			}
		}

		if(!flag)
		{
			cout<<"Khong co thi sinh nao co so bao danh ["<<sbd<<"] !"<<endl;
		}
	}

	void xoaThiSinh()
	{
		char sbd[10];
		cout<<"Nhap so bao danh thi sinh can xoa: "; fflush(stdin); gets(sbd);
		bool flag = false;
		int index = -1;
		for(int i = 0; i < soTS; ++ i)
		{
			if(strcmp(thiSinh[i].getSBD(), sbd) == 0)
			{
				index = i;
				flag = true;
				break;
			}
		}

		if(!flag)
		{
			cout<<"Khong co thi sinh nao co so bao danh ["<<sbd<<"] !"<<endl;
		}
		else
		{
			for(int i = index; i < soTS - 1; ++ i)
			{
				thiSinh[i] = thiSinh[i + 1];
				-- soTS;
				thiSinh = (ThiSinh*) realloc(thiSinh, soTS * sizeof(ThiSinh));
			}
		}
	}

	void subThemNguyenVong(ThiSinh &ts)
	{
		NguyenVong nguyenVong;
		nguyenVong.nhap();
		ts.nv = (NguyenVong*) realloc(ts.nv, (ts.soNV + 1) * sizeof(NguyenVong));
		ts.nv[ts.soNV] = nguyenVong;
		++ts.soNV;
	}
    void themNguyenVong()
    {
    	char sbd[10];
    	bool flag = false;
    	cout<<"Nhap so bao danh thi sinh can chinh sua: "; fflush(stdin); gets(sbd);
    	for(int i = 0; i < soTS; ++i)
    	{
    		if(strcmp(thiSinh[i].getSBD(),sbd) == 0)
    		{
    			flag = true;
    			subThemNguyenVong(thiSinh[i]);
    			break;
    		}
    	}
    	if(!flag)
    	{
    		cout<<"Khong co thi sinh nao co so bao danh ["<<sbd<<"]!" <<endl;
    	}
    }
	void subXoaNguyenVong(ThiSinh &ts)
	{
		char maNV[10];
		cout<<"Nhap ma nguyen vong can xoa: "; fflush(stdin); gets(maNV);
		bool flag = false;
		int index;
		for(int i = 0; i < ts.soNV; ++ i)
		{
			if(strcmp(ts.nv[i].getMaNV(), maNV) == 0)
			{
				index = i;
				flag = true;
				break;
			}
		}

		if(!flag)
		{
			cout<<"Khong co ma nguyen vong ["<<maNV<<"] !"<<endl;
		}
		else
		{
			for(int i = index; i < ts.soNV - 1; ++ i)
				ts.nv[i] = ts.nv[i + 1];
			--ts.soNV;
			ts.nv = (NguyenVong*) realloc(ts.nv, ts.soNV * sizeof(NguyenVong));
		}
	}
    void xoaNguyenVong()
	{
		char sbd[10];
		bool flag = false;
		cout<<"Nhap so bao danh thi sinh can chinh sua: "; fflush(stdin); gets(sbd);
		for(int i = 0; i < soTS; ++ i)
		{
			if(strcmp(thiSinh[i].getSBD(), sbd) == 0)
			{
				flag = true;
				subXoaNguyenVong(thiSinh[i]);
				break;
			}
		}
		if(!flag)
		{
			cout<<"Khong co thi sinh nao co so bao danh ["<<sbd<<"] !"<<endl;
		}
	}
	
	void hienDanhSachTrungTuyen(const char* maNganh, float diemChuan)
	{
		for(int i = 0; i < soTS; ++ i)
		{
			for(int j = 0; j < thiSinh[i].getSoNV(); ++ j)
			{
				if(strcmp(thiSinh[i].getNguyenVong()[j].getMaNganh(), maNganh) == 0 && thiSinh[i].getNguyenVong()[j].getDiemThi() >= diemChuan)
					thiSinh[i].hien();
			}
		}
	}

	void sapXepNguyenVongTheoDiem(ThiSinh ts)
	{
		for(int i = 0; i < ts.soNV - 1; ++ i)
		{
			for(int j = i + 1; j < ts.soNV; ++ j)
				if(ts.getNguyenVong()[i].getDiemThi() < ts.getNguyenVong()[j].getDiemThi())
					swap(ts.nv[i], ts.nv[j]);
		}
	}

	void sapXep()
	{
		for(int i = 0; i < soTS; ++ i)
			sapXepNguyenVongTheoDiem(thiSinh[i]);
	}

	void hienThiDanhSachThiSinh()
	{
		for(int i = 0; i < soTS; ++ i)
		{
			cout<<"======================================================================================================"<<endl;
			cout<<"--------------------------- Thong tin thi sinh thu "<<i + 1<<" ----------------------------------"<<endl;
			thiSinh[i].xuat();
		}
	}

	void docFile()
	{
		ThiSinh ts;
		ifstream ifs("TuyenSinh.txt");
		while(!ifs.eof())
		{
			string s;
			getline(ifs, s);
			cout<<s<<endl;
		}

	}

	void ghiFile()
	{
		ofstream f("TuyenSinh.txt");
		f.close();
		for(int i = 0; i < soTS; ++ i)
		{
			thiSinh[i].ghiFile("TuyenSinh.txt");
		}
	}
};
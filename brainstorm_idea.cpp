#include <iostream>
#include <string>

using namespace std;

void* realloc(void* pointer, int so_luong);

class DonVanChuyen {
	double quang_duong;
	double can_nang;
	class dia_chi {
		int so_nha;
		string pho;
		string quan;
		string tinh;
	};
	int ID;
	int thoi_diem_gui; //yyyymmdd
	int thoi_diem_toi; //yyyymmdd
	
	double chiphi();
	DonVanChuyen(double quang_duong, double can_nang, dia_chi diaChi);
	DonVanChuyen(double quang_duong, dia_chi diaChi);
	void suaDonHang(double quang_duong_moi, double can_nang_moi, dia_chi diaChi_moi);
	int timkiemDon(int so_nha, string pho, string quan, string tinh); //tra ve ID
};

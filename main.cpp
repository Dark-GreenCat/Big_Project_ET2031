#include "data_structure.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<fstream>
using namespace std;

#define MAX_NUMBER_OF_FORM 100

/*struct sinhvien{
    string hoTen;
    int mssv;
    string namSinh;
    vector<monhoc> d_s_monhoc;//mang cac mon hoc
};
struct  monhoc{
    string tenMonHoc;
    float diem;
};

//ham doc file thong tin cua 1 sv
void doc_file_thong_tin_sinh_vien(ifstream &filein, sinhvien &sv){
    getline(filein, sv.hoTen,','); //doc du lieu den dau , thi dung
    filein>>sv.mssv; //mssv kieu int
    getline(filein, sv.namSinh);//doc den het dong thi dung
}

//ham doc file thong tin cua 1 mon hoc
void doc_file_thong_tin_mon_hoc(ifstream &filein, monhoc &mon){
    getline(filein, mon.tenMonHoc);
    filein>>mon.diem;
}

//ham doc thong tin sinh vien va danh sach mon hoc
void doc_file(ifstream &filein, vector<sinhvien> &d_s_sinhvien){
    sinhvien sv;
    doc_file_thong_tin_sinh_vien(filein,sv);//đọc thông tin của 1 sv
    int n; //số lượng môn học
    filein >>n;
    for(int i=0;i<n;i++){
        monhoc mon;
        doc_file_thong_tin_mon_hoc(filein, mon);
        sv.d_s_monhoc.push_back(mon);//thêm 1 môn học vào cuối mảng d_s môn học của sv
    }
    //thêm thông tin sv vào mảng 1 chiều sinh viên
    d_s_sinhvien.push_back(sv);
}
//hàm xuất thông tin Sv
void xuat_thong_tin_sv(sinhvien sv){
    cout<<"\nho ten: "<<sv.hoTen;
    cout<<"\nMSSV: "<<sv.mssv;
    cout<<"\nNam sinh: "<<sv.namSinh;
}
//hàm xuaatsa thông tin môn học
void xuat_thong_tin_mon_hoc(monhoc mon){
    cout<<"\nTen mon hoc: "<<mon.tenMonHoc;
    cout<<"\nDiem: "<<mon.diem;
}
//hàm test xuất dữ liệu sv
void test(vector<sinhvien> ds){
    for (int i = 0; i < ds.size(); i++)
    {  
        cout<<"\nsinh vien thu"<<i+1;
        xuat_thong_tin_sv(ds[i]);//xuất thông tin sv
        cout<<"\n====Danh sach mon hoc tuong ung===\n";
        for(int j=0; j<ds[i].d_s_monhoc.size();j++){
            cout<<"\nmon hoc thu: "<<j+1;
            xuat_thong_tin_mon_hoc(ds[i].d_s_monhoc[j]);
        }
    }
}*/
int main() { 
    //vector<ShippingForm *> pList; 
    // Price price;

    // DocumentShippingForm DocList;
    // DocList.inputInfo();

    // pList.push_back(&DocList);
    // cout << DocList.getShippingPrice(price);
    // cout << endl << default_money.DOC_distance << endl;

    // cout << pList.at(0)->getShippingPrice(price);
    // cout << endl << default_money.DOC_distance << endl;

    /*ShippingFormList pLIST;
    pLIST.inputList();
    pLIST.outputList();*/
    
    /*ifstream filein;
    filein.open("test.txt",ios_base::in);//mở file test.txt ra doc
    vector<sinhvien>d_s_sv;//khai bao ds sinh vien
    doc_file(filein,d_s_sv);//đọc tất cả dữ liệu từ file test.txt
    test(d_s_sv);
    filein.close();*/
    return 0;
}

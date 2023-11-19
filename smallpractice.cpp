#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
//class
//thuoc tinh: attribute
//phuong thuc: method, behavior
//object: doi tuong
//constructor: ham khoi tao
//destructor: ham huy
//this-> 
//setter, getter: lấy và gán phần từ từ trong class

//1
//-Encapsulation: Dong goi
//-Access modifier: mo ta pham vi truy cap thuoc tinh, phuong thuc 
//+Private (thuong chua thuoc tinh)
//+Public (thuong chua phuong thuc)
//+Protected
//SV001=>SV002=>SV003 (Static)
// friend function, friend class: có hàm ko thuộc class nhưng vẫn truy cập vào các thuộc tính của object
//Forward declaration
//Operation overloading << >> : nhập trồng toán tử
// cout: ostream
//cin: istream
class GiaoVien;
class SinhVien;
//Khai bao class
/*class Tenclass {
	//thuoc tinh va phuong thuc
};
*/
class SinhVien {
	friend class GiaoVien;
//thuoc tinh
private:
	string id, ten, ns;
	double gpa; 
	static int dem;
public:
	SinhVien(); // constructor: ham luon dc tao khi khai bao moi 1 sv
	SinhVien(string, string, string, double);// constructor
/*	void xinchao();
	void dihoc();
*/
	void nhap();
	void in();
	double getGPA();
	void setGPA(double);
	void tangDem();
	int getDem();
	~SinhVien(); // hàm này gọi khi đối tượng kết thúc
	friend void inthongtin(SinhVien a);
	//Overloading
	friend istream& operator >> (istream &in, SinhVien&);
	friend ostream& operator << (ostream& out, SinhVien a);
};

int SinhVien::dem = 0;

void inthongtin(SinhVien a) {
	cout << a.id << " " << a.ten << endl;
}
//---------------------------------------------------------------------------------------------------
//Impelemtation
int SinhVien::getDem() {
	return dem;
}
void SinhVien::tangDem() {
	++dem;
}
SinhVien::SinhVien() {
	cout << "Doi tuong mac dinh duoc tao o day" << endl;
	this->id = this->ten = this->ns = "";
	this->gpa = 0;
}

SinhVien::SinhVien(string id, string ten, string ns, double gpa) {
	this->id = id; // this->... để chỉ rõ thuộc tính thuộc lớp
	this->ten = ten;
	this->ns = ns;
	this->gpa = gpa;
}
SinhVien::~SinhVien() {
	cout << "Doi tuong duoc huy tai day";
}
void SinhVien::nhap() {
	cout << "Nhap id: "; cin >> this->id;
	cin.ignore();
	cout << "Nhap ten: "; getline(cin, this->ten);
	cout << "Nhap ns: "; cin >> this->ns;
	cout << "Nhap diem: "; cin >> this->gpa;
}
void SinhVien::in() {
	cout << this->id << " " << this->ten << " " << this->ns << " " << fixed<< setprecision(2)<<this->gpa;
}
/*
void SinhVien::xinchao() {
	cout << "Hello"<<endl;
}
void SinhVien::dihoc() {
	cout << "di hoc" << endl;
}
*/
void abc() {
	SinhVien x;
}
//lấy gpa từ class
/*
double SinhVien::getGPA() {
	return this->gpa; // return gpa;
}
bool cmp(SinhVien a, SinhVien b) {
	return a.getGPA() > b.getGPA();
}
*/
// hàm gán value cho thuộc tính
void SinhVien::setGPA(double gpa) {
	this->gpa = gpa;
}

class GiaoVien {
private:
	string khoa;
public:
	void update(SinhVien&);
};
void GiaoVien::update(SinhVien& x) {
	x.gpa = 3.20;
}
//Overloading
istream& operator >> (istream& in, SinhVien&) {
	cout << "Nhap id: ";
	in >> a.id;
	cout << "Nhap ten: "; in.ignore();
	getline(in, a.ten);
	in >> a.ns >> a.gpa;
	return in;
}
ostream& operator >> (ostream& out, SinhVien a) {
	cout << a.id << " " << a.ten << " " << a.ns << " " << fixed << serprecision(2) << a.getGPA << endl;
	return out;
}

//---------------------------------------------------------------------------------------------------
int main() {
/*	SinhVien x("123", "Nguyen Van A", "23/10/2023", 3.14);
	x.dihoc();
	x.xinchao();
*/
/*	abc();
	cout << "Xin chao";
	if (1) {
		SinhVien x; //mỗi lần khai SinhVien x sẽ gọi hàm tạo, khi hết Encapsulation sẽ gọi destructor
	} 
	cout << "hello";
	return 0;
*/
/*	int n; cin >> n;
	SinhVien a[100]; // có 1 danh sách 100 sinh viên
	for (int i = 0;i < n;i++) {
		a[i].nhap();
	}
	for (int i = 0;i < n;i++) {
		a[i].in();
	}
	x.nhap();
	x.in();
*/
// hàm gán value cho thuộc tính
/*	x.setGPA(2.18);
*/
//Sinh vien x= sinh vien y
/*
	SinhVien x;
	x.nhap();
	SinhVien y=x;
	y.in();
*/
	SinhVien x;
	x.tangDem();
	x.tangDem();
	SinhVien y;
	cout << y.getDem() << endl;
//overloading
	SinhVien x;
	cin >> x; // sẽ thực hiện câu lệnh của istream
	cout << x;// sẽ thực hiên câu lệnh của ostream 
}
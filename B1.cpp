#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SV {
protected:
    string MaSV;
    string hoten;

public:
    SV() {}
    virtual ~SV() {}
    virtual void nhap();
    virtual void xuat() const;
};

void SV::nhap() {
    cout << "Nhap ma sinh vien: ";
    getline(cin, MaSV);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
}

void SV::xuat() const {
    cout << "Ma SV: " << MaSV << ", Ho ten: " << hoten;
}

class SVTMDT : public SV {
private:
    float diem;

public:
    SVTMDT() {}
    void nhap() override;
    void xuat() const override;
    bool operator<(const SVTMDT &other) const;
};

void SVTMDT::nhap() {
    SV::nhap();
    cout << "Nhap diem kinh doanh online: ";
    cin >> diem;
    cin.ignore();
}

void SVTMDT::xuat() const {
    SV::xuat();
    cout << ", Diem: " << diem << endl;
}

bool SVTMDT::operator<(const SVTMDT &other) const {
    return diem < other.diem;
}

int main() {
    SV sv;
    cout << "Nhap thong tin sinh vien:\n";
    sv.nhap();
    
    cout << "\nThong tin sinh vien:\n";
    sv.xuat();
    cout << endl;

    int n;
    cout << "\nNhap so luong sinh vien TMDT: ";
    cin >> n;
    cin.ignore();
    vector<SVTMDT> danhSachSV(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien TMDT thu " << i + 1 << ":\n";
        danhSachSV[i].nhap();
    }

    cout << "\nDanh sach sinh vien TMDT:\n";
    for (const auto &sv : danhSachSV) {
        sv.xuat();
    }

    sort(danhSachSV.rbegin(), danhSachSV.rend());
    cout << "\nDanh sach sinh vien TMDT sau khi sap xep theo diem giam dan:\n";
    for (const auto &sv : danhSachSV) {
        sv.xuat();
    }

    return 0;
}


#include <iostream>
#include <string>

using namespace std;

class Vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    int giave;

public:
    Vemaybay(string tenchuyen = "", string ngaybay = "", int giave = 0)
    {
        this->tenchuyen = tenchuyen;
        this->ngaybay = ngaybay;
        this->giave = giave;
    }

    ~Vemaybay()
    {
        this->tenchuyen = "";
        this->ngaybay = "";
        this->giave = 0;
    }

    void Nhap()
    {
        cout << "Nhap ten chuyen: ";
        getline(cin, this->tenchuyen);
        cout << "Nhap ngay bay: ";
        getline(cin, this->ngaybay);
        cout << "Nhap gia ve: ";
        cin >> this->giave;
        cin.ignore();
    }

    void Xuat() const
    {
        cout << "Chuyen bay: " << this->tenchuyen << "\n"
             << "Ngay bay: " << this->ngaybay << "\n"
             << "Gia ve: " << this->giave << "\n";
    }

    int getGiave() const
    {
        return this->giave;
    }
};

class Nguoi
{
private:
    string ten;
    string gioitinh;
    int tuoi;

public:
    Nguoi(string ten = "", string gioitinh = "", int tuoi = 0)
    {
        this->ten = ten;
        this->gioitinh = gioitinh;
        this->tuoi = tuoi;
    }

    ~Nguoi()
    {
        this->ten = "";
        this->gioitinh = "";
        this->tuoi = 0;
    }

    void Nhap()
    {
        cout << "Nhap ten: ";
        getline(cin, this->ten);
        cout << "Nhap gioi tinh: ";
        getline(cin, this->gioitinh);
        cout << "Nhap tuoi: ";
        cin >> this->tuoi;
        cin.ignore();
    }

    void Xuat() const
    {
        cout << "Ten: " << this->ten << "\n"
             << "Gioi tinh: " << this->gioitinh << "\n"
             << "Tuoi: " << this->tuoi << "\n";
    }
};

class hanhkhach : public Nguoi
{
private:
    Vemaybay *ve;
    int soluong;

public:
    hanhkhach(string ten, string gioitinh, int tuoi, Vemaybay *ve, int soluong) : Nguoi(ten, gioitinh, tuoi)
    {
        this->ve = ve;
        this->soluong = soluong;
    }

    ~hanhkhach()
    {
        delete ve;
        this->soluong = 0;
    }

    void Nhap()
    {
        Nguoi::Nhap();
        ve = new Vemaybay();
        ve->Nhap();
        cout << "Nhap so luong: ";
        cin >> this->soluong;
        cin.ignore();
    }

    void Xuat() const
    {
        Nguoi::Xuat();
        ve->Xuat();
        cout << "So luong: " << this->soluong << "\n";
    }

    int getTongtien() const
    {
        return this->soluong * ve->getGiave();
    }
};

int main()
{
    int n;
    cout << "Nhap so hanh khach: ";
    cin >> n;
    cin.ignore();

    hanhkhach **arr = new hanhkhach *[n];
    for (int i = 0; i < n; i++)
    {
        string ten, gioitinh;
        int tuoi;
        Vemaybay *ve = nullptr;
        int soluong;
        arr[i] = new hanhkhach(ten, gioitinh, tuoi, ve, soluong);
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":\n";
        arr[i]->Nhap();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin hanh khach thu " << i + 1 << ":\n";
        arr[i]->Xuat();
    }

    return 0;
}
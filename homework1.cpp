#include <iostream>
#include <vector>

using namespace std;

class Student{
    string name, sname;
    int album_number;
    vector<float> grades;
public:
    void setname(const string &nname){
        name = nname;
    }
    void setsname(const string &nsname){
        sname = nsname;
    }
    void setalbum(const int &nalbum_number){
        if (nalbum_number >= 10000 && nalbum_number <= 999999) {
            album_number = nalbum_number;
        } else {
            cout << "Invalid album number." << endl;
        }
    }
    void print_student(){
        cout << name << " " << sname << " "<< album_number << " " << endl;
        for(const auto &grade:grades){
            cout << grade << " , ";
        }
        cout << endl;
    }
    bool add_grade(float grade){
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }
    void mean_grade(){
        int sum = 0, avg = 0, count = 0;
        for(const auto &grade:grades){
            sum += grade;
            count++;
        }
        avg = sum/count;
        cout << avg << endl;
    }
    bool pass(){
        int count = 0;
        for(const auto &grade:grades){
            if(grade == 2.0){
                count++;
            }
        }
        if (count > 1){
            cout << "you are failing" << endl;
            return false;
        }else{
            cout << "you are passing" << endl;
            return true;
        }
    }
};

class Complex{
    float real, imaginary;
public:
    Complex(){real = 0; imaginary = 0;}
    Complex(const float &nreal){
        real = nreal;
    }
    Complex(const float &nreal, const float &nimaginary){
        real = nreal;
        imaginary = nimaginary;
    }
    void set_re(const float &nreal){
        this->real = nreal;
    }
    void set_im(const float &nimaginary){
        this->imaginary = nimaginary;
    }
    void print(){
        if(imaginary < 0)
            cout << real << imaginary << "i " << endl;
        else
            cout << real << "+" <<imaginary << "i " << endl;
    }
    Complex add(const Complex &x){
        Complex a;
        a.real = this->real + x.real;
        a.imaginary = this->imaginary + x.imaginary;
        return a;
    }
};

int main()
{
    Student s;
    s.setname("John");
    s.setsname("Meyers");
    s.setalbum(1234844);
    s.setalbum(1803807633);
    s.setalbum(124456);
    s.add_grade(7);
    s.add_grade(3);
    s.add_grade(4.5);
    s.add_grade(2);
    s.add_grade(3.5);
    s.add_grade(9);
    s.add_grade(3.5);
    s.add_grade(5);
    s.add_grade(2);
    s.print_student();
    s.mean_grade();
    s.pass();

    Complex c(4.77);
    Complex a(1.9, -3);
    c.set_im(-4);
    c.print();
    a.print();
    Complex b = c.add(a);
    b.print();

    return 0;
}
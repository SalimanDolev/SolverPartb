#include "solver.hpp"
#include <iostream>
#include <math.h> 

using namespace std;
namespace solver{
          RealVariable operator*(RealVariable x, RealVariable y){
              if (x.strong >1 && y.strong >1) throw out_of_range("Cant handle greater than quadratic");

              RealVariable temp;
              if(x.coefficient !=0 && x.freeMember!=0 
              && y.coefficient !=0 && y.freeMember !=0){
                  temp.quad_coefficient = x.coefficient * y.coefficient;
                  temp.coefficient = x.coefficient * y.freeMember + y.freeMember * x.freeMember;
                  temp.strong =2;
              }
              else if(x.coefficient !=0 && x.freeMember ==0 
              && y.coefficient !=0 && y.freeMember !=0){
                  temp.quad_coefficient = x.coefficient * y.coefficient;
                  temp.strong = 2;
                  temp.coefficient = x.coefficient * y.freeMember;
                  temp.freeMember =0;

              }else if(x.coefficient !=0 && x.freeMember !=0 
              && y.coefficient !=0 && y.freeMember ==0){
                  temp.quad_coefficient = x.coefficient * y.coefficient;
                  temp.strong =2;
                  temp.coefficient = y.coefficient * x.freeMember;
                  temp.freeMember =0;
              }
              else if(x.coefficient !=0 && y.coefficient !=0 
                    &&x.freeMember == 0 && y.freeMember ==0){
                        temp.quad_coefficient = x.coefficient * y.coefficient;
                        temp.strong = 2;
                        temp.coefficient = 0;
                        temp.freeMember =0;
                    }
              return temp;
            }

          RealVariable operator*(RealVariable x, double y){
              x.quad_coefficient =x.quad_coefficient * y;
              x.coefficient = x.coefficient * y;
              x.freeMember = x.freeMember * y;
              return x;
            }

          RealVariable operator*(double y,RealVariable x){
              RealVariable temp;
              temp.coefficient = x.coefficient * y;
              temp.freeMember = x.freeMember *y;
              if(x.strong == 2){
                temp.quad_coefficient = x.quad_coefficient * y;
                temp.strong = x.strong;              
              }
              return temp;
            }

          RealVariable operator==(RealVariable x, double y){
              x.freeMember = x.freeMember + (-1*y);

              return x;
              }
          RealVariable operator==(RealVariable x, RealVariable y){
              x.quad_coefficient = x.quad_coefficient - y.quad_coefficient;
              x.coefficient = x.coefficient - y.coefficient;
              x.freeMember = x.freeMember + -1*y.freeMember;
              return x;
              }
          RealVariable operator^(RealVariable x, double y){
              RealVariable temp;
              if (y == 2 ){
                  
                  temp.quad_coefficient = (x.quad_coefficient + 1);
                  if(x.coefficient == 1 && x.freeMember == 0 ){  
                  temp.coefficient = 0;
                  temp.strong =2;
                  }

                  return temp;
              }
              else throw out_of_range ("Cant handle bigger than qaudratic");
              }
          
          RealVariable operator+(RealVariable x, double y){
              RealVariable temp;
              temp.quad_coefficient = x.quad_coefficient;
              temp.coefficient = x.coefficient;
              temp.strong = x.strong;
              temp.freeMember += y;
              return temp;
              }
          
          RealVariable operator+(RealVariable x, RealVariable y){
              RealVariable temp; 
              temp.coefficient = x.coefficient + y.coefficient;
              temp.freeMember = x.freeMember + y.freeMember;
              if(x.strong >1 || y.strong >1){
              temp.strong =2;
              temp.quad_coefficient =x.quad_coefficient + y.quad_coefficient;
              }
              return temp;
              }

          RealVariable operator+(double y,RealVariable x){
              RealVariable temp;
              temp.coefficient=x.coefficient;
              temp.freeMember = x.freeMember +y;
              temp.quad_coefficient = x.quad_coefficient;
              temp.strong = x.strong; 
              return temp;
              }

          RealVariable operator-(RealVariable x, double y){
              RealVariable temp;
              temp.coefficient = x.coefficient;
              temp.quad_coefficient = x.quad_coefficient;
              temp.freeMember = x.freeMember - y;
              temp.strong = x.strong;
              return temp;
              }

          RealVariable operator-(RealVariable x, RealVariable y){
              x.coefficient = x.coefficient - y.coefficient;
              x.freeMember = x.freeMember - y.freeMember;
              x.quad_coefficient = x.quad_coefficient - y.quad_coefficient;
              return x;
              }

          RealVariable operator-(double y,RealVariable x){return x;}

          RealVariable operator/(RealVariable x, double y){
              if (y !=0){
              x.coefficient = x.coefficient / y;
              x.freeMember = x.freeMember / y;
              if (x.strong == 2){
              x.quad_coefficient =x.quad_coefficient / y;
              }
              return x;
              }else {throw out_of_range ("Cant divide with 0");}
          }

          RealVariable operator/(RealVariable x, RealVariable y){return x;}
         

          RealVariable nullify(RealVariable x){
              x.coefficient = 1.0;
              x.freeMember = 0.0;
              x.strong = 1.0;
              return x;
          }

            double solve(RealVariable x){
              RealVariable temp(x);
              nullify(x);
              
              if (temp.getStrong() == 1){
                   if(temp.getCoefficient()!=0){
                        return (-1*temp.getFreeMember()/temp.getCoefficient());
                   }else { throw out_of_range ("Cant divide with 0");}
              }

              if (temp.getStrong() == 2 && temp.getFreeMember() < 0 &&
                  temp.getCoefficient() == 0 && temp.getQuad_coff() !=0){
                  return sqrt((-1*temp.getFreeMember()/temp.getQuad_coff()));
              }

              if(temp.getStrong()==2 && temp.getFreeMember() != 0 &&
                 temp.getCoefficient() !=0 && temp.getQuad_coff()!=0){
                     return ((-1.0*temp.getCoefficient() + (sqrt(pow(temp.getCoefficient(),2) - 4.0*temp.getQuad_coff()*temp.getFreeMember()))) 
                                                                / (2*temp.getQuad_coff()));
                 }
                
              if(temp.getStrong() ==2 && temp.getQuad_coff()!=0 && temp.getCoefficient() !=0
                 && temp.getFreeMember() == 0 ){
                     return ((-1.0*temp.getCoefficient() + (sqrt(pow(temp.getCoefficient(),2) - 4.0*temp.getQuad_coff()*temp.getFreeMember()))) 
                                                                / (2*temp.getQuad_coff()));
                 }
                
              else throw out_of_range ("There is no real solution"); 
            }


          



          ComplexVariable operator*(ComplexVariable x, ComplexVariable y){
              ComplexVariable temp;

              return x;
              }
          ComplexVariable operator*(complex<double> x, ComplexVariable y){
              ComplexVariable temp;
              temp.coefficient = y.coefficient * x;
              temp.freeMember = y.freeMember * x;
              if(y.strong ==2){
                  temp.strong =2;
                  temp.quad_coefficient = y.quad_coefficient * x;
              }
              return temp;
              }
          ComplexVariable operator*(ComplexVariable x, double y){
              ComplexVariable temp;
              temp.coefficient = x.coefficient * y;
              temp.freeMember = x.freeMember * y;
              if(x.strong ==2){
                  temp.strong =2;
                  temp.quad_coefficient = x.quad_coefficient * y;
              }
              temp.strong = 1;
              return temp;
              }
          ComplexVariable operator*(double y,ComplexVariable x){
              ComplexVariable temp;
              temp.coefficient = x.coefficient * y;
              temp.freeMember = x.freeMember * y;
              if(x.strong ==2){
                  temp.strong =2;
                  temp.quad_coefficient = x.quad_coefficient * y;
              }
              else {temp.strong = 1;}
              return temp;
              }
              
          
          ComplexVariable operator==(ComplexVariable x, double y){
              ComplexVariable temp;
              temp.freeMember = x.freeMember -1*y;
              temp.quad_coefficient = x.quad_coefficient;
              temp.strong = x.strong;
              temp.coefficient = x.coefficient;
              return temp;
              }

          ComplexVariable operator==(ComplexVariable x, ComplexVariable y){
              ComplexVariable temp;
              temp.quad_coefficient = x.quad_coefficient - y.quad_coefficient;
              temp.coefficient = x.coefficient - y.coefficient;
              temp.freeMember = x.freeMember - y.freeMember;
              x.strong > y.strong ? temp.strong=x.strong : temp.strong = y.strong; 
              return temp;
              }
          
          ComplexVariable operator==(ComplexVariable x, complex<double> y){
              
              return x;
              }
          
          ComplexVariable operator^(ComplexVariable x, double y){
              ComplexVariable temp;
              if(y == 2){
                  temp.strong = y;
                  temp.quad_coefficient = x.coefficient * x.coefficient;
              }
              temp.freeMember = x.freeMember * x.freeMember;
              temp.coefficient = (0.0);
              return temp;
              }

          ComplexVariable operator^(ComplexVariable x, ComplexVariable y){return x;}
          ComplexVariable operator+(ComplexVariable x, double y){
              ComplexVariable temp;
              temp.quad_coefficient = x.quad_coefficient;
              temp.strong = x.strong;
              temp.coefficient = x.coefficient;
              temp.freeMember = x.freeMember + y;
              return temp;
              }
          ComplexVariable operator+(double y,ComplexVariable x){
              ComplexVariable temp;
              temp.coefficient = x.coefficient;
              temp.freeMember = x.freeMember + y;
              temp.quad_coefficient = x.quad_coefficient;
              temp.strong = x.strong;
              return temp;
              }
          ComplexVariable operator+(ComplexVariable x, ComplexVariable y){
              ComplexVariable temp;
              temp.coefficient = x.coefficient + y.coefficient;
              temp.freeMember = x.freeMember + y.freeMember;
              temp.quad_coefficient = x.quad_coefficient + y.quad_coefficient;
              temp.strong = x.strong>y.strong ? x.strong:y.strong;
              return temp;
              }
          ComplexVariable operator+(ComplexVariable x, complex<double> y){
              ComplexVariable temp;
              temp.freeMember = x.freeMember + y;
              temp.quad_coefficient = x.quad_coefficient;
              temp.strong = x.strong;
              temp.coefficient = x.coefficient;
              return temp;
              }
          ComplexVariable operator-(ComplexVariable x, double y){
              ComplexVariable temp;
              temp.coefficient = x.coefficient;
              temp.quad_coefficient = x.quad_coefficient;
              temp.freeMember = x.freeMember - y;
              temp.strong = x.strong;
              return temp;
              }
          ComplexVariable operator-(ComplexVariable x, ComplexVariable y){
              ComplexVariable temp;
              temp.coefficient = x.coefficient - y.coefficient;
              temp.freeMember = x.freeMember - y.freeMember;
              temp.quad_coefficient = x.quad_coefficient - y.quad_coefficient;
              temp.strong = x.strong > y.strong ? x.strong : y.strong;
              return temp;
              }
          ComplexVariable operator-(ComplexVariable x, complex<double> y){return x;}
          ComplexVariable operator/(ComplexVariable x, double y){
              ComplexVariable temp;
              temp.quad_coefficient = x.quad_coefficient / y;
              temp.coefficient = x.coefficient / y;
              temp.freeMember = x.freeMember /y;
              temp.strong = x.strong;
              return temp;
              }
          ComplexVariable operator/(ComplexVariable x, ComplexVariable y){return x;}

          ComplexVariable nullifyComplex(ComplexVariable x){
              ComplexVariable temp;
              temp.coefficient = (1.0,0.0);
              temp.freeMember = (0.0,0.0);
              temp.quad_coefficient = (0.0,0.0);
              temp.strong = 1;
              return temp;
          }

          std::complex<double> solve(ComplexVariable x){
            ComplexVariable temp(x);
            cout <<temp.getQuadCoff().real() << " "   << temp.getCoff().real() << " " << temp.Strong()<< " "<< temp.getFreeMember().real()<<endl;
            cout << temp.getCoff().imag() << " " << temp.Strong()<< " "<< temp.getFreeMember().imag()<<endl;
            nullifyComplex(x);
            if(temp.getQuadCoff().real() != 0 && temp.Strong() ==2 && temp.getCoff().real() == 0
            && temp.getFreeMember().real() > 0){
                 return complex<double>(0.0,sqrt(temp.getFreeMember().real() / temp.getQuadCoff().real()));
            }
            if (temp.Strong() == 1 && temp.getCoff().real()!=0  
             && temp.getFreeMember().real() !=0){ 
                 return complex<double>(-1.0*temp.getFreeMember() /temp.getCoff());// ,
                         //-1.0*temp.getFreeMember().imag() / temp.getCoff().imag());
            }
            if (temp.Strong() == 1 && temp.getCoff().real()!=0  
             && temp.getFreeMember().imag() !=0){ 
                 return complex<double>( -1.0*temp.getFreeMember() /temp.getCoff());// ,
                         //-1.0*temp.getFreeMember().imag() / temp.getCoff().imag());
            }   
            if (temp.Strong() == 2 && temp.getQuadCoff().real()!=0  
             && temp.getFreeMember().real() < 0){ 
                 return complex<double>(sqrt(-1.0* temp.getFreeMember() / temp.getQuadCoff()));
            }
            if (temp.Strong() == 2 && temp.getQuadCoff().real()!=0  
             && temp.getFreeMember().real() > 0){
                 cout<< sqrt(temp.getFreeMember() / temp.getQuadCoff()) << endl;
                 return complex<double>(sqrt(temp.getFreeMember() / temp.getQuadCoff()));
            }
            else {
                throw out_of_range("There is no real sulotion");
            }
          }
};
//}
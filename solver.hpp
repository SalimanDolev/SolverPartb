#include <iostream>
#include <complex>

using namespace std;


namespace solver
{
    class RealVariable{
        private:
        double coefficient;
        double freeMember;
        double strong;
        double quad_coefficient;
        public:
        RealVariable():coefficient(1), freeMember(0), strong(1),quad_coefficient(0){};
        RealVariable(double cof, double free, double stro,double quad_coeff):coefficient(cof), freeMember(free), strong(stro),quad_coefficient(quad_coeff){};
        RealVariable(const RealVariable& x):RealVariable(x.coefficient,x.freeMember,x.strong,x.quad_coefficient){};
        
        double getQuad_coff(){
          return (*this).quad_coefficient;
        }
        double getCoefficient(){
          return (*this).coefficient;
        }
        double getFreeMember(){
          return (*this).freeMember;
        }
        double getStrong(){
          return (*this).strong;
        }
          friend RealVariable operator*(RealVariable x, RealVariable y);
          friend RealVariable operator*(RealVariable x, double y);
          friend RealVariable operator*(double y,RealVariable x);
          friend RealVariable operator==(RealVariable x, double y);
          friend RealVariable operator==(RealVariable x, RealVariable y);
          friend RealVariable operator^(RealVariable x, double y);
          friend RealVariable operator^(RealVariable x, RealVariable y);
          friend RealVariable operator+(RealVariable x, double y);
          friend RealVariable operator+(RealVariable x, RealVariable y);
          friend RealVariable operator+(double y,RealVariable x);
          friend RealVariable operator-(RealVariable x, double y);
          friend RealVariable operator-(RealVariable x, RealVariable y);
          friend RealVariable operator-(double y,RealVariable x);
          friend RealVariable operator/(RealVariable x, double y);
          friend RealVariable operator/(RealVariable x, RealVariable y);
          
        
          friend RealVariable nullify(RealVariable x);
        
    };  
        



    class ComplexVariable{
        private:
        complex<double> coefficient;
        complex<double> freeMember;
        double strong;
        complex<double> quad_coefficient;
        public:
          ComplexVariable():coefficient(1.0,0.0),freeMember(0.0,0.0),quad_coefficient(0.0,0.0),strong(1){};
          ComplexVariable(const ComplexVariable& x):coefficient(x.coefficient),freeMember(x.freeMember),strong(x.strong),quad_coefficient(x.quad_coefficient){};
          complex<double> getCoff(){
            return (*this).coefficient;
          }
          complex<double> getFreeMember(){
            return (*this).freeMember;
          }
          double Strong(){
            return (*this).strong;
          }
          complex<double> getQuadCoff(){
            return (*this).quad_coefficient;
          }


          friend ComplexVariable operator*(ComplexVariable x, ComplexVariable y);
          friend ComplexVariable operator*(complex<double> x, ComplexVariable y);
          friend ComplexVariable operator*(ComplexVariable x, double y);
          friend ComplexVariable operator*(double y,ComplexVariable x);
          friend ComplexVariable operator==(ComplexVariable x, double y);
          friend ComplexVariable operator==(ComplexVariable x, ComplexVariable y);
          friend ComplexVariable operator==(ComplexVariable x, complex<double> y);
          friend ComplexVariable operator^(ComplexVariable x, double y);
          friend ComplexVariable operator^(ComplexVariable x, ComplexVariable y);
          friend ComplexVariable operator+(ComplexVariable x, double y);
          friend ComplexVariable operator+(double y,ComplexVariable x);
          friend ComplexVariable operator+(ComplexVariable x, ComplexVariable y);
          friend ComplexVariable operator+(ComplexVariable x, complex<double> y);
          friend ComplexVariable operator+(double x, complex<double> y);
          friend ComplexVariable operator-(ComplexVariable x, double y);
          friend ComplexVariable operator-(ComplexVariable x, ComplexVariable y);
          friend ComplexVariable operator-(ComplexVariable x, complex<double> y);
          friend ComplexVariable operator/(ComplexVariable x, double y);
          friend ComplexVariable operator/(ComplexVariable x, ComplexVariable y);

          friend ComplexVariable nullifyComplex(ComplexVariable x);
          
    };


   double solve(RealVariable);
   std::complex<double> solve(ComplexVariable);
   

    
    } // namespace solver

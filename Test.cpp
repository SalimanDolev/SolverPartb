#include "doctest.h"
#include "solver.hpp"
using namespace solver;
#include <string>
using namespace std;


/////////////////////////////////////////////////////////////////////
////////////////////////Equation solver//////////////////////////////
/////////////////////////////////////////////////////////////////////
/**
TEST_CASE("Real variable * / + - ^") {
    RealVariable x;
    CHECK(solve(7*x == 7) == 1);
    CHECK(solve(5*x == 10) == 2);
    CHECK(solve(2*x - 1*x == 10) == 10);
    CHECK(solve(2*x - 3*x == 20) == -20);
    CHECK(solve(1*x + 1*x == 4) == 2);
    CHECK(solve(x + 2*x == 6) == 2);
    CHECK(solve(1*x/2 + 1*x/2 == 6) == 6);
    CHECK(solve(1*x/4 + 3*x/4 == 2) == 2);
    CHECK(solve(4*x - 3*x == 6) == 6);
    CHECK(solve((x^2) == 16) == 4);
    CHECK(solve((x^2) == 36) == 6);
}

TEST_CASE("Real variable equations") {
    RealVariable x;
    CHECK(solve(x == 7) == 7);
    CHECK(solve(x == 11) == 11);
    CHECK(solve(x == 150) == 150);
    CHECK(solve(2*x == 20) == 20);
    CHECK(solve(3*x == 150) == 50);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve(x/2 == 6) == 12);
    CHECK(solve(2*x/4 == 60) == 120);
    CHECK(solve(3*x + 5 == 20) == 5);
    CHECK(solve(3*x + 5  - 5 == 30) == 10);
    CHECK(solve(3*x + 5 == 20) == 5);
    CHECK(solve(23.4*x+234.54 == 53.54+435.4*x) == 0.4393204 );
	CHECK(solve(12+5.1*x == 5*x+2) == -100.0 );
	CHECK(solve(3*x+4 == x/3) == -1.5 );
	CHECK(solve(x == 0.5*x) == 0 );
	CHECK(solve(23*x+1 == 3*x-1) == -0.1 );
	CHECK(solve(34*x/1.55-5 == 20*x) == 2.5833333333 );
	CHECK(solve(12.5+2.0*x/0.5 == 41-5.5*x/5) == 2.567567568 );
	CHECK(solve(-2*x+5 == 4*x-1.6) == 1.1 );
	CHECK(solve(1.23*x-8.4 == -0.77*x) == 4.2 );
}

TEST_CASE("Real veriables X^2 equations"){
    RealVariable x;
    CHECK(solve((x^2) + 2*x + 1 == 0) == -1.0 );
    CHECK(solve((x^2) -2*x + 1 == 0) == 1.0 );
    CHECK(solve((x^2)  == 4) == 2.0);
    CHECK((solve((x^2)  == 9) == 3 || solve((x^2)  == 9) == -3));
    CHECK((solve((x^2) + 16 == 0) == 4 || solve((x^2) + 16  == 0) == -4));
    CHECK((solve((x^2) - 6*x + 9  == 0 == 3) || solve((x^2) - 6*x + 9  == 0) == -3));
    CHECK((solve((x^2) + 16 == 0) == 4 || solve((x^2) + 16  == 0) == -4));
    CHECK((solve(2*(x^2) -4*x - 6 == 0) == -1 || solve(2*(x^2) -4*x - 6 == 0) == 3));
    CHECK((solve(2*(x^2) -4*x == 0) == 0 || solve(2*(x^2) -4*x == 0) == 2));
    CHECK((solve((3*x^2) +6*x == 0) == 0 || solve((3*x^2) + 6*x == 0) == 2));
    CHECK((solve((x^2) - x == 0) == 1 || solve((x^2) - x == 0) == 0));
    CHECK((solve((x^2) == 9) == 3 || solve((x^2) == 9) == -3));   
    
}

TEST_CASE("Complex variable * / + - ^") {
    ComplexVariable x;
    CHECK(solve(7*x == 7) == std::complex<double>(7.0, 0.0));
    CHECK(solve(1i*x == 1i) == std::complex<double>(1.0, 0.0));
    CHECK(solve(2i*x - 1i*x == 1i) == std::complex<double>(1.0, 0.0));
    CHECK(solve(2*x -4i+5.0 == 4i - 5.0) == -std::complex<double>(-10.0, 8.0));
    CHECK(solve(1i*x + 1i*x == 4i) == std::complex<double>(2.0, 0.0));
    CHECK(solve(1i*x + 2i*x == 6i) == std::complex<double>(2.0, 0.0));
    CHECK(solve(1i*x/2 + 1i*x/2 == 6i) == std::complex<double>(6.0, 0.0));
    CHECK(solve(1i*x/4 + 3i*x/4 == 2i) == std::complex<double>(2.0, 0.0));
    CHECK(solve(4i*x - 3i*x == 6i) == std::complex<double>(6.0, 0.0));
    CHECK(solve(1i*(x^2) == 16i) == std::complex<double>(4.0, 0.0));
    CHECK(solve(1i*(x^2) == 36i) == std::complex<double>(6.0, 0.0));
}

TEST_CASE("Complex variable equations") {
    ComplexVariable y;
    CHECK(solve(2*y-4.0 == 10.0) == std::complex<double>(7.0, 0.0));
    CHECK(solve(2*y == 10.0) == std::complex<double>(5.0,0.0));
    CHECK(solve(2*y == 6.0) == std::complex<double>(3.0,0.0));
    CHECK(solve(2*y + 2i == 3i) == std::complex<double>(0.0,0.5));
    CHECK(solve(y + 2i == 3.0) == std::complex<double>(3.0,-2.0));
    CHECK(solve(y + 2i == 3i + 5i) == std::complex<double>(0.0,6.0));
    CHECK(solve(y + 2i == 10i) == std::complex<double>(0.0,8.0));
    CHECK(solve(y + 2.0 == 3i) == std::complex<double>(-2.0,3.0));
    CHECK(solve(y + 2.0 + 1i == 3i + 5.0) == std::complex<double>(3.0,2.0));
    CHECK(solve(y + 2.0 + 4i == 10i + 50.0) == std::complex<double>(48.0,6.0));
    CHECK(solve(12.0 + 5.1*y == 5.0*y + 2.0) == std::complex<double>(-100.0,0.0) );
	CHECK(solve(17.0*(y^2) == 17.0 ) == std::complex<double>(-1.0,0.0));
	CHECK(solve((y*2.0) + 5.0 == 30.0 ) ==  std::complex<double>(5.0,0.0));
	CHECK(solve(3.0*(y^2) - 6.0*y + 1i == 9.0 ) ==  std::complex<double>(3.0,-1.0));
	CHECK(solve(4.0*(y^2) / 2.0 == 12.0*y^2.0 /4.0 ) ==  std::complex<double>(0.0,0.0));
	CHECK(solve(4.0*(y^2) == -16.0*(y^2)/4.0 ) ==  std::complex<double>(0.0,0.0) );
	CHECK(solve(5.0+3.0*(y^2) == 8.0*y ) ==  std::complex<double>(1.0,0.0) );
	CHECK(solve(3.0*(y^2)-4.0*y == 0 ) ==  std::complex<double>(1.0,0.0));
	CHECK(solve(-4.0*y+12.0 == 8.0*(y^2)  ) ==  std::complex<double>(1.0,0.0));
}



TEST_CASE("Complex variable X^2 equations") {
    ComplexVariable y;
    CHECK(solve(y + 3i * (6.0 -5i) == 0) == std::complex<double>(15.0,18.0));
    CHECK(solve((y^2) + (1.0 - 1i) * y - 1i == 0) == std::complex<double>(-1.0,0.0));
    CHECK(solve((y^2) + (2.0i-3.0)*y +2 - 4i == 0) == std::complex<double>(1.0,0.0));
    
}

TEST_CASE("Real variables error massages"){
    RealVariable x;
    CHECK_THROWS(solve((x^2) == -16));
    CHECK_THROWS(solve((x^3) == 8));
    CHECK_THROWS(solve((x^4) == 16));
    CHECK_THROWS(solve((x/0) == 1));
    RealVariable y;
    CHECK_THROWS(solve(x + y == 1));
    CHECK_THROWS(solve(x * y == 1));
    CHECK_THROWS(solve(x / y == 1));
    CHECK_THROWS(solve((x ^ y) == 1));
    CHECK_THROWS(solve(x == y));
    CHECK_THROWS(solve(2*x == 2*y));
    CHECK_THROWS(solve((x/2) == (y/2)));

}

TEST_CASE("complex variables error massages"){
    ComplexVariable x;
    CHECK_THROWS(solve((x^2.0) == 1i));
    CHECK_THROWS(solve((x^3.0) == 10i + 5.0));
    CHECK_THROWS(solve((x^4) == 16));
    CHECK_THROWS(solve((x/0) == 1));
    CHECK_THROWS(solve((x*0) == 1));
    CHECK_THROWS(solve(x-x == 1));
    ComplexVariable y;
    CHECK_THROWS(solve(x + y == 1));
    CHECK_THROWS(solve(x * y == 1));
    CHECK_THROWS(solve(x / y == 1));
    CHECK_THROWS(solve((x ^ y) == 1));
    CHECK_THROWS(solve(x == y));
    CHECK_THROWS(solve(2*x == 2*y));
    CHECK_THROWS(solve(x/2 == y/2));

}
**/

TEST_CASE("Test") 
{
 RealVariable x;


     CHECK(solve(2*x-4 == 10) ==7);
     CHECK(solve(3*x-5 == 1) ==2);
     CHECK(solve(4*x-4 == 16) ==5);
     CHECK(solve(2*x-4 == 10) ==7);
     CHECK(solve(5*x-6 == 14) ==4);
     CHECK(solve(1*x-4 == 3) ==7);
     CHECK(solve(5*x-4 == 36) ==8);
     CHECK(solve(2*x-3 == 15) ==9);
     CHECK(solve(5*x-2 == 8) ==2);
     CHECK(solve(5*x-3 == 2) ==1);

     CHECK(solve(3*x-1 == 2) ==1);
     CHECK(solve(3*x-2 == 4) ==2);
     CHECK(solve(4*x-1 == 3) ==1);
     CHECK(solve(4*x-2 == 6) ==2);
     CHECK(solve(5*x-1 == 4) ==1);
     CHECK(solve(5*x-2 == 8) ==2);
     CHECK(solve(6*x-1 == 5) ==1);
     CHECK(solve(6*x-2 == 10) ==2);
     CHECK(solve(7*x-1 == 6) ==1);
     CHECK(solve(7*x-2 == 12) ==2);

     CHECK(solve(3*x-3 == 6) ==3);
     CHECK(solve(3*x-4 == 5) ==3);
     CHECK(solve(4*x-3 == 9) ==3);
     CHECK(solve(4*x-4 == 8) ==3);
     CHECK(solve(5*x-3 == 12) ==3);
     CHECK(solve(5*x-4 == 11) ==3);
     CHECK(solve(6*x-3 == 15) ==3);
     CHECK(solve(6*x-4 == 14) ==3);
     CHECK(solve(7*x-3 == 18) ==3);
     CHECK(solve(7*x-4 == 17) ==3);

    
     CHECK(((solve((x^2) == 1) ==1) || (solve((x^2) == 1) ==-1))); 
     CHECK(((solve((x^2) == 4) ==2 )||( solve((x^2) == 4) ==-2)));
     CHECK(((solve((x^2) == 9) ==3) ||( solve((x^2) == 9) ==-3)));
     CHECK(((solve((x^2) == 16) ==4) || (solve((x^2) == 16) ==-4)));
     CHECK(((solve((x^2) == 25) ==5) || (solve((x^2) == 25) ==-5)));
     CHECK(((solve((x^2) == 36) ==6) || (solve((x^2) == 36) ==-6)));
     CHECK(((solve((x^2) == 49) ==7) || (solve((x^2) == 49) ==-7)));
     CHECK(((solve((x^2) == 64) ==8) || (solve((x^2) == 64) ==-8)));
     CHECK(((solve((x^2) == 81) ==9) || (solve((x^2) == 81) ==-9)));
     CHECK(((solve((x^2) == 100) ==10) || (solve((x^2) == 100) ==-10))); 

     CHECK(((solve((x^2) == 121) ==11) || (solve((x^2) == 121) ==-11))); 
     CHECK(((solve((x^2) == 1936) ==44) ||( solve((x^2) == 1936) ==-44)));
     CHECK(((solve((x^2) == 9801) ==99) || (solve((x^2) == 9801) ==-99)));
     CHECK(((solve((x^2) == 1089) ==33) || (solve((x^2) == 1089) ==-33)));
     CHECK(((solve((x^2) == 484) ==22) || (solve((x^2) == 484) ==-22)));
     CHECK(((solve((x^2) == 3025) ==55) || (solve((x^2) == 3025) ==-55)));
     CHECK(((solve((x^2) == 4356) ==66) || (solve((x^2) == 4356) ==-66)));
     CHECK(((solve((x^2) == 5929) ==77)|| (solve((x^2) == 5929) ==-77)));
     CHECK(((solve((x^2) == 7744) ==88) || (solve((x^2) == 7744) ==-88)));
     CHECK(((solve((x^2) == 12321) ==111) || (solve((x^2) == 12321) ==-111)));  

     CHECK(((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) ==4) ||(solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) ==-4)));   
     CHECK(((solve((x^2) + 3*x + 6.0 == 12 + 6.0*x/2 - x) ==2 )|| (solve((x^2) + 3*x + 6.0 == 12 + 6.0*x/2 - x) ==-3)));//16
     CHECK(((solve((x^2) + 2*x + 5.0 == 27 + 3.0*x/2 - x) ==4 )|| (solve((x^2) + 2*x + 5.0 == 27 + 3.0*x/2 - x) ==-5.5)));//29
     CHECK(((solve((x^2) + 5*x + 7.0 == 18 + 5.0*x/2 - x) ==2 )|| (solve((x^2) + 5*x + 7.0 == 18 + 5.0*x/2 - x) ==-5.5)));//21
     CHECK(((solve((x^2) + 5*x + 1.0 == 22 + 4.0*x/2 - x) ==3 )|| (solve((x^2) + 5*x + 1.0 == 22 + 4.0*x/2 - x) ==-7)));//25
     CHECK(((solve((x^2) + 9*x + 3.0 == 51 + 4.0*x/2 - x) ==4 )|| (solve((x^2) + 9*x + 3.0 == 51 + 4.0*x/2 - x) ==-12)));//55
     CHECK(((solve((x^2) + 1*x + 1.0 == 1 + 6.0*x/2 - x) ==1 )|| (solve((x^2) + 1*x + 1.0 == 1 + 6.0*x/2 - x) ==0)));//3
     CHECK(((solve((x^2) + 2*x + 8.0 == 33 + 6.0*x/2 - x) ==5 )|| (solve((x^2) + 2*x + 8.0 == 33 + 6.0*x/2 - x) ==-5)));//43
     CHECK(((solve((x^2) + 2*x + 5.0 == 41 + 6.0*x/2 - x) ==6 )|| (solve((x^2) + 2*x + 5.0 == 41 + 6.0*x/2 - x) ==-6)));//53
     CHECK(((solve((x^2) + 2*x + 10.0 == 16 + 4.0*x/2 - x) ==2 )||( solve((x^2) + 2*x + 10.0 == 16 + 4.0*x/2 - x) ==-3)));//18
     
     CHECK(((solve((x^2) + 1*x + 1.0 == 4 + 0.0*x/2 - x) ==1) ||( solve((x^2) + 1*x + 1.0 == 4 + 0.0*x/2 - x) ==-3)));//3   
     CHECK(((solve((x^2) + 1*x + 2.0 == 10 + 0.0*x/2 - x) ==2) ||( solve((x^2) + 1*x + 2.0 == 10 + 0.0*x/2 - x) ==-4)));//8
     CHECK(((solve((x^2) + 3*x + 3.0 == 24 + 0.0*x/2 - x) ==3 )|| (solve((x^2) + 3*x + 3.0 == 24 + 0.0*x/2 - x) ==-7)));//21
     CHECK(((solve((x^2) + 4*x + 4.0 == 40 + 0.0*x/2 - x) ==4 )|| (solve((x^2) + 4*x + 4.0 == 40 + 0.0*x/2 - x) ==-9)));//36
     CHECK(((solve((x^2) + 5*x + 5.0 == 60 + 0.0*x/2 - x) ==5 )|| (solve((x^2) + 5*x + 5.0 == 60 + 0.0*x/2 - x) ==-11)));//55
     CHECK(((solve((x^2) + 6*x + 6.0 == 84 + 0.0*x/2 - x) ==6 )|| (solve((x^2) + 6*x + 6.0 == 84 + 0.0*x/2 - x) ==-13)));//78
     CHECK(((solve((x^2) + 7*x + 7.0 == 112 + 0.0*x/2 - x) ==7 )|| (solve((x^2) + 7*x + 7.0 == 112 + 0.0*x/2 - x) ==-15)));//105
     CHECK(((solve((x^2) + 8*x + 8.0 == 144 + 0.0*x/2 - x) ==8 )|| (solve((x^2) + 8*x + 8.0 == 144 + 0.0*x/2 - x) ==-17)));//136
     CHECK(((solve((x^2) + 9*x + 9.0 == 180 + 0.0*x/2 - x) ==9 )|| (solve((x^2) + 9*x + 9.0 == 180 + 0.0*x/2 - x) ==-19)));//171
     CHECK(((solve((x^2) + 10*x + 10.0 == 220 + 0.0*x/2 - x) ==10 )|| (solve((x^2) + 10*x + 10.0 == 220 + 0.0*x/2 - x) ==-21)));//210
     
     
     CHECK(solve(2*x-4.0 == 10.0) ==7);
     CHECK(solve(3*x-5.0 == 1.0) ==2);
     CHECK(solve(4*x-4.0 == 16.0) ==5);
     CHECK(solve(2*x-4.0 == 10.0) ==7);
     CHECK(solve(5*x-6.0 == 14.0) ==4);
     CHECK(solve(1*x-4.0 == 3.0) ==7);
     CHECK(solve(5*x-4.0 == 36.0) ==8);
     CHECK(solve(2*x-3.0 == 15.0) ==9);
     CHECK(solve(5*x-2.0 == 8.0) ==2);
     CHECK(solve(5*x-3.0 == 2.0) ==1);

     CHECK(solve(3*x-1.0 == 2.0) ==1);
     CHECK(solve(3*x-2.0 == 4.0) ==2);
     CHECK(solve(4*x-1.0 == 3.0) ==1);
     CHECK(solve(4*x-2.0 == 6.0) ==2);
     CHECK(solve(5*x-1.0 == 4.0) ==1);
     CHECK(solve(5*x-2.0 == 8.0) ==2);
     CHECK(solve(6*x-1.0 == 5.0) ==1);
     CHECK(solve(6*x-2.0 == 10.0) ==2);
     CHECK(solve(7*x-1.0 == 6.0) ==1);
     CHECK(solve(7*x-2.0 == 12.0) ==2);

     CHECK_THROWS(solve(0*x==20));
     CHECK_THROWS(solve(2*x-2*x == 10));
     CHECK_THROWS(solve((x^2)==-4));
     CHECK_THROWS(solve((x^2) + 1*x + 1.0 == 4 + 6.0*x/0.0 - x));
     CHECK_THROWS(solve(3*0*x==45));
     CHECK_THROWS(solve(3*x-3*x+1*x-1*x==20));
     CHECK_THROWS(solve(x/0-0+0==20));
     CHECK_THROWS(solve(0*x+5.0==10));
     CHECK_THROWS(solve(0*x-7.0==30));
     CHECK_THROWS(solve(0*x+11==40));

     
}


TEST_CASE("simple equation") {
     RealVariable x;
     CHECK(solve(2*x==10)==5);
     CHECK(solve(-2*x==-10)==5);
     CHECK(solve(2*x==0)==0);
     CHECK(solve(8*x==0)==0);
     CHECK(solve(8*x/8==1)==1);
     CHECK(solve(3*x==90)==30);
     CHECK(solve(4*x+10==90)==20);
     CHECK(solve(4*x-10==90)==25);
     CHECK(solve(2*x+5==10)==2.5);
     CHECK(solve(2*x==9)==4.5);
     CHECK(solve(2*x==18)==9);
     CHECK(solve(4*x==36)==9);
     CHECK(solve(2*x==100)==50);
     CHECK(solve(x+5==20 )==15);
     CHECK(solve(x-20==-20 )==0);
     CHECK(solve(x-20==-5)==15);
     CHECK(solve(x+20==5)==-15);
     CHECK(solve(x+25==5)==-20);
     CHECK(solve(2*x== -4 )==-2);
     CHECK(solve(3*x+5==11)==2);
     CHECK(solve(2*x-4.0 == 10.0)==7);
     CHECK(solve(4*x/2-4.0 == 10.0)==7);
     CHECK(solve(4*x-4.0 == 36.0)==10);
     CHECK(solve(19*x==0)==0);
     CHECK(solve(8*x/2-4.0 == 36.0)==10);
     CHECK(solve(x==5)==5);
     CHECK(solve(x==20-10)==10);
     CHECK(solve(3*x+2==14)==4);
     CHECK(solve(3*x+4==16)==4);
     CHECK(solve(x+15==-8)==-23);
     CHECK(solve(6*x/2+2==14)==4);


}


TEST_CASE("test 2"){
    RealVariable x;
            CHECK((solve((x^2)==9)==3||solve((x^2)==9)==-3));
            CHECK((solve(2*(x^2)==18)==3||solve(2*(x^2)==18)==-3));
            CHECK((solve((x^2)+5==30)==5||solve((x^2)+5==30)==-5));
            CHECK(solve(2*x-2==4)==3);
            CHECK(((solve((x^2)==16)==4)||(solve((x^2)==16)==-4)));
            CHECK((solve((x^2)==25)==5 ||solve((x^2)==25)==-5));
            CHECK((solve((x^2)+2==18)==4||solve((x^2)+2==18)==-4));
            CHECK((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==4||solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==-4));
            CHECK((solve((x^2) + 2*x == 16 + 6.0*x/2 - x)==4||solve((x^2) + 2*x == 16 + 6.0*x/2 - x)==-4));
            CHECK((solve(2*(x^2)  == 32 )==4||solve(2*(x^2)  == 32 )==-4));
            CHECK((solve(3*(x^2)-15 == 60 )==5||solve(3*(x^2)-15 == 60 )==-5));
            CHECK((solve((x^2)==81)==9||solve((x^2)==81)==-9));
            CHECK((solve(2*(x^2)==162)==9||solve(2*(x^2)==162)==-9));
            CHECK((solve((x^2) + 2*x+5 == 21 + 6.0*x/2 - x)==4||solve((x^2) + 2*x+5 == 21 + 6.0*x/2 - x)==-4));
            CHECK(solve(3*(x^2)-30 == 45 )==5);
            CHECK((solve((x^2)==1)==1||solve((x^2)==1)==-1));// also -1
            CHECK((solve((x^2)==100)==10||solve((x^2)==100)==-10));
}

TEST_CASE("CHECK_THROWS"){
    RealVariable x;
    CHECK_THROWS(solve((x^2)==-100));
    CHECK_THROWS( solve((x^2)==-16));
    CHECK_THROWS( solve((x^2)==-1));
    CHECK_THROWS( solve(2*(x^2)==-16));
    CHECK_THROWS( solve(2*(x^2)==-100));
    CHECK_THROWS(solve((x^2)==-25));
    CHECK_THROWS(solve(2*(x^2)==-50));
    CHECK_THROWS(solve(2*(x^2)==-7));
    CHECK_THROWS(solve((x^2)==-9));
    CHECK_THROWS(solve((x^2)==-12));

}


TEST_CASE("test ComplexVariable"){

    ComplexVariable y;
    CHECK(solve(2*y-4 == 10)==std::complex<double>(7,0));
    CHECK(solve(y-4 == 10)==std::complex<double>(14,0));
   CHECK((solve((y^2) == 16)==std::complex<double>(4,0)||solve((y^2) == 16)==std::complex<double>(-4,0)));
     CHECK((solve((y^2) == -16)==std::complex<double>(0,4)||solve((y^2) == -16)==std::complex<double>(0,-4)));
    CHECK((solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(4,0)||solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y)==std::complex<double>(-4,0))); //(-4,0)
    CHECK((solve(y+5i == 2*y+3i)==std::complex<double>(0,2)||solve(y+5i == 2*y+3i)==std::complex<double>(0,-2)));
    CHECK((solve((y^2)==-100)==std::complex<double>(0,10)||solve((y^2)==-100)==std::complex<double>(0,-10)));
    CHECK((solve(2*(y^2)==-200)==std::complex<double>(0,10)||solve(2*(y^2)==-200)==std::complex<double>(0,-10)));
    CHECK((solve((y^2)==100)==std::complex<double>(10,0)||solve((y^2)==100)==std::complex<double>(-10,0)));
    CHECK((solve((y^2)==-25)==std::complex<double>(0,5)||solve((y^2)==-25)==std::complex<double>(0,-5)));
    CHECK((solve(2*(y^2)==-50)==std::complex<double>(0,5)||solve(2*(y^2)==-50)==std::complex<double>(0,-5)));
    CHECK((solve((y^2)==-9)==std::complex<double>(0,3)||solve((y^2)==-9)==std::complex<double>(0,-3)));
    CHECK((solve((y^2)==-81)==std::complex<double>(0,9)||solve((y^2)==-81)==std::complex<double>(0,-9)));
    CHECK((solve((y^2) + 3*y + 4 == 20 + 6*y/2 )==std::complex<double>(4,0)||solve((y^2) + 3*y + 4 == 20 + 6*y/2 )==std::complex<double>(-4,0))); //(-4,0)
    CHECK((solve((y^2) + 3*y == 16 + 3*y )==std::complex<double>(4,0)||solve((y^2) + 3*y == 16 + 3*y )==std::complex<double>(-4,0))); //(-4,0)
    CHECK((solve((y^2) + 6*y/2 == 16 + 9*y/3 )==std::complex<double>(4,0)||solve((y^2) + 6*y/2 == 16 + 9*y/3 )==std::complex<double>(-4,0))); //(-4,0)
    CHECK((solve((y^2)==9)==std::complex<double>(3,0)||solve((y^2)==9)==std::complex<double>(-3,0)));  //-3
    CHECK((solve((y^2)+5==30)==std::complex<double>(5,0)||solve((y^2)+5==30)==std::complex<double>(-5,0))); //-5
    CHECK((solve(2*y-2==4)==std::complex<double>(3,0)||solve(2*y-2==4)==std::complex<double>(-3,0)));   //-3
    CHECK((solve((y^2) == 16)==std::complex<double>(4,0)||solve((y^2) == 16)==std::complex<double>(-4,0))); //(-4,0)
    CHECK((solve((y^2)==25)==std::complex<double>(5,0)||solve((y^2)==25)==std::complex<double>(-5,0)));  //-5
    CHECK((solve((y^2)+2==18)==std::complex<double>(4,0)||solve((y^2)+2==18)==std::complex<double>(-4,0)));  //-4



}
TEST_CASE("CHECK_THROWS ComplexVariable ") {
    ComplexVariable y;
    CHECK_THROWS(solve((y ^ 0)==-16));
}
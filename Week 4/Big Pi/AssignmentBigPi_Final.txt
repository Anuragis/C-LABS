#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);

/***** Add more functions as necessary. *****/

/** Compute The value pi by Borwein's_algorithm using Nonic Convergence*/
void computeBigPi();


/**
 * Computes t as tn=1+2*rn
 * @param one BASE 10 value 1
 * @param one BASE 10 value 2
 * @param r rn the previous value of r
 * @param t value of computed tn stored in t.
 */
void computeT(mpf_t&one,mpf_t&two,mpf_t &r, mpf_t&t);
/**
 * Computes t as un=(9rn*(1+rn+rn^2))*(1/3)
 * @param one BASE 10 value 1
 * @param nine BASE 10 value 9
 * @param r rn the previous value of r
 * @param rSquare rn^2 the previous value of r^2
 * @param u value of computed tn stored in u.
 */
void computeU(mpf_t &one, mpf_t &nine, mpf_t &r, mpf_t &rSquare,mpf_t &u);
/**
 * Computes vn as vn=tn*2+tn*un+un^2
 * @param t tn the previous value of t
 * @param u un the previous value of u
 * @param v value of computed vn stored in v.
 */
void computeV(mpf_t &t, mpf_t &u, mpf_t &v);
/**
 * Computes t as tn=1+2*rn
 * @param one BASE 10 value 1
 * @param twentySeven BASE 10 value 27
 * @param s sn the previous value of s
 * @param v vn the previous value of v
 * @param w value of computed wn stored in w.
 */
void computeW(mpf_t &one, mpf_t &twentySeven, mpf_t &s, mpf_t &v, mpf_t &w);

/**
 * Computes a as an+1=wn+1*an+(3^(2*n-1))*(1-wn+1)
 * @param one BASE 10 value 1
 * @param twentySeven BASE 10 value 3
 * @param w wn the previous value of w
 * @param v vn the previous value of v
 * @param a value of computed wn stored in a.
 */
void computeA(mpf_t &one,mpf_t &three,int &n,mpf_t &w,mpf_t &a);

/**
 * Computes s as sn+1=((1-rn)^3)/(tn+1 + 2un+1)*vn+1
 * @param one BASE 10 value 1
 * @param twentySeven BASE 10 value 2
 * @param r rn the previous value of r
 * @param t tn the previous value of t
 * @param u un the previous value of u
 * @param v vn the previous value of v
 * @param s value of computed sn stored in s.
 */
void computeS(mpf_t &one,mpf_t &two,mpf_t &r,mpf_t &t,mpf_t &u,mpf_t &v,mpf_t &s);


/**
 * Computes r as rn+1=(1-(sn+1)^3)^(1/3)
 * @param one BASE 10 value 1
 * @param nullValue BASE 10 value 0
 * @param s sn the previous value of s
 * @param r value of computed rn stored in r.
 */
void computeR(mpf_t &one,mpf_t &nullValue, mpf_t &s, mpf_t &r);
/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
    computeBigPi();

    return 0;
}

void computeBigPi(){
    mpf_set_default_prec(BIT_COUNT*PRECISION);
    mpf_t one;mpf_init(one);
    mpf_t two;mpf_init(two);
    mpf_t three;mpf_init(three);
    mpf_t nine;mpf_init(nine);
    mpf_t twentySeven;mpf_init(twentySeven);
    mpf_t nullValue;mpf_init(nullValue);

    mpf_set_str(one,"1",BASE);
    mpf_set_str(two,"2",BASE);
    mpf_set_str(three,"3",BASE);
    mpf_set_str(nine,"9",BASE);
    mpf_set_str(twentySeven,"27",BASE);
    mpf_set_str(nullValue,"0",BASE);

    mpf_t a;mpf_init(a);
    mpf_t r;mpf_init(r);
    mpf_t s;mpf_init(s);
    mpf_t rSquare;mpf_init(rSquare);
    mpf_t rCube;mpf_init(rCube);
    mpf_t nrOfR;mpf_init(nrOfR);
    mpf_t rootThree;mpf_init(rootThree);
    mpf_t sDiff;mpf_init(sDiff);
    mpf_t sDiffCubeRoot;mpf_init(sDiffCubeRoot);

    //Initialization a0, r0 and s0

    mpf_div(a,one,three);
    mpf_add(rootThree,rootThree,three);
    mpf_sqrt(rootThree,rootThree);
    mpf_sub(nrOfR,rootThree,one);
    mpf_div(r,nrOfR,two);
    mpf_mul(rSquare,r,r);
    mpf_mul(rCube,rSquare,r);
    mpf_sub(sDiff,one,rCube);
    cube_root(sDiffCubeRoot, sDiff);
    mpf_add(s,sDiffCubeRoot,nullValue);

    //Declare and Initialize computation parameters
    mpf_t t;mpf_init(t);
    mpf_t u;mpf_init(u);
    mpf_t v;mpf_init(v);
    mpf_t w;mpf_init(w);
    mpf_t pi;mpf_init(pi);



    //Iterate
    for (int n=0;n<MAX_ITERATIONS;n++){

        computeT(one,two,r, t);
        computeU(one, nine, r, rSquare, u);
        computeV(t, u, v);
        computeW(one, twentySeven, s, v, w);
        computeA(one,three,n,w,a);
        computeS(one,two,r,t,u,v,s);
        computeR(one,nullValue,s,r);
        mpf_mul(rSquare,r,r);
        mpf_div(pi,one,a);

    }

    //Print Pi
    long int exponent;
    char* outputStr;
    outputStr = mpf_get_str(NULL, &exponent, 10, 0, pi);

    cout<<outputStr[0];
    cout<<".";
    int ln=0,count=0,grp=0;

    for(int i=1;i<PLACES+1;i++){
    	cout<<outputStr[i];
    	ln++;
    	count++;
    	if(count==BLOCK_SIZE){
    		cout<<" ";
    		count=0;
    	}
    	if(ln==LINE_SIZE){
    		cout<<endl;
    		cout<<"  ";
    		grp++;
    		ln=0;
    	}
    	if(grp==GROUP_SIZE){
    		cout<<endl;
    		cout<<"  ";
    		grp=0;
    	}
    }
}

void computeT(mpf_t&one,mpf_t&two,mpf_t &r, mpf_t &t){
    mpf_t prod; mpf_init(prod);
    mpf_mul(prod,two,r);
    mpf_add(t,one,prod);
}

void computeU(mpf_t &one, mpf_t &nine, mpf_t &r, mpf_t &rSquare,mpf_t &u){
    mpf_t fProd; mpf_init(fProd);
    mpf_t sProd; mpf_init(sProd);
    mpf_t fSum; mpf_init(fSum);
    mpf_t sSum; mpf_init(sSum);
    mpf_t wholeRoot; mpf_init(wholeRoot);
    mpf_t nullValue; mpf_init(nullValue);

    mpf_add(fSum,r,rSquare);
    mpf_add(sSum,one,fSum);
    mpf_mul(fProd,nine,r);
    mpf_mul(sProd,fProd,sSum);
    cube_root(wholeRoot, sProd);
    mpf_add(u,wholeRoot,nullValue);
}

void computeV(mpf_t &t, mpf_t &u, mpf_t &v){
    mpf_t tSquare; mpf_init(tSquare);
    mpf_t uSquare; mpf_init(uSquare);
    mpf_t tUProd; mpf_init(tUProd);
    mpf_t fSum; mpf_init(fSum);

    mpf_mul(tSquare,t,t);
    mpf_mul(uSquare,u,u);
    mpf_mul(tUProd,t,u);
    mpf_add(fSum,tUProd,uSquare);
    mpf_add(v,fSum,tSquare);
}

void computeW(mpf_t &one, mpf_t &twentySeven, mpf_t &s, mpf_t &v, mpf_t &w){
    mpf_t sSquare; mpf_init(sSquare);
    mpf_t fSum; mpf_init(fSum);
    mpf_t sSum; mpf_init(sSum);
    mpf_t prod; mpf_init(prod);

    mpf_mul(sSquare,s,s);
    mpf_add(fSum,s,sSquare);
    mpf_add(sSum,one,fSum);
    mpf_mul(prod,twentySeven,sSum);
    mpf_div(w,prod,v);
}

void computeA(mpf_t &one,mpf_t &three,int &n,mpf_t &w,mpf_t &a){

    mpf_t diff; mpf_init(diff);
    mpf_t fProd; mpf_init(fProd);
    mpf_t sProd; mpf_init(sProd);
    mpf_t powResult; mpf_init(powResult);
    mpf_t nullValue; mpf_init(nullValue);

    mpf_sub(diff,one,w);
    if(n>0){
        int pow=(2*n)-1;
        mpf_pow_ui(powResult,three,pow);
    }else{
        mpf_add(powResult,a,nullValue);
    }

    mpf_mul(fProd,powResult,diff);
    mpf_mul(sProd,w,a);
    mpf_add(a,sProd,fProd);
}

void computeS(mpf_t &one,mpf_t &two,mpf_t &r,mpf_t &t,mpf_t &u,mpf_t &v,mpf_t &s){
    mpf_t nrDiff; mpf_init(nrDiff);
    mpf_t nrDiffSquare; mpf_init(nrDiffSquare);
    mpf_t nrDiffCube; mpf_init(nrDiffCube);
    mpf_t drSum; mpf_init(drSum);
    mpf_t drFProd; mpf_init(drFProd);
    mpf_t drSProd; mpf_init(drSProd);

    mpf_sub(nrDiff,one,r);
    mpf_mul(nrDiffSquare,nrDiff,nrDiff);
    mpf_mul(nrDiffCube,nrDiffSquare,nrDiff);

    mpf_mul(drFProd,two,u);
    mpf_add(drSum,drFProd,t);
    mpf_mul(drSProd,drSum,v);
    mpf_div(s,nrDiffCube,drSProd);
}

void computeR(mpf_t &one,mpf_t &nullValue, mpf_t &s, mpf_t &r){
    mpf_t sSquare; mpf_init(sSquare);
    mpf_t sCube; mpf_init(sCube);
    mpf_t diff; mpf_init(diff);
    mpf_t diffCubeRoot; mpf_init(diffCubeRoot);

    mpf_mul(sSquare,s,s);
    mpf_mul(sCube,sSquare,s);
    mpf_sub(diff,one,sCube);
    cube_root(diffCubeRoot,diff);
    mpf_add(r,diffCubeRoot,nullValue);
}

void cube_root(mpf_t& x, const mpf_t a)
{
    /***** Complete this function. *****/
    mpf_t prev; mpf_init(prev);
    mpf_t prevSq; mpf_init(prevSq);
    mpf_t prevCube; mpf_init(prevCube);
    mpf_t root_divisor; mpf_init(root_divisor);
    mpf_t multiplier; mpf_init(multiplier);
    mpf_t nrMul; mpf_init(nrMul);
    mpf_t drMul; mpf_init(drMul);
    mpf_t nrSum; mpf_init(nrSum);
    mpf_t drSum; mpf_init(drSum);
    mpf_t divResult; mpf_init(divResult);
    mpf_t nullValue; mpf_init(nullValue);
    mpf_t compValue; mpf_init(compValue);

    mpf_set_str(root_divisor,"3",BASE);
    mpf_set_str(multiplier,"2",BASE);
    mpf_set_str(nullValue,"0",BASE);


         mpf_div(prev,a,root_divisor);

         mpf_div(prevCube,a,root_divisor);

         mpf_div(prevSq,a,root_divisor);

     for(int i=0;i<MAX_ITERATIONS;i++){
        mpf_mul(prevSq,prevSq,prevSq);

        mpf_mul(prevCube,prev,prevSq);

        mpf_mul(nrMul,multiplier,a);

        mpf_mul(drMul,multiplier,prevCube);

        mpf_add(nrSum,prevCube,nrMul);

        mpf_add(drSum,drMul,a);

        mpf_div(divResult,nrSum,drSum);

        mpf_mul(x,divResult,prev);
        if(mpf_cmp(x,prev)==0){
            break;
        }else{
        mpf_add(prev,x,nullValue);
        mpf_add(prevSq,x,nullValue);
        mpf_add(prevCube,x,nullValue);}
     }
}

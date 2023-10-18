#include "fraction.h"

    void fraction::mul(unsigned int _i)
    {multiset<unsigned int >::iterator it=den.find(_i);
     if (it!=den.end()) den.erase(it);
        else num.insert(_i);
    };


    void fraction::div(unsigned int _i)
    {multiset<unsigned int >::iterator it=num.find(_i);
     if (it!=num.end()) num.erase(it);
        else den.insert(_i);
    }

fraction& fraction::operator*=(const fraction& _f)
  { if(_f.zero) {set_zero(); return *this;}
      multiset<unsigned int >::iterator it;
   for(it=_f.num.begin();it!=_f.num.end();it++)
     {mul(*it);}
   for(it=_f.den.begin();it!=_f.den.end();it++)
     {div(*it);}
     return *this;
  }

  long double fraction::compute()
  { if (zero) return 0;
      long double temp_n,temp_d;
      temp_n=1;temp_d=1;
      multiset<unsigned int >::iterator it;
   for(it=den.begin();it!=den.end();it++)
     {temp_d*=*it;}
   for(it=num.begin();it!=num.end();it++)
     {temp_n*=*it;}
return temp_n/temp_d; // come si fa con il tipo?
  }

long double fraction::compute2()
{ if (zero) return 0;
      long double temp=1;
      long double temp_n,temp_d;
       multiset<unsigned int >::reverse_iterator itn,itd;
  itn=num.rbegin();
  itd=den.rbegin();
  while ((itn!=num.rend())&&(itd!=den.rend()))
  {temp_n=*itn;
   temp_d=*itd;
    temp*=temp_n/temp_d;
//  cout<<"compute2 temp:"<<temp<<endl;
  itd++;itn++;
  }
    while(itn!=num.rend()){temp_n=*itn;
                            temp*=temp_n;
                            itn++;}
    while(itd!=den.rend()){temp_d=*itd;
                            temp/=temp_d;
                            itd++;}
cout<<"compute2 temp:"<<temp<<endl; 
return temp;
}


fraction fraction::simplify_as_factorial()
{
    fraction temp;
    if (zero) return temp.set_zero();
  multiset<unsigned int >::reverse_iterator itn,itd;
  itn=num.rbegin();
  itd=den.rbegin();
  while ((itn!=num.rend())&&(itd!=den.rend()))
  {
      if ((*itn)>(*itd)) {for(unsigned int i=*itn; i>*itd;i--)
                            temp.mul(i);
      }
        else if ((*itn)<(*itd)) {for(unsigned int i=*itd; i>*itn;i--)
                            temp.div(i);}
      else {cout<<"something is wrong";}
      itd++; itn++;
  }
  while(itn!=num.rend()){for(unsigned int i=*itn; i>1;i--)
                            {temp.mul(i);}
                            itn++;}

  while(itd!=den.rend()){for(unsigned int i=*itd; i>1;i--)
                            {temp.div(i);}
                            itd++;}
 return temp;
}


fraction fraction::simplify_with_primes()
{
    fraction temp;
    if (zero) return temp.set_zero();
  multiset<unsigned int >::reverse_iterator itn,itd;
  multiset<unsigned int >::iterator it;
  multiset<unsigned int> primes;
  itn=num.rbegin();
  itd=den.rbegin();
  while ((itn!=num.rend())&&(itd!=den.rend()))
  {
      primes=primeFactors(*itn);
      for (it=primes.begin();it!=primes.end();it++)
        {temp.mul(*it);}
      primes=primeFactors(*itd);
      for (it=primes.begin();it!=primes.end();it++)
        {temp.div(*it);}
      itd++; itn++;
  }
  while(itn!=num.rend()){primes=primeFactors(*itn);
                        for (it=primes.begin();it!=primes.end();it++)
                                {temp.mul(*it);}
                         itn++;}

  while(itd!=den.rend()){primes=primeFactors(*itd);
                            for (it=primes.begin();it!=primes.end();it++)
                            {temp.div(*it);}
                            itd++;}
 return temp;
}


ostream& operator<<(ostream& os,const fraction& _f){
   if (_f.zero) return os<<" 0/1 ";
   multiset<unsigned int >::iterator it;
   for(it=_f.num.begin();it!=_f.num.end();it++)
     {os<<*it<<" ";}

   os<<"  "<<"/"<<"  ";
   for(it=_f.den.begin();it!=_f.den.end();it++)
     {os<<*it<<" ";}
    os<<endl;
    return os;
  }

unsigned long long int fract(unsigned int _i)
 { unsigned long long int temp=1;
   for(unsigned int i=1;i<=_i;i++)
   {
     temp*=i;
   }
return temp;
 }

multiset<unsigned int> primeFactors(int n)
{ multiset<unsigned int> temp;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " "; temp.insert(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " "; temp.insert(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        {cout << n << " "; temp.insert(n);}
return temp;
}



fraction hg(unsigned int x, unsigned int r, unsigned int n, unsigned int N)
 {
     fraction temp;
//     unsigned int max_cond=(N > r+n) ? 0: r-N+n;
//     unsigned int min_cond=( r < n) ? r : n;
//     cout<<endl<<" max"<<max_cond;
//     cout<<" x"<<x;
//     cout<<" min"<<min_cond;
     if ( (((N > r+n) ? 0: r-N+n)>x)|| ((( r < n) ? r : n)<x))
     {
         return temp.set_zero();
     }

     temp.mul(n);temp.div(x);temp.div(n-x);
     temp.mul(N-n);temp.div(r-x);temp.div(N-n-r+x);
     temp.div(N); temp.mul(r);temp.mul(N-r);
     cout<<"hg"<<temp<<endl;
     return temp;
 }

fraction coeff_binom(unsigned int n, unsigned int k)
{fraction temp;
     temp.mul(n);temp.div(k);temp.div(n-k);
     return temp;
}


void test_fraction()
{
    fraction f;
    f.mul(4);
    f.mul(3);
    f.div(15);
    f.div(3);
    f.div(9);
    f.mul(13);
    f.div(12);
    f.mul(11);
    cout<<f;
    fraction f2;
    f2.mul(3); f2.mul(5); f2.mul(9);
    f2.div(12); f2.div(11);
    f2.div(45);f2.mul(87000); f2.div(87000-10);
    cout<<f2;
    f*=f2;
    cout<<f;
    cout<<f.compute()<<endl;
  //  cout<<f.compute_num()<<endl;
  //  cout<<f.compute_den()<<endl;
    cout<<fract(5);
    cout<<f.simplify_as_factorial();
    cout<<f.compute()<<endl;
 //   cout<<f.compute_num()<<endl;
  //  cout<<f.compute_den()<<endl;
  //  fraction f3=hg(3,300,1000,87000);
   cout<<"f3";
      fraction f3=hg(2,13,4,52);
    //f3*=hg(3,297,1000,86000);
    cout<<f3;
   cout<<f3.simplify_as_factorial();
   cout<<f3.simplify_as_factorial().compute();
//    multiset<unsigned int> primes=primeFactors(87000);
//    for(auto it=primes.begin();it!=primes.end();it++)
//    {cout<<*it;}
   cout<<"prime simplification:";
//    //cout<<f3.simplify_as_factorial().simplify_with_primes();
//    //cout<<f3.simplify_as_factorial().simplify_with_primes().compute();
//    //cout<<coeff_binom(5,2);
    fraction f4=hg(1,13,12,52);
//    cout<<f4;
//    //cout<<f4.simplify_as_factorial().simplify_with_primes().compute();
    f4*=hg(2,13,12-1,52-13);
//    cout<<f4;
//    //cout<<f4.simplify_as_factorial().simplify_with_primes().compute();
    f4*=hg(3,13,12-1-2,52-13*2);
    cout<<f4;
    cout<<f4.simplify_as_factorial().simplify_with_primes().compute();
//    cout<<hg(4,13,12-1-2-3,52-13*3);
cout<<hg(4,13,6,13);
    f4*=hg(6,13,12-6,52-13*3);
    cout<<f4;
cout<<f4.simplify_as_factorial().simplify_with_primes().compute();

fraction f5=hg(1,13,12,52);
f5*=hg(2,13,12-1,52-13)*=hg(3,13,12-1-2,52-13*2);
cout<<f5.simplify_as_factorial().simplify_with_primes().compute();

fraction f6=hg(3,13,12,52);
f6*=hg(2,13,12-3,52-13)*=hg(1,13,12-2-3,52-13*2);
cout<<f6.simplify_as_factorial().simplify_with_primes().compute();

fraction f7=hg(2,13,12,52);
f7*=hg(3,13,12-2,52-13)*=hg(1,13,12-2-3,52-13*2);
cout<<f7.simplify_as_factorial().simplify_with_primes().compute();

}

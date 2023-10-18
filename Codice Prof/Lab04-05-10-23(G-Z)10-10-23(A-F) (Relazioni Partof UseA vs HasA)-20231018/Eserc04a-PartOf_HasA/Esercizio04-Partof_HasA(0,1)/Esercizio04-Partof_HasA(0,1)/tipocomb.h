#ifndef __TIPOCOMB_H__
#define __TIPOCOMB_H__

typedef enum {DIESEL, BENZINA, GPL} Tcombustibile;
class Tipocomb{
private:
  Tcombustibile comb;      
public:  
  Tipocomb(Tcombustibile _comb); 
  ~Tipocomb();
  void stampa()const;         
};

#endif

#ifndef _OBJETO_H_
#define _OBJETO_H_

class Objeto {
  protected:
    std::string id;
  public:
    virtual std::string darId() = 0;
};

#endif

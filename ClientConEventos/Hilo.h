#ifndef _HILO_H
#define _HILO_H
#include <pthread.h>
#include <thread>
#include <iostream>

class Hilo {
private:
    std::thread hilo;

public:
    Hilo() {}

    void start() {
        hilo = std::thread(&Hilo::runSeguro, this);
    }

    void join() {
        hilo.join();
    }
    void runSeguro(){
        try{
            run();
        }catch (std::exception &e){
            std::cerr << "Error en un hilo: " << e.what() << std::endl;
        }catch (...){
            std::cerr << "Error deconocido" << std::endl;
        }
    }
    virtual void run() = 0;
    virtual ~Hilo() {}

    Hilo(const Hilo&) = delete;
    Hilo& operator=(const Hilo&) = delete;

    Hilo(Hilo&& other) {
        this->hilo = std::move(other.hilo);
    }

    Hilo& operator=(Hilo&& other) {
        this->hilo = std::move(other.hilo);
        return *this;
    }
};


#endif

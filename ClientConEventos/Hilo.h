#ifndef _HILO_H
#define _HILO_H
#include <pthread.h>
#include <thread>

class Hilo {
private:
    std::thread hilo;

public:
    Hilo() {}

    void start() {
        hilo = std::thread(&Hilo::run, this);
    }

    void join() {
        hilo.join();
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

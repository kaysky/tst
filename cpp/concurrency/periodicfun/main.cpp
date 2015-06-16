#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <pthread.h>

class Thread
{
private:
    pthread_t thread;

    Thread(const Thread& copy);         // copy constructor denied
    static void *thread_func(void *d)   { ((Thread *)d)->run(); return NULL; }

public:
    Thread()             {}
    virtual ~Thread()    {}

    virtual void run() = 0;

    int start()          { return pthread_create(&thread, NULL,
                           Thread::thread_func, (void*)this); }
    int wait ()          { return pthread_join  (thread, NULL); }
};

typedef std::auto_ptr<Thread> ThreadPtr;

class Thread_a : public Thread
{
public:
    void run()
    {
        for (int i=0; i<10; i++, sleep(1))
            std::cout << "a  " << std::endl;
    }
};

class Thread_b : public Thread
{

public:
    void run()
    {
        for(int i=0; i<10; i++, sleep(1))
            std::cout << "  b" << std::endl;
    }
};


class periodic : public Thread
{
//    static timespec ts;
    pthread_mutex_t mutex;
    pthread_cond_t  cv;
    int delta_time;
    time_t tm;
    struct timespec ts;
public:
    explicit periodic(int t)
        : delta_time(t)
        , mutex(PTHREAD_MUTEX_INITIALIZER)
        , cv(PTHREAD_COND_INITIALIZER)
        , tm(time(NULL))
    {
//        time(&tm);
        tm += delta_time;
        ts.tv_sec = tm;
    }
    void run()
    {
//      pthread_mutex_lock(&mutex);
        for(int i = 0; i < 10; ++i)
        {
            pthread_cond_timedwait(&cv,&mutex,&ts);
            time_update();
            std::cout << " periodic work " << std::endl;
        }
//      pthread_mutex_unlock(&mutex);
    }
    void time_update()
    {
        time(&tm);
        tm += delta_time;
        ts.tv_sec = tm;
    }
};


int main(void)
{

//    ThreadPtr a( new Thread_a() );
//    ThreadPtr b( new Thread_b() );
    ThreadPtr pr( new periodic(2) );

//    if (a->start() != 0 || b->start() != 0)
//        return EXIT_FAILURE;

//    if (a->wait() != 0 || b->wait() != 0)
//        return EXIT_FAILURE;

    if (pr->start() != 0)
        return EXIT_FAILURE;

    if (pr->wait() != 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

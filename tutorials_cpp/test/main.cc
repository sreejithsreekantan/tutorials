#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;


int main(int argc, char *argv[])
{
    struct addrinfo hints, *res, *res0;
    int error;
    int s;
    const char *cause = NULL;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    error = getaddrinfo("TVMATP245227M.local", "3490", &hints, &res0);
    if (error)
    {
        cout << "ERROR: " << gai_strerror(error) << endl;
        /*NOTREACHED*/
    }
    s = -1;
    for (res = res0; res; res = res->ai_next)
    {
        s = socket(res->ai_family, res->ai_socktype,
                   res->ai_protocol);
        if (s < 0)
        {
            cause = "socket";
            continue;
        }

        if (connect(s, res->ai_addr, res->ai_addrlen) < 0)
        {
            cause = "connect";
            // close(s);
            s = -1;
            continue;
        }
        cout << "SUCCESS: Connected.." << endl;
        break;  /* okay we got one */
    }
    if (s < 0)
    {
        cout << "ERROR: " << cause << endl;
        /*NOTREACHED*/
    }
    freeaddrinfo(res0);
}

// int getaddrinfo(const char *node, // e.g. "www.example.com" or IP
// const char *service, // e.g. "http" or port number
// const struct addrinfo *hints,
// struct addrinfo **res);


// struct addrinfo
// {
//     int ai_flags; // AI_PASSIVE, AI_CANONNAME, etc.
//     int ai_family; // AF_INET, AF_INET6, AF_UNSPEC
//     int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
//     int ai_protocol; // use 0 for "any"
//     size_t ai_addrlen; // size of ai_addr in bytes
//     struct sockaddr *ai_addr; // struct sockaddr_in or _in6
//     char *ai_canonname; // full canonical hostname
//     struct addrinfo *ai_next; // linked list, next node
// };
// struct sockaddr
// {
//     unsigned short sa_family; // address family, AF_xxx
//     char sa_data[14]; // 14 bytes of protocol address
// };

// using namespace std;

// int main(int argc, char const *argv[])
// {

// // // IPv4:
//  //    char ip4[INET_ADDRSTRLEN]; // space to hold the IPv4 string
//  //    struct sockaddr_in sa; // pretend this is loaded with something
//  //    inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
//  //    printf("The IPv4 address is: %s\n", ip4);
//  //    // IPv6:
//  //    char ip6[INET6_ADDRSTRLEN]; // space to hold the IPv6 string
//  //    struct sockaddr_in6 sa6; // pretend this is loaded with something
//  //    inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);
//  //    printf("The address is: %s\n", ip6);

//     int status;
//     struct addrinfo hints;
//     struct addrinfo *servinfo; // will point to the results
//     memset(&hints, 0, sizeof hints); // make sure the struct is empty
//     hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
//     hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
//     hints.ai_flags = AI_PASSIVE; // fill in my IP for me
//     if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0)
//     {
//         fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
//         exit(1);
//     }

//     struct  addrinfo *next = servinfo;
//     while (next)
//     {
//         cout << "ai_flags\t:\t" << next->ai_flags << endl;
//         cout << "ai_family\t:\t" << next->ai_family << endl;
//         cout << "ai_socktype\t:\t" << next->ai_socktype << endl;
//         cout << "ai_protocol\t:\t" << next->ai_protocol << endl;
//         cout << "ai_addrlen\t:\t" << next->ai_addrlen << endl;
//         cout << "ai_addr->sa_family\t:\t" << next->ai_addr->sa_family << endl;
//         printf("ai_canonname\t:\t%s\n", next->ai_canonname);
//         // printf("ai_addr->sa_data\t:\t%s\n",next->ai_addr->sa_data);
//         cout << "ai_next\t:\t" << next->ai_next << endl << endl;
//         next = next->ai_next;
//     }

//     // servinfo now points to a linked list of 1 or more struct addrinfos
//     // ... do everything until you don't need servinfo anymore ....
//     freeaddrinfo(servinfo); // free the linked-list

//     return 0;
// }




// // condition_variable example
// #include <iostream>           // std::cout
// #include <thread>             // std::thread
// #include <mutex>              // std::mutex, std::unique_lock
// #include <condition_variable> // std::condition_variable

// std::mutex mtx;
// std::condition_variable cv;
// bool ready = false;
// int i = 0;

// void print_id (int id)
// {
//     // std::cout << "thread " << id << endl;
//     std::unique_lock<std::mutex> lck(mtx);

//     // while (!ready)
//     // {
//         std::cout << "thread " << id << " cv.wait(lck)" << endl;
//         cv.wait(lck);
//         std::cout << "thread " << id << " cv.wait(lck) done " << endl;
//     // }

//     // ...
//     std::cout << "thread " << id << " " << (boost::posix_time::microsec_clock::local_time()) << endl;
// }

// void go()
// {
//     std::unique_lock<std::mutex> lck(mtx);
//     cout << "ready = true" << endl;
//     ready = true;
//     cout << "cv.notify_all()" << endl;
//     cv.notify_all();
// }

// int main ()
// {
//     std::thread threads[2];
//     // spawn 10 threads:
//     for (int i = 0; i < 2; ++i)
//         threads[i] = std::thread(print_id, i);


//     std::cout << "10 threads ready to race..." << endl;

//     this_thread::sleep_for(chrono::seconds(5));

//     go();                       // go!

//     for (auto &th : threads) th.join();

//     cout << "the end.." << endl;
//     return 0;
// }


// class NewHandleHolder
// {
// public:
//     explicit NewHandleHolder(new_handler nh): h(set_new_handler(nh))
//     {
//         cout << "\tNewHandleHolder()\n";
//         cout << "\tprev new_handler() : " << (long long)h << endl;
//         cout << "\tget_new_handler() : " << (long long)get_new_handler() << endl;
//     }
//     ~NewHandleHolder()
//     {
//         set_new_handler(h);
//         cout << "\t~NewHandleHolder()\n";
//         cout << "\tget_new_handler() : " << (long long)get_new_handler() << endl;
//     }
// private:
//     NewHandleHolder(const NewHandleHolder &) = delete;
//     NewHandleHolder &operator=(const NewHandleHolder &) = delete;
//     new_handler h;
// };

// class Widget
// {
// public:
//     static void *operator new(size_t);
//     static new_handler set_new_handler(const new_handler &);
// private:
//     static new_handler current_handler_;
//     int *i = new int[1000000000000000000];
// };

// new_handler Widget::current_handler_ = 0;

// void *Widget::operator new(size_t size)
// {
//     cout << "Widget::operator new(" << size << ")" << endl;
//     NewHandleHolder newHandlerHolder(current_handler_);

//     return ::operator new(size);
// }

// new_handler Widget::set_new_handler(const new_handler &newHandler)
// {
//     new_handler oldHandler = current_handler_;
//     current_handler_ = newHandler;
//     return oldHandler;
// }

// void handler1()
// {
//     cout << "handler1()\n";
//     abort();
// }

// void handler2()
// {
//     cout << "handler2()\n";
//     abort();
// }

// // void consumeMemory()
// // {
// //     cout << "consumeMemory()\n";
// //     NewHandleHolder newHandlerHolder(handler2);
// //     cout << "\tget_new_handler() : " << (long long)get_new_handler() << endl;

// // }

// #include <cstdlib>
// #include <cstdio>


// /* function main begins program execution */
// int main(void) {
//     int i; /* counter */
//     unsigned seed; /* number used to seed random number generator */

//     seed = 9;

//     int p[6] = {};

//     srand(seed); /* seed random number generator */
//     /* loop 10 times */
//     for (i = 1; i <= 100; i++) {

//         /* pick a random number from 1 to 6 and output it */
//         p[1 + (rand() % 6)]++;

//     } /* end for */

//     for (int i = 0; i < 6; ++i)
//     {
//         std::cout << i << "-" << (i + 1) << ": ";
//         std::cout << std::string(p[i], '*') << std::endl;
//     }
//     return 0; /* indicates successful termination */


//     // cout << "handler1 : "<< (long long)handler1 << endl;
//     // cout << "handler2 : "<< (long long)handler2 << endl;
//     // std::set_new_handler(handler1);
//     // cout << "get_new_handler() : " << (long long)get_new_handler() << endl;
//     // Widget::set_new_handler(handler2);
//     // new Widget();
//     // cout << "get_new_handler() : " << (long long)get_new_handler() << endl;
//     // set_new_handler(handler1);
//     // cout << "get_new_handler() : " << (long long)get_new_handler() << endl;
//     // consumeMemory();

// }


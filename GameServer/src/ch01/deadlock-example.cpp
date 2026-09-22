#include <thread>
#include <iostream>
#include "deadlock-example.h"

using std::thread;
using std::cout;
using std::endl;

namespace ch01::deadlock_example
{
    CriticalSection::CriticalSection()
    {
        InitializeCriticalSectionEx(&m_critSec, 0, 0);
    }

    CriticalSection::~CriticalSection()
    {
        DeleteCriticalSection(&m_critSec);
    }

    void CriticalSection::Lock()
    {
        EnterCriticalSection(&m_critSec);
    }

    void CriticalSection::Unlock()
    {
        LeaveCriticalSection(&m_critSec);
    }

    CriticalSectionLock::CriticalSectionLock(CriticalSection& critSec)
    {
        m_pCritSec = &critSec;
        m_pCritSec->Lock();
    }

    CriticalSectionLock::~CriticalSectionLock()
    {
        m_pCritSec->Unlock();
    }

    int a, b;
    CriticalSection a_mutex, b_mutex;

    int ExecMain()
    {
        thread t1([](){
            while(true)
            {
                CriticalSectionLock a_lock(a_mutex);
                a++;
                CriticalSectionLock b_lock(b_mutex);
                b++;
                cout << "[t1] a: " << a << ", b: " << b << endl;
            }
        });

        thread t2([](){
            while(true)
            {
                CriticalSectionLock b_lock(b_mutex);
                b++;
                CriticalSectionLock a_lock(a_mutex);
                a++;
                cout << "[t2] a: " << a << ", b: " << b << endl;
            }
        });

        t1.join();
        t2.join();

        return 0;
    }
}